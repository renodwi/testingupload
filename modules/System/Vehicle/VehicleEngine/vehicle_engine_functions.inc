stock StartVehicleEngine(vehicleid) 
{
    if(!IsValidVehicle(vehicleid)) return 1;
    if(GetVehicleParams(vehicleid, VEHICLE_PARAMS_ENGINE)) return 1;

    new delay = RandomMinMax(1500, 2000);
    if(GetVehicleDriver(vehicleid) != INVALID_PLAYER_ID) ShowPlayerFooter(GetVehicleDriver(vehicleid), delay, "~w~Mencoba menghidupkan mesin kendaraan...");
    SetTimerEx("TryStartVehicleEngine", delay, false, "dd", GetVehicleDriver(vehicleid), vehicleid);
    return 1;
}

stock StopVehicleEngine(vehicleid)
{
    if(!IsValidVehicle(vehicleid)) return 1;
    if(!GetVehicleParams(vehicleid, VEHICLE_PARAMS_ENGINE)) return 1;

    SetVehicleParams(vehicleid, VEHICLE_PARAMS_ENGINE, false);
    StopVehicleConsumeFuel(vehicleid);
    ToggleVehicleLight(vehicleid, false);
    return 1;
}