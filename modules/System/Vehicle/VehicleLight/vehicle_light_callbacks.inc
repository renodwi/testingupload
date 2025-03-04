hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(IsKeyJustDown(KEY_FIRE, newkeys, oldkeys) && IsKeyJustDown(KEY_NO, newkeys, oldkeys))
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
            
        }
    }
    return 1;
}