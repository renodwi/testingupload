stock ShowModernHudInfo(playerid)
{
	if(created_hud_modern_info_td[playerid] == false) CreateHudModernInfoTD(playerid);
	if(showed_hud_modern_info_td[playerid] == false)
	{
		PlayerTextDrawShow(playerid, hud_modern_info_box[playerid]);
		PlayerTextDrawShow(playerid, hud_modern_info_hungrybg[playerid]);
		PlayerTextDrawShow(playerid, hud_modern_info_thristbg[playerid]);
		PlayerTextDrawShow(playerid, hud_modern_info_hungryicon[playerid]);
		PlayerTextDrawShow(playerid, hud_modern_info_thristicon[playerid]);
		PlayerTextDrawShow(playerid, hud_modern_info_hungryvalue[playerid]);
		PlayerTextDrawShow(playerid, hud_modern_info_thristvalue[playerid]);
		PlayerTextDrawShow(playerid, hud_modern_info_hungrypercent[playerid]);
		PlayerTextDrawShow(playerid, hud_modern_info_thristpercent[playerid]);
		showed_hud_modern_info_td[playerid] = true;

		UpdateModernHudInfo(playerid);
	}
	else UpdateModernHudInfo(playerid);
    return 1;
}

stock UpdateModernHudInfo(playerid) 
{
	if(showed_hud_modern_info_td[playerid] == false) ShowModernHudInfo(playerid);

	new cent[100];
	format(cent, sizeof(cent), "%.0f%", playerInfo[playerid][playerHungry]);
	PlayerTextDrawSetString(playerid, hud_modern_info_hungrypercent[playerid], cent);

	format(cent, sizeof(cent), "%.0f%", playerInfo[playerid][playerThrist]);
	PlayerTextDrawSetString(playerid, hud_modern_info_thristpercent[playerid], cent);

	PlayerTextDrawShow(playerid, hud_modern_info_hungrypercent[playerid]);
	PlayerTextDrawShow(playerid, hud_modern_info_thristpercent[playerid]);

	// min: 633.000000 max: 544.00000
	new Float:value, color;
	value = (633.000000) - (0.9 * playerInfo[playerid][playerHungry]);
	color = GetValueColor(playerInfo[playerid][playerHungry]);
	PlayerTextDrawTextSize(playerid, hud_modern_info_hungryvalue[playerid], value, 17.000000);
	PlayerTextDrawBoxColor(playerid, hud_modern_info_hungryvalue[playerid], color - 150);
	PlayerTextDrawColor(playerid, hud_modern_info_hungrypercent[playerid], color);
	PlayerTextDrawShow(playerid, hud_modern_info_hungryvalue[playerid]);

	value = (633.000000) - (0.9 * playerInfo[playerid][playerThrist]);
	color = GetValueColor(playerInfo[playerid][playerHungry]);
	PlayerTextDrawTextSize(playerid, hud_modern_info_thristvalue[playerid], value, 17.000000);
	PlayerTextDrawBoxColor(playerid, hud_modern_info_thristvalue[playerid], color - 150);
	PlayerTextDrawColor(playerid, hud_modern_info_thristpercent[playerid], color);
	PlayerTextDrawShow(playerid, hud_modern_info_thristvalue[playerid]);
	return 1;
}

stock HideModernHudInfo(playerid)
{
    showed_hud_modern_info_td[playerid] = false;
	PlayerTextDrawHide(playerid, hud_modern_info_box[playerid]);
	PlayerTextDrawHide(playerid, hud_modern_info_hungrybg[playerid]);
	PlayerTextDrawHide(playerid, hud_modern_info_thristbg[playerid]);
	PlayerTextDrawHide(playerid, hud_modern_info_hungryicon[playerid]);
	PlayerTextDrawHide(playerid, hud_modern_info_thristicon[playerid]);
	PlayerTextDrawHide(playerid, hud_modern_info_hungryvalue[playerid]);
	PlayerTextDrawHide(playerid, hud_modern_info_thristvalue[playerid]);
	PlayerTextDrawHide(playerid, hud_modern_info_hungrypercent[playerid]);
	PlayerTextDrawHide(playerid, hud_modern_info_thristpercent[playerid]);
    return 1;
}