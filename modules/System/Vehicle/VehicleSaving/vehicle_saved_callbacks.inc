hook OnVehicleCreated(vehicleid)
{
    SetVehicleSaved(vehicleid, false);
    return 1;
}

hook OnVehicleSaved(vehicleid) 
{
    vehicle_databaseid[vehicleid] = cache_insert_id();
    UpdateVehicleData(vehicleid);
    return 1;
}