stock SetVehicleLocked(vehicleid, bool:locked)
{
    if(locked == true) 
    {
        SetVehicleParams(vehicleid, VEHICLE_PARAMS_DOORS, true);
        ShowPlayerFooter(GetVehicleDriver(vehicleid), 1500, "Pintu kendaraan ~r~terkunci");
    }
    else
    {
        SetVehicleParams(vehicleid, VEHICLE_PARAMS_DOORS, false);
        ShowPlayerFooter(GetVehicleDriver(vehicleid), 1500, "Pintu kendaraan ~r~terbuka");
    }
    return 1;
}