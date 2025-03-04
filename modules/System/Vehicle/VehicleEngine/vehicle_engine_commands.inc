YCMD:engine(playerid, params[], help) 
{

    if(!IsPlayerInAnyVehicle(playerid)) return 1;

    new vehicleid = GetPlayerVehicleID(playerid);
    if(!IsVehicleHasEngine(vehicleid)) return 1;
    

    if(IsVehicleRefueling(vehicleid))
        return SendErrorMessage(playerid, "Anda tidak dapat menghidupkan mesin kendaraan ketika mengisi bahan bakar!");

    if(GetVehicleOwnerType(vehicleid) == VEHICLE_OWNER_DEALERSHIP) return 1;
    
    if(!GetVehicleParams(vehicleid, VEHICLE_PARAMS_ENGINE))
    {
        StartVehicleEngine(vehicleid);
    }
    else
    {
        ShowPlayerFooter(playerid, 1000, "~w~Mesin kendaraan ~r~mati");
        StopVehicleEngine(vehicleid);
    }
    return 1;
}