hook OnVehicleCreated(vehicleid)
{
    if(IsVehicleHasEngine(vehicleid))
    {
        SetVehicleParams(vehicleid, VEHICLE_PARAMS_ENGINE, false);
    }
    else
    {
        SetVehicleParams(vehicleid, VEHICLE_PARAMS_ENGINE, true);
    }
    return 1;
}

function TryStartVehicleEngine(playerid, vehicleid) 
{
    if(!IsPlayerInVehicle(playerid, vehicleid))
        return ShowPlayerFooter(playerid, 1000, "~w~Mesin kendaraan ~r~mati");

    new Float:health, Float:fuel;
    GetVehicleHealth(vehicleid, health);
    GetVehicleFuel(vehicleid, fuel);

    if(health <= 350.0)
        return ShowPlayerFooter(playerid, 2000, "~r~Gagal menghidupkan mesin kendaraan ~w~karena mesin rusak!");

    if(fuel <= 0.0)
        return ShowPlayerFooter(playerid, 2000, "~r~Gagal menghidupkan mesin kendaraan ~w~karena bahan bakar kendaraan habis!");

    SetVehicleParams(vehicleid, VEHICLE_PARAMS_ENGINE, true);
    StartVehicleConsumeFuel(vehicleid);

    ShowPlayerFooter(playerid, 1200, "~w~Mesin kendaraan telah ~g~hidup");
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(IsKeyJustDown(KEY_FIRE, newkeys, oldkeys))
    {
        if(IsPlayerInAnyVehicle(playerid) && !GetVehicleParams(GetPlayerVehicleID(playerid), VEHICLE_PARAMS_ENGINE))
        {
            new vehicleid = GetPlayerVehicleID(playerid);

            if(IsVehicleRefueling(vehicleid)) return 1;
            if(GetVehicleOwnerType(vehicleid) == VEHICLE_OWNER_DEALERSHIP) return 1;
            if(!IsVehicleHasEngine(vehicleid)) return 1;
            
            StartVehicleEngine(GetPlayerVehicleID(playerid));
        }
    }
    else if(IsKeyJustDown(KEY_FIRE, newkeys, oldkeys) && IsKeyJustDown(KEY_NO, newkeys, oldkeys))
    {
        if(IsPlayerInAnyVehicle(playerid) && GetVehicleParams(GetPlayerVehicleID(playerid), VEHICLE_PARAMS_ENGINE))
        {
            new vehicleid = GetPlayerVehicleID(playerid);

            if(IsVehicleRefueling(vehicleid)) return 1;
            if(GetVehicleOwnerType(vehicleid) == VEHICLE_OWNER_DEALERSHIP) return 1;
            if(!IsVehicleHasEngine(vehicleid)) return 1;
            
            StopVehicleEngine(GetPlayerVehicleID(playerid));
            ShowPlayerFooter(playerid, 1000, "~w~Mesin kendaraan ~r~mati");

            return 1;
        }
    }
    return 1;
}