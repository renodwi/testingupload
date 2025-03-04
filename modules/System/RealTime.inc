#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    RealTime_SetInterval(10000, false);
    RealTime_Sync();
    return 1;
}

hook OnWorldTimeUpdate(hour, minute)
{
    new
        str[16]
    ;

    format(str, sizeof(str), "worldtime %02d:%02d", hour, minute);
    SendRconCommand(str);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    SetPlayerTime(playerid, RealTime_GetHour(), RealTime_GetMinute());
    return 1;
}

hook OnPlayerRequestClass(playerid, classid)
{
    SetPlayerTime(playerid, RealTime_GetHour(), RealTime_GetMinute());
    return 1;
}

hook OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
    if (newinteriorid != 0)
    {
        RealTime_FreezeForPlayer(playerid);
        SetPlayerTime(playerid, 13, 0);
    }
    else
    {
        RealTime_UnfreezeForPlayer(playerid);
        RealTime_SyncPlayerWorldTime(playerid);
    }
    return 1;
}