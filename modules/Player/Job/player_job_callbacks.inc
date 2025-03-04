function OnPlayerAddJob(playerid, slot) 
{
    playerjobInfo[playerid][slot][playerjobDBID] = cache_insert_id();
    return 1;
}

hook OnPlayerConnect(playerid) 
{
    player_jobduty_type[playerid] = -1;
    ClearPlayerJob(playerid);
    return 1;
}

hook OnGameModeInit()
{
    AddAdminCommand(Manager, "/playerjob [action]", "Mengubah data pekerjaan yang dapat di miliki oleh player");
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(IsKeyJustDown(KEY_NO, newkeys, oldkeys))
    {
        if(IsPlayerInJoinJobPickup(playerid) != -1)
        {
            Command_ReProcess(playerid, "/joinjob", false);
            return 1;
        }
    }
    return 1;
}

function AssignCharacterJob(playerid) 
{
    new rows = cache_num_rows();
    if(rows)
    {
		for(new i; i < rows; i++)
		{
			cache_get_value_int(i, "id", playerjobInfo[playerid][i][playerjobDBID]);
			cache_get_value_int(i, "type", playerjobInfo[playerid][i][playerjobType]);
			cache_get_value_int(i, "delayuntil", _:playerjobInfo[playerid][i][playerjobDelayUntil]);
            playerjobInfo[playerid][i][playerjobExist] = true;
		}
	}
    return 1;
}

function OnPlayerExitJob(playerid) 
{
    LoadPlayerJob(playerid);
    return 1;
}