#include <YSI_Coding\y_hooks>

new bool:player_selecttextdraw[MAX_PLAYERS];
hook OnPlayerConnect(playerid)
{
    player_selecttextdraw[playerid] = false;
    return 1;
}

stock n_SelectTextDraw(playerid, color = 0xFFFF00FF)
{
    SelectTextDraw(playerid, color);
    player_selecttextdraw[playerid] = true;
    return 1;
}

#if defined _ALS_SelectTextDraw
	#undef SelectTextDraw
#else
	#define _ALS_SelectTextDraw
#endif
#define SelectTextDraw n_SelectTextDraw

YCMD:cursor(playerid, params[], help)
{
    if(player_selecttextdraw[playerid] == false) return 1;
    else if(player_selecttextdraw[playerid] == true)
    {
        SelectTextDraw(playerid);
    }
    return 1;
}

stock n_CancelSelectTextDraw(playerid)
{
    player_selecttextdraw[playerid] = false;
    CancelSelectTextDraw(playerid);
    return 1;
}

#if defined _ALS_CancelSelectTextDraw
	#undef CancelSelectTextDraw
#else
	#define _ALS_CancelSelectTextDraw
#endif
#define CancelSelectTextDraw n_CancelSelectTextDraw

hook OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    if(clickedid == Text:INVALID_TEXT_DRAW)
    {
        if(player_selecttextdraw[playerid] == true)
        {
            SelectTextDraw(playerid);
        }
    }
    return 1;
}
