stock CreateHudModernInfoTD(playerid)
{
	hud_modern_info_box[playerid] = CreatePlayerTextDraw(playerid, 601.000000, 391.000000, "_");
	PlayerTextDrawFont(playerid, hud_modern_info_box[playerid], 1);
	PlayerTextDrawLetterSize(playerid, hud_modern_info_box[playerid], 0.600000, 6.250000);
	PlayerTextDrawTextSize(playerid, hud_modern_info_box[playerid], 298.500000, 171.000000);
	PlayerTextDrawSetOutline(playerid, hud_modern_info_box[playerid], 1);
	PlayerTextDrawSetShadow(playerid, hud_modern_info_box[playerid], 0);
	PlayerTextDrawAlignment(playerid, hud_modern_info_box[playerid], 2);
	PlayerTextDrawColor(playerid, hud_modern_info_box[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, hud_modern_info_box[playerid], 255);
	PlayerTextDrawBoxColor(playerid, hud_modern_info_box[playerid], 1687547282);
	PlayerTextDrawUseBox(playerid, hud_modern_info_box[playerid], 1);
	PlayerTextDrawSetProportional(playerid, hud_modern_info_box[playerid], 0);
	PlayerTextDrawSetSelectable(playerid, hud_modern_info_box[playerid], 0);

	hud_modern_info_hungrybg[playerid] = CreatePlayerTextDraw(playerid, 636.000000, 397.000000, "_");
	PlayerTextDrawFont(playerid, hud_modern_info_hungrybg[playerid], 2);
	PlayerTextDrawLetterSize(playerid, hud_modern_info_hungrybg[playerid], 1.166666, 2.000000);
	PlayerTextDrawTextSize(playerid, hud_modern_info_hungrybg[playerid], 542.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, hud_modern_info_hungrybg[playerid], 1);
	PlayerTextDrawSetShadow(playerid, hud_modern_info_hungrybg[playerid], 0);
	PlayerTextDrawAlignment(playerid, hud_modern_info_hungrybg[playerid], 1);
	PlayerTextDrawColor(playerid, hud_modern_info_hungrybg[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, hud_modern_info_hungrybg[playerid], 255);
	PlayerTextDrawBoxColor(playerid, hud_modern_info_hungrybg[playerid], 50);
	PlayerTextDrawUseBox(playerid, hud_modern_info_hungrybg[playerid], 1);
	PlayerTextDrawSetProportional(playerid, hud_modern_info_hungrybg[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, hud_modern_info_hungrybg[playerid], 0);

	hud_modern_info_thristbg[playerid] = CreatePlayerTextDraw(playerid, 636.000000, 424.000000, "_");
	PlayerTextDrawFont(playerid, hud_modern_info_thristbg[playerid], 1);
	PlayerTextDrawLetterSize(playerid, hud_modern_info_thristbg[playerid], 1.166666, 2.000000);
	PlayerTextDrawTextSize(playerid, hud_modern_info_thristbg[playerid], 542.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, hud_modern_info_thristbg[playerid], 1);
	PlayerTextDrawSetShadow(playerid, hud_modern_info_thristbg[playerid], 0);
	PlayerTextDrawAlignment(playerid, hud_modern_info_thristbg[playerid], 1);
	PlayerTextDrawColor(playerid, hud_modern_info_thristbg[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, hud_modern_info_thristbg[playerid], 255);
	PlayerTextDrawBoxColor(playerid, hud_modern_info_thristbg[playerid], 50);
	PlayerTextDrawUseBox(playerid, hud_modern_info_thristbg[playerid], 1);
	PlayerTextDrawSetProportional(playerid, hud_modern_info_thristbg[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, hud_modern_info_thristbg[playerid], 0);

	hud_modern_info_hungryicon[playerid] = CreatePlayerTextDraw(playerid, 521.000000, 397.000000, "HUD:radar_datefood");
	PlayerTextDrawFont(playerid, hud_modern_info_hungryicon[playerid], 4);
	PlayerTextDrawLetterSize(playerid, hud_modern_info_hungryicon[playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, hud_modern_info_hungryicon[playerid], 17.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, hud_modern_info_hungryicon[playerid], 1);
	PlayerTextDrawSetShadow(playerid, hud_modern_info_hungryicon[playerid], 0);
	PlayerTextDrawAlignment(playerid, hud_modern_info_hungryicon[playerid], 1);
	PlayerTextDrawColor(playerid, hud_modern_info_hungryicon[playerid], -76);
	PlayerTextDrawBackgroundColor(playerid, hud_modern_info_hungryicon[playerid], 255);
	PlayerTextDrawBoxColor(playerid, hud_modern_info_hungryicon[playerid], 50);
	PlayerTextDrawUseBox(playerid, hud_modern_info_hungryicon[playerid], 1);
	PlayerTextDrawSetProportional(playerid, hud_modern_info_hungryicon[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, hud_modern_info_hungryicon[playerid], 0);

	hud_modern_info_thristicon[playerid] = CreatePlayerTextDraw(playerid, 521.000000, 425.000000, "HUD:radar_diner");
	PlayerTextDrawFont(playerid, hud_modern_info_thristicon[playerid], 4);
	PlayerTextDrawLetterSize(playerid, hud_modern_info_thristicon[playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, hud_modern_info_thristicon[playerid], 17.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, hud_modern_info_thristicon[playerid], 1);
	PlayerTextDrawSetShadow(playerid, hud_modern_info_thristicon[playerid], 0);
	PlayerTextDrawAlignment(playerid, hud_modern_info_thristicon[playerid], 1);
	PlayerTextDrawColor(playerid, hud_modern_info_thristicon[playerid], -76);
	PlayerTextDrawBackgroundColor(playerid, hud_modern_info_thristicon[playerid], 255);
	PlayerTextDrawBoxColor(playerid, hud_modern_info_thristicon[playerid], 50);
	PlayerTextDrawUseBox(playerid, hud_modern_info_thristicon[playerid], 1);
	PlayerTextDrawSetProportional(playerid, hud_modern_info_thristicon[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, hud_modern_info_thristicon[playerid], 0);

	hud_modern_info_hungryvalue[playerid] = CreatePlayerTextDraw(playerid, 634.000000, 400.000000, "_");
	PlayerTextDrawFont(playerid, hud_modern_info_hungryvalue[playerid], 1);
	PlayerTextDrawLetterSize(playerid, hud_modern_info_hungryvalue[playerid], 1.166666, 1.450000);
	PlayerTextDrawTextSize(playerid, hud_modern_info_hungryvalue[playerid], 544.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, hud_modern_info_hungryvalue[playerid], 1);
	PlayerTextDrawSetShadow(playerid, hud_modern_info_hungryvalue[playerid], 0);
	PlayerTextDrawAlignment(playerid, hud_modern_info_hungryvalue[playerid], 1);
	PlayerTextDrawColor(playerid, hud_modern_info_hungryvalue[playerid], 16711935);
	PlayerTextDrawBackgroundColor(playerid, hud_modern_info_hungryvalue[playerid], 255);
	PlayerTextDrawBoxColor(playerid, hud_modern_info_hungryvalue[playerid], 16711790);
	PlayerTextDrawUseBox(playerid, hud_modern_info_hungryvalue[playerid], 1);
	PlayerTextDrawSetProportional(playerid, hud_modern_info_hungryvalue[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, hud_modern_info_hungryvalue[playerid], 0);

	hud_modern_info_thristvalue[playerid] = CreatePlayerTextDraw(playerid, 634.000000, 427.000000, "_");
	PlayerTextDrawFont(playerid, hud_modern_info_thristvalue[playerid], 1);
	PlayerTextDrawLetterSize(playerid, hud_modern_info_thristvalue[playerid], 1.166666, 1.450000);
	PlayerTextDrawTextSize(playerid, hud_modern_info_thristvalue[playerid], 544.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, hud_modern_info_thristvalue[playerid], 1);
	PlayerTextDrawSetShadow(playerid, hud_modern_info_thristvalue[playerid], 0);
	PlayerTextDrawAlignment(playerid, hud_modern_info_thristvalue[playerid], 1);
	PlayerTextDrawColor(playerid, hud_modern_info_thristvalue[playerid], 16711935);
	PlayerTextDrawBackgroundColor(playerid, hud_modern_info_thristvalue[playerid], 255);
	PlayerTextDrawBoxColor(playerid, hud_modern_info_thristvalue[playerid], 16711790);
	PlayerTextDrawBoxColor(playerid, hud_modern_info_thristvalue[playerid], 0x00FF00FF);
	PlayerTextDrawUseBox(playerid, hud_modern_info_thristvalue[playerid], 1);
	PlayerTextDrawSetProportional(playerid, hud_modern_info_thristvalue[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, hud_modern_info_thristvalue[playerid], 0);

	hud_modern_info_hungrypercent[playerid] = CreatePlayerTextDraw(playerid, 629.000000, 401.000000, "100%");
	PlayerTextDrawFont(playerid, hud_modern_info_hungrypercent[playerid], 3);
	PlayerTextDrawLetterSize(playerid, hud_modern_info_hungrypercent[playerid], 0.229166, 1.100000);
	PlayerTextDrawTextSize(playerid, hud_modern_info_hungrypercent[playerid], 640.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, hud_modern_info_hungrypercent[playerid], 1);
	PlayerTextDrawSetShadow(playerid, hud_modern_info_hungrypercent[playerid], 0);
	PlayerTextDrawAlignment(playerid, hud_modern_info_hungrypercent[playerid], 3);
	PlayerTextDrawColor(playerid, hud_modern_info_hungrypercent[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, hud_modern_info_hungrypercent[playerid], 255);
	PlayerTextDrawBoxColor(playerid, hud_modern_info_hungrypercent[playerid], 50);
	PlayerTextDrawUseBox(playerid, hud_modern_info_hungrypercent[playerid], 0);
	PlayerTextDrawSetProportional(playerid, hud_modern_info_hungrypercent[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, hud_modern_info_hungrypercent[playerid], 0);

	hud_modern_info_thristpercent[playerid] = CreatePlayerTextDraw(playerid, 629.000000, 428.000000, "100%");
	PlayerTextDrawFont(playerid, hud_modern_info_thristpercent[playerid], 3);
	PlayerTextDrawLetterSize(playerid, hud_modern_info_thristpercent[playerid], 0.229166, 1.100000);
	PlayerTextDrawTextSize(playerid, hud_modern_info_thristpercent[playerid], 640.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, hud_modern_info_thristpercent[playerid], 1);
	PlayerTextDrawSetShadow(playerid, hud_modern_info_thristpercent[playerid], 0);
	PlayerTextDrawAlignment(playerid, hud_modern_info_thristpercent[playerid], 3);
	PlayerTextDrawColor(playerid, hud_modern_info_thristpercent[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, hud_modern_info_thristpercent[playerid], 255);
	PlayerTextDrawBoxColor(playerid, hud_modern_info_thristpercent[playerid], 50);
	PlayerTextDrawUseBox(playerid, hud_modern_info_thristpercent[playerid], 0);
	PlayerTextDrawSetProportional(playerid, hud_modern_info_thristpercent[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, hud_modern_info_thristpercent[playerid], 0);
    created_hud_modern_info_td[playerid] = true;
	return 1;
}

stock DestroyHudModernInfoTD(playerid)
{
	PlayerTextDrawDestroy(playerid, hud_modern_info_box[playerid]);
	PlayerTextDrawDestroy(playerid, hud_modern_info_hungrybg[playerid]);
	PlayerTextDrawDestroy(playerid, hud_modern_info_thristbg[playerid]);
	PlayerTextDrawDestroy(playerid, hud_modern_info_hungryicon[playerid]);
	PlayerTextDrawDestroy(playerid, hud_modern_info_thristicon[playerid]);
	PlayerTextDrawDestroy(playerid, hud_modern_info_hungryvalue[playerid]);
	PlayerTextDrawDestroy(playerid, hud_modern_info_thristvalue[playerid]);
	PlayerTextDrawDestroy(playerid, hud_modern_info_hungrypercent[playerid]);
	PlayerTextDrawDestroy(playerid, hud_modern_info_thristpercent[playerid]);
    created_hud_modern_info_td[playerid] = false;
	return 1;
}