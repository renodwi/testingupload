#include <YSI_Coding\y_hooks>

new playeronline_count = 0;
hook OnPlayerConnect(playerid)
{
    playeronline_count = playeronline_count + 1;
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    playeronline_count = playeronline_count - 1;
    return 1;
}

stock GetOnlinePlayers()
{
    new count;
    count = playeronline_count;
    return count;
}