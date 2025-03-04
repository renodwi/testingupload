YCMD:setvehiclefuel(playerid, params[], help) 
{
    /* if(!IsPlayerAdmin(playerid, Admin1))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!"); */

    new vehicleid, Float:fuel, Float:before_fuel;

    if(IsPlayerInAnyVehicle(playerid))
    {
        if(sscanf(params, "f", fuel))
            return SendUsageMessage(playerid, "/setvehiclefuel [Float: fuel]");

        vehicleid = GetPlayerVehicleID(playerid);
    }
    else
    {
        if(sscanf(params, "df", vehicleid, fuel))
            return SendUsageMessage(playerid, "/setvehiclefuel [vehicle id] [Float: fuel]");
    }

    GetVehicleFuel(vehicleid, before_fuel);
    SendClientMessageEx(playerid, COLOR_REN, "VEHICLE: "WHITE"Anda telah mengubah bahan bakar "YELLOW"kendaraan %d"WHITE" dari "LB"%.2f L."WHITE" menjadi "LG"%.2f L.", vehicleid, before_fuel, fuel);
    
    SetVehicleFuel(vehicleid, fuel);
    return 1;
}

YCMD:setvehiclemaxfuel(playerid, params[], help) 
{
    /* if(!IsPlayerAdmin(playerid, Admin1))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!"); */

    new vehicleid, Float:fuel, Float:before_fuel;

    if(IsPlayerInAnyVehicle(playerid))
    {
        if(sscanf(params, "f", fuel))
            return SendUsageMessage(playerid, "/setvehiclefuel [Float: max fuel]");

        vehicleid = GetPlayerVehicleID(playerid);
    }
    else
    {
        if(sscanf(params, "df", vehicleid, fuel))
            return SendUsageMessage(playerid, "/setvehiclefuel [vehicle id] [Float: max fuel]");
    }

    GetVehicleMaxFuel(vehicleid, before_fuel);
    SendClientMessageEx(playerid, COLOR_REN, "VEHICLE: "WHITE"Anda telah mengubah maksimal bahan bakar "YELLOW"kendaraan %d"WHITE" dari "LB"%.2f L."WHITE" menjadi "LG"%.2f L.", vehicleid, before_fuel, fuel);
    
    SetVehicleMaxFuel(vehicleid, fuel);
    return 1;
}