hook OnPlayerConnect(playerid) 
{
    player_select_character_actor[playerid] = INVALID_ACTOR_ID;
    player_select_character_slot[playerid] = 0;
    LoadPlayerCharacterSelectTD(playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyPlayerCharacterSelectTD(playerid);
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if(playertextid == character_selector_enterbtn[playerid])
    {
        if(playertextid == character_selector_enterbtn[playerid]) 
        {
            if(playercharacterInfo[playerid][player_select_character_slot[playerid]][playercharacterExist] == true) 
            {
                new query[1000];
                mysql_format(sql, query, sizeof(query), "SELECT * FROM `characters` WHERE `account_id` = '%d' AND `name` = '%e'", accountInfo[playerid][accountDBID], playercharacterInfo[playerid][player_select_character_slot[playerid]][playercharacterName]);
                mysql_tquery(sql, query, "AssignCharacterData", "d", playerid);

                HidePlayerCharacterSelectTD(playerid);

                if(IsValidDynamicActor(player_select_character_actor[playerid])) DestroyDynamicActor(player_select_character_actor[playerid]); 
            }
            else 
            {
                HidePlayerCharacterSelectTD(playerid);
                SetupPlayerCreateCharacter(playerid);
                ShowPlayerCreateCharacterInfo(playerid);
            }
        }
    }
    else if(playertextid == character_selector_leftbtn[playerid]) 
    {
        if(player_select_character_slot[playerid] == 0)
        {
            player_select_character_slot[playerid] = MAX_PLAYER_CHARACTER - 1;
            ShowPlayerSelectCharacterInfo(playerid, player_select_character_slot[playerid]);
        }
        else
        {
            player_select_character_slot[playerid] = player_select_character_slot[playerid] - 1;
            ShowPlayerSelectCharacterInfo(playerid, player_select_character_slot[playerid]);
        }
        ShowPlayerCharacterIndicator(playerid, player_select_character_slot[playerid], MAX_PLAYER_CHARACTER - 1);
    }
    else if(playertextid == character_selector_rightbtn[playerid]) 
    {
        if(player_select_character_slot[playerid] == MAX_PLAYER_CHARACTER - 1)
        {
            player_select_character_slot[playerid] = 0;
            ShowPlayerSelectCharacterInfo(playerid, player_select_character_slot[playerid]);
        }
        else
        {
            player_select_character_slot[playerid] = player_select_character_slot[playerid] + 1;
            ShowPlayerSelectCharacterInfo(playerid, player_select_character_slot[playerid]);
        }
        ShowPlayerCharacterIndicator(playerid, player_select_character_slot[playerid], MAX_PLAYER_CHARACTER - 1);
    }
    return 1;
}