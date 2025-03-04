YCMD:sweeper(playerid, params[], help) 
{
    if(!IsPlayerSpawned(playerid)) return 1;

    if(!IsPlayerAdmin(playerid, Manager))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");

    if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0)
        return SendErrorMessage(playerid, "Akses untuk mengedit sweeper hanya untuk Interior: 0 dan Virtual World: 0");

    if(player_sweepermark_editmode[playerid] == true) 
    {
        if(isnull(params))
        {
            new slot = CreateSweeperMarkByPlayer(playerid);
            if(slot == -1) return SendErrorMessage(playerid, "Anda tidak dapat membuat mark (checkpoint) lagi karena telah mencapai batas maksimum");
        }
        else if(!strcmp(params, "end", true))
        {
            StopPlayerEditSweeperMarkMode(playerid);
        }
        return 1;
    }
    else if(player_editingsweeperroute_loc[playerid] == true) 
    {
        new Float:x, Float:y, Float:z;
        GetPlayerPos(playerid, x, y, z);
        SweeperRouteEdit_SetLoc(playerid, x, y, z);
        ShowPlayerEditSweeperRoute(playerid, 0);

        player_editingsweeperroute_loc[playerid] = false;
        return 1;
    }
    else
    {
        ShowPlayerSweeperRouteMenu(playerid);
    }
    return 1;
}