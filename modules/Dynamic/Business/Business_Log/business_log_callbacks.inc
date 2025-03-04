function OnBusinessLogCreate(businessid, logid) 
{
    businesslogInfo[businessid][logid][businesslogDBID] = cache_insert_id();
    return 1;
}

function AssignBusinessLogData(businessid)
{
	new rows  = cache_num_rows();
    if(rows)
    {
		for(new i; i < rows; i++)
		{
            cache_get_value_int(i, "id", businesslogInfo[businessid][i][businesslogDBID]);
            cache_get_value(i, "message", businesslogInfo[businessid][i][businesslogMessage]);
            cache_get_value_int(i, "timestamp", _:businesslogInfo[businessid][i][businesslogTimestamp]);
            businesslogInfo[businessid][i][businesslogExist] = true;

            #if defined DEBUG_MODE
                printf("[Business Log Data] Businessid: %d ID: %d Timestamp: %s (%s) Message: %s", businessid, businesslogInfo[businessid][i][businesslogDBID], TimestampToDateString(businesslogInfo[businessid][i][businesslogTimestamp]), TimestampToTimeString(businesslogInfo[businessid][i][businesslogTimestamp]), businesslogInfo[businessid][i][businesslogMessage]);
            #endif
		}
	}
    return 1;
}