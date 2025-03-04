stock CreateGasPump(Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, world, interior)
{
    new gaspumpid = -1;
    gaspumpid = Iter_Free(GasPump);

    if(gaspumpid == -1) return gaspumpid;

    gaspumpInfo[gaspumpid][gaspumpBusinessID] = -1;
    gaspumpInfo[gaspumpid][gaspumpPositionX] = x;
    gaspumpInfo[gaspumpid][gaspumpPositionY] = y;
    gaspumpInfo[gaspumpid][gaspumpPositionZ] = z;
    gaspumpInfo[gaspumpid][gaspumpRotationX] = rx;
    gaspumpInfo[gaspumpid][gaspumpRotationY] = ry;
    gaspumpInfo[gaspumpid][gaspumpRotationZ] = rz;
    gaspumpInfo[gaspumpid][gaspumpWorld] = world;
    gaspumpInfo[gaspumpid][gaspumpInterior] = interior;
    
    new query[500];
    mysql_format(sql, query, sizeof(query), "INSERT INTO `gaspumps`(`id`) VALUES ('%d')", gaspumpid);
    mysql_tquery(sql, query);

    Iter_Add(GasPump, gaspumpid);
    RefreshGasPump(gaspumpid);
    return gaspumpid;
}

stock RefreshGasPump(gaspumpid)
{
    if(!Iter_Contains(GasPump, gaspumpid)) return 1;

    if(IsValidDynamicObject(gaspumpInfo[gaspumpid][gaspumpObject])) SetDynamicObjectPos(gaspumpInfo[gaspumpid][gaspumpObject], gaspumpInfo[gaspumpid][gaspumpPositionX], gaspumpInfo[gaspumpid][gaspumpPositionY], gaspumpInfo[gaspumpid][gaspumpPositionZ]), SetDynamicObjectRot(gaspumpInfo[gaspumpid][gaspumpObject], gaspumpInfo[gaspumpid][gaspumpRotationX], gaspumpInfo[gaspumpid][gaspumpRotationY], gaspumpInfo[gaspumpid][gaspumpRotationZ]);
    else gaspumpInfo[gaspumpid][gaspumpObject] = CreateDynamicObject(3465, gaspumpInfo[gaspumpid][gaspumpPositionX], gaspumpInfo[gaspumpid][gaspumpPositionY], gaspumpInfo[gaspumpid][gaspumpPositionZ], gaspumpInfo[gaspumpid][gaspumpRotationX], gaspumpInfo[gaspumpid][gaspumpRotationY], gaspumpInfo[gaspumpid][gaspumpRotationZ], gaspumpInfo[gaspumpid][gaspumpWorld], gaspumpInfo[gaspumpid][gaspumpInterior]);

    if(IsValidDynamic3DTextLabel(gaspumpInfo[gaspumpid][gaspumpLabel])) DestroyDynamic3DTextLabel(gaspumpInfo[gaspumpid][gaspumpLabel]);

    new message[2000];
    format(message, sizeof(message), "Gas Pump\n(( Tekan ~k~~CONVERSATION_NO~ untuk menggunakan ))");
    gaspumpInfo[gaspumpid][gaspumpLabel] = CreateDynamic3DTextLabel(message, COLOR_GREY, gaspumpInfo[gaspumpid][gaspumpPositionX], gaspumpInfo[gaspumpid][gaspumpPositionY], gaspumpInfo[gaspumpid][gaspumpPositionZ] + 0.5, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, gaspumpInfo[gaspumpid][gaspumpWorld], gaspumpInfo[gaspumpid][gaspumpInterior]);
    
    UpdateGasPumpData(gaspumpid);
    return 1;
}

stock ConnectGasPumpBusiness(gaspumpid, businessid)
{
    if(!Iter_Contains(GasPump, gaspumpid) || !Iter_Contains(Business, businessid)) return 1;

    gaspumpInfo[gaspumpid][gaspumpBusinessID] = businessid;
    RefreshGasPump(gaspumpid);
    return 1;
}

stock DeleteGasPump(gaspumpid)
{
    if(!Iter_Contains(GasPump, gaspumpid)) return 1;
    Iter_Remove(GasPump, gaspumpid);

    if(IsValidDynamicObject(gaspumpInfo[gaspumpid][gaspumpObject])) DestroyDynamicObject(gaspumpInfo[gaspumpid][gaspumpObject]);
    if(IsValidDynamic3DTextLabel(gaspumpInfo[gaspumpid][gaspumpLabel])) DestroyDynamic3DTextLabel(gaspumpInfo[gaspumpid][gaspumpLabel]);
    
    new query[900];
	mysql_format(sql, query, sizeof(query), "DELETE FROM `gaspumps` WHERE `id` = '%d'", gaspumpid);
	mysql_tquery(sql, query);
    return 1;
}

stock GetPlayerNearestGasPump(playerid) 
{
    new gaspumpid = -1;
    foreach(new i : GasPump)
    {
        if(Iter_Contains(GasPump, i) && IsPlayerInRangeOfPoint(playerid, 5.0, gaspumpInfo[i][gaspumpPositionX], gaspumpInfo[i][gaspumpPositionY], gaspumpInfo[i][gaspumpPositionZ]) && GetPlayerVirtualWorld(playerid) == gaspumpInfo[i][gaspumpWorld] && GetPlayerInterior(playerid) == gaspumpInfo[i][gaspumpInterior])
        {
            gaspumpid = i;
            break;
        }
    }
    return gaspumpid;
}

stock IsBusinessHaveGasPump(businessid) 
{
    new bool:status = false;
    foreach(new i : GasPump) 
    {
        if(Iter_Contains(GasPump, i) && gaspumpInfo[i][gaspumpBusinessID] == businessid) 
        {
            status = true;
            break;
        }
    }
    return status;
}

stock UpdateGasPumpData(gaspumpid) 
{
    if(!Iter_Contains(GasPump, gaspumpid)) return 1;

    new fetchChars[3060];  
    mysql_format(sql, fetchChars, sizeof(fetchChars), "UPDATE `gaspumps` SET");
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `businessid` = '%d', ", fetchChars, gaspumpInfo[gaspumpid][gaspumpBusinessID]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `positionx` = '%f', ", fetchChars, gaspumpInfo[gaspumpid][gaspumpPositionX]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `positiony` = '%f', ", fetchChars, gaspumpInfo[gaspumpid][gaspumpPositionY]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `positionz` = '%f', ", fetchChars, gaspumpInfo[gaspumpid][gaspumpPositionZ]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `rotationx` = '%f', ", fetchChars, gaspumpInfo[gaspumpid][gaspumpRotationX]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `rotationy` = '%f', ", fetchChars, gaspumpInfo[gaspumpid][gaspumpRotationY]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `rotationz` = '%f', ", fetchChars, gaspumpInfo[gaspumpid][gaspumpRotationZ]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `world` = '%d', ", fetchChars, gaspumpInfo[gaspumpid][gaspumpWorld]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `interior` = '%d' WHERE `id` = '%d'", fetchChars, gaspumpInfo[gaspumpid][gaspumpInterior], gaspumpid);
    mysql_tquery(sql, fetchChars);
    return 1;
}

function AssignGasPumpData()
{
    static gaspumpid;
    new rows;
    rows = cache_num_rows();
    if(rows)
    {
        for(new i = 0; i < rows; i++)
        {
            cache_get_value_int(i, "id", gaspumpid);
            cache_get_value_int(i, "businessid", gaspumpInfo[gaspumpid][gaspumpBusinessID]);
            cache_get_value_float(i, "positionx", gaspumpInfo[gaspumpid][gaspumpPositionX]);
            cache_get_value_float(i, "positiony", gaspumpInfo[gaspumpid][gaspumpPositionY]);
            cache_get_value_float(i, "positionz", gaspumpInfo[gaspumpid][gaspumpPositionZ]);
            cache_get_value_float(i, "rotationx", gaspumpInfo[gaspumpid][gaspumpRotationX]);
            cache_get_value_float(i, "rotationy", gaspumpInfo[gaspumpid][gaspumpRotationY]);
            cache_get_value_float(i, "rotationz", gaspumpInfo[gaspumpid][gaspumpRotationZ]);
            cache_get_value_int(i, "world", gaspumpInfo[gaspumpid][gaspumpWorld]);
            cache_get_value_int(i, "interior", gaspumpInfo[gaspumpid][gaspumpInterior]);

            Iter_Add(GasPump, gaspumpid);
            RefreshGasPump(gaspumpid);

            #if defined DEBUG_MODE
                printf("[Dynamic Gas Pump] Business ID: %d ID: %d position (x: %f y: %f z: %f rx: %f ry: %f rz: %f) World ID: %d Interior ID: %d", gaspumpInfo[gaspumpid][gaspumpBusinessID], gaspumpid, gaspumpInfo[gaspumpid][gaspumpPositionX], gaspumpInfo[gaspumpid][gaspumpPositionY], gaspumpInfo[gaspumpid][gaspumpPositionZ], gaspumpInfo[gaspumpid][gaspumpRotationX], gaspumpInfo[gaspumpid][gaspumpRotationY], gaspumpInfo[gaspumpid][gaspumpRotationZ], gaspumpInfo[gaspumpid][gaspumpWorld], gaspumpInfo[gaspumpid][gaspumpInterior]);
            #endif
        }
    }
    return 1;
}