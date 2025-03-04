YCMD:pickup(playerid, params[], help) 
{
    if(!IsPlayerAdmin(playerid, Manager))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");
        
    new option[50], string[200], bool:syntax = true;
    if(sscanf(params, "s[50]S()[50]", option, string))
    {
        syntax = false;
    }
    else
    {
        if(!strcmp(option, "create", true) || !strcmp(option, "make", true))
        {
            new model;
            if(sscanf(string, "d", model))
                return SendUsageMessage(playerid, "/pickup create [model id]");

            player_createpickup_model[playerid] = model;

            AddDialogListitem(playerid, "Name\tDescription");
            Loop(i, sizeof(e_pickupinfo))
            {
                AddDialogListitem(playerid, ""LB"%s\t"WHITE"%s", e_pickupinfo[i][e_pickupname], e_pickupinfo[i][e_pickupdescription]);
            }
            ShowPlayerDialogPages(playerid, "Create_Pickup", DIALOG_STYLE_TABLIST_HEADERS, "Create Pickup", "Select", "Close", 10);
        }
        else if(!strcmp(option, "delete", true) || !strcmp(option, "remove", true))
        {
            new pickupid = -1;
            foreach(new i : Pickup) 
            {
                if(IsPlayerInRangeOfPoint(playerid, 2.0, pickupInfo[i][pickupPositionX], pickupInfo[i][pickupPositionY], pickupInfo[i][pickupPositionZ]))
                {
                    pickupid = i;
                    break;
                }
            }

            if(pickupid == -1) 
            {
                if(sscanf(string, "d", pickupid))
                    return SendUsageMessage(playerid, "/pickup create [pickup id]");
            }

            if(pickupid != -1 && Iter_Contains(Pickup, pickupid))
            {
                DeletePickup(pickupid);
                SendClientMessageEx(playerid, COLOR_REN, "PICKUP: "WHITE"Anda telah menghapus "LR"pickup %d", pickupid);
            }
            else SendErrorMessage(playerid, "Pickup tidak terdeteksi!");
        }
        else if(!strcmp(option, "goto", true))
        {
            new pickupid = -1;
            foreach(new i : Pickup) 
            {
                if(IsPlayerInRangeOfPoint(playerid, 2.0, pickupInfo[i][pickupPositionX], pickupInfo[i][pickupPositionY], pickupInfo[i][pickupPositionZ]))
                {
                    pickupid = i;
                    break;
                }
            }

            if(pickupid == -1) 
            {
                if(sscanf(string, "d", pickupid))
                    return SendUsageMessage(playerid, "/pickup create [pickup id]");
            }

            if(pickupid != -1 && Iter_Contains(Pickup, pickupid))
            {
                SetPlayerPos(playerid, pickupInfo[pickupid][pickupPositionX], pickupInfo[pickupid][pickupPositionY], pickupInfo[pickupid][pickupPositionZ]);
                SetPlayerInterior(playerid, pickupInfo[pickupid][pickupInterior]);
                SetPlayerVirtualWorld(playerid, pickupInfo[pickupid][pickupWorld]);
                SendClientMessageEx(playerid, COLOR_REN, "TELEPORT: "WHITE"Teleportasi ke "YELLOW"pickup %d", pickupid);
            }
            else SendErrorMessage(playerid, "Pickup tidak terdeteksi!");
        }
        else if(!strcmp(string, "list", true))
        {
            AddDialogListitem(playerid, "Type\tLocation\tCoordinates");
            foreach(new i : Pickup)
            {
                if(Iter_Contains(Pickup, i)) 
                {
                    AddDialogListitem(playerid, "%s\t%s\t(%f %f %f)", e_pickupinfo[pickupInfo[i][pickupType]][e_pickupname], GetLocation(pickupInfo[i][pickupPositionX], pickupInfo[i][pickupPositionY], pickupInfo[i][pickupPositionZ]), pickupInfo[i][pickupPositionX], pickupInfo[i][pickupPositionY], pickupInfo[i][pickupPositionZ]);
                }
            }
            ShowPlayerDialogPages(playerid, "Pickup_List", DIALOG_STYLE_TABLIST_HEADERS, "Pickup List", "Teleport", "Close", 10);
        }
        else syntax = false;
    }

    if(syntax == false) 
    {
        SendUsageMessage(playerid, "/pickup [option]");
        SendClientMessageEx(playerid, COLOR_GREY, "OPTION: create delete goto list");
    }
    return 1;
}