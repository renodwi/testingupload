hook OnVehicleCreated(vehicleid)
{
    if(IsVehicleHasEngine(vehicleid)) SetVehicleNumberPlate(vehicleid, "--------");
    return 1;
}