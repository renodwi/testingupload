stock MakeSweeperMark(routeid, Float:x, Float:y, Float:z) 
{
    new slot = -1;
    slot = GetFreeSweeperMarkSlot(slot);

    sweepermarkInfo[routeid][slot][sweepermarkExist] = true;
    sweepermarkInfo[routeid][slot][sweepermarkLocationX] = x;
    sweepermarkInfo[routeid][slot][sweepermarkLocationY] = y;
    sweepermarkInfo[routeid][slot][sweepermarkLocationZ] = z;

    new query[1200];
    mysql_format(sql, query, sizeof(query), "INSERT INTO `sweeper_mark` (`routeid`, `x`, `y`, `z`) VALUES ('%d', '%f', '%f', '%f')", routeid, x, y, z);
    mysql_tquery(sql, query, "OnSweeperMarkCreated", "dd", routeid, slot);
    return 1;
}

stock ResetSweeperMark(routeid, bool:delete_in_database = false) 
{
    if(!Iter_Contains(SweeperRoute, routeid)) return 1;

    Loop(i, MAX_SWEEPER_MARK)
    {
        sweepermarkInfo[routeid][i][sweepermarkExist] = false;
        sweepermarkInfo[routeid][i][sweepermarkLocationX] = 0.0;
        sweepermarkInfo[routeid][i][sweepermarkLocationY] = 0.0;
        sweepermarkInfo[routeid][i][sweepermarkLocationZ] = 0.0;
    }

    if(delete_in_database == true) 
    {
        new query[64];
        mysql_format(sql, query, sizeof(query), "DELETE FROM `sweeper_mark` WHERE `routeid` = '%d'", routeid);
        mysql_tquery(sql, query);
    }
    return 1;
}

stock GetFreeSweeperMarkSlot(routeid) 
{
    if(!Iter_Contains(SweeperRoute, routeid)) return 1;

    new slot = -1;
    Loop(i, MAX_SWEEPER_MARK) {
        if(sweepermarkInfo[routeid][i][sweepermarkExist] == false) {
            slot = i;
            break;
        }
    }
    return slot;
}

stock LoadSweeeperMark(routeid) 
{
    ResetSweeperMark(routeid);

    new query[200];
    mysql_format(sql, query, sizeof(query), "SELECT * FROM `sweeper_mark` WHERE `routeid` = '%d'", routeid);
    mysql_tquery(sql, query, "AssignSweeperMark", "d", routeid);
    return 1;
}

stock CreateSweeperMarkByPlayer(playerid)
{
    new Float:x, Float:y, Float:z, slot;
    GetPlayerPos(playerid, x, y, z);
    slot = MakeSweeperMark(player_sweepermark_routeid[playerid], x, y, z);

    SetPlayerRaceCheckpoint(playerid, CP_TYPE_GROUND_FINISH, x, y, z, x, y, z, 5.0);
    return slot;
}

stock SetPlayerEditSweeperMarkMode(playerid, routeid) 
{
    ResetSweeperMark(routeid, true);
    player_sweepermark_routeid[playerid] = routeid;
    player_sweepermark_editmode[playerid] = true;
    
    SendClientMessageEx(playerid, COLOR_REN, "SWEEPER-MARK: "WHITE"Anda memasuki mode edit sweeper mark pada route "YELLOW"%s", sweeperrouteInfo[routeid][sweeperrouteName]);
    SendClientMessageEx(playerid, COLOR_REN, "SWEEPER-MARK: "WHITE"Gunakan command "YELLOW"/sweeper"WHITE" untuk melanjutkan membuat mark pada sweeper route");
    SendClientMessageEx(playerid, COLOR_REN, "SWEEPER-MARK: "WHITE"Gunakan command "YELLOW"/sweeper end"WHITE" untuk menyelesaikannya");
    return 1;
}

stock StopPlayerEditSweeperMarkMode(playerid)
{
    new count = 0;
    Loop(i, MAX_SWEEPER_ROUTE)
    {
        if(sweepermarkInfo[player_sweepermark_routeid[playerid]][i][sweepermarkExist] == true) 
        {
            count++;
        }
    }
    SendClientMessageEx(playerid, COLOR_REN, "SWEEPER-MARK: "WHITE"Anda telah menyelesaikan untuk mengatur sweeper route mark (checkpoint) pada rute sweeper "YELLOW"%s"WHITE", total mark "LG"%d", sweeperrouteInfo[player_sweepermark_routeid[playerid]][sweeperrouteName], count);
    player_sweepermark_routeid[playerid] = -1;
    player_sweepermark_editmode[playerid] = false;
    DisablePlayerRaceCheckpoint(playerid);
    return 1;
}

stock StartPlayerSweeperMark(playerid) 
{
    new routeid = player_startsweeperroute_id[playerid];
    player_sweepermark_step[playerid] = 0;

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
    return 1;
}