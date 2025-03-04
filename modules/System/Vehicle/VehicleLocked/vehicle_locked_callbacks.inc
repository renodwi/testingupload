hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(IsKeyJustDown(KEY_SUBMISSION, newkeys, oldkeys))
    {
        if(IsPlayerInAnyVehicle(playerid))
        {
            new vehicleid = GetPlayerVehicleID(playerid);
            if(GetVehicleOwnerType(vehicleid) != VEHICLE_OWNER_PLAYER) return 1;

            if(GetVehicleParams(vehicleid, VEHICLE_PARAMS_DOORS)) SetVehicleLocked(vehicleid, false);
            else SetVehicleLocked(vehicleid, true);
        }
    }
    return 1;
}