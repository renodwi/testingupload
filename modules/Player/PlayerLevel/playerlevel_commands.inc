YCMD:levels(playerid, params[], help) 
{
    new message[1200];
    format(message, sizeof(message), "Level\tXP Needs\n");

    for(new i = 1; i <= MAX_LEVELS; i ++)
    {
        if(i == playerInfo[playerid][playerLevel])
        {
            format(message, sizeof(message), "%s%d\t%d "YELLOW"Level saat ini "LB"(%d / %d)\n", message, i, player_xplevelneed[i], playerInfo[playerid][playerXP], GetXPNeedForNextLevel(playerInfo[playerid][playerLevel]));
        }
        else
        {
            format(message, sizeof(message), "%s%d\t%d\n", message, i, player_xplevelneed[i]);
        }
    }
    Dialog_Show(playerid, Levels, DIALOG_STYLE_TABLIST_HEADERS, "Levels", message, "Close", "");
    return 1;
}

YCMD:setlevel(playerid, params[], help) 
{
    if(!IsPlayerAdmin(playerid, Admin3))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");

    new toplayer, level;
    if(sscanf(params, "ud", toplayer, level))
        return SendUsageMessage(playerid, "/setlevel [player name / playerid] [level (maksimal level %d)]", MAX_LEVELS);

    if(!IsPlayerSpawned(toplayer))
        return SendErrorMessage(playerid, "Player tujuan tidak terdeteksi!");

    if(level > MAX_LEVELS)
        return SendErrorMessage(playerid, "Maksimal level yang dapat dimiliki player adalah %d!", MAX_LEVELS);

    playerInfo[toplayer][playerLevel] = level;
    playerInfo[toplayer][playerXP] = player_xplevelneed[level];

    SendClientMessageEx(playerid, COLOR_REN, "LEVEL: "WHITE"Anda telah mengatur level "YELLOW"%s"WHITE" menjadi "LG"%d"LB" (%d/%d)", RemoveUnderscore(playerInfo[toplayer][playerName]), level, playerInfo[toplayer][playerXP], GetXPNeedForNextLevel(level));
    SendClientMessageEx(toplayer, COLOR_REN, "LEVEL: "LR"%s"WHITE" telah mengatur level anda menjadi "LG"%d"LB" (%d/%d)", GetAdminName(toplayer), level, playerInfo[toplayer][playerXP], GetXPNeedForNextLevel(level));
    return 1;
}

YCMD:setxp(playerid, params[], help) 
{
    if(!IsPlayerAdmin(playerid, Admin3))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");

    new toplayer, xp;
    if(sscanf(params, "ud", toplayer, xp))
        return SendUsageMessage(playerid, "/setlevel [player name / playerid] [xp (maksimal xp %d)]", player_xplevelneed[MAX_LEVELS]);

    if(!IsPlayerSpawned(toplayer))
        return SendErrorMessage(playerid, "Player tujuan tidak terdeteksi!");

    if(xp > player_xplevelneed[MAX_LEVELS])
        return SendErrorMessage(playerid, "Maksimal level yang dapat dimiliki player adalah %d!", player_xplevelneed[MAX_LEVELS]);
    
    playerInfo[toplayer][playerXP] = xp;

    SendClientMessageEx(playerid, COLOR_REN, "LEVEL: "WHITE"Anda telah mengatur xp "YELLOW"%s"WHITE" menjadi "LB"%d", RemoveUnderscore(playerInfo[toplayer][playerName]), playerInfo[toplayer][playerXP]);
    SendClientMessageEx(toplayer, COLOR_REN, "LEVEL: "LR"%s"WHITE" telah mengatur xp anda menjadi "LB"%d", GetAdminName(toplayer), playerInfo[toplayer][playerXP]);
    return 1;
}