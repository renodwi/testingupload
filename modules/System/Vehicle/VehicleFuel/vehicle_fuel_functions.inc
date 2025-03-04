stock SetVehicleMaxFuel(vehicleid, Float:max_fuel) 
{
    if(!IsValidVehicle(vehicleid)) return 1;

    vehicle_max_fuel[vehicleid] = max_fuel;
    return 1;
}

stock GetVehicleMaxFuel(vehicleid, &Float:max_fuel) 
{
    if(!IsValidVehicle(vehicleid)) return 1;

    max_fuel = vehicle_max_fuel[vehicleid];
    return 1;
}

stock SetVehicleFuel(vehicleid, Float:fuel) 
{
    if(!IsValidVehicle(vehicleid)) return 1;

    vehicle_fuel[vehicleid] = fuel;
    return 1;
}

stock GetVehicleFuel(vehicleid, &Float:fuel)
{
    if(!IsValidVehicle(vehicleid)) return 1;

    fuel = vehicle_fuel[vehicleid];
    return 1;
}

stock SetVehicleFuelToMax(vehicleid) 
{
    if(!IsValidVehicle(vehicleid)) return 1;

    new Float:fuel;
    GetVehicleMaxFuel(vehicleid, fuel);
    SetVehicleFuel(vehicleid, fuel);
    return 1;
}

/* ================================= */

stock StartVehicleConsumeFuel(vehicleid)
{
    if(!IsValidVehicle(vehicleid)) return 1;
    if(vehicle_consuming_fuel[vehicleid] == true) return 1;
    if(!IsVehicleHasEngine(vehicleid)) return 1;

    vehicle_consuming_fuel[vehicleid] = true;
    GetVehiclePos(vehicleid, last_vehicle_position[vehicleid][0], last_vehicle_position[vehicleid][1], last_vehicle_position[vehicleid][2]);

    vehicle_consume_fuel_timer[vehicleid] = SetTimerEx("ConsumeVehicleFuel", 1000, true, "d", vehicleid);
    return 1;
}

stock StopVehicleConsumeFuel(vehicleid) 
{
    if(!IsValidVehicle(vehicleid)) return 1;
    if(vehicle_consuming_fuel[vehicleid] == false) return 1;

    vehicle_consuming_fuel[vehicleid] = false;
    KillTimer(vehicle_consume_fuel_timer[vehicleid]);
    return 1;
}

/* ================================ */

stock SetVehicleRefueling(vehicleid, Float:amount)
{
    if(!IsValidVehicle(vehicleid)) return 1;
    
    vehicle_refueling[vehicleid] = true;
    vehicle_refueling_amount[vehicleid] = amount;
    vehicle_refueling_timer[vehicleid] = SetTimerEx("VehicleRefueling", Random(200, 300), true, "d", vehicleid);
    return 1;
}

stock IsVehicleRefueling(vehicleid) 
{
    new status = vehicle_refueling[vehicleid];
    return status;
}