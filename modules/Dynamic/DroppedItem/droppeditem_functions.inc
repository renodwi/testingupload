/* 

-> Dropped Item
Commands: /createdroppeditem /deletedroppeditem
Functions: Digunakan untuk membuat item yang dijatuhkan dan menghapus item yang dijatuhkan

*/
stock CreateDroppedItem(type, amount, Float:x, Float:y, Float:z, Float:angle, world, interior)
{
    new droppeditemid = Iter_Free(DroppedItem);
    if(droppeditemid == -1) return 1;

    droppeditemInfo[droppeditemid][droppeditemType] = type;
    droppeditemInfo[droppeditemid][droppeditemPositionX] = x;
    droppeditemInfo[droppeditemid][droppeditemPositionY] = y;
    droppeditemInfo[droppeditemid][droppeditemPositionZ] = z;
    droppeditemInfo[droppeditemid][droppeditemAngle] = angle;
    droppeditemInfo[droppeditemid][droppeditemWorld] = world;
    droppeditemInfo[droppeditemid][droppeditemInterior] = interior;
    droppeditemInfo[droppeditemid][droppeditemAmount] = amount;

    droppeditemInfo[droppeditemid][droppeditemDeletedAt] = Now() + Timestamp:36000;

    Iter_Add(DroppedItem, droppeditemid);

    new query[500];
    mysql_format(sql, query, sizeof(query), "INSERT INTO `droppeditems` (`id`) VALUE ('%d')", droppeditemid);
    mysql_tquery(sql, query, "OnDroppedItemCreate", "d", droppeditemid);

    RefreshDroppedItem(droppeditemid);
    return droppeditemid;
}

stock RefreshDroppedItem(droppeditemid) 
{
    if(!Iter_Contains(DroppedItem, droppeditemid)) return 1;

    if(IsValidDynamic3DTextLabel(droppeditemInfo[droppeditemid][droppeditemLabel]))
        DestroyDynamic3DTextLabel(droppeditemInfo[droppeditemid][droppeditemLabel]);
        
    if(IsValidDynamicObject(droppeditemInfo[droppeditemid][droppeditemObject]))
        DestroyDynamicObject(droppeditemInfo[droppeditemid][droppeditemObject]);

    new message[1000];
    format(message, sizeof(message), "[ID: %d]\n%s (%d %s)\n%s\n((Otomatis dihapus dalam %s))\nTekan ~k~~CONVERSATION_YES~ atau gunakan /takeitem", droppeditemid, GetItemName(GetItemIDByType(droppeditemInfo[droppeditemid][droppeditemType])), droppeditemInfo[droppeditemid][droppeditemAmount], GetItemUnitName(GetItemIDByType(droppeditemInfo[droppeditemid][droppeditemType])), GetItemDescription(GetItemIDByType(droppeditemInfo[droppeditemid][droppeditemType])), TimestampToTimeString(droppeditemInfo[droppeditemid][droppeditemDeletedAt]));
    droppeditemInfo[droppeditemid][droppeditemLabel] = CreateDynamic3DTextLabel(message, COLOR_GREY, droppeditemInfo[droppeditemid][droppeditemPositionX], droppeditemInfo[droppeditemid][droppeditemPositionY], droppeditemInfo[droppeditemid][droppeditemPositionZ] - 1.0, 1.5, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, droppeditemInfo[droppeditemid][droppeditemWorld], droppeditemInfo[droppeditemid][droppeditemInterior], -1);
    droppeditemInfo[droppeditemid][droppeditemObject] = CreateDynamicObject(GetItemModel(GetItemIDByType(droppeditemInfo[droppeditemid][droppeditemType])), droppeditemInfo[droppeditemid][droppeditemPositionX], droppeditemInfo[droppeditemid][droppeditemPositionY], droppeditemInfo[droppeditemid][droppeditemPositionZ] - 1.0, 0.0, 0.0, droppeditemInfo[droppeditemid][droppeditemAngle], droppeditemInfo[droppeditemid][droppeditemWorld], droppeditemInfo[droppeditemid][droppeditemInterior], -1);

    UpdateDroppedItemData(droppeditemid);
    return 1;
}

stock DeleteDroppedItem(droppeditemid) 
{
    if(!Iter_Contains(DroppedItem, droppeditemid)) return 1;

    if(IsValidDynamic3DTextLabel(droppeditemInfo[droppeditemid][droppeditemLabel]))
        DestroyDynamic3DTextLabel(droppeditemInfo[droppeditemid][droppeditemLabel]);
        
    if(IsValidDynamicObject(droppeditemInfo[droppeditemid][droppeditemObject]))
        DestroyDynamicObject(droppeditemInfo[droppeditemid][droppeditemObject]);

    new query[500];
    mysql_format(sql, query, sizeof(query), "DELETE FROM `droppeditems` WHERE `id` = '%d'", droppeditemid);
    mysql_tquery(sql, query);

    Iter_Remove(DroppedItem, droppeditemid);
    return 1;
}

function AssignDroppedItemData()
{
    static droppeditemid;

	new rows  = cache_num_rows();
 	if(rows)
  	{
		for(new i; i < rows; i++)
		{
            cache_get_value_int(i, "id", droppeditemid);
            cache_get_value_int(i, "type", droppeditemInfo[droppeditemid][droppeditemType]);
            cache_get_value_int(i, "interior", droppeditemInfo[droppeditemid][droppeditemInterior]);
            cache_get_value_int(i, "world", droppeditemInfo[droppeditemid][droppeditemWorld]);
            cache_get_value_int(i, "deletedat", _:droppeditemInfo[droppeditemid][droppeditemDeletedAt]);
            cache_get_value_int(i, "amount", droppeditemInfo[droppeditemid][droppeditemAmount]);
            cache_get_value_float(i, "positionx", droppeditemInfo[droppeditemid][droppeditemPositionX]);
            cache_get_value_float(i, "positiony", droppeditemInfo[droppeditemid][droppeditemPositionY]);
            cache_get_value_float(i, "positionz", droppeditemInfo[droppeditemid][droppeditemPositionZ]);
            cache_get_value_float(i, "angle", droppeditemInfo[droppeditemid][droppeditemAngle]);
            
            Iter_Add(DroppedItem, droppeditemid);
            RefreshDroppedItem(droppeditemid);

            #if defined DEBUG_MODE
                printf("[Dynamic DroppedItem] ID: %d Type: %d Interior ID: %d World ID: %d Delete At: %s (%s) Amount: %d position (X: %f y: %f z: %f a: %f)", droppeditemid, droppeditemInfo[droppeditemid][droppeditemType], droppeditemInfo[droppeditemid][droppeditemInterior], droppeditemInfo[droppeditemid][droppeditemWorld], TimestampToDateString(droppeditemInfo[droppeditemid][droppeditemDeletedAt]), TimestampToTimeString(droppeditemInfo[droppeditemid][droppeditemDeletedAt]), droppeditemInfo[droppeditemid][droppeditemAmount], droppeditemInfo[droppeditemid][droppeditemPositionX], droppeditemInfo[droppeditemid][droppeditemPositionY], droppeditemInfo[droppeditemid][droppeditemPositionZ], droppeditemInfo[droppeditemid][droppeditemAngle]);
            #endif
		}
	}
    return 1;
}

stock UpdateDroppedItemData(droppeditemid) 
{
    new cQuery[3048];
    mysql_format(sql, cQuery, sizeof(cQuery), "UPDATE `droppeditems` SET ");
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`type` = '%d', ", cQuery, droppeditemInfo[droppeditemid][droppeditemType]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`positionx` = '%f', ", cQuery, droppeditemInfo[droppeditemid][droppeditemPositionX]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`positiony` = '%f', ", cQuery, droppeditemInfo[droppeditemid][droppeditemPositionY]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`positionz` = '%f', ", cQuery, droppeditemInfo[droppeditemid][droppeditemPositionZ]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`angle` = '%f', ", cQuery, droppeditemInfo[droppeditemid][droppeditemAngle]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`interior` = '%d', ", cQuery, droppeditemInfo[droppeditemid][droppeditemInterior]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`world` = '%d', ", cQuery, droppeditemInfo[droppeditemid][droppeditemWorld]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`deletedat` = '%d', ", cQuery, _:droppeditemInfo[droppeditemid][droppeditemDeletedAt]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`amount` = '%d' WHERE `id` = '%d'", cQuery, droppeditemInfo[droppeditemid][droppeditemAmount], droppeditemid);
	mysql_tquery(sql, cQuery);
	return 1;
}

stock GetNearestDroppedItem(playerid)
{
    new droppeditemid = -1;
    foreach(new i : DroppedItem) 
    {
        if(IsPlayerInRangeOfPoint(playerid, 1.5, droppeditemInfo[i][droppeditemPositionX], droppeditemInfo[i][droppeditemPositionY], droppeditemInfo[i][droppeditemPositionZ]))
        {
            droppeditemid = i;
            break;
        }
    }
    return droppeditemid;
}

stock GetDroppedItemType(droppeditemid)
{
    new type = -1;
    if(!Iter_Contains(DroppedItem, droppeditemid)) type = -1;
    else 
    {
        type = droppeditemInfo[droppeditemid][droppeditemType];
    }
    return type;
}

stock GetDroppedItemAmount(droppeditemid)
{
    new amount = -1;
    if(!Iter_Contains(DroppedItem, droppeditemid)) amount = -1;
    else 
    {
        amount = droppeditemInfo[droppeditemid][droppeditemAmount];
    }
    return amount;
}

stock SetDroppedItemAmount(droppeditemid, amount)
{
    if(!Iter_Contains(DroppedItem, droppeditemid)) return 1;
    droppeditemInfo[droppeditemid][droppeditemAmount] = amount;
    UpdateDroppedItemData(droppeditemid);
    return 1;
}