YCMD:light(playerid, params[], help)
{
    if(IsPlayerInAnyVehicle(playerid))
    {
        new vehicleid = GetPlayerVehicleID(playerid);
        if(GetVehicleParams(vehicleid, VEHICLE_PARAMS_ENGINE))
        {
            if(GetVehicleParams(vehicleid, VEHICLE_PARAMS_LIGHTS)) {
                ToggleVehicleLight(vehicleid, false);
            } else {
                ToggleVehicleLight(vehicleid, true);
            }
        }
        else SendErrorMessage(playerid, "Mesin kendaraan mati!");
    }
    else SendErrorMessage(playerid, "Anda tidak berada di kendaraan!");
    return 1;
}