function AssignBusinessBuyPoint(businessid) 
{
    new rows  = cache_num_rows();
    if(rows)
    {
		for(new i; i < rows; i++)
		{
            cache_get_value_int(i, "id", businessbuypointInfo[businessid][i][businessbuypointDBID]);
            cache_get_value_float(i, "position_x", businessbuypointInfo[businessid][i][businessbuypointPositionX]);
            cache_get_value_float(i, "position_y", businessbuypointInfo[businessid][i][businessbuypointPositionY]);
            cache_get_value_float(i, "position_z", businessbuypointInfo[businessid][i][businessbuypointPositionZ]);
            cache_get_value_int(i, "interior", businessbuypointInfo[businessid][i][businessbuypointInterior]);
            cache_get_value_int(i, "world", businessbuypointInfo[businessid][i][businessbuypointWorld]);
            
            businessbuypointInfo[businessid][i][businessbuypointExist] = true;
            RefreshBusinessBuyPoint(businessid, i);

            #if defined DEBUG_MODE
                printf("[Business Buy Point] Businessid: %d ID: %d position (x: %f y: %f z: %f) InteriorID: %d WorldID: %d", businessid, businessbuypointInfo[businessid][i][businessbuypointDBID], businessbuypointInfo[businessid][i][businessbuypointPositionX], businessbuypointInfo[businessid][i][businessbuypointPositionY], businessbuypointInfo[businessid][i][businessbuypointPositionZ], businessbuypointInfo[businessid][i][businessbuypointInterior], businessbuypointInfo[businessid][i][businessbuypointWorld]);
            #endif
		}
	}
    return 1;
}

function OnBusinessBuypointCreate(businessid, buypointid)
{
    businessbuypointInfo[businessid][buypointid][businessbuypointDBID] = cache_insert_id();
    return 1;
}