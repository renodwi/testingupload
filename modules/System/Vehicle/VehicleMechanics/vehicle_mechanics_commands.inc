YCMD:inspectvehicle(playerid, params[], help) 
{
    if(!IsPlayerInJob(playerid, JOB_MECHANIC))
        return SendErrorMessage(playerid, "Anda bukan seorang mekanik!");

    new vehicleid = INVALID_VEHICLE_ID, Float:x, Float:y, Float:z;
    foreach(new i : Vehicle)
    {
        GetVehiclePos(i, x, y, z);
        if(IsPlayerInRangeOfPoint(playerid, 10.0, x, y, z))
        {
            vehicleid = i;
            break;
        }
        else
        {
            vehicleid = INVALID_VEHICLE_ID;
            continue;
        }
    }

    if(vehicleid == INVALID_VEHICLE_ID)
        return SendErrorMessage(playerid, "Anda tidak berada di dekat kendaraan apapun!");

    player_inspectveh_id[playerid] = vehicleid;
    Dialog_Show(playerid, InspectVehicle, DIALOG_STYLE_MSGBOX, "Cek Kendaraan", va_return("Anda yakin akan mengecek kondisi kendaraan %s ini?", GetVehicleModelName(GetVehicleModel(vehicleid))), "Ya", "Tidak");
    return 1;
}

YCMD:mech(playerid, params[], help)
{
    if(!IsPlayerInJob(playerid, JOB_MECHANIC))
        return SendErrorMessage(playerid, "Anda bukan seorang mekanik!");

    new vehicleid = INVALID_VEHICLE_ID, Float:x, Float:y, Float:z;
    foreach(new i : Vehicle)
    {
        GetVehiclePos(i, x, y, z);
        if(IsPlayerInRangeOfPoint(playerid, 10.0, x, y, z))
        {
            vehicleid = i;
            break;
        }
        else
        {
            vehicleid = INVALID_VEHICLE_ID;
            continue;
        }
    }

    if(vehicleid != player_inspectveh_id[playerid])
        return SendErrorMessage(playerid, "Anda sebelumnya tidak mengecek kondisi kendaraan ini!");

    if(player_hasinspectveh[playerid] == false)
        return SendErrorMessage(playerid, "Anda sebelumnya tidak mengecek kondisi kendaraan ini!");

    ShowPlayerMechMenu(playerid, vehicleid);
    return 1;
}