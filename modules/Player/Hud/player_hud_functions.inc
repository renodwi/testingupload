#define GetPlayerHudMode(%0) playerInfo[%0][playerHudMode]
#define GetHudModeName(%0) hud_name[%0]

stock SetPlayerHudStatus(playerid, bool:status)
{
    if(status == false)
    {
        if(player_hud_status[playerid] == false) return 1;
        
        player_hud_status[playerid] = false;
        // Hide All Hud Components
        HideModernHudInfo(playerid);
        // HideModernHudSpeedo(playerid);
    }
    else
    {
        if(player_hud_status[playerid] == true) return 1;

        player_hud_status[playerid] = true;
    }
    return 1;
}

stock SwitchPlayerHudMode(playerid, hudmode)
{
    SendClientMessageEx(playerid, COLOR_REN, "HUD: "WHITE"Mode HUD telah diubah dari "LB"%s"WHITE" menjadi "LG"%s", GetHudModeName(playerInfo[playerid][playerHudMode]), GetHudModeName(hudmode));
    
    playerInfo[playerid][playerHudMode] = hudmode;
    UpdateCharacterData(playerid);
    return 1;
}

stock UpdatePlayerInfoHud(playerid) 
{
    if(player_hud_status[playerid] == false) return 1;

    if(playerInfo[playerid][playerHudMode] == HUD_MODE_MODERN)
    {
        ShowModernHudInfo(playerid);
        if(IsPlayerInAnyVehicle(playerid)) ShowModernHudSpeedo(playerid);
        else HideModernHudSpeedo(playerid);
    }
    return 1;
}