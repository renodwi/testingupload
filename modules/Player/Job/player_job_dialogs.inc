stock ShowPlayerJobOffer(playerid, type)
{
    new bool:player_has_joinjob = false;
    Loop(i, playerInfo[playerid][playerMaxJob])
    {
        if(playerjobInfo[playerid][i][playerjobType] == type)
        {
            player_has_joinjob = true;
            break;
        }
    }

    if(player_has_joinjob == true) 
        return SendErrorMessage(playerid, "Anda sebelumnya telah bergabung dalam pekerjaan %s!", job_name[type]);

    player_joinjob_offertype[playerid] = type;
    Dialog_Show(playerid, PlayerJob_Offer, DIALOG_STYLE_MSGBOX, "Pekerjaan > Terima", va_return("Anda yakin akan menerima pekerjaan sebagai %s?", job_name[type]), "Ya", "Tidak");
    return 1;
}

stock ShowPlayerJob(playerid, type, slot = -1)
{
    switch(type) 
    {
        case PLAYERJOB_LIST:
        {
            new message[2000];
            Loop(i, playerInfo[playerid][playerMaxJob])
            {
                if(playerjobInfo[playerid][i][playerjobExist] == true) 
                {
                    format(message, sizeof(message), "%s"WHITE"%s\n", message, job_name[playerjobInfo[playerid][i][playerjobType]]);
                }
            }
            Dialog_Show(playerid, PlayerJob_List, DIALOG_STYLE_LIST, "Pekerjaan", message, "Pilih", "Tutup");
        }
        case PLAYERJOB_EXIT:
        {
            player_quitjob_slot[playerid] = slot;
            Dialog_Show(playerid, PlayerJob_Exit, DIALOG_STYLE_LIST, "Pekerjaan > Keluar", "a", "Keluar", "Kembali");
        }
    }
    return 1;
}

Dialog:PlayerJob_List(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    else
    {
        if(playerjobInfo[playerid][listitem][playerjobDelayUntil] >= Now())
        {
            SendErrorMessage(playerid, "Anda dapat keluar dari pekerjaan ini pada %s %s", TimestampToDateString(playerjobInfo[playerid][listitem][playerjobDelayUntil]), TimestampToTimeString(playerjobInfo[playerid][listitem][playerjobDelayUntil]));
        }
        else
        {
            ShowPlayerJob(playerid, PLAYERJOB_EXIT, listitem);
        }
    }
    return 1;
}

Dialog:PlayerJob_Exit(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowPlayerJob(playerid, PLAYERJOB_LIST);
    else
    {
        SendClientMessageEx(playerid, COLOR_REN, "PEKERJAAN: "WHITE"Anda telah keluar dari pekerjaan sebagai "LR"%s", job_name[playerjobInfo[playerid][player_quitjob_slot[playerid]][playerjobType]]);
        ResetPlayerJob(playerid, player_quitjob_slot[playerid], true);
    }
    return 1;
}

Dialog:PlayerJob_Offer(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    else
    {
        new type = player_joinjob_offertype[playerid];
        SendClientMessageEx(playerid, COLOR_REN, "PEKERJAAN: "WHITE"Selamat! Anda telah bergabung ke pekerjaan sebagai "YELLOW"%s", job_name[type]);
        AddPlayerJob(playerid, type);
    }
    return 1;
}