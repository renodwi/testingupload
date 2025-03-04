YCMD:allitems(playerid, params[], help) 
{
    new message[3000];
    format(message, sizeof(message), "Type\tCategory\tName\tDescription\n");
    foreach(new i : Items) 
    {
        if(Iter_Contains(Items, i)) 
        {
            format(message, sizeof(message), "%s"WHITE"%d\t%s\t%s\t%s\n", message, GetItemType(i), GetItemCategoryName(GetItemCategory(i)), GetItemName(i), GetItemDescription(i));
        }
    }
    Dialog_Show(playerid, AllItems, DIALOG_STYLE_TABLIST_HEADERS, "All Items", message, "Close", "");
    return 1;
}