#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    Command_SetDeniedReturn(true);
    return 1;
}

hook OnPlayerCommandText(playerid, cmdtext[])
{
	return 1;
}

hook OnPlayerCommandReceived(playerid, cmdtext[], e_COMMAND_ERRORS:success)
{
    if(!IsPlayerSpawned(playerid)) return 1;
    
    if(success != COMMAND_OK)
    {
        SendErrorMessage(playerid, "Command tidak ditemukan, gunakan /help untuk melihatnya");
    }
    return success;
}