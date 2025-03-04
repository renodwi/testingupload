#include <YSI_Coding\y_hooks>

stock fixed_SetPlayerChatBubble(playerid, const text[], colour, Float:distance, expire_time, {Float, _}:...)
{
    new
		str[200];
	va_format(str, sizeof (str), text, va_start<5>);

    SetPlayerChatBubble(playerid, str, colour, distance, expire_time);
    return 1;
}

#if defined _ALS_SetPlayerChatBubble
	#undef SetPlayerChatBubble
#else
	#define _ALS_SetPlayerChatBubble
#endif
#define SetPlayerChatBubble fixed_SetPlayerChatBubble