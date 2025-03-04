hook OnPlayerConnect(playerid) 
{
    LoadPlayerMechanicTD(playerid);

    player_inspectveh_id[playerid] = INVALID_VEHICLE_ID;
    player_hasinspectveh[playerid] = false;
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyPlayerMechanicTD(playerid);
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if(playertextid == mechmenu_repair_btn[playerid]) MechMenu_Repair(playerid, player_inspectveh_id[playerid]);
    else if(playertextid == mechmenu_color_btn[playerid]) MechMenu_Color(playerid, player_inspectveh_id[playerid]);
    else if(playertextid == mechmenu_upgrade_btn[playerid]) MechMenu_Upgrade(playerid, player_inspectveh_id[playerid]);
    else if(playertextid == mechamenu_back[playerid]) ShowPlayerMechMenu(playerid, player_inspectveh_id[playerid]);
    return 1;
}