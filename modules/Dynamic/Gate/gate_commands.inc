/*

==> Gate (Command)
Contains Command for the gate system.

Credit: Rndwst
Created On: 14 January 2023

*/

YCMD:gate(playerid, params[], help)
{
    if(!IsPlayerNearGate(playerid)) return 1;

    new gateid = -1;
    gateid = GetNearestGate(playerid);

    if(IsGateOpened(gateid)) CloseGate(gateid);
    else if(IsGateClosed(gateid)) OpenGate(gateid);
    return 1;
}

YCMD:gates(playerid, params[], help)
{
    if(!IsPlayerAdmin(playerid, Admin3))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk command ini!");
        
    new menu[120], string[300], bool:syntax = true;
    if(sscanf(params, "s[120]S()[120]", menu, string))
    {
        syntax = false;
    }
    else 
    {
        if(!strcmp(menu, "create", true))
        {
            new Float:x, Float:y, Float:z, interior, world, gateid;
            GetPlayerPos(playerid, x, y, z);
            interior = GetPlayerInterior(playerid);
            world = GetPlayerVirtualWorld(playerid);

            gateid = CreateGate(x + 2.0, y, z, interior, world);
            SendClientMessageEx(playerid, COLOR_REN, "CREATE-GATE: "WHITE"Created "YELLOW"gate %d", gateid);
        }
        else if(!strcmp(menu, "edit", true))
        {
            new near_gateid = -1;
            foreach(new i : Gate) {
                new Float:x, Float:y, Float:z;
                GetGatePosition(i, x, y, z);
                if(IsPlayerInRangeOfPoint(playerid, 2.0, x, y, z)) {
                    near_gateid = i;
                    break;
                }
            }

            if(near_gateid == -1)
            {
                new gateid;
                if(sscanf(string, "d", gateid))
                    return SendUsageMessage(playerid, "/gates edit [gateid]");

                if(!Iter_Contains(Gate, gateid))
                    return SendErrorMessage(playerid, "ID Gate %d tidak ada", gateid);

                ShowPlayerEditGate(playerid, gateid, GATEEDIT_LIST);
            }
            else 
            {
                ShowPlayerEditGate(playerid, near_gateid, GATEEDIT_LIST);
            }
        }
        else if(!strcmp(menu, "movetest", true))
        {
            new near_gateid = -1;
            foreach(new i : Gate) {
                new Float:x, Float:y, Float:z;
                GetGatePosition(i, x, y, z);
                if(IsPlayerInRangeOfPoint(playerid, 2.0, x, y, z)) {
                    near_gateid = i;
                    break;
                }
            }

            if(near_gateid == -1)
            {
                new gateid;
                if(sscanf(string, "d", gateid))
                    return SendUsageMessage(playerid, "/gates movetest [gateid]");

                if(!Iter_Contains(Gate, gateid))
                    return SendErrorMessage(playerid, "ID Gate %d tidak ada", gateid);

                OpenGate(gateid);
            }
            else 
            {
                OpenGate(near_gateid);
            }
        }
        else if(!strcmp(menu, "goto", true))
        {   
            new near_gateid = -1;
            foreach(new i : Gate) {
                new Float:x, Float:y, Float:z;
                GetGatePosition(i, x, y, z);
                if(IsPlayerInRangeOfPoint(playerid, 2.0, x, y, z)) {
                    near_gateid = i;
                    break;
                }
            }
            if(near_gateid == -1)
            {
                new gateid;
                if(sscanf(string, "d", gateid))
                    return SendUsageMessage(playerid, "/gates goto [gateid]");

                if(!Iter_Contains(Gate, gateid))
                    return SendErrorMessage(playerid, "ID Gate %d tidak ada", gateid);

                SendPlayerToGate(playerid, gateid);
            }
            else 
            {
                SendPlayerToGate(playerid, near_gateid);
            }
        }
        else if(!strcmp(menu, "delete", true))
        {
            new near_gateid = -1;
            foreach(new i : Gate) {
                new Float:x, Float:y, Float:z;
                GetGatePosition(i, x, y, z);
                if(IsPlayerInRangeOfPoint(playerid, 2.0, x, y, z)) {
                    near_gateid = i;
                    break;
                }
            }

            if(near_gateid == -1)
            {
                new gateid;
                if(sscanf(string, "d", gateid))
                    return SendUsageMessage(playerid, "/gates delete [gateid]");

                DeleteGate(gateid);
                SendClientMessageEx(playerid, COLOR_REN, "DELETE-GATE: "WHITE"Deleted "RED"gate %d", gateid);
            }
            else 
            {
                DeleteGate(near_gateid);
                SendClientMessageEx(playerid, COLOR_REN, "DELETE-GATE: "WHITE"Deleted "RED"gate %d", near_gateid);
            }
        }
        else syntax = false;
    }

    if(syntax == false)
    {
        SendUsageMessage(playerid, "/gates [menu] [string]");
        SendClientMessageEx(playerid, COLOR_REN, "MENU: create, edit, movetest, goto, delete");
        // model, position, moveposition, movetest, gethere, goto, price, owner
    }
    return 1;
}