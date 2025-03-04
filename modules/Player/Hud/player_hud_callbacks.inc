hook OnPlayerConnect(playerid)
{
    player_hud_status[playerid] = true;
    return 1;
}

hook OneSecond()
{
    foreach(new playerid : Player)
    {
        if(IsPlayerSpawned(playerid))
        {
            if(player_hud_status[playerid] == true)
            {
                UpdatePlayerInfoHud(playerid);
            }
        }
    }
    return 1;
}