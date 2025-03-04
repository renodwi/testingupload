stock SetVehicleSaved(vehicleid, bool:saved) 
{
    if(saved == false) 
    {
        if(vehicle_saved[vehicleid] == true)
        {
            new query[200];
            mysql_format(sql, query, sizeof(query), "DELETE FROM `vehicles` WHERE `id` = '%d'", vehicle_databaseid[MAX_VEHICLES]);
            mysql_tquery(sql, query);
        }

        vehicle_saved[vehicleid] = false;
        vehicle_databaseid[vehicleid] = -1;
    }
    else
    {
        if(vehicle_saved[vehicleid] == true)
        {
            UpdateVehicleData(vehicleid);
            return 1;
        }
        else
        {
            new query[200];
            mysql_format(sql, query, sizeof(query), "INSERT INTO `vehicles` (`model`) VALUES (`%d`)", GetVehicleModel(vehicleid));
            mysql_tquery(sql, query, "OnVehicleSaved", "d", vehicleid);

            vehicle_saved[vehicleid] = true;
        }
    }
    return 1;
}

stock UpdateVehicleData(vehicleid) 
{
    new query[3090];
    mysql_format(sql, query, sizeof(query), "UPDATE `vehicles` SET");
    mysql_format(sql, query, sizeof(query), "%s `hungry` = '%f', ", query, playerInfo[playerid][playerHungry]);
    mysql_format(sql, query, sizeof(query), "%s `name` = '%e' WHERE `id` = '%d'", query, playerInfo[playerid][playerName], playerInfo[playerid][playerDBID]);
    mysql_tquery(sql, query);
    return 1;
}

