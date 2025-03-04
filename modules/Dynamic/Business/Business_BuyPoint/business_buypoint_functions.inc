stock CreateBusinessBuyPoint(businessid, interior, world, Float:x, Float:y, Float:z) 
{
    new buypointid = -1;

    buypointid = GetBusinessFreeBuyPoint(businessid);
    if(buypointid == -1) return 1;

    businessbuypointInfo[businessid][buypointid][businessbuypointInterior] = interior;
    businessbuypointInfo[businessid][buypointid][businessbuypointWorld] = world;
    businessbuypointInfo[businessid][buypointid][businessbuypointPositionX] = x;
    businessbuypointInfo[businessid][buypointid][businessbuypointPositionY] = y;
    businessbuypointInfo[businessid][buypointid][businessbuypointPositionZ] = z;

    businessbuypointInfo[businessid][buypointid][businessbuypointExist] = true;
    RefreshBusinessBuyPoint(businessid, buypointid);

    new query[1000];
    mysql_format(sql, query, sizeof(query), "INSERT INTO `business_buypoints` (`businessid`, `position_x`, `position_y`, `position_z`, `interior`, `world`) VALUES ('%d', '%f', '%f', '%f', '%d', '%d')", businessid, x, y, z, interior, world);
    mysql_tquery(sql, query, "OnBusinessBuypointCreate", "dd", businessid, buypointid);
    return buypointid;
}

stock DeleteBusinessBuyPoint(businessid, buypointid) 
{
    if(businessbuypointInfo[businessid][buypointid][businessbuypointExist] == false) return 1;

    businessbuypointInfo[businessid][buypointid][businessbuypointExist] = false;
    
    if(IsValidDynamic3DTextLabel(businessbuypointInfo[businessid][buypointid][businessbuypointLabel]))
        DestroyDynamic3DTextLabel(businessbuypointInfo[businessid][buypointid][businessbuypointLabel]);

    if(IsValidDynamicPickup(businessbuypointInfo[businessid][buypointid][businessbuypointPickup]))
        DestroyDynamicPickup(businessbuypointInfo[businessid][buypointid][businessbuypointPickup]);

    new query[500];
    mysql_format(sql, query, sizeof(query), "DELETE FROM `business_buypoints` WHERE `id` = '%d'", businessbuypointInfo[businessid][buypointid][businessbuypointDBID]);
    mysql_tquery(sql, query);

    LoadBusinessBuyPoint(businessid);
    return 1;
}

stock RefreshBusinessBuyPoint(businessid, buypointid)
{
    if(IsValidDynamic3DTextLabel(businessbuypointInfo[businessid][buypointid][businessbuypointLabel]))
        DestroyDynamic3DTextLabel(businessbuypointInfo[businessid][buypointid][businessbuypointLabel]);

    if(IsValidDynamicPickup(businessbuypointInfo[businessid][buypointid][businessbuypointPickup]))
        DestroyDynamicPickup(businessbuypointInfo[businessid][buypointid][businessbuypointPickup]);

    new label[500];
    format(label, sizeof(label), ""LB"[Business Buy Point: %d]"WHITE"\n"WHITE"Gunakan "YELLOW"'/buy'"WHITE" untuk membeli", buypointid);
    businessbuypointInfo[businessid][buypointid][businessbuypointLabel] = CreateDynamic3DTextLabel(label, COLOR_WHITE, businessbuypointInfo[businessid][buypointid][businessbuypointPositionX], businessbuypointInfo[businessid][buypointid][businessbuypointPositionY], businessbuypointInfo[businessid][buypointid][businessbuypointPositionZ] + 0.3, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, businessbuypointInfo[businessid][buypointid][businessbuypointWorld], businessbuypointInfo[businessid][buypointid][businessbuypointInterior]);
    businessbuypointInfo[businessid][buypointid][businessbuypointPickup] = CreateDynamicPickup(1239, 23, businessbuypointInfo[businessid][buypointid][businessbuypointPositionX], businessbuypointInfo[businessid][buypointid][businessbuypointPositionY], businessbuypointInfo[businessid][buypointid][businessbuypointPositionZ], businessbuypointInfo[businessid][buypointid][businessbuypointWorld], businessbuypointInfo[businessid][buypointid][businessbuypointInterior], -1);
    return 1;
}

stock GetBusinessFreeBuyPoint(businessid) 
{
    new id = -1;
    Loop(i, MAX_BUSINESS_BUYPOINT) 
    {
        if(businessbuypointInfo[businessid][i][businessbuypointExist] == false) 
        {
            id = i;
            break;
        }
        else 
        {
            id = -1;
        }
    }
    return id;
}

stock ResetBusinessBuyPoint(businessid, bool:database_juga = false) 
{
    Loop(i, MAX_BUSINESS_BUYPOINT)
    {
        businessbuypointInfo[businessid][i][businessbuypointExist] = false;
    }

    if(database_juga == true) 
    {
        new query[500];
        mysql_format(sql, query, sizeof(query), "DELETE FROM `business_buypoints` WHERE `businessid` = '%d'", businessid);
        mysql_tquery(sql, query);
    }
    return 1;
}

stock LoadBusinessBuyPoint(businessid) 
{
    ResetBusinessBuyPoint(businessid);

    new query[500];
    mysql_format(sql, query, sizeof(query), "SELECT * FROM `business_buypoints` WHERE `businessid` = '%d'", businessid);
    mysql_tquery(sql, query, "AssignBusinessBuyPoint", "d", businessid);
    return 1;
}