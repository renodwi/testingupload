hook OnPlayerConnect(playerid)
{
    player_editing_object_id[playerid] = -1;
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(player_editing_object_id[playerid] != -1)
	{
        new slot = player_editing_object_id[playerid];
		player_editing_object_id[playerid] = -1;
        ObjectEditor[slot] = INVALID_PLAYER_ID;
	}
    return 1;
}

hook OnPlayerEditDynamicObj(playerid, objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
    if(response == EDIT_RESPONSE_FINAL)
	{
		if(player_editing_object_id[playerid] != -1)
		{
            new slot = player_editing_object_id[playerid];
            player_editing_object_id[playerid] = -1;
            ObjectEditor[slot] = INVALID_PLAYER_ID;

            SetDynamicObjectPos(objectid, x, y, z);
            SetDynamicObjectRot(objectid, rx, ry, rz);

            RefreshDynamicObjectLabel(slot);
		}
	}
    else if(response == EDIT_RESPONSE_CANCEL)
	{
	    if(player_editing_object_id[playerid] != -1)
		{
            new slot = player_editing_object_id[playerid];
            player_editing_object_id[playerid] = -1;
            ObjectEditor[slot] = INVALID_PLAYER_ID;

            new Float:cPos[3],Float:cRot[3];
            Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_X, cPos[0]);
            Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_Y, cPos[1]);
            Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_Z, cPos[2]);
            Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_R_X, cRot[0]);
            Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_R_Y, cRot[1]);
            Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_R_Z, cRot[2]);
            SetDynamicObjectPos(objectid, cPos[0], cPos[1], cPos[2]);
            SetDynamicObjectRot(objectid, cRot[0], cRot[1], cRot[2]);

            RefreshDynamicObjectLabel(slot);
		}
	}
    return 1;
}

hook OnPlayerSelectDynObject(playerid, objectid, modelid, Float:x, Float:y, Float:z)
{
    foreach(new slot : DynamicObjects)
    {
        if(DynamicObject[slot] == objectid)
        {
            if(EditDynamicObjectMode[playerid] == OBJECT_SELECT_EDITOR)
            {
                if(ObjectEditor[slot] != INVALID_PLAYER_ID) SendErrorMessage(playerid, "Object ini sedang diedit oleh seseorang!");

				ObjectEditor[slot] = playerid;
                player_editing_object_id[playerid] = slot;
                EditDynamicObject(playerid,objectid);
                SendClientMessageEx(playerid, COLOR_REN, "OBJECT: "WHITE"Editing object "YELLOW"id %d", slot);
                break;
            }
            if(EditDynamicObjectMode[playerid] == OBJECT_SELECT_DELETE)
            {
		        if(ObjectEditor[slot] != INVALID_PLAYER_ID) SendErrorMessage(playerid, "Object ini sedang diedit oleh seseorang!");

                DestroyDynamicObject(DynamicObject[slot]);

				Loop(i,MAX_OBJECT_MATERIAL_SLOT)
				{
					DynamicObjectMaterial[slot][i] = OBJECT_MATERIAL_TYPE_NONE;
				}
				Iter_Remove(DynamicObjects, slot);
                SendClientMessageEx(playerid, COLOR_REN, "OBJECT: "WHITE"Object dengan "LR"ID %d "WHITE"telah dihapus, total objects: "LG"%d", slot, Iter_Count(DynamicObjects));
                break;
            }
            if(EditDynamicObjectMode[playerid] == OBJECT_SELECT_PAINT)
            {
                new index, model, txdname[32], texture[32], color, string[144];
		        GetPVarString(playerid, "PaintParam", string, sizeof(string));
		        unformat(string, "p<|>dds[32]s[32]d", index, model, txdname, texture, color);
		        SetDynamicObjectMaterial(DynamicObject[slot], index, model, txdname, texture, color);
				DynamicObjectMaterial[slot][index] = OBJECT_MATERIAL_TYPE_TEXTURE;
                break;
            }
            if(EditDynamicObjectMode[playerid] == OBJECT_SELECT_CLEAN)
            {
	    		new model,Float:cPos[3],Float:cRot[3];
				model = Streamer_GetIntData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_MODEL_ID);
				Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_X, cPos[0]);
				Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_Y, cPos[1]);
				Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_Z, cPos[2]);
				Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_R_X, cRot[0]);
				Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_R_Y, cRot[1]);
				Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_R_Z, cRot[2]);
                DestroyDynamicObject(DynamicObject[slot]);
				Loop(index,MAX_OBJECT_MATERIAL_SLOT)
				{
					DynamicObjectMaterial[slot][index] = OBJECT_MATERIAL_TYPE_NONE;
				}
				DynamicObject[slot] = CreateDynamicObject(model, cPos[0], cPos[1], cPos[2], cRot[0], cRot[1], cRot[2]);
				Streamer_Update(playerid);
                break;
            }
            break;
        }
    }
    return 1;
}

function LoadObjectFromMappingFolder(forplayerid) 
{
    new slot, params[3000];

    new value_string[MAX_OBJECT_MATERIAL_SLOT][50], value_int[MAX_OBJECT_MATERIAL_SLOT];
    new texture_model, texture_txdname[50], texture_name[50], texture_color;
    new text_text[256], text_size, text_fontface[50], text_fontsize, text_fontbold, text_fontcolor, text_backcolor, text_alignment;

	new rows  = cache_num_rows();
    if(rows)
    {
		for(new i; i < rows; i++)
		{
            slot = Iter_Free(DynamicObjects);

            new model, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, Float:radius, type;
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
                DynamicObject[slot] = CreateDynamicObject(model, x, y, z, rx, ry, rz);

                cache_get_value(i, "texture_model", params);
                unformat(params, "p<|>dddddddddd", value_int[0], value_int[1], value_int[2], value_int[3], value_int[4], value_int[5], value_int[6], value_int[7], value_int[8], value_int[9]);
                Loop(index, MAX_OBJECT_MATERIAL_SLOT)
                {
                    if(value_int[index] != 0)
                    {
                        GetDynamicObjectMaterial(DynamicObject[slot], index, texture_model, texture_txdname, texture_name, texture_color);
                        SetDynamicObjectMaterial(DynamicObject[slot], index, value_int[index], texture_txdname, texture_name, texture_color);
                        DynamicObjectMaterial[slot][index] = OBJECT_MATERIAL_TYPE_TEXTURE;
                    }
                }

                cache_get_value(i, "texture_txdname", params);
                unformat(params, "p<|>s[50]s[50]s[50]s[50]s[50]s[50]s[50]s[50]s[50]s[50]", value_string[0], value_string[1], value_string[2], value_string[3], value_string[4], value_string[5], value_string[6], value_string[7], value_string[8], value_string[9]);
                Loop(index, MAX_OBJECT_MATERIAL_SLOT)
                {
                    if(!isnull(value_string[index]))
                    {
                        GetDynamicObjectMaterial(DynamicObject[slot], index, texture_model, texture_txdname, texture_name, texture_color);
                        SetDynamicObjectMaterial(DynamicObject[slot], index, texture_model, value_string[index], texture_name, texture_color);
                        DynamicObjectMaterial[slot][index] = OBJECT_MATERIAL_TYPE_TEXTURE;
                    }
                }

                cache_get_value(i, "texture_texturename", params);
                unformat(params, "p<|>s[50]s[50]s[50]s[50]s[50]s[50]s[50]s[50]s[50]s[50]", value_string[0], value_string[1], value_string[2], value_string[3], value_string[4], value_string[5], value_string[6], value_string[7], value_string[8], value_string[9]);
                Loop(index, MAX_OBJECT_MATERIAL_SLOT)
                {
                    if(!isnull(value_string[index]))
                    {
                        GetDynamicObjectMaterial(DynamicObject[slot], index, texture_model, texture_txdname, texture_name, texture_color);
                        SetDynamicObjectMaterial(DynamicObject[slot], index, texture_model, texture_txdname, value_string[index], texture_color);
                        DynamicObjectMaterial[slot][index] = OBJECT_MATERIAL_TYPE_TEXTURE;
                    }
                }

                cache_get_value(i, "texture_color", params);
                unformat(params, "p<|>dddddddddd", value_int[0], value_int[1], value_int[2], value_int[3], value_int[4], value_int[5], value_int[6], value_int[7], value_int[8], value_int[9]);
                Loop(index, MAX_OBJECT_MATERIAL_SLOT)
                {
                    if(value_int[index] != 0)
                    {
                        GetDynamicObjectMaterial(DynamicObject[slot], index, texture_model, texture_txdname, texture_name, texture_color);
                        SetDynamicObjectMaterial(DynamicObject[slot], index, texture_model, texture_txdname, texture_name, value_int[index]);
                        DynamicObjectMaterial[slot][index] = OBJECT_MATERIAL_TYPE_TEXTURE;
                    }
                }

                cache_get_value(i, "text_text", params);
                unformat(params, "p<|>s[50]s[50]s[50]s[50]s[50]s[50]s[50]s[50]s[50]s[50]", value_string[0], value_string[1], value_string[2], value_string[3], value_string[4], value_string[5], value_string[6], value_string[7], value_string[8], value_string[9]);
                Loop(index, MAX_OBJECT_MATERIAL_SLOT)
                {
                    if(!isnull(value_string[index]))
                    {
                        GetDynamicObjectMaterialText(DynamicObject[slot], index, text_text, text_size, text_fontface, text_fontsize, text_fontbold, text_fontcolor, text_backcolor, text_alignment);
                        SetDynamicObjectMaterialText(DynamicObject[slot], index, value_string[index], text_size, text_fontface, text_fontsize, text_fontbold, text_fontcolor, text_backcolor, text_alignment);
                        DynamicObjectMaterial[slot][index] = OBJECT_MATERIAL_TYPE_MESSAGE;
                    }
                }

                cache_get_value(i, "text_size", params);
                unformat(params, "p<|>dddddddddd", value_int[0], value_int[1], value_int[2], value_int[3], value_int[4], value_int[5], value_int[6], value_int[7], value_int[8], value_int[9]);
                Loop(index, MAX_OBJECT_MATERIAL_SLOT)
                {
                    if(!isnull(value_string[index]))
                    {
                        GetDynamicObjectMaterialText(DynamicObject[slot], index, text_text, text_size, text_fontface, text_fontsize, text_fontbold, text_fontcolor, text_backcolor, text_alignment);
                        SetDynamicObjectMaterialText(DynamicObject[slot], index, text_text, value_int[index], text_fontface, text_fontsize, text_fontbold, text_fontcolor, text_backcolor, text_alignment);
                        DynamicObjectMaterial[slot][index] = OBJECT_MATERIAL_TYPE_MESSAGE;
                    }
                }

                cache_get_value(i, "text_fontface", params);
                unformat(params, "p<|>s[50]s[50]s[50]s[50]s[50]s[50]s[50]s[50]s[50]s[50]", value_string[0], value_string[1], value_string[2], value_string[3], value_string[4], value_string[5], value_string[6], value_string[7], value_string[8], value_string[9]);
                Loop(index, MAX_OBJECT_MATERIAL_SLOT)
                {
                    if(!isnull(value_string[index]))
                    {
                        GetDynamicObjectMaterialText(DynamicObject[slot], index, text_text, text_size, text_fontface, text_fontsize, text_fontbold, text_fontcolor, text_backcolor, text_alignment);
                        SetDynamicObjectMaterialText(DynamicObject[slot], index, text_text, text_size, value_string[index], text_fontsize, text_fontbold, text_fontcolor, text_backcolor, text_alignment);
                        DynamicObjectMaterial[slot][index] = OBJECT_MATERIAL_TYPE_MESSAGE;
                    }
                }

                cache_get_value(i, "text_fontsize", params);
                unformat(params, "p<|>dddddddddd", value_int[0], value_int[1], value_int[2], value_int[3], value_int[4], value_int[5], value_int[6], value_int[7], value_int[8], value_int[9]);
                Loop(index, MAX_OBJECT_MATERIAL_SLOT)
                {
                    if(!isnull(value_string[index]))
                    {
                        GetDynamicObjectMaterialText(DynamicObject[slot], index, text_text, text_size, text_fontface, text_fontsize, text_fontbold, text_fontcolor, text_backcolor, text_alignment);
                        SetDynamicObjectMaterialText(DynamicObject[slot], index, text_text, text_size, text_fontface, value_int[index], text_fontbold, text_fontcolor, text_backcolor, text_alignment);
                        DynamicObjectMaterial[slot][index] = OBJECT_MATERIAL_TYPE_MESSAGE;
                    }
                }

                cache_get_value(i, "text_fontbold", params);
                unformat(params, "p<|>dddddddddd", value_int[0], value_int[1], value_int[2], value_int[3], value_int[4], value_int[5], value_int[6], value_int[7], value_int[8], value_int[9]);
                Loop(index, MAX_OBJECT_MATERIAL_SLOT)
                {
                    if(!isnull(value_string[index]))
                    {
                        GetDynamicObjectMaterialText(DynamicObject[slot], index, text_text, text_size, text_fontface, text_fontsize, text_fontbold, text_fontcolor, text_backcolor, text_alignment);
                        SetDynamicObjectMaterialText(DynamicObject[slot], index, text_text, text_size, text_fontface, text_fontsize, value_int[index], text_fontcolor, text_backcolor, text_alignment);
                        DynamicObjectMaterial[slot][index] = OBJECT_MATERIAL_TYPE_MESSAGE;
                    }
                }

                cache_get_value(i, "text_backcolor", params);
                unformat(params, "p<|>dddddddddd", value_int[0], value_int[1], value_int[2], value_int[3], value_int[4], value_int[5], value_int[6], value_int[7], value_int[8], value_int[9]);
                Loop(index, MAX_OBJECT_MATERIAL_SLOT)
                {
                    if(!isnull(value_string[index]))
                    {
                        GetDynamicObjectMaterialText(DynamicObject[slot], index, text_text, text_size, text_fontface, text_fontsize, text_fontbold, text_fontcolor, text_backcolor, text_alignment);
                        SetDynamicObjectMaterialText(DynamicObject[slot], index, text_text, text_size, text_fontface, text_fontsize, text_fontbold, text_fontcolor, value_int[index], text_alignment);
                        DynamicObjectMaterial[slot][index] = OBJECT_MATERIAL_TYPE_MESSAGE;
                    }
                }

                cache_get_value(i, "text_alignment", params);
                unformat(params, "p<|>dddddddddd", value_int[0], value_int[1], value_int[2], value_int[3], value_int[4], value_int[5], value_int[6], value_int[7], value_int[8], value_int[9]);
                Loop(index, MAX_OBJECT_MATERIAL_SLOT)
                {
                    if(!isnull(value_string[index]))
                    {
                        GetDynamicObjectMaterialText(DynamicObject[slot], index, text_text, text_size, text_fontface, text_fontsize, text_fontbold, text_fontcolor, text_backcolor, text_alignment);
                        SetDynamicObjectMaterialText(DynamicObject[slot], index, text_text, text_size, text_fontface, text_fontsize, text_fontbold, text_fontcolor, text_backcolor, value_int[index]);
                        DynamicObjectMaterial[slot][index] = OBJECT_MATERIAL_TYPE_MESSAGE;
                    }
                }

                Iter_Add(DynamicObjects, slot);
                ObjectEditor[slot] = INVALID_PLAYER_ID;
                RefreshDynamicObjectLabel(slot);
            }
            else if(type == 1)
            {
                AddRemoveBuilding(model, x, y, z, radius);
                RefreshRemoveBuildings(forplayerid);
            }
        }
    }
    return 1;
}