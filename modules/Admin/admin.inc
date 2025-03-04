#include <YSI_Coding\y_hooks>

#define     Volunteer       1
#define     JuniorHelper    2
#define     Helper          3
#define     Admin1          4
#define     Admin2          5
#define     Admin3          6
#define     Manager         7
#define     Developer       8

#define GetAdminLevel(%0) accountInfo[%0][accountAdminLevel]

new bool:adminduty[MAX_PLAYERS] = false;
#define IsPlayerAdminDuty(%0) adminduty[%0]

hook OnPlayerConnect(playerid)
{
    adminduty[playerid] = false;
    return 1;
}

hook OnGameModeInit()
{
    AddAdminCommand(Manager, "/setadminname [toplayer] [admin name]", "Mengubah nama admin");
    return 1;
}

stock GetAdminLevelName(level)
{
	new adminlevel[128] = "Unknown";
	if(level == 0           ) adminlevel= "Non Admin";
	if(level == Volunteer   ) adminlevel= "Volunteer";
	if(level == JuniorHelper) adminlevel= "Junior Helper";
	if(level == Helper      ) adminlevel= "Helper";
	if(level == Admin1      ) adminlevel= "Admin Level 1";
	if(level == Admin2      ) adminlevel= "Admin Level 2";
	if(level == Admin3      ) adminlevel= "Admin Level 3";
	if(level == Manager     ) adminlevel= "Manager";
	if(level == Developer   ) adminlevel= "Developer";
    else adminlevel = "Developer";
	return adminlevel;
}

YCMD:setmedeveloper(playerid, params[], help)
{
    if(!IsPlayerAdmin(playerid))
        return SendErrorMessage(playerid, "Anda harus melakukan login terlebih dahulu pada RCON!");

    accountInfo[playerid][accountAdminLevel] = Developer;

    SendClientMessageEx(playerid, COLOR_REN, "DEVELOPER: "WHITE"Sekarang anda memiliki akses sebagai developer");

    SetPlayerAdminName(playerid, accountInfo[playerid][accountName]);

    new cQuery[500];
    mysql_format(sql, cQuery, sizeof(cQuery), "UPDATE `accounts` SET `adminlevel` = '%d' WHERE `id` = '%d'", Developer, accountInfo[playerid][accountDBID]);
    mysql_tquery(sql, cQuery);
    return 1;
}

stock n_IsPlayerAdmin(playerid, level)
{ 
    new bool:valid = false;
    if(GetAdminLevel(playerid) < level)
    {
        valid = false;
    } else 
    {
        valid = true;
    }
    return valid;
}

#if defined _ALS_IsPlayerAdmin
    #undef IsPlayerAdmin
#else
    #define _ALS_IsPlayerAdmin
#endif
#define IsPlayerAdmin n_IsPlayerAdmin

stock GetAdminName(playerid)
{
    new name[200];
    format(name, sizeof(name), "%s", accountInfo[playerid][accountAdminName]);
    return name;
}

hook OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
    if(adminduty[playerid] == true) {
        SetPlayerPosFindZ(playerid, fX, fY, fZ);
        SetPlayerInterior(playerid, 0);
        SetPlayerVirtualWorld(playerid, 0);
        SetTimerEx("TeleportToMap", 1200, false, "ifff", playerid, fX, fY, fZ);
    }
    return 1;
}

function TeleportToMap(playerid, Float:x, Float:y, Float:z)
{
    SetPlayerPos(playerid, x, y, z);
    return 1;
}

YCMD:setadminname(playerid, params[], help) 
{
    if(!IsPlayerAdmin(playerid, Manager))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");

    new toplayer, name[MAX_PLAYER_NAME];
    if(sscanf(params, "us[24]", toplayer, name))
        return SendUsageMessage(playerid, "/setadminname [player name / player ID] [admin name]");

    if(!IsPlayerSpawned(toplayer))
        return SendErrorMessage(playerid, "Invalid player!");

    if(!ContainsSpaceOrNumber(name))
        return SendErrorMessage(playerid, "Nama admin tidak valid!");

    SetPlayerAdminName(toplayer, name);
    SendClientMessageEx(playerid, COLOR_REN, "ADMIN-NAME: "WHITE"Anda telah mengubah nama admin "YELLOW"%s"WHITE" menjadi "LG"%s", accountInfo[toplayer][accountAdminName], name);
    return 1;
}

YCMD:aod(playerid, params[], help)
{
    if(IsPlayerAdminDuty(playerid))
    {
        adminduty[playerid] = false;
        SetPlayerName(playerid, playerInfo[playerid][playerName]);
        SetPlayerColor(playerid, COLOR_WHITE);
    }
    else
    {
        adminduty[playerid] = true;
        SetPlayerName(playerid, GetAdminName(playerid));
        SetPlayerColor(playerid, COLOR_RED);
    }
    return 1;
}

stock SetPlayerAdminName(playerid, const name[])
{
    SendClientMessageEx(playerid, COLOR_REN, "ADMIN-NAME: "WHITE"Nama admin anda di ubah menjadi "YELLOW"%s", name);
    SendClientMessageEx(playerid, COLOR_REN, "ADMIN-NAME: Anda dapat melakukan pengubahan nama dengan /setadminname (hanya admin dengan akses manager keatas)");

    format(accountInfo[playerid][accountAdminName], MAX_PLAYER_NAME, name);

    new cQuery[500];
    mysql_format(sql, cQuery, sizeof(cQuery), "UPDATE `accounts` SET `adminname` = '%e' WHERE `id` = '%d'", name, accountInfo[playerid][accountDBID]);
    mysql_tquery(sql, cQuery);
    return 1;
}