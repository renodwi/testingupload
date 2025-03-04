YCMD:jobduty(playerid, params[], help) 
{
    if(IsPlayerJobDuty(playerid)) 
    {
        SendClientMessageEx(playerid, COLOR_REN, "PEKERJAAN: "WHITE"Anda telah "LR"menyelesaikan"WHITE" pekerjaan sebagai "YELLOW"%s", job_name[IsPlayerJobDuty(playerid)]);
        SetPlayerJobDuty(playerid, IsPlayerJobDuty(playerid), false);
    }
    else
    {
        new type = 0;
        if(!strcmp(params, "mechanic", true)) type = JOB_MECHANIC;
        else SendUsageMessage(playerid, "/jobduty [mechanic]");

        if(!IsPlayerInJob(playerid, type))
            return SendErrorMessage(playerid, "Anda tidak bergabung dalam pekerjaan sebagai %s!", job_name[type]);

        SetPlayerJobDuty(playerid, type, true);
        SendClientMessageEx(playerid, COLOR_REN, "PEKERJAAN: "WHITE"Anda "LG"memulai"WHITE" pekerjaan sebagai "YELLOW"%s", job_name[type]);
    }
    return 1;
}

YCMD:joinjob(playerid, params[], help)
{
    new bool:can_joinjob = false;
    if(GetPlayerJobFreeSlot(playerid) != -1) can_joinjob = true;
    
    if(can_joinjob == false)
        return SendErrorMessage(playerid, "Anda telah bergabung ke salah satu pekerjaan, keluar dari pekerjaan terlebih dahulu '/quitjob'");
    
    if(IsPlayerInJoinJobPickup(playerid) != -1)
    {
        ShowPlayerJobOffer(playerid, IsPlayerInJoinJobPickup(playerid));
    }
    return 1;
}

YCMD:playerjob(playerid, params[], help) 
{
    if(!IsPlayerAdmin(playerid, Manager))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");

    new action[50], string[250], bool:syntax = true;
    if(sscanf(params, "s[50]S()[250]", action, string))
    {
        syntax = false;
    }
    else
    {
        if(!strcmp(action, "add", true))
        {
            new toplayer, type[50];
            if(sscanf(string, "ds[50]", toplayer, type))
            {
                SendUsageMessage(playerid, "/playerjob add [toplayer] [job type]");

                new message[1000];
                Loop(i, sizeof(job_name))
                {
                    format(message, sizeof(message), "%s"WHITE"%s ", message, job_name[i]);
                }
                SendClientMessageEx(playerid, COLOR_REN, "JOB-TYPE: %s", message);
                return 1;
            }
            else
            {
                if(!IsPlayerSpawned(toplayer))
                    return SendErrorMessage(playerid, "Player tujuan tidak terdeteksi!");

                new slot = -1;
                slot = GetPlayerJobFreeSlot(toplayer);

                if(slot == -1)
                    return SendErrorMessage(playerid, "Player tujuan tidak memiliki slot pekerjaan yang kosong!");

                new jobid = -1;
                Loop(i, sizeof(job_name))
                {
                    if(!strcmp(job_name[i], type, true))
                    {
                        jobid = i;
                        break;
                    }
                }

                if(jobid == -1)
                    return SendErrorMessage(playerid, "Tipe pekerjaan tidak sesuai!");

                AddPlayerJob(toplayer, jobid);
                SendClientMessageEx(toplayer, COLOR_REN, "PEKERJAAN: "WHITE"Admin "LR"%s"WHITE" telah menambah pekerjaan "YELLOW"%s"WHITE" kepada anda", GetAdminName(playerid), job_name[jobid]);
                SendClientMessageEx(playerid, COLOR_REN, "PEKERJAAN: "WHITE"Anda telah menambahkan pekerjaan "YELLOW"%s"WHITE" kepada player "LG"%s", job_name, RemoveUnderscore(playerInfo[toplayer][playerName]));
            }
        }
        else if(!strcmp(action, "remove", true))
        {
            new toplayer, type[50];
            if(sscanf(string, "ds[50]", toplayer, type))
            {
                SendUsageMessage(playerid, "/playerjob remove [toplayer] [job type]");

                new message[1000];
                Loop(i, sizeof(job_name))
                {
                    if(i == 0) continue;
                    else
                    {
                        format(message, sizeof(message), "%s"WHITE"%s", message, job_name[i]);
                    }
                }
                SendClientMessageEx(playerid, COLOR_REN, "JOB-TYPE: %s", message);
                return 1;
            }
            else
            {
                if(!IsPlayerSpawned(toplayer))
                    return SendErrorMessage(playerid, "Player tujuan tidak terdeteksi!");

                new jobid = -1;
                Loop(i, sizeof(job_name))
                {
                    if(!strcmp(job_name[i], type, true))
                    {
                        jobid = i;
                        break;
                    }
                }

                new slot = IsPlayerInJob(toplayer, jobid);
                if(slot == -1)
                    return SendErrorMessage(playerid, "Player tujuan tidak bekerja pada pekerjaan %s!", job_name[jobid]);

                SendClientMessageEx(toplayer, COLOR_REN, "PEKERJAAN: "WHITE"Admin "LR"%s"WHITE" telah menghapus "YELLOW"%s"WHITE" dari daftar pekerjaan anda", GetAdminName(playerid), job_name[jobid]);
                SendClientMessageEx(playerid, COLOR_REN, "PEKERJAAN: "WHITE"Anda telah menghapus pekerjaan "YELLOW"%s"WHITE" dari "LG"%s", job_name[jobid], RemoveUnderscore(playerInfo[playerid][playerName]));
            
                ResetPlayerJob(toplayer, slot, true);
            }
        }
        else if(!strcmp(action, "slot", true))
        {
            new toplayer, amount;
            if(sscanf(string, "dd", toplayer, amount))
            {
                SendUsageMessage(playerid, "/playerjob slot [toplayer] [jumlah]");
                SendClientMessageEx(playerid, COLOR_REN, "INFO: (Jumlah minimal: 1) (Jumlah maksimal: %d)", MAX_PLAYER_JOB);
            }
            else
            {
                if(!IsPlayerSpawned(toplayer))
                    return SendErrorMessage(playerid, "Player tujuan tidak terdeteksi!");

                SendClientMessage(toplayer, COLOR_REN, "PEKERJAAN: "WHITE"Admin "LR"%s"WHITE" telah mengubah jumlah slot pekerjaan anda menjadi "LG"%d", GetAdminName(playerid), amount);
                SendClientMessageEx(playerid, COLOR_REN, "PEKERJAAN: "WHITE"Anda telah mengubah jumlah slot pekerjaan "YELLOW"%s"WHITE" menjadi "LG"%d", RemoveUnderscore(playerInfo[toplayer][playerName]), amount);
                
                playerInfo[toplayer][playerMaxJob] = amount;
                UpdateCharacterData(toplayer);
            }
        }
        else if(!strcmp(action, "check", true))
        {
            new toplayer;
            if(sscanf(string, "d", toplayer))
            {
                SendUsageMessage(playerid, "/playerjob check [toplayer]");
            }
            else
            {
                if(!IsPlayerSpawned(toplayer))
                    return SendErrorMessage(playerid, "Player tujuan tidak terdeteksi!");

                new message[1000], count = 0;
                Loop(i, playerInfo[toplayer][playerMaxJob])
                {
                    if(playerjobInfo[toplayer][i][playerjobExist] == true) 
                    {
                        format(message, sizeof(message), "%s"WHITE"%s\n", message, job_name[playerjobInfo[toplayer][i][playerjobType]]);
                        count++;
                    }
                }
                
                if(count == 0)
                    return SendErrorMessage(playerid, "%s Tidak memiliki pekerjaan!", RemoveUnderscore(playerInfo[toplayer][playerName]));

                Dialog_Show(playerid, Unused, DIALOG_STYLE_LIST, va_return("Pekerjaan %s %d/%d", RemoveUnderscore(playerInfo[toplayer][playerName]), count, playerInfo[playerid][playerMaxJob]), message, "Tutup", "");
            }
        }
    }

    if(syntax == false) 
    {
        SendUsageMessage(playerid, "/playerjob [action]");
        SendClientMessageEx(playerid, COLOR_REN, "ACTION: add remove slot check");
    }

    return 1;
}

YCMD:quitjob(playerid, params[], help)
{
    ShowPlayerJob(playerid, PLAYERJOB_LIST);
    return 1;
}