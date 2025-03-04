new player_showanimation_slot[MAX_PLAYERS];
stock ShowPlayerSavedAnimationInfo(playerid, slot)
{
    player_showanimation_slot[playerid] = slot;

    new animstatus[20];
    if(IsSavedAnimationLooping(slot)) format(animstatus, sizeof(animstatus), "Looping");
    else format(animstatus, sizeof(animstatus), "Once Play");

    new message[3000];
    format(message, sizeof(message), "%s"WHITE"Animation Info\n\n", message);
    format(message, sizeof(message), "%s"WHITE"Anim Name: "YELLOW"%s\n", message, GetSavedAnimationName(slot));
    format(message, sizeof(message), "%s"WHITE"Creator: "LG"%s\n", message, GetSavedAnimationCreator(slot));
    format(message, sizeof(message), "%s"GREY"Animation: %s %s %s\n\n", message, GetSavedAnimationAnimLibrary(slot), GetSavedAnimationAnimName(slot), animstatus);
    Dialog_Show(playerid, SavedAnimation_Info, DIALOG_STYLE_MSGBOX, "Animation", message, "Play Animation", "Close");
    return 1;
}

Dialog:SavedAnimation_Info(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    else 
    {
        if(!IsPlayerOnFoot(playerid))
            return SendErrorMessage(playerid, "Anda harus berdiri untuk menggunakan fitur ini!");
        
        ApplySavedAnimation(playerid, player_showanimation_slot[playerid]);
    }
    return 1;
}

stock ShowPlayerAllSavedAnimation(playerid)
{
    ClearDialogListitems(playerid);

    AddDialogListitem(playerid, "#\tName\tCreator");
    foreach(new slot : SavedAnimation)
    {
        if(Iter_Contains(SavedAnimation, slot))
        {
            AddDialogListitem(playerid, "%d\t"YELLOW"%s\t"LG"%s", slot, GetSavedAnimationName(slot), GetSavedAnimationCreator(slot));
        }
    }
    ShowPlayerDialogPages(playerid, "SavedAnimation_AllList", DIALOG_STYLE_TABLIST_HEADERS, "All Animation", "Pilih", "Tutup", 20, ""LG"Next Page >>>", ""LG"Previous Page<<<");
    return 1;
}

DialogPages:SavedAnimation_AllList(playerid, response, listitem, inputtext[])
{
	if(!response) return 1;
    else 
    {
        ShowPlayerSavedAnimationInfo(playerid, listitem);
    }
	return 1;
}