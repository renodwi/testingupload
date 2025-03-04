new PlayerText:animationtextdraw[MAX_PLAYERS];

stock LoadPlayerAnimationTextDraw(playerid)
{
    animationtextdraw[playerid] = CreatePlayerTextDraw(playerid, 325.000000, 432.000000, "~w~~h~Tekan ~r~~h~~k~~CONVERSATION_NO~ ~w~~h~untuk menghentikan animasi");
	PlayerTextDrawFont(playerid, animationtextdraw[playerid], 1);
	PlayerTextDrawLetterSize(playerid, animationtextdraw[playerid], 0.300000, 1.600000);
	PlayerTextDrawTextSize(playerid, animationtextdraw[playerid], 400.000000, 454.000000);
	PlayerTextDrawSetOutline(playerid, animationtextdraw[playerid], 1);
	PlayerTextDrawSetShadow(playerid, animationtextdraw[playerid], 0);
	PlayerTextDrawAlignment(playerid, animationtextdraw[playerid], 2);
	PlayerTextDrawColor(playerid, animationtextdraw[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, animationtextdraw[playerid], 255);
	PlayerTextDrawBoxColor(playerid, animationtextdraw[playerid], 50);
	PlayerTextDrawUseBox(playerid, animationtextdraw[playerid], 0);
	PlayerTextDrawSetProportional(playerid, animationtextdraw[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, animationtextdraw[playerid], 0);
    return 1;
}

stock DestroyPlayerAnimationTextDraw(playerid)
{
	PlayerTextDrawDestroy(playerid, animationtextdraw[playerid]);
	return 1;
}

stock ShowPlayerAnimationTextDraw(playerid)
{
	PlayerTextDrawShow(playerid, animationtextdraw[playerid]);
	return 1;
}

stock HidePlayerAnimationTextDraw(playerid)
{
	PlayerTextDrawHide(playerid, animationtextdraw[playerid]);
	return 1;
}