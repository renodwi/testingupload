YCMD:modif(playerid, params[], help)
{
    if(!IsPlayerInAnyVehicle(playerid)) return 1;

    ShowPlayerVehicleTuneDialog(playerid, VEHICLE_TUNE_LIST, GetPlayerVehicleID(playerid)); 
    return 1;
}

YCMD:camerapos(playerid, params[], help) 
{
    new vehicleid = GetPlayerVehicleID(playerid), Float:num1, Float:num2, Float:num3, Float:Pos[3];

    if(sscanf(params, "fff", num1, num2, num3))
        return SendUsageMessage(playerid, "/camerapos [num1] [num2] [num3]");

    GetVehicleCameraPos(vehicleid, Pos[0], Pos[1], Pos[2], num1, num2, num3);
	SetPlayerCameraPos(playerid, Pos[0], Pos[1], Pos[2] );
	GetVehiclePos(vehicleid, Pos[0],Pos[1],Pos[2]);
	SetPlayerCameraLookAt(playerid, Pos[0],Pos[1],Pos[2]);
    return 1;
}

stock ShowPlayerVehicleTuneDialog(playerid, type, vehicleid) 
{
    switch(type) 
    {
        case VEHICLE_TUNE_LIST:
        {
            Dialog_Show(playerid, VehicleTune_List, DIALOG_STYLE_LIST, "Vehicle Modification", "Paintjobs\nColors\nExhausts\nFront Bumper\nRear Bumper\nRoof\nSpoilers\nSide Skirts\nWheels\nHydraulics\nNitro", "Pilih", "Cancel");
        }
        case VEHICLE_TUNE_PAINTJOB:
        {
            new paintjobid = -1;

            Loop(i, NUMBER_TYPE_PAINTJOB) 
            {
                if(paintjobInfo[i][paintjobModel] == GetVehicleModel(vehicleid)) 
                {
                    paintjobid = i;
                    break;
                } 
                else continue;
            }

            if(paintjobid == -1)
                return SendErrorMessage(playerid, "Kendaraan ini tidak dapat dipasangi paintjob!");

            GetVehicleColor(vehicleid, default_vehicle_color[vehicleid][0], default_vehicle_color[vehicleid][1]);
            GetVehiclePaintjob(vehicleid, default_vehicle_paintjob[vehicleid]);

            if(default_vehicle_paintjob[vehicleid] == -1) default_vehicle_paintjob[vehicleid] = 3;

            SetPlayerTuneInfo(playerid, paintjobid, PLAYER_TUNE_PAINTJOB, vehicleid);

            ChangeVehicleColor(vehicleid, 1, 1);
            ChangeVehiclePaintjob(vehicleid, paintjobInfo[paintjobid][paintjobID]);
            
            TogglePlayerControllable(playerid, false);
            ShowPlayerVTuneTD(playerid, GetVehicleModelName(GetVehicleModel(vehicleid)), paintjobInfo[paintjobid][paintjobName], paintjobInfo[paintjobid][paintjobNeeds]);
        
            new Float:Pos[3];
            GetVehicleCameraPos(vehicleid, Pos[0], Pos[1], Pos[2], 4, 0, 5);
			SetPlayerCameraPos(playerid, Pos[0], Pos[1], Pos[2]);
			GetVehiclePos(vehicleid, Pos[0], Pos[1], Pos[2]);
			SetPlayerCameraLookAt(playerid, Pos[0],Pos[1],Pos[2]);
        }
        case VEHICLE_TUNE_COLOR:
        {
            Dialog_Show(playerid, VehicleTune_ColorMenu, DIALOG_STYLE_LIST, "Vehicle Modification - Color", "List warna kendaraan (hanya dapat 1 warna)\nCari warna berdasarkan kode...", "Pilih", "Kembali");
        }
        case VEHICLE_TUNE_EXHAUST:
        {
            VTuneCarmod(playerid, vehicleid, CARMODTYPE_EXHAUST);
        
            new Float:Pos[3];
            GetVehicleCameraPos(vehicleid, Pos[0], Pos[1], Pos[2], -2, -5, 0);
			SetPlayerCameraPos(playerid, Pos[0], Pos[1], Pos[2]);
			GetVehiclePos(vehicleid, Pos[0], Pos[1], Pos[2]);
			SetPlayerCameraLookAt(playerid, Pos[0],Pos[1],Pos[2]);
        }
        case VEHICLE_TUNE_FRONTBUMPER:
        {
            VTuneCarmod(playerid, vehicleid, CARMODTYPE_FRONT_BUMPER);
        
            new Float:Pos[3];
            GetVehicleCameraPos(vehicleid, Pos[0], Pos[1], Pos[2], 0, 6, 0.5);
			SetPlayerCameraPos(playerid, Pos[0], Pos[1], Pos[2]);
			GetVehiclePos(vehicleid, Pos[0], Pos[1], Pos[2]);
			SetPlayerCameraLookAt(playerid, Pos[0],Pos[1],Pos[2]);
        }
        case VEHICLE_TUNE_REARBUMBER:
        {
            VTuneCarmod(playerid, vehicleid, CARMODTYPE_REAR_BUMPER);
        
            new Float:Pos[3];
            GetVehicleCameraPos(vehicleid, Pos[0], Pos[1], Pos[2], 0, -6, 0.5);
			SetPlayerCameraPos(playerid, Pos[0], Pos[1], Pos[2]);
			GetVehiclePos(vehicleid, Pos[0], Pos[1], Pos[2]);
			SetPlayerCameraLookAt(playerid, Pos[0],Pos[1],Pos[2]);
        }
        case VEHICLE_TUNE_ROOF:
        {
            VTuneCarmod(playerid, vehicleid, CARMODTYPE_ROOF);
        
            new Float:Pos[3];
            GetVehicleCameraPos(vehicleid, Pos[0], Pos[1], Pos[2], 0, 6, 2);
			SetPlayerCameraPos(playerid, Pos[0], Pos[1], Pos[2]);
			GetVehiclePos(vehicleid, Pos[0], Pos[1], Pos[2]);
			SetPlayerCameraLookAt(playerid, Pos[0],Pos[1],Pos[2]);
        }
        case VEHICLE_TUNE_SPOILERS:
        {
            VTuneCarmod(playerid, vehicleid, CARMODTYPE_SPOILER);
        
            new Float:Pos[3];
            GetVehicleCameraPos(vehicleid, Pos[0], Pos[1], Pos[2], 0, -6, 2);
			SetPlayerCameraPos(playerid, Pos[0], Pos[1], Pos[2]);
			GetVehiclePos(vehicleid, Pos[0], Pos[1], Pos[2]);
			SetPlayerCameraLookAt(playerid, Pos[0],Pos[1],Pos[2]);
        }
        case VEHICLE_TUNE_SIDESKIRT:
        {
            VTuneCarmod(playerid, vehicleid, CARMODTYPE_SIDESKIRT);
        
            new Float:Pos[3];
            GetVehicleCameraPos(vehicleid, Pos[0], Pos[1], Pos[2], 4, 0, 0.5);
			SetPlayerCameraPos(playerid, Pos[0], Pos[1], Pos[2]);
			GetVehiclePos(vehicleid, Pos[0], Pos[1], Pos[2]);
			SetPlayerCameraLookAt(playerid, Pos[0],Pos[1],Pos[2]);
        }
        case VEHICLE_TUNE_WHEEL:
        {
            VTuneCarmod(playerid, vehicleid, CARMODTYPE_WHEELS);
        
            new Float:Pos[3];
            GetVehicleCameraPos(vehicleid, Pos[0], Pos[1], Pos[2], 4, 0, 0.5);
			SetPlayerCameraPos(playerid, Pos[0], Pos[1], Pos[2]);
			GetVehiclePos(vehicleid, Pos[0], Pos[1], Pos[2]);
			SetPlayerCameraLookAt(playerid, Pos[0],Pos[1],Pos[2]);
        }
        case VEHICLE_TUNE_HYDRAULICS:
        {
            VTuneCarmod(playerid, vehicleid, CARMODTYPE_HYDRAULICS);
        
            new Float:Pos[3];
            GetVehicleCameraPos(vehicleid, Pos[0], Pos[1], Pos[2], 2, 2, 2);
			SetPlayerCameraPos(playerid, Pos[0], Pos[1], Pos[2]);
			GetVehiclePos(vehicleid, Pos[0], Pos[1], Pos[2]);
			SetPlayerCameraLookAt(playerid, Pos[0],Pos[1],Pos[2]);
        }
        case VEHICLE_TUNE_NITRO:
        {
            VTuneCarmod(playerid, vehicleid, CARMODTYPE_NITRO);
        
            new Float:Pos[3];
            GetVehicleCameraPos(vehicleid, Pos[0], Pos[1], Pos[2], 0, -6, 2);
			SetPlayerCameraPos(playerid, Pos[0], Pos[1], Pos[2]);
			GetVehiclePos(vehicleid, Pos[0], Pos[1], Pos[2]);
			SetPlayerCameraLookAt(playerid, Pos[0],Pos[1],Pos[2]);
        }
    }

    playervtuneInfo[playerid][playervtuneVehID] = vehicleid;
    return 1;
}

Dialog:VehicleTune_List(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    else
    {
        new vehicleid = GetPlayerVehicleID(playerid);
        playervtuneInfo[playerid][playervtuneStatus] = true;

        switch(listitem) 
        {
            case 0: ShowPlayerVehicleTuneDialog(playerid, VEHICLE_TUNE_PAINTJOB, vehicleid);
            case 1: ShowPlayerVehicleTuneDialog(playerid, VEHICLE_TUNE_COLOR, vehicleid);
            case 2: ShowPlayerVehicleTuneDialog(playerid, VEHICLE_TUNE_EXHAUST, vehicleid);
            case 3: ShowPlayerVehicleTuneDialog(playerid, VEHICLE_TUNE_FRONTBUMPER, vehicleid);
            case 4: ShowPlayerVehicleTuneDialog(playerid, VEHICLE_TUNE_REARBUMBER, vehicleid);
            case 5: ShowPlayerVehicleTuneDialog(playerid, VEHICLE_TUNE_ROOF, vehicleid);
            case 6: ShowPlayerVehicleTuneDialog(playerid, VEHICLE_TUNE_SPOILERS, vehicleid);
            case 7: ShowPlayerVehicleTuneDialog(playerid, VEHICLE_TUNE_SIDESKIRT, vehicleid);
            case 8: ShowPlayerVehicleTuneDialog(playerid, VEHICLE_TUNE_WHEEL, vehicleid);
            case 9: ShowPlayerVehicleTuneDialog(playerid, VEHICLE_TUNE_HYDRAULICS, vehicleid);
            case 10: ShowPlayerVehicleTuneDialog(playerid, VEHICLE_TUNE_NITRO, vehicleid);
        }
    }
    return 1;
}

Dialog:VehicleTune_ColorMenu(playerid, response, listitem, inputtext[])
{
    new tuneid, type, vehicleid;
    GetPlayerTuneInfo(playerid, tuneid, type, vehicleid);

    if(!response) return ShowPlayerVehicleTuneDialog(playerid, VEHICLE_TUNE_LIST, vehicleid); 
    else
    {
        switch(listitem)
        {
            case 0:
            {
                new slot;
                Loop(i, 254)
                {
                    slot = AddPlayerSelectionItem(playerid, GetVehicleModel(vehicleid), GetVehicleModelName(GetVehicleModel(vehicleid)), "Pilih warna kendaraan");
                    SetPlayerSelectionVehColor(playerid, slot, i, i);
                }

                ShowPlayerSelection(playerid, VehicleTune_ColorList, "Pilih warna kendaraan");
            }
            case 1:
            {
                Dialog_Show(playerid, VehicleTune_ColorCode, DIALOG_STYLE_INPUT, "Vehicle Modification - Color", "Masukkan kode warna gambar dengan input angka (dengan syntax {[warna 1] [warna 2]} contoh: 2 2)\n\nJika tidak mengetahui kode warna, silahkan cek di internet!", "Pilih", "Kembali");
            }
        }
    }
    return 1;
}

Selection:VehicleTune_ColorList(playerid, response, model, vehicle_color1, vehicle_color2)
{
    new tuneid, type, vehicleid;
    GetPlayerTuneInfo(playerid, tuneid, type, vehicleid);
    
    if(!response) return ShowPlayerVehicleTuneDialog(playerid, VEHICLE_TUNE_LIST, vehicleid); 
    else
    {
        GetVehicleColor(vehicleid, default_vehicle_color[vehicleid][0], default_vehicle_color[vehicleid][1]);

        ChangeVehicleColor(vehicleid, vehicle_color1, vehicle_color2);

        SetPlayerTuneInfo(playerid, vehicle_color1, PLAYER_TUNE_COLOR, vehicleid);

        TogglePlayerControllable(playerid, false);
        ShowPlayerVTuneTD(playerid, GetVehicleModelName(GetVehicleModel(vehicleid)), "Mengubah warna kendaraan", 10);
        
        new Float:Pos[3];
        GetVehicleCameraPos(vehicleid, Pos[0], Pos[1], Pos[2], 4, 0, 5);
		SetPlayerCameraPos(playerid, Pos[0], Pos[1], Pos[2]);
		GetVehiclePos(vehicleid, Pos[0], Pos[1], Pos[2]);
		SetPlayerCameraLookAt(playerid, Pos[0],Pos[1],Pos[2]);
    }
	return 1;
}

Dialog:VehicleTune_ColorCode(playerid, response, listitem, inputtext[])
{
    new tuneid, type, vehicleid;
    GetPlayerTuneInfo(playerid, tuneid, type, vehicleid);
    
    if(!response) return ShowPlayerVehicleTuneDialog(playerid, VEHICLE_TUNE_COLOR, vehicleid); 
    else
    {
        new color1, color2;

        if(sscanf(inputtext, "dd", color1, color2))
            return Dialog_Show(playerid, VehicleTune_ColorCode, DIALOG_STYLE_INPUT, "Vehicle Modification - Color", "Masukkan kode warna gambar dengan input angka (dengan syntax {[warna 1] [warna 2]} contoh: 2 2)\n\nJika tidak mengetahui kode warna, silahkan cek di internet!\n\nInput yang anda masukkan salah!", "Pilih", "Kembali");
    
        GetVehicleColor(vehicleid, default_vehicle_color[vehicleid][0], default_vehicle_color[vehicleid][1]);
        GetVehiclePaintjob(vehicleid, default_vehicle_paintjob[vehicleid]);

        ChangeVehicleColor(vehicleid, color1, color2);

        SetPlayerTuneInfo(playerid, color1, PLAYER_TUNE_COLOR, vehicleid);

        TogglePlayerControllable(playerid, false);
        ShowPlayerVTuneTD(playerid, GetVehicleModelName(GetVehicleModel(vehicleid)), "Mengubah warna kendaraan", 10);
        
        new Float:Pos[3];
        GetVehicleCameraPos(vehicleid, Pos[0], Pos[1], Pos[2], 4, 0, 5);
		SetPlayerCameraPos(playerid, Pos[0], Pos[1], Pos[2]);
		GetVehiclePos(vehicleid, Pos[0], Pos[1], Pos[2]);
		SetPlayerCameraLookAt(playerid, Pos[0],Pos[1],Pos[2]);
    }
    return 1;
}