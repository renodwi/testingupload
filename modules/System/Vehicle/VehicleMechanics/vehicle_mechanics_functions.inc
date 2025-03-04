stock ShowPlayerMechMenu(playerid, vehicleid)
{
    PlayerTextDrawHide(playerid, mechmenu_repair_info[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_repair_component[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_repair_info2[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_repair_install[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_color_google[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_color_component[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_color_component2[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_color_change[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_color_componeed[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_color_info[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_upgrade_info[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_upgrade_component2[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_upgrade_install[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_upgrade_next[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_upgrade_component1[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_upgrade_component3[playerid]);

    PlayerTextDrawShow(playerid, mechmenu_box[playerid]);
    PlayerTextDrawShow(playerid, mechmenu_header_box[playerid]);
    PlayerTextDrawShow(playerid, mechmenu_header_icon[playerid]);
    PlayerTextDrawShow(playerid, mechmenu_close[playerid]);

    PlayerTextDrawSetString(playerid, mechmenu_header_name[playerid], "Menu Mekanik");
    PlayerTextDrawShow(playerid, mechmenu_header_name[playerid]);

    new vehinfo[200], mesincolor[4], 
        Float:vehiclehealth, Float:vehiclemaxhealth, Float:percent,
        color1, color2, upgrade;

    GetVehicleHealth(vehicleid, vehiclehealth);
    GetVehicleMaxHealth(vehicleid, vehiclemaxhealth);
    GetVehicleColor(vehicleid, color1, color2);
    GetVehicleUpgrade(vehicleid, upgrade);

    percent = (vehiclehealth / vehiclemaxhealth) * 100;

    if (percent >= 70) format(mesincolor, sizeof(mesincolor), "~g~");
    else if (percent >= 50) format(mesincolor, sizeof(mesincolor), "~y~");
    else format(mesincolor, sizeof(mesincolor), "~r~");

    format(vehinfo, sizeof(vehinfo), "~p~Informasi Kendaraan:~w~_(Model: ~y~%s~w~)_(Mesin:_%s%.0f%~w~)_(ID_Warna:_%d_%d)_(Upgrade:_%d/4)", GetVehicleModelName(GetVehicleModel(vehicleid)), mesincolor, percent, color1, color2, upgrade);
    PlayerTextDrawSetString(playerid, mechmenu_vehinfo[playerid], vehinfo);
    PlayerTextDrawShow(playerid, mechmenu_vehinfo[playerid]);
    
    PlayerTextDrawShow(playerid, mechmenu_upgrade_btn[playerid]);
    PlayerTextDrawShow(playerid, mechmenu_color_btn[playerid]);
    PlayerTextDrawShow(playerid, mechmenu_repair_btn[playerid]);
    return 1;
}

stock MechMenu_Repair(playerid, vehicleid)
{
    PlayerTextDrawHide(playerid, mechmenu_upgrade_btn[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_color_btn[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_repair_btn[playerid]);

    PlayerTextDrawSetString(playerid, mechmenu_header_name[playerid], "Perbaikan Kendaraan");
    PlayerTextDrawShow(playerid, mechmenu_header_name[playerid]);

    PlayerTextDrawShow(playerid, mechamenu_back[playerid]);

    new Float:vehiclehealth, Float:vehiclemaxhealth, Float:healthgap, Float:componentneed;
    GetVehicleHealth(vehicleid, vehiclehealth);
    GetVehicleMaxHealth(vehicleid, vehiclemaxhealth);

    healthgap = vehiclemaxhealth - vehiclehealth;
    componentneed = healthgap * 0.2853;

    player_mechmenu_componentneed[playerid] = floatround(componentneed);

    PlayerTextDrawSetString(playerid, mechmenu_repair_component[playerid], va_return("%3d", player_mechmenu_componentneed[playerid]));
    PlayerTextDrawShow(playerid, mechmenu_repair_component[playerid]);

    PlayerTextDrawShow(playerid, mechmenu_repair_info[playerid]);
    PlayerTextDrawShow(playerid, mechmenu_repair_info2[playerid]);
    PlayerTextDrawShow(playerid, mechmenu_repair_install[playerid]);
    return 1;
}

stock MechMenu_Color(playerid, vehicleid)
{
    PlayerTextDrawHide(playerid, mechmenu_upgrade_btn[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_color_btn[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_repair_btn[playerid]);

    PlayerTextDrawShow(playerid, mechamenu_back[playerid]);

    PlayerTextDrawSetString(playerid, mechmenu_header_name[playerid], "Ganti Warna Kendaraan");
    PlayerTextDrawShow(playerid, mechmenu_header_name[playerid]);

    new color1, color2;
    GetVehicleColor(vehicleid, color1, color2);
    PlayerTextDrawSetString(playerid, mechmenu_color_info[playerid], va_return("~y~ID Warna saat ini: ~w~%d %d", color1, color2));
    PlayerTextDrawHide(playerid, mechmenu_color_info[playerid]);

    player_mechmenu_componentneed[playerid] = 50;

    PlayerTextDrawSetString(playerid, mechmenu_color_component[playerid], va_return("%3d", player_mechmenu_componentneed[playerid]));
    PlayerTextDrawShow(playerid, mechmenu_color_component[playerid]);

    PlayerTextDrawHide(playerid, mechmenu_color_google[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_color_component2[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_color_change[playerid]);
    PlayerTextDrawShow(playerid, mechmenu_color_componeed[playerid]);
    return 1;
}

stock MechMenu_Upgrade(playerid, vehicleid)
{
    PlayerTextDrawHide(playerid, mechmenu_upgrade_btn[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_color_btn[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_repair_btn[playerid]);

    PlayerTextDrawShow(playerid, mechamenu_back[playerid]);

    PlayerTextDrawSetString(playerid, mechmenu_header_name[playerid], "Perbaikan Kendaraan");
    PlayerTextDrawShow(playerid, mechmenu_header_name[playerid]);

    new upgrade, upgradeinfo[200];
    GetVehicleUpgrade(vehicleid, upgrade);

    if(upgrade == 0) format(upgradeinfo, sizeof(upgradeinfo), "Status Upgrade~n~~w~[~r~~h~Engine~w~]_[~r~~h~Body~w~]_[~r~~h~Fuel Tank~w~]");
    else if(upgrade == 1) format(upgradeinfo, sizeof(upgradeinfo), "Status Upgrade~n~~w~[~g~~h~Engine~w~]_[~r~~h~Body~w~]_[~r~~h~Fuel Tank~w~]");
    else if(upgrade == 2) format(upgradeinfo, sizeof(upgradeinfo), "Status Upgrade~n~~w~[~g~~h~Engine~w~]_[~g~~h~Body~w~]_[~r~~h~Fuel Tank~w~]");
    else if(upgrade == 3) format(upgradeinfo, sizeof(upgradeinfo), "Status Upgrade~n~~w~[~g~~h~Engine~w~]_[~g~~h~Body~w~]_[~g~~h~Fuel Tank~w~]");
    PlayerTextDrawSetString(playerid, mechmenu_upgrade_info[playerid], upgradeinfo);
    PlayerTextDrawShow(playerid, mechmenu_upgrade_info[playerid]);

    player_mechmenu_componentneed[playerid] = 300;

    PlayerTextDrawSetString(playerid, mechmenu_upgrade_component2[playerid], va_return("%3d", player_mechmenu_componentneed[playerid]));
    PlayerTextDrawShow(playerid, mechmenu_upgrade_component2[playerid]);

    PlayerTextDrawShow(playerid, mechmenu_upgrade_install[playerid]);
    PlayerTextDrawShow(playerid, mechmenu_upgrade_next[playerid]);
    PlayerTextDrawShow(playerid, mechmenu_upgrade_component1[playerid]);
    PlayerTextDrawShow(playerid, mechmenu_upgrade_component3[playerid]);
    return 1;
}