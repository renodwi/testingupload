stock SetVehicleSpawnPos(vehicleid, Float:x, Float:y, Float:z, Float:a, interior, world)
{
    if(!IsValidVehicle(vehicleid)) return 1;

    vehicle_spawnpos[vehicleid][0] = x;
    vehicle_spawnpos[vehicleid][1] = y;
    vehicle_spawnpos[vehicleid][2] = z;
    vehicle_spawnpos[vehicleid][3] = a;

    vehicle_spawninterior[vehicleid] = interior;
    vehicle_spawnworld[vehicleid] = world;
    return 1;
}

stock GetVehicleSpawnPos(vehicleid, &Float:x, &Float:y, &Float:z, &Float:a, &interior, &world)
{
    if(!IsValidVehicle(vehicleid)) return 1;

    x = vehicle_spawnpos[vehicleid][0];
    y = vehicle_spawnpos[vehicleid][1];
    z = vehicle_spawnpos[vehicleid][2];
    a = vehicle_spawnpos[vehicleid][3];

    interior = vehicle_spawninterior[vehicleid];
    world = vehicle_spawnworld[vehicleid];
    return 1;
}

stock PutVehicleToSpawnPos(vehicleid) 
{
    if(!IsValidVehicle(vehicleid)) return 1;

    SetVehiclePos(vehicleid, vehicle_spawnpos[vehicleid][0], vehicle_spawnpos[vehicleid][1], vehicle_spawnpos[vehicleid][2]);
    SetVehicleZAngle(vehicleid, vehicle_spawnpos[vehicleid][3]);
    SetVehicleInterior(vehicleid, vehicle_spawninterior[vehicleid]);
    SetVehicleVirtualWorld(vehicleid, vehicle_spawnworld[vehicleid]);
    return 1;
}