stock CreateMappingFolder(const name[], const creator[], Timestamp:time, Float:x, Float:y, Float:z) 
{
    new slot;
    slot = Iter_Free(MappingFolder);

    if(slot == cellmax) return -1;

    mappingInfo[slot][mappingLoaded] = false;

    format(mappingInfo[slot][mappingName], MAX_MAPPING_FOLDER_NAME + 1, name);
    format(mappingInfo[slot][mappingCreator], MAX_PLAYER_NAME + 1, creator);
    mappingInfo[slot][mappingCreateAt] = time;
    mappingInfo[slot][mappingLocationX] = x;
    mappingInfo[slot][mappingLocationY] = y;
    mappingInfo[slot][mappingLocationZ] = z;

    mappingInfo[slot][mappingInterior] = 0;
    mappingInfo[slot][mappingWorld] = 0;

    new query[1000];
    mysql_format(sql, query, sizeof query, "INSERT INTO `mapping_folder` (`id`, `name`, `creator`, `createdat`, `x`, `y`, `z`, `interior`, `world`, `loaded`) VALUES ('%d', '%e', '%e', '%d', '%f', '%f', '%f', '0', '0', '0')", slot, name, creator, _:time, x, y, z);
    mysql_tquery(sql, query);

    Iter_Add(MappingFolder, slot);
    return 1;
}

stock SaveObjectToMappingFolder(const foldername[])
{
    if(!IsValidMappingFolder(foldername)) return 1;
    if(Iter_Count(DynamicObjects) == 0) return 1;
    
    foreach(new slot : DynamicObjects) 
    {
        if(Iter_Contains(DynamicObjects, slot)) 
        {
            new query[100];
            mysql_format(sql, query, sizeof query, "INSERT INTO `mapping_object` (`type`, `folder`) VALUES ('0', '%e')", foldername);
            mysql_tquery(sql, query, "OnMappingObjectSaved", "ds", slot, foldername);
        }
    }
    return 1;
}

stock SaveRemoveObjectToMappingFolder(const foldername[])
{
    if(!IsValidMappingFolder(foldername)) return 1;
    if(Iter_Count(RemoveObject) == 0) return 1;
    
    foreach(new slot : RemoveObject) 
    {
        if(Iter_Contains(RemoveObject, slot)) 
        {
            new query[100];
            mysql_format(sql, query, sizeof query, "INSERT INTO `mapping_object` (`type`, `folder`) VALUES ('1', '%e')", foldername);
            mysql_tquery(sql, query, "OnMappingRemoveObjectSaved", "ds", slot, foldername);

            printf(query);
        }
    }
    return 1;
}

stock IsValidMappingFolder(const foldername[])
{
    new bool:status = false;
    foreach(new i : MappingFolder)
    {
        if(!strcmp(mappingInfo[i][mappingName], foldername, true))
        {
            status = true;
            break;
        }
    }
    return status;
}

stock GetMappingFolderID(const foldername[]) 
{
    if(!IsValidMappingFolder(foldername)) return 1;

    new folderid = -1;
    foreach(new i : MappingFolder)
    {
        if(!strcmp(mappingInfo[i][mappingName], foldername, true))
        {
            folderid = i;
            break;
        }
    }
    return folderid;
}

stock LoadMappingObject(const foldername[], world, interior) 
{
    if(!IsValidMappingFolder(foldername)) return 1; 

    mappingInfo[GetMappingFolderID(foldername)][mappingWorld] = world;
    mappingInfo[GetMappingFolderID(foldername)][mappingInterior] = interior;

    new query[200];
    mysql_format(sql, query, sizeof(query), "SELECT * FROM `mapping_object` WHERE `folder` = '%e'", foldername);
    mysql_tquery(sql, query, "CreateLoadMappingObject", "d", GetMappingFolderID(foldername));

    return 1;
}

stock UnloadMappingObject(const foldername[]) 
{
    new folderid = GetMappingFolderID(foldername);
    Loop(i, mappingInfo[folderid][mappingObjectTotal] + 1)
    {
        if(IsValidDynamicObject(ObjectIDFromMappingFolder[folderid][i]))
        {
            DestroyDynamicObject(ObjectIDFromMappingFolder[folderid][i]);
        }
    }
    return 1;
}