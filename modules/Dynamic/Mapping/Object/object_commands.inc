YCMD:object(playerid, params[], help) 
{
    new option[50], string[200], bool:syntax = true;

    if(sscanf(params, "s[50]S()[200]", option, string)) 
    {
        syntax = false;
    }
    else 
    {
        if(!strcmp(option, "create", true)) 
        {
            new model;
            if(sscanf(string, "d", model))
                return SendUsageMessage(playerid, "/object create [model]");

            if(!IsValidObjectModel(model))
                return SendErrorMessage(playerid, "Model object tidak ada!");

			new slot = Iter_Free(DynamicObjects);
			if(slot != cellmin)
			{
				new Float:cPos[3];
				GetPlayerPos(playerid,cPos[0],cPos[1],cPos[2]);

				DynamicObject[slot] = CreateDynamicObject(model,cPos[0],cPos[1],cPos[2],0.0,0.0,0.0);
                RefreshDynamicObjectLabel(slot);
                ObjectEditor[slot] = INVALID_PLAYER_ID;
                
				Iter_Add(DynamicObjects,slot);
				Streamer_Update(playerid);

				SendClientMessageEx(playerid, COLOR_REN, "OBJECT: "WHITE"Object dibuat dengan "YELLOW"ID %d"WHITE", total objects: "LG"%d", slot, Iter_Count(DynamicObjects));
			}
            else SendErrorMessage(playerid, "Maksimal edit object penuh!");
        }
        else if(!strcmp(option, "remove", true) || !strcmp(option, "delete", true))
        {
            new slot;
            if(sscanf(string, "d", slot))
                return SendUsageMessage(playerid, "/object remove [slot]");

            
			if(Iter_Contains(DynamicObjects, slot))
			{
				Iter_Remove(DynamicObjects,slot);
				DestroyDynamicObject(DynamicObject[slot]);
                RefreshDynamicObjectLabel(slot);
				Loop(i,MAX_OBJECT_MATERIAL_SLOT)
				{
					DynamicObjectMaterial[slot][i] = OBJECT_MATERIAL_TYPE_NONE;
				}
				SendClientMessageEx(playerid, COLOR_REN, "OBJECT: "WHITE"Object dengan "LR"ID %d "WHITE"telah dihapus, total objects: "LG"%d", slot, Iter_Count(DynamicObjects));
			}
            else SendErrorMessage(playerid, "Object dengan slot itu tidak terdeteksi!");
        }
        else if(!strcmp(option, "clear", true))
        {
            Dialog_Show(playerid, Object_Clear, DIALOG_STYLE_MSGBOX, "Clear Object", "Anda yakin akan menghapus semua object?", "Clear", "Cancel");
        }
        else if(!strcmp(option, "clone", true))
        {
            new slot;
            if(sscanf(string, "d", slot))
                return SendUsageMessage(playerid, "/object clone [object id]");

            if(Iter_Contains(DynamicObjects, slot))
            {
                new slot2 = Iter_Free(DynamicObjects);
                if(slot2 != cellmin)
				{
                    new model,Float:cPos[3],Float:cRot[3];
					model = Streamer_GetIntData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_MODEL_ID);
					Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_X, cPos[0]);
					Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_Y, cPos[1]);
					Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_Z, cPos[2]);
					Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_R_X, cRot[0]);
					Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_R_Y, cRot[1]);
					Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_R_Z, cRot[2]);
                    DynamicObject[slot2] = CreateDynamicObject(model, cPos[0], cPos[1], cPos[2], cRot[0], cRot[1], cRot[2]);
                    Iter_Add(DynamicObjects, slot2);
                    RefreshDynamicObjectLabel(slot2);
                    
                    ObjectEditor[slot] = INVALID_PLAYER_ID;

                    Loop(index,MAX_OBJECT_MATERIAL_SLOT)
					{
						if(DynamicObjectMaterial[slot][index] == OBJECT_MATERIAL_TYPE_TEXTURE)
						{
							new modelid,txdname[32],texturename[32],color;
							GetDynamicObjectMaterial(DynamicObject[slot], index, modelid, txdname, texturename, color);
							SetDynamicObjectMaterial(DynamicObject[slot2], index, modelid, txdname, texturename, color);
							DynamicObjectMaterial[slot2][index] = OBJECT_MATERIAL_TYPE_TEXTURE;
						}
						else if(DynamicObjectMaterial[slot][index] == OBJECT_MATERIAL_TYPE_MESSAGE)
						{
							new text[128], resolution, font[20], size, bold, fcolor, bcolor, alignment;
							GetDynamicObjectMaterialText(DynamicObject[slot], index, text, resolution, font, size, bold, fcolor, bcolor, alignment);
							SetDynamicObjectMaterialText(DynamicObject[slot2], index, text, resolution, font, size, bold, fcolor, bcolor, alignment);
							DynamicObjectMaterial[slot2][index] = OBJECT_MATERIAL_TYPE_MESSAGE;
						}
					}
                    Streamer_Update(playerid);
                    SendClientMessageEx(playerid, COLOR_REN, "OBJECT: "WHITE"Duplikasi object "YELLOW"ID %d "WHITE" dengan "YELLOW"ID %d"WHITE", total objects: "GREEN"%d",slot, slot2, Iter_Count(DynamicObjects));
                }
                else SendErrorMessage(playerid, "Maksimal edit object penuh!");
            }
            else SendErrorMessage(playerid, "Object tidak terdeteksi!");
        }
        else if(!strcmp(option, "x", true))
        {
            new slot, Float:amount, Float:cPos[3];
            if(sscanf(string, "df(1.0)", slot, amount))
                return SendUsageMessage(playerid, "/object x [slot] [Float: amount = 1.0]");

            if(Iter_Contains(DynamicObjects, slot))
            {
                GetDynamicObjectPos(DynamicObject[slot], cPos[0], cPos[1], cPos[2]);
                SetDynamicObjectPos(DynamicObject[slot], cPos[0] + amount, cPos[1], cPos[2]);
            }
            else SendErrorMessage(playerid, "Object tidak terdeteksi!");
        }
        else if(!strcmp(option, "y", true))
        {
            new slot, Float:amount, Float:cPos[3];
            if(sscanf(string, "df(1.0)", slot, amount))
                return SendUsageMessage(playerid, "/object y [slot] [Float: amount = 1.0]");

            if(Iter_Contains(DynamicObjects, slot))
            {
                GetDynamicObjectPos(DynamicObject[slot], cPos[0], cPos[1], cPos[2]);
                SetDynamicObjectPos(DynamicObject[slot], cPos[0], cPos[1] + amount, cPos[2]);
            }
            else SendErrorMessage(playerid, "Object tidak terdeteksi!");
        }
        else if(!strcmp(option, "z", true))
        {
            new slot, Float:amount, Float:cPos[3];
            if(sscanf(string, "df(1.0)", slot, amount))
                return SendUsageMessage(playerid, "/object z [slot] [Float: amount = 1.0]");

            if(Iter_Contains(DynamicObjects, slot))
            {
                GetDynamicObjectPos(DynamicObject[slot], cPos[0], cPos[1], cPos[2]);
                SetDynamicObjectPos(DynamicObject[slot], cPos[0], cPos[1], cPos[2] + amount);
            }
            else SendErrorMessage(playerid, "Object tidak terdeteksi!");
        }
        else if(!strcmp(option, "rx", true))
        {
            new slot, Float:amount, Float:cPos[3];
            if(sscanf(string, "df(1.0)", slot, amount))
                return SendUsageMessage(playerid, "/object rx [slot] [Float: amount = 1.0]");

            if(Iter_Contains(DynamicObjects, slot))
            {
                GetDynamicObjectRot(DynamicObject[slot], cPos[0], cPos[1], cPos[2]);
                SetDynamicObjectRot(DynamicObject[slot], cPos[0] + amount, cPos[1], cPos[2]);
            }
            else SendErrorMessage(playerid, "Object tidak terdeteksi!");
        }
        else if(!strcmp(option, "ry", true))
        {
            new slot, Float:amount, Float:cPos[3];
            if(sscanf(string, "df(1.0)", slot, amount))
                return SendUsageMessage(playerid, "/object ry [slot] [Float: amount = 1.0]");

            if(Iter_Contains(DynamicObjects, slot))
            {
                GetDynamicObjectRot(DynamicObject[slot], cPos[0], cPos[1], cPos[2]);
                SetDynamicObjectRot(DynamicObject[slot], cPos[0], cPos[1] + amount, cPos[2]);
            }
            else SendErrorMessage(playerid, "Object tidak terdeteksi!");
        }
        else if(!strcmp(option, "rz", true))
        {
            new slot, Float:amount, Float:cPos[3];
            if(sscanf(string, "df(1.0)", slot, amount))
                return SendUsageMessage(playerid, "/object rz [slot] [Float: amount = 1.0]");

            if(Iter_Contains(DynamicObjects, slot))
            {
                GetDynamicObjectRot(DynamicObject[slot], cPos[0], cPos[1], cPos[2]);
                SetDynamicObjectRot(DynamicObject[slot], cPos[0], cPos[1], cPos[2] + amount);
            }
            else SendErrorMessage(playerid, "Object tidak terdeteksi!");
        }
        else if(!strcmp(option, "edit", true)) 
        {
            new slot;
            if(sscanf(string, "d", slot))
                return SendUsageMessage(playerid, "/object edit [object id]");

            if(Iter_Contains(DynamicObjects, slot))
            {
                if(player_editing_object_id[playerid] != -1)
                    return SendErrorMessage(playerid, "Selesaikan edit object sebelumnya terlebih dahulu!, %d", player_editing_object_id[playerid]);

                if(ObjectEditor[slot] != INVALID_PLAYER_ID)
                    return SendErrorMessage(playerid, "Object ini sedang diedit oleh seseorang!");

                SendClientMessageEx(playerid, COLOR_REN, "OBJECT: "WHITE"Editing object "YELLOW"id %d", slot);
                
                ObjectEditor[slot] = playerid;
                player_editing_object_id[playerid] = slot;
                EditDynamicObject(playerid, DynamicObject[slot]);
            }
            else SendErrorMessage(playerid, "Object tidak terdeteksi!");
        }
        else if(!strcmp(option, "select", true)) 
        {
            if(player_editing_object_id[playerid] != -1)
                return SendErrorMessage(playerid, "Selesaikan edit object sebelumnya terlebih dahulu!");

            EditDynamicObjectMode[playerid] = OBJECT_SELECT_EDITOR;

            SelectObject(playerid);

            SendClientMessageEx(playerid, COLOR_REN, "OBJECT: "WHITE"Klik pada object untuk mengedit");
        }
        else if(!strcmp(option, "goto", true)) 
        {
            new slot;
            if(sscanf(string, "d", slot))
                return SendUsageMessage(playerid, "/object goto [object id]");

            if(Iter_Contains(DynamicObjects, slot))
            {
                new Float:cPos[3];
                Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_X, cPos[0]);
				Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_Y, cPos[1]);
				Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_Z, cPos[2]);

                SetPlayerPos(playerid, cPos[0] + 0.5, cPos[1] + 0.5, cPos[2]);

                SendClientMessageEx(playerid, COLOR_REN, "OBJECT: "WHITE"Teleportasi ke object "YELLOW"id %d", slot);
            }
            else SendErrorMessage(playerid, "Object tidak terdeteksi!");
        }
        else if(!strcmp(option, "gethere", true)) 
        {
            new slot;
            if(sscanf(string, "d", slot))
                return SendUsageMessage(playerid, "/object gethere [object id]");

            if(Iter_Contains(DynamicObjects, slot))
            {
                new Float:cPos[3];
                GetPlayerPos(playerid, cPos[0], cPos[1], cPos[2]);
                SetDynamicObjectPos(DynamicObject[slot], cPos[0], cPos[1], cPos[2]);

                SendClientMessageEx(playerid, COLOR_REN, "OBJECT: "WHITE"Teleportasi object "YELLOW"id %d"WHITE" ke lokasi anda", slot);
            }
            else SendErrorMessage(playerid, "Object tidak terdeteksi!");
        }
        else if(!strcmp(option, "model", true)) 
        {
            new slot, model, oldmodel;
            if(sscanf(string, "dd", slot, model))
                return SendUsageMessage(playerid, "/object model [object id] [model]");

            if(Iter_Contains(DynamicObjects, slot))
            {
                oldmodel = Streamer_GetIntData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_MODEL_ID);
                Streamer_SetIntData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_MODEL_ID, model);
                Streamer_Update(playerid);

                SendClientMessageEx(playerid, COLOR_REN, "OBJECT: "WHITE"Mengubah model object "YELLOW"id %d"WHITE" dari "LG"%d"WHITE" menjadi "LB"%d", slot, oldmodel, model);
            }
            else SendErrorMessage(playerid, "Object tidak terdeteksi!");
        }
        else if(!strcmp(option, "material", true))
        {
			new slot,index,model,txdname[32],texture[32],color[4];
			if(!sscanf(string,"ddds[32]s[32]D(0)D(0)D(0)D(0)",slot,index,model,txdname,texture,color[0],color[1],color[2],color[3]))
			{
				if((index >= MAX_OBJECT_MATERIAL_SLOT) || (index < 0)) return SendErrorMessage(playerid,"Index tidak dapat kurang dari 0 dan lebih dari 9");
				if(Iter_Contains(DynamicObjects,slot))
				{
					if(model == 0)
					{
						model = Streamer_GetIntData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_MODEL_ID);
					}
					SetDynamicObjectMaterial(DynamicObject[slot], index, model, txdname, texture, GetColourCode(color[0],color[1],color[2],color[3],COLOUR_MODE_ARGB));
					DynamicObjectMaterial[slot][index] = OBJECT_MATERIAL_TYPE_TEXTURE;
				}
				else SendErrorMessage(playerid, "Object tidak terdeteksi!");
			}
			else SendUsageMessage(playerid,"/object material [object id] [index] [model] [txdname] [texture] [opt: alpha] [opt: red]  [opt: green]  [opt: blue]");
        }
        else if(!strcmp(option, "textprop", true))
        {
			new slot,index;
			if(!sscanf(string,"dD(0)",slot,index))
			{
				if((index >= MAX_OBJECT_MATERIAL_SLOT) || (index < 0)) return SendErrorMessage(playerid,"Index tidak dapat kurang dari 0 dan lebih dari 9");
				if(Iter_Contains(DynamicObjects, slot))
				{
					if(DynamicObjectMaterial[slot][index] != OBJECT_MATERIAL_TYPE_MESSAGE)
					{
						SetDynamicObjectMaterialText(DynamicObject[slot], index, "Text Here", OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, 1, 0xFFFFFFFF, 0xFF000000);
						DynamicObjectMaterial[slot][index] = OBJECT_MATERIAL_TYPE_MESSAGE;
					}
					player_editing_object_id[playerid] = slot;
                    player_editing_object_index[playerid] = index;
					Dialog_Show(playerid, Object_TextMenu, DIALOG_STYLE_LIST, "Material Text", "Text\nResolution\nFont\nFont Size\nToggle Bold\nFont Color\nBackground Color\nText Alignment\nReset", "Select", "Close");
				}
				else SendErrorMessage(playerid, "Object tidak terdeteksi!");
			}
			else SendUsageMessage(playerid,"/object textprop [object id] [index]");
        }
        else if(!strcmp(option, "resetmaterial", true)) 
        {
            new slot;
            if(sscanf(string, "d", slot))
                return SendUsageMessage(playerid, "/object resetmaterial [object id]");

            if(Iter_Contains(DynamicObjects, slot))
            {
                new model, Float:cPos[3], Float:cRot[3];
				model = Streamer_GetIntData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_MODEL_ID);
				Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_X, cPos[0]);
				Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_Y, cPos[1]);
				Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_Z, cPos[2]);
				Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_R_X, cRot[0]);
				Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_R_Y, cRot[1]);
				Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_R_Z, cRot[2]);

				DestroyDynamicObject(DynamicObject[slot]);
                RefreshDynamicObjectLabel(slot);
				Loop(index,MAX_OBJECT_MATERIAL_SLOT)
				{
					DynamicObjectMaterial[slot][index] = OBJECT_MATERIAL_TYPE_NONE;
				}

				DynamicObject[slot] = CreateDynamicObject(model, cPos[0], cPos[1], cPos[2], cRot[0], cRot[1], cRot[2]);
				Streamer_Update(playerid);
                RefreshDynamicObjectLabel(slot);

                ObjectEditor[slot] = INVALID_PLAYER_ID;

                SendClientMessageEx(playerid, COLOR_REN, "OBJECT: "WHITE"Menghapus semua tekstur object "YELLOW"id %d", slot);
            }
            else SendErrorMessage(playerid, "Object tidak terdeteksi!");
        }
        else if(!strcmp(option, "deletemode", true)) 
        {
            EditDynamicObjectMode[playerid] = OBJECT_SELECT_DELETE;
            SendClientMessageEx(playerid, COLOR_REN, "OBJECT: "WHITE"Klik pada object untuk menghapus");
            SelectObject(playerid);
        }
        else if(!strcmp(option, "paintbrush", true)) 
        {
			new index, model, txdname[32], texture[32], color[4];
			if(!sscanf(string, "dds[32]s[32]D(0)D(0)D(0)D(0)", index, model, txdname, texture, color[0], color[1], color[2], color[3]))
			{
				if((index >= MAX_OBJECT_MATERIAL_SLOT) || (index < 0)) return SendErrorMessage(playerid,"Index tidak dapat kurang dari 0 dan lebih dari 9");
				
                format(string,sizeof(string),"%d|%d|%s|%s|%d",index,model,txdname,texture,GetColourCode(color[0],color[1],color[2],color[3],COLOUR_MODE_ARGB));
				SetPVarString(playerid,"PaintParam",string);

				EditDynamicObjectMode[playerid] = OBJECT_SELECT_PAINT;
				SendClientMessageEx(playerid, COLOR_REN, "OBJECT: "WHITE"Klik pada object untuk memberi tekstur");
				SelectObject(playerid);
			}
			else SendUsageMessage(playerid,"/object paintbrush [index] [model] [txdname] [texture] [opt: alpha] [opt: red]  [opt: green]  [opt: blue]");
        }
        else if(!strcmp(option, "cleanbrush", true)) 
        {
            EditDynamicObjectMode[playerid] = OBJECT_SELECT_CLEAN;
            SendClientMessageEx(playerid, COLOR_REN, "OBJECT: "WHITE"Klik pada object untuk membersihkan tekstur");
            SelectObject(playerid);
        }
        else if(!strcmp(option, "save", true)) 
        {
            if(Iter_Count(DynamicObjects) == 0 && Iter_Count(RemoveObject) == 0)
                return SendErrorMessage(playerid, "Tidak ada object untuk disimpan!");

            new foldername[50];
            if(sscanf(string, "s[50]", foldername))
                return SendUsageMessage(playerid, "/object save [foldername]");

            if(!IsValidMappingFolder(foldername)) 
            {
                new Float:x, Float:y, Float:z;
                GetPlayerPos(playerid, x, y, z);
                CreateMappingFolder(foldername, GetName(playerid), Now(), x, y, z);
                SaveObjectToMappingFolder(foldername);
                SaveRemoveObjectToMappingFolder(foldername);

                SendClientMessageEx(playerid, COLOR_REN, "OBJECT: "WHITE"Menyimpan object dengan folder "YELLOW"%s"WHITE", total objects: "LG"%d", foldername, Iter_Count(DynamicObjects));
                SendClientMessageEx(playerid, COLOR_REN, "REMOVE-OBJECT: "WHITE"Menyimpan object yang dihapus dengan folder "YELLOW"%s"WHITE", total object dihapus: "YELLOW"%d", foldername, Iter_Count(RemoveObject));
            }
            else 
            {
                SendErrorMessage(playerid, "Object tidak dapat disimpan karena folder telah ada!");
            }
        }
        else if(!strcmp(option, "load", true)) 
        {
            new foldername[50];
            if(sscanf(string, "s[50]", foldername))
                return SendUsageMessage(playerid, "/object load [foldername]");

            if(IsValidMappingFolder(foldername)) 
            {
                new query[200];
                mysql_format(sql, query, sizeof(query), "SELECT * FROM `mapping_object` WHERE `folder` = '%e'", foldername);
                mysql_tquery(sql, query, "LoadObjectFromMappingFolder", "d", playerid);

                SendClientMessageEx(playerid, COLOR_REN, "OBJECT: "WHITE"Memuat semua object dari mapping folder "YELLOW"%s", foldername);
            }
            else 
            {
                SendErrorMessage(playerid, "Mapping dengan folder tersebut tidak ada, gunakan '/map list' untuk melihat daftar map yang ada!");
            }
        }
        else syntax = false;
    }

    if(syntax == false)
    {
        SendUsageMessage(playerid, "/object [option]");
        SendClientMessageEx(playerid, COLOR_REN, "OPTION: create remove clear clone x y z rx ry rz edit select goto gethere");
        SendClientMessageEx(playerid, COLOR_REN, "OPTION: model material textprop resetmaterial deletemode paintbrush cleanbrush");
        SendClientMessageEx(playerid, COLOR_REN, "OPTION: save load");
    }
    return 1;
}