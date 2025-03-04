stock ShowPlayerCreateCharacterInfo(playerid)
{
    if(IsValidDynamicActor(player_create_character_actor[playerid])) DestroyDynamicActor(player_create_character_actor[playerid]);

    if(player_create_character_gender[playerid] == GENDER_MALE) 
    {
        player_create_character_actor[playerid] = CreateDynamicActor(MaleSkinList[player_create_character_skin[playerid]], 995.021606, -846.437072, 99.866462, 1.704791, 1, 100.0, GetPlayerVirtualWorld(playerid));
    }
    else 
    {
        player_create_character_actor[playerid] = CreateDynamicActor(FemaleSkinList[player_create_character_skin[playerid]], 995.021606, -846.437072, 99.866462, 1.704791, 1, 100.0, GetPlayerVirtualWorld(playerid));
    }

    ShowPlayerCreateCharacterTD(playerid, player_create_character_name[playerid], player_create_character_origin[playerid], player_create_character_birth[playerid], player_create_character_gender[playerid]);
    return 1;
}

stock SetupPlayerCreateCharacter(playerid)
{
    ResetPlayerCreateCharacter(playerid);
    InterpolateCameraPos(playerid, 1008.0490, -833.7874, 100.0157, 993.823425, -842.478881, 99.866462, 2000);
    InterpolateCameraLookAt(playerid, 1162.9019, -950.9866, 100.6472, 993.841430, -846.532836, 100.266462, 2000);
    return 1;
}

stock ResetPlayerCreateCharacter(playerid) 
{
    format(player_create_character_name[playerid], MAX_PLAYER_NAME + 1, "Namadepan_Namabelakang");
    format(player_create_character_origin[playerid], 50, "Indonesia");
    format(player_create_character_birth[playerid], 50, "1 Januari 1970");
    player_create_character_gender[playerid] = GENDER_MALE;
    player_create_character_skin[playerid] = 0;
    return 1;
}

stock CreateCharacter(account_id, const name[], const origin[], const birth_date[], gender, skin, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:spawn_a) 
{
    new query[3000];
    mysql_format(sql, query, sizeof(query), 
        "INSERT INTO `characters` (`account_id`, `name`, `origin`, `birth_date`, `gender`, `skin`, `money`, `position_x`, `position_y`, `position_z`, `position_a`, `hungry`, `thrist`, `health`, `armour`)\
        VALUES ('%d', '%e', '%e', '%e', '%d', '%d', '25000', '%f', '%f', '%f', '%f', '100', '100', '100', '0')", 
        account_id, name, origin, birth_date, gender, skin, spawn_x, spawn_y, spawn_z, spawn_a
    );
    mysql_tquery(sql, query);
    return 1;
}