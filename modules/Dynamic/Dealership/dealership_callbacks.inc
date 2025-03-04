hook OnPlayerConnect(playerid) 
{
    player_editdealer_id[playerid] = -1;
    player_editdealer_position[playerid] = false;
    return 1;
}

hook OnDealershipCreated(dealershipid)
{
    RefreshDealership(dealershipid);
    return 1;
}

hook OnServerAssignData()
{
    LoadDealership();
    return 1;
}

function AssignDealershipData()
{
    static dealershipid;
	new rows  = cache_num_rows();
    if(rows)
    {
		for(new i; i < rows; i++)
		{
			cache_get_value_int(i, "id", dealershipid);
			cache_get_value(i, "owner", dealershipInfo[dealershipid][dealershipOwner]);
			cache_get_value(i, "name", dealershipInfo[dealershipid][dealershipName]);
			cache_get_value_int(i, "money", dealershipInfo[dealershipid][dealershipMoney]);
			cache_get_value_int(i, "price", dealershipInfo[dealershipid][dealershipPrice]);
			cache_get_value_float(i, "positionx", dealershipInfo[dealershipid][dealershipPositionX]);
			cache_get_value_float(i, "positiony", dealershipInfo[dealershipid][dealershipPositionY]);
			cache_get_value_float(i, "positionz", dealershipInfo[dealershipid][dealershipPositionZ]);
			cache_get_value_float(i, "spawnpositionx", dealershipInfo[dealershipid][dealershipSpawnPositionX]);
			cache_get_value_float(i, "spawnpositiony", dealershipInfo[dealershipid][dealershipSpawnPositionY]);
			cache_get_value_float(i, "spawnpositionz", dealershipInfo[dealershipid][dealershipSpawnPositionZ]);
			cache_get_value_float(i, "spawnpositiona", dealershipInfo[dealershipid][dealershipSpawnPositionA]);

			cache_get_value_int(i, "vehiclemodel0", dealershipInfo[dealershipid][dealershipVehicleModel][0]);
			cache_get_value_int(i, "vehiclemodel1", dealershipInfo[dealershipid][dealershipVehicleModel][1]);
			cache_get_value_int(i, "vehiclemodel2", dealershipInfo[dealershipid][dealershipVehicleModel][2]);
			cache_get_value_int(i, "vehiclemodel3", dealershipInfo[dealershipid][dealershipVehicleModel][3]);
			cache_get_value_int(i, "vehiclemodel4", dealershipInfo[dealershipid][dealershipVehicleModel][4]);
			cache_get_value_int(i, "vehiclemodel5", dealershipInfo[dealershipid][dealershipVehicleModel][5]);
			cache_get_value_int(i, "vehiclemodel6", dealershipInfo[dealershipid][dealershipVehicleModel][6]);
			cache_get_value_int(i, "vehiclemodel7", dealershipInfo[dealershipid][dealershipVehicleModel][7]);
			cache_get_value_int(i, "vehiclemodel8", dealershipInfo[dealershipid][dealershipVehicleModel][8]);
			cache_get_value_int(i, "vehiclemodel9", dealershipInfo[dealershipid][dealershipVehicleModel][9]);

			Iter_Add(Dealership, dealershipid);
            RefreshDealership(dealershipid);

			LoadDealersvipVehPos(dealershipid);

			#if defined DEBUG_MODE
				printf("[Dynamic Dealership] ID: %d Owner: %s Name: %s Money: $%s Price: $%s Position (x: %f y: %f z: %f spawnx: %f spawny: %f spawnz: %f spawna:) Vehicle Model (0: %d 1: %d 2: %d 3: %d 4: %d 5: %d 6: %d 7: %d 8: %d 9: %d)", dealershipid, dealershipInfo[dealershipid][dealershipOwner], dealershipInfo[dealershipid][dealershipName], FormatMoney(dealershipInfo[dealershipid][dealershipMoney]), FormatMoney(dealershipInfo[dealershipid][dealershipPrice]),  dealershipInfo[dealershipid][dealershipPositionX], dealershipInfo[dealershipid][dealershipPositionY], dealershipInfo[dealershipid][dealershipPositionZ], dealershipInfo[dealershipid][dealershipSpawnPositionX], dealershipInfo[dealershipid][dealershipSpawnPositionY], dealershipInfo[dealershipid][dealershipSpawnPositionZ], dealershipInfo[dealershipid][dealershipSpawnPositionA], dealershipInfo[dealershipid][dealershipVehicleModel][0], dealershipInfo[dealershipid][dealershipVehicleModel][1], dealershipInfo[dealershipid][dealershipVehicleModel][2], dealershipInfo[dealershipid][dealershipVehicleModel][3], dealershipInfo[dealershipid][dealershipVehicleModel][4], dealershipInfo[dealershipid][dealershipVehicleModel][5], dealershipInfo[dealershipid][dealershipVehicleModel][6], dealershipInfo[dealershipid][dealershipVehicleModel][7], dealershipInfo[dealershipid][dealershipVehicleModel][8], dealershipInfo[dealershipid][dealershipVehicleModel][9]);
			#endif
		}
	}
    return 1;
}