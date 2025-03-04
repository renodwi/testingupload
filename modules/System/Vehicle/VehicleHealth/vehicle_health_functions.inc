stock SetVehicleMaxHealth(vehicleid, Float:max_health) 
{
    if(!IsValidVehicle(vehicleid)) return 1;
    
    new Float:health;
    GetVehicleHealth(vehicleid, health);
    
    vehicle_max_health[vehicleid] = max_health;
    return 1;
}

stock SetVehicleHealthToMax(vehicleid) 
{
    if(!IsValidVehicle(vehicleid)) return 1;
    
    new Float:max_health;
    GetVehicleMaxHealth(vehicleid, max_health);
    SetVehicleHealth(vehicleid, max_health);
    return 1;
}

stock GetVehicleMaxHealth(vehicleid, &Float:max_health) 
{
    if(!IsValidVehicle(vehicleid)) return 1;
    
    max_health = vehicle_max_health[vehicleid];
    return 1;
}