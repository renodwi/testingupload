YCMD:actor(playerid, params[], help)
{
    if(!IsPlayerAdmin(playerid, Manager))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");

    new option[50], string[200], bool:syntax = true;
    if(sscanf(params, "s[50]S()[200]", option, string))
    {
        syntax = false;
    }
    else
    {
        if(!strcmp(option, "create", true))
        {
            new skin;
            if(sscanf(string, "d", skin))
                return SendUsageMessage(playerid, "/actor create [skin id]");

            new Float:x, Float:y, Float:z, Float:a, world, interior, actorid;
            GetPlayerPos(playerid, x, y, z);
            GetPlayerFacingAngle(playerid, a);
            world = GetPlayerVirtualWorld(playerid);
            interior = GetPlayerInterior(playerid);

            actorid = MakeActor(GetName(playerid), TimestampToDateString(Now()), skin, x, y, z, a, world, interior);

            x = x + (1.0 * floatsin(-a, degrees));
            y = y + (1.0 * floatcos(-a, degrees));
            SetPlayerPos(playerid, x, y, z);

            SendClientMessageEx(playerid, COLOR_REN, "ACTOR: "WHITE"Anda membuat aktor "YELLOW"id %d"WHITE" dengan "LB"model %d.", actorid, skin);
        }
        else if(!strcmp(option, "name", true))
        {
            new actorid, name[100];
            if(sscanf(string, "ds[100]", actorid, name))
                return SendUsageMessage(playerid, "/actor name [actorid] [actor name]");

            if(!Iter_Contains(Actors, actorid))
                return SendErrorMessage(playerid, "Aktor dengan id %d tidak diketahui", actorid);

            SendClientMessageEx(playerid, COLOR_REN, "ACTOR: "WHITE"Anda mengubah nama aktor "YELLOW"id %d"WHITE" dari "LB"%s"WHITE" menjadi "LG"%s", actorid, actorInfo[actorid][actorName], name);
            format(actorInfo[actorid][actorName], 100, "%s", name);

            RefreshActor(actorid);
        }
        else if(!strcmp(option, "skin", true))
        {
            new actorid, skin;
            if(sscanf(string, "dd", actorid, skin))
                return SendUsageMessage(playerid, "/actor skin [actorid] [actor skin]");

            if(!Iter_Contains(Actors, actorid))
                return SendErrorMessage(playerid, "Aktor dengan id %d tidak diketahui", actorid);

            SendClientMessageEx(playerid, COLOR_REN, "ACTOR: "WHITE"Anda mengubah skin aktor "YELLOW"id %d"WHITE" dari "LB"%d"WHITE" menjadi "LG"%d", actorid, actorInfo[actorid][actorSkinID], skin);
            actorInfo[actorid][actorSkinID] = skin; 
            
            RefreshActor(actorid);
        }
        else if(!strcmp(option, "position", true))
        {
            new actorid;
            if(sscanf(string, "d", actorid))
                return SendUsageMessage(playerid, "/actor position [actorid]");

            if(!Iter_Contains(Actors, actorid))
                return SendErrorMessage(playerid, "Aktor dengan id %d tidak diketahui", actorid);

            SendClientMessageEx(playerid, COLOR_REN, "ACTOR: "WHITE"Anda mengubah posisi aktor "YELLOW"id %d"WHITE" ke posisi anda", actorid);
            
            new Float:x, Float:y, Float:z, Float:a, world, interior;
            GetPlayerPos(playerid, x, y, z);
            GetPlayerFacingAngle(playerid, a);
            world = GetPlayerVirtualWorld(playerid);
            interior = GetPlayerInterior(playerid);

            actorInfo[actorid][actorPositionX] = x;
            actorInfo[actorid][actorPositionY] = y;
            actorInfo[actorid][actorPositionZ] = z;
            actorInfo[actorid][actorPositionA] = a;
            actorInfo[actorid][actorWorldID] = world;
            actorInfo[actorid][actorInteriorID] = interior;

            RefreshActor(actorid);
        }
        else if(!strcmp(option, "anim", true))
        {
            new actorid, animation[50];
            if(sscanf(string, "ds[50]", actorid, animation))
                return SendUsageMessage(playerid, "/actor anim [actorid] [nama animasi atau 0 - %d]", sizeof(panimation_Info));

            if(!Iter_Contains(Actors, actorid))
                return SendErrorMessage(playerid, "Aktor dengan id %d tidak diketahui", actorid);

            if(IsNumeric(animation))
            {
                new slot = strval(params);

                if(slot > sizeof(panimation_Info) || slot < 0) 
                    return SendUsageMessage(playerid, "/actor anim [actorid] [nama animasi atau 0 - %d]", sizeof(panimation_Info));
                    
                format(actorInfo[actorid][actorAnimLib], 100, "%s", panimation_Info[slot][panimation_Library]);
                format(actorInfo[actorid][actorAnimName], 100, "%s", panimation_Info[slot][panimation_Name]);

                SendClientMessageEx(playerid, COLOR_REN, "ACTOR: "WHITE"Anda telah menjalankan animasi pada aktor "YELLOW"id %d"WHITE" "LB"[Animation ID: %d]", actorid, params);
            }
            else
            {
                if(!IsValidSavedAnimationName(params))
                    return SendErrorMessage(playerid, "Animasi '%s' tidak terdeteksi!", params);

                new slot = GetSavedAnimationSlotByName(params);
                format(actorInfo[actorid][actorAnimLib], 100, "%s", GetSavedAnimationAnimLibrary(slot));
                format(actorInfo[actorid][actorAnimName], 100, "%s", GetSavedAnimationAnimName(slot));

                SendClientMessageEx(playerid, COLOR_REN, "ACTOR: "WHITE"Anda telah menjalankan animasi pada aktor "YELLOW"id %d"WHITE" "LB"[Animation Name: %s]", actorid, params);
            }
            RefreshActor(actorid);
        }
        else if(!strcmp(option, "clearanim", true))
        {
            new actorid;
            if(sscanf(string, "d", actorid))
                return SendUsageMessage(playerid, "/actor clearanim [actorid]");

            if(!Iter_Contains(Actor, actorid))
                return SendErrorMessage(playerid, "Aktor dengan id %d tidak diketahui", actorid);

            format(actorInfo[actorid][actorAnimLib], 100, "Unknown");
            format(actorInfo[actorid][actorAnimName], 100, "Unknown");
            RefreshActor(actorid);
        }
        else if(!strcmp(option, "goto", true))
        {
            new actorid;
            if(sscanf(string, "d", actorid))
                return SendUsageMessage(playerid, "/actor [goto] [actorid]");

            if(!Iter_Contains(Actors, actorid))
                return SendErrorMessage(playerid, "Aktor dengan id %d tidak diketahui", actorid);

            SendClientMessageEx(playerid, COLOR_REN, "ACTOR: "WHITE"Teleportasi ke aktor "YELLOW"id %d"WHITE"", actorid);
            SetPlayerPos(playerid, actorInfo[actorid][actorPositionX], actorInfo[actorid][actorPositionY], actorInfo[actorid][actorPositionZ]);
            SetPlayerInterior(playerid, actorInfo[actorid][actorInteriorID]);
            SetPlayerVirtualWorld(playerid, actorInfo[actorid][actorWorldID]);
        }
        else if(!strcmp(option, "delete", true))
        {
            new actorid;
            if(sscanf(string, "d", actorid))
                return SendUsageMessage(playerid, "/actor [delete] [actorid]");

            if(!Iter_Contains(Actors, actorid))
                return SendErrorMessage(playerid, "Aktor dengan id %d tidak diketahui", actorid);

            SendClientMessageEx(playerid, COLOR_REN, "ACTOR: "WHITE"Anda telah menghapus aktor "RED"id %d"WHITE"", actorid);
            DeleteActor(actorid);
        }
        else syntax = false;
    }

    if(syntax == false)
    {
        SendUsageMessage(playerid, "/actor [option]");
        SendClientMessageEx(playerid, COLOR_GREY, "option: create name skin position anim clearanim goto delete");
    }
    return 1;
}