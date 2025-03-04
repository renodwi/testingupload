/*

==> Gate (Dialogs)
Contains Dialogs for the gate system.

Credit: Rndwst
Created On: 14 January 2023

*/

new playereditgate_type[MAX_PLAYERS],
    playereditgate_gateid[MAX_PLAYERS];

hook OnPlayerConnect(playerid)
{
    playereditgate_type[playerid] = -1;
    playereditgate_gateid[playerid] = -1;
    return 1;
}

stock GetPlayerEditGateID(playerid)
{
    return playereditgate_gateid[playerid];
}

stock ShowPlayerEditGate(playerid, gateid, type)
{
    playereditgate_type[playerid] = type;
    playereditgate_gateid[playerid] = gateid;
    
    switch(type)
    {
        case GATEEDIT_LIST:
        {
            new message[3000];
            format(message, sizeof(message), "%sOwner\n", message);
            format(message, sizeof(message), "%sPassword\n", message);
            format(message, sizeof(message), "%sModel\n", message);
            format(message, sizeof(message), "%sPrice\n", message);
            format(message, sizeof(message), "%sPosition\n", message);
            format(message, sizeof(message), "%sMove Position\n", message);
            Dialog_Show(playerid, GateEdit_List, DIALOG_STYLE_LIST, va_return("Edit Gate %d", gateid), message, "Select", "Close");
        }
        case GATEEDIT_OWNERTYPE:
        {
            new message[3000];
            Loop(i, sizeof(ownertypeString))
            {
                format(message, sizeof(message), "%s%s\n", message, ownertypeString[i]);
            }
            Dialog_Show(playerid, GateEdit_OwnerType, DIALOG_STYLE_LIST, va_return("Edit Gate %d > Owner Type", gateid), message, "Select", "Close");
        }
        case GATEEDIT_OWNERPLAYER:
        {
            new message[3000];
            format(message, sizeof(message), ""WHITE"Enter player name / id for the owner this gate");
            Dialog_Show(playerid, GateEdit_OwnerPlayer, DIALOG_STYLE_INPUT, va_return("Edit Gate %d > Owner Type > Owner Name", gateid), message, "Select", "Close");
        }
        case GATEEDIT_OWNERFACTION:
        {
            new message[3000];
            Loop(i, sizeof(factionNames))
            {
                format(message, sizeof(message), "%s%s\n", message, factionNames[i]);
            }
            Dialog_Show(playerid, GateEdit_OwnerFaction, DIALOG_STYLE_INPUT, va_return("Edit Gate %d > Owner Type > Owner Faction", gateid), message, "Select", "Close");
        }
        case GATEEDIT_PASSWORD:
        {
            new message[3000];
            format(message, sizeof(message), ""WHITE"Enter new password for gate password");
            Dialog_Show(playerid, GateEdit_Password, DIALOG_STYLE_INPUT, va_return("Edit Gate %d > Password", gateid), message, "Select", "Close");
        }
        case GATEEDIT_MODEL:
        {
            ShowPlayerGateModel(playerid);
        }
        case GATEEDIT_PRICE:
        {
            new message[3000];
            format(message, sizeof(message), ""WHITE"Enter new price for gate pay price (Money Format)");
            Dialog_Show(playerid, GateEdit_Price, DIALOG_STYLE_INPUT, va_return("Edit Gate %d > Pay Price", gateid), message, "Select", "Close");
        }
        case GATEEDIT_POSITION:
        {
            ShowPlayerEditObjectPosition(playerid, EDITINGOBJECT_GATEPOSITION, GetGateObjectID(gateid));
        }
        case GATEEDIT_MOVEPOSITION:
        {
            new Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz;
            GetGateMovePosition(gateid, x, y, z);
            GetGateMoveRotation(gateid, rx, ry, rz);

            SetDynamicObjectPos(GetGateObjectID(gateid), x, y, z);
            SetDynamicObjectRot(GetGateObjectID(gateid), rx, ry, rz);
            ShowPlayerEditObjectPosition(playerid, EDITINGOBJECT_GATEMOVEPOSITION, GetGateObjectID(gateid));
        }
    }
    return 1;
}

Dialog:GateEdit_List(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    else 
    {
        new gateid = GetPlayerEditGateID(playerid);
        switch(listitem) 
        {
            case 0: ShowPlayerEditGate(playerid, gateid, GATEEDIT_OWNERTYPE);
            case 1: ShowPlayerEditGate(playerid, gateid, GATEEDIT_PASSWORD);
            case 2: ShowPlayerEditGate(playerid, gateid, GATEEDIT_MODEL);
            case 3: ShowPlayerEditGate(playerid, gateid, GATEEDIT_PRICE);
            case 4: ShowPlayerEditGate(playerid, gateid, GATEEDIT_POSITION);
            case 5: ShowPlayerEditGate(playerid, gateid, GATEEDIT_MOVEPOSITION);
        }
    }
    return 1;
}

Dialog:GateEdit_OwnerType(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowPlayerEditGate(playerid, GetPlayerEditGateID(playerid), GATEEDIT_LIST);
    else 
    {
        new gateid = GetPlayerEditGateID(playerid);
        SetGateOwner(gateid, listitem, "None");

        if(GetGateOwnerType(gateid) == GATEOWNER_PUBLIC) SetGateOwner(gateid, listitem, "Public"), SendClientMessageEx(playerid, COLOR_REN, "GATE-OWNER: "WHITE"Changed "YELLOW"gate %d"WHITE" owner to "LG"Public", gateid);
        if(GetGateOwnerType(gateid) == GATEOWNER_PLAYER) ShowPlayerEditGate(playerid, gateid, GATEEDIT_OWNERPLAYER);
        if(GetGateOwnerType(gateid) == GATEOWNER_FACTION) ShowPlayerEditGate(playerid, gateid, GATEEDIT_OWNERFACTION);
        if(GetGateOwnerType(gateid) == GATEOWNER_TOLL) SetGateOwner(gateid, listitem, "Toll"), SendClientMessageEx(playerid, COLOR_REN, "GATE-OWNER: "WHITE"Changed "YELLOW"gate %d"WHITE" owner to "LG"Public", gateid);
    }
    return 1;
}

Dialog:GateEdit_OwnerPlayer(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowPlayerEditGate(playerid, GetPlayerEditGateID(playerid), GATEEDIT_OWNERTYPE);
    else
    {
        new gateid = GetPlayerEditGateID(playerid);

        new owner;
        if(sscanf(inputtext, "u", owner))
            return ShowPlayerEditGate(playerid, gateid, GATEEDIT_OWNERPLAYER);

        if(!IsPlayerSpawned(owner))
            return SendErrorMessage(playerid, "Player tidak terdeteksi!");

        SetGateOwner(gateid, GATEOWNER_PLAYER, playerInfo[owner][playerName]);
        SendClientMessageEx(playerid, COLOR_REN, "GATE-OWNER: "WHITE"Changed "YELLOW"gate %d"WHITE" owner to "LG"Player %s", gateid, playerInfo[owner][playerName]);
    }
    return 1;
}

Dialog:GateEdit_OwnerFaction(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowPlayerEditGate(playerid, GetPlayerEditGateID(playerid), GATEEDIT_OWNERTYPE);
    else 
    {
        new gateid = GetPlayerEditGateID(playerid);
        SetGateOwner(gateid, GATEOWNER_FACTION, factionNames[listitem]);
        SendClientMessageEx(playerid, COLOR_REN, "GATE-OWNER: "WHITE"Changed "YELLOW"gate %d"WHITE" owner to "LG"Faction %s", gateid, factionNames[listitem]);
    }
    return 1;
}

Dialog:GateEdit_Password(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowPlayerEditGate(playerid, GetPlayerEditGateID(playerid), GATEEDIT_LIST);
    else 
    {
        new gateid = GetPlayerEditGateID(playerid);
        
        new password[8];
        if(sscanf(inputtext, "s[8]", password))
            return ShowPlayerEditGate(playerid, gateid, GATEEDIT_PASSWORD);

        SetGatePassword(gateid, password);
    }
    return 1;
}

Dialog:GateEdit_Price(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowPlayerEditGate(playerid, GetPlayerEditGateID(playerid), GATEEDIT_LIST);
    else 
    {
        new gateid = GetPlayerEditGateID(playerid);

        if(!IsMoneyFormat(inputtext))
            return ShowPlayerEditGate(playerid, gateid, GATEEDIT_PRICE);

        SetGatePrice(gateid, StringToMoney(inputtext));
    }
    return 1;
}