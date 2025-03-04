stock AddPlayerItems(playerid, type, amount) 
{
    if(amount == 0) return 1;

    if(IsPlayerHaveItems(playerid, type) == -1)
    {
        if(amount <= 0) return 1;

        new i = GetPlayerFreeInventorySlot(playerid);

        pinventoryInfo[playerid][i][pinventoryExist] = true;
        pinventoryInfo[playerid][i][pinventoryType] = type;
        pinventoryInfo[playerid][i][pinventoryAmount] = amount;

        new query[1000];
        mysql_format(sql, query, sizeof(query), "INSERT INTO `inventory` (`owner`, `type`, `amount`) VALUES ('%e', '%d', '%d')", playerInfo[playerid][playerName], type, amount);
        mysql_tquery(sql, query, "OnPlayerInventoryAdd", "dd", playerid, i);
    }
    else 
    {
        new i = GetPlayerInventorySlotFromType(playerid, type);
        pinventoryInfo[playerid][i][pinventoryAmount] += amount;

        new query[1000];
        mysql_format(sql, query, sizeof(query), "UPDATE `inventory` SET `amount` = '%d' WHERE `id` = '%d'", pinventoryInfo[playerid][i][pinventoryAmount], pinventoryInfo[playerid][i][pinventoryDBID]);
        mysql_tquery(sql, query);

        if(pinventoryInfo[playerid][i][pinventoryAmount] == 0)
        {
            pinventoryInfo[playerid][i][pinventoryExist] = false; 
            mysql_format(sql, query, sizeof(query), "DELETE FROM `inventory` WHERE `id` = '%d'", pinventoryInfo[playerid][i][pinventoryDBID]);
            mysql_tquery(sql, query);

            LoadPlayerInventory(playerid);
        }
    }
    return 1;
}

stock IsPlayerHaveItems(playerid, type) 
{
    for(new i = 0; i < MAX_PLAYER_INVENTORY; i++)
    {
        if(pinventoryInfo[playerid][i][pinventoryExist] == true && pinventoryInfo[playerid][i][pinventoryType] == type) 
        {
            return pinventoryInfo[playerid][i][pinventoryAmount]; // Segera kembalikan jumlahnya
        }
    }
    return -1;
}

stock GetPlayerFreeInventorySlot(playerid) 
{
    new slot;
    for(new i = 0; i < MAX_PLAYER_INVENTORY; i ++)
    {
        if(pinventoryInfo[playerid][i][pinventoryExist] == false) 
        {
            slot = i;
            break;
        }
    }
    return slot;
}

stock GetPlayerInventorySlotFromType(playerid, type) 
{
    new slot;
    for(new i = 0; i < MAX_PLAYER_INVENTORY; i ++)
    {
        if(pinventoryInfo[playerid][i][pinventoryExist] == true && pinventoryInfo[playerid][i][pinventoryType] == type) 
        {
            slot = i;
            break;
        }
    }
    return slot;
}

stock ResetPlayerInventory(playerid)
{
    for(new i = 0; i < MAX_PLAYER_INVENTORY; i ++)
    {
        pinventoryInfo[playerid][i][pinventoryExist] = false;
    }
    return 1;
}

stock LoadPlayerInventory(playerid) 
{
    ResetPlayerInventory(playerid);

    new query[256];
	mysql_format(sql, query, sizeof(query), "SELECT * FROM `inventory` WHERE `owner` = '%e'", playerInfo[playerid][playerName]);
	mysql_tquery(sql, query, "AssignPlayerInventory", "d", playerid);
    return 1;
}

stock ShowPlayerInventory(playerid)
{
    new slot;
    for(new i = 0; i < MAX_PLAYER_INVENTORY; i++)
    {
        if(pinventoryInfo[playerid][i][pinventoryExist] == true) 
        {
            slot = AddPlayerSelectionItem(playerid, GetItemModel(GetItemIDByType(pinventoryInfo[playerid][i][pinventoryType])), GetItemName(GetItemIDByType(pinventoryInfo[playerid][i][pinventoryType])), GetItemDescription(GetItemIDByType(pinventoryInfo[playerid][i][pinventoryType])));
            SetPlayerSelectionItemAmount(playerid, slot, pinventoryInfo[playerid][i][pinventoryAmount]);
        }
    }

    ShowPlayerSelection(playerid, Inventory, "Inventory");
    return 1;
}

Selection:Inventory(playerid, response, model, vehicle_color1, vehicle_color2)
{
    return 1;
}