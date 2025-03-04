hook OnPlayerConnect(playerid)
{
    LoadPlayerVTuneTD(playerid);
    ResetPlayerTuneInfo(playerid);

    player_vtunetd_showed[playerid] = false;
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyPlayerVTuneTD(playerid);
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if(playertextid == td_vtune_next[playerid]) // Next
    {
        new tuneid, type, vehicleid;
        GetPlayerTuneInfo(playerid, tuneid, type, vehicleid);

        if(type == PLAYER_TUNE_PAINTJOB)
        {
            new paintjobid = -1;
            for(new i = (tuneid+1); i < NUMBER_TYPE_PAINTJOB; i++) 
            {
                if(paintjobInfo[i][paintjobModel] == GetVehicleModel(vehicleid)) 
                {
					paintjobid = i;
					break;
				}
			}

            if(paintjobid == -1) 
                return ShowPlayerFooter(playerid, 300, "Tidak ada paintjob yang kompatible untuk model kendaraan ini!");

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
        else if(type == PLAYER_TUNE_COLOR)
        {
            ShowPlayerVehicleTuneDialog(playerid, VEHICLE_TUNE_COLOR, vehicleid); 
        }
        else
        {
            new componentid = -1;
            for(new i = (tuneid+1); i < MAX_COMPONENTS; i++) 
            {
                if(componentInfo[i][componentType] == player_vtune_carmodtype[playerid]) 
                {
                    if(componentInfo[i][componentID] == IsComponentidCompatible(GetVehicleModel(vehicleid), componentInfo[i][componentID])) {
                        componentid = i;
                        break;
                    }
                    else continue;
                } 
                else continue;
            }

            if(componentid == -1)
            {
                Loop(i, MAX_COMPONENTS) 
                {
                    if(componentInfo[i][componentType] == player_vtune_carmodtype[playerid]) 
                    {
                        if(componentInfo[i][componentID] == IsComponentidCompatible(GetVehicleModel(vehicleid), componentInfo[i][componentID])) {
                            componentid = i;
                            break;
                        }
                        else continue;
                    } 
                    else continue;
                }
            }

            AddVehicleComponent(vehicleid, componentInfo[componentid][componentID]);

            SetPlayerTuneInfo(playerid, componentid, PLAYER_TUNE_COMPONENT, vehicleid);

            TogglePlayerControllable(playerid, false);
            ShowPlayerVTuneTD(playerid, GetVehicleModelName(GetVehicleModel(vehicleid)), componentInfo[componentid][componentName], componentInfo[componentid][componentNeeds]);
        }
    }
    else if(playertextid == td_vtune_previous[playerid])
    {
        new tuneid, type, vehicleid;
        GetPlayerTuneInfo(playerid, tuneid, type, vehicleid);

        if(type == PLAYER_TUNE_PAINTJOB)
        {
            new paintjobid = -1;
            for(new i = (tuneid-1); i > 0; i--) 
            {
                if(paintjobInfo[i][paintjobModel] == GetVehicleModel(vehicleid)) 
                {
					paintjobid = i;
					break;
				}
			}

            if(paintjobid == -1) 
                return ShowPlayerFooter(playerid, 300, "Tidak ada paintjob yang kompatible untuk model kendaraan ini!");

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
        else if(type == PLAYER_TUNE_COLOR)
        {
            ShowPlayerVehicleTuneDialog(playerid, VEHICLE_TUNE_COLOR, vehicleid); 
        }
        else
        {
            new componentid = -1;
            for(new i = (tuneid-1); i > 0; i--) 
            {
                if(componentInfo[i][componentType] == player_vtune_carmodtype[playerid]) 
                {
                    if(componentInfo[i][componentID] == IsComponentidCompatible(GetVehicleModel(vehicleid), componentInfo[i][componentID])) {
                        componentid = i;
                        break;
                    }
                    else continue;
                } 
                else continue;
            }

            if(componentid == -1)
            {
                Loop(i, MAX_COMPONENTS) 
                {
                    if(componentInfo[i][componentType] == player_vtune_carmodtype[playerid]) 
                    {
                        if(componentInfo[i][componentID] == IsComponentidCompatible(GetVehicleModel(vehicleid), componentInfo[i][componentID])) {
                            componentid = i;
                        }
                        else continue;
                    } 
                    else continue;
                }
            }

            AddVehicleComponent(vehicleid, componentInfo[componentid][componentID]);

            SetPlayerTuneInfo(playerid, componentid, PLAYER_TUNE_COMPONENT, vehicleid);

            TogglePlayerControllable(playerid, false);
            ShowPlayerVTuneTD(playerid, GetVehicleModelName(GetVehicleModel(vehicleid)), componentInfo[componentid][componentName], componentInfo[componentid][componentNeeds]);
        }
    }
    else if(playertextid == td_vtune_instal[playerid])
    {
        new tuneid, type, vehicleid;
        GetPlayerTuneInfo(playerid, tuneid, type, vehicleid);

        if(type == PLAYER_TUNE_PAINTJOB)
        {
            new paintjobid = tuneid;

            PlaySpraySound(playerid);
            ChangeVehicleColor(vehicleid, 1, 1);
            ChangeVehiclePaintjob(vehicleid, paintjobInfo[paintjobid][paintjobID]);
        }
        else if(type == PLAYER_TUNE_COLOR)
        {
            new color1, color2;

            PlaySpraySound(playerid);

            GetVehicleColor(vehicleid, color1, color2);
            ChangeVehicleColor(vehicleid, color1, color2);
        }
        else
        {
            PlayMechSound(playerid);
        }

        /* NANTI */
        CancelSelectTextDraw(playerid);
        TogglePlayerControllable(playerid, true);
        SetCameraBehindPlayer(playerid);
        ResetPlayerTuneInfo(playerid);
        HidePlayerVTuneTD(playerid);
    }
    else if(playertextid == td_vtune_close[playerid])
    {
        new tuneid, type, vehicleid;
        GetPlayerTuneInfo(playerid, tuneid, type, vehicleid);
        
        if(type == PLAYER_TUNE_PAINTJOB)
        {
            ChangeVehicleColor(vehicleid, default_vehicle_color[vehicleid][0], default_vehicle_color[vehicleid][1]);
            ChangeVehiclePaintjob(vehicleid, default_vehicle_paintjob[vehicleid]);

            default_vehicle_paintjob[vehicleid] = -1;
        }
        else if(type == PLAYER_TUNE_COLOR)
        {
            ChangeVehicleColor(vehicleid, default_vehicle_color[vehicleid][0], default_vehicle_color[vehicleid][1]);
        }
        else 
        {
            new tune_before = 0, tune_now, carmod;

            tune_before = default_vehicle_component[vehicleid];
            carmod = player_vtune_carmodtype[playerid];
            tune_now = GetVehicleComponentInSlot(vehicleid, carmod);

            if(tune_before != 0)
            {
                RemoveVehicleComponent(vehicleid, tune_now);
                AddVehicleComponent(vehicleid, tune_before);
            }
            else
            {
                RemoveVehicleComponent(vehicleid, tune_now);
            }
        }

        CancelSelectTextDraw(playerid);
        TogglePlayerControllable(playerid, true);
        SetCameraBehindPlayer(playerid);
        ResetPlayerTuneInfo(playerid);
        HidePlayerVTuneTD(playerid);
    }
    return 1;
}