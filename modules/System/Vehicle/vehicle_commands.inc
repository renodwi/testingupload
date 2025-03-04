YCMD:vehicle(playerid, params[], help) 
{
    if(!IsPlayerAdmin(playerid, Admin3))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");

    new action[50], string[250], bool:syntax = true;
    if(sscanf(params, "s[50]S()[250]", action, string))
    {
        syntax = false;
    }
    else
    {
        if(!strcmp(action, "create", true)) 
        {
            new model, Float:x, Float:y, Float:z, Float:a, color[2], vehicleid;

            if(sscanf(string, "d", model))
                return SendUsageMessage(playerid, "/vehicle create [vehicle model (see /vmodels)]");
            
            GetPlayerPos(playerid, x, y, z);
            GetPlayerFacingAngle(playerid, a);

            GetVehicleRandomColors(model, color[0], color[1]);
            vehicleid = CreateVehicle(model, x, y, z, a, color[0], color[1], -1, false);
            SetVehicleOwner(vehicleid, VEHICLE_OWNER_ADMIN, "Admin");

            PutPlayerInVehicle(playerid, vehicleid, 0);
        }
    }

    if(syntax == false)
    {
        SendUsageMessage(playerid, "/vehicle [action]");
        SendClientMessageEx(playerid, COLOR_REN, "ACTION: create");
    }
    return 1;
}