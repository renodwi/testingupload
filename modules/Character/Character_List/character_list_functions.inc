stock SetPlayerSelectCharacterCamera(playerid)
{
    SetPlayerCameraPos(playerid, 1008.0490, -833.7874, 100.0157);
    SetPlayerCameraLookAt(playerid, 1162.9019, -950.9866, 100.6472);
    return 1;
}

function ShowPlayerSelectCharacterInfo(playerid, slot)
{
    if(IsValidDynamicActor(player_select_character_actor[playerid])) DestroyDynamicActor(player_select_character_actor[playerid]); 
    
    if(playercharacterInfo[playerid][slot][playercharacterExist])
    {
        player_select_character_actor[playerid] = CreateDynamicActor(playercharacterInfo[playerid][slot][playercharacterSkin], 1011.318859, -835.270495, 99.866462, 61.856884, 1, 100.0, GetPlayerVirtualWorld(playerid));
        ShowPlayerCharacterSelectTD(playerid, playercharacterInfo[playerid][slot][playercharacterName], playercharacterInfo[playerid][slot][playercharacterLevel], playercharacterInfo[playerid][slot][playercharacterMoney], playercharacterInfo[playerid][slot][playercharacterGender], playercharacterInfo[playerid][slot][playercharacterLastSeen], playercharacterInfo[playerid][slot][playercharacterLastSeenPosX], playercharacterInfo[playerid][slot][playercharacterLastSeenPosY], playercharacterInfo[playerid][slot][playercharacterLastSeenPosZ]);
    }
    else 
    {
        ShowPlayerCharacterNoCharTD(playerid);
    }
    return 1;
}

stock ShowPlayerSelectCharacterInfoLd(playerid, slot) 
{
    SetTimerEx("ShowPlayerSelectCharacterInfo", 1000, false, "dd", playerid, slot);
    return 1;
}