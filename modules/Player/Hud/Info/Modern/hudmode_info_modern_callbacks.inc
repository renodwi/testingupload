hook OnPlayerConnect(playerid)
{
    created_hud_modern_info_td[playerid] = false;
    showed_hud_modern_info_td[playerid] = false;
    CreateHudModernInfoTD(playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyHudModernInfoTD(playerid);
    return 1;
}