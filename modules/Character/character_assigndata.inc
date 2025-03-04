function AssignCharacterData(playerid) 
{
    #if defined DEBUG_MODE
        printf("[Character Load]: Load all '%s' data", GetName(playerid));
    #endif
    
    accountInfo[playerid][accountIsSpawned] = true;

    cache_get_value_int(0, "id", playerInfo[playerid][playerDBID]);
    cache_get_value(0, "name", playerInfo[playerid][playerName]);
    cache_get_value(0, "origin", playerInfo[playerid][playerOrigin]);
    cache_get_value_int(0, "gender", playerInfo[playerid][playerGender]);
    cache_get_value_int(0, "skin", playerInfo[playerid][playerSkin]);
    cache_get_value_int(0, "level", playerInfo[playerid][playerLevel]);
    cache_get_value_int(0, "xp", playerInfo[playerid][playerXP]);
    cache_get_value_int(0, "money", playerInfo[playerid][playerMoney]);
    cache_get_value_int(0, "lastseen", _:playerInfo[playerid][playerLastSeen]);
    cache_get_value_float(0, "position_x", playerInfo[playerid][playerPositionX]);
    cache_get_value_float(0, "position_y", playerInfo[playerid][playerPositionY]);
    cache_get_value_float(0, "position_z", playerInfo[playerid][playerPositionZ]);
    cache_get_value_float(0, "position_a", playerInfo[playerid][playerPositionA]);
    
    cache_get_value_float(0, "health", playerInfo[playerid][playerHealth]);
    cache_get_value_float(0, "armour", playerInfo[playerid][playerArmour]);
    cache_get_value_int(0, "virtual_world", playerInfo[playerid][playerVirtualWorld]);
    cache_get_value_int(0, "interior", playerInfo[playerid][playerInterior]);
    cache_get_value_int(0, "inbusiness", playerInfo[playerid][playerInBusiness]);
    cache_get_value_int(0, "hudmode", playerInfo[playerid][playerHudMode]);
    cache_get_value_float(0, "thrist", playerInfo[playerid][playerThrist]);
    cache_get_value_float(0, "hungry", playerInfo[playerid][playerHungry]);

    cache_get_value_int(0, "maxjob", playerInfo[playerid][playerMaxJob]);

    SetTimerEx("OnCharacterSpawn", 1000, false, "d", playerid);

    SetPlayerName(playerid, playerInfo[playerid][playerName]);

    if(playerInfo[playerid][playerMaxJob] == 0) playerInfo[playerid][playerMaxJob] = 1;
    LoadPlayerJob(playerid);
    return 1;
}

function OnCharacterSpawn(playerid) 
{
    TogglePlayerSpectating(playerid, false);
    SetPlayerPos(playerid, playerInfo[playerid][playerPositionX], playerInfo[playerid][playerPositionY], playerInfo[playerid][playerPositionZ]);
    SetCameraBehindPlayer(playerid);

    SetPlayerHealth(playerid, playerInfo[playerid][playerHealth]);
    SetPlayerArmour(playerid, playerInfo[playerid][playerArmour]);
    SetPlayerVirtualWorld(playerid, playerInfo[playerid][playerVirtualWorld]);
    SetPlayerInterior(playerid, playerInfo[playerid][playerInterior]);
    SetPlayerMoney(playerid, playerInfo[playerid][playerMoney]);
    SetPlayerSkin(playerid, playerInfo[playerid][playerSkin]);

    SendClientMessageEx(playerid, COLOR_REN, "SERVER: "WHITE"Halo "YELLOW"%s.", RemoveUnderscore(playerInfo[playerid][playerName]));
    SendClientMessageEx(playerid, COLOR_REN, "SERVER: "WHITE"Hari ini adalah %s", TimestampToDateString(Now()));
    SendClientMessageEx(playerid, COLOR_REN, "SERVER: "WHITE"Kamu terakhir mengunjungi kota pada "LB"%s.", TimestampToDateString(playerInfo[playerid][playerLastSeen]));
    SendClientMessageEx(playerid, COLOR_REN, "PESAN: "WHITE"%s", serverInfo[serverMotd]);

    LoadPlayerInventory(playerid);

    if(accountInfo[playerid][accountAdminLevel] > 0)
    {
        SendClientMessageEx(playerid, COLOR_REN, "ADMIN: "WHITE"Anda login sebagai "YELLOW"%s", GetAdminLevelName(accountInfo[playerid][accountAdminLevel]));
        SendClientMessageEx(playerid, COLOR_REN, "ADMIN-MOTD: "WHITE"%s", serverInfo[serverAdminMotd]);
    }
    return 1;
}