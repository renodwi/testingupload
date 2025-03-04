stock fixed_Kick(playerid, const reasons[] = "Nothing", {Float, _}:...)
{
    new
		str[145];
	va_format(str, sizeof (str), reasons, va_start<3>);

    SetTimerEx("fixed_timer_Kick", 1000, false, "d", playerid);
    
    if(strcmp(reasons, "Nothing", true))
    {
        SendClientMessageEx(playerid, COLOR_LIGHTRED, "Anda telah dikeluarkan dari server.");
        SendClientMessageEx(playerid, COLOR_LIGHTRED, "Alasan: %s", str);
    }
    return 1;
}

function fixed_timer_Kick(playerid)
{
    Kick(playerid);
    return 1;
}

#if defined _ALS_Kick
	#undef Kick
#else
	#define _ALS_Kick
#endif
#define Kick fixed_Kick