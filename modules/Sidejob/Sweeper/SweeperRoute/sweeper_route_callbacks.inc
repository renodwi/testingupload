hook OnServerAssignData()
{
    LoadSweeperRoute();
    return 1;
}

hook OnPlayerConnect(playerid)
{
    player_startsweeperroute_id[playerid] = -1;
    return 1;
}

function AssignSweeperRoute() 
{
    static routeid;
	new rows  = cache_num_rows();
    if(rows)
    {
		for(new i; i < rows; i++)
		{
            cache_get_value_int(i, "id", routeid);
            cache_get_value(i, "name", sweeperrouteInfo[routeid][sweeperrouteName]);
            cache_get_value_int(i, "salary", sweeperrouteInfo[routeid][sweeperrouteSalary]);
            cache_get_value_float(i, "locationx", sweeperrouteInfo[routeid][sweeperrouteLocationX]);
            cache_get_value_float(i, "locationy", sweeperrouteInfo[routeid][sweeperrouteLocationY]);
            cache_get_value_float(i, "locationz", sweeperrouteInfo[routeid][sweeperrouteLocationZ]);

            Iter_Add(SweeperRoute, routeid);
            LoadSweeeperMark(routeid);

            #if defined DEBUG_MODE
                printf("[Sweeper Route] sweeper id: %d name: %s salary: $%s location: %s", routeid, sweeperrouteInfo[routeid][sweeperrouteName], FormatMoney(sweeperrouteInfo[routeid][sweeperrouteSalary]), GetLocation(sweeperrouteInfo[routeid][sweeperrouteLocationX], sweeperrouteInfo[routeid][sweeperrouteLocationY], sweeperrouteInfo[routeid][sweeperrouteLocationZ]));
            #endif
        }
    }
    return 1;
}