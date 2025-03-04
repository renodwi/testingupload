hook OnGameModeInit() 
{
    AddAdminCommand(Manager, "/mechanicarea [action]", "Mengatur area mekanik");
    return 1;
}

hook OnServerAssignData()
{
    LoadMechanicArea();
    return 1;
}

hook OnPlayerConnect(playerid)
{
    player_create_mecharea[playerid][0][0] = 0.0;
    player_create_mecharea[playerid][0][1] = 0.0;
    player_create_mecharea[playerid][0][2] = 0.0;
    player_create_mecharea[playerid][1][0] = 0.0;
    player_create_mecharea[playerid][1][1] = 0.0;
    player_create_mecharea[playerid][1][2] = 0.0;

    if(IsValidDynamic3DTextLabel(player_create_mecharea_label[playerid][0]))
        DestroyDynamic3DTextLabel(player_create_mecharea_label[playerid][0]);

    if(IsValidDynamicPickup(player_create_mecharea_pickup[playerid][0]))
        DestroyDynamicPickup(player_create_mecharea_pickup[playerid][0]);
            
    if(IsValidDynamic3DTextLabel(player_create_mecharea_label[playerid][1]))
        DestroyDynamic3DTextLabel(player_create_mecharea_label[playerid][1]);

    if(IsValidDynamicPickup(player_create_mecharea_pickup[playerid][1]))
        DestroyDynamicPickup(player_create_mecharea_pickup[playerid][1]);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(IsValidDynamic3DTextLabel(player_create_mecharea_label[playerid][0]))
        DestroyDynamic3DTextLabel(player_create_mecharea_label[playerid][0]);

    if(IsValidDynamicPickup(player_create_mecharea_pickup[playerid][0]))
        DestroyDynamicPickup(player_create_mecharea_pickup[playerid][0]);
            
    if(IsValidDynamic3DTextLabel(player_create_mecharea_label[playerid][1]))
        DestroyDynamic3DTextLabel(player_create_mecharea_label[playerid][1]);

    if(IsValidDynamicPickup(player_create_mecharea_pickup[playerid][1]))
        DestroyDynamicPickup(player_create_mecharea_pickup[playerid][1]);
    return 1;
}

function OnMechanicAreaCreated(areaid) 
{
    mechanicareaInfo[areaid][mechanicareaDBID] = cache_insert_id();
    return 1;
}

function AssignMechanicAreaData()
{
	new rows  = cache_num_rows();
    if(rows)
    {
		for(new i; i < rows; i++)
		{
			cache_get_value_int(i, "id", mechanicareaInfo[i][mechanicareaDBID]);
			cache_get_value_float(i, "fromx", mechanicareaInfo[i][mechanicareaFrom][0]);
			cache_get_value_float(i, "fromy", mechanicareaInfo[i][mechanicareaFrom][1]);
			cache_get_value_float(i, "tox", mechanicareaInfo[i][mechanicareaTo][0]);
			cache_get_value_float(i, "toy", mechanicareaInfo[i][mechanicareaTo][1]);

			mechanicareaInfo[i][mechanicareaID] = -1;
            
			Iter_Add(MechanicArea, i);
			RefreshMechanicArea(i);

			#if defined DEBUG_MODE
				printf("[Dynamic Mechanic Area]: ID: %d (from x: %f from y: %f to x: %f to y: %f)", i, mechanicareaInfo[i][mechanicareaFrom][0], mechanicareaInfo[i][mechanicareaFrom][1], mechanicareaInfo[i][mechanicareaTo][0], mechanicareaInfo[i][mechanicareaTo][1]);
			#endif
		}
	}
    return 1;
}