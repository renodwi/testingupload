YCMD:createdroppeditem(playerid, params[], help)
{
    if(!IsPlayerAdmin(playerid, Admin2))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");

    ShowPlayerDroppedItemMenu(playerid);
    return 1;
}

YCMD:deletedroppeditem(playerid, params[], help) 
{
    if(!IsPlayerAdmin(playerid, Admin2))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");

    new droppeditemid = -1;
    foreach(new i : DroppedItem) 
    {
        if(IsPlayerInRangeOfPoint(playerid, 1.5, droppeditemInfo[i][droppeditemPositionX], droppeditemInfo[i][droppeditemPositionY], droppeditemInfo[i][droppeditemPositionZ]))
        {
            droppeditemid = i;
            break;
        }
    }

    if(droppeditemid == -1) return SendErrorMessage(playerid, "Anda tidak berada di dekat item yang dijatuhkan!");
    else DeleteDroppedItem(droppeditemid);
    return 1;
}