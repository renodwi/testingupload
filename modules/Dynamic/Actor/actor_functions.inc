stock MakeActor(const createdby[], const createdat[], skinid, Float:x, Float:y, Float:z, Float:a, worldid = -1, interiorid = -1)
{
    new actorid = -1;
    actorid = Iter_Free(Actors);
    if(actorid == cellmax) return 1; 

    format(actorInfo[actorid][actorName], 100, "Unknown");
    actorInfo[actorid][actorSkinID] = skinid;

    actorInfo[actorid][actorPositionX] = x;
    actorInfo[actorid][actorPositionY] = y;
    actorInfo[actorid][actorPositionZ] = z;
    actorInfo[actorid][actorPositionA] = a;

    format(actorInfo[actorid][actorAnimLib], 100, "Unknown");
    format(actorInfo[actorid][actorAnimName], 100, "Unknown");

    actorInfo[actorid][actorWorldID] = worldid;
    actorInfo[actorid][actorInteriorID] = interiorid;

    new query[1500];
    mysql_format(sql, query, sizeof query, "INSERT INTO `actors` (`id`, `name`, `skin`, `x`, `y`, `z`, `a`) VALUES ('%d', '%e', '%d', '%f', '%f', '%f', '%f')", actorid, createdby, createdat, skinid, x, y, z, a);
    mysql_tquery(sql, query);

    Iter_Add(Actors, actorid);
    RefreshActor(actorid);
    return actorid;
}

stock RefreshActor(actorid)
{
    if(!Iter_Contains(Actors, actorid)) return 1;
    
    if(IsValidDynamicActor(actorInfo[actorid][actorID]))
        DestroyDynamicActor(actorInfo[actorid][actorID]);

    if(IsValidDynamic3DTextLabel(actorInfo[actorid][actorLabel]))
        DestroyDynamic3DTextLabel(actorInfo[actorid][actorLabel]);

    actorInfo[actorid][actorID] = CreateDynamicActor(actorInfo[actorid][actorSkinID], actorInfo[actorid][actorPositionX], actorInfo[actorid][actorPositionY], actorInfo[actorid][actorPositionZ], actorInfo[actorid][actorPositionA], 1, 2.0, actorInfo[actorid][actorWorldID], actorInfo[actorid][actorInteriorID], -1);

    new message[900];
    format(message, sizeof(message), ""GREY"[ID: %d]\n%s", actorid, actorInfo[actorid][actorName]);
    actorInfo[actorid][actorLabel] = CreateDynamic3DTextLabel(message, COLOR_WHITE, actorInfo[actorid][actorPositionX], actorInfo[actorid][actorPositionY], actorInfo[actorid][actorPositionZ] + 0.6, 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, actorInfo[actorid][actorWorldID], actorInfo[actorid][actorInteriorID]);

    UpdateActorData(actorid);

    if(!strcmp(actorInfo[actorid][actorAnimLib], "Unknown", true))
    {
        ClearDynamicActorAnimations(actorid);
    }
    else 
    {
        ApplyDynamicActorAnimation(actorid, actorInfo[actorid][actorAnimLib], actorInfo[actorid][actorAnimName], 4.1, 1, 0, 0, 1, 9999999);
    }
    return 1;
}

stock UpdateActorData(actorid)
{
    if(!Iter_Contains(Actors, actorid)) return 1;

    new cQuery[3048];
    mysql_format(sql, cQuery, sizeof(cQuery), "UPDATE `actors` SET ");
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`name` = '%e', ", cQuery, actorInfo[actorid][actorName]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`skin` = '%d', ", cQuery, actorInfo[actorid][actorSkinID]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`x` = '%f', ", cQuery, actorInfo[actorid][actorPositionX]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`y` = '%f', ", cQuery, actorInfo[actorid][actorPositionY]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`z` = '%f', ", cQuery, actorInfo[actorid][actorPositionZ]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`a` = '%f', ", cQuery, actorInfo[actorid][actorPositionA]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`animlib` = '%e', ", cQuery, actorInfo[actorid][actorAnimLib]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`animname` = '%e', ", cQuery, actorInfo[actorid][actorAnimName]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`world` = '%d', ", cQuery, actorInfo[actorid][actorWorldID]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`interior` = '%d' WHERE `id` = '%d'", cQuery, actorInfo[actorid][actorInteriorID], actorid);
	mysql_tquery(sql, cQuery);
    return 1;
}

stock LoadActors()
{
    mysql_tquery(sql, "SELECT * FROM `actors`", "AssignActorData");
    return 1;
}

stock DeleteActor(actorid)
{
    if(!Iter_Contains(Actors, actorid)) return 1;
    
    if(IsValidDynamicActor(actorInfo[actorid][actorID]))
        DestroyDynamicActor(actorInfo[actorid][actorID]);

    if(IsValidDynamic3DTextLabel(actorInfo[actorid][actorLabel]))
        DestroyDynamic3DTextLabel(actorInfo[actorid][actorLabel]);

    new query[64];
    mysql_format(sql, query, sizeof(query), "DELETE FROM `actors` WHERE `id` = '%d'", actorid);
    mysql_tquery(sql, query);

    Iter_Remove(Actors, actorid);
    return 1;
}