YCMD:mapicon(playerid, params[], help) 
{
    if(!IsPlayerAdmin(playerid, Admin3))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");
        
    new option[50], string[250], bool:syntax = true;

    if(sscanf(params, "s[50]S()[250]", option, string))
    {
        syntax = false;
    }
    else
    {
        if(!strcmp(option, "create", true))
        {
            new type;
            if(sscanf(string, "d", type))
                return SendUsageMessage(playerid, "/mapicon create [type (check https://sampwiki.blast.hk/wiki/MapIcons)]");

            if(type < 0 || type > 63)
                return SendErrorMessage(playerid, "Tipe map icon tidak valid!");

            if(type == 0)
            {
                // ShowPlayerColorList(playerid, MapIcon_Color, "Choose Map Icon Color", "Select", "Close");
            }
            else
            {
                new mapiconid, Float:x, Float:y, Float:z;
                GetPlayerPos(playerid, x, y, z);
                mapiconid = MakeMapIcon(x, y, z, type, 0);
                SendClientMessageEx(playerid, COLOR_REN, "MAP-ICON: "WHITE"Anda telah membuat "YELLOW"mapicon %d"WHITE" dengan tipe "LB"%d", mapiconid, type);
            }
        }
        else if(!strcmp(option, "delete", true))
        {
            new mapiconid = -1;
            
            foreach(new i : MapIcon)
            {
                if(Iter_Contains(MapIcon, i), IsPlayerInRangeOfPoint(playerid, 10.0, mapiconInfo[i][mapiconPositionX], mapiconInfo[i][mapiconPositionY], mapiconInfo[i][mapiconPositionZ]))
                {
                    mapiconid = i;
                    break;
                }
            }

            if(mapiconid == -1)
            {
                if(sscanf(string, "d", mapiconid))
                    return SendUsageMessage(playerid, "/mapicon delete [mapiconid]");
            }

            DeleteMapIcon(mapiconid);
            SendClientMessageEx(playerid, COLOR_REN, "MAP-ICON: "WHITE"Anda telah menghapus "LR"mapicon %d", mapiconid);
        }
        else if(!strcmp(option, "goto", true))
        {
            new mapiconid;

            if(sscanf(string, "d", mapiconid))
                return SendUsageMessage(playerid, "/mapicon goto [mapiconid]");

            SetPlayerPos(playerid, mapiconInfo[mapiconid][mapiconPositionX], mapiconInfo[mapiconid][mapiconPositionY], mapiconInfo[mapiconid][mapiconPositionZ]);
            SetPlayerInterior(playerid, 0);
            SetPlayerVirtualWorld(playerid, 0);

            SendClientMessageEx(playerid, COLOR_REN, "TELEPORT: "WHITE"Anda teleportasi ke "YELLOW"mapicon %d", mapiconid);
        }
        else if(!strcmp(option, "list", true))
        {
            AddDialogListitem(playerid, "#   Type\tLocation");
            foreach(new i : MapIcon)
            {
                if(Iter_Contains(MapIcon, i)) 
                {
                    AddDialogListitem(playerid, ""WHITE"%d   %d\t"GREY"%s, %f %f %f", i, mapiconInfo[i][mapiconType], GetLocation(mapiconInfo[i][mapiconPositionX], mapiconInfo[i][mapiconPositionY], mapiconInfo[i][mapiconPositionZ]), mapiconInfo[i][mapiconPositionX], mapiconInfo[i][mapiconPositionY], mapiconInfo[i][mapiconPositionZ]);
                }
            }
            ShowPlayerDialogPages(playerid, "MapIcon_List", DIALOG_STYLE_TABLIST_HEADERS, "Map Icon List", "Teleport", "Close", 10);
        }
        else syntax = false;
    }

    if(syntax == false)
    {
        SendUsageMessage(playerid, "/mapicon [option]");
        SendClientMessageEx(playerid, COLOR_GREY, "OPTION: create delete goto list");
    }
    return 1;
}