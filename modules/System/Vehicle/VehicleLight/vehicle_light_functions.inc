stock ToggleVehicleLight(vehicleid, bool:toggle) 
{
    SetVehicleParams(vehicleid, VEHICLE_PARAMS_LIGHTS, toggle);
    SendClientMessageEx(GetVehicleDriver(vehicleid), COLOR_REN, "VEHICLE-LIGHT: "WHITE"Status %s", toggle ? ""LG"On" : ""LR"Off");
    return toggle;
}