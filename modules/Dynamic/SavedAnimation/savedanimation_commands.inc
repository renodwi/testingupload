YCMD:saveanim(playerid, params[], help)
{
    if(IsPlayerAdmin(playerid, Admin1))
    {
        new name[50], slot, looping;
        if(sscanf(params, "s[50]dd", name, slot, looping))
            return SendUsageMessage(playerid, "/saveanim [name] [animation: 0 - %d] [looping = 1 / once play = 0]", sizeof(panimation_Info));

        if(IsValidSavedAnimationName(name))
            return SendErrorMessage(playerid, "Nama animasi ini telah digunakan!");

        AddSavedAnimation(name, GetName(playerid), panimation_Info[slot][panimation_Library], panimation_Info[slot][panimation_Name], looping);
        SendClientMessageEx(playerid, COLOR_REN, "ANIMATION: "WHITE"Anda menyimpan animasi dengan nama "YELLOW"%s", name);
    }
    else if(!IsPlayerAlreadySaveAnimation(playerid))
    {
        new name[50], slot, looping;
        if(sscanf(params, "s[50]dd", name, slot, looping))
            return SendUsageMessage(playerid, "/saveanim [name] [animation: 0 - %d] [looping = 1 / once play = 0]", sizeof(panimation_Info));

        if(IsValidSavedAnimationName(name))
            return SendErrorMessage(playerid, "Nama animasi ini telah digunakan!");

        AddSavedAnimation(name, GetName(playerid), panimation_Info[slot][panimation_Library], panimation_Info[slot][panimation_Name], looping);
        SendClientMessageEx(playerid, COLOR_REN, "ANIMATION: "WHITE"Anda menyimpan animasi dengan nama "YELLOW"%s", name);
    }
    else SendErrorMessage(playerid, "Anda hanya dapat berkontribusi menyimpan 1 animasi saja!");
    return 1;
}

YCMD:deleteanim(playerid, params[], help)
{
    if(IsPlayerAdmin(playerid, Admin1))
    {
        new name[100];
        if(sscanf(params, "s[100]", name))
            return SendUsageMessage(playerid, "/deleteanim [saved animation name]");

        if(!IsValidSavedAnimationName(name))
            return SendErrorMessage(playerid, "Nama animasi tidak terdeteksi!");

        DeleteSavedAnimation(GetSavedAnimationSlotByName(name));
        SendClientMessageEx(playerid, COLOR_REN, "ANIMATION: "WHITE"Anda menghapus animasi "LR"%s", name);
    }
    else if(IsPlayerAlreadySaveAnimation(playerid))
    {
        new slot = GetSavedAnimationSlotByCreator(GetName(playerid));
        DeleteSavedAnimation(slot);
        SendClientMessageEx(playerid, COLOR_REN, "ANIMATION: "WHITE"Anda menghapus animasi "LR"%s", GetSavedAnimationName(slot));
    }
    else SendErrorMessage(playerid, "Anda hanya dapat berkontribusi menyimpan 1 animasi saja!");
    return 1;
}

YCMD:checkanim(playerid, params[], help)
{
    new animname[100];
    if(sscanf(params, "s[100]", animname))
        return SendUsageMessage(playerid, "/checkanim [animation name]");

    if(!IsValidSavedAnimationName(animname))
        return SendErrorMessage(playerid, "Nama animasi '%s' tidak terdeteksi!", animname);

    ShowPlayerSavedAnimationInfo(playerid, GetSavedAnimationSlotByName(animname));
    return 1;
}

YCMD:checkallanim(playerid, params[], help)
{
    ShowPlayerAllSavedAnimation(playerid);
    return 1;
}