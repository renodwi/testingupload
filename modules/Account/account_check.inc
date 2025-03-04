#include <YSI_Coding\y_hooks>

public OnPlayerRequestClass(playerid, classid)
{
    SpawnPlayer(playerid);
    TogglePlayerSpectating(playerid, 1);
    SetTimerEx("CheckPlayerAccount", 500, false, "d", playerid);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    accountInfo[playerid][accountIsSpawned] = false;
    return 1;
}

function CheckPlayerAccount(playerid)
{
    new query[200];
    mysql_format(sql, query, sizeof(query), "SELECT * FROM `accounts` WHERE `username` = '%e'", GetName(playerid));
    mysql_tquery(sql, query, "CheckingPlayerAccount", "d", playerid);

    ClearPlayerMessage(playerid);
    SetPlayerCameraLoginPosition(playerid);
    return 1;
}

function CheckingPlayerAccount(playerid)
{
    if(cache_num_rows())
    {
        cache_get_value_int(0, "id", accountInfo[playerid][accountDBID]);
        cache_get_value(0, "username", accountInfo[playerid][accountName]);
        cache_get_value(0, "password", accountInfo[playerid][accountPassword]);
        cache_get_value(0, "email", accountInfo[playerid][accountEmail]);
        cache_get_value(0, "ip", accountInfo[playerid][accountIP]);
        cache_get_value(0, "registerdate", _:accountInfo[playerid][accountRegisterDate]);
        cache_get_value_int(0, "adminlevel", accountInfo[playerid][accountAdminLevel]);
        cache_get_value(0, "adminname", accountInfo[playerid][accountAdminName]);

        SetPlayerName(playerid, accountInfo[playerid][accountName]);
        ShowPlayerLoginDialog(playerid, 0);
    }
    else 
    {
        new query[200];
        mysql_format(sql, query, sizeof(query), "SELECT * FROM `characters` WHERE `name` = '%e'", GetName(playerid));
        mysql_tquery(sql, query, "CheckingCharacterName", "d", playerid);
    }
    return 1;
}

function CheckingCharacterName(playerid) 
{
    if(cache_num_rows())
    {
        new account_id, query[200];
        cache_get_value_int(0, "account_id", account_id);
        mysql_format(sql, query, sizeof(query), "SELECT * FROM `accounts` WHERE `id` = '%d'", account_id);
        mysql_tquery(sql, query, "CheckingPlayerAccount", "d", playerid);
    }
    else
    {
        ShowPlayerRegisterOption(playerid);
    }
    return 1;
}

stock IsPlayerSpawned(playerid)
{
    new bool:status = true;
    if(playerid == INVALID_PLAYER_ID) status = false;
    else if(accountInfo[playerid][accountIsSpawned] == false) status = false;
    else status = true;
    return status;
}