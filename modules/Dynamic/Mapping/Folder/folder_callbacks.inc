hook OnServerAssignData()
{
    mysql_tquery(sql, "SELECT * FROM `mapping_folder`", "LoadMappingFolder");
    return 1;
}

function OnMappingRemoveObjectSaved(slot, const foldername[])
{
    new dbid = cache_insert_id(), query[500];
    mysql_format(sql, query, sizeof query, "UPDATE `mapping_object` SET `model` = '%d', `x` = '%f', `y` = '%f', `z` = '%f', `radius` = '%f' WHERE `id` = '%d'", removeobjectInfo[slot][removeobjectModel], removeobjectInfo[slot][removeobjectPositionX], removeobjectInfo[slot][removeobjectPositionY], removeobjectInfo[slot][removeobjectPositionZ], removeobjectInfo[slot][removeobjectRadius], dbid);
    mysql_tquery(sql, query);
    return 1;
}

function OnMappingObjectSaved(slot, const foldername[]) 
{
    new dbid = cache_insert_id(), query[500];

    new omodel, Float:ox, Float:oy, Float:oz, Float:orx, Float:ory, Float:orz, 
        texture_model[MAX_OBJECT_MATERIAL_SLOT], texture_txdname[MAX_OBJECT_MATERIAL_SLOT][20], texture_texturename[MAX_OBJECT_MATERIAL_SLOT][20], texture_color[MAX_OBJECT_MATERIAL_SLOT], 
        text_text[MAX_OBJECT_MATERIAL_SLOT][125], text_size[MAX_OBJECT_MATERIAL_SLOT], text_fontface[MAX_OBJECT_MATERIAL_SLOT][20], text_fontsize[MAX_OBJECT_MATERIAL_SLOT], text_fontbold[MAX_OBJECT_MATERIAL_SLOT], text_fontcolor[MAX_OBJECT_MATERIAL_SLOT], text_backcolor[MAX_OBJECT_MATERIAL_SLOT], text_alignment[MAX_OBJECT_MATERIAL_SLOT];

    new string[1000];
    omodel = Streamer_GetIntData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_MODEL_ID);
    Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_X, ox);
    Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_Y, oy);
    Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_Z, oz);
    Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_R_X, orx);
    Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_R_Y, ory);
    Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_R_Z, orz);
    mysql_format(sql, query, sizeof query, "UPDATE `mapping_object` SET `model` = '%d', `x` = '%f', `y` = '%f', `z` = '%f', `rx` = '%f', `ry` = '%f', `rz` = '%f' WHERE `id` = '%d'", omodel, ox, oy, oz, orx, ory, orz, dbid);
    mysql_tquery(sql, query);

    Loop(i, MAX_OBJECT_MATERIAL_SLOT)
    {
        GetDynamicObjectMaterial(DynamicObject[slot], i, texture_model[i], texture_txdname[i], texture_texturename[i], texture_color[i]);
        GetDynamicObjectMaterialText(DynamicObject[slot], i, text_text[i], text_size[i], text_fontface[i], text_fontsize[i], text_fontbold[i], text_fontcolor[i], text_backcolor[i], text_alignment[i]);
    }

    format(string, sizeof(string), "%d|%d|%d|%d|%d|%d|%d|%d|%d|%d", texture_model[0], texture_model[1], texture_model[2], texture_model[3], texture_model[4], texture_model[5], texture_model[6], texture_model[7], texture_model[8], texture_model[9]);
    mysql_format(sql, query, sizeof query, "UPDATE `mapping_object` SET `texture_model` = '%e' WHERE `id` = '%d'", string, dbid);
    mysql_tquery(sql, query);

    format(string, sizeof(string), "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s", texture_txdname[0], texture_txdname[1], texture_txdname[2], texture_txdname[3], texture_txdname[4], texture_txdname[5], texture_txdname[6], texture_txdname[7], texture_txdname[8], texture_txdname[9]);
    mysql_format(sql, query, sizeof query, "UPDATE `mapping_object` SET `texture_txdname` = '%e' WHERE `id` = '%d'", string, dbid);
    mysql_tquery(sql, query);

    format(string, sizeof(string), "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s", texture_texturename[0], texture_texturename[1], texture_texturename[2], texture_texturename[3], texture_texturename[4], texture_texturename[5], texture_texturename[6], texture_texturename[7], texture_texturename[8], texture_texturename[9]);
    mysql_format(sql, query, sizeof query, "UPDATE `mapping_object` SET `texture_texturename` = '%e' WHERE `id` = '%d'", string, dbid);
    mysql_tquery(sql, query);

    format(string, sizeof(string), "%d|%d|%d|%d|%d|%d|%d|%d|%d|%d", texture_color[0], texture_color[1], texture_color[2], texture_color[3], texture_color[4], texture_color[5], texture_color[6], texture_color[7], texture_color[8], texture_color[9]);
    mysql_format(sql, query, sizeof query, "UPDATE `mapping_object` SET `texture_color` = '%e' WHERE `id` = '%d'", string, dbid);
    mysql_tquery(sql, query);

    format(string, sizeof(string), "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s", text_text[0], text_text[1], text_text[2], text_text[3], text_text[4], text_text[5], text_text[6], text_text[7], text_text[8], text_text[9]);
    mysql_format(sql, query, sizeof query, "UPDATE `mapping_object` SET `text_text` = '%e' WHERE `id` = '%d'", string, dbid);
    mysql_tquery(sql, query);

    format(string, sizeof(string), "%d|%d|%d|%d|%d|%d|%d|%d|%d|%d", text_size[0], text_size[1], text_size[2], text_size[3], text_size[4], text_size[5], text_size[6], text_size[7], text_size[8], text_size[9]);
    mysql_format(sql, query, sizeof query, "UPDATE `mapping_object` SET `text_size` = '%e' WHERE `id` = '%d'", string, dbid);
    mysql_tquery(sql, query);

    format(string, sizeof(string), "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s", text_fontface[0], text_fontface[1], text_fontface[2], text_fontface[3], text_fontface[4], text_fontface[5], text_fontface[6], text_fontface[7], text_fontface[8], text_fontface[9]);
    mysql_format(sql, query, sizeof query, "UPDATE `mapping_object` SET `text_fontface` = '%e' WHERE `id` = '%d'", string, dbid);
    mysql_tquery(sql, query);

    format(string, sizeof(string), "%d|%d|%d|%d|%d|%d|%d|%d|%d|%d", text_fontsize[0], text_fontsize[1], text_fontsize[2], text_fontsize[3], text_fontsize[4], text_fontsize[5], text_fontsize[6], text_fontsize[7], text_fontsize[8], text_fontsize[9]);
    mysql_format(sql, query, sizeof query, "UPDATE `mapping_object` SET `text_fontsize` = '%e' WHERE `id` = '%d'", string, dbid);
    mysql_tquery(sql, query);

    format(string, sizeof(string), "%d|%d|%d|%d|%d|%d|%d|%d|%d|%d", text_fontbold[0], text_fontbold[1], text_fontbold[2], text_fontbold[3], text_fontbold[4], text_fontbold[5], text_fontbold[6], text_fontbold[7], text_fontbold[8], text_fontbold[9]);
    mysql_format(sql, query, sizeof query, "UPDATE `mapping_object` SET `text_fontbold` = '%e' WHERE `id` = '%d'", string, dbid);
    mysql_tquery(sql, query);

    format(string, sizeof(string), "%d|%d|%d|%d|%d|%d|%d|%d|%d|%d", text_fontcolor[0], text_fontcolor[1], text_fontcolor[2], text_fontcolor[3], text_fontcolor[4], text_fontcolor[5], text_fontcolor[6], text_fontcolor[7], text_fontcolor[8], text_fontcolor[9]);
    mysql_format(sql, query, sizeof query, "UPDATE `mapping_object` SET `text_fontcolor` = '%e' WHERE `id` = '%d'", string, dbid);
    mysql_tquery(sql, query);

    format(string, sizeof(string), "%d|%d|%d|%d|%d|%d|%d|%d|%d|%d", text_backcolor[0], text_backcolor[1], text_backcolor[2], text_backcolor[3], text_backcolor[4], text_backcolor[5], text_backcolor[6], text_backcolor[7], text_backcolor[8], text_backcolor[9]);
    mysql_format(sql, query, sizeof query, "UPDATE `mapping_object` SET `text_backcolor` = '%e' WHERE `id` = '%d'", string, dbid);
    mysql_tquery(sql, query);

    format(string, sizeof(string), "%d|%d|%d|%d|%d|%d|%d|%d|%d|%d", text_alignment[0], text_alignment[1], text_alignment[2], text_alignment[3], text_alignment[4], text_alignment[5], text_alignment[6], text_alignment[7], text_alignment[8], text_alignment[9]);
    mysql_format(sql, query, sizeof query, "UPDATE `mapping_object` SET `text_alignment` = '%e' WHERE `id` = '%d'", string, dbid);
    mysql_tquery(sql, query);

    mysql_format(sql, query, sizeof query, "UPDATE `mapping_folder` SET `objecttotal` = '%d' WHERE `name` = '%e'", Iter_Count(DynamicObjects), foldername);
    mysql_tquery(sql, query);
    
    mappingInfo[GetMappingFolderID(foldername)][mappingObjectTotal] = Iter_Count(DynamicObjects);
    return 1;
}

function LoadMappingFolder()
{
    static folderid;
	new rows  = cache_num_rows();
    if(rows)
    {
		for(new i; i < rows; i++)
		{
            cache_get_value_int(i, "id", folderid);
            cache_get_value_int(i, "loaded", mappingInfo[folderid][mappingLoaded]);
            cache_get_value(i, "name", mappingInfo[folderid][mappingName]);
            cache_get_value(i, "creator", mappingInfo[folderid][mappingCreator]);
            cache_get_value_int(i, "createdat", _:mappingInfo[folderid][mappingCreateAt]);
            cache_get_value_float(i, "x", mappingInfo[folderid][mappingLocationX]);
            cache_get_value_float(i, "y", mappingInfo[folderid][mappingLocationY]);
            cache_get_value_float(i, "z", mappingInfo[folderid][mappingLocationZ]);
            cache_get_value_int(i, "interior", mappingInfo[folderid][mappingInterior]);
            cache_get_value_int(i, "world", mappingInfo[folderid][mappingWorld]);
            cache_get_value_int(i, "objecttotal", mappingInfo[folderid][mappingObjectTotal]);

            Iter_Add(MappingFolder, folderid);

            if(mappingInfo[folderid][mappingLoaded]) LoadMappingObject(mappingInfo[folderid][mappingName], mappingInfo[folderid][mappingWorld], mappingInfo[folderid][mappingInterior]);
        }
    }
    return 1;
}

function CreateLoadMappingObject(folderid)
{
    new params[3000];

    new value_string[MAX_OBJECT_MATERIAL_SLOT][50], value_int[MAX_OBJECT_MATERIAL_SLOT];
    new texture_model, texture_txdname[50], texture_name[50], texture_color;
    new text_text[256], text_size, text_fontface[50], text_fontsize, text_fontbold, text_fontcolor, text_backcolor, text_alignment;

	new rows  = cache_num_rows();
    if(rows)
    {
		for(new i; i < rows; i++)
		{
            new model, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, Float:radius, type = 0;
            cache_get_value_int(i, "type", type);
            cache_get_value_int(i, "model", model);
            cache_get_value_float(i, "x", x);
            cache_get_value_float(i, "y", y);
            cache_get_value_float(i, "z", z);
            cache_get_value_float(i, "rx", rx);
            cache_get_value_float(i, "ry", ry);
            cache_get_value_float(i, "rz", rz);
            cache_get_value_float(i, "radius", radius);

            if(type == 0) 
            {
                ObjectIDFromMappingFolder[folderid][i] = CreateDynamicObject(model, x, y, z, rx, ry, rz, mappingInfo[folderid][mappingWorld], mappingInfo[folderid][mappingInterior]);
                
                cache_get_value(i, "texture_model", params);
                unformat(params, "p<|>dddddddddd", value_int[0], value_int[1], value_int[2], value_int[3], value_int[4], value_int[5], value_int[6], value_int[7], value_int[8], value_int[9]);
                Loop(index, MAX_OBJECT_MATERIAL_SLOT)
                {
                    if(value_int[index] != 0)
                    {
                        GetDynamicObjectMaterial(ObjectIDFromMappingFolder[folderid][i], index, texture_model, texture_txdname, texture_name, texture_color);
                        SetDynamicObjectMaterial(ObjectIDFromMappingFolder[folderid][i], index, value_int[index], texture_txdname, texture_name, texture_color);
                    }
                }

                cache_get_value(i, "texture_txdname", params);
                unformat(params, "p<|>s[50]s[50]s[50]s[50]s[50]s[50]s[50]s[50]s[50]s[50]", value_string[0], value_string[1], value_string[2], value_string[3], value_string[4], value_string[5], value_string[6], value_string[7], value_string[8], value_string[9]);
                Loop(index, MAX_OBJECT_MATERIAL_SLOT)
                {
                    if(!isnull(value_string[index]))
                    {
                        GetDynamicObjectMaterial(ObjectIDFromMappingFolder[folderid][i], index, texture_model, texture_txdname, texture_name, texture_color);
                        SetDynamicObjectMaterial(ObjectIDFromMappingFolder[folderid][i], index, texture_model, value_string[index], texture_name, texture_color);
                    }
                }

                cache_get_value(i, "texture_texturename", params);
                unformat(params, "p<|>s[50]s[50]s[50]s[50]s[50]s[50]s[50]s[50]s[50]s[50]", value_string[0], value_string[1], value_string[2], value_string[3], value_string[4], value_string[5], value_string[6], value_string[7], value_string[8], value_string[9]);
                Loop(index, MAX_OBJECT_MATERIAL_SLOT)
                {
                    if(!isnull(value_string[index]))
                    {
                        GetDynamicObjectMaterial(ObjectIDFromMappingFolder[folderid][i], index, texture_model, texture_txdname, texture_name, texture_color);
                        SetDynamicObjectMaterial(ObjectIDFromMappingFolder[folderid][i], index, texture_model, texture_txdname, value_string[index], texture_color);
                    }
                }

                cache_get_value(i, "texture_color", params);
                unformat(params, "p<|>dddddddddd", value_int[0], value_int[1], value_int[2], value_int[3], value_int[4], value_int[5], value_int[6], value_int[7], value_int[8], value_int[9]);
                Loop(index, MAX_OBJECT_MATERIAL_SLOT)
                {
                    if(value_int[index] != 0)
                    {
                        GetDynamicObjectMaterial(ObjectIDFromMappingFolder[folderid][i], index, texture_model, texture_txdname, texture_name, texture_color);
                        SetDynamicObjectMaterial(ObjectIDFromMappingFolder[folderid][i], index, texture_model, texture_txdname, texture_name, value_int[index]);
                    }
                }

                cache_get_value(i, "text_text", params);
                unformat(params, "p<|>s[50]s[50]s[50]s[50]s[50]s[50]s[50]s[50]s[50]s[50]", value_string[0], value_string[1], value_string[2], value_string[3], value_string[4], value_string[5], value_string[6], value_string[7], value_string[8], value_string[9]);
                Loop(index, MAX_OBJECT_MATERIAL_SLOT)
                {
                    if(!isnull(value_string[index]))
                    {
                        GetDynamicObjectMaterialText(ObjectIDFromMappingFolder[folderid][i], index, text_text, text_size, text_fontface, text_fontsize, text_fontbold, text_fontcolor, text_backcolor, text_alignment);
                        SetDynamicObjectMaterialText(ObjectIDFromMappingFolder[folderid][i], index, value_string[index], text_size, text_fontface, text_fontsize, text_fontbold, text_fontcolor, text_backcolor, text_alignment);
                    }
                }

                cache_get_value(i, "text_size", params);
                unformat(params, "p<|>dddddddddd", value_int[0], value_int[1], value_int[2], value_int[3], value_int[4], value_int[5], value_int[6], value_int[7], value_int[8], value_int[9]);
                Loop(index, MAX_OBJECT_MATERIAL_SLOT)
                {
                    if(!isnull(value_string[index]))
                    {
                        GetDynamicObjectMaterialText(ObjectIDFromMappingFolder[folderid][i], index, text_text, text_size, text_fontface, text_fontsize, text_fontbold, text_fontcolor, text_backcolor, text_alignment);
                        SetDynamicObjectMaterialText(ObjectIDFromMappingFolder[folderid][i], index, text_text, value_int[index], text_fontface, text_fontsize, text_fontbold, text_fontcolor, text_backcolor, text_alignment);
                    }
                }

                cache_get_value(i, "text_fontface", params);
                unformat(params, "p<|>s[50]s[50]s[50]s[50]s[50]s[50]s[50]s[50]s[50]s[50]", value_string[0], value_string[1], value_string[2], value_string[3], value_string[4], value_string[5], value_string[6], value_string[7], value_string[8], value_string[9]);
                Loop(index, MAX_OBJECT_MATERIAL_SLOT)
                {
                    if(!isnull(value_string[index]))
                    {
                        GetDynamicObjectMaterialText(ObjectIDFromMappingFolder[folderid][i], index, text_text, text_size, text_fontface, text_fontsize, text_fontbold, text_fontcolor, text_backcolor, text_alignment);
                        SetDynamicObjectMaterialText(ObjectIDFromMappingFolder[folderid][i], index, text_text, text_size, value_string[index], text_fontsize, text_fontbold, text_fontcolor, text_backcolor, text_alignment);
                    }
                }

                cache_get_value(i, "text_fontsize", params);
                unformat(params, "p<|>dddddddddd", value_int[0], value_int[1], value_int[2], value_int[3], value_int[4], value_int[5], value_int[6], value_int[7], value_int[8], value_int[9]);
                Loop(index, MAX_OBJECT_MATERIAL_SLOT)
                {
                    if(!isnull(value_string[index]))
                    {
                        GetDynamicObjectMaterialText(ObjectIDFromMappingFolder[folderid][i], index, text_text, text_size, text_fontface, text_fontsize, text_fontbold, text_fontcolor, text_backcolor, text_alignment);
                        SetDynamicObjectMaterialText(ObjectIDFromMappingFolder[folderid][i], index, text_text, text_size, text_fontface, value_int[index], text_fontbold, text_fontcolor, text_backcolor, text_alignment);
                    }
                }

                cache_get_value(i, "text_fontbold", params);
                unformat(params, "p<|>dddddddddd", value_int[0], value_int[1], value_int[2], value_int[3], value_int[4], value_int[5], value_int[6], value_int[7], value_int[8], value_int[9]);
                Loop(index, MAX_OBJECT_MATERIAL_SLOT)
                {
                    if(!isnull(value_string[index]))
                    {
                        GetDynamicObjectMaterialText(ObjectIDFromMappingFolder[folderid][i], index, text_text, text_size, text_fontface, text_fontsize, text_fontbold, text_fontcolor, text_backcolor, text_alignment);
                        SetDynamicObjectMaterialText(ObjectIDFromMappingFolder[folderid][i], index, text_text, text_size, text_fontface, text_fontsize, value_int[index], text_fontcolor, text_backcolor, text_alignment);
                    }
                }

                cache_get_value(i, "text_fontcolor", params);
                unformat(params, "p<|>dddddddddd", value_int[0], value_int[1], value_int[2], value_int[3], value_int[4], value_int[5], value_int[6], value_int[7], value_int[8], value_int[9]);
                Loop(index, MAX_OBJECT_MATERIAL_SLOT)
                {
                    if(!isnull(value_string[index]))
                    {
                        GetDynamicObjectMaterialText(ObjectIDFromMappingFolder[folderid][i], index, text_text, text_size, text_fontface, text_fontsize, text_fontbold, text_fontcolor, text_backcolor, text_alignment);
                        SetDynamicObjectMaterialText(ObjectIDFromMappingFolder[folderid][i], index, text_text, text_size, text_fontface, text_fontsize, text_fontbold, value_int[index], text_backcolor, text_alignment);
                    }
                }

                cache_get_value(i, "text_backcolor", params);
                unformat(params, "p<|>dddddddddd", value_int[0], value_int[1], value_int[2], value_int[3], value_int[4], value_int[5], value_int[6], value_int[7], value_int[8], value_int[9]);
                Loop(index, MAX_OBJECT_MATERIAL_SLOT)
                {
                    if(!isnull(value_string[index]))
                    {
                        GetDynamicObjectMaterialText(ObjectIDFromMappingFolder[folderid][i], index, text_text, text_size, text_fontface, text_fontsize, text_fontbold, text_fontcolor, text_backcolor, text_alignment);
                        SetDynamicObjectMaterialText(ObjectIDFromMappingFolder[folderid][i], index, text_text, text_size, text_fontface, text_fontsize, text_fontbold, text_fontcolor, value_int[index], text_alignment);
                    }
                }

                cache_get_value(i, "text_alignment", params);
                unformat(params, "p<|>dddddddddd", value_int[0], value_int[1], value_int[2], value_int[3], value_int[4], value_int[5], value_int[6], value_int[7], value_int[8], value_int[9]);
                Loop(index, MAX_OBJECT_MATERIAL_SLOT)
                {
                    if(!isnull(value_string[index]))
                    {
                        GetDynamicObjectMaterialText(ObjectIDFromMappingFolder[folderid][i], index, text_text, text_size, text_fontface, text_fontsize, text_fontbold, text_fontcolor, text_backcolor, text_alignment);
                        SetDynamicObjectMaterialText(ObjectIDFromMappingFolder[folderid][i], index, text_text, text_size, text_fontface, text_fontsize, text_fontbold, text_fontcolor, text_backcolor, value_int[index]);
                    }
                }
            }
            else if(type == 1)
            {
                AddRemoveBuilding(model, x, y, z, radius);
                foreach(new allplayer : Player) 
                {
                    RefreshRemoveBuildings(allplayer);
                }
            }
        }
    }
    return 1;
}