stock ShowModernHudSpeedo(playerid)
{
    if(!IsPlayerInAnyVehicle(playerid)) return 1;

    new vehicleid = GetPlayerVehicleID(playerid), message[200];

    if(created_hud_modern_speedo_td[playerid] == false) CreateHudModernSpeedoTD(playerid);

	format(message, sizeof(message), "%s", GetVehicleModelName(GetVehicleModel(vehicleid)));
	PlayerTextDrawSetString(playerid, hud_modern_spdo_carname[playerid], message);
	
	new Float:speed = GetVehicleSpeed(vehicleid);
	format(message, sizeof(message), "%.0f", speed);
	PlayerTextDrawSetString(playerid, hud_modern_spdo_speed[playerid], message);

	// Min: 509 Max: 459
	new Float:value, Float:value2, color;
	GetVehicleHealth(vehicleid, value);
	value = (value / 10);
	PlayerTextDrawTextSize(playerid, hud_modern_spdo_carhealth_value[playerid], 509.0000 - (0.5 * value), 17.000000);
	color = GetValueColor(value);
	PlayerTextDrawBoxColor(playerid, hud_modern_spdo_carhealth_value[playerid], color - 150);
	PlayerTextDrawColor(playerid, hud_modern_spdo_carhealth_cnt[playerid], color);
	PlayerTextDrawSetString(playerid, hud_modern_spdo_carhealth_cnt[playerid], va_return("%.0f%", value));

	GetVehicleFuel(vehicleid, value);
	GetVehicleMaxFuel(vehicleid, value2);

	value = ((value / value2) * 100);
	PlayerTextDrawTextSize(playerid, hud_modern_spdo_carfuel_value[playerid], 509.0000 - (0.5 * value), 17.000000);
	color = GetValueColor(value);
	PlayerTextDrawBoxColor(playerid, hud_modern_spdo_carfuel_value[playerid], color - 150);
	PlayerTextDrawColor(playerid, hud_modern_spdo_carfuel_cnt[playerid], color);
	PlayerTextDrawSetString(playerid, hud_modern_spdo_carfuel_cnt[playerid], va_return("%.0f%", value));

	PlayerTextDrawShow(playerid, hud_modern_spdo_box[playerid]);
	PlayerTextDrawShow(playerid, hud_modern_spdo_carhealth_bg[playerid]);
	PlayerTextDrawShow(playerid, hud_modern_spdo_carname[playerid]);
	PlayerTextDrawShow(playerid, hud_modern_spdo_speed[playerid]);
	PlayerTextDrawShow(playerid, hud_modern_spdo_kmh[playerid]);
	PlayerTextDrawShow(playerid, hud_modern_spdo_carfuel_bg[playerid]);
	PlayerTextDrawShow(playerid, hud_modern_spdo_carhealth_icon[playerid]);
	PlayerTextDrawShow(playerid, hud_modern_spdo_carfuel_icon[playerid]);
	PlayerTextDrawShow(playerid, hud_modern_spdo_carhealth_value[playerid]);
	PlayerTextDrawShow(playerid, hud_modern_spdo_carfuel_value[playerid]);
	PlayerTextDrawShow(playerid, hud_modern_spdo_carhealth_cnt[playerid]);
	PlayerTextDrawShow(playerid, hud_modern_spdo_carfuel_cnt[playerid]);
    showed_hud_modern_speedo_td[playerid] = true;
    return 1;
}

stock HideModernHudSpeedo(playerid)
{
	PlayerTextDrawHide(playerid, hud_modern_spdo_box[playerid]);
	PlayerTextDrawHide(playerid, hud_modern_spdo_carhealth_bg[playerid]);
	PlayerTextDrawHide(playerid, hud_modern_spdo_carname[playerid]);
	PlayerTextDrawHide(playerid, hud_modern_spdo_speed[playerid]);
	PlayerTextDrawHide(playerid, hud_modern_spdo_kmh[playerid]);
	PlayerTextDrawHide(playerid, hud_modern_spdo_carfuel_bg[playerid]);
	PlayerTextDrawHide(playerid, hud_modern_spdo_carhealth_icon[playerid]);
	PlayerTextDrawHide(playerid, hud_modern_spdo_carfuel_icon[playerid]);
	PlayerTextDrawHide(playerid, hud_modern_spdo_carhealth_value[playerid]);
	PlayerTextDrawHide(playerid, hud_modern_spdo_carfuel_value[playerid]);
	PlayerTextDrawHide(playerid, hud_modern_spdo_carhealth_cnt[playerid]);
	PlayerTextDrawHide(playerid, hud_modern_spdo_carfuel_cnt[playerid]);
	showed_hud_modern_speedo_td[playerid] = false;
	return 1;
}