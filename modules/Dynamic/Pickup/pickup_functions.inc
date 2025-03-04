stock MakePickup(model, type, Float:x, Float:y, Float:z, world, interior) 
{
    new pickupid = Iter_Free(Pickup);
    if(pickupid == cellmax) return 1;

    pickupInfo[pickupid][pickupModel] = model;
    pickupInfo[pickupid][pickupType] = type;
    pickupInfo[pickupid][pickupPositionX] = x;
    pickupInfo[pickupid][pickupPositionY] = y;
    pickupInfo[pickupid][pickupPositionZ] = z;
    pickupInfo[pickupid][pickupWorld] = world;
    pickupInfo[pickupid][pickupInterior] = interior;

    new query[500];
    mysql_format(sql, query, sizeof query, "INSERT INTO `pickups` (`id`, `model`, `type`, `x`, `y`, `z`, `world`, `interior`) VALUES ('%d', '%d', '%d', '%f', '%f', '%f', '%d', '%d')", pickupid, model, type, x, y, z, world, interior);
    mysql_tquery(sql, query);

    Iter_Add(Pickup, pickupid);
    RefreshPickup(pickupid);
    return pickupid;
}

stock RefreshPickup(pickupid) 
{
    if(!Iter_Contains(Pickup, pickupid)) return 1;

    if(IsValidDynamicPickup(pickupInfo[pickupid][pickupID]))
        DestroyDynamicPickup(pickupInfo[pickupid][pickupID]);

    if(IsValidDynamic3DTextLabel(pickupInfo[pickupid][pickupLabel]))
        DestroyDynamic3DTextLabel(pickupInfo[pickupid][pickupLabel]);

    new label[1200];
    format(label, sizeof(label), ""LB"[ID: %d]\n"YELLOW"%s\n"WHITE"%s", pickupid, e_pickupinfo[pickupInfo[pickupid][pickupType]][e_pickupname], e_pickupinfo[pickupInfo[pickupid][pickupType]][e_pickupdescription]);
    pickupInfo[pickupid][pickupLabel] = CreateDynamic3DTextLabel(label, COLOR_WHITE, pickupInfo[pickupid][pickupPositionX], pickupInfo[pickupid][pickupPositionY], pickupInfo[pickupid][pickupPositionZ] + 0.5, 5.0);
    pickupInfo[pickupid][pickupID] = CreateDynamicPickup(pickupInfo[pickupid][pickupModel], 23, pickupInfo[pickupid][pickupPositionX], pickupInfo[pickupid][pickupPositionY], pickupInfo[pickupid][pickupPositionZ], pickupInfo[pickupid][pickupWorld], pickupInfo[pickupid][pickupInterior]);
    return 1;
}

stock IsPlayerInPickup(playerid, pickuptype)
{
    new bool:status = false;
    foreach(new i : Pickup) 
    {
        if(pickupInfo[i][pickupType] == pickuptype && IsPlayerInRangeOfPoint(playerid, 2.0, pickupInfo[i][pickupPositionX], pickupInfo[i][pickupPositionY], pickupInfo[i][pickupPositionZ]))
        {
            status = true;
            break;
        } else status = false;
    }
    return status;
}

stock DeletePickup(pickupid) 
{
    if(!Iter_Contains(Pickup, pickupid)) return 1;

    if(IsValidDynamicPickup(pickupInfo[pickupid][pickupID]))
        DestroyDynamicPickup(pickupInfo[pickupid][pickupID]);

    if(IsValidDynamic3DTextLabel(pickupInfo[pickupid][pickupLabel]))
        DestroyDynamic3DTextLabel(pickupInfo[pickupid][pickupLabel]);

    new query[64];
    mysql_format(sql, query, sizeof(query), "DELETE FROM `pickups` WHERE `id` = '%d'", pickupid);
    mysql_tquery(sql, query);

    Iter_Remove(Pickup, pickupid);
    return 1;
}

stock LoadPickups()
{
    mysql_tquery(sql, "SELECT * FROM `pickups`", "AssignPickupData");
    return 1;
}

function AssignPickupData() 
{
    static pickupid;
	new rows  = cache_num_rows();
    if(rows)
    {
		for(new i; i < rows; i++)
		{
            cache_get_value_int(i, "id", pickupid);
            cache_get_value_int(i, "model", pickupInfo[pickupid][pickupModel]);
            cache_get_value_int(i, "type", pickupInfo[pickupid][pickupType]);
            cache_get_value_float(i, "x", pickupInfo[pickupid][pickupPositionX]);
            cache_get_value_float(i, "y", pickupInfo[pickupid][pickupPositionY]);
            cache_get_value_float(i, "z", pickupInfo[pickupid][pickupPositionZ]);
            cache_get_value_int(i, "world", pickupInfo[pickupid][pickupWorld]);
            cache_get_value_int(i, "interior", pickupInfo[pickupid][pickupInterior]);

            Iter_Add(Pickup, pickupid);
            RefreshPickup(pickupid);

            #if defined DEBUG_MODE
                printf("[Dynamic Pickup] ID: %d Model: %d Type: %d position (x: %f y: %f z: %f) World ID: %d Interior ID: %d", pickupid, pickupInfo[pickupid][pickupModel], pickupInfo[pickupid][pickupType], pickupInfo[pickupid][pickupPositionX], pickupInfo[pickupid][pickupPositionY], pickupInfo[pickupid][pickupPositionZ], pickupInfo[pickupid][pickupWorld], pickupInfo[pickupid][pickupInterior]);
            #endif
        }
    }
    return 1;
}