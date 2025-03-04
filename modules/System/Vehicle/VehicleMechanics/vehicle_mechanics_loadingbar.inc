LoadingBar:InspectVehicle(playerid) 
{
    new vehicleid = player_inspectveh_id[playerid];
    SendClientMessageEx(playerid, COLOR_REN, "MEKANIK: "WHITE"Berhasil mengecek kondisi kendaraan "LR"%s", GetVehicleModelName(GetVehicleModel(vehicleid)));
    SendClientMessageEx(playerid, COLOR_REN, "MEKANIK: "WHITE"Gunakan "YELLOW"/mech"WHITE" untuk membuka menu mekanik.");

    player_hasinspectveh[playerid] = true;
    return 1;
}