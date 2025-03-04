hook OnPlayerConnect(playerid)
{
    player_create_character_actor[playerid] = INVALID_ACTOR_ID;
    LoadPlayerCreateCharacterTD(playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyPlayerCharacterCreateTD(playerid);
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if(playertextid == character_creator_ubahnamabtn[playerid])
    {
        ShowPlayerCreateCharacterDialog(playerid, CREATE_CHARACTER_FIRSTNAME);
    }
    else if(playertextid == character_creator_ubahasalbtn[playerid]) 
    {
        ShowPlayerCreateCharacterDialog(playerid, CREATE_CHARACTER_ORIGIN);
    }
    else if(playertextid == character_creator_ubahklmnbtn[playerid]) 
    {
        ShowPlayerCreateCharacterDialog(playerid, CREATE_CHARACTER_GENDER);
    }
    else if(playertextid == character_creator_ubahlahirbtn[playerid])
    {
        ShowPlayerCreateCharacterDialog(playerid, CREATE_CHARACTER_BIRTH_YEAR);
    }
    else if(playertextid == character_creator_bajuleft[playerid])
    {
        new skin_max;
        if(player_create_character_gender[playerid] == GENDER_MALE) skin_max = sizeof(MaleSkinList) - 1;
        else skin_max = sizeof(FemaleSkinList) - 1;

        if(player_create_character_skin[playerid] == 0)
        {
            player_create_character_skin[playerid] = skin_max;
            ShowPlayerCreateCharacterInfo(playerid);
        }
        else 
        {
            player_create_character_skin[playerid] = player_create_character_skin[playerid] - 1;
            ShowPlayerCreateCharacterInfo(playerid);
        }
    }
    else if(playertextid == character_creator_bajuright[playerid])
    {
        new skin_max;
        if(player_create_character_gender[playerid] == GENDER_MALE) skin_max = sizeof(MaleSkinList) - 1;
        else skin_max = sizeof(FemaleSkinList) - 1;

        if(player_create_character_skin[playerid] == skin_max)
        {
            player_create_character_skin[playerid] = 0;
            ShowPlayerCreateCharacterInfo(playerid);
        }
        else    
        {
            player_create_character_skin[playerid] = player_create_character_skin[playerid] + 1;
            ShowPlayerCreateCharacterInfo(playerid);
        }
    } 
    else if(playertextid == character_creator_konfirmasibtn[playerid]) 
    {
        if(!strcmp(player_create_character_name[playerid], "Namadepan_Namabelakang"))
        {
            Dialog_Show(playerid, CreateCharacter_Error, DIALOG_STYLE_MSGBOX, "Error", "Tolong lengkapi semua data karakter terlebih dahulu!", "Ya", "");
        }
        else 
        {
            ShowPlayerCreateCharacterDialog(playerid, CREATE_CHARACTER_SPAWN);
        }
    }
    else if(playertextid == character_creator_batalkanbtn[playerid])
    {
        ShowPlayerCreateCharacterDialog(playerid, CREATE_CHARACTER_CANCEL);
    }
    return 1;
}

function CreateCharacter_SelectChar(playerid) 
{
    LoadPlayerCharacters(playerid);
    ShowPlayerSelectCharacterInfoLd(playerid, 0);
    return 1;
}

function CreateCharacterCheckName(playerid) 
{
    if(cache_num_rows())
    {
        SendErrorMessage(playerid, "Nama karakter %s telah digunakan, tolong gunakan nama lainnya.", player_create_character_name[playerid]);
        ShowPlayerCreateCharacterDialog(playerid, CREATE_CHARACTER_FIRSTNAME);
    }
    else 
    {
        ShowPlayerCreateCharacterInfo(playerid);
    }
    return 1;
}