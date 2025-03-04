hook OnVehicleCreated(vehicleid)
{
    SetVehicleMaxFuel(vehicleid, 45.0);
    SetVehicleFuelToMax(vehicleid);

    StopVehicleConsumeFuel(vehicleid);
    return 1;
}

hook OnVehicleDestroyed(vehicleid)
{
    SetVehicleMaxFuel(vehicleid, 0.0);
    SetVehicleFuelToMax(vehicleid);

    StopVehicleConsumeFuel(vehicleid);
    return 1;
}

function ConsumeVehicleFuel(vehicleid) 
{
    new Float:mass, Float:speed, Float:dist, Float:oldfuel;
    GetVehicleFuel(vehicleid, oldfuel);
    if(oldfuel > 0.0)
    {
        dist = GetVehicleDistanceFromPoint(vehicleid, last_vehicle_position[vehicleid][0], last_vehicle_position[vehicleid][1], last_vehicle_position[vehicleid][2]);
        mass = GetVehicleMass(GetVehicleModel(vehicleid));
        speed = GetVehicleSpeed(vehicleid);

        SetVehicleFuel(vehicleid, oldfuel-(((mass / (mass * 4.5)) * ((speed / 60) + 0.015) / 30) * ((dist / 10) + 0.001)) / 100);

        GetVehiclePos(vehicleid, last_vehicle_position[vehicleid][0], last_vehicle_position[vehicleid][1], last_vehicle_position[vehicleid][2]);

        GetVehicleFuel(vehicleid, oldfuel);
    }
    else if(oldfuel <= 0.0)
    {
        StopVehicleEngine(vehicleid);
        StopVehicleConsumeFuel(vehicleid);

        ShowPlayerFooter(GetVehicleDriver(vehicleid), 2000, "~r~Mesin kendaraan mati ~w~karena bahan bakar kendaraan habis!");
    }
    return 1;
}

function VehicleRefueling(vehicleid) 
{
    new Float:oldfuel, Float:maxfuel;
    GetVehicleFuel(vehicleid, oldfuel);
    GetVehicleMaxFuel(vehicleid, maxfuel);

    if(vehicle_refueling_amount[vehicleid] > 0.0)
    {
        if(oldfuel <= maxfuel)
        {
            vehicle_refueling_amount[vehicleid] -= 0.1;
            SetVehicleFuel(vehicleid, oldfuel + 0.1);

            ShowPlayerFooter(GetVehicleDriver(vehicleid), 500, "~w~Mengisi bahan bakar kendaraan...~n~~y~%.2f L / %.2f L", (oldfuel + 0.1), maxfuel);
        }
        else
        {
            SetVehicleFuel(vehicleid, maxfuel);
            vehicle_refueling_amount[vehicleid] = 0.0;

            ShowPlayerFooter(GetVehicleDriver(vehicleid), 1500, "~w~Pengisian bahan bakar ~y~selesai~w~. Bahan bakar kendaraan sekarang ~g~Penuh");
            vehicle_refueling[vehicleid] = false;
        }
    }
    else if(vehicle_refueling_amount[vehicleid] <= 0.0)
    {
        vehicle_refueling_amount[vehicleid] = 0.0;
        ShowPlayerFooter(GetVehicleDriver(vehicleid), 1500, "~w~Pengisian bahan bakar ~y~selesai~w~");
        
        vehicle_refueling[vehicleid] = false;
    }
    return 1;
}