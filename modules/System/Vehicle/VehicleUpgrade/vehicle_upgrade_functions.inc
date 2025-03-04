stock SetVehicleUpgrade(vehicleid, upgrade)
{
    vehicle_upgrade[vehicleid] = upgrade;

    switch(upgrade)
    {
        case 0: // No Uprade
        {
            SetVehicleMaxHealth(vehicleid, 1000.0);
            SetVehicleHealthToMax(vehicleid);
        }
        case 1: // Engine Upgrade
        {
            SetVehicleMaxHealth(vehicleid, 2000.0);
            SetVehicleHealthToMax(vehicleid);
        }
        case 2: // Body Upgrade 
        {
            new Float:health;
            GetVehicleHealth(vehicleid, health);

            RepairVehicle(vehicleid);
            SetVehicleHealth(vehicleid, health);
        }
        case 3: // Fuel Uprade
        {
            SetVehicleMaxFuel(vehicleid, 60.0);
            SetVehicleFuelToMax(vehicleid);
        }
    }
    return 1;
}

stock GetVehicleUpgrade(vehicleid, &upgrade) 
{
    upgrade = vehicle_upgrade[vehicleid];
    return 1;
}