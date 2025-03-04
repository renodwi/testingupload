hook OnPlayerConnect(playerid)
{
    player_editdealer_vehposloc[playerid] = false;
    player_editdealer_vehposid[playerid] = -1;
    player_editdealer_cvehposloc[playerid] = false;
    player_buyveh_dealerid[playerid] = -1;
    player_buyveh_dealervehposid[playerid] = -1;
    return 1;
}

function OnDealershipVehPosCreated(dealershipid, dealervehposid)
{
    dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposDBID] = cache_insert_id();
    RefreshDealershipVehPos(dealershipid, dealervehposid);
    return 1;
}

function AssignDealershipVehPos(dealershipid)
{
	new rows  = cache_num_rows();
    if(rows)
    {
		for(new i; i < rows; i++)
		{
			cache_get_value_int(i, "id", dealershipvehposInfo[dealershipid][i][dealershipvehposDBID]);
			cache_get_value_float(i, "positionx", dealershipvehposInfo[dealershipid][i][dealershipvehposPositionX]);
			cache_get_value_float(i, "positiony", dealershipvehposInfo[dealershipid][i][dealershipvehposPositionY]);
			cache_get_value_float(i, "positionz", dealershipvehposInfo[dealershipid][i][dealershipvehposPositionZ]);
			cache_get_value_float(i, "positiona", dealershipvehposInfo[dealershipid][i][dealershipvehposPositionA]);
			cache_get_value_int(i, "model", dealershipvehposInfo[dealershipid][i][dealershipvehposModel]);
			cache_get_value_int(i, "price", dealershipvehposInfo[dealershipid][i][dealershipvehposPrice]);

            dealershipvehposInfo[dealershipid][i][dealershipvehposExist] = true;
            RefreshDealershipVehPos(dealershipid, i);

            #if defined DEBUG_MODE
                printf("[Dealership VehPos]: id %d position (x: %f y: %f z: %f a: %f) model %d price $%s", dealershipvehposInfo[dealershipid][i][dealershipvehposDBID], dealershipvehposInfo[dealershipid][i][dealershipvehposPositionX], dealershipvehposInfo[dealershipid][i][dealershipvehposPositionY], dealershipvehposInfo[dealershipid][i][dealershipvehposPositionZ], dealershipvehposInfo[dealershipid][i][dealershipvehposPositionA], dealershipvehposInfo[dealershipid][i][dealershipvehposModel], FormatMoney(dealershipvehposInfo[dealershipid][i][dealershipvehposPrice]));
            #endif
		}
	}
    return 1;
}

hook OnPlayerInVehicle(playerid, vehicleid)
{
    if(GetVehicleOwnerType(vehicleid) == VEHICLE_OWNER_DEALERSHIP)
    {
        new price, dealershipid, dealervehposid;
        unformat(GetVehicleOwnerName(vehicleid), "p<|>dd", dealershipid, dealervehposid);
        price = dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPrice];
        Dialog_Show(playerid, BuyVehicle_Conf, DIALOG_STYLE_MSGBOX, "Buy Vehicle", ""WHITE"Anda yakin akan membeli kendaraan "YELLOW"%s"WHITE" dengan harga "LG"$%s"WHITE"?", "Beli", "Tidak", GetVehicleModelName(GetVehicleModel(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposID])), FormatMoney(price));
    
        player_buyveh_dealerid[playerid] = dealershipid;
        player_buyveh_dealervehposid[playerid] = dealervehposid;
    }
    return 1;
}