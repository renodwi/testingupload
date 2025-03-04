#include <YSI_Coding\y_hooks>

stock fixed_SendRconCommand(const command[], {Float, _}:...)
{
    new
		str[200];
	va_format(str, sizeof (str), command, va_start<1>);
    return SendRconCommand(str);
}

#if defined _ALS_SendRconCommand
	#undef SendRconCommand
#else
	#define _ALS_SendRconCommand
#endif
#define SendRconCommand fixed_SendRconCommand