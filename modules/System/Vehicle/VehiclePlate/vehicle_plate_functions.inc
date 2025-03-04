stock n_SetVehicleNumberPlate(vehicleid, const numberplate[])
{
    if(!IsValidVehicle(vehicleid)) return 1;

    format(vehicle_plate[vehicleid], MAX_VEHICLE_PLATE, numberplate);
    RefreshVehicleNumberPlate(vehicleid);
    return 1;
}

#if defined _ALS_SetVehicleNumberPlate
	#undef SetVehicleNumberPlate
#else
	#define _ALS_SetVehicleNumberPlate
#endif
#define SetVehicleNumberPlate n_SetVehicleNumberPlate

stock GetVehicleNumberPlate(vehicleid)
{
    new value[10];
    format(value, sizeof(value), vehicle_plate[vehicleid]);
    return value;
}

stock RefreshVehicleNumberPlate(vehicleid) 
{
    if(!IsValidVehicle(vehicleid)) return 1;

    if(IsValidDynamic3DTextLabel(vehicle_platetext[vehicleid]))
        DestroyDynamic3DTextLabel(vehicle_platetext[vehicleid]);

    if(IsVehicleHasEngine(vehicleid))
    {
        new Float:sx, Float:sy, Float:sz;
        GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_SIZE, sx, sy, sz);
        vehicle_platetext[vehicleid] = CreateDynamic3DTextLabel(GetVehicleNumberPlate(vehicleid), COLOR_YELLOW, 0.0, -(sy/2.3), 0.0, 10.0, INVALID_PLAYER_ID, vehicleid, 0, GetVehicleVirtualWorld(vehicleid), GetVehicleInterior(vehicleid));
        Streamer_Update(GetVehicleDriver(vehicleid));

        SetVehicleNumberPlate(vehicleid, vehicle_plate[vehicleid]);
    }
    return 1;
}