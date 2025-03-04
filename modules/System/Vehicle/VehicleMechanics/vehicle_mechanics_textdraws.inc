stock HidePlayerMechanicTD(playerid)
{
    PlayerTextDrawHide(playerid, mechmenu_box[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_header_box[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_vehinfo[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_header_icon[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_close[playerid]);
    PlayerTextDrawHide(playerid, mechamenu_back[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_header_name[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_upgrade_btn[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_color_btn[playerid]);
    PlayerTextDrawHide(playerid, mechmenu_repair_btn[playerid]);

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
    return 1;
}

stock DestroyPlayerMechanicTD(playerid)
{
    HidePlayerMechanicTD(playerid);
    PlayerTextDrawDestroy(playerid, mechmenu_box[playerid]);
    PlayerTextDrawDestroy(playerid, mechmenu_header_box[playerid]);
    PlayerTextDrawDestroy(playerid, mechmenu_vehinfo[playerid]);
    PlayerTextDrawDestroy(playerid, mechmenu_header_icon[playerid]);
    PlayerTextDrawDestroy(playerid, mechmenu_close[playerid]);
    PlayerTextDrawDestroy(playerid, mechamenu_back[playerid]);
    PlayerTextDrawDestroy(playerid, mechmenu_header_name[playerid]);
    PlayerTextDrawDestroy(playerid, mechmenu_upgrade_btn[playerid]);
    PlayerTextDrawDestroy(playerid, mechmenu_color_btn[playerid]);
    PlayerTextDrawDestroy(playerid, mechmenu_repair_btn[playerid]);
    PlayerTextDrawDestroy(playerid, mechmenu_repair_info[playerid]);
    PlayerTextDrawDestroy(playerid, mechmenu_repair_component[playerid]);
    PlayerTextDrawDestroy(playerid, mechmenu_repair_info2[playerid]);
    PlayerTextDrawDestroy(playerid, mechmenu_repair_install[playerid]);
    PlayerTextDrawDestroy(playerid, mechmenu_color_google[playerid]);
    PlayerTextDrawDestroy(playerid, mechmenu_color_component[playerid]);
    PlayerTextDrawDestroy(playerid, mechmenu_color_component2[playerid]);
    PlayerTextDrawDestroy(playerid, mechmenu_color_change[playerid]);
    PlayerTextDrawDestroy(playerid, mechmenu_color_componeed[playerid]);
    PlayerTextDrawDestroy(playerid, mechmenu_color_info[playerid]);
    PlayerTextDrawDestroy(playerid, mechmenu_upgrade_info[playerid]);
    PlayerTextDrawDestroy(playerid, mechmenu_upgrade_component2[playerid]);
    PlayerTextDrawDestroy(playerid, mechmenu_upgrade_btn[playerid]);
    PlayerTextDrawDestroy(playerid, mechmenu_upgrade_next[playerid]);
    PlayerTextDrawDestroy(playerid, mechmenu_upgrade_component1[playerid]);
    PlayerTextDrawDestroy(playerid, mechmenu_upgrade_component3[playerid]);
    return 1;
}

stock LoadPlayerMechanicTD(playerid)
{
    /* Default */
    mechmenu_box[playerid] = CreatePlayerTextDraw(playerid, 517.000000, 211.000000, "_");
	PlayerTextDrawFont(playerid, mechmenu_box[playerid], 1);
	PlayerTextDrawLetterSize(playerid, mechmenu_box[playerid], 0.600000, 10.600004);
	PlayerTextDrawTextSize(playerid, mechmenu_box[playerid], 298.500000, 181.000000);
	PlayerTextDrawSetOutline(playerid, mechmenu_box[playerid], 1);
	PlayerTextDrawSetShadow(playerid, mechmenu_box[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechmenu_box[playerid], 2);
	PlayerTextDrawColor(playerid, mechmenu_box[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, mechmenu_box[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechmenu_box[playerid], 135);
	PlayerTextDrawUseBox(playerid, mechmenu_box[playerid], 1);
	PlayerTextDrawSetProportional(playerid, mechmenu_box[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechmenu_box[playerid], 0);

	mechmenu_header_box[playerid] = CreatePlayerTextDraw(playerid, 517.000000, 211.000000, "_");
	PlayerTextDrawFont(playerid, mechmenu_header_box[playerid], 0);
	PlayerTextDrawLetterSize(playerid, mechmenu_header_box[playerid], 0.600000, 1.000002);
	PlayerTextDrawTextSize(playerid, mechmenu_header_box[playerid], 298.500000, 181.000000);
	PlayerTextDrawSetOutline(playerid, mechmenu_header_box[playerid], 1);
	PlayerTextDrawSetShadow(playerid, mechmenu_header_box[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechmenu_header_box[playerid], 2);
	PlayerTextDrawColor(playerid, mechmenu_header_box[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, mechmenu_header_box[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechmenu_header_box[playerid], 1097458055);
	PlayerTextDrawUseBox(playerid, mechmenu_header_box[playerid], 1);
	PlayerTextDrawSetProportional(playerid, mechmenu_header_box[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechmenu_header_box[playerid], 0);

	mechmenu_vehinfo[playerid] = CreatePlayerTextDraw(playerid, 429.000000, 287.000000, "~p~Informasi Kendaraan:~w~_(Model: ~y~Bus~w~)_(Mesin:_~r~Rusak~w~)_(ID_Warna:_2_3)_(Upgrade:_1/4)");
	PlayerTextDrawFont(playerid, mechmenu_vehinfo[playerid], 1);
	PlayerTextDrawLetterSize(playerid, mechmenu_vehinfo[playerid], 0.162496, 0.949998);
	PlayerTextDrawTextSize(playerid, mechmenu_vehinfo[playerid], 602.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, mechmenu_vehinfo[playerid], 1);
	PlayerTextDrawSetShadow(playerid, mechmenu_vehinfo[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechmenu_vehinfo[playerid], 1);
	PlayerTextDrawColor(playerid, mechmenu_vehinfo[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, mechmenu_vehinfo[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechmenu_vehinfo[playerid], 50);
	PlayerTextDrawUseBox(playerid, mechmenu_vehinfo[playerid], 0);
	PlayerTextDrawSetProportional(playerid, mechmenu_vehinfo[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechmenu_vehinfo[playerid], 0);

	mechmenu_header_icon[playerid] = CreatePlayerTextDraw(playerid, 427.000000, 211.000000, "HUD:radar_modgarage");
	PlayerTextDrawFont(playerid, mechmenu_header_icon[playerid], 4);
	PlayerTextDrawLetterSize(playerid, mechmenu_header_icon[playerid], 0.337498, 1.500000);
	PlayerTextDrawTextSize(playerid, mechmenu_header_icon[playerid], 8.000000, 9.000000);
	PlayerTextDrawSetOutline(playerid, mechmenu_header_icon[playerid], 0);
	PlayerTextDrawSetShadow(playerid, mechmenu_header_icon[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechmenu_header_icon[playerid], 2);
	PlayerTextDrawColor(playerid, mechmenu_header_icon[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, mechmenu_header_icon[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechmenu_header_icon[playerid], 100);
	PlayerTextDrawUseBox(playerid, mechmenu_header_icon[playerid], 1);
	PlayerTextDrawSetProportional(playerid, mechmenu_header_icon[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechmenu_header_icon[playerid], 0);

	mechmenu_close[playerid] = CreatePlayerTextDraw(playerid, 607.000000, 203.000000, "X");
	PlayerTextDrawFont(playerid, mechmenu_close[playerid], 1);
	PlayerTextDrawLetterSize(playerid, mechmenu_close[playerid], 0.583333, 2.000000);
	PlayerTextDrawTextSize(playerid, mechmenu_close[playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, mechmenu_close[playerid], 1);
	PlayerTextDrawSetShadow(playerid, mechmenu_close[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechmenu_close[playerid], 2);
	PlayerTextDrawColor(playerid, mechmenu_close[playerid], -16776961);
	PlayerTextDrawBackgroundColor(playerid, mechmenu_close[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechmenu_close[playerid], 50);
	PlayerTextDrawUseBox(playerid, mechmenu_close[playerid], 0);
	PlayerTextDrawSetProportional(playerid, mechmenu_close[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechmenu_close[playerid], 1);

	mechamenu_back[playerid] = CreatePlayerTextDraw(playerid, 453.000000, 226.000000, "< Kembali");
	PlayerTextDrawFont(playerid, mechamenu_back[playerid], 2);
	PlayerTextDrawLetterSize(playerid, mechamenu_back[playerid], 0.183329, 1.299998);
	PlayerTextDrawTextSize(playerid, mechamenu_back[playerid], 16.500000, 47.500000);
	PlayerTextDrawSetOutline(playerid, mechamenu_back[playerid], 1);
	PlayerTextDrawSetShadow(playerid, mechamenu_back[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechamenu_back[playerid], 2);
	PlayerTextDrawColor(playerid, mechamenu_back[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, mechamenu_back[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechamenu_back[playerid], -764862837);
	PlayerTextDrawUseBox(playerid, mechamenu_back[playerid], 1);
	PlayerTextDrawSetProportional(playerid, mechamenu_back[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechamenu_back[playerid], 1);

    /* Menus */
    mechmenu_upgrade_btn[playerid] = CreatePlayerTextDraw(playerid, 517.000000, 265.000000, "Upgrade");
	PlayerTextDrawFont(playerid, mechmenu_upgrade_btn[playerid], 3);
	PlayerTextDrawLetterSize(playerid, mechmenu_upgrade_btn[playerid], 0.337498, 1.500000);
	PlayerTextDrawTextSize(playerid, mechmenu_upgrade_btn[playerid], 16.500000, 172.000000);
	PlayerTextDrawSetOutline(playerid, mechmenu_upgrade_btn[playerid], 0);
	PlayerTextDrawSetShadow(playerid, mechmenu_upgrade_btn[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechmenu_upgrade_btn[playerid], 2);
	PlayerTextDrawColor(playerid, mechmenu_upgrade_btn[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, mechmenu_upgrade_btn[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechmenu_upgrade_btn[playerid], 100);
	PlayerTextDrawUseBox(playerid, mechmenu_upgrade_btn[playerid], 1);
	PlayerTextDrawSetProportional(playerid, mechmenu_upgrade_btn[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechmenu_upgrade_btn[playerid], 1);

	mechmenu_color_btn[playerid] = CreatePlayerTextDraw(playerid, 517.000000, 246.000000, "Ganti Warna");
	PlayerTextDrawFont(playerid, mechmenu_color_btn[playerid], 3);
	PlayerTextDrawLetterSize(playerid, mechmenu_color_btn[playerid], 0.337498, 1.500000);
	PlayerTextDrawTextSize(playerid, mechmenu_color_btn[playerid], 16.500000, 172.000000);
	PlayerTextDrawSetOutline(playerid, mechmenu_color_btn[playerid], 0);
	PlayerTextDrawSetShadow(playerid, mechmenu_color_btn[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechmenu_color_btn[playerid], 2);
	PlayerTextDrawColor(playerid, mechmenu_color_btn[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, mechmenu_color_btn[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechmenu_color_btn[playerid], 100);
	PlayerTextDrawUseBox(playerid, mechmenu_color_btn[playerid], 1);
	PlayerTextDrawSetProportional(playerid, mechmenu_color_btn[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechmenu_color_btn[playerid], 1);

	mechmenu_repair_btn[playerid] = CreatePlayerTextDraw(playerid, 517.000000, 227.000000, "Perbaiki Kendaraan");
	PlayerTextDrawFont(playerid, mechmenu_repair_btn[playerid], 3);
	PlayerTextDrawLetterSize(playerid, mechmenu_repair_btn[playerid], 0.337498, 1.500000);
	PlayerTextDrawTextSize(playerid, mechmenu_repair_btn[playerid], 16.500000, 172.000000);
	PlayerTextDrawSetOutline(playerid, mechmenu_repair_btn[playerid], 0);
	PlayerTextDrawSetShadow(playerid, mechmenu_repair_btn[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechmenu_repair_btn[playerid], 2);
	PlayerTextDrawColor(playerid, mechmenu_repair_btn[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, mechmenu_repair_btn[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechmenu_repair_btn[playerid], 100);
	PlayerTextDrawUseBox(playerid, mechmenu_repair_btn[playerid], 1);
	PlayerTextDrawSetProportional(playerid, mechmenu_repair_btn[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechmenu_repair_btn[playerid], 1);

    /* Repair */

    mechmenu_repair_info[playerid] = CreatePlayerTextDraw(playerid, 428.000000, 243.000000, "Untuk memperbaiki kendaraan ini, berikut adalah komponen yang diperlukan");
	PlayerTextDrawFont(playerid, mechmenu_repair_info[playerid], 1);
	PlayerTextDrawLetterSize(playerid, mechmenu_repair_info[playerid], 0.137500, 0.800000);
	PlayerTextDrawTextSize(playerid, mechmenu_repair_info[playerid], 603.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, mechmenu_repair_info[playerid], 0);
	PlayerTextDrawSetShadow(playerid, mechmenu_repair_info[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechmenu_repair_info[playerid], 1);
	PlayerTextDrawColor(playerid, mechmenu_repair_info[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, mechmenu_repair_info[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechmenu_repair_info[playerid], 50);
	PlayerTextDrawUseBox(playerid, mechmenu_repair_info[playerid], 0);
	PlayerTextDrawSetProportional(playerid, mechmenu_repair_info[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechmenu_repair_info[playerid], 0);

	mechmenu_repair_component[playerid] = CreatePlayerTextDraw(playerid, 474.000000, 250.000000, "000");
	PlayerTextDrawFont(playerid, mechmenu_repair_component[playerid], 3);
	PlayerTextDrawLetterSize(playerid, mechmenu_repair_component[playerid], 0.708333, 3.649991);
	PlayerTextDrawTextSize(playerid, mechmenu_repair_component[playerid], 603.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, mechmenu_repair_component[playerid], 1);
	PlayerTextDrawSetShadow(playerid, mechmenu_repair_component[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechmenu_repair_component[playerid], 3);
	PlayerTextDrawColor(playerid, mechmenu_repair_component[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, mechmenu_repair_component[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechmenu_repair_component[playerid], 50);
	PlayerTextDrawUseBox(playerid, mechmenu_repair_component[playerid], 0);
	PlayerTextDrawSetProportional(playerid, mechmenu_repair_component[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechmenu_repair_component[playerid], 0);

	mechmenu_repair_info2[playerid] = CreatePlayerTextDraw(playerid, 475.000000, 270.000000, "Komponen");
	PlayerTextDrawFont(playerid, mechmenu_repair_info2[playerid], 3);
	PlayerTextDrawLetterSize(playerid, mechmenu_repair_info2[playerid], 0.266665, 1.150001);
	PlayerTextDrawTextSize(playerid, mechmenu_repair_info2[playerid], 603.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, mechmenu_repair_info2[playerid], 1);
	PlayerTextDrawSetShadow(playerid, mechmenu_repair_info2[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechmenu_repair_info2[playerid], 1);
	PlayerTextDrawColor(playerid, mechmenu_repair_info2[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, mechmenu_repair_info2[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechmenu_repair_info2[playerid], 50);
	PlayerTextDrawUseBox(playerid, mechmenu_repair_info2[playerid], 0);
	PlayerTextDrawSetProportional(playerid, mechmenu_repair_info2[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechmenu_repair_info2[playerid], 0);

	mechmenu_repair_install[playerid] = CreatePlayerTextDraw(playerid, 568.000000, 257.000000, "Perbaiki");
	PlayerTextDrawFont(playerid, mechmenu_repair_install[playerid], 2);
	PlayerTextDrawLetterSize(playerid, mechmenu_repair_install[playerid], 0.308331, 2.349997);
	PlayerTextDrawTextSize(playerid, mechmenu_repair_install[playerid], 16.500000, 65.500000);
	PlayerTextDrawSetOutline(playerid, mechmenu_repair_install[playerid], 1);
	PlayerTextDrawSetShadow(playerid, mechmenu_repair_install[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechmenu_repair_install[playerid], 2);
	PlayerTextDrawColor(playerid, mechmenu_repair_install[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, mechmenu_repair_install[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechmenu_repair_install[playerid], -2016478606);
	PlayerTextDrawUseBox(playerid, mechmenu_repair_install[playerid], 1);
	PlayerTextDrawSetProportional(playerid, mechmenu_repair_install[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechmenu_repair_install[playerid], 1);

    /* Color */
    mechmenu_color_google[playerid] = CreatePlayerTextDraw(playerid, 483.000000, 228.000000, "Jika kamu tidak mengetahui id warna, silahkan cek di google!");
	PlayerTextDrawFont(playerid, mechmenu_color_google[playerid], 1);
	PlayerTextDrawLetterSize(playerid, mechmenu_color_google[playerid], 0.216665, 0.850000);
	PlayerTextDrawTextSize(playerid, mechmenu_color_google[playerid], 603.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, mechmenu_color_google[playerid], 1);
	PlayerTextDrawSetShadow(playerid, mechmenu_color_google[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechmenu_color_google[playerid], 1);
	PlayerTextDrawColor(playerid, mechmenu_color_google[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, mechmenu_color_google[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechmenu_color_google[playerid], 50);
	PlayerTextDrawUseBox(playerid, mechmenu_color_google[playerid], 0);
	PlayerTextDrawSetProportional(playerid, mechmenu_color_google[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechmenu_color_google[playerid], 0);

	mechmenu_color_component[playerid] = CreatePlayerTextDraw(playerid, 474.000000, 250.000000, "000");
	PlayerTextDrawFont(playerid, mechmenu_color_component[playerid], 3);
	PlayerTextDrawLetterSize(playerid, mechmenu_color_component[playerid], 0.708333, 3.649991);
	PlayerTextDrawTextSize(playerid, mechmenu_color_component[playerid], 603.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, mechmenu_color_component[playerid], 1);
	PlayerTextDrawSetShadow(playerid, mechmenu_color_component[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechmenu_color_component[playerid], 3);
	PlayerTextDrawColor(playerid, mechmenu_color_component[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, mechmenu_color_component[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechmenu_color_component[playerid], 50);
	PlayerTextDrawUseBox(playerid, mechmenu_color_component[playerid], 0);
	PlayerTextDrawSetProportional(playerid, mechmenu_color_component[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechmenu_color_component[playerid], 0);

	mechmenu_color_component2[playerid] = CreatePlayerTextDraw(playerid, 475.000000, 270.000000, "Komponen");
	PlayerTextDrawFont(playerid, mechmenu_color_component2[playerid], 3);
	PlayerTextDrawLetterSize(playerid, mechmenu_color_component2[playerid], 0.266665, 1.150001);
	PlayerTextDrawTextSize(playerid, mechmenu_color_component2[playerid], 603.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, mechmenu_color_component2[playerid], 1);
	PlayerTextDrawSetShadow(playerid, mechmenu_color_component2[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechmenu_color_component2[playerid], 1);
	PlayerTextDrawColor(playerid, mechmenu_color_component2[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, mechmenu_color_component2[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechmenu_color_component2[playerid], 50);
	PlayerTextDrawUseBox(playerid, mechmenu_color_component2[playerid], 0);
	PlayerTextDrawSetProportional(playerid, mechmenu_color_component2[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechmenu_color_component2[playerid], 0);

	mechmenu_color_change[playerid] = CreatePlayerTextDraw(playerid, 568.000000, 262.000000, "Ganti Warna");
	PlayerTextDrawFont(playerid, mechmenu_color_change[playerid], 2);
	PlayerTextDrawLetterSize(playerid, mechmenu_color_change[playerid], 0.187497, 1.849997);
	PlayerTextDrawTextSize(playerid, mechmenu_color_change[playerid], 16.500000, 65.500000);
	PlayerTextDrawSetOutline(playerid, mechmenu_color_change[playerid], 1);
	PlayerTextDrawSetShadow(playerid, mechmenu_color_change[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechmenu_color_change[playerid], 2);
	PlayerTextDrawColor(playerid, mechmenu_color_change[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, mechmenu_color_change[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechmenu_color_change[playerid], -2016478606);
	PlayerTextDrawUseBox(playerid, mechmenu_color_change[playerid], 1);
	PlayerTextDrawSetProportional(playerid, mechmenu_color_change[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechmenu_color_change[playerid], 1);

	mechmenu_color_componeed[playerid] = CreatePlayerTextDraw(playerid, 428.000000, 247.000000, "Jumlah Komponen Dibutuhkan");
	PlayerTextDrawFont(playerid, mechmenu_color_componeed[playerid], 2);
	PlayerTextDrawLetterSize(playerid, mechmenu_color_componeed[playerid], 0.116665, 0.699999);
	PlayerTextDrawTextSize(playerid, mechmenu_color_componeed[playerid], 574.500000, 9.500000);
	PlayerTextDrawSetOutline(playerid, mechmenu_color_componeed[playerid], 0);
	PlayerTextDrawSetShadow(playerid, mechmenu_color_componeed[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechmenu_color_componeed[playerid], 1);
	PlayerTextDrawColor(playerid, mechmenu_color_componeed[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, mechmenu_color_componeed[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechmenu_color_componeed[playerid], 50);
	PlayerTextDrawUseBox(playerid, mechmenu_color_componeed[playerid], 0);
	PlayerTextDrawSetProportional(playerid, mechmenu_color_componeed[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechmenu_color_componeed[playerid], 0);

	mechmenu_color_info[playerid] = CreatePlayerTextDraw(playerid, 522.000000, 248.000000, "~y~ID Warna saat ini: ~w~120 122");
	PlayerTextDrawFont(playerid, mechmenu_color_info[playerid], 1);
	PlayerTextDrawLetterSize(playerid, mechmenu_color_info[playerid], 0.174999, 0.849999);
	PlayerTextDrawTextSize(playerid, mechmenu_color_info[playerid], 606.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, mechmenu_color_info[playerid], 1);
	PlayerTextDrawSetShadow(playerid, mechmenu_color_info[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechmenu_color_info[playerid], 1);
	PlayerTextDrawColor(playerid, mechmenu_color_info[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, mechmenu_color_info[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechmenu_color_info[playerid], 50);
	PlayerTextDrawUseBox(playerid, mechmenu_color_info[playerid], 0);
	PlayerTextDrawSetProportional(playerid, mechmenu_color_info[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechmenu_color_info[playerid], 0);

    /* Upgrade */

    mechmenu_header_name[playerid] = CreatePlayerTextDraw(playerid, 439.000000, 211.000000, "Upgrade Kendaraan");
	PlayerTextDrawFont(playerid, mechmenu_header_name[playerid], 2);
	PlayerTextDrawLetterSize(playerid, mechmenu_header_name[playerid], 0.191666, 0.850000);
	PlayerTextDrawTextSize(playerid, mechmenu_header_name[playerid], 581.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, mechmenu_header_name[playerid], 0);
	PlayerTextDrawSetShadow(playerid, mechmenu_header_name[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechmenu_header_name[playerid], 1);
	PlayerTextDrawColor(playerid, mechmenu_header_name[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, mechmenu_header_name[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechmenu_header_name[playerid], 50);
	PlayerTextDrawUseBox(playerid, mechmenu_header_name[playerid], 0);
	PlayerTextDrawSetProportional(playerid, mechmenu_header_name[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechmenu_header_name[playerid], 0);

	mechmenu_upgrade_info[playerid] = CreatePlayerTextDraw(playerid, 483.000000, 226.000000, "Status Upgrade~n~~w~[~g~~h~Engine~w~]_[~g~~h~Body~w~]_[~r~~h~Fuel Tank~w~]");
	PlayerTextDrawFont(playerid, mechmenu_upgrade_info[playerid], 1);
	PlayerTextDrawLetterSize(playerid, mechmenu_upgrade_info[playerid], 0.170833, 0.699998);
	PlayerTextDrawTextSize(playerid, mechmenu_upgrade_info[playerid], 669.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, mechmenu_upgrade_info[playerid], 1);
	PlayerTextDrawSetShadow(playerid, mechmenu_upgrade_info[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechmenu_upgrade_info[playerid], 1);
	PlayerTextDrawColor(playerid, mechmenu_upgrade_info[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, mechmenu_upgrade_info[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechmenu_upgrade_info[playerid], 50);
	PlayerTextDrawUseBox(playerid, mechmenu_upgrade_info[playerid], 0);
	PlayerTextDrawSetProportional(playerid, mechmenu_upgrade_info[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechmenu_upgrade_info[playerid], 0);

	mechmenu_upgrade_component2[playerid] = CreatePlayerTextDraw(playerid, 497.000000, 259.000000, "400");
	PlayerTextDrawFont(playerid, mechmenu_upgrade_component2[playerid], 3);
	PlayerTextDrawLetterSize(playerid, mechmenu_upgrade_component2[playerid], 0.762498, 3.399996);
	PlayerTextDrawTextSize(playerid, mechmenu_upgrade_component2[playerid], 605.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, mechmenu_upgrade_component2[playerid], 1);
	PlayerTextDrawSetShadow(playerid, mechmenu_upgrade_component2[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechmenu_upgrade_component2[playerid], 1);
	PlayerTextDrawColor(playerid, mechmenu_upgrade_component2[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, mechmenu_upgrade_component2[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechmenu_upgrade_component2[playerid], 50);
	PlayerTextDrawUseBox(playerid, mechmenu_upgrade_component2[playerid], 0);
	PlayerTextDrawSetProportional(playerid, mechmenu_upgrade_component2[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechmenu_upgrade_component2[playerid], 0);

	mechmenu_upgrade_install[playerid] = CreatePlayerTextDraw(playerid, 461.000000, 259.000000, "Instal Upgrade");
	PlayerTextDrawFont(playerid, mechmenu_upgrade_install[playerid], 2);
	PlayerTextDrawLetterSize(playerid, mechmenu_upgrade_install[playerid], 0.283331, 1.099997);
	PlayerTextDrawTextSize(playerid, mechmenu_upgrade_install[playerid], 16.500000, 63.000000);
	PlayerTextDrawSetOutline(playerid, mechmenu_upgrade_install[playerid], 1);
	PlayerTextDrawSetShadow(playerid, mechmenu_upgrade_install[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechmenu_upgrade_install[playerid], 2);
	PlayerTextDrawColor(playerid, mechmenu_upgrade_install[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, mechmenu_upgrade_install[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechmenu_upgrade_install[playerid], 1687547279);
	PlayerTextDrawUseBox(playerid, mechmenu_upgrade_install[playerid], 1);
	PlayerTextDrawSetProportional(playerid, mechmenu_upgrade_install[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechmenu_upgrade_install[playerid], 1);

	mechmenu_upgrade_next[playerid] = CreatePlayerTextDraw(playerid, 429.000000, 243.000000, "Upgrade Selanjutnya: ~y~Fuel Tank");
	PlayerTextDrawFont(playerid, mechmenu_upgrade_next[playerid], 3);
	PlayerTextDrawLetterSize(playerid, mechmenu_upgrade_next[playerid], 0.262499, 1.250000);
	PlayerTextDrawTextSize(playerid, mechmenu_upgrade_next[playerid], 605.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, mechmenu_upgrade_next[playerid], 1);
	PlayerTextDrawSetShadow(playerid, mechmenu_upgrade_next[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechmenu_upgrade_next[playerid], 1);
	PlayerTextDrawColor(playerid, mechmenu_upgrade_next[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, mechmenu_upgrade_next[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechmenu_upgrade_next[playerid], 50);
	PlayerTextDrawUseBox(playerid, mechmenu_upgrade_next[playerid], 0);
	PlayerTextDrawSetProportional(playerid, mechmenu_upgrade_next[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechmenu_upgrade_next[playerid], 0);

	mechmenu_upgrade_component1[playerid] = CreatePlayerTextDraw(playerid, 497.000000, 257.000000, "Component Dibutuhkan");
	PlayerTextDrawFont(playerid, mechmenu_upgrade_component1[playerid], 2);
	PlayerTextDrawLetterSize(playerid, mechmenu_upgrade_component1[playerid], 0.104166, 0.699998);
	PlayerTextDrawTextSize(playerid, mechmenu_upgrade_component1[playerid], 605.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, mechmenu_upgrade_component1[playerid], 0);
	PlayerTextDrawSetShadow(playerid, mechmenu_upgrade_component1[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechmenu_upgrade_component1[playerid], 1);
	PlayerTextDrawColor(playerid, mechmenu_upgrade_component1[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, mechmenu_upgrade_component1[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechmenu_upgrade_component1[playerid], 50);
	PlayerTextDrawUseBox(playerid, mechmenu_upgrade_component1[playerid], 0);
	PlayerTextDrawSetProportional(playerid, mechmenu_upgrade_component1[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechmenu_upgrade_component1[playerid], 0);

	mechmenu_upgrade_component3[playerid] = CreatePlayerTextDraw(playerid, 548.000000, 277.000000, "Component");
	PlayerTextDrawFont(playerid, mechmenu_upgrade_component3[playerid], 3);
	PlayerTextDrawLetterSize(playerid, mechmenu_upgrade_component3[playerid], 0.229166, 1.049998);
	PlayerTextDrawTextSize(playerid, mechmenu_upgrade_component3[playerid], 605.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, mechmenu_upgrade_component3[playerid], 1);
	PlayerTextDrawSetShadow(playerid, mechmenu_upgrade_component3[playerid], 0);
	PlayerTextDrawAlignment(playerid, mechmenu_upgrade_component3[playerid], 1);
	PlayerTextDrawColor(playerid, mechmenu_upgrade_component3[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, mechmenu_upgrade_component3[playerid], 255);
	PlayerTextDrawBoxColor(playerid, mechmenu_upgrade_component3[playerid], 50);
	PlayerTextDrawUseBox(playerid, mechmenu_upgrade_component3[playerid], 0);
	PlayerTextDrawSetProportional(playerid, mechmenu_upgrade_component3[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, mechmenu_upgrade_component3[playerid], 0);
    return 1;
}