hook OnGameModeInit()
{
    PlayerLevelInit();
    return 1;
}

hook OnPlayerConnect(playerid)
{
    playerInfo[playerid][playerLevel] = 0;
    playerInfo[playerid][playerXP] = 0;
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    playerInfo[playerid][playerLevel] = 0;
    playerInfo[playerid][playerXP] = 0;
    return 1;
}

hook OneSecond()
{
    foreach(new playerid : Player) 
    {
        if(IsPlayerSpawned(playerid))
        {
            for(new i = 1; i <= MAX_LEVELS; i++)
            {
                if(playerInfo[playerid][playerLevel] == i && playerInfo[playerid][playerXP] >= player_xplevelneed[playerInfo[playerid][playerLevel] + 1]) 
                {
                    playerInfo[playerid][playerXP] = player_xplevelneed[playerInfo[playerid][playerLevel] + 1];
                    playerInfo[playerid][playerLevel] += 1;
                    CallLocalFunction("OnPlayerLevelUP", "d", playerid);
                }
                else continue;
            }
        }
    }
    return 1;
}