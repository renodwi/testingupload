stock AddSavedAnimation(const name[], const creator[], const anim_library[], const anim_name[], anim_looping)
{
    new slot = Iter_Free(SavedAnimation);
    if(slot == -1) return 1;

    format(savedanimationInfo[slot][savedanimationName], 50, name);
    format(savedanimationInfo[slot][savedanimationCreator], 200, creator);
    format(savedanimationInfo[slot][savedanimationAnimLibrary], 100, anim_library);
    format(savedanimationInfo[slot][savedanimationAnimName], 100, anim_name);
    savedanimationInfo[slot][savedanimationLooping] = anim_looping;

    Iter_Add(SavedAnimation, slot);

    new query[1000];
	mysql_format(sql, query, sizeof(query), "INSERT INTO `saved_animations` (`id`, `name`, `creator`, `anim_library`, `anim_name`, `anim_looping`) VALUES ('%d', '%e', '%e', '%e', '%e', '%d')", slot, name, creator, anim_library, anim_name, anim_looping);
	mysql_tquery(sql, query);
    return 1;
}

stock DeleteSavedAnimation(slot)
{
    if(!Iter_Contains(SavedAnimation, slot)) return 1;

    new query[100];
	mysql_format(sql, query, sizeof(query), "DELETE FROM `saved_animations` WHERE `id` = '%d'", slot);
	mysql_tquery(sql, query);

    Iter_Remove(SavedAnimation, slot);
    return 1;
}

stock GetSavedAnimationName(slot)
{
    new name[100];
    format(name, sizeof(name), savedanimationInfo[slot][savedanimationName]);
    return name;
}

stock GetSavedAnimationCreator(slot)
{
    new creator[200];
    format(creator, sizeof(creator), savedanimationInfo[slot][savedanimationCreator]);
    return creator;
}

stock GetSavedAnimationAnimLibrary(slot)
{
    new library[100];
    format(library, sizeof(library), savedanimationInfo[slot][savedanimationAnimLibrary]);
    return library;
}

stock GetSavedAnimationAnimName(slot)
{
    new animname[100];
    format(animname, sizeof(animname), savedanimationInfo[slot][savedanimationAnimName]);
    return animname;
}

stock GetSavedAnimationSlotByName(const name[])
{
    new slot = -1;
    foreach(new i : SavedAnimation) {
        if(!strcmp(savedanimationInfo[i][savedanimationName], name, true)) {
            slot = i;
            break;
        }
    }
    return slot;
}

stock GetSavedAnimationSlotByCreator(const creator[])
{
    new slot = -1;
    foreach(new i : SavedAnimation) {
        if(!strcmp(savedanimationInfo[i][savedanimationCreator], creator, true)) {
            slot = i;
            break;
        }
    }
    return slot;
}

stock IsSavedAnimationLooping(slot)
{
    new bool:status = false;
    if(savedanimationInfo[slot][savedanimationLooping] == 1) status = true;
    return status;
}

stock IsValidSavedAnimationName(const name[])
{
    new bool:status = false;
    foreach(new slot : SavedAnimation) {
        if(!isnull(savedanimationInfo[slot][savedanimationName]) && !strcmp(name, savedanimationInfo[slot][savedanimationName], true) && Iter_Contains(SavedAnimation, slot)) {
            status = true;
            break;
        }
    }
    return status;
}

stock IsPlayerAlreadySaveAnimation(playerid)
{
    new bool:status = false;
    foreach(new slot : SavedAnimation) {
        if(!strcmp(GetName(playerid), savedanimationInfo[slot][savedanimationCreator], true)) {
            status = true;
            break;
        }
    }
    return status;
}

stock ApplySavedAnimation(playerid, slot)
{
    if(!Iter_Contains(SavedAnimation, slot)) return 1;

    if(IsSavedAnimationLooping(slot)) 
    {
        ApplyPlayerLoopingAnimation(playerid, GetSavedAnimationAnimLibrary(slot), GetSavedAnimationAnimName(slot));
    }
    else 
    {
        ApplyPlayerAnimation(playerid, GetSavedAnimationAnimLibrary(slot), GetSavedAnimationAnimName(slot));
    }
    return 1;
}

stock LoadSavedAnimation()
{
    mysql_tquery(sql, "SELECT * FROM `saved_animations`", "AssignSavedAnimationDatabase");
    return 1;
}

function AssignSavedAnimationDatabase()
{
    static slot;

	new rows  = cache_num_rows();
 	if(rows)
  	{
		for(new i; i < rows; i++)
		{
            cache_get_value_int(i, "id", slot);
            cache_get_value(i, "name", savedanimationInfo[slot][savedanimationName]);
            cache_get_value(i, "creator", savedanimationInfo[slot][savedanimationCreator]);
            cache_get_value(i, "anim_library", savedanimationInfo[slot][savedanimationAnimLibrary]);
            cache_get_value(i, "anim_name", savedanimationInfo[slot][savedanimationAnimName]);
            cache_get_value_int(i, "anim_looping", savedanimationInfo[slot][savedanimationLooping]);

            #if defined DEBUG_MODE
                printf("[Saved Animation] ID: %d Name: %s Creator: %s anim_library: %s anim_name: %s anim_looping: %s", slot, savedanimationInfo[slot][savedanimationName], savedanimationInfo[slot][savedanimationCreator], savedanimationInfo[slot][savedanimationAnimLibrary], savedanimationInfo[slot][savedanimationAnimName], savedanimationInfo[slot][savedanimationLooping]);
            #endif
            Iter_Add(SavedAnimation, slot);
		}
	}
	return 1;
}