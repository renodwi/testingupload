stock ShowPlayerEditBusinessDialog(playerid, businessid, edit) 
{
    switch(edit) 
    {
        case EDIT_BUSINESS_LIST:
        {
            new message[3000];
            format(message, sizeof(message), "%sOwner\t"YELLOW"%s\n", message, GetBusinessOwner(businessid));
            format(message, sizeof(message), "%sName\t"LB"%s\n", message, GetBusinessName(businessid));
            format(message, sizeof(message), "%sPrice\t"LG"$%s\n", message, FormatMoney(GetBusinessPrice(businessid)));
            format(message, sizeof(message), "%sLocked\t%s\n", message, GetBusinessLocked(businessid) ?  ""LR"Locked" : ""LG"Unlocked");
            format(message, sizeof(message), "%sType\t"YELLOW"%s\n", message, BusinessTypeName[GetBusinessType(businessid)]);
            format(message, sizeof(message), "%sMoney\t"LG"$%s\n", message, FormatMoney(GetBusinessMoney(businessid)));
            format(message, sizeof(message), "%sRadio\t"PURPLE"%s\n", message, GetBusinessRadio(businessid));
            format(message, sizeof(message), "%s"WHITE"Edit Business Exterior Position\t \n", message);
            format(message, sizeof(message), "%s"WHITE"Edit Business Interior Position\t \n", message);
            format(message, sizeof(message), "%s"WHITE"Log Bisnis\t \n", message);
            format(message, sizeof(message), "%s"WHITE"Buypoint Bisnis\t \n", message);
            if(IsBusinessHaveGasPump(businessid))
            {
                format(message, sizeof(message), "%s"WHITE"Fuel\t"YELLOW"%.2f Liter\n", message, businessInfo[businessid][businessFuelAmount]);
                format(message, sizeof(message), "%s"WHITE"Fuel Price\t"LG"$%s", message, FormatMoney(businessInfo[businessid][businessFuelPrice]));
            }
            Dialog_Show(playerid, BusinessEdit_List, DIALOG_STYLE_TABLIST, va_return("Edit Businessid %d", businessid), message, "Pilih", "Tutup");
        }
        case EDIT_BUSINESS_OWNER:
        {
            new message[3000];
            format(message, sizeof(message), "Masukkan nama (atau playerid) pemilik bisnis untuk digantikan. Pemilik bisnis saat ini: %s\n\n(Masukkan input -1 untuk menghapus kepemilikan bisnis)", GetBusinessOwner(businessid));
            Dialog_Show(playerid, BusinessEdit_Owner, DIALOG_STYLE_INPUT, va_return("Edit Businessid %d > Owner", businessid), message, "Ubah", "Kembali");
        }
        case EDIT_BUSINESS_NAME:
        {
            new message[3000];
            format(message, sizeof(message), "Masukkan nama bisnis untuk digantikan. Nama bisnis saat ini: %s", GetBusinessName(businessid));
            Dialog_Show(playerid, BusinessEdit_Name, DIALOG_STYLE_INPUT, va_return("Edit Businessid %d > Name", businessid), message, "Ubah", "Kembali");
        }
        case EDIT_BUSINESS_PRICE:
        {
            new message[3000];
            format(message, sizeof(message), "Masukkan harga bisnis untuk digantikan. Harga bisnis saat ini: $%s", FormatMoney(GetBusinessPrice(businessid)));
            Dialog_Show(playerid, Businessedit_Price, DIALOG_STYLE_INPUT, va_return("Edit Businessid %d > Price", businessid), message, "Ubah", "Kembali");
        }
        case EDIT_BUSINESS_LOCKED:
        {
            if(GetBusinessLocked(businessid)) SetBusinessLocked(businessid, false), SendClientMessageEx(playerid, COLOR_REN, "BUSINESS: "WHITE"Business "LG"Unlocked");
            else SetBusinessLocked(businessid, true), SendClientMessageEx(playerid, COLOR_REN, "BUSINESS: "WHITE"Business "LR"Locked");
        }
        case EDIT_BUSINESS_TYPE:
        {
            new message[3000];
            Loop(i, sizeof(BusinessTypeName))
            {
                format(message, sizeof(message), "%s"WHITE"%s\n", message, BusinessTypeName[i]);
            }
            Dialog_Show(playerid, BusinessEdit_Type, DIALOG_STYLE_LIST, va_return("Edit Businessid %d > Type", businessid), message, "Ubah", "Kembali");
        }
        case EDIT_BUSINESS_MONEY:
        {
            new message[3000];
            format(message, sizeof(message), "Masukkan jumlah uang bisnis untuk digantikan. Jumlah uang bisnis saat ini: $%s", FormatMoney(GetBusinessMoney(businessid)));
            Dialog_Show(playerid, BusinessEdit_Money, DIALOG_STYLE_INPUT, va_return("Edit Businessid %d > Money", businessid), message, "Ubah", "Kembali");
        }
        case EDIT_BUSINESS_RADIO:
        {
            new message[3000];
            format(message, sizeof(message), "Masukkan url radio bisnis untuk digantikan. Url radio bisnis saat ini: %s", GetBusinessRadio(businessid));
            Dialog_Show(playerid, BusinessEdit_Radio, DIALOG_STYLE_INPUT, va_return("Edit Businessid %d > Radio", businessid), message, "Ubah", "Kembali");
        }
        case EDIT_BUSINESS_EXTERIORPOS:
        {
            if(GetPlayerInterior(playerid) > 0)
                return SendErrorMessage(playerid, "Anda harus berada pada interior 0!");
                
            if(GetPlayerVirtualWorld(playerid) > 0)
                return SendErrorMessage(playerid, "Anda harus berada pada virtual world 0!");

            new Float:x, Float:y, Float:z, Float:a;
            GetPlayerPos(playerid, x, y, z);
            GetPlayerFacingAngle(playerid, a);

            SetBusinessExterior(businessid, x, y, z, a);
            SendClientMessageEx(playerid, COLOR_REN, "BUSINESS: "WHITE"Exterior bisnis telah diubah");

            CreateBusinessLog(businessid, "Admin "RED"%s"WHITE" mengubah posisi exterior bisnis", GetAdminName(playerid));
        }
        case EDIT_BUSINESS_INTERIORPOS:
        {
            new Float:x, Float:y, Float:z, Float:a, interiorid;
            GetPlayerPos(playerid, x, y, z);
            GetPlayerFacingAngle(playerid, a);
            interiorid = GetPlayerInterior(playerid);

            SetBusinessInterior(businessid, x, y, z, a);
            SetBusinessInteriorID(businessid, interiorid);
            SendClientMessageEx(playerid, COLOR_REN, "BUSINESS: "WHITE"Interior bisnis telah diubah");

            CreateBusinessLog(businessid, "Admin "RED"%s"WHITE" mengubah posisi exterior bisnis", GetAdminName(playerid));
        }
        case EDIT_BUSINESS_FUEL:
        {
            new message[200];
            format(message, sizeof(message), "Masukkan jumlah bahan bakar bisnis untuk digantikan\nBahan bakar saat ini: %.2f Liter", businessInfo[businessid][businessFuelAmount]);
            Dialog_Show(playerid, BusinessEdit_Fuel, DIALOG_STYLE_INPUT, "Business edit fuel", message, "Ubah", "Kembali");
        }
        case EDIT_BUSINESS_FUELPRICE:
        {
            new message[200];
            format(message, sizeof(message), "Masukkan harga bahan bakar untuk digantikan\nHarga bahan bakar sekarang: $%s", FormatMoney(businessInfo[businessid][businessFuelPrice]));
            Dialog_Show(playerid, BusinessEdit_FuelPrice, DIALOG_STYLE_INPUT, "Business edit fuel price", message, "Ubah", "Kembali");
        }
    }
    player_edit_business[playerid] = businessid;
    return 1;
}

Dialog:BusinessEdit_List(playerid, response, listitem, inputtext[])
{
    new businessid = player_edit_business[playerid];
    if(!response) return 1;
    else 
    {
        switch(listitem) 
        {
            case 0: ShowPlayerEditBusinessDialog(playerid, businessid, EDIT_BUSINESS_OWNER);
            case 1: ShowPlayerEditBusinessDialog(playerid, businessid, EDIT_BUSINESS_NAME);
            case 2: ShowPlayerEditBusinessDialog(playerid, businessid, EDIT_BUSINESS_PRICE);
            case 3: ShowPlayerEditBusinessDialog(playerid, businessid, EDIT_BUSINESS_LOCKED);
            case 4: ShowPlayerEditBusinessDialog(playerid, businessid, EDIT_BUSINESS_TYPE);
            case 5: ShowPlayerEditBusinessDialog(playerid, businessid, EDIT_BUSINESS_MONEY);
            case 6: ShowPlayerEditBusinessDialog(playerid, businessid, EDIT_BUSINESS_RADIO);
            case 7: ShowPlayerEditBusinessDialog(playerid, businessid, EDIT_BUSINESS_EXTERIORPOS);
            case 8: ShowPlayerEditBusinessDialog(playerid, businessid, EDIT_BUSINESS_INTERIORPOS);
            case 9: ShowPlayerBusinessLog(playerid, businessid);
            case 10: ShowPlayerBusinessBuypoint(playerid, businessid);
            case 11: ShowPlayerEditBusinessDialog(playerid, businessid, EDIT_BUSINESS_FUEL);
            case 12: ShowPlayerEditBusinessDialog(playerid, businessid, EDIT_BUSINESS_FUELPRICE);
        }
    }
    return 1;
}

Dialog:BusinessEdit_Owner(playerid, response, listitem, inputtext[])
{
    new businessid = player_edit_business[playerid];
    if(!response) return ShowPlayerEditBusinessDialog(playerid, businessid, EDIT_BUSINESS_LIST);
    else 
    {
        if(isnull(inputtext)) return 1;
        else 
        {
            if(!strcmp(inputtext, "-1", true)) 
            {
                SendClientMessageEx(playerid, COLOR_REN, "BUSINESS: "WHITE"Anda telah menghapus kepemilikan bisnis");
                SetBusinessOwner(businessid, "Unknown");
                
                CreateBusinessLog(businessid, ""WHITE"Admin "RED"%s"WHITE" telah menghapus kepemilikan bisnis", GetAdminName(playerid));
            }
            else
            {
                new owner_id;
                if(sscanf(inputtext, "u", owner_id))
                    return SendErrorMessage(playerid, "Masukkan nama atau playerid dari pemilik bisnis!"), ShowPlayerEditBusinessDialog(playerid, businessid, EDIT_BUSINESS_OWNER);

                if(!IsPlayerSpawned(owner_id))
                    return SendErrorMessage(playerid, "Nama atau id pemilik bisnis tidak terdeteksi!"), ShowPlayerEditBusinessDialog(playerid, businessid, EDIT_BUSINESS_OWNER);

                SendClientMessageEx(playerid, COLOR_REN, "BUSINESS: "WHITE"Anda mengubah kepemilikan bisnis dari "YELLOW"%s"WHITE" menjadi "LG"%s", GetBusinessOwner(businessid), RemoveUnderscore(playerInfo[owner_id][playerName]));
                SetBusinessOwner(businessid, playerInfo[owner_id][playerName]);

                CreateBusinessLog(businessid, ""WHITE"Admin "RED"%s"WHITE" mengubah kepemilikan bisnis dari "YELLOW"%s"WHITE" menjadi "LG"%s", GetAdminName(playerid), GetBusinessOwner(businessid), RemoveUnderscore(playerInfo[owner_id][playerName]));
            }
        }
    }
    return 1;
}

Dialog:BusinessEdit_Name(playerid, response, listitem, inputtext[])
{
    new businessid = player_edit_business[playerid];
    if(!response) return ShowPlayerEditBusinessDialog(playerid, businessid, EDIT_BUSINESS_LIST);
    else 
    {
        if(isnull(inputtext)) return 1;
        else 
        {
            new name[999];
            if(sscanf(inputtext, "s[999]", name))
                return SendErrorMessage(playerid, "Masukkan nama bisnis!"), ShowPlayerEditBusinessDialog(playerid, businessid, EDIT_BUSINESS_NAME);

            SendClientMessageEx(playerid, COLOR_REN, "BUSINESS: "WHITE"Anda mengubah nama bisnis dari "YELLOW"%s"WHITE" menjadi "LG"%s", GetBusinessName(businessid), inputtext);
            SetBusinessName(businessid, inputtext);

            CreateBusinessLog(businessid, ""WHITE"Admin "RED"%s"WHITE" mengubah nama bisnis dari "YELLOW"%s"WHITE" menjadi "LG"%s", GetAdminName(playerid), GetBusinessName(businessid), inputtext);
        }
    }
    return 1;
}

Dialog:Businessedit_Price(playerid, response, listitem, inputtext[])
{
    new businessid = player_edit_business[playerid];
    if(!response) return ShowPlayerEditBusinessDialog(playerid, businessid, EDIT_BUSINESS_LIST);
    else 
    {
        if(isnull(inputtext)) return 1;
        else 
        {
            if(!IsMoneyFormat(inputtext))
                return SendErrorMessage(playerid, "Masukkan input dengan format uang!"), ShowPlayerEditBusinessDialog(playerid, businessid, EDIT_BUSINESS_PRICE);

            SendClientMessageEx(playerid, COLOR_REN, "BUSINESS: "WHITE"Anda mengubah harga bisnis dari "LB"$%s"WHITE" menjadi "LG"$%s", FormatMoney(GetBusinessPrice(businessid)), FormatMoney(StringToMoney(inputtext)));

            SetBusinessPrice(businessid, StringToMoney(inputtext));

            CreateBusinessLog(businessid, ""WHITE"Admin "RED"%s"WHITE" mengubah harga bisnis dari "YELLOW"$%s"WHITE" menjadi "LG"$%s", GetAdminName(playerid), FormatMoney(GetBusinessPrice(businessid)), FormatMoney(StringToMoney(inputtext)));
        }
    }
    return 1;
}

Dialog:BusinessEdit_Type(playerid, response, listitem, inputtext[])
{
    new businessid = player_edit_business[playerid];
    if(!response) return ShowPlayerEditBusinessDialog(playerid, businessid, EDIT_BUSINESS_LIST);
    else 
    {
        SendClientMessageEx(playerid, COLOR_REN, "BUSINESS: "WHITE"Anda mengubah tipe bisnis dari "LB"%s"WHITE" menjadi "LG"%s", BusinessTypeName[GetBusinessType(businessid)], BusinessTypeName[listitem]);
        SetBusinessType(businessid, listitem);

        CreateBusinessLog(businessid, ""WHITE"Admin "RED"%s"WHITE" mengubah tipe bisnis dari "LB"%s"WHITE" menjadi "LG"%s", GetAdminName(playerid), BusinessTypeName[GetBusinessType(businessid)], BusinessTypeName[listitem]);
    }
    return 1;
}

Dialog:BusinessEdit_Money(playerid, response, listitem, inputtext[])
{
    new businessid = player_edit_business[playerid];
    if(!response) return ShowPlayerEditBusinessDialog(playerid, businessid, EDIT_BUSINESS_LIST);
    else 
    {
        if(isnull(inputtext)) return 1;
        else 
        {
            if(!IsMoneyFormat(inputtext))
                return SendErrorMessage(playerid, "Masukkan input dengan format uang!"), ShowPlayerEditBusinessDialog(playerid, businessid, EDIT_BUSINESS_MONEY);

            if(StringToMoney(inputtext) < 0)
                return SendErrorMessage(playerid, "Minimal uang bisnis tidak dapat kurang dari $0!"), ShowPlayerEditBusinessDialog(playerid, businessid, EDIT_BUSINESS_MONEY);
            SendClientMessageEx(playerid, COLOR_REN, "BUSINESS: "WHITE"Anda mengubah uang bisnis dari "LB"$%s"WHITE" menjadi "LG"$%s", FormatMoney(GetBusinessMoney(businessid)), FormatMoney(StringToMoney(inputtext)));

            SetBusinessMoney(businessid, StringToMoney(inputtext));

            CreateBusinessLog(businessid, ""WHITE"Admin "RED"%s"WHITE" mengubah uang bisnis dari "LB"$%s"WHITE" menjadi "LG"$%s", GetAdminName(playerid), FormatMoney(GetBusinessMoney(businessid)), FormatMoney(StringToMoney(inputtext)));
        }
    }
    return 1;
}

Dialog:BusinessEdit_Radio(playerid, response, listitem, inputtext[])
{
    new businessid = player_edit_business[playerid];
    if(!response) return ShowPlayerEditBusinessDialog(playerid, businessid, EDIT_BUSINESS_LIST);
    else 
    {
        if(isnull(inputtext)) return 1;
        else 
        {
            SendClientMessageEx(playerid, COLOR_REN, "BUSINESS: "WHITE"Anda mengubah url radio bisnis dari "PURPLE"%s"WHITE" menjadi "LG"%s", GetBusinessRadio(businessid), inputtext);
            SetBusinessRadio(businessid, inputtext);

            CreateBusinessLog(businessid, ""WHITE"Admin "RED"%s"WHITE" mengubah url radio bisnis dari "PURPLE"%s"WHITE" menjadi "LG"%s", GetAdminName(playerid), GetBusinessRadio(businessid), inputtext);
        }
    }
    return 1;
}

// --------------------------------------------------------------------------
// Normal Players
// --------------------------------------------------------------------------
Dialog:BusinessBuy_Confirm(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    else 
    {
        new businessid = player_buybusiness_id[playerid];
        GivePlayerMoney(playerid, -GetBusinessPrice(businessid));
        SendClientMessageEx(playerid, COLOR_REN, "BUSINESS: "WHITE"Anda telah membeli "YELLOW"bisnis %d"WHITE" dengan harga "LG"$%s", businessid, FormatMoney(GetBusinessPrice(businessid)));

        SetBusinessOwner(businessid, playerInfo[playerid][playerName]);
        CreateBusinessLog(businessid, "Bisnis telah dibeli oleh "YELLOW"%s"WHITE" dengan harga "LG"$%s", RemoveUnderscore(playerInfo[playerid][playerName]), FormatMoney(GetBusinessPrice(businessid)));
    }
    return 1;
}


stock ShowPlayerBusinessMenu(playerid, businessid, menu) 
{
    switch(menu) 
    {
        case BUSINESS_MENU_LIST:
        {
            new message[3000];
            format(message, sizeof(message), "%s"WHITE"Nama Bisnis\t"YELLOW"%s\n", message, GetBusinessName(businessid));
            format(message, sizeof(message), "%s"WHITE"Lock\t%s\n", message, GetBusinessLocked(businessid) ? ""LR"Locked" : ""LG"Unlocked");
            format(message, sizeof(message), "%s"WHITE"Uang\t"LG"$%s\n", message, FormatMoney(GetBusinessMoney(businessid)));
            format(message, sizeof(message), "%s"WHITE"Radio URL\t"PURPLE"%s\n", message, GetBusinessRadio(businessid));
            format(message, sizeof(message), "%s"WHITE"Log Bisnis\t ", message);
            Dialog_Show(playerid, BusinessMenu_List, DIALOG_STYLE_TABLIST, "Menu Bisnis", message, "Pilih", "Tutup");
        }
        case BUSINESS_MENU_NAME:
        {
            new message[3000];
            format(message, sizeof(message), "Masukkan nama bisnis untuk digantikan. Nama bisnis saat ini: %s", GetBusinessName(businessid));
            Dialog_Show(playerid, BusinessMenu_Name, DIALOG_STYLE_INPUT, "Menu Bisnis > Nama", message, "Ubah", "Kembali");
        }
        case BUSINESS_MENU_LOCKED:
        {
            if(GetBusinessLocked(businessid)) SetBusinessLocked(businessid, false), SendClientMessageEx(playerid, COLOR_REN, "BUSINESS: "WHITE"Business "LG"Unlocked");
            else SetBusinessLocked(businessid, true), SendClientMessageEx(playerid, COLOR_REN, "BUSINESS: "WHITE"Business "LR"Locked");
        }
        case BUSINESS_MENU_MONEY:
        {
            Dialog_Show(playerid, BusinessMenu_Money, DIALOG_STYLE_LIST, "Menu Bisnis > Uang", "Withdraw\nDeposit", "Ubah", "Kembali");
        }
        case BUSINESS_MENU_RADIO:
        {
            new message[3000];
            format(message, sizeof(message), "Masukkan url radio bisnis untuk digantikan. URL Radio bisnis saat ini: %s", GetBusinessRadio(businessid));
            Dialog_Show(playerid, BusinessMenu_Radio, DIALOG_STYLE_INPUT, "Menu Bisnis > Radio", message, "Ubah", "Kembali");
        }
    }
    player_businessmenu_id[playerid] = businessid;
    return 1;
}

Dialog:BusinessMenu_List(playerid, response, listitem, inputtext[]) 
{
    new businessid = player_businessmenu_id[playerid];
    if(!response) return 1;
    else 
    {
        switch(listitem) 
        {
            case 0: ShowPlayerBusinessMenu(playerid, businessid, BUSINESS_MENU_NAME);
            case 1: ShowPlayerBusinessMenu(playerid, businessid, BUSINESS_MENU_LOCKED);
            case 2: ShowPlayerBusinessMenu(playerid, businessid, BUSINESS_MENU_MONEY);
            case 3: ShowPlayerBusinessMenu(playerid, businessid, BUSINESS_MENU_RADIO);
            case 4: ShowPlayerBusinessLog(playerid, businessid);
        }
    }
    return 1;
}
Dialog:BusinessMenu_Name(playerid, response, listitem, inputtext[]) 
{
    new businessid = player_businessmenu_id[playerid];
    if(!response) return ShowPlayerBusinessMenu(playerid, businessid, BUSINESS_MENU_LIST);
    else 
    {
        if(isnull(inputtext)) return 1;
        else 
        {
            new name[999];
            if(sscanf(inputtext, "s[999]", name))
                return SendErrorMessage(playerid, "Masukkan nama bisnis!"), ShowPlayerBusinessMenu(playerid, businessid, BUSINESS_MENU_NAME);

            SendClientMessageEx(playerid, COLOR_REN, "BUSINESS: "WHITE"Anda mengubah nama bisnis dari "YELLOW"%s"WHITE" menjadi "LG"%s", GetBusinessName(businessid), inputtext);

            SetBusinessName(businessid, inputtext);

            CreateBusinessLog(businessid, ""LIME"%s"WHITE" Telah mengubah nama bisnis telah diubah dari "YELLOW"%s"WHITE" menjadi "LG"%s", RemoveUnderscore(playerInfo[playerid][playerName]), GetBusinessName(businessid), inputtext);
        }
    }
    return 1;
}
Dialog:BusinessMenu_Money(playerid, response, listitem, inputtext[]) 
{
    new businessid = player_businessmenu_id[playerid];
    if(!response) return ShowPlayerBusinessMenu(playerid, businessid, BUSINESS_MENU_LIST);
    else 
    {
        if(listitem == 0) Dialog_Show(playerid, BusinessMenu_MoneyWD, DIALOG_STYLE_INPUT, "Menu Bisnis > Withdraw", va_return("Massukan jumlah uang yang akan ditarik dari bisnis. Jumlah uang pada bisnis saat ini: $%s", FormatMoney(GetBusinessMoney(businessid))), "Tarik", "Kembali");
        if(listitem == 1) Dialog_Show(playerid, BusinessMenu_MoneyDP, DIALOG_STYLE_INPUT, "Menu Bisnis > Deposit", va_return("Massukan jumlah uang yang akan ditambahkan ke bisnis. Jumlah uang pada bisnis saat ini: $%s", FormatMoney(GetBusinessMoney(businessid))), "Deposit", "Kembali");
    }
    return 1;
}
Dialog:BusinessMenu_MoneyWD(playerid, response, listitem, inputtext[])
{
    new businessid = player_businessmenu_id[playerid];
    if(!response) return ShowPlayerBusinessMenu(playerid, businessid, BUSINESS_MENU_MONEY);
    else 
    {
        if(isnull(inputtext)) return 1;
        else 
        {
            if(!IsMoneyFormat(inputtext))
                return SendErrorMessage(playerid, "Masukkan input dengan format uang!"), Dialog_Show(playerid, BusinessMenu_MoneyWD, DIALOG_STYLE_INPUT, "Menu Bisnis > Withdraw", va_return("Massukan jumlah uang yang akan ditarik dari bisnis. Jumlah uang pada bisnis saat ini: $%s", FormatMoney(GetBusinessMoney(businessid))), "Tarik", "Kembali");

            if(GetBusinessMoney(businessid) < StringToMoney(inputtext))
                return SendErrorMessage(playerid, "Bisnis anda tidak memiliki uang sebanyak itu"), Dialog_Show(playerid, BusinessMenu_MoneyWD, DIALOG_STYLE_INPUT, "Menu Bisnis > Withdraw", va_return("Massukan jumlah uang yang akan ditarik dari bisnis. Jumlah uang pada bisnis saat ini: $%s", FormatMoney(GetBusinessMoney(businessid))), "Tarik", "Kembali");

            if(StringToMoney(inputtext) < 1)
                return SendErrorMessage(playerid, "Anda hanya dapat mengamil uang dengan minimal $1"), Dialog_Show(playerid, BusinessMenu_MoneyWD, DIALOG_STYLE_INPUT, "Menu Bisnis > Withdraw", va_return("Massukan jumlah uang yang akan ditarik dari bisnis. Jumlah uang pada bisnis saat ini: $%s", FormatMoney(GetBusinessMoney(businessid))), "Tarik", "Kembali");
                
            SendClientMessageEx(playerid, COLOR_REN, "BUSINESS: "WHITE"Anda menarik uang dari bisnis sebesar "LG"$%s", FormatMoney(StringToMoney(inputtext)));
            SetBusinessMoney(businessid, GetBusinessMoney(businessid) - StringToMoney(inputtext));

            GivePlayerMoney(playerid, StringToMoney(inputtext));
            CreateBusinessLog(businessid, ""LIME"%s"WHITE" Telah menarik uang dari bisnis sebesar "LG"$%s", RemoveUnderscore(playerInfo[playerid][playerName]), FormatMoney(StringToMoney(inputtext)));
        }
    }
    return 1;
}
Dialog:BusinessMenu_MoneyDP(playerid, response, listitem, inputtext[])
{
    new businessid = player_businessmenu_id[playerid];
    if(!response) return ShowPlayerBusinessMenu(playerid, businessid, BUSINESS_MENU_MONEY);
    else 
    {
        if(isnull(inputtext)) return 1;
        else 
        {
            if(!IsMoneyFormat(inputtext))
                return SendErrorMessage(playerid, "Masukkan input dengan format uang!"), Dialog_Show(playerid, BusinessMenu_MoneyDP, DIALOG_STYLE_INPUT, "Menu Bisnis > Deposit", va_return("Massukan jumlah uang yang akan ditambahkan ke bisnis. Jumlah uang pada bisnis saat ini: $%s", FormatMoney(GetBusinessMoney(businessid))), "Deposit", "Kembali");

            if(GetPlayerMoney(playerid) < StringToMoney(inputtext))
                return SendErrorMessage(playerid, "Anda tidak memiliki uang sebanyak itu!"), Dialog_Show(playerid, BusinessMenu_MoneyDP, DIALOG_STYLE_INPUT, "Menu Bisnis > Deposit", va_return("Massukan jumlah uang yang akan ditambahkan ke bisnis. Jumlah uang pada bisnis saat ini: $%s", FormatMoney(GetBusinessMoney(businessid))), "Deposit", "Kembali");
                
            SendClientMessageEx(playerid, COLOR_REN, "BUSINESS: "WHITE"Anda menambahkan uang kedalam bisnis sebesar "LG"$%s", FormatMoney(StringToMoney(inputtext)));
            SetBusinessMoney(businessid, GetBusinessMoney(businessid) + StringToMoney(inputtext));

            GivePlayerMoney(playerid, -StringToMoney(inputtext));
            CreateBusinessLog(businessid, ""LIME"%s"WHITE" Telah menambahkan uang kedalam bisnis sebesar "LG"$%s", RemoveUnderscore(playerInfo[playerid][playerName]), FormatMoney(StringToMoney(inputtext)));
        }
    }
    return 1;
}
Dialog:BusinessMenu_Radio(playerid, response, listitem, inputtext[]) 
{
    new businessid = player_businessmenu_id[playerid];
    if(!response) return ShowPlayerBusinessMenu(playerid, businessid, BUSINESS_MENU_LIST);
    else 
    {
        if(isnull(inputtext)) return 1;
        else 
        {
            SendClientMessageEx(playerid, COLOR_REN, "BUSINESS: "WHITE"Anda mengubah url radio bisnis dari "PURPLE"%s"WHITE" menjadi "LG"%s", GetBusinessRadio(businessid), inputtext);
            SetBusinessRadio(businessid, inputtext);

            CreateBusinessLog(businessid, ""LIME"%s"WHITE" Telah mengubah url radio bisnis dari "PURPLE"%s"WHITE" menjadi "LG"%s", RemoveUnderscore(playerInfo[playerid][playerName]), GetBusinessRadio(businessid), inputtext);
        }
    }
    return 1;
}

Dialog:BusinessEdit_Fuel(playerid, response, listitem, inputtext[]) 
{
    new businessid = player_businessmenu_id[playerid];
    if(!response) return ShowPlayerBusinessMenu(playerid, businessid, BUSINESS_MENU_LIST);
    else 
    {
        new Float:fuel;
        if(sscanf(inputtext, "f", fuel))
            return ShowPlayerBusinessMenu(playerid, businessid, EDIT_BUSINESS_FUEL), SendErrorMessage(playerid, "Masukkan input dengan tipe float!");

        if(fuel < 0.0)
            return SendErrorMessage(playerid, "Jumlah bahan bakar tidak dapat kurang dari 0!"), ShowPlayerBusinessMenu(playerid, businessid, EDIT_BUSINESS_FUEL);

        if(fuel > 10000.0)
            return SendErrorMessage(playerid, "Jumlah maksimal bahan bakar yang dapat dimiliki oleh bisnis hanya 10000.0 Liter saja!"), ShowPlayerBusinessMenu(playerid, businessid, EDIT_BUSINESS_FUEL);

        SendClientMessageEx(playerid, COLOR_REN, "BUSINESS: "WHITE"Anda mengubah jumlah bahan bakar "YELLOW"bisnis %d"WHITE" dari "LB"%.2f Liter"WHITE" menjadi "LG"%.2f Liter", businessid, businessInfo[businessid][businessFuelAmount], fuel);

        businessInfo[businessid][businessFuelAmount] = fuel;
        UpdateBusinessData(businessid);
    }
    return 1;
}

Dialog:BusinessEdit_FuelPrice(playerid, response, listitem, inputtext[]) 
{
    new businessid = player_businessmenu_id[playerid];
    if(!response) return ShowPlayerBusinessMenu(playerid, businessid, BUSINESS_MENU_LIST);
    else 
    {
        new price;
        if(!IsMoneyFormat(inputtext))
            return SendErrorMessage(playerid, "Masukkan input dengan format uang!"), ShowPlayerBusinessMenu(playerid, businessid, EDIT_BUSINESS_FUELPRICE);

        price = StringToMoney(inputtext);

        businessInfo[businessid][businessFuelPrice] = price;
        UpdateBusinessData(businessid);

        SendClientMessageEx(playerid, COLOR_REN, "BUSINESS: "WHITE"Anda telah mengubah harga bahan bakar pada "YELLOW"bisnis %d"WHITE" menjadi "LG"$%s", businessid, FormatMoney(price));
    }
    return 1;
}