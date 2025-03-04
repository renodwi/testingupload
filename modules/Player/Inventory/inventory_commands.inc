YCMD:inventory(playerid, params[], help) 
{
    if(!IsPlayerSpawned(playerid)) return 1;
    ShowPlayerInventory(playerid);
    return 1;
}

YCMD:playerinventory(playerid, params[], help) 
{
    if(!IsPlayerAdmin(playerid, Admin2))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");

    new type[50], string[200], bool:syntax = true;
    if(sscanf(params, "s[50]S()[200]", type, string))
    {
        syntax = false;
    }
    else 
    {
        if(!strcmp(type, "give", true)) 
        {
            new toplayer, itemtype, amount;
            if(sscanf(string, "ddd", toplayer, itemtype, amount))
                return SendUsageMessage(playerid, "/playerinventory give [to playerid / username] [item type (plz see /allitems)] [amount]");

            if(!IsPlayerSpawned(toplayer))
                return SendErrorMessage(playerid, "Invalid player ID!");

            if(GetItemIDByType(itemtype) == -1)
                return SendErrorMessage(playerid, "Invalid item type, tolong cek pada bagian /allitems!");

            if(amount <= 0)
                return SendErrorMessage(playerid, "Item yang diberikan tidak dapat kurang atau sama dengan 0!");

            AddPlayerItems(toplayer, itemtype, amount);

            SendClientMessageEx(playerid, COLOR_REN, "INVENTORY: "WHITE"Anda memberi "YELLOW"%d %s"WHITE" kepada "YELLOW"%s", amount, GetItemName(GetItemIDByType(itemtype)), RemoveUnderscore(playerInfo[toplayer][playerName]));
            SendClientMessageEx(toplayer, COLOR_REN, "INVENTORY: "LR"%s "WHITE"memberi anda "YELLOW"%d %s", GetAdminName(playerid), amount, GetItemName(GetItemIDByType(itemtype)));
        }
        else if(!strcmp(type, "remove", true)) 
        {
            new toplayer, itemtype, amount;
            if(sscanf(string, "ddd", toplayer, itemtype, amount))
                return SendUsageMessage(playerid, "/playerinventory remove [to playerid / username] [item type (plz see /allitems)] [amount]");

            if(!IsPlayerSpawned(toplayer))
                return SendErrorMessage(playerid, "Invalid player ID!");

            if(GetItemIDByType(itemtype) == -1)
                return SendErrorMessage(playerid, "Invalid item type, tolong cek pada bagian /allitems!");

            if(IsPlayerHaveItems(playerid, itemtype) == -1)
                return SendErrorMessage(playerid, "Player tersebut tidak memiliki item yang dimaksud!");

            if(amount <= 0)
                return SendErrorMessage(playerid, "Item yang akan dihilangkan tidak dapat kurang atau sama dengan 0!");

            if(amount > IsPlayerHaveItems(playerid, itemtype))
                return SendErrorMessage(playerid, "Player tersebut tidak memiliki %s sebanyak itu!", GetItemName(GetItemIDByType(itemtype)));

            AddPlayerItems(toplayer, itemtype, -amount);

            SendClientMessageEx(playerid, COLOR_REN, "INVENTORY: "WHITE"Anda memberi "YELLOW"%d %s"WHITE" kepada "YELLOW"%s", amount, GetItemName(GetItemIDByType(itemtype)), RemoveUnderscore(playerInfo[toplayer][playerName]));
            SendClientMessageEx(toplayer, COLOR_REN, "INVENTORY: "LR"%s "WHITE"memberi anda "YELLOW"%d %s", GetAdminName(playerid), amount, GetItemName(GetItemIDByType(itemtype)));
        }
        else if(!strcmp(type, "clear", true)) 
        {
            new toplayer, itemtype;
            if(sscanf(string, "dd", toplayer, itemtype))
                return SendUsageMessage(playerid, "/playerinventory clear [to playerid / username] [item type (plz see /allitems)]");

            if(!IsPlayerSpawned(toplayer))
                return SendErrorMessage(playerid, "Invalid player ID!");

            if(GetItemIDByType(itemtype) == -1)
                return SendErrorMessage(playerid, "Invalid item type, tolong cek pada bagian /allitems!");

            if(IsPlayerHaveItems(playerid, itemtype) == -1)
                return SendErrorMessage(playerid, "Player tersebut tidak memiliki item yang dimaksud!");

            for(new i = 0; i < MAX_PLAYER_INVENTORY; i ++)
            {
                if(pinventoryInfo[toplayer][i][pinventoryExist] == true && pinventoryInfo[toplayer][i][pinventoryType] == itemtype)
                {
                    pinventoryInfo[toplayer][i][pinventoryAmount] = 0;
                    pinventoryInfo[toplayer][i][pinventoryExist] = false;
                }
            }

            SendClientMessageEx(playerid, COLOR_REN, "INVENTORY: "WHITE"Anda menghilangkan "YELLOW"%s"WHITE" dari inventory "YELLOW"%s", GetItemName(GetItemIDByType(itemtype)), RemoveUnderscore(playerInfo[toplayer][playerName]));
            SendClientMessageEx(toplayer, COLOR_REN, "INVENTORY: "WHITE"Anda sekarang tidak memiliki "YELLOW"%s", GetItemName(GetItemIDByType(itemtype)));
        }
        else if(!strcmp(type, "reset", true)) 
        {
            new toplayer;
            if(sscanf(string, "d", toplayer))
                return SendUsageMessage(playerid, "/playerinventory reset [to playerid / username]");

            if(!IsPlayerSpawned(toplayer))
                return SendErrorMessage(playerid, "Invalid player ID!");

            ResetPlayerInventory(toplayer);

            SendClientMessageEx(playerid, COLOR_REN, "INVENTORY: "WHITE"Anda telah mereset inventory milik "YELLOW"%s", RemoveUnderscore(playerInfo[toplayer][playerName]));
            SendClientMessageEx(toplayer, COLOR_REN, "INVENTORY: "LR"%s"WHITE" telah mereset inventory anda", GetAdminName(playerid));
        }
        else syntax = false;
    }

    if(syntax == false) 
    {
        SendUsageMessage(playerid, "/playerinventory [type]");
        SendClientMessageEx(playerid, COLOR_REN, "TYPE: give remove clear reset");
    }
    return 1;
}