stock CreateAtm(world, interior, Float:x, Float:y, Float:z)
{
    new atmid = Iter_Free(Atm);

	atmInfo[atmid][atmWorld] = world;
	atmInfo[atmid][atmInterior] = interior;
	atmInfo[atmid][atmPositionX] = x;
	atmInfo[atmid][atmPositionY] = y;
	atmInfo[atmid][atmPositionZ] = z;
	atmInfo[atmid][atmRotationX] = 0.0;
	atmInfo[atmid][atmRotationY] = 0.0;
	atmInfo[atmid][atmRotationZ] = 0.0;
	atmInfo[atmid][atmObjectID] = -1;

	new query[100];
    mysql_format(sql, query, sizeof query, "INSERT INTO `atms` (`id`) VALUES ('%d')", atmid);
    mysql_tquery(sql, query);

    Iter_Add(Atm, atmid);
	RefreshAtm(atmid);
	return atmid;
}

stock RefreshAtm(atmid)
{
	if(!Iter_Contains(Atm, atmid)) return 1;

	if(atmInfo[atmid][atmObjectID] == -1) 
	{
		atmInfo[atmid][atmObjectID] = CreateDynamicObject(19324, atmInfo[atmid][atmPositionX], atmInfo[atmid][atmPositionY], atmInfo[atmid][atmPositionZ], atmInfo[atmid][atmRotationX], atmInfo[atmid][atmRotationY], atmInfo[atmid][atmRotationZ], atmInfo[atmid][atmWorld], atmInfo[atmid][atmInterior]);
	}
	else 
	{
		SetDynamicObjectPos(atmInfo[atmid][atmObjectID], atmInfo[atmid][atmPositionX], atmInfo[atmid][atmPositionY], atmInfo[atmid][atmPositionZ]);
		SetDynamicObjectRot(atmInfo[atmid][atmObjectID], atmInfo[atmid][atmRotationX], atmInfo[atmid][atmRotationY], atmInfo[atmid][atmRotationZ]);
	}
	UpdateAtmData(atmid);
	return 1;
}

stock DeleteAtm(atmid)
{
	DestroyDynamicObject(atmInfo[atmid][atmObjectID]);
	atmInfo[atmid][atmObjectID] = -1;
	Iter_Remove(Atm, atmid);

	new query[900];
	mysql_format(sql, query, sizeof(query), "DELETE FROM `atms` WHERE `id` = '%d'", atmid);
	mysql_tquery(sql, query);
	return 1;
}

stock IsPlayerInAtm(playerid)
{
	new atmid = -1;
    foreach(new i : Atm)
    {
        if(Iter_Contains(Atm, i))
        {
            if(IsPlayerInRangeOfPoint(playerid, 2.0, atmInfo[i][atmPositionX], atmInfo[i][atmPositionY], atmInfo[i][atmPositionZ]) && GetPlayerInterior(playerid) == atmInfo[i][atmInterior] && GetPlayerVirtualWorld(playerid) == atmInfo[i][atmWorld])
            {
                atmid = i;
                break;
            }
        }
    }
	return atmid;
}

stock UpdateAtmData(atmid)
{
    if(!Iter_Contains(Atm, atmid)) return 1;

    new cQuery[3048];
    mysql_format(sql, cQuery, sizeof(cQuery), "UPDATE `atms` SET ");
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`world` = '%d', ", cQuery, atmInfo[atmid][atmWorld]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`interior` = '%d', ", cQuery, atmInfo[atmid][atmInterior]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`positionx` = '%f', ", cQuery, atmInfo[atmid][atmPositionX]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`positiony` = '%f', ", cQuery, atmInfo[atmid][atmPositionY]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`positionz` = '%f', ", cQuery, atmInfo[atmid][atmPositionZ]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`rotationx` = '%f', ", cQuery, atmInfo[atmid][atmRotationX]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`rotationy` = '%f', ", cQuery, atmInfo[atmid][atmRotationY]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`rotationz` = '%f' WHERE `id` = '%d'", cQuery, atmInfo[atmid][atmRotationZ], atmid);
	mysql_tquery(sql, cQuery);
    return 1;
}

function AssignAtmData()
{
    static atmid;

	new rows  = cache_num_rows();
 	if(rows)
  	{
		for(new i; i < rows; i++)
		{
			cache_get_value_int(i, "id", atmid);
			cache_get_value_int(i, "world", atmInfo[atmid][atmWorld]);
			cache_get_value_int(i, "interior", atmInfo[atmid][atmInterior]);
			cache_get_value_float(i, "positionx", atmInfo[atmid][atmPositionX]);
			cache_get_value_float(i, "positiony", atmInfo[atmid][atmPositionY]);
			cache_get_value_float(i, "positionz", atmInfo[atmid][atmPositionZ]);
			cache_get_value_float(i, "rotationx", atmInfo[atmid][atmRotationX]);
			cache_get_value_float(i, "rotationy", atmInfo[atmid][atmRotationY]);
			cache_get_value_float(i, "rotationz", atmInfo[atmid][atmRotationZ]);

			atmInfo[atmid][atmObjectID] = -1;
			Iter_Add(Atm, atmid);
			RefreshAtm(atmid);

			#if defined DEBUG_MODE
				printf("[Dynamic Atm]: ID: %d World: %d Interior: %d position (x: %f y: %f z: %f rx: %f ry: %f rz: %f)", atmid, atmInfo[atmid][atmWorld], atmInfo[atmid][atmInterior], atmInfo[atmid][atmPositionX], atmInfo[atmid][atmPositionY], atmInfo[atmid][atmPositionZ], atmInfo[atmid][atmRotationX], atmInfo[atmid][atmRotationY], atmInfo[atmid][atmRotationZ]);
			#endif
		}
	}
    return 1;
}