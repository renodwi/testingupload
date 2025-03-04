hook OnPlayerConnect(playerid)
{
    created_hud_modern_speedo_td[playerid] = false;
    showed_hud_modern_speedo_td[playerid] = false;
    CreateHudModernSpeedoTD(playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyHudModernSpeedoTD(playerid);
    return 1;
}