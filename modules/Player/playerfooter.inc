#include <YSI_Coding\y_hooks>

new PlayerText:footer_textdraw[MAX_PLAYERS];
new FooterTimer[MAX_PLAYERS];
new bool:IsShowedFooter[MAX_PLAYERS];

hook OnPlayerConnect(playerid)
{
    footer_textdraw[playerid] = CreatePlayerTextDraw(playerid, 322.000000, 350.000000, "Selamat datang kembali ~y~Christ Morant~w~. Anda terakhir login pada ~g~8 Maret 2008");
	PlayerTextDrawFont(playerid, footer_textdraw[playerid], 1);
	PlayerTextDrawLetterSize(playerid, footer_textdraw[playerid], 0.250000, 0.999996);
	PlayerTextDrawTextSize(playerid, footer_textdraw[playerid], 663.500000, 229.500000);
	PlayerTextDrawSetOutline(playerid, footer_textdraw[playerid], 1);
	PlayerTextDrawSetShadow(playerid, footer_textdraw[playerid], 0);
	PlayerTextDrawAlignment(playerid, footer_textdraw[playerid], 2);
	PlayerTextDrawColor(playerid, footer_textdraw[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, footer_textdraw[playerid], 255);
	PlayerTextDrawBoxColor(playerid, footer_textdraw[playerid], 65);
	PlayerTextDrawUseBox(playerid, footer_textdraw[playerid], 0);
	PlayerTextDrawSetProportional(playerid, footer_textdraw[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, footer_textdraw[playerid], 0);
    return 1;
}

stock ShowPlayerFooter(playerid, time, const text[], {Float, _}:...)
{
    if(IsShowedFooter[playerid] == true)
    {
        PlayerTextDrawHide(playerid, footer_textdraw[playerid]);
        KillTimer(FooterTimer[playerid]);
    }
	FooterTimer[playerid] = SetTimerEx("Footer_PlayerFooterTimer", time, false, "d", playerid);

	new str[145];

	va_format(str, sizeof (str), text, va_start<3>);

    PlayerTextDrawSetString(playerid, footer_textdraw[playerid], str);
    PlayerTextDrawShow(playerid, footer_textdraw[playerid]);
    IsShowedFooter[playerid] = true;
    
    return 1;
}

// ----------------------------------------------------
forward Footer_PlayerFooterTimer(playerid);
public Footer_PlayerFooterTimer(playerid)
{
    PlayerTextDrawHide(playerid, footer_textdraw[playerid]);
    KillTimer(FooterTimer[playerid]);
    IsShowedFooter[playerid] = false;
    return 1;
}