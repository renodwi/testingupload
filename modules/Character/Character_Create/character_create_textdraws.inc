stock LoadPlayerCreateCharacterTD(playerid) 
{
    character_creator_box[playerid] = CreatePlayerTextDraw(playerid, 492.000000, 135.000000, "_");
	PlayerTextDrawFont(playerid, character_creator_box[playerid], 1);
	PlayerTextDrawLetterSize(playerid, character_creator_box[playerid], 0.600000, 23.300003);
	PlayerTextDrawTextSize(playerid, character_creator_box[playerid], 298.500000, 164.500000);
	PlayerTextDrawSetOutline(playerid, character_creator_box[playerid], 1);
	PlayerTextDrawSetShadow(playerid, character_creator_box[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_creator_box[playerid], 2);
	PlayerTextDrawColor(playerid, character_creator_box[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_creator_box[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_creator_box[playerid], 135);
	PlayerTextDrawUseBox(playerid, character_creator_box[playerid], 1);
	PlayerTextDrawSetProportional(playerid, character_creator_box[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_creator_box[playerid], 0);

	character_creator_header1[playerid] = CreatePlayerTextDraw(playerid, 414.000000, 141.000000, "Buat Karakter Kamu");
	PlayerTextDrawFont(playerid, character_creator_header1[playerid], 3);
	PlayerTextDrawLetterSize(playerid, character_creator_header1[playerid], 0.429165, 1.649999);
	PlayerTextDrawTextSize(playerid, character_creator_header1[playerid], 570.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, character_creator_header1[playerid], 0);
	PlayerTextDrawSetShadow(playerid, character_creator_header1[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_creator_header1[playerid], 1);
	PlayerTextDrawColor(playerid, character_creator_header1[playerid], 1687547391);
	PlayerTextDrawBackgroundColor(playerid, character_creator_header1[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_creator_header1[playerid], 1687547186);
	PlayerTextDrawUseBox(playerid, character_creator_header1[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_creator_header1[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_creator_header1[playerid], 0);

	character_creator_header2[playerid] = CreatePlayerTextDraw(playerid, 413.000000, 139.000000, "Buat Karakter Kamu");
	PlayerTextDrawFont(playerid, character_creator_header2[playerid], 3);
	PlayerTextDrawLetterSize(playerid, character_creator_header2[playerid], 0.429165, 1.649999);
	PlayerTextDrawTextSize(playerid, character_creator_header2[playerid], 570.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, character_creator_header2[playerid], 0);
	PlayerTextDrawSetShadow(playerid, character_creator_header2[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_creator_header2[playerid], 1);
	PlayerTextDrawColor(playerid, character_creator_header2[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_creator_header2[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_creator_header2[playerid], 50);
	PlayerTextDrawUseBox(playerid, character_creator_header2[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_creator_header2[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_creator_header2[playerid], 0);

	character_creator_infobox[playerid] = CreatePlayerTextDraw(playerid, 492.000000, 161.000000, "_");
	PlayerTextDrawFont(playerid, character_creator_infobox[playerid], 1);
	PlayerTextDrawLetterSize(playerid, character_creator_infobox[playerid], 0.600000, 16.150018);
	PlayerTextDrawTextSize(playerid, character_creator_infobox[playerid], 298.500000, 150.500000);
	PlayerTextDrawSetOutline(playerid, character_creator_infobox[playerid], 1);
	PlayerTextDrawSetShadow(playerid, character_creator_infobox[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_creator_infobox[playerid], 2);
	PlayerTextDrawColor(playerid, character_creator_infobox[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_creator_infobox[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_creator_infobox[playerid], 135);
	PlayerTextDrawUseBox(playerid, character_creator_infobox[playerid], 1);
	PlayerTextDrawSetProportional(playerid, character_creator_infobox[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_creator_infobox[playerid], 0);

	character_creator_name[playerid] = CreatePlayerTextDraw(playerid, 420.000000, 164.000000, "Supra_Sudarshan");
	PlayerTextDrawFont(playerid, character_creator_name[playerid], 0);
	PlayerTextDrawLetterSize(playerid, character_creator_name[playerid], 0.345833, 1.350000);
	PlayerTextDrawTextSize(playerid, character_creator_name[playerid], 525.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, character_creator_name[playerid], 1);
	PlayerTextDrawSetShadow(playerid, character_creator_name[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_creator_name[playerid], 1);
	PlayerTextDrawColor(playerid, character_creator_name[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_creator_name[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_creator_name[playerid], 50);
	PlayerTextDrawUseBox(playerid, character_creator_name[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_creator_name[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_creator_name[playerid], 0);

	character_creator_asal[playerid] = CreatePlayerTextDraw(playerid, 420.000000, 188.000000, "Asal : ~n~~y~Indonesia");
	PlayerTextDrawFont(playerid, character_creator_asal[playerid], 1);
	PlayerTextDrawLetterSize(playerid, character_creator_asal[playerid], 0.300000, 1.350000);
	PlayerTextDrawTextSize(playerid, character_creator_asal[playerid], 525.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, character_creator_asal[playerid], 1);
	PlayerTextDrawSetShadow(playerid, character_creator_asal[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_creator_asal[playerid], 1);
	PlayerTextDrawColor(playerid, character_creator_asal[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_creator_asal[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_creator_asal[playerid], 50);
	PlayerTextDrawUseBox(playerid, character_creator_asal[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_creator_asal[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_creator_asal[playerid], 0);

	character_creator_kelamin[playerid] = CreatePlayerTextDraw(playerid, 420.000000, 221.000000, "Kelamin: ~n~~p~~h~Perempuan");
	PlayerTextDrawFont(playerid, character_creator_kelamin[playerid], 1);
	PlayerTextDrawLetterSize(playerid, character_creator_kelamin[playerid], 0.300000, 1.350000);
	PlayerTextDrawTextSize(playerid, character_creator_kelamin[playerid], 525.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, character_creator_kelamin[playerid], 1);
	PlayerTextDrawSetShadow(playerid, character_creator_kelamin[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_creator_kelamin[playerid], 1);
	PlayerTextDrawColor(playerid, character_creator_kelamin[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_creator_kelamin[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_creator_kelamin[playerid], 50);
	PlayerTextDrawUseBox(playerid, character_creator_kelamin[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_creator_kelamin[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_creator_kelamin[playerid], 0);

	character_creator_lahir[playerid] = CreatePlayerTextDraw(playerid, 420.000000, 256.000000, "Tanggal Lahir: ~n~~g~~h~8 Maret 2008");
	PlayerTextDrawFont(playerid, character_creator_lahir[playerid], 1);
	PlayerTextDrawLetterSize(playerid, character_creator_lahir[playerid], 0.300000, 1.350000);
	PlayerTextDrawTextSize(playerid, character_creator_lahir[playerid], 523.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, character_creator_lahir[playerid], 1);
	PlayerTextDrawSetShadow(playerid, character_creator_lahir[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_creator_lahir[playerid], 1);
	PlayerTextDrawColor(playerid, character_creator_lahir[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_creator_lahir[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_creator_lahir[playerid], 50);
	PlayerTextDrawUseBox(playerid, character_creator_lahir[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_creator_lahir[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_creator_lahir[playerid], 0);

	character_creator_ubahlahirbtn[playerid] = CreatePlayerTextDraw(playerid, 535.000000, 247.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, character_creator_ubahlahirbtn[playerid], 5);
	PlayerTextDrawLetterSize(playerid, character_creator_ubahlahirbtn[playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, character_creator_ubahlahirbtn[playerid], 37.500000, 28.000000);
	PlayerTextDrawSetOutline(playerid, character_creator_ubahlahirbtn[playerid], 0);
	PlayerTextDrawSetShadow(playerid, character_creator_ubahlahirbtn[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_creator_ubahlahirbtn[playerid], 1);
	PlayerTextDrawColor(playerid, character_creator_ubahlahirbtn[playerid], -16776961);
	PlayerTextDrawBackgroundColor(playerid, character_creator_ubahlahirbtn[playerid], -256);
	PlayerTextDrawBoxColor(playerid, character_creator_ubahlahirbtn[playerid], 255);
	PlayerTextDrawUseBox(playerid, character_creator_ubahlahirbtn[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_creator_ubahlahirbtn[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_creator_ubahlahirbtn[playerid], 1);
	PlayerTextDrawSetPreviewModel(playerid, character_creator_ubahlahirbtn[playerid], 1239);
	PlayerTextDrawSetPreviewRot(playerid, character_creator_ubahlahirbtn[playerid], 0.000000, 90.000000, 90.000000, 0.790000);
	PlayerTextDrawSetPreviewVehCol(playerid, character_creator_ubahlahirbtn[playerid], 1, 1);

	character_creator_ubahklmnbtn[playerid] = CreatePlayerTextDraw(playerid, 535.000000, 218.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, character_creator_ubahklmnbtn[playerid], 5);
	PlayerTextDrawLetterSize(playerid, character_creator_ubahklmnbtn[playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, character_creator_ubahklmnbtn[playerid], 37.500000, 28.000000);
	PlayerTextDrawSetOutline(playerid, character_creator_ubahklmnbtn[playerid], 0);
	PlayerTextDrawSetShadow(playerid, character_creator_ubahklmnbtn[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_creator_ubahklmnbtn[playerid], 1);
	PlayerTextDrawColor(playerid, character_creator_ubahklmnbtn[playerid], -16776961);
	PlayerTextDrawBackgroundColor(playerid, character_creator_ubahklmnbtn[playerid], -256);
	PlayerTextDrawBoxColor(playerid, character_creator_ubahklmnbtn[playerid], 255);
	PlayerTextDrawUseBox(playerid, character_creator_ubahklmnbtn[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_creator_ubahklmnbtn[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_creator_ubahklmnbtn[playerid], 1);
	PlayerTextDrawSetPreviewModel(playerid, character_creator_ubahklmnbtn[playerid], 1239);
	PlayerTextDrawSetPreviewRot(playerid, character_creator_ubahklmnbtn[playerid], 0.000000, 90.000000, 90.000000, 0.790000);
	PlayerTextDrawSetPreviewVehCol(playerid, character_creator_ubahklmnbtn[playerid], 1, 1);

	character_creator_batalkanbtn[playerid] = CreatePlayerTextDraw(playerid, 509.000000, 312.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, character_creator_batalkanbtn[playerid], 5);
	PlayerTextDrawLetterSize(playerid, character_creator_batalkanbtn[playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, character_creator_batalkanbtn[playerid], 52.000000, 26.000000);
	PlayerTextDrawSetOutline(playerid, character_creator_batalkanbtn[playerid], 0);
	PlayerTextDrawSetShadow(playerid, character_creator_batalkanbtn[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_creator_batalkanbtn[playerid], 1);
	PlayerTextDrawColor(playerid, character_creator_batalkanbtn[playerid], -16776961);
	PlayerTextDrawBackgroundColor(playerid, character_creator_batalkanbtn[playerid], -256);
	PlayerTextDrawBoxColor(playerid, character_creator_batalkanbtn[playerid], 255);
	PlayerTextDrawUseBox(playerid, character_creator_batalkanbtn[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_creator_batalkanbtn[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_creator_batalkanbtn[playerid], 1);
	PlayerTextDrawSetPreviewModel(playerid, character_creator_batalkanbtn[playerid], 19454);
	PlayerTextDrawSetPreviewRot(playerid, character_creator_batalkanbtn[playerid], 180.000000, 0.000000, 60.000000, 0.349999);
	PlayerTextDrawSetPreviewVehCol(playerid, character_creator_batalkanbtn[playerid], 1, 1);

	character_creator_ubahasalbtn[playerid] = CreatePlayerTextDraw(playerid, 535.000000, 187.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, character_creator_ubahasalbtn[playerid], 5);
	PlayerTextDrawLetterSize(playerid, character_creator_ubahasalbtn[playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, character_creator_ubahasalbtn[playerid], 37.500000, 28.000000);
	PlayerTextDrawSetOutline(playerid, character_creator_ubahasalbtn[playerid], 0);
	PlayerTextDrawSetShadow(playerid, character_creator_ubahasalbtn[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_creator_ubahasalbtn[playerid], 1);
	PlayerTextDrawColor(playerid, character_creator_ubahasalbtn[playerid], -16776961);
	PlayerTextDrawBackgroundColor(playerid, character_creator_ubahasalbtn[playerid], -256);
	PlayerTextDrawBoxColor(playerid, character_creator_ubahasalbtn[playerid], 255);
	PlayerTextDrawUseBox(playerid, character_creator_ubahasalbtn[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_creator_ubahasalbtn[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_creator_ubahasalbtn[playerid], 1);
	PlayerTextDrawSetPreviewModel(playerid, character_creator_ubahasalbtn[playerid], 1239);
	PlayerTextDrawSetPreviewRot(playerid, character_creator_ubahasalbtn[playerid], 0.000000, 90.000000, 90.000000, 0.790000);
	PlayerTextDrawSetPreviewVehCol(playerid, character_creator_ubahasalbtn[playerid], 1, 1);

	character_creator_ubahkelamin[playerid] = CreatePlayerTextDraw(playerid, 550.000000, 228.000000, "Ubah");
	PlayerTextDrawFont(playerid, character_creator_ubahkelamin[playerid], 2);
	PlayerTextDrawLetterSize(playerid, character_creator_ubahkelamin[playerid], 0.120833, 0.850000);
	PlayerTextDrawTextSize(playerid, character_creator_ubahkelamin[playerid], 564.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, character_creator_ubahkelamin[playerid], 0);
	PlayerTextDrawSetShadow(playerid, character_creator_ubahkelamin[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_creator_ubahkelamin[playerid], 1);
	PlayerTextDrawColor(playerid, character_creator_ubahkelamin[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_creator_ubahkelamin[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_creator_ubahkelamin[playerid], 50);
	PlayerTextDrawUseBox(playerid, character_creator_ubahkelamin[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_creator_ubahkelamin[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_creator_ubahkelamin[playerid], 0);

	character_creator_ubahnamabtn[playerid] = CreatePlayerTextDraw(playerid, 535.000000, 158.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, character_creator_ubahnamabtn[playerid], 5);
	PlayerTextDrawLetterSize(playerid, character_creator_ubahnamabtn[playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, character_creator_ubahnamabtn[playerid], 37.500000, 28.000000);
	PlayerTextDrawSetOutline(playerid, character_creator_ubahnamabtn[playerid], 0);
	PlayerTextDrawSetShadow(playerid, character_creator_ubahnamabtn[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_creator_ubahnamabtn[playerid], 1);
	PlayerTextDrawColor(playerid, character_creator_ubahnamabtn[playerid], -16776961);
	PlayerTextDrawBackgroundColor(playerid, character_creator_ubahnamabtn[playerid], -256);
	PlayerTextDrawBoxColor(playerid, character_creator_ubahnamabtn[playerid], 255);
	PlayerTextDrawUseBox(playerid, character_creator_ubahnamabtn[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_creator_ubahnamabtn[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_creator_ubahnamabtn[playerid], 1);
	PlayerTextDrawSetPreviewModel(playerid, character_creator_ubahnamabtn[playerid], 1239);
	PlayerTextDrawSetPreviewRot(playerid, character_creator_ubahnamabtn[playerid], 0.000000, 90.000000, 90.000000, 0.790000);
	PlayerTextDrawSetPreviewVehCol(playerid, character_creator_ubahnamabtn[playerid], 1, 1);

	character_creator_ubahasal[playerid] = CreatePlayerTextDraw(playerid, 550.000000, 196.000000, "Ubah");
	PlayerTextDrawFont(playerid, character_creator_ubahasal[playerid], 2);
	PlayerTextDrawLetterSize(playerid, character_creator_ubahasal[playerid], 0.120833, 0.850000);
	PlayerTextDrawTextSize(playerid, character_creator_ubahasal[playerid], 564.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, character_creator_ubahasal[playerid], 0);
	PlayerTextDrawSetShadow(playerid, character_creator_ubahasal[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_creator_ubahasal[playerid], 1);
	PlayerTextDrawColor(playerid, character_creator_ubahasal[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_creator_ubahasal[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_creator_ubahasal[playerid], 50);
	PlayerTextDrawUseBox(playerid, character_creator_ubahasal[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_creator_ubahasal[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_creator_ubahasal[playerid], 0);

	character_creator_ubahnama[playerid] = CreatePlayerTextDraw(playerid, 550.000000, 167.000000, "Ubah");
	PlayerTextDrawFont(playerid, character_creator_ubahnama[playerid], 2);
	PlayerTextDrawLetterSize(playerid, character_creator_ubahnama[playerid], 0.120833, 0.850000);
	PlayerTextDrawTextSize(playerid, character_creator_ubahnama[playerid], 564.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, character_creator_ubahnama[playerid], 0);
	PlayerTextDrawSetShadow(playerid, character_creator_ubahnama[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_creator_ubahnama[playerid], 1);
	PlayerTextDrawColor(playerid, character_creator_ubahnama[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_creator_ubahnama[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_creator_ubahnama[playerid], 50);
	PlayerTextDrawUseBox(playerid, character_creator_ubahnama[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_creator_ubahnama[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_creator_ubahnama[playerid], 0);

	character_creator_ubahlahir[playerid] = CreatePlayerTextDraw(playerid, 550.000000, 256.000000, "Ubah");
	PlayerTextDrawFont(playerid, character_creator_ubahlahir[playerid], 2);
	PlayerTextDrawLetterSize(playerid, character_creator_ubahlahir[playerid], 0.120833, 0.850000);
	PlayerTextDrawTextSize(playerid, character_creator_ubahlahir[playerid], 564.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, character_creator_ubahlahir[playerid], 0);
	PlayerTextDrawSetShadow(playerid, character_creator_ubahlahir[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_creator_ubahlahir[playerid], 1);
	PlayerTextDrawColor(playerid, character_creator_ubahlahir[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_creator_ubahlahir[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_creator_ubahlahir[playerid], 50);
	PlayerTextDrawUseBox(playerid, character_creator_ubahlahir[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_creator_ubahlahir[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_creator_ubahlahir[playerid], 0);

	character_creator_konfirmasibtn[playerid] = CreatePlayerTextDraw(playerid, 429.000000, 312.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, character_creator_konfirmasibtn[playerid], 5);
	PlayerTextDrawLetterSize(playerid, character_creator_konfirmasibtn[playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, character_creator_konfirmasibtn[playerid], 52.000000, 26.000000);
	PlayerTextDrawSetOutline(playerid, character_creator_konfirmasibtn[playerid], 0);
	PlayerTextDrawSetShadow(playerid, character_creator_konfirmasibtn[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_creator_konfirmasibtn[playerid], 1);
	PlayerTextDrawColor(playerid, character_creator_konfirmasibtn[playerid], -16776961);
	PlayerTextDrawBackgroundColor(playerid, character_creator_konfirmasibtn[playerid], -256);
	PlayerTextDrawBoxColor(playerid, character_creator_konfirmasibtn[playerid], 255);
	PlayerTextDrawUseBox(playerid, character_creator_konfirmasibtn[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_creator_konfirmasibtn[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_creator_konfirmasibtn[playerid], 1);
	PlayerTextDrawSetPreviewModel(playerid, character_creator_konfirmasibtn[playerid], 19454);
	PlayerTextDrawSetPreviewRot(playerid, character_creator_konfirmasibtn[playerid], 0.000000, 0.000000, 60.000000, 0.349999);
	PlayerTextDrawSetPreviewVehCol(playerid, character_creator_konfirmasibtn[playerid], 1, 1);

	character_creator_konfirmasi[playerid] = CreatePlayerTextDraw(playerid, 455.000000, 318.000000, "Konfirmasi");
	PlayerTextDrawFont(playerid, character_creator_konfirmasi[playerid], 2);
	PlayerTextDrawLetterSize(playerid, character_creator_konfirmasi[playerid], 0.166666, 1.049999);
	PlayerTextDrawTextSize(playerid, character_creator_konfirmasi[playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, character_creator_konfirmasi[playerid], 0);
	PlayerTextDrawSetShadow(playerid, character_creator_konfirmasi[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_creator_konfirmasi[playerid], 2);
	PlayerTextDrawColor(playerid, character_creator_konfirmasi[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_creator_konfirmasi[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_creator_konfirmasi[playerid], 50);
	PlayerTextDrawUseBox(playerid, character_creator_konfirmasi[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_creator_konfirmasi[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_creator_konfirmasi[playerid], 0);

	character_creator_batalkan[playerid] = CreatePlayerTextDraw(playerid, 536.000000, 318.000000, "Membatalkan");
	PlayerTextDrawFont(playerid, character_creator_batalkan[playerid], 2);
	PlayerTextDrawLetterSize(playerid, character_creator_batalkan[playerid], 0.166666, 1.049999);
	PlayerTextDrawTextSize(playerid, character_creator_batalkan[playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, character_creator_batalkan[playerid], 0);
	PlayerTextDrawSetShadow(playerid, character_creator_batalkan[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_creator_batalkan[playerid], 2);
	PlayerTextDrawColor(playerid, character_creator_batalkan[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_creator_batalkan[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_creator_batalkan[playerid], 50);
	PlayerTextDrawUseBox(playerid, character_creator_batalkan[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_creator_batalkan[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_creator_batalkan[playerid], 0);

	character_creator_dot[playerid] = CreatePlayerTextDraw(playerid, 490.000000, 315.000000, "ld_beat:chit");
	PlayerTextDrawFont(playerid, character_creator_dot[playerid], 4);
	PlayerTextDrawLetterSize(playerid, character_creator_dot[playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, character_creator_dot[playerid], 10.000000, 10.000000);
	PlayerTextDrawSetOutline(playerid, character_creator_dot[playerid], 1);
	PlayerTextDrawSetShadow(playerid, character_creator_dot[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_creator_dot[playerid], 1);
	PlayerTextDrawColor(playerid, character_creator_dot[playerid], -16776961);
	PlayerTextDrawBackgroundColor(playerid, character_creator_dot[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_creator_dot[playerid], 50);
	PlayerTextDrawUseBox(playerid, character_creator_dot[playerid], 1);
	PlayerTextDrawSetProportional(playerid, character_creator_dot[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_creator_dot[playerid], 0);

	character_creator_baju[playerid] = CreatePlayerTextDraw(playerid, 496.000000, 287.000000, "Baju");
	PlayerTextDrawFont(playerid, character_creator_baju[playerid], 3);
	PlayerTextDrawLetterSize(playerid, character_creator_baju[playerid], 0.429166, 1.400000);
	PlayerTextDrawTextSize(playerid, character_creator_baju[playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, character_creator_baju[playerid], 1);
	PlayerTextDrawSetShadow(playerid, character_creator_baju[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_creator_baju[playerid], 2);
	PlayerTextDrawColor(playerid, character_creator_baju[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_creator_baju[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_creator_baju[playerid], 50);
	PlayerTextDrawUseBox(playerid, character_creator_baju[playerid], 0);
	PlayerTextDrawSetProportional(playerid, character_creator_baju[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_creator_baju[playerid], 0);

	character_creator_bajuleft[playerid] = CreatePlayerTextDraw(playerid, 450.000000, 284.000000, "ld_beat:left");
	PlayerTextDrawFont(playerid, character_creator_bajuleft[playerid], 4);
	PlayerTextDrawLetterSize(playerid, character_creator_bajuleft[playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, character_creator_bajuleft[playerid], 19.500000, 19.500000);
	PlayerTextDrawSetOutline(playerid, character_creator_bajuleft[playerid], 1);
	PlayerTextDrawSetShadow(playerid, character_creator_bajuleft[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_creator_bajuleft[playerid], 1);
	PlayerTextDrawColor(playerid, character_creator_bajuleft[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_creator_bajuleft[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_creator_bajuleft[playerid], 50);
	PlayerTextDrawUseBox(playerid, character_creator_bajuleft[playerid], 1);
	PlayerTextDrawSetProportional(playerid, character_creator_bajuleft[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_creator_bajuleft[playerid], 1);

	character_creator_bajuright[playerid] = CreatePlayerTextDraw(playerid, 522.000000, 284.000000, "ld_beat:right");
	PlayerTextDrawFont(playerid, character_creator_bajuright[playerid], 4);
	PlayerTextDrawLetterSize(playerid, character_creator_bajuright[playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, character_creator_bajuright[playerid], 19.500000, 19.500000);
	PlayerTextDrawSetOutline(playerid, character_creator_bajuright[playerid], 1);
	PlayerTextDrawSetShadow(playerid, character_creator_bajuright[playerid], 0);
	PlayerTextDrawAlignment(playerid, character_creator_bajuright[playerid], 1);
	PlayerTextDrawColor(playerid, character_creator_bajuright[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, character_creator_bajuright[playerid], 255);
	PlayerTextDrawBoxColor(playerid, character_creator_bajuright[playerid], 50);
	PlayerTextDrawUseBox(playerid, character_creator_bajuright[playerid], 1);
	PlayerTextDrawSetProportional(playerid, character_creator_bajuright[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, character_creator_bajuright[playerid], 1);
    return 1;
}

stock DestroyPlayerCharacterCreateTD(playerid) 
{
    PlayerTextDrawDestroy(playerid, character_creator_box[playerid]);
	PlayerTextDrawDestroy(playerid, character_creator_header1[playerid]);
	PlayerTextDrawDestroy(playerid, character_creator_header2[playerid]);
	PlayerTextDrawDestroy(playerid, character_creator_infobox[playerid]);
	PlayerTextDrawDestroy(playerid, character_creator_name[playerid]);
	PlayerTextDrawDestroy(playerid, character_creator_asal[playerid]);
	PlayerTextDrawDestroy(playerid, character_creator_kelamin[playerid]);
	PlayerTextDrawDestroy(playerid, character_creator_lahir[playerid]);
	PlayerTextDrawDestroy(playerid, character_creator_ubahlahirbtn[playerid]);
	PlayerTextDrawDestroy(playerid, character_creator_ubahklmnbtn[playerid]);
	PlayerTextDrawDestroy(playerid, character_creator_batalkanbtn[playerid]);
	PlayerTextDrawDestroy(playerid, character_creator_ubahasalbtn[playerid]);
	PlayerTextDrawDestroy(playerid, character_creator_ubahkelamin[playerid]);
	PlayerTextDrawDestroy(playerid, character_creator_ubahnamabtn[playerid]);
	PlayerTextDrawDestroy(playerid, character_creator_ubahasal[playerid]);
	PlayerTextDrawDestroy(playerid, character_creator_ubahnama[playerid]);
	PlayerTextDrawDestroy(playerid, character_creator_ubahlahir[playerid]);
	PlayerTextDrawDestroy(playerid, character_creator_konfirmasibtn[playerid]);
	PlayerTextDrawDestroy(playerid, character_creator_konfirmasi[playerid]);
	PlayerTextDrawDestroy(playerid, character_creator_batalkan[playerid]);
	PlayerTextDrawDestroy(playerid, character_creator_dot[playerid]);
	PlayerTextDrawDestroy(playerid, character_creator_baju[playerid]);
	PlayerTextDrawDestroy(playerid, character_creator_bajuleft[playerid]);
	PlayerTextDrawDestroy(playerid, character_creator_bajuright[playerid]);
    return 1;
}

stock HidePlayerCharacterCreateTD(playerid)
{
    PlayerTextDrawHide(playerid, character_creator_box[playerid]);
	PlayerTextDrawHide(playerid, character_creator_header1[playerid]);
	PlayerTextDrawHide(playerid, character_creator_header2[playerid]);
	PlayerTextDrawHide(playerid, character_creator_infobox[playerid]);
	PlayerTextDrawHide(playerid, character_creator_name[playerid]);
	PlayerTextDrawHide(playerid, character_creator_asal[playerid]);
	PlayerTextDrawHide(playerid, character_creator_kelamin[playerid]);
	PlayerTextDrawHide(playerid, character_creator_lahir[playerid]);
	PlayerTextDrawHide(playerid, character_creator_ubahlahirbtn[playerid]);
	PlayerTextDrawHide(playerid, character_creator_ubahklmnbtn[playerid]);
	PlayerTextDrawHide(playerid, character_creator_batalkanbtn[playerid]);
	PlayerTextDrawHide(playerid, character_creator_ubahasalbtn[playerid]);
	PlayerTextDrawHide(playerid, character_creator_ubahkelamin[playerid]);
	PlayerTextDrawHide(playerid, character_creator_ubahnamabtn[playerid]);
	PlayerTextDrawHide(playerid, character_creator_ubahasal[playerid]);
	PlayerTextDrawHide(playerid, character_creator_ubahnama[playerid]);
	PlayerTextDrawHide(playerid, character_creator_ubahlahir[playerid]);
	PlayerTextDrawHide(playerid, character_creator_konfirmasibtn[playerid]);
	PlayerTextDrawHide(playerid, character_creator_konfirmasi[playerid]);
	PlayerTextDrawHide(playerid, character_creator_batalkan[playerid]);
	PlayerTextDrawHide(playerid, character_creator_dot[playerid]);
	PlayerTextDrawHide(playerid, character_creator_baju[playerid]);
	PlayerTextDrawHide(playerid, character_creator_bajuleft[playerid]);
	PlayerTextDrawHide(playerid, character_creator_bajuright[playerid]);

	CancelSelectTextDraw(playerid);
    return 1;
}

stock ShowPlayerCreateCharacterTD(playerid, const name[], const origin[], const birthdate[], gender)
{
    PlayerTextDrawSetString(playerid, character_creator_name[playerid], name);
    PlayerTextDrawSetString(playerid, character_creator_lahir[playerid], "Tanggal Lahir: ~n~~g~~h~%s", birthdate);
    PlayerTextDrawSetString(playerid, character_creator_asal[playerid], "Asal : ~n~~y~%s", origin);

    if(gender == GENDER_MALE)
    {
        PlayerTextDrawSetString(playerid, character_creator_kelamin[playerid], "Kelamin : ~n~~b~~h~Laki-Laki");
    }
    else if(gender == GENDER_FEMALE)
    {
        PlayerTextDrawSetString(playerid, character_creator_kelamin[playerid], "Kelamin : ~n~~p~~h~Perempuan");
    }
    
    PlayerTextDrawShow(playerid, character_creator_box[playerid]);
	PlayerTextDrawShow(playerid, character_creator_header1[playerid]);
	PlayerTextDrawShow(playerid, character_creator_header2[playerid]);
	PlayerTextDrawShow(playerid, character_creator_infobox[playerid]);
	PlayerTextDrawShow(playerid, character_creator_name[playerid]);
	PlayerTextDrawShow(playerid, character_creator_asal[playerid]);
	PlayerTextDrawShow(playerid, character_creator_kelamin[playerid]);
	PlayerTextDrawShow(playerid, character_creator_lahir[playerid]);
	PlayerTextDrawShow(playerid, character_creator_ubahlahirbtn[playerid]);
	PlayerTextDrawShow(playerid, character_creator_ubahklmnbtn[playerid]);
	PlayerTextDrawShow(playerid, character_creator_batalkanbtn[playerid]);
	PlayerTextDrawShow(playerid, character_creator_ubahasalbtn[playerid]);
	PlayerTextDrawShow(playerid, character_creator_ubahkelamin[playerid]);
	PlayerTextDrawShow(playerid, character_creator_ubahnamabtn[playerid]);
	PlayerTextDrawShow(playerid, character_creator_ubahasal[playerid]);
	PlayerTextDrawShow(playerid, character_creator_ubahnama[playerid]);
	PlayerTextDrawShow(playerid, character_creator_ubahlahir[playerid]);
	PlayerTextDrawShow(playerid, character_creator_konfirmasibtn[playerid]);
	PlayerTextDrawShow(playerid, character_creator_konfirmasi[playerid]);
	PlayerTextDrawShow(playerid, character_creator_batalkan[playerid]);
	PlayerTextDrawShow(playerid, character_creator_dot[playerid]);
	PlayerTextDrawShow(playerid, character_creator_baju[playerid]);
	PlayerTextDrawShow(playerid, character_creator_bajuleft[playerid]);
	PlayerTextDrawShow(playerid, character_creator_bajuright[playerid]);

    SelectTextDraw(playerid);
    return 1;
}