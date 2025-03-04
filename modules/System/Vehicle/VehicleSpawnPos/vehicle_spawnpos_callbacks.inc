hook OnVehicleCreated(vehicleid)
{
    new Float:x, Float:y, Float:z, Float:a;
    GetVehiclePos(vehicleid, x, y, z);
    GetVehicleZAngle(vehicleid, a);

    SetVehicleSpawnPos(vehicleid, x, y, z, a, GetVehicleInterior(vehicleid), GetVehicleVirtualWorld(vehicleid));
    return 1;
}

