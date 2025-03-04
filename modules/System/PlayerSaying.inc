#include <YSI_Coding\y_hooks>

hook OnPlayerText(playerid, text[])
{
    if(!IsPlayerSpawned(playerid)) return 1;

    new Float:x, Float:y, Float:z, Float:dist, Float:radius = 5.0, color;
	GetPlayerPos(playerid, x, y, z);

    foreach(new i : Player) 
    {
        if(IsPlayerSpawned(i) && IsPlayerNearPlayer(playerid, i, radius))
        {
            dist = GetPlayerDistanceFromPoint(i, x, y, z);
            if(dist > radius) continue;

            if(dist <= 1.0) color = 0xFDFCFCFF;
            else if(dist <= 2.0) color = 0xE1E0E0FF;
            else if(dist <= 3.0) color = 0xA1A1A1FF;
            else if(dist <= 4.0) color = 0x707070FF;
            else if(dist <= 5.0) color = 0x4B4B4BFF;
            SendClientMessageEx(i, color, "%s berkata: %s", RemoveUnderscore(playerInfo[playerid][playerName]), text);
        }
    }
    return 0;
}