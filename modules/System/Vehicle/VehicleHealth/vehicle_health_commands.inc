YCMD:setvehiclehealth(playerid, params[], help) 
{
    /* if(!IsPlayerAdmin(playerid, Admin1))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!"); */

    new vehicleid, Float:health, Float:before_health;

    if(IsPlayerInAnyVehicle(playerid))
    {
        if(sscanf(params, "f", health))
            return SendUsageMessage(playerid, "/setvehiclehealth [Float: health]");

        vehicleid = GetPlayerVehicleID(playerid);
    }
    else
    {
        if(sscanf(params, "df", vehicleid, health))
            return SendUsageMessage(playerid, "/setvehiclehealth [vehicle id] [Float: health]");
    }

    GetVehicleHealth(vehicleid, before_health);
    SendClientMessageEx(playerid, COLOR_REN, "VEHICLE: "WHITE"Anda telah mengubah health "YELLOW"kendaraan %d"WHITE" dari "LB"%.2f"WHITE" menjadi "LG"%.2f", vehicleid, before_health, health);
    
    SetVehicleHealth(vehicleid, health);
    return 1;
}

YCMD:setvehiclemaxhealth(playerid, params[], help) 
{
    /* if(!IsPlayerAdmin(playerid, Admin1))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!"); */

    new vehicleid, Float:health, Float:before_health;

    if(IsPlayerInAnyVehicle(playerid))
    {
        if(sscanf(params, "f", health))
            return SendUsageMessage(playerid, "/setvehiclemaxhealth [Float: health]");

        vehicleid = GetPlayerVehicleID(playerid);
    }
    else
    {
        if(sscanf(params, "df", vehicleid, health))
            return SendUsageMessage(playerid, "/setvehiclemaxhealth [vehicle id] [Float: health]");
    }

    GetVehicleMaxHealth(vehicleid, before_health);
    SendClientMessageEx(playerid, COLOR_REN, "VEHICLE: "WHITE"Anda telah mengubah health maksimal "YELLOW"kendaraan %d"WHITE" dari "LB"%.2f"WHITE" menjadi "LG"%.2f", vehicleid, before_health, health);
    
    SetVehicleMaxHealth(vehicleid, health);
    return 1;
}