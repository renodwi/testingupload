stock IsPlayerJobDuty(playerid) 
{
    new value = player_jobduty_type[playerid];
    return value;
}

stock SetPlayerJobDuty(playerid, type, bool:status) 
{
    if(status == true) player_jobduty_type[playerid] = type;
    else player_jobduty_type[playerid] = -1;
    return 1;
}

stock IsPlayerInJob(playerid, type) 
{
    new slot = -1;
    Loop(i, playerInfo[playerid][playerMaxJob])
    {
        if(playerjobInfo[playerid][i][playerjobType] == type)
        {
            slot = i;
            break;
        }
    }
    return slot;
}

stock ClearPlayerJob(playerid)
{
    Loop(i, playerInfo[playerid][playerMaxJob])
    {
        ResetPlayerJob(playerid, i);
    }
    return 1;
}

stock ResetPlayerJob(playerid, slot, bool:deletefromdatabase = false) 
{
    if(deletefromdatabase == true) 
    {
        new query[700];
        mysql_format(sql, query, sizeof(query), "DELETE FROM `characters_job` WHERE `id` = '%d'", playerjobInfo[playerid][slot][playerjobDBID]);
        mysql_tquery(sql, query, "OnPlayerExitJob", "d", playerid);
    }
    
    playerjobInfo[playerid][slot][playerjobDBID] = -1;
    playerjobInfo[playerid][slot][playerjobExist] = false;
    playerjobInfo[playerid][slot][playerjobType] = JOB_NONE;
    playerjobInfo[playerid][slot][playerjobDelayUntil] = Timestamp:0;
    return 1;
}

stock AddPlayerJob(playerid, type)
{
    new slot = -1;
    slot = GetPlayerJobFreeSlot(playerid);

    if(slot == -1) return slot;

    playerjobInfo[playerid][slot][playerjobExist] = true;
    playerjobInfo[playerid][slot][playerjobType] = type;
    playerjobInfo[playerid][slot][playerjobDelayUntil] = Now() + Timestamp:86400;

    new query[700];
    mysql_format(sql, query, sizeof(query), "INSERT INTO `characters_job` (`characters_id`, `type`, `delayuntil`) VALUES ('%d', '%d', '%d')", playerInfo[playerid][playerDBID], type, _:playerjobInfo[playerid][slot][playerjobDelayUntil]);
    mysql_tquery(sql, query, "OnPlayerAddJob", "dd", playerid, slot);
    return slot;
}

stock GetPlayerJobFreeSlot(playerid)
{
    new slot = -1;
    Loop(i, playerInfo[playerid][playerMaxJob])
    {
        if(playerjobInfo[playerid][i][playerjobExist] == false) 
        {
            slot = i;
            break;
        }
    }
    return slot;
}

stock LoadPlayerJob(playerid)
{
    ClearPlayerJob(playerid);
    
    new query[500];
    mysql_format(sql, query, sizeof(query), "SELECT * FROM `characters_job` WHERE `characters_id` = '%d'", playerInfo[playerid][playerDBID]);
    mysql_tquery(sql, query, "AssignCharacterJob", "d", playerid);
    return 1;
}

stock IsPlayerInJoinJobPickup(playerid)
{
    new jobid = -1;
    if(IsPlayerInPickup(playerid, PICKUPTYPE_JOINJOB_MECHANIC)) jobid = JOB_MECHANIC;
    return jobid;
}