stock MakeSweeperRoute(Float:x, Float:y, Float:z, const name[MAX_SWEEPER_ROUTE_NAME], salary)
{
    new routeid = -1;
    routeid = Iter_Free(SweeperRoute);
    if(routeid == cellmax) return -1;

    format(sweeperrouteInfo[routeid][sweeperrouteName], MAX_SWEEPER_ROUTE_NAME, name);
    sweeperrouteInfo[routeid][sweeperrouteSalary] = salary;
    sweeperrouteInfo[routeid][sweeperrouteLocationX] = x;
    sweeperrouteInfo[routeid][sweeperrouteLocationY] = y;
    sweeperrouteInfo[routeid][sweeperrouteLocationZ] = z;
    sweeperrouteInfo[routeid][sweeperrouteStatus] = SWEEPER_ROUTE_UNUSED;

    Iter_Add(SweeperRoute, routeid);

    new query[1000];
    mysql_format(sql, query, sizeof query, "INSERT INTO `sweeper_route` (`id`, `name`, `salary`, `locationx`, `locationy`, `locationz`) VALUES ('%d', '%e', '%d', '%f', '%f', '%f')", routeid, sweeperrouteInfo[routeid][sweeperrouteName], sweeperrouteInfo[routeid][sweeperrouteSalary], sweeperrouteInfo[routeid][sweeperrouteLocationX], sweeperrouteInfo[routeid][sweeperrouteLocationY], sweeperrouteInfo[routeid][sweeperrouteLocationZ]);
    mysql_tquery(sql, query);
    return 1;
}

stock DeleteSweeperRoute(routeid) 
{
    if(!Iter_Contains(SweeperRoute, routeid)) return 1;
    sweeperrouteInfo[routeid][sweeperrouteStatus] = SWEEPER_ROUTE_UNUSED;
    Iter_Remove(SweeperRoute, routeid);

    new query[500];
    mysql_format(sql, query, sizeof(query), "DELETE FROM `sweeper_route` WHERE `id` = '%d'", routeid);
    mysql_tquery(sql, query);
    return 1;
}

stock LoadSweeperRoute() 
{
    mysql_tquery(sql, "SELECT * FROM `sweeper_route`", "AssignSweeperRoute");
    return 1;
}

stock SweeperRouteEdit_SetLoc(playerid, Float:x, Float:y, Float:z)
{
    player_editsweeperroute_loc[playerid][0] = x;
    player_editsweeperroute_loc[playerid][1] = y;
    player_editsweeperroute_loc[playerid][2] = z;
    return 1;
}

// ===========================
stock ShowPlayerSweeperRouteList(playerid) 
{
    if(!IsPlayerInAnyVehicle(playerid)) return 1;
    if(GetVehicleModel(GetPlayerVehicleID(playerid)) != 574) return 1;

    new message[3000];
    format(message, sizeof(message), "Rute\tGaji\n");
    foreach(new i : SweeperRoute) 
    {
        format(message, sizeof(message), "%s"WHITE"%s\t"LG"$%s\n", message, sweeperrouteInfo[i][sweeperrouteName], FormatMoney(sweeperrouteInfo[i][sweeperrouteSalary]));
    }
    Dialog_Show(playerid, SweeperRoute_JobList, DIALOG_STYLE_TABLIST_HEADERS, "Sweeper Job", message, "Pilih", "Tutup");
    return 1;
}

stock StartPlayerSweeperJob(playerid, routeid) 
{
    player_startsweeperroute_id[playerid] = routeid;
    player_startsweeperroute_vehid[playerid] = GetPlayerVehicleID(playerid);
    sweeperrouteInfo[routeid][sweeperrouteStatus] = SWEEPER_ROUTE_USED;
    StartPlayerSweeperMark(playerid);

    SendClientMessageEx(playerid, COLOR_REN, "SWEEPER: "WHITE"Anda sekarang bekerja sebagai "YELLOW"pembersih jalan (sweeper)");
    SendClientMessageEx(playerid, COLOR_REN, "TIPS: Ikuti tanda (checkpoint) untuk mengetahui rute pembersih jalan!");
    return 1;
}

stock StopPlayerSweeperJob(playerid, bool:give_salary = false) 
{
    new routeid = player_startsweeperroute_id[playerid];
    sweeperrouteInfo[routeid][sweeperrouteStatus] = SWEEPER_ROUTE_UNUSED;

    if(give_salary == true) 
    {
        GivePlayerMoney(playerid, sweeperrouteInfo[routeid][sweeperrouteSalary]);
        SendClientMessageEx(playerid, COLOR_REN, "SWEEPER: "WHITE"Anda mendapatkan "LG"$%s"WHITE" untuk menyelesaikan pekerjaan sweeper", FormatMoney(sweeperrouteInfo[routeid][sweeperrouteSalary]));
    }

    new vehicleid = GetPlayerVehicleID(playerid);
    RemovePlayerFromVehicle(playerid);

    PutVehicleToSpawnPos(vehicleid);
    
    new Float:maxfuel;
    GetVehicleMaxFuel(vehicleid, maxfuel);
    SetVehicleFuel(vehicleid, maxfuel);

    SetVehicleHealth(vehicleid, 1000.0);
    StopVehicleEngine(vehicleid);
    SetVehicleParams(vehicleid, VEHICLE_PARAMS_DOORS, false);

    player_startsweeperroute_id[playerid] = -1;
    DisablePlayerRaceCheckpoint(playerid);
    return 1;
}