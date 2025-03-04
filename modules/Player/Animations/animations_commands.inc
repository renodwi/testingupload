YCMD:anim(playerid, params[], help)
{
    if(!IsPlayerOnFoot(playerid))
        return SendErrorMessage(playerid, "Anda harus berdiri di tempat!");

    if(isnull(params))
        return SendUsageMessage(playerid, "/anim [nama animasi atau 0 - %d]", sizeof(panimation_Info));

    if(IsNumeric(params))
    {
        new slot = strval(params);
        if(slot > sizeof(panimation_Info) || slot < 0) 
            return SendUsageMessage(playerid, "/anim [nama animasi atau 0 - %d]", sizeof(panimation_Info));
            
        ApplyPlayerLoopingAnimation(playerid, panimation_Info[slot][panimation_Library], panimation_Info[slot][panimation_Name]);
    }
    else 
    {
        if(!IsValidSavedAnimationName(params))
            return SendErrorMessage(playerid, "Animasi '%s' tidak terdeteksi!", params);

        ApplySavedAnimation(playerid, GetSavedAnimationSlotByName(params));
    }
    return 1;
}