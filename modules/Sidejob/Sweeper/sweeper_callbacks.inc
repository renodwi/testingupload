hook OnGameModeInit()
{
    AddAdminCommand(Manager, "/sweeper", "Membuka menu untuk edit rute sweeper");
    return 1;
}

hook OnPlayerInVehicle(playerid, vehicleid) 
{
    if(GetVehicleOwnerType(vehicleid) == VEHICLE_OWNER_SWEEPER && player_startsweeperroute_id[playerid] == -1)
    {
        ShowPlayerSweeperRouteList(playerid);
    }
    return 1;
}

hook OnPlayerOutVehicle(playerid, vehicleid)
{
    vehicleid = player_startsweeperroute_vehid[playerid];
    if(player_startsweeperroute_id[playerid] != -1)
    {
        PutPlayerInVehicle(playerid, vehicleid, 0);
        Dialog_Show(playerid, SweeperJob_Exit, DIALOG_STYLE_MSGBOX, "Sweeper", ""WHITE"Anda yakin akan keluar dari pekerjaan? (anda akan tetap mendapatkan delay pekerjaan)", "Ya", "Tidak");
    }
    return 1;
}