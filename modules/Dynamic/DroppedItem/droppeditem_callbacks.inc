hook OnGameModeInit()
{
    AddAdminCommand(Admin2, "/createdroppeditem", "Digunakan untuk membuat item yang dijatuhkan");
    AddAdminCommand(Admin2, "/deletedroppeditem", "Digunakan untuk menghapus item yang dijatuhkan");
    return 1;
}

hook OnServerAssignData()
{
    mysql_tquery(sql, "SELECT * FROM `droppeditems`", "AssignDroppedItemData");
    return 1;
}

hook OneSecond()
{
    foreach(new i : DroppedItem) 
    {
        if(Iter_Contains(DroppedItem, i)) 
        {
            if(droppeditemInfo[i][droppeditemDeletedAt] < Now()) 
            {
                DeleteDroppedItem(i);
            }
        }
    }
    return 1;
}

function OnDroppedItemCreate(droppeditemid)
{
    RefreshDroppedItem(droppeditemid);
    return 1;
}