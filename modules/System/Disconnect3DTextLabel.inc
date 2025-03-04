#include <YSI_Coding\y_hooks>

#define MAX_DISCONNECT_LABEL (MAX_PLAYERS + 200)

enum DISCONNECT_LABEL 
{
	disconnect3DLabelName[MAX_PLAYER_NAME + 1],
	Text3D:disconnect3DLabelText,
}
new disconnect3DLabelInfo[MAX_DISCONNECT_LABEL][DISCONNECT_LABEL],
    Iterator: Disconnect3DText<MAX_DISCONNECT_LABEL>;

stock CreateDisconnectLabel(playerid, reason) 
{
	new Float:x, Float:y, Float:z, id;
	GetPlayerPos(playerid, x, y, z);
    id = Iter_Free(Disconnect3DText);

    switch(reason)
	{
		case 0:
		{
			disconnect3DLabelInfo[id][disconnect3DLabelText] = CreateDynamic3DTextLabel(va_return("[ %s telah keluar dari kota. (timeout/crash) ]", RemoveUnderscore(playerInfo[playerid][playerName]), playerid), COLOR_GREY, x, y, z, 5.0);
		}
		case 1:
		{
			disconnect3DLabelInfo[id][disconnect3DLabelText] = CreateDynamic3DTextLabel(va_return("[ %s telah keluar dari kota. (leaving) ]", RemoveUnderscore(playerInfo[playerid][playerName]), playerid), COLOR_GREY, x, y, z, 5.0);
		}
		case 2:
		{
			disconnect3DLabelInfo[id][disconnect3DLabelText] = CreateDynamic3DTextLabel(va_return("[ %s telah keluar dari kota. (kicked/banned) ]", RemoveUnderscore(playerInfo[playerid][playerName]), playerid), COLOR_GREY, x, y, z, 5.0);
		}
	}
	defer DestroyDisconnectLabel(id);
    Iter_Add(Disconnect3DText, id);
    return 1;
}

timer DestroyDisconnectLabel[1800](id) 
{
    if(!Iter_Contains(Disconnect3DText, id)) return 1;
    
    DestroyDynamic3DTextLabel(disconnect3DLabelInfo[id][disconnect3DLabelText]);
    Iter_Remove(Disconnect3DText, id);
    return 1;
}

hook OnCharacterSpawn(playerid) 
{
	foreach(new i : Disconnect3DText) 
	{
		if(Iter_Contains(Disconnect3DText, i) && !strcmp(playerInfo[playerid][playerName], disconnect3DLabelInfo[i][disconnect3DLabelName])) 
		{
			// DestroyDisconnectLabel(i);
		}
	}
	return 1;
}

hook OnPlayerDisconnect(playerid, reason) 
{
	CreateDisconnectLabel(playerid, reason);
	return 1;
}