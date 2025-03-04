YCMD:map(playerid, params[], help) 
{
    new option[50], string[200], bool:syntax = true;

    if(sscanf(params, "s[50]S()[200]", option, string)) 
    {
        syntax = false;
    }
    else 
    {
        if(!strcmp(option, "list", true)) 
        {
            AddDialogListitem(playerid, "Name\tStatus\tCreator\tLocation");
            foreach(new i : MappingFolder)
            {
                if(Iter_Contains(MappingFolder, i)) 
                {
                    AddDialogListitem(playerid, "%s\t%s\t%s\t%s", mappingInfo[i][mappingName], mappingInfo[i][mappingLoaded] ? ""LG"Loaded" : ""LR"Unloaded", mappingInfo[i][mappingCreator], GetLocation(mappingInfo[i][mappingLocationX], mappingInfo[i][mappingLocationY], mappingInfo[i][mappingLocationZ]));
                }
            }
            ShowPlayerDialogPages(playerid, "MappingList", DIALOG_STYLE_TABLIST_HEADERS, "Mapping List", "Close", "", 10);
        }
        else if(!strcmp(option, "load", true)) 
        {
            new foldername[MAX_MAPPING_FOLDER_NAME], interior, world;
            if(sscanf(string, "s[50]dd", foldername, interior, world))
                return SendUsageMessage(playerid, "/map load [mapping name] [interior id] [world id]");

            if(IsValidMappingFolder(foldername))
            {
                new folderid = GetMappingFolderID(foldername);
                if(mappingInfo[folderid][mappingLoaded] == true) 
                    return SendErrorMessage(playerid, "Mapping %s telah dimuat sebelumnya!", foldername);

                LoadMappingObject(foldername, world, interior);
                mappingInfo[folderid][mappingLoaded] = true;

                new query[200];
                mysql_format(sql, query, sizeof query, "UPDATE `mapping_folder` SET `loaded` = '1', `world` = '%d', `interior` = '%d' WHERE `name` = '%e'", world, interior, foldername);
                mysql_tquery(sql, query);

                SendClientMessageEx(playerid, COLOR_REN, "MAPPING: "WHITE"Mapping "YELLOW"%s"WHITE" saat ini "LG"loaded", foldername);
            }
            else SendErrorMessage(playerid, "Tidak ada mapping yang disimpan dengan folder %s", foldername);
        }
        else if(!strcmp(option, "unload", true)) 
        {
            if(isnull(string))
                return SendUsageMessage(playerid, "/map unload [mapping folder]");

            if(IsValidMappingFolder(string))
            {
                new folderid = GetMappingFolderID(string);
                if(mappingInfo[folderid][mappingLoaded] == false) 
                    return SendErrorMessage(playerid, "Mapping %s tidak dimuat sebelumnya!", string);

                UnloadMappingObject(string);
                mappingInfo[folderid][mappingLoaded] = false;

                new query[200];
                mysql_format(sql, query, sizeof query, "UPDATE `mapping_folder` SET `loaded` = '0' WHERE `name` = '%e'", string);
                mysql_tquery(sql, query);

                SendClientMessageEx(playerid, COLOR_REN, "MAPPING: "WHITE"Mapping "YELLOW"%s"WHITE" saat ini "LR"unloaded", string);
            }
            else SendErrorMessage(playerid, "Tidak ada mapping yang disimpan dengan folder %s", string);
        }
        else if(!strcmp(option, "delete", true) || !strcmp(option, "remove", true)) 
        {
            if(isnull(string))
                return SendUsageMessage(playerid, "/map unload [mapping folder]");

            if(!IsValidMappingFolder(string))
                return SendErrorMessage(playerid, "Tidak ada mapping yang disimpan dengan folder %s", string);
            
            Dialog_Show(playerid, Mapping_Delete, DIALOG_STYLE_MSGBOX, "Delete Mapping", "Anda yakin akan menghapus semua object pada mapping %s?", "Clear", "Cancel", string);
            format(player_delete_mappingname[playerid], MAX_MAPPING_FOLDER_NAME, string);
        }
        else if(!strcmp(option, "rename", true)) 
        {
            new foldername[MAX_MAPPING_FOLDER_NAME], newfoldername[MAX_MAPPING_FOLDER_NAME];

            if(sscanf(string, "s[50]s[50]", foldername, newfoldername))
                return SendUsageMessage(playerid, "/map rename [mapping folder] [new mapping folder name]");

            if(!IsValidMappingFolder(foldername))
                return SendErrorMessage(playerid, "Tidak ada mapping yang disimpan dengan folder %s", foldername);
            
            new folderid = GetMappingFolderID(foldername);
            format(mappingInfo[folderid][mappingName], MAX_MAPPING_FOLDER_NAME, newfoldername);

            new query[500];
            mysql_format(sql, query, sizeof query, "UPDATE `mapping_folder` SET `name` = '%e' WHERE `name` = '%e'", newfoldername, foldername);
            mysql_tquery(sql, query);
            
            mysql_format(sql, query, sizeof query, "UPDATE `mapping_object` SET `folder` = '%e' WHERE `folder` = '%e'", newfoldername, foldername);
            mysql_tquery(sql, query);

            SendClientMessageEx(playerid, COLOR_REN, "MAPPING: "WHITE"Anda telah mengubah nama folder mapping "YELLOW"%s"WHITE" menjadi "LG"%s", foldername, newfoldername);
        }
        else if(!strcmp(option, "goto", true)) 
        {
            if(isnull(string))
                return SendUsageMessage(playerid, "/map goto [mapping name]");

            if(!IsValidMappingFolder(string))
                return SendErrorMessage(playerid, "Tidak ada mapping yang disimpan dengan folder %s", string);
            
            new folderid = GetMappingFolderID(string);
            SetPlayerPos(playerid, mappingInfo[folderid][mappingLocationX], mappingInfo[folderid][mappingLocationY], mappingInfo[folderid][mappingLocationZ]);
            SendClientMessageEx(playerid, COLOR_REN, "TELEPORT: "WHITE"Teleportasi ke mapping "YELLOW"%s", string);
        }
        else if(!strcmp(option, "info", true)) 
        {
            if(isnull(string))
                return SendUsageMessage(playerid, "/map info [mapping name]");

            if(!IsValidMappingFolder(string))
                return SendErrorMessage(playerid, "Tidak ada mapping yang disimpan dengan folder %s", string);

            new folderid = GetMappingFolderID(string), message[3000];
            format(message, sizeof(message), "%s"WHITE"Status:\t%s\n", message, mappingInfo[folderid][mappingLoaded] ? ""LG"Loaded" : ""LR"Unloaded");
            format(message, sizeof(message), "%s"WHITE"Name:\t"YELLOW"%s\n", message, mappingInfo[folderid][mappingName]);
            format(message, sizeof(message), "%s"WHITE"Creator:\t"LR"%s\n", message, mappingInfo[folderid][mappingCreator]);
            format(message, sizeof(message), "%s"WHITE"Date:\t"LB"%s\n", message, TimestampToDateString(mappingInfo[folderid][mappingCreateAt]));
            format(message, sizeof(message), "%s"WHITE"Location:\t"GREY"%f %f %f\n", message, mappingInfo[folderid][mappingLocationX], mappingInfo[folderid][mappingLocationY], mappingInfo[folderid][mappingLocationZ]);
            format(message, sizeof(message), "%s"WHITE"Interior / World:\t"GREY"%d / %d\n", message, mappingInfo[folderid][mappingInterior], mappingInfo[folderid][mappingWorld]);
            format(message, sizeof(message), "%s"WHITE"Object Total:\t"LG"%d Objects\n", message, mappingInfo[folderid][mappingObjectTotal]);
            Dialog_Show(playerid, Mapping_Info, DIALOG_STYLE_TABLIST, "Mapping Info", message, "Close", "");
        }
        else syntax = false;
    }

    if(syntax == false) 
    {
        SendUsageMessage(playerid, "/map [option]");
        SendClientMessageEx(playerid, COLOR_REN, "OPTION: list load unload delete rename goto info");
    }
    return 1;
}