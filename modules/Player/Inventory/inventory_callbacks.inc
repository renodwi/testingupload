hook OnGameModeInit()
{
    AddAdminCommand(Admin2, "/playerinventory", "Digunakan untuk mengatur inventory player");
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(IsKeyJustDown(KEY_YES, newkeys, oldkeys))
    {
        new droppeditemid = -1, type, dropped_itemamount, maksimal, dibawa = 0, bisadibawa = 0;
        droppeditemid = GetNearestDroppedItem(playerid);

        if (droppeditemid != -1)
        {
            type = GetDroppedItemType(droppeditemid);
            dropped_itemamount = GetDroppedItemAmount(droppeditemid);
            maksimal = GetItemMaxStack(type);
            
            new itemID = GetItemIDByType(type);
            new itemname[64], itemUnit[32];
            format(itemname, sizeof(itemname), "%s", GetItemName(itemID));
            format(itemUnit, sizeof(itemUnit), "%s", GetItemUnitName(itemID));

            dibawa = IsPlayerHaveItems(playerid, type);
            if (dibawa == -1) dibawa = 0; // Jika player belum memiliki item, atur dibawa = 0

            bisadibawa = maksimal - dibawa;
            if (bisadibawa < 0) bisadibawa = 0; // Pastikan tidak negatif

            printf("A %d", dropped_itemamount);
            printf("B %d", maksimal);
            printf("C %d", dibawa);
            printf("D %d", bisadibawa);

            if (bisadibawa == 0)
                return SendErrorMessage(playerid, "Anda tidak dapat membawa lebih banyak %s lagi!", itemname);

            new jumlahDiambil = (dropped_itemamount > bisadibawa) ? bisadibawa : dropped_itemamount;
            AddPlayerItems(playerid, type, jumlahDiambil);

            SendClientMessageEx(playerid, COLOR_REN, "ITEM: "WHITE"Anda telah mengambil "YELLOW"%s"WHITE" sebanyak "LG"%d %s", itemname, jumlahDiambil, itemUnit);

            if (dropped_itemamount > jumlahDiambil)
            {
                SetDroppedItemAmount(droppeditemid, dropped_itemamount - jumlahDiambil);
                RefreshDroppedItem(droppeditemid);
                Streamer_Update(playerid);
            }
            else
            {
                DeleteDroppedItem(droppeditemid);
            }
            return 1;
        }
    }
    return 1;
}

function OnPlayerInventoryAdd(playerid, slot) 
{
    pinventoryInfo[playerid][slot][pinventoryDBID] = cache_insert_id();
    return 1;
}

hook OnPlayerConnect(playerid)
{
    ResetPlayerInventory(playerid);
    return 1;
}

function AssignPlayerInventory(playerid) 
{
    new rows  = cache_num_rows();
    if(rows)
    {
		for(new i; i < rows; i++)
		{
            cache_get_value_int(i, "id", pinventoryInfo[playerid][i][pinventoryDBID]);
            cache_get_value_int(i, "type", pinventoryInfo[playerid][i][pinventoryType]);
            cache_get_value_int(i, "amount", pinventoryInfo[playerid][i][pinventoryAmount]);

            pinventoryInfo[playerid][i][pinventoryExist] = true;

            #if defined DEBUG_MODE
                printf("[Player Inventory] Player: %s ID: %d Type: %d Amount: %d", GetName(playerid), pinventoryInfo[playerid][i][pinventoryDBID], pinventoryInfo[playerid][i][pinventoryType], pinventoryInfo[playerid][i][pinventoryAmount]);
            #endif
		}
	}
    return 1;
}