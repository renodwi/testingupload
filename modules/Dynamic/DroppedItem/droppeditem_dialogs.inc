

stock ShowPlayerDroppedItemMenu(playerid, menu = DROPPEDITEM_CREATE_TYPE)
{
    switch(menu) 
    {
        case DROPPEDITEM_CREATE_TYPE:
        {
            foreach(new i : Items) 
            {
                if(Iter_Contains(Items, i))
                {
                    AddDialogListitem(playerid, ""WHITE"%s\n", GetItemName(i));
                }
            }
            ShowPlayerDialogPages(playerid, "DroppedItem_Create_Type", DIALOG_STYLE_LIST, "Pilih item yang akan dijatuhkan", "Pilih", "Tutup", 20);
        }
        case DROPPEDITEM_CREATE_AMOUNT:
        {
            Dialog_Show(playerid, DroppedItem_Create_Amount, DIALOG_STYLE_INPUT, "Jumlah", "Berapa item yang akan dijatuhkan?", "Pilih", "Kembali");
        }
    }
    return 1;
}

DialogPages:DroppedItem_Create_Type(playerid, response, listitem, inputtext[]) 
{
    if(!response) return 1;
    else 
    {
        player_droppeditemcreate_type[playerid] = listitem;
        ShowPlayerDroppedItemMenu(playerid, DROPPEDITEM_CREATE_AMOUNT);
    }
    return 1;
}

Dialog:DroppedItem_Create_Amount(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowPlayerDroppedItemMenu(playerid, DROPPEDITEM_CREATE_TYPE);
    else
    {
        new amount;
        if(sscanf(inputtext, "d", amount))
            return ShowPlayerDroppedItemMenu(playerid, DROPPEDITEM_CREATE_AMOUNT);

        if(amount <= 0)
            return ShowPlayerDroppedItemMenu(playerid, DROPPEDITEM_CREATE_AMOUNT);

        player_droppeditemcreate_amount[playerid] = amount;

        new Float:x, Float:y, Float:z, Float:a;
        GetPlayerPos(playerid, x, y, z);
        GetPlayerFacingAngle(playerid, a);

        CreateDroppedItem(player_droppeditemcreate_type[playerid], player_droppeditemcreate_amount[playerid], x, y, z, a, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid));
    }
    return 1;
}