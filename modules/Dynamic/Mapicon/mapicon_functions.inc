stock MakeMapIcon(Float:x, Float:y, Float:z, type, color) 
{
    new mapiconid = -1;
    mapiconid = Iter_Free(MapIcon);
    if(mapiconid == cellmax) return -1;

    mapiconInfo[mapiconid][mapiconPositionX] = x;
    mapiconInfo[mapiconid][mapiconPositionY] = y;
    mapiconInfo[mapiconid][mapiconPositionZ] = z;
    mapiconInfo[mapiconid][mapiconType] = type;
    mapiconInfo[mapiconid][mapiconColor] = color;

    Iter_Add(MapIcon, mapiconid);
    RefreshMapIcon(mapiconid);

    new query[700];
    mysql_format(sql, query, sizeof query, "INSERT INTO `mapicons` (`id`, `x`, `y`, `z`, `type`, `color`) VALUES ('%d', '%f', '%f', '%f', '%d', '%d')", mapiconid, mapiconInfo[mapiconid][mapiconPositionX], mapiconInfo[mapiconid][mapiconPositionY], mapiconInfo[mapiconid][mapiconPositionZ], mapiconInfo[mapiconid][mapiconType], mapiconInfo[mapiconid][mapiconColor]);
    mysql_tquery(sql, query);
    return mapiconid;
}

stock RefreshMapIcon(mapiconid) 
{
    if(!Iter_Contains(MapIcon, mapiconid)) return 1;
    
    if(IsValidDynamicMapIcon(mapiconInfo[mapiconid][mapiconID]))
        DestroyDynamicMapIcon(mapiconInfo[mapiconid][mapiconID]);

    mapiconInfo[mapiconid][mapiconID] = CreateDynamicMapIcon(mapiconInfo[mapiconid][mapiconPositionX], mapiconInfo[mapiconid][mapiconPositionY], mapiconInfo[mapiconid][mapiconPositionZ], mapiconInfo[mapiconid][mapiconType], mapiconInfo[mapiconid][mapiconColor]);
    return 1;
}

stock DeleteMapIcon(mapiconid) 
{
    if(!Iter_Contains(MapIcon, mapiconid)) return 1;
    
    if(IsValidDynamicMapIcon(mapiconInfo[mapiconid][mapiconID]))
        DestroyDynamicMapIcon(mapiconInfo[mapiconid][mapiconID]);

    Iter_Clear(MapIcon);

    new query[64];
    mysql_format(sql, query, sizeof(query), "DELETE FROM `mapicons` WHERE `id` = '%d'", mapiconid);
    mysql_tquery(sql, query);
    return 1;
}

stock LoadMapIcon()
{
    mysql_tquery(sql, "SELECT * FROM `mapicons`", "AssignMapIconData");
    return 1;
}