hook OnGameModeInit()
{
    return 1;
}

hook OnVehicleCreated(vehicleid)
{
    SetVehicleMaxHealth(vehicleid, 1000.0);
    SetVehicleHealthToMax(vehicleid);
    return 1;
}

hook OnVehicleDestroyed(vehicleid)
{
    SetVehicleMaxHealth(vehicleid, 0.0);
    SetVehicleHealthToMax(vehicleid);
    return 1;
}