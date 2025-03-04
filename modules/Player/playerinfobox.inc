#include <YSI_Coding\y_hooks>

new PlayerText:informasi_textdraw_box[MAX_PLAYERS];
new PlayerText:informasi_textdraw_headerbox[MAX_PLAYERS];
new PlayerText:informasi_textdraw_headertext[MAX_PLAYERS];
new PlayerText:informasi_textdraw_infocontains[MAX_PLAYERS];
new PlayerText:informasi_textdraw_description[MAX_PLAYERS];
new PlayerText:informasi_textdraw_button1[MAX_PLAYERS];
new PlayerText:informasi_textdraw_button2[MAX_PLAYERS];
new PlayerText:informasi_textdraw_button3[MAX_PLAYERS];

new bool:player_informasi_textdraw_show[MAX_PLAYERS] = false;
new player_informasi_textdraw_type[MAX_PLAYERS] = -1;
new player_informasi_timer[MAX_PLAYERS];

hook OnPlayerConnect(playerid)
{
    player_informasi_textdraw_show[playerid] = false;
    player_informasi_textdraw_type[playerid] = -1;
	player_informasi_timer[playerid] = -1;
    LoadPlayerInfoBoxTextDraw(playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyPlayerInfoBoxTextDraw(playerid);
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if(player_informasi_textdraw_show[playerid])
    {
        if(playertextid == informasi_textdraw_button1[playerid]) CallRemoteFunction("OnInformasiResponse", "ddd", playerid, player_informasi_textdraw_type[playerid], 1);
        else if(playertextid == informasi_textdraw_button2[playerid]) CallRemoteFunction("OnInformasiResponse", "ddd", playerid, player_informasi_textdraw_type[playerid], 0);
        else if(playertextid == informasi_textdraw_button3[playerid]) CallRemoteFunction("OnInformasiResponse", "ddd", playerid, player_informasi_textdraw_type[playerid], 1);
        HidePlayerInfoBoxTextDraw(playerid);
    }
    return 1;
}

function OnInformasiResponse(playerid, infoid, response)
{
    return 1;
}

stock LoadPlayerInfoBoxTextDraw(playerid)
{
    informasi_textdraw_box[playerid] = CreatePlayerTextDraw(playerid, 325.000000, 170.000000, "_");
	PlayerTextDrawFont(playerid, informasi_textdraw_box[playerid], 1);
	PlayerTextDrawLetterSize(playerid, informasi_textdraw_box[playerid], 0.600000, 12.250005);
	PlayerTextDrawTextSize(playerid, informasi_textdraw_box[playerid], 298.500000, 264.500000);
	PlayerTextDrawSetOutline(playerid, informasi_textdraw_box[playerid], 1);
	PlayerTextDrawSetShadow(playerid, informasi_textdraw_box[playerid], 0);
	PlayerTextDrawAlignment(playerid, informasi_textdraw_box[playerid], 2);
	PlayerTextDrawColor(playerid, informasi_textdraw_box[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, informasi_textdraw_box[playerid], 255);
	PlayerTextDrawBoxColor(playerid, informasi_textdraw_box[playerid], 135);
	PlayerTextDrawUseBox(playerid, informasi_textdraw_box[playerid], 1);
	PlayerTextDrawSetProportional(playerid, informasi_textdraw_box[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, informasi_textdraw_box[playerid], 0);

	informasi_textdraw_headerbox[playerid] = CreatePlayerTextDraw(playerid, 325.000000, 170.000000, "_");
	PlayerTextDrawFont(playerid, informasi_textdraw_headerbox[playerid], 1);
	PlayerTextDrawLetterSize(playerid, informasi_textdraw_headerbox[playerid], 0.600000, 1.450001);
	PlayerTextDrawTextSize(playerid, informasi_textdraw_headerbox[playerid], 298.500000, 263.500000);
	PlayerTextDrawSetOutline(playerid, informasi_textdraw_headerbox[playerid], 1);
	PlayerTextDrawSetShadow(playerid, informasi_textdraw_headerbox[playerid], 0);
	PlayerTextDrawAlignment(playerid, informasi_textdraw_headerbox[playerid], 2);
	PlayerTextDrawColor(playerid, informasi_textdraw_headerbox[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, informasi_textdraw_headerbox[playerid], 255);
	PlayerTextDrawBoxColor(playerid, informasi_textdraw_headerbox[playerid], 135);
	PlayerTextDrawUseBox(playerid, informasi_textdraw_headerbox[playerid], 1);
	PlayerTextDrawSetProportional(playerid, informasi_textdraw_headerbox[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, informasi_textdraw_headerbox[playerid], 0);

	informasi_textdraw_headertext[playerid] = CreatePlayerTextDraw(playerid, 325.000000, 170.000000, "Informasi");
	PlayerTextDrawFont(playerid, informasi_textdraw_headertext[playerid], 1);
	PlayerTextDrawLetterSize(playerid, informasi_textdraw_headertext[playerid], 0.320832, 1.100000);
	PlayerTextDrawTextSize(playerid, informasi_textdraw_headertext[playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, informasi_textdraw_headertext[playerid], 0);
	PlayerTextDrawSetShadow(playerid, informasi_textdraw_headertext[playerid], 0);
	PlayerTextDrawAlignment(playerid, informasi_textdraw_headertext[playerid], 2);
	PlayerTextDrawColor(playerid, informasi_textdraw_headertext[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, informasi_textdraw_headertext[playerid], 255);
	PlayerTextDrawBoxColor(playerid, informasi_textdraw_headertext[playerid], 50);
	PlayerTextDrawUseBox(playerid, informasi_textdraw_headertext[playerid], 1);
	PlayerTextDrawSetProportional(playerid, informasi_textdraw_headertext[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, informasi_textdraw_headertext[playerid], 0);

	informasi_textdraw_infocontains[playerid] = CreatePlayerTextDraw(playerid, 325.000000, 192.000000, "~p~~h~SERVER INITIALIZING...");
	PlayerTextDrawFont(playerid, informasi_textdraw_infocontains[playerid], 3);
	PlayerTextDrawLetterSize(playerid, informasi_textdraw_infocontains[playerid], 0.704164, 2.449999);
	PlayerTextDrawTextSize(playerid, informasi_textdraw_infocontains[playerid], 400.000000, 252.000000);
	PlayerTextDrawSetOutline(playerid, informasi_textdraw_infocontains[playerid], 1);
	PlayerTextDrawSetShadow(playerid, informasi_textdraw_infocontains[playerid], 0);
	PlayerTextDrawAlignment(playerid, informasi_textdraw_infocontains[playerid], 2);
	PlayerTextDrawColor(playerid, informasi_textdraw_infocontains[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, informasi_textdraw_infocontains[playerid], 255);
	PlayerTextDrawBoxColor(playerid, informasi_textdraw_infocontains[playerid], 50);
	PlayerTextDrawUseBox(playerid, informasi_textdraw_infocontains[playerid], 0);
	PlayerTextDrawSetProportional(playerid, informasi_textdraw_infocontains[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, informasi_textdraw_infocontains[playerid], 0);

	informasi_textdraw_description[playerid] = CreatePlayerTextDraw(playerid, 325.000000, 216.000000, "Lorem Ipsum Dolor Sit Amer");
	PlayerTextDrawFont(playerid, informasi_textdraw_description[playerid], 2);
	PlayerTextDrawLetterSize(playerid, informasi_textdraw_description[playerid], 0.216664, 1.250000);
	PlayerTextDrawTextSize(playerid, informasi_textdraw_description[playerid], 400.000000, 257.000000);
	PlayerTextDrawSetOutline(playerid, informasi_textdraw_description[playerid], 1);
	PlayerTextDrawSetShadow(playerid, informasi_textdraw_description[playerid], 0);
	PlayerTextDrawAlignment(playerid, informasi_textdraw_description[playerid], 2);
	PlayerTextDrawColor(playerid, informasi_textdraw_description[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, informasi_textdraw_description[playerid], 255);
	PlayerTextDrawBoxColor(playerid, informasi_textdraw_description[playerid], 50);
	PlayerTextDrawUseBox(playerid, informasi_textdraw_description[playerid], 0);
	PlayerTextDrawSetProportional(playerid, informasi_textdraw_description[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, informasi_textdraw_description[playerid], 0);

	informasi_textdraw_button1[playerid] = CreatePlayerTextDraw(playerid, 265.000000, 263.000000, "Button1");
	PlayerTextDrawFont(playerid, informasi_textdraw_button1[playerid], 1);
	PlayerTextDrawLetterSize(playerid, informasi_textdraw_button1[playerid], 0.450000, 1.500000);
	PlayerTextDrawTextSize(playerid, informasi_textdraw_button1[playerid], 10.000000, 98.500000);
	PlayerTextDrawSetOutline(playerid, informasi_textdraw_button1[playerid], 1);
	PlayerTextDrawSetShadow(playerid, informasi_textdraw_button1[playerid], 0);
	PlayerTextDrawAlignment(playerid, informasi_textdraw_button1[playerid], 2);
	PlayerTextDrawColor(playerid, informasi_textdraw_button1[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, informasi_textdraw_button1[playerid], 255);
	PlayerTextDrawBoxColor(playerid, informasi_textdraw_button1[playerid], -206);
	PlayerTextDrawUseBox(playerid, informasi_textdraw_button1[playerid], 1);
	PlayerTextDrawSetProportional(playerid, informasi_textdraw_button1[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, informasi_textdraw_button1[playerid], 1);

	informasi_textdraw_button2[playerid] = CreatePlayerTextDraw(playerid, 388.000000, 263.000000, "Button2");
	PlayerTextDrawFont(playerid, informasi_textdraw_button2[playerid], 1);
	PlayerTextDrawLetterSize(playerid, informasi_textdraw_button2[playerid], 0.450000, 1.500000);
	PlayerTextDrawTextSize(playerid, informasi_textdraw_button2[playerid], 10.000000, 98.500000);
	PlayerTextDrawSetOutline(playerid, informasi_textdraw_button2[playerid], 1);
	PlayerTextDrawSetShadow(playerid, informasi_textdraw_button2[playerid], 0);
	PlayerTextDrawAlignment(playerid, informasi_textdraw_button2[playerid], 2);
	PlayerTextDrawColor(playerid, informasi_textdraw_button2[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, informasi_textdraw_button2[playerid], 255);
	PlayerTextDrawBoxColor(playerid, informasi_textdraw_button2[playerid], -206);
	PlayerTextDrawUseBox(playerid, informasi_textdraw_button2[playerid], 1);
	PlayerTextDrawSetProportional(playerid, informasi_textdraw_button2[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, informasi_textdraw_button2[playerid], 1);

	informasi_textdraw_button3[playerid] = CreatePlayerTextDraw(playerid, 325.000000, 263.000000, "Button3");
	PlayerTextDrawFont(playerid, informasi_textdraw_button3[playerid], 1);
	PlayerTextDrawLetterSize(playerid, informasi_textdraw_button3[playerid], 0.450000, 1.500000);
	PlayerTextDrawTextSize(playerid, informasi_textdraw_button3[playerid], 10.000000, 98.500000);
	PlayerTextDrawSetOutline(playerid, informasi_textdraw_button3[playerid], 1);
	PlayerTextDrawSetShadow(playerid, informasi_textdraw_button3[playerid], 0);
	PlayerTextDrawAlignment(playerid, informasi_textdraw_button3[playerid], 2);
	PlayerTextDrawColor(playerid, informasi_textdraw_button3[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, informasi_textdraw_button3[playerid], 255);
	PlayerTextDrawBoxColor(playerid, informasi_textdraw_button3[playerid], -206);
	PlayerTextDrawUseBox(playerid, informasi_textdraw_button3[playerid], 1);
	PlayerTextDrawSetProportional(playerid, informasi_textdraw_button3[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, informasi_textdraw_button3[playerid], 1);
    return 1;
}

stock DestroyPlayerInfoBoxTextDraw(playerid)
{
    PlayerTextDrawDestroy(playerid, informasi_textdraw_box[playerid]);
	PlayerTextDrawDestroy(playerid, informasi_textdraw_headerbox[playerid]);
	PlayerTextDrawDestroy(playerid, informasi_textdraw_headertext[playerid]);
	PlayerTextDrawDestroy(playerid, informasi_textdraw_infocontains[playerid]);
	PlayerTextDrawDestroy(playerid, informasi_textdraw_description[playerid]);
	PlayerTextDrawDestroy(playerid, informasi_textdraw_button1[playerid]);
	PlayerTextDrawDestroy(playerid, informasi_textdraw_button2[playerid]);
	PlayerTextDrawDestroy(playerid, informasi_textdraw_button3[playerid]);
    return 1;
}

stock ShowPlayerInfoBoxTextDraw(playerid, INFO_ID, const title[], const content[], const button1[] = "null", const button2[] = "null", {Float, _}:...)
{
    new
		message[200];
	va_format(message, sizeof (message), content, va_start<6>);

    PlayerTextDrawSetString(playerid, informasi_textdraw_infocontains[playerid], title);
    PlayerTextDrawSetString(playerid, informasi_textdraw_description[playerid], message);
    PlayerTextDrawShow(playerid, informasi_textdraw_box[playerid]);
	PlayerTextDrawShow(playerid, informasi_textdraw_headerbox[playerid]);
	PlayerTextDrawShow(playerid, informasi_textdraw_headertext[playerid]);
	PlayerTextDrawShow(playerid, informasi_textdraw_infocontains[playerid]);
	PlayerTextDrawShow(playerid, informasi_textdraw_description[playerid]);

	if(!strcmp(button1, "null", true) && strcmp(button2, "null", true))
    {
        PlayerTextDrawSetString(playerid, informasi_textdraw_button3[playerid], button2);

        PlayerTextDrawHide(playerid, informasi_textdraw_button1[playerid]);
        PlayerTextDrawHide(playerid, informasi_textdraw_button2[playerid]);
        PlayerTextDrawShow(playerid, informasi_textdraw_button3[playerid]);
    }
    else if(!strcmp(button2, "null", true) && strcmp(button1, "null", true))
    {
        PlayerTextDrawSetString(playerid, informasi_textdraw_button3[playerid], button1);

        PlayerTextDrawHide(playerid, informasi_textdraw_button1[playerid]);
        PlayerTextDrawHide(playerid, informasi_textdraw_button2[playerid]);
        PlayerTextDrawShow(playerid, informasi_textdraw_button3[playerid]);
    }
    else if(!strcmp(button1, "null", true) && !strcmp(button2, "null", true))
    {
        PlayerTextDrawSetString(playerid, informasi_textdraw_button1[playerid], " ");
        PlayerTextDrawSetString(playerid, informasi_textdraw_button2[playerid], " ");
        PlayerTextDrawSetString(playerid, informasi_textdraw_button3[playerid], " ");

        PlayerTextDrawHide(playerid, informasi_textdraw_button1[playerid]);
        PlayerTextDrawHide(playerid, informasi_textdraw_button2[playerid]);
        PlayerTextDrawHide(playerid, informasi_textdraw_button3[playerid]);

        player_informasi_timer[playerid] = SetTimerEx("InfoTD_HideInfoWithoutButton", 3000, false, "d", playerid);
    }
    else 
    {
        PlayerTextDrawSetString(playerid, informasi_textdraw_button1[playerid], button1);
        PlayerTextDrawSetString(playerid, informasi_textdraw_button2[playerid], button2);

        PlayerTextDrawShow(playerid, informasi_textdraw_button1[playerid]);
        PlayerTextDrawShow(playerid, informasi_textdraw_button2[playerid]);
        PlayerTextDrawHide(playerid, informasi_textdraw_button3[playerid]);
    }

    SelectTextDraw(playerid);
    player_informasi_textdraw_show[playerid] = true;
	player_informasi_textdraw_type[playerid] = INFO_ID;
    return 1;
}

function InfoTD_HideInfoWithoutButton(playerid)
{
    CallRemoteFunction("OnInformasiResponse", "ddd", playerid, player_informasi_textdraw_type[playerid], 1);
    HidePlayerInfoBoxTextDraw(playerid);
    return 1;
}

stock HidePlayerInfoBoxTextDraw(playerid)
{
    if(player_informasi_textdraw_show[playerid] == false) return 1;

    CancelSelectTextDraw(playerid);
    PlayerTextDrawHide(playerid, informasi_textdraw_box[playerid]);
	PlayerTextDrawHide(playerid, informasi_textdraw_headerbox[playerid]);
	PlayerTextDrawHide(playerid, informasi_textdraw_headertext[playerid]);
	PlayerTextDrawHide(playerid, informasi_textdraw_infocontains[playerid]);
	PlayerTextDrawHide(playerid, informasi_textdraw_description[playerid]);
	PlayerTextDrawHide(playerid, informasi_textdraw_button1[playerid]);
	PlayerTextDrawHide(playerid, informasi_textdraw_button2[playerid]);
	PlayerTextDrawHide(playerid, informasi_textdraw_button3[playerid]);
	player_informasi_textdraw_show[playerid] = false;
	
	if(player_informasi_timer[playerid] != -1) 
	{
		KillTimer(player_informasi_timer[playerid]);
		player_informasi_timer[playerid] = -1;
	}
    return 1;
}