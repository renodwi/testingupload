function OnSweeperMarkCreated(routeid, slot) 
{
    sweepermarkInfo[routeid][slot][sweepermarkDBID] = cache_insert_id();
    return 1;
}

function AssignSweeperMark(routeid) 
{
    new rows  = cache_num_rows();
    if(rows)
    {
		for(new i; i < rows; i++)
		{
            cache_get_value_int(i, "id", sweepermarkInfo[routeid][i][sweepermarkDBID]);
            cache_get_value_float(i, "x", sweepermarkInfo[routeid][i][sweepermarkLocationX]);
            cache_get_value_float(i, "y", sweepermarkInfo[routeid][i][sweepermarkLocationY]);
            cache_get_value_float(i, "z", sweepermarkInfo[routeid][i][sweepermarkLocationZ]);
            sweepermarkInfo[routeid][i][sweepermarkExist] = true;

            #if defined DEBUG_MODE
                printf("[Sweeper Mark] Route ID: %d ID: %d position (x: %f y: %f z: %f)", routeid, sweepermarkInfo[routeid][i][sweepermarkDBID], sweepermarkInfo[routeid][i][sweepermarkLocationX], sweepermarkInfo[routeid][i][sweepermarkLocationY], sweepermarkInfo[routeid][i][sweepermarkLocationZ]);
            #endif
        }
    }
    return 1;
}

hook OnPlayerEnterRaceCP(playerid)
{
    if(player_startsweeperroute_id[playerid] != -1)
    {
        PlayerPlaySound(playerid, 1138, 0.0, 0.0, 10.0);
        new routeid = player_startsweeperroute_id[playerid];
        player_sweepermark_step[playerid] += 1;

        if(sweepermarkInfo[routeid][player_sweepermark_step[playerid]][sweepermarkLocationX] == 0.0 || sweepermarkInfo[routeid][player_sweepermark_step[playerid]][sweepermarkLocationY] == 0.0 || sweepermarkInfo[routeid][player_sweepermark_step[playerid]][sweepermarkLocationZ] == 0.0)
        {
            StopPlayerSweeperJob(playerid, true);
            DisablePlayerRaceCheckpoint(playerid);
        }
        else
        {
            new Float:fromx, Float:fromy, Float:fromz, Float:tox, Float:toy, Float:toz;
            fromx = sweepermarkInfo[routeid][player_sweepermark_step[playerid]][sweepermarkLocationX];
            fromy = sweepermarkInfo[routeid][player_sweepermark_step[playerid]][sweepermarkLocationY];
            fromz = sweepermarkInfo[routeid][player_sweepermark_step[playerid]][sweepermarkLocationZ];
            tox = sweepermarkInfo[routeid][player_sweepermark_step[playerid] + 1][sweepermarkLocationX];
            toy = sweepermarkInfo[routeid][player_sweepermark_step[playerid] + 1][sweepermarkLocationY];
            toz = sweepermarkInfo[routeid][player_sweepermark_step[playerid] + 1][sweepermarkLocationZ];
            if(tox == 0.0 || toy == 0.0 || toz == 0.0) 
            {
                SetPlayerRaceCheckpoint(playerid, CP_TYPE_GROUND_FINISH, fromx, fromy, fromz, tox, toy, toz, 5.0);
            }
            else 
            {
                SetPlayerRaceCheckpoint(playerid, CP_TYPE_GROUND_NORMAL, fromx, fromy, fromz, tox, toy, toz, 5.0);
            }
        }
    }
    return 1;
}