stock LoadPlayerAnimation(playerid, const library[])
{
    ApplyAnimation(playerid, library,"null", 0.0, 0, 0, 0, 0, 0);
    return 1;
}

stock LoadPlayerAllAnimation(playerid)
{
    Loop(i, sizeof(animation_library))
    {
        LoadPlayerAnimation(playerid, animation_library[i]);
    }
    player_loopinganimation[playerid] = false;
    return 1;
}

stock IsValidAnimation(const library[], const name[])
{
    new bool:status = false;
    Loop(i, sizeof(panimation_Info))
    {
        if(!strcmp(library, panimation_Info[i][panimation_Library], true) && !strcmp(name, panimation_Info[i][panimation_Name], true))
        {
            status = true;
            break;
        }
    }
    return status;
}

stock ApplyPlayerLoopingAnimation(playerid, const library[], const name[])
{
    if(player_loopinganimation[playerid] == true) StopPlayerAnimation(playerid);

    ShowPlayerAnimationTextDraw(playerid);
    ApplyAnimation(playerid, library, name, 4.1, 1, 0, 0, 0, 0);

    player_loopinganimation[playerid] = true;
    return 1;
}

stock ApplyPlayerAnimation(playerid, const library[], const name[])
{
    ApplyAnimation(playerid, library, name, 4.1, 0, 0, 0, 0, 0);
    return 1;
}

stock StopPlayerAnimation(playerid)
{
    ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0);
    
    if(player_loopinganimation[playerid] == true) 
    {
        HidePlayerAnimationTextDraw(playerid);
        player_loopinganimation[playerid] = false;
    }
    return 1;
}