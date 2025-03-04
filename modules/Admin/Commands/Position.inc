#include <YSI_Coding\y_hooks>

GetXYLeftOfPoint(Float:x, Float:y, &Float:x2, &Float:y2, Float:A, Float:distance)
{
	x2 = x - (distance * floatsin(-A-90.0, degrees));
	y2 = y - (distance * floatcos(-A-90.0, degrees));
}
GetXYRightOfPoint(Float:x, Float:y, &Float:x2, &Float:y2, Float:A, Float:distance)
{
	x2 = x - (distance * floatsin(-A+90.0, degrees));
	y2 = y - (distance * floatcos(-A+90.0, degrees));
}
GetXYInFrontOfPoint(Float:x, Float:y, &Float:x2, &Float:y2, Float:A, Float:distance)
{
	x2 = x + (distance * floatsin(-A, degrees));
	y2 = y + (distance * floatcos(-A, degrees));
}
GetXYBehindPoint(Float:x, Float:y, &Float:x2, &Float:y2, Float:A, Float:distance)
{
	x2 = x - (distance * floatsin(-A, degrees));
	y2 = y - (distance * floatcos(-A, degrees));
}

YCMD:lt(playerid, params[], help)
{
    if(!IsPlayerAdmin(playerid, Volunteer))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");
        
    new Float:cDistance = 2.0;
    if(!IsNull(params))
    {
        cDistance = floatstr(params);
    }
    new Float:cPos[4];
    GetPlayerPos(playerid, cPos[0], cPos[1], cPos[2]);
    GetPlayerFacingAngle(playerid, cPos[3]);
    GetXYLeftOfPoint(cPos[0], cPos[1], cPos[0], cPos[1], cPos[3], cDistance);
    SetPlayerPos(playerid, cPos[0], cPos[1], cPos[2]);
	return 1;
}

YCMD:rt(playerid, params[], help)
{
    if(!IsPlayerAdmin(playerid, Volunteer))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");

    new Float:cDistance = 2.0;
    if(!IsNull(params))
    {
        cDistance = floatstr(params);
    }
    new Float:cPos[4];
    GetPlayerPos(playerid, cPos[0], cPos[1], cPos[2]);
    GetPlayerFacingAngle(playerid, cPos[3]);
    GetXYRightOfPoint(cPos[0], cPos[1], cPos[0], cPos[1], cPos[3], cDistance);
    SetPlayerPos(playerid, cPos[0], cPos[1], cPos[2]);
	return 1;
}

YCMD:ft(playerid, params[], help)
{
    if(!IsPlayerAdmin(playerid, Volunteer))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");

    new Float:cDistance = 2.0;
    if(!IsNull(params))
    {
        cDistance = floatstr(params);
    }
    new Float:cPos[4];
    GetPlayerPos(playerid, cPos[0], cPos[1], cPos[2]);
    GetPlayerFacingAngle(playerid, cPos[3]);
    GetXYInFrontOfPoint(cPos[0], cPos[1], cPos[0], cPos[1], cPos[3], cDistance);
    SetPlayerPos(playerid, cPos[0], cPos[1], cPos[2]);
	return 1;
}

YCMD:bt(playerid, params[], help)
{
    if(!IsPlayerAdmin(playerid, Volunteer))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");

    new Float:cDistance = 2.0;
    if(!IsNull(params))
    {
        cDistance = floatstr(params);
    }
    new Float:cPos[4];
    GetPlayerPos(playerid, cPos[0], cPos[1], cPos[2]);
    GetPlayerFacingAngle(playerid, cPos[3]);
    GetXYBehindPoint(cPos[0], cPos[1], cPos[0], cPos[1], cPos[3], cDistance);
    SetPlayerPos(playerid, cPos[0], cPos[1], cPos[2]);
	return 1;
}

YCMD:up(playerid, params[], help)
{
    if(!IsPlayerAdmin(playerid, Volunteer))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");

    new Float:cDistance = 2.0;
    if(!IsNull(params))
    {
        cDistance = floatstr(params);
    }
    new Float:cPos[3];
    GetPlayerPos(playerid, cPos[0], cPos[1], cPos[2]);
    SetPlayerPos(playerid, cPos[0], cPos[1], (cPos[2]+cDistance));
	return 1;
}

YCMD:dn(playerid, params[], help)
{
    if(!IsPlayerAdmin(playerid, Volunteer))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");

    new Float:cDistance = 2.0;
    if(!IsNull(params))
    {
        cDistance = floatstr(params);
    }
    new Float:cPos[3];
    GetPlayerPos(playerid, cPos[0], cPos[1], cPos[2]);
    SetPlayerPos(playerid, cPos[0], cPos[1], (cPos[2]-cDistance));
	return 1;
}