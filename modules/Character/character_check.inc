#include <YSI_Coding\y_hooks>

stock LoadPlayerCharacters(playerid) 
{
    new query[200];
    mysql_format(sql, query, sizeof(query), "SELECT * FROM `characters` WHERE `account_id` = '%d'", accountInfo[playerid][accountDBID]);
    mysql_tquery(sql, query, "CheckPlayerCharacters", "d", playerid);
    return 1;
}

function CheckPlayerCharacters(playerid) 
{
    if(!cache_num_rows())
    {
        Loop(i, MAX_PLAYER_CHARACTER)
        {
            playercharacterInfo[playerid][i][playercharacterExist] = false;
        }
    }
    else 
    {
        new rows  = cache_num_rows();
        Loop(i, rows) 
        {
            cache_get_value(i, "name", playercharacterInfo[playerid][i][playercharacterName]);
            cache_get_value_int(i, "level", playercharacterInfo[playerid][i][playercharacterLevel]);
            cache_get_value_int(i, "skin", playercharacterInfo[playerid][i][playercharacterSkin]);
            cache_get_value_int(i, "money", playercharacterInfo[playerid][i][playercharacterMoney]);
            cache_get_value_int(i, "gender", playercharacterInfo[playerid][i][playercharacterGender]);
            cache_get_value_int(i, "lastseen", _:playercharacterInfo[playerid][i][playercharacterLastSeen]);
            cache_get_value_float(i, "position_x", playercharacterInfo[playerid][i][playercharacterLastSeenPosX]);
            cache_get_value_float(i, "position_y", playercharacterInfo[playerid][i][playercharacterLastSeenPosY]);
            cache_get_value_float(i, "position_z", playercharacterInfo[playerid][i][playercharacterLastSeenPosZ]);

            playercharacterInfo[playerid][i][playercharacterExist] = true;
        }
    }
    return 1;
}