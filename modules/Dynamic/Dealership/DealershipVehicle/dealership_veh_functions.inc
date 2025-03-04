stock MakeDealershipVehPos(dealershipid, Float:x, Float:y, Float:z, Float:a) 
{
    new dealervehposid = GetDealershipVehPosFreeSlot(dealershipid);
    if(dealervehposid == -1) return 1;

    dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposExist] = true;
    dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPositionX] = x;
    dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPositionY] = y;
    dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPositionZ] = z;
    dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPositionA] = a;
    dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel] = -1;
    dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPrice] = 0;

    new query[1000];
    mysql_format(sql, query, sizeof(query), "INSERT INTO `dealership_vehpos` (`model`, `price`, `positionx`, `positiony`, `positionz`, `positiona`) VALUES ('%d', '%d', '%f', '%f', '%f', '%f')", dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel], dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPrice], dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPositionX], dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPositionY], dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPositionZ], dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPositionA]);
    mysql_tquery(sql, query, "OnDealershipVehPosCreated", "dd", dealershipid, dealervehposid);
    return 1;
}

stock DeleteDealershipVehPos(dealershipid, dealervehposid)
{
    if(IsValidVehicle(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposID]))
        DestroyVehicle(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposID]);
    
    if(IsValidDynamicPickup(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPickup]))
        DestroyDynamicPickup(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPickup]);

    if(IsValidDynamic3DTextLabel(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposLabel]))
        DestroyDynamic3DTextLabel(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposLabel]);

    dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposExist] = false;

    new query[64];
    mysql_format(sql, query, sizeof(query), "DELETE FROM `dealership_vehpos` WHERE `id` = '%d'", dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposDBID]);
    mysql_tquery(sql, query);

    LoadDealersvipVehPos(dealershipid);
    return 1;
}

stock ResetDealershipVehPos(dealershipid, bool:indatabasetoo = false) 
{
    Loop(i, MAX_DEALERSHIP_VEHPOS)
    {
        if(IsValidVehicle(dealershipvehposInfo[dealershipid][i][dealershipvehposID]))
        DestroyVehicle(dealershipvehposInfo[dealershipid][i][dealershipvehposID]);
    
        if(IsValidDynamicPickup(dealershipvehposInfo[dealershipid][i][dealershipvehposPickup]))
            DestroyDynamicPickup(dealershipvehposInfo[dealershipid][i][dealershipvehposPickup]);

        if(IsValidDynamic3DTextLabel(dealershipvehposInfo[dealershipid][i][dealershipvehposLabel]))
            DestroyDynamic3DTextLabel(dealershipvehposInfo[dealershipid][i][dealershipvehposLabel]);

        dealershipvehposInfo[dealershipid][i][dealershipvehposExist] = false;
    }

    if(indatabasetoo == true) 
    {
        new query[64];
        mysql_format(sql, query, sizeof(query), "DELETE FROM `dealership_vehpos` WHERE `dealershipid` = '%d'", dealershipid);
        mysql_tquery(sql, query);
    }
    return 1;
}

stock LoadDealersvipVehPos(dealershipid)
{
    ResetDealershipVehPos(dealershipid);

    new query[500];
    mysql_format(sql, query, sizeof(query), "SELECT * FROM `dealership_vehpos` WHERE `dealershipid` = '%d'", dealershipid);
    mysql_tquery(sql, query, "AssignDealershipVehPos", "d", dealershipid);
    return 1;
}

stock GetDealershipVehPosFreeSlot(dealershipid) 
{
    new slot = -1;
    Loop(i, MAX_DEALERSHIP_VEHPOS) {
        if(dealershipvehposInfo[dealershipid][i][dealershipvehposExist] == false) {
            slot = i;
            break;
        }
    }
    return slot;
}

stock RefreshDealershipVehPos(dealershipid, dealervehposid) 
{
    if(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposExist] == false) return 1;
    
    if(IsValidDynamicPickup(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPickup]))
        DestroyDynamicPickup(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPickup]);

    if(IsValidDynamic3DTextLabel(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposLabel]))
        DestroyDynamic3DTextLabel(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposLabel]);

    if(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel] != -1)
    {
        if(IsValidVehicle(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposID]))
            DestroyVehicle(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposID]);
            
        new color1, color2;
        GetVehicleRandomColors(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel], color1, color2);
        dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposID] = CreateVehicle(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel], dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPositionX], dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPositionY], dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPositionZ], dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPositionA], color1, color2, -1, false);

        new idstr[15];
        format(idstr, sizeof(idstr), "%d|%d", dealershipid, dealervehposid);
        SetVehicleOwner(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposID], VEHICLE_OWNER_DEALERSHIP, idstr);

        new label[500], Float:vehicle_maxfuel;
        GetVehicleMaxFuel(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposID], vehicle_maxfuel);
        format(label, sizeof(label), ""YELLOW"%s\n"WHITE"Harga: "LG"$%s\n"GREY"Top Speed: %.0f KM/Jam\n"GREY"Bahan Bakar: %.0f", GetVehicleModelName(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel]), FormatMoney(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPrice]), GetVehicleModelTopSpeed(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel]), vehicle_maxfuel);
        dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposLabel] = CreateDynamic3DTextLabel(label, COLOR_REN, dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPositionX], dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPositionY], dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPositionZ], 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0);
    }
    else
    {
        if(IsValidVehicle(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposID]))
            DestroyVehicle(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposID]);

        dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPickup] = CreateDynamicPickup(1239, 23, dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPositionX], dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPositionY], dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPositionZ], 0, 0);

        new label[500];
        format(label, sizeof(label), ""LB"[DID: %d ID: %d]\n"LG"Model kendaraan pada tampilan ini kosong!\n"WHITE"Gunakan "YELLOW"/dm > cars"WHITE" untuk mengaturnya", dealershipid, dealervehposid);
        dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposLabel] = CreateDynamic3DTextLabel(label, COLOR_REN, dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPositionX], dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPositionY], dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPositionZ], 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0);
    }
    return 1;
}