stock SetVehicleOwner(vehicleid, owner_type, const owner_name[])
{
    if(!IsValidVehicle(vehicleid)) return 1;

    vehicle_owner_type[vehicleid] = owner_type;
    format(vehicle_owner_name[vehicleid], MAX_VEHICLE_OWNERNAME, owner_name);
    return 1;
}

stock GetVehicleOwnerType(vehicleid) 
{
    if(!IsValidVehicle(vehicleid)) return 1;

    new type = vehicle_owner_type[vehicleid];
    return type;
}

stock GetVehicleOwnerName(vehicleid) 
{
    new name[MAX_VEHICLE_OWNERNAME];
    format(name, MAX_VEHICLE_OWNERNAME, vehicle_owner_name[vehicleid]);
    return name;
}