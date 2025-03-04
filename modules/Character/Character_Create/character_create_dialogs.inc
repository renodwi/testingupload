stock ShowPlayerCreateCharacterDialog(playerid, dialog) 
{
    switch(dialog) 
    {
        case CREATE_CHARACTER_FIRSTNAME:
        {
            Dialog_Show(playerid, CreateCharacter_Firstname, DIALOG_STYLE_INPUT, "Nama Depan", "Masukkan nama depan karakter kamu.", "Ubah", "Batal");
        }
        case CREATE_CHARACTER_LASTNAME:
        {
            Dialog_Show(playerid, CreateCharacter_Lastname, DIALOG_STYLE_INPUT, "Nama Belakang", "Masukkan nama belakang karakter kamu.", "Ubah", "Kembali");
        }
        case CREATE_CHARACTER_ORIGIN:
        {
            new message[3000];
            Loop(i, sizeof(create_character_origin))
            {
                format(message, sizeof(message), "%s%s\n", message, create_character_origin[i]);
            }
            Dialog_Show(playerid, CreateCharacter_Origin, DIALOG_STYLE_LIST, "Pilih negara asal karakter", message, "Pilih", "Batal");
        }
        case CREATE_CHARACTER_GENDER:
        {
            Dialog_Show(playerid, CreateCharacter_Gender, DIALOG_STYLE_LIST, "Pilih jenis kelamin karakter", "Laki-Laki\nPerempuan", "Pilih", "Batal");
        }
        case CREATE_CHARACTER_BIRTH_YEAR:
        {
            new message[3000];
            for(new i = 1970; i < 2005; i++) 
            {
                format(message, sizeof(message), "%s%d\n", message, i);
            }
            Dialog_Show(playerid, CreateCharacter_BirthYear, DIALOG_STYLE_LIST, "Pilih tahun kelahiran karakter", message, "Pilih", "Batal");
        }
        case CREATE_CHARACTER_BIRTH_MONTH:
        {
            new message[3000];
            for(new i = 0; i < 12; i++) 
            {
                format(message, sizeof(message), "%s%s\n", message, GetMonthName(i + 1));
            }
            Dialog_Show(playerid, CreateCharacter_BirthMonth, DIALOG_STYLE_LIST, "Pilih bulan kelahiran karakter", message, "Pilih", "Batal");
        }
        case CREATE_CHARACTER_BIRTH_DAY:
        {
            new message[3000];
            for(new i = 0; i < GetMonthDay(player_create_character_month[playerid], player_create_character_year[playerid]); i++) 
            {
                format(message, sizeof(message), "%s%d\n", message, i + 1);
            }
            Dialog_Show(playerid, CreateCharacter_BirthDay, DIALOG_STYLE_LIST, "Pilih tanggal kelahiran karakter", message, "Pilih", "Batal");
        }
        case CREATE_CHARACTER_CANCEL:
        {
            Dialog_Show(playerid, CreateCharacter_Cancel, DIALOG_STYLE_MSGBOX, "Membatalkan pembuatan karakter", ""WHITE"Anda yakin akan "RED"membatalkan"WHITE" pembuatan karakter? Data tidak akan disimpan!", "Ya", "Tidak");
        }
        case CREATE_CHARACTER_SPAWN:
        {
            new message[3000];
            format(message, sizeof(message), "Lokasi\tRoleplay\n");
            Loop(i, sizeof(createcharacterSpawnInfo))
            {
                format(message, sizeof(message), "%s"WHITE"%s\t"YELLOW"(%s)\n", message, createcharacterSpawnInfo[i][createcharacterSpawnName], createcharacterSpawnInfo[i][createcharacterSpawnRoleplay]);
            }
            Dialog_Show(playerid, CreateCharacter_Spawn, DIALOG_STYLE_TABLIST_HEADERS, "Pilih spawn pertama karakter", message, "Pilih", "Batal");
        }
        case CREATE_CHARACTER_CONFIRM:
        {
            new message[3000];
            format(message, sizeof(message), "%s"YELLOW"Konfirmasi pembuatan karakter\n\n", message);
            format(message, sizeof(message), "%s"WHITE"Nama: "YELLOW"%s\n", message, player_create_character_name[playerid]);
            format(message, sizeof(message), "%s"WHITE"Asal: "PURPLE"%s\n", message, player_create_character_origin[playerid]);
            if(player_create_character_gender[playerid] == GENDER_MALE)
            {
                format(message, sizeof(message), "%s"WHITE"Jenis Kelamin: "LB"Laki-Laki\n", message);
            }
            else 
            {
                format(message, sizeof(message), "%s"WHITE"Jenis Kelamin: "PINK"Perempuan\n", message);
            }
            format(message, sizeof(message), "%s"WHITE"Tanggal Lahir: "LG"%s\n", message, player_create_character_birth[playerid]);
            format(message, sizeof(message), "%s"WHITE"Lokasi Spawn: "YELLOW"%s\n\n", message, createcharacterSpawnInfo[player_create_character_spawn[playerid]][createcharacterSpawnName]);
            format(message, sizeof(message), "%s"WHITE"Pastikan data karakter kamu benar.\n", message);
            format(message, sizeof(message), "%s\n", message);
            Dialog_Show(playerid, CreateCharacter_Confirm, DIALOG_STYLE_MSGBOX, "Konfirmasi", message, "Ya", "Kembali");
        }
    }
    return 1;
}

Dialog:CreateCharacter_Firstname(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    else 
    {
        if(!IsAlphaOnly(inputtext))
        {
            Dialog_Show(playerid, CreateCharacter_Firstname, DIALOG_STYLE_INPUT, "Nama Depan", "Masukkan nama depan karakter kamu.\n\nMohon masukkan nama dengan sesuai...", "Ubah", "Batal");
            return 1;
        }
        format(player_create_character_name[playerid], MAX_PLAYER_NAME + 1, "%s", inputtext);
        ShowPlayerCreateCharacterDialog(playerid, CREATE_CHARACTER_LASTNAME);
    }
    return 1;
}

Dialog:CreateCharacter_Lastname(playerid, response, listitem, inputtext[]) 
{
    if(!response) return ShowPlayerCreateCharacterDialog(playerid, CREATE_CHARACTER_FIRSTNAME);
    else 
    {
        if(!IsAlphaOnly(inputtext))
        {
            Dialog_Show(playerid, CreateCharacter_Lastname, DIALOG_STYLE_INPUT, "Nama Belakang", "Masukkan nama belakang karakter kamu.\n\nMohon masukkan nama dengan sesuai...", "Ubah", "Batal");
            return 1;
        }
        format(player_create_character_name[playerid], MAX_PLAYER_NAME + 1, "%s_%s", player_create_character_name[playerid], inputtext);

        new query[500];
        mysql_format(sql, query, sizeof(query), "SELECT * FROM `characters` WHERE `name` = '%e'", player_create_character_name[playerid]);
        mysql_tquery(sql, query, "CreateCharacterCheckName", "d", playerid);
    }
    return 1;
}

Dialog:CreateCharacter_Origin(playerid, response, listitem, inputtext[]) 
{
    if(!response) return 1;
    else 
    {
        format(player_create_character_origin[playerid], 50, create_character_origin[listitem]);
        ShowPlayerCreateCharacterInfo(playerid);
    }
    return 1;
}

Dialog:CreateCharacter_Gender(playerid, response, listitem, inputtext[]) 
{
    if(!response) return 1;
    else 
    {
        player_create_character_skin[playerid] = 0;
        player_create_character_gender[playerid] = listitem;
        ShowPlayerCreateCharacterInfo(playerid);
    }
    return 1; 
}

Dialog:CreateCharacter_BirthYear(playerid, response, listitem, inputtext[]) 
{
    if(!response) return 1;
    else 
    {
        player_create_character_year[playerid] = 1970 + listitem;
        ShowPlayerCreateCharacterDialog(playerid, CREATE_CHARACTER_BIRTH_MONTH);
    }
    return 1;
}

Dialog:CreateCharacter_BirthMonth(playerid, response, listitem, inputtext[]) 
{
    if(!response) return 1;
    else 
    {
        player_create_character_month[playerid] = listitem + 1;
        ShowPlayerCreateCharacterDialog(playerid, CREATE_CHARACTER_BIRTH_DAY);
    }
    return 1;
}

Dialog:CreateCharacter_BirthDay(playerid, response, listitem, inputtext[]) 
{
    if(!response) return 1;
    else 
    {
        player_create_character_day[playerid] = listitem + 1;

        format(player_create_character_birth[playerid], 50, "%d %s %d", player_create_character_day[playerid], GetMonthName(player_create_character_month[playerid]), player_create_character_year[playerid]);
        ShowPlayerCreateCharacterInfo(playerid);
    }
    return 1;
}

Dialog:CreateCharacter_Cancel(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    else 
    {
        if(IsValidDynamicActor(player_create_character_actor[playerid])) DestroyDynamicActor(player_create_character_actor[playerid]);
        HidePlayerCharacterCreateTD(playerid);

        InterpolateCameraPos(playerid, 993.823425, -842.478881, 99.866462, 1008.0490, -833.7874, 100.0157, 2000);
        InterpolateCameraLookAt(playerid, 993.841430, -846.532836, 100.266462, 1162.9019, -950.9866, 100.6472, 2000);

        ShowPlayerSelectCharacterInfo(playerid, 0);
    }
    return 1;
}

Dialog:CreateCharacter_Spawn(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    else 
    {
        player_create_character_spawn[playerid] = listitem;
        ShowPlayerCreateCharacterDialog(playerid, CREATE_CHARACTER_CONFIRM);
    }
    return 1;
}

Dialog:CreateCharacter_Confirm(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    else 
    {
        new player_skin;
        if(player_create_character_gender[playerid] == GENDER_MALE) 
        {
            player_skin = MaleSkinList[player_create_character_skin[playerid]];
        }
        else 
        {
            player_skin = FemaleSkinList[player_create_character_skin[playerid]];
        }

        CreateCharacter(accountInfo[playerid][accountDBID], player_create_character_name[playerid], player_create_character_origin[playerid], player_create_character_birth[playerid], player_create_character_gender[playerid], player_skin, createcharacterSpawnInfo[player_create_character_spawn[playerid]][createcharacterSpawnPosX], createcharacterSpawnInfo[player_create_character_spawn[playerid]][createcharacterSpawnPosY], createcharacterSpawnInfo[player_create_character_spawn[playerid]][createcharacterSpawnPosZ], createcharacterSpawnInfo[player_create_character_spawn[playerid]][createcharacterSpawnPosA]);
        ShowPlayerInfoBoxTextDraw(playerid, -1, "~g~~h~Berhasil", "Karakter kamu telah dibuat! Mohon tunggu sebentar");

        if(IsValidDynamicActor(player_create_character_actor[playerid])) DestroyDynamicActor(player_create_character_actor[playerid]);
        InterpolateCameraPos(playerid, 993.823425, -842.478881, 99.866462, 1008.0490, -833.7874, 100.0157, 2000);
        InterpolateCameraLookAt(playerid, 993.841430, -846.532836, 100.266462, 1162.9019, -950.9866, 100.6472, 2000);
        HidePlayerCharacterCreateTD(playerid);

        SetTimerEx("CreateCharacter_SelectChar", 5000, false, "d", playerid);
    }
    return 1;
}

Dialog:CreateCharacter_Error(playerid, response, listitem, inputtext[]) 
{
    return 1;
}