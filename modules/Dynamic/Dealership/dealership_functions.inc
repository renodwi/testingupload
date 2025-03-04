stock MakeDealership(const owner[], const name[], price, Float:x, Float:y, Float:z) 
{
    new dealershipid = -1;
    dealershipid = Iter_Free(Dealership);
    if(dealershipid == cellmax) return -1;
    
    Iter_Add(Dealership, dealershipid);

    format(dealershipInfo[dealershipid][dealershipOwner], MAX_PLAYER_NAME, owner);
    format(dealershipInfo[dealershipid][dealershipName], MAX_DEALERSHIP_NAME, name);
    dealershipInfo[dealershipid][dealershipMoney] = 0;
    dealershipInfo[dealershipid][dealershipPrice] = price;
    dealershipInfo[dealershipid][dealershipLocked] = true;
    dealershipInfo[dealershipid][dealershipPositionX] = x;
    dealershipInfo[dealershipid][dealershipPositionY] = y;
    dealershipInfo[dealershipid][dealershipPositionZ] = z;
    
    Loop(i, MAX_DEALERSHIP_VEHICLEMODEL)
    {
        dealershipInfo[dealershipid][dealershipVehicleModel][i] = -1;
    }

    new query[200];
    mysql_format(sql, query, sizeof(query), "INSERT INTO `dealership` (`id`) VALUES ('%d')", dealershipid);
    mysql_tquery(sql, query, "OnDealershipCreated", "d", dealershipid);
    return dealershipid;
}

stock DeleteDealership(dealershipid) 
{
    if(!Iter_Contains(Dealership, dealershipid)) return 1;

    if(IsValidDynamicPickup(dealershipInfo[dealershipid][dealershipPickup])) DestroyDynamicPickup(dealershipInfo[dealershipid][dealershipPickup]);
    if(IsValidDynamic3DTextLabel(dealershipInfo[dealershipid][dealershipLabel])) DestroyDynamic3DTextLabel(dealershipInfo[dealershipid][dealershipLabel]);

    new query[64];
    mysql_format(sql, query, sizeof(query), "DELETE FROM `dealership` WHERE `id` = '%d'", dealershipid);
    mysql_tquery(sql, query);

    Iter_Remove(Dealership, dealershipid);
    return 1;
}

stock LoadDealership()
{
    mysql_tquery(sql, "SELECT * FROM `dealership`", "AssignDealershipData");
    return 1;
}

stock UpdateDealershipData(dealershipid) 
{
    new cQuery[3048];
    mysql_format(sql, cQuery, sizeof(cQuery), "UPDATE `dealership` SET ");
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`owner` = '%e', ", cQuery, dealershipInfo[dealershipid][dealershipOwner]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`name` = '%e', ", cQuery, dealershipInfo[dealershipid][dealershipName]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`money` = '%d', ", cQuery, dealershipInfo[dealershipid][dealershipMoney]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`price` = '%d', ", cQuery, dealershipInfo[dealershipid][dealershipPrice]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`locked` = '%d', ", cQuery, dealershipInfo[dealershipid][dealershipLocked]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`positionx` = '%f', ", cQuery, dealershipInfo[dealershipid][dealershipPositionX]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`positiony` = '%f', ", cQuery, dealershipInfo[dealershipid][dealershipPositionY]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`positionz` = '%f', ", cQuery, dealershipInfo[dealershipid][dealershipPositionZ]);
    mysql_format(sql, cQuery, sizeof(cQuery), "%s`spawnpositionx` = '%f', ", cQuery, dealershipInfo[dealershipid][dealershipSpawnPositionX]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`spawnpositiony` = '%f', ", cQuery, dealershipInfo[dealershipid][dealershipSpawnPositionY]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`spawnpositionz` = '%f', ", cQuery, dealershipInfo[dealershipid][dealershipSpawnPositionZ]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`spawnpositiona` = '%f', ", cQuery, dealershipInfo[dealershipid][dealershipSpawnPositionA]);
    Loop(i, MAX_DEALERSHIP_VEHICLEMODEL)
    {
        mysql_format(sql, cQuery, sizeof(cQuery), "%s`vehiclemodel%d` = '%d', ", cQuery, i, dealershipInfo[dealershipid][dealershipVehicleModel][i]);
    }
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`id` = '%d' WHERE `id` = '%d'", cQuery, dealershipid, dealershipid);
	mysql_tquery(sql, cQuery);
	return 1;
}

stock RefreshDealership(dealershipid) 
{    
    if(!Iter_Contains(Dealership, dealershipid)) return 1;

    if(IsValidDynamicPickup(dealershipInfo[dealershipid][dealershipPickup])) 
        DestroyDynamicPickup(dealershipInfo[dealershipid][dealershipPickup]);

    if(IsValidDynamic3DTextLabel(dealershipInfo[dealershipid][dealershipLabel])) 
        DestroyDynamic3DTextLabel(dealershipInfo[dealershipid][dealershipLabel]);

    dealershipInfo[dealershipid][dealershipPickup] = CreateDynamicPickup(1239, 23, dealershipInfo[dealershipid][dealershipPositionX], dealershipInfo[dealershipid][dealershipPositionY], dealershipInfo[dealershipid][dealershipPositionZ], 0, 0);

    new label[200];
    format(label, sizeof(label), ""LB"[ID: %d]\n"YELLOW"%s\n"WHITE"Owner: "LG"%s", dealershipid, dealershipInfo[dealershipid][dealershipName], dealershipInfo[dealershipid][dealershipOwner]);
    dealershipInfo[dealershipid][dealershipLabel] = CreateDynamic3DTextLabel(label, COLOR_WHITE, dealershipInfo[dealershipid][dealershipPositionX], dealershipInfo[dealershipid][dealershipPositionY], dealershipInfo[dealershipid][dealershipPositionZ], 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0);
    
    UpdateDealershipData(dealershipid);
    return 1;
}

stock SortDealershipVehicleModel(dealershipid) 
{
    new n = MAX_DEALERSHIP_VEHICLEMODEL, temp;
    for (new i = 0; i < n - 1; i++) {
        for (new j = 0; j < n - i - 1; j++) {
            if (dealershipInfo[dealershipid][dealershipVehicleModel][j] < dealershipInfo[dealershipid][dealershipVehicleModel][j + 1]) {
                // Menukar elemen
                temp = dealershipInfo[dealershipid][dealershipVehicleModel][j];
                dealershipInfo[dealershipid][dealershipVehicleModel][j] = dealershipInfo[dealershipid][dealershipVehicleModel][j + 1];
                dealershipInfo[dealershipid][dealershipVehicleModel][j + 1] = temp;
            }
        }
    }
    return 1;
}