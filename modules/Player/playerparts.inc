#include <YSI_Coding\y_hooks>

enum PLAYER_INFO 
{
    playerDBID,
    playerName[MAX_PLAYER_NAME + 1],
    playerOrigin[50],
    playerGender,
    playerSkin,
    playerLevel,
    playerXP,
    playerMoney,
    Timestamp:playerLastSeen,
    Float:playerPositionX,
    Float:playerPositionY,
    Float:playerPositionZ,
    Float:playerPositionA,

    playerInterior,
    playerVirtualWorld,
    Float:playerHealth,
    Float:playerArmour,

    playerInBusiness,

    playerHudMode,

    Float:playerHungry,
    Float:playerThrist,

    playerMaxJob,
}
new playerInfo[MAX_PLAYERS][PLAYER_INFO];

new PlayerText:player_moneyinfo_textdraw[MAX_PLAYERS];
new player_moneyinfo_timer[MAX_PLAYERS];
hook OnPlayerConnect(playerid) 
{
    player_moneyinfo_timer[playerid] = -1;
    player_moneyinfo_textdraw[playerid] = CreatePlayerTextDraw(playerid, 607.000000, 98.000000, "~r~-$20.00");
	PlayerTextDrawFont(playerid, player_moneyinfo_textdraw[playerid], 3);
	PlayerTextDrawLetterSize(playerid, player_moneyinfo_textdraw[playerid], 0.304166, 1.499999);
	PlayerTextDrawTextSize(playerid, player_moneyinfo_textdraw[playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, player_moneyinfo_textdraw[playerid], 1);
	PlayerTextDrawSetShadow(playerid, player_moneyinfo_textdraw[playerid], 0);
	PlayerTextDrawAlignment(playerid, player_moneyinfo_textdraw[playerid], 3);
	PlayerTextDrawColor(playerid, player_moneyinfo_textdraw[playerid], 1097458175);
	PlayerTextDrawBackgroundColor(playerid, player_moneyinfo_textdraw[playerid], 255);
	PlayerTextDrawBoxColor(playerid, player_moneyinfo_textdraw[playerid], 50);
	PlayerTextDrawUseBox(playerid, player_moneyinfo_textdraw[playerid], 0);
	PlayerTextDrawSetProportional(playerid, player_moneyinfo_textdraw[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, player_moneyinfo_textdraw[playerid], 0);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    PlayerTextDrawDestroy(playerid, player_moneyinfo_textdraw[playerid]);
    return 1;
}

// Function
stock n_GivePlayerMoney(playerid, amount, bool:saved = true)
{
    if(player_moneyinfo_timer[playerid] != -1)
    {
        PlayerTextDrawHide(playerid, player_moneyinfo_textdraw[playerid]);
        KillTimer(player_moneyinfo_timer[playerid]);
        player_moneyinfo_timer[playerid] = -1;
    }

    if(saved == true)
    {
        new jumlah = playerInfo[playerid][playerMoney];
        jumlah += amount;
        playerInfo[playerid][playerMoney] = jumlah;
    }
    GivePlayerMoney(playerid, amount);

    new money_info_format[50];
    if(amount < 0)
    {
        format(money_info_format, sizeof(money_info_format), "~r~-$%s", FormatMoney(amount * -1));
    }
    else 
    {
        format(money_info_format, sizeof(money_info_format), "~g~+$%s", FormatMoney(amount));
    }
    PlayerTextDrawSetString(playerid, player_moneyinfo_textdraw[playerid], money_info_format);
    PlayerTextDrawShow(playerid, player_moneyinfo_textdraw[playerid]);

    player_moneyinfo_timer[playerid] = SetTimerEx("HidePlayerMoneyInfoTimer", 1725, false, "d", playerid);
    return amount;
}

function HidePlayerMoneyInfoTimer(playerid) 
{
    PlayerTextDrawHide(playerid, player_moneyinfo_textdraw[playerid]);
    KillTimer(player_moneyinfo_timer[playerid]);

    player_moneyinfo_timer[playerid] = -1;
    return 1;
}

#if defined _ALS_GivePlayerMoney
	#undef GivePlayerMoney
#else
	#define _ALS_GivePlayerMoney
#endif
#define GivePlayerMoney n_GivePlayerMoney

stock n_GetPlayerMoney(playerid)
{
    new money;
    money = playerInfo[playerid][playerMoney];
    return money;
}

#if defined _ALS_GetPlayerMoney
	#undef GetPlayerMoney
#else
	#define _ALS_GetPlayerMoney
#endif
#define GetPlayerMoney n_GetPlayerMoney

stock n_SetPlayerPos(playerid, Float:x, Float:y, Float:z)
{
    TogglePlayerControllable(playerid, false);
    SetTimerEx("timer_SetPlayerPos", 300, false, "dfff", playerid, x, y, z);
    return 1;
}

function timer_SetPlayerPos(playerid, Float:x, Float:y, Float:z)
{
    SetPlayerPos(playerid, x, y, z);
    SetTimerEx("timer_SetPlayerPos_Clear", 300, false, "d", playerid);

    playerInfo[playerid][playerPositionX] = x;
    playerInfo[playerid][playerPositionY] = y;
    playerInfo[playerid][playerPositionZ] = z;
    return 1;
}

function timer_SetPlayerPos_Clear(playerid)
{
    TogglePlayerControllable(playerid, true);
    return 1;
}

#if defined _ALS_SetPlayerPos
	#undef SetPlayerPos
#else
	#define _ALS_SetPlayerPos
#endif
#define SetPlayerPos n_SetPlayerPos

stock n_SetPlayerFacingAngle(playerid, Float:angle)
{
    playerInfo[playerid][playerPositionA] = angle;
    SetPlayerFacingAngle(playerid, angle);
    return 1;
}

#if defined _ALS_SetPlayerFacingAngle
	#undef SetPlayerFacingAngle
#else
	#define _ALS_SetPlayerFacingAngle
#endif
#define SetPlayerFacingAngle n_SetPlayerFacingAngle

stock n_SetPlayerInterior(playerid, interior)
{
    SetPlayerInterior(playerid, interior);
    playerInfo[playerid][playerInterior] = interior;
    return interior;
}

#if defined _ALS_SetPlayerInterior
	#undef SetPlayerInterior
#else
	#define _ALS_SetPlayerInterior
#endif
#define SetPlayerInterior n_SetPlayerInterior

stock n_SetPlayerVirtualWorld(playerid, world)
{
    SetPlayerVirtualWorld(playerid, world);
    playerInfo[playerid][playerVirtualWorld] = world;
    return world;
}

#if defined _ALS_SetPlayerVirtualWorld
	#undef SetPlayerVirtualWorld
#else
	#define _ALS_SetPlayerVirtualWorld
#endif
#define SetPlayerVirtualWorld n_SetPlayerVirtualWorld