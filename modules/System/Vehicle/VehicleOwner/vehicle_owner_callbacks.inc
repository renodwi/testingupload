hook OnPlayerInVehicle(playerid, vehicleid) 
{
    if(GetVehicleOwnerType(vehicleid) == VEHICLE_OWNER_UNKNOWN)
    {
        RemovePlayerFromVehicle(playerid);
        ShowPlayerFooter(playerid, 2000, "Anda tidak dapat menaiki kendaraan ini!");
        return 1;
    }
    return 1;
}

hook OnVehicleDestroyed(vehicleid)
{
    SetVehicleOwner(vehicleid, VEHICLE_OWNER_UNKNOWN, "Unknown");
    return 1;
}