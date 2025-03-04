#include <YSI_Coding\y_hooks>

stock fixed_PlayerTextDrawSetString(playerid, PlayerText:text, const string[], {Float, _}:...)
{
    new
		str[200];
	va_format(str, sizeof (str), command, va_start<3>);
    return PlayerTextDrawSetString(playerid, text, str);
}

#if defined _ALS_PlayerTextDrawSetString
	#undef PlayerTextDrawSetString
#else
	#define _ALS_PlayerTextDrawSetString
#endif
#define PlayerTextDrawSetString fixed_PlayerTextDrawSetString