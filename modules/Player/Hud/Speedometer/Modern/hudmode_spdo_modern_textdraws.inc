stock CreateHudModernSpeedoTD(playerid)
{
	hud_modern_spdo_box[playerid] = CreatePlayerTextDraw(playerid, 450.000000, 391.000000, "_");
	PlayerTextDrawFont(playerid, hud_modern_spdo_box[playerid], 1);
	PlayerTextDrawLetterSize(playerid, hud_modern_spdo_box[playerid], 0.600000, 6.250000);
	PlayerTextDrawTextSize(playerid, hud_modern_spdo_box[playerid], 298.500000, 126.000000);
	PlayerTextDrawSetOutline(playerid, hud_modern_spdo_box[playerid], 1);
	PlayerTextDrawSetShadow(playerid, hud_modern_spdo_box[playerid], 0);
	PlayerTextDrawAlignment(playerid, hud_modern_spdo_box[playerid], 2);
	PlayerTextDrawColor(playerid, hud_modern_spdo_box[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, hud_modern_spdo_box[playerid], 255);
	PlayerTextDrawBoxColor(playerid, hud_modern_spdo_box[playerid], 1687547282);
	PlayerTextDrawUseBox(playerid, hud_modern_spdo_box[playerid], 1);
	PlayerTextDrawSetProportional(playerid, hud_modern_spdo_box[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, hud_modern_spdo_box[playerid], 0);

	hud_modern_spdo_carhealth_bg[playerid] = CreatePlayerTextDraw(playerid, 511.000000, 413.000000, "_");
	PlayerTextDrawFont(playerid, hud_modern_spdo_carhealth_bg[playerid], 1);
	PlayerTextDrawLetterSize(playerid, hud_modern_spdo_carhealth_bg[playerid], 0.562500, 1.099997);
	PlayerTextDrawTextSize(playerid, hud_modern_spdo_carhealth_bg[playerid], 457.000000, 30.500000);
	PlayerTextDrawSetOutline(playerid, hud_modern_spdo_carhealth_bg[playerid], 1);
	PlayerTextDrawSetShadow(playerid, hud_modern_spdo_carhealth_bg[playerid], 0);
	PlayerTextDrawAlignment(playerid, hud_modern_spdo_carhealth_bg[playerid], 1);
	PlayerTextDrawColor(playerid, hud_modern_spdo_carhealth_bg[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, hud_modern_spdo_carhealth_bg[playerid], 255);
	PlayerTextDrawBoxColor(playerid, hud_modern_spdo_carhealth_bg[playerid], 50);
	PlayerTextDrawUseBox(playerid, hud_modern_spdo_carhealth_bg[playerid], 1);
	PlayerTextDrawSetProportional(playerid, hud_modern_spdo_carhealth_bg[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, hud_modern_spdo_carhealth_bg[playerid], 0);

	hud_modern_spdo_carname[playerid] = CreatePlayerTextDraw(playerid, 511.000000, 393.000000, "Sultan");
	PlayerTextDrawFont(playerid, hud_modern_spdo_carname[playerid], 1);
	PlayerTextDrawLetterSize(playerid, hud_modern_spdo_carname[playerid], 0.470833, 1.250000);
	PlayerTextDrawTextSize(playerid, hud_modern_spdo_carname[playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, hud_modern_spdo_carname[playerid], 1);
	PlayerTextDrawSetShadow(playerid, hud_modern_spdo_carname[playerid], 0);
	PlayerTextDrawAlignment(playerid, hud_modern_spdo_carname[playerid], 3);
	PlayerTextDrawColor(playerid, hud_modern_spdo_carname[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, hud_modern_spdo_carname[playerid], 255);
	PlayerTextDrawBoxColor(playerid, hud_modern_spdo_carname[playerid], 50);
	PlayerTextDrawUseBox(playerid, hud_modern_spdo_carname[playerid], 0);
	PlayerTextDrawSetProportional(playerid, hud_modern_spdo_carname[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, hud_modern_spdo_carname[playerid], 0);

	hud_modern_spdo_speed[playerid] = CreatePlayerTextDraw(playerid, 417.000000, 396.000000, "100");
	PlayerTextDrawFont(playerid, hud_modern_spdo_speed[playerid], 3);
	PlayerTextDrawLetterSize(playerid, hud_modern_spdo_speed[playerid], 0.799998, 3.849994);
	PlayerTextDrawTextSize(playerid, hud_modern_spdo_speed[playerid], 400.000000, 47.000000);
	PlayerTextDrawSetOutline(playerid, hud_modern_spdo_speed[playerid], 1);
	PlayerTextDrawSetShadow(playerid, hud_modern_spdo_speed[playerid], 0);
	PlayerTextDrawAlignment(playerid, hud_modern_spdo_speed[playerid], 2);
	PlayerTextDrawColor(playerid, hud_modern_spdo_speed[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, hud_modern_spdo_speed[playerid], 255);
	PlayerTextDrawBoxColor(playerid, hud_modern_spdo_speed[playerid], 50);
	PlayerTextDrawUseBox(playerid, hud_modern_spdo_speed[playerid], 0);
	PlayerTextDrawSetProportional(playerid, hud_modern_spdo_speed[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, hud_modern_spdo_speed[playerid], 0);

	hud_modern_spdo_kmh[playerid] = CreatePlayerTextDraw(playerid, 417.000000, 434.000000, "km/h");
	PlayerTextDrawFont(playerid, hud_modern_spdo_kmh[playerid], 2);
	PlayerTextDrawLetterSize(playerid, hud_modern_spdo_kmh[playerid], 0.191666, 0.899995);
	PlayerTextDrawTextSize(playerid, hud_modern_spdo_kmh[playerid], 400.000000, 47.000000);
	PlayerTextDrawSetOutline(playerid, hud_modern_spdo_kmh[playerid], 1);
	PlayerTextDrawSetShadow(playerid, hud_modern_spdo_kmh[playerid], 0);
	PlayerTextDrawAlignment(playerid, hud_modern_spdo_kmh[playerid], 2);
	PlayerTextDrawColor(playerid, hud_modern_spdo_kmh[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, hud_modern_spdo_kmh[playerid], 255);
	PlayerTextDrawBoxColor(playerid, hud_modern_spdo_kmh[playerid], 50);
	PlayerTextDrawUseBox(playerid, hud_modern_spdo_kmh[playerid], 0);
	PlayerTextDrawSetProportional(playerid, hud_modern_spdo_kmh[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, hud_modern_spdo_kmh[playerid], 0);

	hud_modern_spdo_carfuel_bg[playerid] = CreatePlayerTextDraw(playerid, 511.000000, 431.000000, "_");
	PlayerTextDrawFont(playerid, hud_modern_spdo_carfuel_bg[playerid], 1);
	PlayerTextDrawLetterSize(playerid, hud_modern_spdo_carfuel_bg[playerid], 0.562500, 1.099997);
	PlayerTextDrawTextSize(playerid, hud_modern_spdo_carfuel_bg[playerid], 457.000000, 30.500000);
	PlayerTextDrawSetOutline(playerid, hud_modern_spdo_carfuel_bg[playerid], 1);
	PlayerTextDrawSetShadow(playerid, hud_modern_spdo_carfuel_bg[playerid], 0);
	PlayerTextDrawAlignment(playerid, hud_modern_spdo_carfuel_bg[playerid], 1);
	PlayerTextDrawColor(playerid, hud_modern_spdo_carfuel_bg[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, hud_modern_spdo_carfuel_bg[playerid], 255);
	PlayerTextDrawBoxColor(playerid, hud_modern_spdo_carfuel_bg[playerid], 50);
	PlayerTextDrawUseBox(playerid, hud_modern_spdo_carfuel_bg[playerid], 1);
	PlayerTextDrawSetProportional(playerid, hud_modern_spdo_carfuel_bg[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, hud_modern_spdo_carfuel_bg[playerid], 0);

	hud_modern_spdo_carhealth_icon[playerid] = CreatePlayerTextDraw(playerid, 443.000000, 411.000000, "HUD:radar_impound");
	PlayerTextDrawFont(playerid, hud_modern_spdo_carhealth_icon[playerid], 4);
	PlayerTextDrawLetterSize(playerid, hud_modern_spdo_carhealth_icon[playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, hud_modern_spdo_carhealth_icon[playerid], 12.500000, 12.000000);
	PlayerTextDrawSetOutline(playerid, hud_modern_spdo_carhealth_icon[playerid], 1);
	PlayerTextDrawSetShadow(playerid, hud_modern_spdo_carhealth_icon[playerid], 0);
	PlayerTextDrawAlignment(playerid, hud_modern_spdo_carhealth_icon[playerid], 1);
	PlayerTextDrawColor(playerid, hud_modern_spdo_carhealth_icon[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, hud_modern_spdo_carhealth_icon[playerid], 255);
	PlayerTextDrawBoxColor(playerid, hud_modern_spdo_carhealth_icon[playerid], 50);
	PlayerTextDrawUseBox(playerid, hud_modern_spdo_carhealth_icon[playerid], 1);
	PlayerTextDrawSetProportional(playerid, hud_modern_spdo_carhealth_icon[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, hud_modern_spdo_carhealth_icon[playerid], 0);

	hud_modern_spdo_carfuel_icon[playerid] = CreatePlayerTextDraw(playerid, 443.000000, 430.000000, "HUD:radar_spray");
	PlayerTextDrawFont(playerid, hud_modern_spdo_carfuel_icon[playerid], 4);
	PlayerTextDrawLetterSize(playerid, hud_modern_spdo_carfuel_icon[playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, hud_modern_spdo_carfuel_icon[playerid], 12.500000, 12.000000);
	PlayerTextDrawSetOutline(playerid, hud_modern_spdo_carfuel_icon[playerid], 1);
	PlayerTextDrawSetShadow(playerid, hud_modern_spdo_carfuel_icon[playerid], 0);
	PlayerTextDrawAlignment(playerid, hud_modern_spdo_carfuel_icon[playerid], 1);
	PlayerTextDrawColor(playerid, hud_modern_spdo_carfuel_icon[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, hud_modern_spdo_carfuel_icon[playerid], 255);
	PlayerTextDrawBoxColor(playerid, hud_modern_spdo_carfuel_icon[playerid], 50);
	PlayerTextDrawUseBox(playerid, hud_modern_spdo_carfuel_icon[playerid], 1);
	PlayerTextDrawSetProportional(playerid, hud_modern_spdo_carfuel_icon[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, hud_modern_spdo_carfuel_icon[playerid], 0);

	hud_modern_spdo_carhealth_value[playerid] = CreatePlayerTextDraw(playerid, 509.000000, 415.000000, "_");
	PlayerTextDrawFont(playerid, hud_modern_spdo_carhealth_value[playerid], 1);
	PlayerTextDrawLetterSize(playerid, hud_modern_spdo_carhealth_value[playerid], 0.562500, 0.699997);
	PlayerTextDrawTextSize(playerid, hud_modern_spdo_carhealth_value[playerid], 459.000000, 31.000000);
	PlayerTextDrawSetOutline(playerid, hud_modern_spdo_carhealth_value[playerid], 1);
	PlayerTextDrawSetShadow(playerid, hud_modern_spdo_carhealth_value[playerid], 0);
	PlayerTextDrawAlignment(playerid, hud_modern_spdo_carhealth_value[playerid], 1);
	PlayerTextDrawColor(playerid, hud_modern_spdo_carhealth_value[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, hud_modern_spdo_carhealth_value[playerid], 255);
	PlayerTextDrawBoxColor(playerid, hud_modern_spdo_carhealth_value[playerid], 16711850);
	PlayerTextDrawUseBox(playerid, hud_modern_spdo_carhealth_value[playerid], 1);
	PlayerTextDrawSetProportional(playerid, hud_modern_spdo_carhealth_value[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, hud_modern_spdo_carhealth_value[playerid], 0);

	hud_modern_spdo_carfuel_value[playerid] = CreatePlayerTextDraw(playerid, 509.000000, 433.000000, "_");
	PlayerTextDrawFont(playerid, hud_modern_spdo_carfuel_value[playerid], 1);
	PlayerTextDrawLetterSize(playerid, hud_modern_spdo_carfuel_value[playerid], 0.562500, 0.699997);
	PlayerTextDrawTextSize(playerid, hud_modern_spdo_carfuel_value[playerid], 459.000000, 31.000000);
	PlayerTextDrawSetOutline(playerid, hud_modern_spdo_carfuel_value[playerid], 1);
	PlayerTextDrawSetShadow(playerid, hud_modern_spdo_carfuel_value[playerid], 0);
	PlayerTextDrawAlignment(playerid, hud_modern_spdo_carfuel_value[playerid], 1);
	PlayerTextDrawColor(playerid, hud_modern_spdo_carfuel_value[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, hud_modern_spdo_carfuel_value[playerid], 255);
	PlayerTextDrawBoxColor(playerid, hud_modern_spdo_carfuel_value[playerid], 16711850);
	PlayerTextDrawUseBox(playerid, hud_modern_spdo_carfuel_value[playerid], 1);
	PlayerTextDrawSetProportional(playerid, hud_modern_spdo_carfuel_value[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, hud_modern_spdo_carfuel_value[playerid], 0);

	hud_modern_spdo_carhealth_cnt[playerid] = CreatePlayerTextDraw(playerid, 506.000000, 414.000000, "100%");
	PlayerTextDrawFont(playerid, hud_modern_spdo_carhealth_cnt[playerid], 1);
	PlayerTextDrawLetterSize(playerid, hud_modern_spdo_carhealth_cnt[playerid], 0.191666, 0.899999);
	PlayerTextDrawTextSize(playerid, hud_modern_spdo_carhealth_cnt[playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, hud_modern_spdo_carhealth_cnt[playerid], 1);
	PlayerTextDrawSetShadow(playerid, hud_modern_spdo_carhealth_cnt[playerid], 0);
	PlayerTextDrawAlignment(playerid, hud_modern_spdo_carhealth_cnt[playerid], 3);
	PlayerTextDrawColor(playerid, hud_modern_spdo_carhealth_cnt[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, hud_modern_spdo_carhealth_cnt[playerid], 255);
	PlayerTextDrawBoxColor(playerid, hud_modern_spdo_carhealth_cnt[playerid], 50);
	PlayerTextDrawUseBox(playerid, hud_modern_spdo_carhealth_cnt[playerid], 0);
	PlayerTextDrawSetProportional(playerid, hud_modern_spdo_carhealth_cnt[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, hud_modern_spdo_carhealth_cnt[playerid], 0);

	hud_modern_spdo_carfuel_cnt[playerid] = CreatePlayerTextDraw(playerid, 506.000000, 432.000000, "100%");
	PlayerTextDrawFont(playerid, hud_modern_spdo_carfuel_cnt[playerid], 1);
	PlayerTextDrawLetterSize(playerid, hud_modern_spdo_carfuel_cnt[playerid], 0.191666, 0.899999);
	PlayerTextDrawTextSize(playerid, hud_modern_spdo_carfuel_cnt[playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, hud_modern_spdo_carfuel_cnt[playerid], 1);
	PlayerTextDrawSetShadow(playerid, hud_modern_spdo_carfuel_cnt[playerid], 0);
	PlayerTextDrawAlignment(playerid, hud_modern_spdo_carfuel_cnt[playerid], 3);
	PlayerTextDrawColor(playerid, hud_modern_spdo_carfuel_cnt[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, hud_modern_spdo_carfuel_cnt[playerid], 255);
	PlayerTextDrawBoxColor(playerid, hud_modern_spdo_carfuel_cnt[playerid], 50);
	PlayerTextDrawUseBox(playerid, hud_modern_spdo_carfuel_cnt[playerid], 0);
	PlayerTextDrawSetProportional(playerid, hud_modern_spdo_carfuel_cnt[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, hud_modern_spdo_carfuel_cnt[playerid], 0);

    created_hud_modern_speedo_td[playerid] = true;
	return 1;
}

stock DestroyHudModernSpeedoTD(playerid)
{
	PlayerTextDrawDestroy(playerid, hud_modern_spdo_box[playerid]);
	PlayerTextDrawDestroy(playerid, hud_modern_spdo_carhealth_bg[playerid]);
	PlayerTextDrawDestroy(playerid, hud_modern_spdo_carname[playerid]);
	PlayerTextDrawDestroy(playerid, hud_modern_spdo_speed[playerid]);
	PlayerTextDrawDestroy(playerid, hud_modern_spdo_kmh[playerid]);
	PlayerTextDrawDestroy(playerid, hud_modern_spdo_carfuel_bg[playerid]);
	PlayerTextDrawDestroy(playerid, hud_modern_spdo_carhealth_icon[playerid]);
	PlayerTextDrawDestroy(playerid, hud_modern_spdo_carfuel_icon[playerid]);
	PlayerTextDrawDestroy(playerid, hud_modern_spdo_carhealth_value[playerid]);
	PlayerTextDrawDestroy(playerid, hud_modern_spdo_carfuel_value[playerid]);
	PlayerTextDrawDestroy(playerid, hud_modern_spdo_carhealth_cnt[playerid]);
	PlayerTextDrawDestroy(playerid, hud_modern_spdo_carfuel_cnt[playerid]);
    created_hud_modern_speedo_td[playerid] = false;
	return 1;
}