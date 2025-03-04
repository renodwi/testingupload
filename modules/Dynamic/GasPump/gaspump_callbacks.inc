hook OnGameModeInit()
{
    AddAdminCommand(Manager, "/gaspump [action]", "Digunakan untuk membuka menu gas pump");
    return 1;
}

hook OnServerAssignData()
{
    mysql_tquery(sql, "SELECT * FROM `gaspumps`", "AssignGasPumpData");
    return 1;
}

hook OnPlayerConnect(playerid)
{
    return 1;
}

hook OnEditObjectResponse(playerid, action, response, objectid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
    if(action == EDITOBJECT_GASPUMP)
    {
        if(player_edit_gaspumpid[playerid] != -1)
        {
            new gaspumpid = player_edit_gaspumpid[playerid];
            if(response == EDIT_RESPONSE_CANCEL)
            {
                RefreshGasPump(gaspumpid);
            }
            else if(response == EDIT_RESPONSE_FINAL)
            {
                gaspumpInfo[gaspumpid][gaspumpPositionX] = x;
                gaspumpInfo[gaspumpid][gaspumpPositionY] = y;
                gaspumpInfo[gaspumpid][gaspumpPositionZ] = z;
                gaspumpInfo[gaspumpid][gaspumpRotationX] = rx;
                gaspumpInfo[gaspumpid][gaspumpRotationY] = ry;
                gaspumpInfo[gaspumpid][gaspumpRotationZ] = rz;
                RefreshGasPump(gaspumpid);
            }
        }
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(IsKeyJustDown(KEY_NO, newkeys, oldkeys))
    {
        if(GetPlayerNearestGasPump(playerid) != -1)
        {
            if(IsPlayerInAnyVehicle(playerid))
            {
                if(GetVehicleParams(GetPlayerVehicleID(playerid), VEHICLE_PARAMS_ENGINE))
                    return SendErrorMessage(playerid, "Matikan mesin kendaraan jika ingin mengisi bahan bakar!");
                    
                new gaspumpid, businessid, vehicleid;
                gaspumpid = GetPlayerNearestGasPump(playerid);
                businessid = gaspumpInfo[gaspumpid][gaspumpBusinessID];
                vehicleid = (GetPlayerVehicleID(playerid));

                if(GetVehicleOwnerType(vehicleid) == VEHICLE_OWNER_DEALERSHIP) return 1;

                if(IsVehicleRefueling(vehicleid))
                    return SendErrorMessage(playerid, "Kendaraan ini sedang di isi bahan bakar!");

                if(gaspumpInfo[gaspumpid][gaspumpBusinessID] == -1)
                    return SendErrorMessage(playerid, "Mesin bahan bakar ini tidak dapat digunakan karena belum memiliki pemilik!");
                    
                ShowBuyFuelMenu(playerid, vehicleid, businessid);
            }
        }
    }
    return 1;
}
