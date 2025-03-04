stock UpdateCharacterData(playerid) 
{
    new Float:x, Float:y, Float:z, Float:a;
    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, playerInfo[playerid][playerPositionA]);
    GetPlayerHealth(playerid, playerInfo[playerid][playerHealth]);
    GetPlayerArmour(playerid, playerInfo[playerid][playerArmour]);
    playerInfo[playerid][playerVirtualWorld] = GetPlayerVirtualWorld(playerid);
    playerInfo[playerid][playerInterior] = GetPlayerInterior(playerid);

    playerInfo[playerid][playerLastSeen] = Now();
    
    new query[3090];
    mysql_format(sql, query, sizeof(query), "UPDATE `characters` SET");
    mysql_format(sql, query, sizeof(query), "%s `name` = '%e', ", query, playerInfo[playerid][playerName]);
    mysql_format(sql, query, sizeof(query), "%s `origin` = '%e', ", query, playerInfo[playerid][playerOrigin]);
    mysql_format(sql, query, sizeof(query), "%s `gender` = '%d', ", query, playerInfo[playerid][playerGender]);
    mysql_format(sql, query, sizeof(query), "%s `skin` = '%d', ", query, playerInfo[playerid][playerSkin]);
    mysql_format(sql, query, sizeof(query), "%s `level` = '%d', ", query, playerInfo[playerid][playerLevel]);
    mysql_format(sql, query, sizeof(query), "%s `xp` = '%d', ", query, playerInfo[playerid][playerXP]);
    mysql_format(sql, query, sizeof(query), "%s `money` = '%d', ", query, playerInfo[playerid][playerMoney]);
    mysql_format(sql, query, sizeof(query), "%s `lastseen` = '%d', ", query, gettime());
    mysql_format(sql, query, sizeof(query), "%s `position_x` = '%f', ", query, x);
    mysql_format(sql, query, sizeof(query), "%s `position_y` = '%f', ", query, y);
    mysql_format(sql, query, sizeof(query), "%s `position_z` = '%f', ", query, z);
    mysql_format(sql, query, sizeof(query), "%s `position_a` = '%f', ", query, a);
    mysql_format(sql, query, sizeof(query), "%s `health` = '%f', ", query, playerInfo[playerid][playerHealth]);
    mysql_format(sql, query, sizeof(query), "%s `armour` = '%f', ", query, playerInfo[playerid][playerArmour]);
    mysql_format(sql, query, sizeof(query), "%s `virtual_world` = '%d', ", query, playerInfo[playerid][playerVirtualWorld]);
    mysql_format(sql, query, sizeof(query), "%s `interior` = '%d', ", query, playerInfo[playerid][playerInterior]);
    mysql_format(sql, query, sizeof(query), "%s `inbusiness` = '%d', ", query, playerInfo[playerid][playerInBusiness]);
    mysql_format(sql, query, sizeof(query), "%s `hudmode` = '%d', ", query, playerInfo[playerid][playerHudMode]);
    mysql_format(sql, query, sizeof(query), "%s `thrist` = '%f', ", query, playerInfo[playerid][playerThrist]);
    mysql_format(sql, query, sizeof(query), "%s `hungry` = '%f', ", query, playerInfo[playerid][playerHungry]);
    mysql_format(sql, query, sizeof(query), "%s `maxjob` = '%d', ", query, playerInfo[playerid][playerMaxJob]);
    mysql_format(sql, query, sizeof(query), "%s `name` = '%e' WHERE `id` = '%d'", query, playerInfo[playerid][playerName], playerInfo[playerid][playerDBID]);
    mysql_tquery(sql, query);
    return 1;
}
