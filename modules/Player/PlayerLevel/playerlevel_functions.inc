function OnPlayerLevelUP(playerid) 
{
    SetPlayerScore(playerid, playerInfo[playerid][playerLevel]);
    SendClientMessageEx(playerid, COLOR_REN, "LEVEL: "YELLOW"Selamat!"WHITE" level anda naik menjadi level "LG"%d "LB"(%d/%d)", playerInfo[playerid][playerLevel], playerInfo[playerid][playerXP], GetXPNeedForNextLevel(playerInfo[playerid][playerLevel]));
    UpdateCharacterData(playerid);
    return 1;
}

stock PlayerLevelInit()
{
    for(new i = 1; i <= MAX_LEVELS; i++)
    {
        player_xplevelneed[i] = 0 + (i * 50);
    }
    return 1;
}

stock GetXPNeedForNextLevel(current_level) 
{
    new amount = 0;

    if(current_level >= MAX_LEVELS)
    {
        amount = player_xplevelneed[MAX_LEVELS];
    } 
    else 
    {
        amount = player_xplevelneed[current_level + 1];
    }
    return amount;
} 

stock AddPlayerXP(playerid, amount) 
{
    if(playerInfo[playerid][playerXP] >= player_xplevelneed[MAX_LEVELS]) amount = player_xplevelneed[MAX_LEVELS] -playerInfo[playerid][playerXP];

    playerInfo[playerid][playerXP] += amount;
    UpdateCharacterData(playerid);
    return 1;
}