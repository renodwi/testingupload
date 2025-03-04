hook OnGameModeInit()
{
    AddAdminCommand(Manager, "/actor [option]", "Digunakan untuk mengatur dynamic actor");
    return 1;
}

function AssignActorData()
{
    static actorid;
    new rows;
    rows = cache_num_rows();
    if(rows)
    {
        for(new i = 0; i < rows; i++)
        {
            cache_get_value_int(i, "id", actorid);
            cache_get_value_int(i, "skin", actorInfo[actorid][actorSkinID]);

            cache_get_value(i, "name", actorInfo[actorid][actorName]);
            cache_get_value(i, "animname", actorInfo[actorid][actorAnimName]);
            cache_get_value(i, "animlib", actorInfo[actorid][actorAnimLib]);

            cache_get_value_float(i, "posx", actorInfo[actorid][actorPositionX]);
            cache_get_value_float(i, "posy", actorInfo[actorid][actorPositionY]);
            cache_get_value_float(i, "posz", actorInfo[actorid][actorPositionZ]);
            cache_get_value_float(i, "posa", actorInfo[actorid][actorPositionA]);
            
            cache_get_value_int(i, "world", actorInfo[actorid][actorWorldID]);
            cache_get_value_int(i, "interior", actorInfo[actorid][actorInteriorID]);

            Iter_Add(Actors, actorid);
            RefreshActor(actorid);

            #if defined DEBUG_MODE
                printf("[Actor]: ID: %d Skin: %d Name: %s Animname: %s Animlib: %s position (x: %f y: %f z: %f a: %f) World: %d Interior: %d", actorid, actorInfo[actorid][actorSkinID], actorInfo[actorid][actorName], actorInfo[actorid][actorAnimName], actorInfo[actorid][actorAnimLib], actorInfo[actorid][actorPositionX], actorInfo[actorid][actorPositionY], actorInfo[actorid][actorPositionZ], actorInfo[actorid][actorPositionA], actorInfo[actorid][actorWorldID], actorInfo[actorid][actorInteriorID]);
            #endif
        }
    }
    return 1;
}