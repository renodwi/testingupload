YCMD:business(playerid, params[], help) 
{
    if(!IsPlayerAdmin(playerid, Manager))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");
        
    new type[100], string[200], bool:syntax = true;
    if(sscanf(params, "s[100]S()[200]", type, string))
    {
        syntax = false;
    }
    else 
    {
        if(!strcmp(type, "create", true)) 
        {
            new btype, price;
            if(sscanf(string, "dd", btype, price))
                return SendUsageMessage(playerid, "/business create [type] [price]"), SendClientMessageEx(playerid, COLOR_REN, "TYPE: [1 = Minimarket] [2 = Gym] [3 = Clothes Store] [4 = Restaurant] [5 = Electronic Store] [6 = Sport Store] [7 = Furniture Store]");

            if(btype < 1 || btype > 7)
                return SendUsageMessage(playerid, "/business create [type] [price]"), SendClientMessageEx(playerid, COLOR_REN, "TYPE: [1 = Minimarket] [2 = Gym] [3 = Clothes Store] [4 = Restaurant] [5 = Electronic Store] [6 = Sport Store] [7 = Furniture Store]");

            if(GetPlayerInterior(playerid) != 0)
                return SendErrorMessage(playerid, "Anda harus berada pada interior 0!");

            if(GetPlayerVirtualWorld(playerid) != 0)
                return SendErrorMessage(playerid, "Anda harus berada pada virtual world 0!");

            new Float:x, Float:y, Float:z, Float:a, businessid;
            GetPlayerPos(playerid, x, y, z);
            GetPlayerFacingAngle(playerid, a);

            businessid = CreateBusiness(btype - 1, price, x, y, z, a);

            SendClientMessageEx(playerid, COLOR_REN, "BUSINESS: "WHITE"Anda telah membuat "YELLOW"business %d"WHITE" dengan tipe "LB"%s"WHITE" dan harga "LG"$%s", businessid, BusinessTypeName[btype], FormatMoney(price));
        }
        else if(!strcmp(type, "edit", true)) 
        {
            new businessid;
            if(GetPlayerNearestBusiness(playerid) == -1)
            {
                if(sscanf(string, "d", businessid))
                    return SendUsageMessage(playerid, "/business edit [businessid]");
            }
            else 
            {
                businessid = GetPlayerNearestBusiness(playerid);
            }

            if(!Iter_Contains(Business, businessid))
                return SendErrorMessage(playerid, "Invalid business ID!");

            ShowPlayerEditBusinessDialog(playerid, businessid, EDIT_BUSINESS_LIST);
        }
        else if(!strcmp(type, "goto", true))
        {
            new businessid;
            if(sscanf(string, "d", businessid))
                return SendUsageMessage(playerid, "/business edit [businessid]");

            if(!Iter_Contains(Business, businessid))
                return SendErrorMessage(playerid, "Invalid business ID!");

            new Float:x, Float:y, Float:z, Float:a;
            GetBusinessExterior(businessid, x, y, z, a);
            SetPlayerPos(playerid, x, y, z);
            SetPlayerFacingAngle(playerid, a);
            SetPlayerInterior(playerid, 0);
            SetPlayerVirtualWorld(playerid, 0);

            SendClientMessageEx(playerid, COLOR_REN, "TELEPORT: "WHITE"Teleportasi ke "YELLOW"bisnis %d", businessid);
        }
        else syntax = false;
    }

    if(syntax == false) 
    {
        SendUsageMessage(playerid, "/business [menu] [string]");
        SendClientMessageEx(playerid, COLOR_REN, "MENU: create edit");
    }
    return 1;
}

YCMD:buybusiness(playerid, params[], help) 
{
    new businessid = -1;
    foreach(new i : Business) 
    {
        if(IsPlayerInDynamicArea(playerid, businessInfo[i][businessEnterCheckpoint])) 
        {
            businessid = i;
            break;
        }
        else businessid = -1;
    }

    if(businessid == -1) return SendErrorMessage(playerid, "Anda harus berada di dekat pintu masuk sebuah bisnis!");

    if(strcmp(GetBusinessOwner(businessid), "Unknown", true))
        return SendErrorMessage(playerid, "Bisnis ini telah dimiliki oleh seseorang!");
        
    if(GetPlayerMoney(playerid) < GetBusinessPrice(businessid))
        return SendErrorMessage(playerid, "Anda tidak memiliki cukup uang untuk membeli bisnis ini!");

    Dialog_Show(playerid, BusinessBuy_Confirm, DIALOG_STYLE_MSGBOX, "Beli Bisnis", va_return(""WHITE"Anda yakin akan membeli bisnis ini dengan harga "LG"$%s"WHITE"?", FormatMoney(GetBusinessPrice(businessid))), "Beli", "Tidak");
    player_buybusiness_id[playerid] = businessid;
    return 1;
}

YCMD:businessmenu(playerid, params[], help) 
{
    if(playerInfo[playerid][playerInBusiness] == -1)
        return SendErrorMessage(playerid, "Anda harus berada di dalam bisnis!");

    new businessid = playerInfo[playerid][playerInBusiness];
    if(strcmp(GetBusinessOwner(businessid), playerInfo[playerid][playerName], true))
        return SendErrorMessage(playerid, "Bisnis ini bukan milik anda!");

    ShowPlayerBusinessMenu(playerid, businessid, BUSINESS_MENU_LIST);
    return 1;
}

YCMD:bm(playerid, params[], help) = businessmenu;