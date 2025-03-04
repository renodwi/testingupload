stock ShowPlayerEditDealership(playerid, dealershipid, show) 
{
    switch(show)
    {
        case DEALERSHIP_EDIT_LIST:
        {
            new message[3000];
            format(message, sizeof(message), "%sData\tValue\n", message);
            format(message, sizeof(message), "%s"WHITE"Owner\t"LG"%s\n", message, dealershipInfo[dealershipid][dealershipOwner]);
            format(message, sizeof(message), "%s"WHITE"Name\t"YELLOW"%s\n", message, dealershipInfo[dealershipid][dealershipName]);
            format(message, sizeof(message), "%s"WHITE"Money\t"LG"$%s\n", message, FormatMoney(dealershipInfo[dealershipid][dealershipMoney]));
            format(message, sizeof(message), "%s"WHITE"Price\t"LB"$%s\n", message, FormatMoney(dealershipInfo[dealershipid][dealershipPrice]));
            format(message, sizeof(message), "%s"WHITE"Lock\t%s\n", message, dealershipInfo[dealershipid][dealershipLocked] ? ""LG"Unlocked" : ""LR"Locked");
            format(message, sizeof(message), "%s"WHITE"Edit Position\t\n", message);
            format(message, sizeof(message), "%s"WHITE"Vehicle Spawn Position\t\n", message);
            format(message, sizeof(message), "%s"WHITE"Edit Vehicle Model\t\n", message);
            format(message, sizeof(message), "%s"WHITE"Vehicle Model Position\t\n", message);
            format(message, sizeof(message), "%s"LR"Delete\t\n", message);
            Dialog_Show(playerid, Dealership_EditList, DIALOG_STYLE_TABLIST_HEADERS, "Dealership > Edit", message, "Pilih", "Tutup");
        }
        case DEALERSHIP_EDIT_OWNER:
        {
            Dialog_Show(playerid, Dealership_EditOwner, DIALOG_STYLE_INPUT, "Dealership > Edit > Owner", ""WHITE"Masukkan nama / id player untuk mengubah kepemilikan deler kendaraan\nPemilik saat ini: "LB"%s", "Ganti", "Kembali", dealershipInfo[dealershipid][dealershipOwner]);
        }
        case DEALERSHIP_EDIT_NAME:
        {
            Dialog_Show(playerid, Dealership_EditName, DIALOG_STYLE_INPUT, "Dealership > Edit > Name", ""WHITE"Masukan nama deler untuk digantikan\nNama saat ini: "YELLOW"%s", "Ganti", "Kembali", dealershipInfo[dealershipid][dealershipName]);
        }
        case DEALERSHIP_EDIT_MONEY:
        {
            Dialog_Show(playerid, Dealership_EditMoney, DIALOG_STYLE_INPUT, "Dealership > Edit > Money", ""WHITE"Masukkan jumlah uang untuk menggantikan jumlah uang deler kendaraan\nJumlah uang saat ini: "LG"$%s", "Ganti", "Kembali", FormatMoney(dealershipInfo[dealershipid][dealershipMoney]));
        }
        case DEALERSHIP_EDIT_PRICE:
        {
            Dialog_Show(playerid, Dealership_EditPrice, DIALOG_STYLE_INPUT, "Dealership > Edit > Price", ""WHITE"Masukkan harga deler kendaraan untuk digantikan\nHarga saat ini: "LG"$%s", "Ganti", "Kembali", FormatMoney(dealershipInfo[dealershipid][dealershipPrice]));
        }
        case DEALERSHIP_EDIT_LOCKED:
        {
            if(dealershipInfo[dealershipid][dealershipLocked] == true)
            {
                dealershipInfo[dealershipid][dealershipLocked] = false;
            }
            else
            {
                dealershipInfo[dealershipid][dealershipLocked] = true;
            }
            ShowPlayerEditDealership(playerid, dealershipid, DEALERSHIP_EDIT_LIST);
        }
        case DEALERSHIP_EDIT_POSITION:
        {
            player_editdealer_position[playerid] = true;
            SendClientMessageEx(playerid, COLOR_REN, "DEALERSHIP: "WHITE"Anda memasuki mode untuk mengubah lokasi deler kendaraan");
            SendClientMessageEx(playerid, COLOR_REN, "DEALERSHIP: "WHITE"Gunakan command "YELLOW"/dealership"WHITE" untuk menentukan lokasi deler kendaraan!");
        }
        case DEALERSHIP_EDIT_SPAWNPOSITION:
        {
            player_editdealer_vehposition[playerid] = true;
            SendClientMessageEx(playerid, COLOR_REN, "DEALERSHIP: "WHITE"Anda memasuki mode untuk mengubah lokasi spawn kendaraan");
            SendClientMessageEx(playerid, COLOR_REN, "DEALERSHIP: "WHITE"Gunakan command "YELLOW"/dealership"WHITE" untuk menentukan lokasi spawn kendaraan!");
        }
        case DEALERSHIP_EDIT_VEHICLEMODEL:
        {
            new message[1000];
            format(message, sizeof(message), "%s"LR"Klik sesuai list untuk mengubah tipe kendaraan!\n", message);
            Loop(i, MAX_DEALERSHIP_VEHICLEMODEL)
            {
                if(dealershipInfo[dealershipid][dealershipVehicleModel][i] < 400)
                {
                    format(message, sizeof(message), "%s"WHITE"(kosong)\n", message);
                }
                else
                {
                    format(message, sizeof(message), "%s"WHITE"(Modelid: %d) "YELLOW"%s\n", message, dealershipInfo[dealershipid][dealershipVehicleModel][i], GetVehicleModelName(dealershipInfo[dealershipid][dealershipVehicleModel][i]));
                }
            }
            Dialog_Show(playerid, Dealership_EditVehicleModel, DIALOG_STYLE_TABLIST_HEADERS, "Dealership > Edit > Vehicle Model", message, "Pilih", "Kembali");
        }
        case DEALERSHIP_EDIT_DELETE:
        {
            Dialog_Show(playerid, Dealership_EditDelete, DIALOG_STYLE_MSGBOX, "Dealership > Edit > Delete", ""WHITE"Konfirmasi bahwa anda akan menghapus "LR"deler kendaraan %d"WHITE"?", "Ya", "Kembali", dealershipid);
        }
    }

    player_editdealer_id[playerid] = dealershipid;
    return 1;
}

Dialog:Dealership_EditList(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    else
    {
        new dealershipid = player_editdealer_id[playerid];
        switch(listitem) 
        {
            case 0: ShowPlayerEditDealership(playerid, dealershipid, DEALERSHIP_EDIT_OWNER);
            case 1: ShowPlayerEditDealership(playerid, dealershipid, DEALERSHIP_EDIT_NAME);
            case 2: ShowPlayerEditDealership(playerid, dealershipid, DEALERSHIP_EDIT_MONEY);
            case 3: ShowPlayerEditDealership(playerid, dealershipid, DEALERSHIP_EDIT_PRICE);
            case 4: ShowPlayerEditDealership(playerid, dealershipid, DEALERSHIP_EDIT_LOCKED);
            case 5: ShowPlayerEditDealership(playerid, dealershipid, DEALERSHIP_EDIT_POSITION);
            case 6: ShowPlayerEditDealership(playerid, dealershipid, DEALERSHIP_EDIT_SPAWNPOSITION);
            case 7: ShowPlayerEditDealership(playerid, dealershipid, DEALERSHIP_EDIT_VEHICLEMODEL);
            case 8: ShowPlayerDealershipVehPos(playerid, dealershipid, DEALERSHIP_VEHPOS_EDITLIST);
            case 9: ShowPlayerEditDealership(playerid, dealershipid, DEALERSHIP_EDIT_DELETE);
        }

    }
    return 1;
}

Dialog:Dealership_EditOwner(playerid, response, listitem, inputtext[])
{
    new dealershipid = player_editdealer_id[playerid];
    if(!response) return ShowPlayerEditDealership(playerid, dealershipid, DEALERSHIP_EDIT_LIST);
    else
    {
        new toplayer;
        if(sscanf(inputtext, "u", toplayer) || !IsPlayerSpawned(toplayer))
            return SendErrorMessage(playerid, "Player tujuan tidak terdeteksi"), ShowPlayerEditDealership(playerid, dealershipid, DEALERSHIP_EDIT_OWNER);
        
        SendClientMessageEx(playerid, COLOR_REN, "DEALERSHIP: "WHITE"Anda telah mengubah kepemilikan deler kendaraan dari "YELLOW"%s"WHITE" menjadi "LG"%s", RemoveUnderscore(dealershipInfo[dealershipid][dealershipOwner]), RemoveUnderscore(playerInfo[toplayer][playerName]));
        format(dealershipInfo[dealershipid][dealershipOwner], MAX_PLAYER_NAME, playerInfo[toplayer][playerName]);
        RefreshDealership(dealershipid);
    }
    return 1;
}

Dialog:Dealership_EditName(playerid, response, listitem, inputtext[])
{
    new dealershipid = player_editdealer_id[playerid];
    if(!response) return ShowPlayerEditDealership(playerid, dealershipid, DEALERSHIP_EDIT_LIST);
    else
    {
        SendClientMessageEx(playerid, COLOR_REN, "DEALERSHIP: "WHITE"Anda telah mengubah nama deler kendaraan dari "YELLOW"%s"WHITE" menjadi "LG"%s", dealershipInfo[dealershipid][dealershipName], inputtext);
        format(dealershipInfo[dealershipid][dealershipName], MAX_DEALERSHIP_NAME, inputtext);
        RefreshDealership(dealershipid);
    }
    return 1;
}

Dialog:Dealership_EditMoney(playerid, response, listitem, inputtext[])
{
    new dealershipid = player_editdealer_id[playerid];
    if(!response) return ShowPlayerEditDealership(playerid, dealershipid, DEALERSHIP_EDIT_LIST);
    else
    {
        if(!IsMoneyFormat(inputtext))
            return SendErrorMessage(playerid, "Input hanya menerima format uang saja!"), ShowPlayerEditDealership(playerid, dealershipid, DEALERSHIP_EDIT_MONEY);

        SendClientMessageEx(playerid, COLOR_REN, "DEALERSHIP: "WHITE"Anda telah mengubah uang deler kendaraan dari "YELLOW"$%s"WHITE" menjadi "LG"$%s", FormatMoney(dealershipInfo[dealershipid][dealershipMoney]), FormatMoney(StringToMoney(inputtext)));
        dealershipInfo[dealershipid][dealershipMoney] = StringToMoney(inputtext);

        UpdateDealershipData(dealershipid);
    }
    return 1;
}

Dialog:Dealership_EditPrice(playerid, response, listitem, inputtext[])
{
    new dealershipid = player_editdealer_id[playerid];
    if(!response) return ShowPlayerEditDealership(playerid, dealershipid, DEALERSHIP_EDIT_LIST);
    else
    {
        if(!IsMoneyFormat(inputtext))
            return SendErrorMessage(playerid, "Input hanya menerima format uang saja!"), ShowPlayerEditDealership(playerid, dealershipid, DEALERSHIP_EDIT_PRICE);

        SendClientMessageEx(playerid, COLOR_REN, "DEALERSHIP: "WHITE"Anda telah mengubah harga deler kendaraan dari "YELLOW"$%s"WHITE" menjadi "LG"$%s", FormatMoney(dealershipInfo[dealershipid][dealershipPrice]), FormatMoney(StringToMoney(inputtext)));
        dealershipInfo[dealershipid][dealershipPrice] = StringToMoney(inputtext);

        RefreshDealership(dealershipid);
    }
    return 1;
}

Dialog:Dealership_EditDelete(playerid, response, listitem, inputtext[])
{
    new dealershipid = player_editdealer_id[playerid];
    if(!response) return ShowPlayerEditDealership(playerid, dealershipid, DEALERSHIP_EDIT_LIST);
    else
    {
        SendClientMessageEx(playerid, COLOR_REN, "DEALERSHIP: "WHITE"Anda telah menghapus "LR"deler kendaraan %d", dealershipid);
        DeleteDealership(dealershipid);
    }
    return 1;
}

Dialog:Dealership_EditVehicleModel(playerid, response, listitem, inputtext[])
{
    new dealershipid = player_editdealer_id[playerid];
    if(!response) return ShowPlayerEditDealership(playerid, dealershipid, DEALERSHIP_EDIT_LIST);
    else
    {
        player_editdealer_vmodelslot[playerid] = listitem;
        new desc[100], color1, color2, slot;
        AddPlayerSelectionItem(playerid, 1239, "Remove Model", "Jika ingin menghilangkan model kendaraan (clear) pilih ini!");
        Loop(i, MAX_VEHICLE_MODELS)
        {
            format(desc, sizeof(desc), "Harga Awal (( oleh server )): $%s", FormatMoney(GetVehicleModelPrice(i + 400)));
            slot = AddPlayerSelectionItem(playerid, i + 400, GetVehicleModelName(i + 400), desc);
            GetVehicleRandomColors(i + 400, color1, color2);
            SetPlayerSelectionVehColor(playerid, slot, color1, color2);
        }
        ShowPlayerSelection(playerid, Dealership_VModelList, "Dealership Vehicle Model");
    }
    return 1;
}

Selection:Dealership_VModelList(playerid, response, model, vehicle_color1, vehicle_color2)
{
    new dealershipid = player_editdealer_id[playerid], slot = player_editdealer_vmodelslot[playerid];
    if(!response) return ShowPlayerEditDealership(playerid, dealershipid, DEALERSHIP_EDIT_VEHICLEMODEL);
    else
    {
        if(model == 1239) 
        {
            dealershipInfo[dealershipid][dealershipVehicleModel][slot] = -1;
            SendClientMessageEx(playerid, COLOR_REN, "DEALERSHIP: "WHITE"Anda telah menghapus model deler kendaraan");
            SortDealershipVehicleModel(dealershipid);
            UpdateDealershipData(dealershipid);
            ShowPlayerEditDealership(playerid, dealershipid, DEALERSHIP_EDIT_VEHICLEMODEL);
            return 1;
        }
        dealershipInfo[dealershipid][dealershipVehicleModel][slot] = model;
        SendClientMessageEx(playerid, COLOR_REN, "DEALERSHIP: "WHITE"Anda telah mengubah model kendaraan "YELLOW"dealership %d"WHITE" menjadi "LG"(model: %d) %s", dealershipid, model, GetVehicleModelName(model));

        SortDealershipVehicleModel(dealershipid);
        UpdateDealershipData(dealershipid);

        ShowPlayerEditDealership(playerid, dealershipid, DEALERSHIP_EDIT_VEHICLEMODEL);
    }
    return 1;
}