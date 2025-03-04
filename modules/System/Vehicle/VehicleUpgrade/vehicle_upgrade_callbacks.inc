hook OnVehicleCreated(vehicleid)
{
    SetVehicleUpgrade(vehicleid, 0);
    return 1;
}

hook OnVehicleDamageStatusUpd(vehicleid, playerid)
{
    new Float:health, upgrade;
    GetVehicleHealth(vehicleid, health);
    GetVehicleUpgrade(vehicleid, upgrade);

    if(upgrade == 2 && health > 1000.0)
    {
        RepairVehicle(vehicleid);
        SetVehicleHealth(vehicleid, health);
    }
    return 1;
}