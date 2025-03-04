stock LoadPlayerCharacterSelectTD(playerid)
{
    character_selector_box[playerid] = CreatePlayerTextDraw(playerid, 492.000000, 135.000000, "_");
	PlayerTextDrawFont(playerid, character_selector_box[playerid], 1);
	PlayerTextDrawLetterSize(playerid, character_selector_box[playerid], 0.600000, 23.300003);
	PlayerTextDrawTextSize(playerid, character_selector_box[playerid], 298.500000, 161.500000);
	PlayerTextDrawSetOutline(playerid, character_selector_box[playerid], 1);
	PlayerTextDrawSetShadow(playerid, character_selector_box[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_selector_box[playerid], 2);
	PlayerTextDrawColor(playerid, character_selector_box[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_selector_box[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_selector_box[playerid], 135);
	PlayerTextDrawUseBox(playerid, character_selector_box[playerid], 1);
	PlayerTextDrawSetProportional(playerid, character_selector_box[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_selector_box[playerid], 0);

	character_selector_header1[playerid] = CreatePlayerTextDraw(playerid, 414.000000, 141.000000, "PILIH KARAKTER KAMU");
	PlayerTextDrawFont(playerid, character_selector_header1[playerid], 3);
	PlayerTextDrawLetterSize(playerid, character_selector_header1[playerid], 0.429165, 1.649999);
	PlayerTextDrawTextSize(playerid, character_selector_header1[playerid], 570.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, character_selector_header1[playerid], 0);
	PlayerTextDrawSetShadow(playerid, character_selector_header1[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_selector_header1[playerid], 1);
	PlayerTextDrawColor(playerid, character_selector_header1[playerid], 1687547391);
	PlayerTextDrawBackgroundColor(playerid, character_selector_header1[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_selector_header1[playerid], 1687547186);
	PlayerTextDrawUseBox(playerid, character_selector_header1[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_selector_header1[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_selector_header1[playerid], 0);

	character_selector_header2[playerid] = CreatePlayerTextDraw(playerid, 413.000000, 139.000000, "PILIH KARAKTER KAMU");
	PlayerTextDrawFont(playerid, character_selector_header2[playerid], 3);
	PlayerTextDrawLetterSize(playerid, character_selector_header2[playerid], 0.429165, 1.649999);
	PlayerTextDrawTextSize(playerid, character_selector_header2[playerid], 570.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, character_selector_header2[playerid], 0);
	PlayerTextDrawSetShadow(playerid, character_selector_header2[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_selector_header2[playerid], 1);
	PlayerTextDrawColor(playerid, character_selector_header2[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_selector_header2[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_selector_header2[playerid], 50);
	PlayerTextDrawUseBox(playerid, character_selector_header2[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_selector_header2[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_selector_header2[playerid], 0);

	character_selector_infobox[playerid] = CreatePlayerTextDraw(playerid, 492.000000, 161.000000, "_");
	PlayerTextDrawFont(playerid, character_selector_infobox[playerid], 1);
	PlayerTextDrawLetterSize(playerid, character_selector_infobox[playerid], 0.600000, 14.450016);
	PlayerTextDrawTextSize(playerid, character_selector_infobox[playerid], 298.500000, 150.500000);
	PlayerTextDrawSetOutline(playerid, character_selector_infobox[playerid], 1);
	PlayerTextDrawSetShadow(playerid, character_selector_infobox[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_selector_infobox[playerid], 2);
	PlayerTextDrawColor(playerid, character_selector_infobox[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_selector_infobox[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_selector_infobox[playerid], 135);
	PlayerTextDrawUseBox(playerid, character_selector_infobox[playerid], 1);
	PlayerTextDrawSetProportional(playerid, character_selector_infobox[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_selector_infobox[playerid], 0);

	character_selector_nochar[playerid] = CreatePlayerTextDraw(playerid, 420.000000, 190.000000, "Karakter kamu pada slot ini kosong! Klik tombol dibawah untuk membuat karakter");
	PlayerTextDrawFont(playerid, character_selector_nochar[playerid], 1);
	PlayerTextDrawLetterSize(playerid, character_selector_nochar[playerid], 0.300000, 1.350000);
	PlayerTextDrawTextSize(playerid, character_selector_nochar[playerid], 564.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, character_selector_nochar[playerid], 1);
	PlayerTextDrawSetShadow(playerid, character_selector_nochar[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_selector_nochar[playerid], 1);
	PlayerTextDrawColor(playerid, character_selector_nochar[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_selector_nochar[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_selector_nochar[playerid], 50);
	PlayerTextDrawUseBox(playerid, character_selector_nochar[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_selector_nochar[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_selector_nochar[playerid], 0);

	character_selector_name[playerid] = CreatePlayerTextDraw(playerid, 420.000000, 164.000000, "Supra_Sudarshan");
	PlayerTextDrawFont(playerid, character_selector_name[playerid], 0);
	PlayerTextDrawLetterSize(playerid, character_selector_name[playerid], 0.345833, 1.350000);
	PlayerTextDrawTextSize(playerid, character_selector_name[playerid], 564.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, character_selector_name[playerid], 1);
	PlayerTextDrawSetShadow(playerid, character_selector_name[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_selector_name[playerid], 1);
	PlayerTextDrawColor(playerid, character_selector_name[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_selector_name[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_selector_name[playerid], 50);
	PlayerTextDrawUseBox(playerid, character_selector_name[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_selector_name[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_selector_name[playerid], 0);

	character_selector_level[playerid] = CreatePlayerTextDraw(playerid, 420.000000, 184.000000, "Level : ~y~25/100");
	PlayerTextDrawFont(playerid, character_selector_level[playerid], 1);
	PlayerTextDrawLetterSize(playerid, character_selector_level[playerid], 0.300000, 1.350000);
	PlayerTextDrawTextSize(playerid, character_selector_level[playerid], 564.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, character_selector_level[playerid], 1);
	PlayerTextDrawSetShadow(playerid, character_selector_level[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_selector_level[playerid], 1);
	PlayerTextDrawColor(playerid, character_selector_level[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_selector_level[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_selector_level[playerid], 50);
	PlayerTextDrawUseBox(playerid, character_selector_level[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_selector_level[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_selector_level[playerid], 0);

	character_selector_uang[playerid] = CreatePlayerTextDraw(playerid, 420.000000, 204.000000, "Uang: ~g~~h~$500,000.00");
	PlayerTextDrawFont(playerid, character_selector_uang[playerid], 1);
	PlayerTextDrawLetterSize(playerid, character_selector_uang[playerid], 0.300000, 1.350000);
	PlayerTextDrawTextSize(playerid, character_selector_uang[playerid], 564.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, character_selector_uang[playerid], 1);
	PlayerTextDrawSetShadow(playerid, character_selector_uang[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_selector_uang[playerid], 1);
	PlayerTextDrawColor(playerid, character_selector_uang[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_selector_uang[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_selector_uang[playerid], 50);
	PlayerTextDrawUseBox(playerid, character_selector_uang[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_selector_uang[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_selector_uang[playerid], 0);

	character_selector_kelamin[playerid] = CreatePlayerTextDraw(playerid, 420.000000, 224.000000, "Kelamin: ~b~~h~Perempuan");
	PlayerTextDrawFont(playerid, character_selector_kelamin[playerid], 1);
	PlayerTextDrawLetterSize(playerid, character_selector_kelamin[playerid], 0.300000, 1.350000);
	PlayerTextDrawTextSize(playerid, character_selector_kelamin[playerid], 564.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, character_selector_kelamin[playerid], 1);
	PlayerTextDrawSetShadow(playerid, character_selector_kelamin[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_selector_kelamin[playerid], 1);
	PlayerTextDrawColor(playerid, character_selector_kelamin[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_selector_kelamin[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_selector_kelamin[playerid], 50);
	PlayerTextDrawUseBox(playerid, character_selector_kelamin[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_selector_kelamin[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_selector_kelamin[playerid], 0);

	character_selector_terakhir[playerid] = CreatePlayerTextDraw(playerid, 420.000000, 244.000000, "Terakhir Terlihat Pada:");
	PlayerTextDrawFont(playerid, character_selector_terakhir[playerid], 1);
	PlayerTextDrawLetterSize(playerid, character_selector_terakhir[playerid], 0.174998, 0.949998);
	PlayerTextDrawTextSize(playerid, character_selector_terakhir[playerid], 564.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, character_selector_terakhir[playerid], 1);
	PlayerTextDrawSetShadow(playerid, character_selector_terakhir[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_selector_terakhir[playerid], 1);
	PlayerTextDrawColor(playerid, character_selector_terakhir[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_selector_terakhir[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_selector_terakhir[playerid], 50);
	PlayerTextDrawUseBox(playerid, character_selector_terakhir[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_selector_terakhir[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_selector_terakhir[playerid], 0);

	character_selector_terakhirinfo[playerid] = CreatePlayerTextDraw(playerid, 428.000000, 257.000000, "Reno dwi sigma skibidi toilet asiq cihuy papale");
	PlayerTextDrawFont(playerid, character_selector_terakhirinfo[playerid], 1);
	PlayerTextDrawLetterSize(playerid, character_selector_terakhirinfo[playerid], 0.229166, 1.250000);
	PlayerTextDrawTextSize(playerid, character_selector_terakhirinfo[playerid], 564.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, character_selector_terakhirinfo[playerid], 1);
	PlayerTextDrawSetShadow(playerid, character_selector_terakhirinfo[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_selector_terakhirinfo[playerid], 1);
	PlayerTextDrawColor(playerid, character_selector_terakhirinfo[playerid], -764862721);
	PlayerTextDrawBackgroundColor(playerid, character_selector_terakhirinfo[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_selector_terakhirinfo[playerid], 50);
	PlayerTextDrawUseBox(playerid, character_selector_terakhirinfo[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_selector_terakhirinfo[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_selector_terakhirinfo[playerid], 0);

	character_selector_enterbtn[playerid] = CreatePlayerTextDraw(playerid, 492.000000, 309.000000, "Buat Karakter");
	PlayerTextDrawFont(playerid, character_selector_enterbtn[playerid], 2);
	PlayerTextDrawLetterSize(playerid, character_selector_enterbtn[playerid], 0.212497, 1.600000);
	PlayerTextDrawTextSize(playerid, character_selector_enterbtn[playerid], 16.500000, 79.500000);
	PlayerTextDrawSetOutline(playerid, character_selector_enterbtn[playerid], 1);
	PlayerTextDrawSetShadow(playerid, character_selector_enterbtn[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_selector_enterbtn[playerid], 2);
	PlayerTextDrawColor(playerid, character_selector_enterbtn[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_selector_enterbtn[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_selector_enterbtn[playerid], 200);
	PlayerTextDrawUseBox(playerid, character_selector_enterbtn[playerid], 1);
	PlayerTextDrawSetProportional(playerid, character_selector_enterbtn[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_selector_enterbtn[playerid], 1);

	character_selector_rightbtn[playerid] = CreatePlayerTextDraw(playerid, 532.000000, 288.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, character_selector_rightbtn[playerid], 5);
	PlayerTextDrawLetterSize(playerid, character_selector_rightbtn[playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, character_selector_rightbtn[playerid], 45.500000, 57.500000);
	PlayerTextDrawSetOutline(playerid, character_selector_rightbtn[playerid], 0);
	PlayerTextDrawSetShadow(playerid, character_selector_rightbtn[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_selector_rightbtn[playerid], 1);
	PlayerTextDrawColor(playerid, character_selector_rightbtn[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_selector_rightbtn[playerid], 0);
	PlayerTextDrawBoxColor(playerid, character_selector_rightbtn[playerid], 255);
	PlayerTextDrawUseBox(playerid, character_selector_rightbtn[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_selector_rightbtn[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_selector_rightbtn[playerid], 1);
	PlayerTextDrawSetPreviewModel(playerid, character_selector_rightbtn[playerid], 19130);
	PlayerTextDrawSetPreviewRot(playerid, character_selector_rightbtn[playerid], 0.000000, 90.000000, 90.000000, 1.000000);
	PlayerTextDrawSetPreviewVehCol(playerid, character_selector_rightbtn[playerid], 1, 1);

	character_selector_leftbtn[playerid] = CreatePlayerTextDraw(playerid, 407.000000, 288.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, character_selector_leftbtn[playerid], 5);
	PlayerTextDrawLetterSize(playerid, character_selector_leftbtn[playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, character_selector_leftbtn[playerid], 45.500000, 57.500000);
	PlayerTextDrawSetOutline(playerid, character_selector_leftbtn[playerid], 0);
	PlayerTextDrawSetShadow(playerid, character_selector_leftbtn[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_selector_leftbtn[playerid], 1);
	PlayerTextDrawColor(playerid, character_selector_leftbtn[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_selector_leftbtn[playerid], 0);
	PlayerTextDrawBoxColor(playerid, character_selector_leftbtn[playerid], 255);
	PlayerTextDrawUseBox(playerid, character_selector_leftbtn[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_selector_leftbtn[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_selector_leftbtn[playerid], 1);
	PlayerTextDrawSetPreviewModel(playerid, character_selector_leftbtn[playerid], 19130);
	PlayerTextDrawSetPreviewRot(playerid, character_selector_leftbtn[playerid], 0.000000, -90.000000, 90.000000, 1.000000);
	PlayerTextDrawSetPreviewVehCol(playerid, character_selector_leftbtn[playerid], 1, 1);

	character_selector_indicator[playerid] = CreatePlayerTextDraw(playerid, 492.000000, 296.000000, "1/5");
	PlayerTextDrawFont(playerid, character_selector_indicator[playerid], 2);
	PlayerTextDrawLetterSize(playerid, character_selector_indicator[playerid], 0.291666, 0.950000);
	PlayerTextDrawTextSize(playerid, character_selector_indicator[playerid], 400.000000, 48.000000);
	PlayerTextDrawSetOutline(playerid, character_selector_indicator[playerid], 1);
	PlayerTextDrawSetShadow(playerid, character_selector_indicator[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_selector_indicator[playerid], 2);
	PlayerTextDrawColor(playerid, character_selector_indicator[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_selector_indicator[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_selector_indicator[playerid], 50);
	PlayerTextDrawUseBox(playerid, character_selector_indicator[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_selector_indicator[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_selector_indicator[playerid], 0);
    return 1;
}

stock DestroyPlayerCharacterSelectTD(playerid) 
{
    PlayerTextDrawDestroy(playerid, character_selector_box[playerid]);
	PlayerTextDrawDestroy(playerid, character_selector_header1[playerid]);
	PlayerTextDrawDestroy(playerid, character_selector_header2[playerid]);
	PlayerTextDrawDestroy(playerid, character_selector_infobox[playerid]);
	PlayerTextDrawDestroy(playerid, character_selector_name[playerid]);
	PlayerTextDrawDestroy(playerid, character_selector_level[playerid]);
	PlayerTextDrawDestroy(playerid, character_selector_uang[playerid]);
	PlayerTextDrawDestroy(playerid, character_selector_kelamin[playerid]);
	PlayerTextDrawDestroy(playerid, character_selector_terakhir[playerid]);
	PlayerTextDrawDestroy(playerid, character_selector_terakhirinfo[playerid]);
	PlayerTextDrawDestroy(playerid, character_selector_enterbtn[playerid]);
	PlayerTextDrawDestroy(playerid, character_selector_rightbtn[playerid]);
	PlayerTextDrawDestroy(playerid, character_selector_leftbtn[playerid]);
    return 1;
}

stock ShowPlayerCharacterSelectTD(playerid, const name[], level, money, gender, Timestamp:lastseen, Float:lastseen_posx, Float:lastseen_posy, Float:lastseen_posz)
{
	PlayerTextDrawHide(playerid, character_selector_nochar[playerid]);

    PlayerTextDrawSetString(playerid, character_selector_name[playerid], name);

    new level_fix[100];
    format(level_fix, sizeof(level_fix), "~w~Level: ~y~%d", level);
    PlayerTextDrawSetString(playerid, character_selector_level[playerid], level_fix);

    new uang_fix[100];
    format(uang_fix, sizeof(uang_fix), "~w~Uang: ~g~~h~$%s", FormatMoney(money));
    PlayerTextDrawSetString(playerid, character_selector_uang[playerid], uang_fix);

    new gender_fix[100];
    if(gender == GENDER_MALE) format(gender_fix, sizeof(gender_fix), "~w~Kelamin: ~b~~h~Pria");
    else if(gender == GENDER_FEMALE) format(gender_fix, sizeof(gender_fix), "~w~Kelamin: ~p~~h~Perempuan");
    PlayerTextDrawSetString(playerid, character_selector_kelamin[playerid], gender_fix);

	if(!strcmp(TimestampToDateString(lastseen), "1 Januari 1970", true)) 
	{
		PlayerTextDrawSetString(playerid, character_selector_terakhirinfo[playerid], "Tidak diketahui");
	}
	else 
	{
		new lastseen_fix[200];
		format(lastseen_fix, sizeof(lastseen_fix), "%s, %s", TimestampToDateString(lastseen), GetLocation(lastseen_posx, lastseen_posy, lastseen_posz));
		PlayerTextDrawSetString(playerid, character_selector_terakhirinfo[playerid], lastseen_fix);
	}

	PlayerTextDrawSetString(playerid, character_selector_enterbtn[playerid], "Pilih Karakter");

    PlayerTextDrawShow(playerid, character_selector_box[playerid]);
	PlayerTextDrawShow(playerid, character_selector_header1[playerid]);
	PlayerTextDrawShow(playerid, character_selector_header2[playerid]);
	PlayerTextDrawShow(playerid, character_selector_infobox[playerid]);
	PlayerTextDrawShow(playerid, character_selector_name[playerid]);
	PlayerTextDrawShow(playerid, character_selector_level[playerid]);
	PlayerTextDrawShow(playerid, character_selector_uang[playerid]);
	PlayerTextDrawShow(playerid, character_selector_kelamin[playerid]);
	PlayerTextDrawShow(playerid, character_selector_terakhir[playerid]);
	PlayerTextDrawShow(playerid, character_selector_terakhirinfo[playerid]);
	PlayerTextDrawShow(playerid, character_selector_enterbtn[playerid]);
	PlayerTextDrawShow(playerid, character_selector_rightbtn[playerid]);
	PlayerTextDrawShow(playerid, character_selector_leftbtn[playerid]);
    SelectTextDraw(playerid);
    return 1;
}

stock ShowPlayerCharacterNoCharTD(playerid) 
{
	PlayerTextDrawHide(playerid, character_selector_name[playerid]);
	PlayerTextDrawHide(playerid, character_selector_level[playerid]);
	PlayerTextDrawHide(playerid, character_selector_uang[playerid]);
	PlayerTextDrawHide(playerid, character_selector_kelamin[playerid]);
	PlayerTextDrawHide(playerid, character_selector_terakhir[playerid]);
	PlayerTextDrawHide(playerid, character_selector_terakhirinfo[playerid]);

	PlayerTextDrawSetString(playerid, character_selector_enterbtn[playerid], "Buat Karakter");

	PlayerTextDrawShow(playerid, character_selector_box[playerid]);
	PlayerTextDrawShow(playerid, character_selector_header1[playerid]);
	PlayerTextDrawShow(playerid, character_selector_header2[playerid]);
	PlayerTextDrawShow(playerid, character_selector_infobox[playerid]);
	PlayerTextDrawShow(playerid, character_selector_nochar[playerid]);
	PlayerTextDrawShow(playerid, character_selector_enterbtn[playerid]);
	PlayerTextDrawShow(playerid, character_selector_rightbtn[playerid]);
	PlayerTextDrawShow(playerid, character_selector_leftbtn[playerid]);

	SelectTextDraw(playerid);
	return 1;
}

stock ShowPlayerCharacterIndicator(playerid, slot, slot_max)
{
	new message[200];
	format(message, sizeof(message), "%d/%d", slot + 1, slot_max + 1);
	PlayerTextDrawSetString(playerid, character_selector_indicator[playerid], message);
	PlayerTextDrawShow(playerid, character_selector_indicator[playerid]);
	return 1;
}

stock HidePlayerCharacterSelectTD(playerid) 
{
	PlayerTextDrawHide(playerid, character_selector_box[playerid]);
	PlayerTextDrawHide(playerid, character_selector_header1[playerid]);
	PlayerTextDrawHide(playerid, character_selector_header2[playerid]);
	PlayerTextDrawHide(playerid, character_selector_infobox[playerid]);
	PlayerTextDrawHide(playerid, character_selector_name[playerid]);
	PlayerTextDrawHide(playerid, character_selector_level[playerid]);
	PlayerTextDrawHide(playerid, character_selector_uang[playerid]);
	PlayerTextDrawHide(playerid, character_selector_kelamin[playerid]);
	PlayerTextDrawHide(playerid, character_selector_terakhir[playerid]);
	PlayerTextDrawHide(playerid, character_selector_terakhirinfo[playerid]);
	PlayerTextDrawHide(playerid, character_selector_enterbtn[playerid]);
	PlayerTextDrawHide(playerid, character_selector_rightbtn[playerid]);
	PlayerTextDrawHide(playerid, character_selector_leftbtn[playerid]);
	PlayerTextDrawHide(playerid, character_selector_nochar[playerid]);
	PlayerTextDrawHide(playerid, character_selector_indicator[playerid]);

	CancelSelectTextDraw(playerid);
	return 1;
}