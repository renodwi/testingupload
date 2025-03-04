DialogPages:Create_Pickup(playerid, response, listitem, inputtext[])
{
	if(!response) return 1;

    new Float:x, Float:y, Float:z, interior, world, pickupid;
    GetPlayerPos(playerid, x, y, z);
    interior = GetPlayerInterior(playerid);
    world = GetPlayerVirtualWorld(playerid);

    pickupid = MakePickup(player_createpickup_model[playerid], listitem, x, y, z, world, interior);
    SendClientMessageEx(playerid, COLOR_REN, "PICKUP: "WHITE"Anda telah membuat "YELLOW"pickup %d"WHITE" dengan tipe "LB"%s", pickupid, e_pickupinfo[pickupInfo[pickupid][pickupType]][e_pickupname]);
	return 1;
}

DialogPages:Pickup_List(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    if(!Iter_Contains(Pickup, listitem)) return 1;
    
    SetPlayerPos(playerid, pickupInfo[listitem][pickupPositionX], pickupInfo[listitem][pickupPositionY], pickupInfo[listitem][pickupPositionZ]);
    SetPlayerInterior(playerid, pickupInfo[listitem][pickupInterior]);
    SetPlayerVirtualWorld(playerid, pickupInfo[listitem][pickupInterior]);
    SendClientMessageEx(playerid, COLOR_REN, "TELEPORT: "WHITE"Teleportasi ke "YELLOW"pickup %d", listitem);
    return 1;
}