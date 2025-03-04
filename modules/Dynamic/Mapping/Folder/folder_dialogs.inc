Dialog:Mapping_Delete(playerid, params, response, listitem, inputtext[])
{
    if(!response) return 1;
    else 
    {
        if(mappingInfo[GetMappingFolderID(player_delete_mappingname[playerid])][mappingLoaded] == true) UnloadMappingObject(player_delete_mappingname[playerid]);

        new query[1000];
        mysql_format(sql, query, sizeof query, "DELETE FROM `mapping_folder` WHERE `name` = '%s'", player_delete_mappingname[playerid]);
        mysql_tquery(sql, query);

        mysql_format(sql, query, sizeof query, "DELETE FROM `mapping_object` WHERE `folder` = '%s'", player_delete_mappingname[playerid]);
        mysql_tquery(sql, query);

        Iter_Remove(MappingFolder, GetMappingFolderID(player_delete_mappingname[playerid]));
        SendClientMessageEx(playerid, COLOR_REN, "MAPPING: "WHITE"Menghapus mapping "LR"%s", player_delete_mappingname[playerid]);
    }
    return 1;
}