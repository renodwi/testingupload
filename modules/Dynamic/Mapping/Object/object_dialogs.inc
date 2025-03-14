Dialog:Object_TextMenu(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		switch(listitem)
		{
			case 0:
			{
				Dialog_Show(playerid,Object_TextSetMessage,DIALOG_STYLE_INPUT,"Material Text: Set Text","Input text: (max length = 255 characters)","Set","Back");
				return 1;
			}
			case 1:
			{
				Dialog_Show(playerid,Object_TextSetResolution,DIALOG_STYLE_LIST,"Material Text: Set Resolution","32x32\n64x32\n64x64\n128x32\n128x64\n128x128\n256x32\n256x64\n256x128\n256x256\n512x64\n512x128\n512x256\n512x512","Set","Back");
				return 1;
			}
			case 2:
			{
				new fonts[256];
				Loop(i,sizeof(WinFonts))
				{
					strcat(fonts,WinFonts[i],sizeof(fonts));
					strcat(fonts,"\n",sizeof(fonts));
				}
                strcat(fonts,"Custom",sizeof(fonts));
				Dialog_Show(playerid,Object_TextSetFont,DIALOG_STYLE_LIST,"Material Text: Set Font",fonts,"Set","Back");
				return 1;
			}
			case 3:
			{
				Dialog_Show(playerid,Object_TextSetFontSize,DIALOG_STYLE_INPUT,"Material Text: Set Font Size","Input font size: (1-255)","Set","Back");
				return 1;
			}
			case 4:
			{
				new text[256],size,font[32],fsize,bold,fcolor,bcolor,alignment;
				new slot = player_editing_object_id[playerid],
			    	index = player_editing_object_index[playerid];
			    GetDynamicObjectMaterialText(DynamicObject[slot],index,text,size,font,fsize,bold,fcolor,bcolor,alignment);
			    SetDynamicObjectMaterialText(DynamicObject[slot],index,text,size,font,fsize,((bold == 1) ? 0 : 1),fcolor,bcolor,alignment);
			    Dialog_Show(playerid,Object_TextMenu,DIALOG_STYLE_LIST,"Material Text","Text\nResolution\nFont\nFont Size\nToggle Bold\nFont Color\nBackground Color\nText Alignment\nReset","Select","Close");
			    return 1;
			}
			case 5:
			{
				ShowPlayerColorList(playerid, Obj_TextFontColor, "Material Text: Set Font Color", "Set", "Back");
				return 1;
			}
			case 6:
			{
				ShowPlayerColorList(playerid, Obj_TextSetColor, "Material Text: Set Background Color", "Set", "Back");
				return 1;
			}
			case 7:
			{
				Dialog_Show(playerid,Object_TextSetAlignment,DIALOG_STYLE_LIST,"Material Text: Set Alignment","Left\nCenter\nRight","Set","Back");
				return 1;
			}
			case 8:
			{
				new Float:cPos[3],Float:cRot[3],
					slot = player_editing_object_id[playerid],
					index = player_editing_object_index[playerid];
				GetDynamicObjectPos(DynamicObject[slot],cPos[0],cPos[1],cPos[2]);
				GetDynamicObjectRot(DynamicObject[slot],cRot[0],cRot[1],cRot[2]);
				new temp = CreateDynamicObject(Streamer_GetIntData(STREAMER_TYPE_OBJECT,DynamicObject[slot],E_STREAMER_MODEL_ID),cPos[0],cPos[1],cPos[2],cRot[0],cRot[1],cRot[2]);
				DynamicObjectMaterial[slot][index] = 0;
				Loop(i,MAX_OBJECT_MATERIAL_SLOT)
				{
					if(DynamicObjectMaterial[slot][i] == OBJECT_MATERIAL_TYPE_TEXTURE)
					{
						new modelid,txdname[32],texturename[32],color;
						GetDynamicObjectMaterial(DynamicObject[slot],i,modelid,txdname,texturename,color);
						SetDynamicObjectMaterial(temp,i,modelid,txdname,texturename,color);
					}
					else if(DynamicObjectMaterial[slot][i] == OBJECT_MATERIAL_TYPE_MESSAGE)
					{
						new text[256],size,font[32],fsize,bold,fcolor,bcolor,alignment;
						GetDynamicObjectMaterialText(DynamicObject[slot],i,text,size,font,fsize,bold,fcolor,bcolor,alignment);
					    SetDynamicObjectMaterialText(temp,i,text,size,font,fsize,bold,fcolor,bcolor,alignment);
					}
				}
				DestroyDynamicObject(DynamicObject[slot]);
				DynamicObject[slot] = temp;
				Streamer_Update(playerid,STREAMER_TYPE_OBJECT);
			}
		}
	}
	DeletePVar(playerid,"EditingObject");
	DeletePVar(playerid,"EditingIndex");
	return 1;
}
Dialog:Object_TextSetMessage(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new text[256],size,font[32],fsize,bold,fcolor,bcolor,alignment;
		new slot = player_editing_object_id[playerid],
	    	index = player_editing_object_index[playerid];
	    GetDynamicObjectMaterialText(DynamicObject[slot],index,text,size,font,fsize,bold,fcolor,bcolor,alignment);
	    SetDynamicObjectMaterialText(DynamicObject[slot],index,((IsNull(inputtext)) ? (text) : (inputtext)),size,font,fsize,bold,fcolor,bcolor,alignment);
	}
	Dialog_Show(playerid,Object_TextMenu,DIALOG_STYLE_LIST,"Material Text","Text\nResolution\nFont\nFont Size\nToggle Bold\nFont Color\nBackground Color\nText Alignment\nReset","Select","Close");
	return 1;
}
Dialog:Object_TextSetResolution(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new text[256],size,font[32],fsize,bold,fcolor,bcolor,alignment;
		new slot = player_editing_object_id[playerid],
	    	index = player_editing_object_index[playerid];
	    GetDynamicObjectMaterialText(DynamicObject[slot],index,text,size,font,fsize,bold,fcolor,bcolor,alignment);
	    size = ((listitem+1)*10);
	    SetDynamicObjectMaterialText(DynamicObject[slot],index,text,size,font,fsize,bold,fcolor,bcolor,alignment);
	}
	Dialog_Show(playerid,Object_TextMenu,DIALOG_STYLE_LIST,"Material Text","Text\nResolution\nFont\nFont Size\nToggle Bold\nFont Color\nBackground Color\nText Alignment\nReset","Select","Close");
	return 1;
}
Dialog:Object_TextSetFont(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		if(listitem < sizeof(WinFonts))
		{
			new text[256],size,font[32],fsize,bold,fcolor,bcolor,alignment;
			new slot = player_editing_object_id[playerid],
		    	index = player_editing_object_index[playerid];
		    GetDynamicObjectMaterialText(DynamicObject[slot],index,text,size,font,fsize,bold,fcolor,bcolor,alignment);
		    SetDynamicObjectMaterialText(DynamicObject[slot],index,text,size,WinFonts[listitem],fsize,bold,fcolor,bcolor,alignment);
		}
		else
		{
			Dialog_Show(playerid,Object_TextSetCustomFont,DIALOG_STYLE_INPUT,"Material Text: Set Custom Font","Input font name:","Input","Back");
		}
	}
	Dialog_Show(playerid,Object_TextMenu,DIALOG_STYLE_LIST,"Material Text","Text\nResolution\nFont\nFont Size\nToggle Bold\nFont Color\nBackground Color\nText Alignment\nReset","Select","Close");
	return 1;
}
Dialog:Object_TextSetCustomFont(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new text[256],size,font[32],fsize,bold,fcolor,bcolor,alignment;
		new slot = player_editing_object_id[playerid],
	    	index = player_editing_object_index[playerid];
	    GetDynamicObjectMaterialText(DynamicObject[slot],index,text,size,font,fsize,bold,fcolor,bcolor,alignment);
	    SetDynamicObjectMaterialText(DynamicObject[slot],index,text,size,((IsNull(inputtext)) ? (text) : (inputtext)),fsize,bold,fcolor,bcolor,alignment);
	}
	Dialog_Show(playerid,Object_TextMenu,DIALOG_STYLE_LIST,"Material Text","Text\nResolution\nFont\nFont Size\nToggle Bold\nFont Color\nBackground Color\nText Alignment\nReset","Select","Close");
	return 1;
}
Dialog:Object_TextSetFontSize(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new text[256],size,font[32],fsize,bold,fcolor,bcolor,alignment;
		new slot = player_editing_object_id[playerid],
	    	index = player_editing_object_index[playerid];
	    GetDynamicObjectMaterialText(DynamicObject[slot],index,text,size,font,fsize,bold,fcolor,bcolor,alignment);
	    SetDynamicObjectMaterialText(DynamicObject[slot],index,text,size,font,((IsNull(inputtext)) ? strval(inputtext) : fsize),bold,fcolor,bcolor,alignment);
	}
	Dialog_Show(playerid,Object_TextMenu,DIALOG_STYLE_LIST,"Material Text","Text\nResolution\nFont\nFont Size\nToggle Bold\nFont Color\nBackground Color\nText Alignment\nReset","Select","Close");
	return 1;
}
ColorSelector:Obj_TextFontColor(playerid, response, color)
{
	if(response)
	{
		new text[256],size,font[32],fsize,bold,fcolor,bcolor,alignment;
		new slot = player_editing_object_id[playerid],
    	index = player_editing_object_index[playerid];
	    GetDynamicObjectMaterialText(DynamicObject[slot],index,text,size,font,fsize,bold,fcolor,bcolor,alignment);
	    fcolor = ConvertColor(color, COLOR_MODE_RGBA, COLOR_MODE_ARGB);
	    SetDynamicObjectMaterialText(DynamicObject[slot],index,text,size,font,fsize,bold,fcolor,bcolor,alignment);
	}
	Dialog_Show(playerid,Object_TextMenu,DIALOG_STYLE_LIST,"Material Text","Text\nResolution\nFont\nFont Size\nToggle Bold\nFont Color\nBackground Color\nText Alignment\nReset","Select","Close");
	return 1;
}
ColorSelector:Obj_TextSetColor(playerid, response, color)
{
	if(response)
	{
		new text[256],size,font[32],fsize,bold,fcolor,bcolor,alignment;
		new slot = player_editing_object_id[playerid],
	    index = player_editing_object_index[playerid];
	    GetDynamicObjectMaterialText(DynamicObject[slot],index,text,size,font,fsize,bold,fcolor,bcolor,alignment);
	    bcolor = ConvertColor(color, COLOR_MODE_RGBA, COLOR_MODE_ARGB);
		SetDynamicObjectMaterialText(DynamicObject[slot],index,text,size,font,fsize,bold,fcolor,bcolor,alignment);
	}
	Dialog_Show(playerid,Object_TextMenu,DIALOG_STYLE_LIST,"Material Text","Text\nResolution\nFont\nFont Size\nToggle Bold\nFont Color\nBackground Color\nText Alignment\nReset","Select","Close");
	return 1;
}
Dialog:Object_TextSetAlignment(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new text[256],size,font[32],fsize,bold,fcolor,bcolor,alignment;
		new slot = player_editing_object_id[playerid],
	    	index = player_editing_object_index[playerid];
	    GetDynamicObjectMaterialText(DynamicObject[slot],index,text,size,font,fsize,bold,fcolor,bcolor,alignment);
	    SetDynamicObjectMaterialText(DynamicObject[slot],index,text,size,font,fsize,bold,fcolor,bcolor,listitem);
	}
	Dialog_Show(playerid,Object_TextMenu,DIALOG_STYLE_LIST,"Material Text","Text\nResolution\nFont\nFont Size\nToggle Bold\nFont Color\nBackground Color\nText Alignment\nReset","Select","Close");
	return 1;
}

Dialog:Object_Clear(playerid, response, listitem, inputtext[])
{
	if(!response) return 1;
	else
	{
		foreach(new slot : DynamicObjects)
		{
			DestroyDynamicObject(DynamicObject[slot]);
			RefreshDynamicObjectLabel(slot);
			Loop(i, MAX_OBJECT_MATERIAL_SLOT)
			{
				DynamicObjectMaterial[slot][i] = OBJECT_MATERIAL_TYPE_NONE;
			}
		}
		SendClientMessageEx(playerid, COLOR_REN, "OBJECT: "YELLOW"%d object "WHITE"telah dihapus", Iter_Count(DynamicObjects));
		Iter_Clear(DynamicObjects);
	}
	return 1;
}