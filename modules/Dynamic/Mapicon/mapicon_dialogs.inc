// ColorSelector:MapIcon_Color(playerid, response, color)
// {
//     new mapiconid, Float:x, Float:y, Float:z;
//     GetPlayerPos(playerid, x, y, z);
//     mapiconid = MakeMapIcon(x, y, z, 0, color);

//     SendClientMessageEx(playerid, COLOR_REN, "MAP-ICON: "WHITE"Anda telah membuat "YELLOW"mapicon %d"WHITE" dengan tipe "LB"0", mapiconid);
//     return 1;
// }

DialogPages:MapIcon_List(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    SetPlayerPos(playerid, mapiconInfo[listitem][mapiconPositionX], mapiconInfo[listitem][mapiconPositionY], mapiconInfo[listitem][mapiconPositionZ]);
    SetPlayerInterior(playerid, 0);
    SetPlayerVirtualWorld(playerid, 0);
    SendClientMessageEx(playerid, COLOR_REN, "TELEPORT: "WHITE"Anda teleportasi ke "YELLOW"mapicon %d", listitem);
    return 1;
}