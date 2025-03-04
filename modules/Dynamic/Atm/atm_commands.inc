YCMD:atms(playerid, params[], help)
{
	if(!IsPlayerAdmin(playerid, Manager))
		return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");

	new action[50], string[200], bool:syntax = true;
    if(sscanf(params, "s[50]S()[200]", action, string))
    {
        syntax = false;
    }
    else 
    {
		if(!strcmp(action, "create", true))
		{
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);

			new atmid = CreateAtm(GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), x, y, z);
			SendClientMessageEx(playerid, COLOR_REN, "ATM: "WHITE"Created atm machine "YELLOW"id %d", atmid);
		}
		else if(!strcmp(action, "edit", true))
		{
			new atmid = IsPlayerInAtm(playerid);

			if(atmid == -1)
				return SendErrorMessage(playerid, "Tidak ada mesin atm disekitar anda!");

			ShowPlayerEditObjectPosition(playerid, EDITOBJECT_ATM, atmInfo[atmid][atmObjectID]);
			player_edit_atmid[playerid] = atmid;
		}
		else if(!strcmp(action, "delete", true))
		{
			new atmid = IsPlayerInAtm(playerid);

			if(atmid == -1)
				return SendErrorMessage(playerid, "Tidak ada mesin atm disekitar anda!");

			DeleteAtm(atmid);
			SendClientMessageEx(playerid, COLOR_REN, "ATM: "WHITE"Deleted atm "RED"machine %d", atmid);
		}
		else syntax = false;
	}

	if(syntax == false)
	{
		SendUsageMessage(playerid, "/atms [action]");
        SendClientMessageEx(playerid, COLOR_GREY, "ACTION: create edit delete");
	}
	return 1;
}