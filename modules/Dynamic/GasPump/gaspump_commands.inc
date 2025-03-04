YCMD:gaspump(playerid, params[], help) 
{
    if(!IsPlayerAdmin(playerid, Manager))
        return SendErrorMessage(playerid, "Kamu tidak memiliki akses untuk menggunakan command ini!");

    new action[50], string[200], bool:syntax = true;
    if(sscanf(params, "s[50]S()[200]", action, string)) 
    {
        syntax = false;
    }
    else
    {
        if(!strcmp(action, "create", true))
        {
            new Float:x, Float:y, Float:z, Float:a, world, interior, gaspumpid;
            GetPlayerPos(playerid, x, y, z);
            GetPlayerFacingAngle(playerid, a);
            world = GetPlayerVirtualWorld(playerid);
            interior = GetPlayerInterior(playerid);

            gaspumpid = CreateGasPump(x, y, z, 0.0, 0.0, a, world, interior);
            SendClientMessageEx(playerid, COLOR_REN, "GAS-PUMP: "WHITE"Kamu telah membuat "YELLOW"gaspump %d", gaspumpid);
        }
        else if(!strcmp(action, "edit", true))
        {
            new gaspumpid;
            if(GetPlayerNearestGasPump(playerid) == -1)
            {
                if(sscanf(string, "d", gaspumpid))
                    return SendUsageMessage(playerid, "/gaspump edit [gaspumpid]");
            }
            else 
            {
                gaspumpid = GetPlayerNearestGasPump(playerid);
            }

            if(!Iter_Contains(GasPump, gaspumpid))
                return SendErrorMessage(playerid, "Invalid gas pump ID!");

            ShowEditGasPumpMenu(playerid, gaspumpid);
        }
        else if(!strcmp(action, "delete", true))
        {
            new gaspumpid;
            if(GetPlayerNearestGasPump(playerid) == -1)
            {
                if(sscanf(string, "d", gaspumpid))
                    return SendUsageMessage(playerid, "/gaspump delete [gaspumpid]");
            }
            else 
            {
                gaspumpid = GetPlayerNearestGasPump(playerid);
            }

            if(!Iter_Contains(GasPump, gaspumpid))
                return SendErrorMessage(playerid, "Invalid gas pump ID!");

            DeleteGasPump(gaspumpid);
        }
        else if(!strcmp(action, "goto", true))
        {
            new gaspumpid;
            if(sscanf(string, "d", gaspumpid))
                return SendUsageMessage(playerid, "/gaspump goto [gaspumpid]");

            if(!Iter_Contains(GasPump, gaspumpid))
                return SendErrorMessage(playerid, "Invalid gas pump ID!");

            SetPlayerPos(playerid, gaspumpInfo[gaspumpid][gaspumpPositionX] + 0.2, gaspumpInfo[gaspumpid][gaspumpPositionY] + 0.2, gaspumpInfo[gaspumpid][gaspumpPositionZ]);
            SetPlayerInterior(playerid, gaspumpInfo[gaspumpid][gaspumpInterior]);
            SetPlayerVirtualWorld(playerid, gaspumpInfo[gaspumpid][gaspumpWorld]);

            SendClientMessageEx(playerid, COLOR_REN, "TELEPORT: "WHITE"Teleportasi ke "YELLOW"gas pump %d", gaspumpid);
        }
        else syntax = false;
    }

    if(syntax == false)
    {
        SendUsageMessage(playerid, "/gaspump [action]");
        SendClientMessageEx(playerid, COLOR_REN, "ACTION: create edit delete");
    }
    return 1;
}