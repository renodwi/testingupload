stock ShowPlayerDealershipVehPos(playerid, dealershipid, show) 
{
    player_editdealer_id[playerid] = dealershipid;
    switch(show) 
    {
        case DEALERSHIP_VEHPOS_EDITLIST:
        {
            new message[3000];
            format(message, sizeof(message), "%s#\tVehicle\tPrice\n", message);
            format(message, sizeof(message), "%s"WHITE"< Buat Posisi Kendaraan Baru >\n", message);
            Loop(i, MAX_DEALERSHIP_VEHPOS)
            {
                if(dealershipvehposInfo[dealershipid][i][dealershipvehposExist] == true) 
                {
                    if(dealershipvehposInfo[dealershipid][i][dealershipvehposModel] == -1)
                    {
                        format(message, sizeof(message), "%s"WHITE"%d\t"YELLOW"(kosong)\t"LG"$%s\n", message, i, FormatMoney(dealershipvehposInfo[dealershipid][i][dealershipvehposPrice]));
                    }
                    else
                    {
                        format(message, sizeof(message), "%s"WHITE"%d\t"YELLOW"%s\t"LG"$%s\n", message, i, GetVehicleModelName(dealershipvehposInfo[dealershipid][i][dealershipvehposModel]), FormatMoney(dealershipvehposInfo[dealershipid][i][dealershipvehposPrice]));
                    }
                }
            }
            Dialog_Show(playerid, DealershipVehPos_List, DIALOG_STYLE_TABLIST_HEADERS, "Dealership Veh Pos > List", message, "Pilih", "Tutup");
        }
        case DEALERSHIP_VEHPOS_EDITMENU:
        {
            new dealervehposid = player_editdealer_vehposid[playerid];

            new message[3000];
            if(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel] < 400)
            {
                format(message, sizeof(message), "%s"WHITE"Model Kendaraan\t"YELLOW"(kosong)\n", message);
            }
            else
            {
                format(message, sizeof(message), "%s"WHITE"Model Kendaraan\t"YELLOW"%s\n", message, GetVehicleModelName(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel]));
            }
            format(message, sizeof(message), "%s"WHITE"Harga\t"LG"$%s\n", message, FormatMoney(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPrice]));
            format(message, sizeof(message), "%s"WHITE"Ubah lokasi model\n", message);
            format(message, sizeof(message), "%s"LR"Hapus\n", message);
            Dialog_Show(playerid, DealershipVehPos_Menu, DIALOG_STYLE_TABLIST, "Dealership Veh Pos > Menu", message, "Pilih", "Tutup");
        }
        case DEALERSHIP_VEHPOS_EDITMODEL:
        {
            new dealervehposid = player_editdealer_vehposid[playerid];
            if(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel] != -1)
            {
                ShowPlayerDealershipVehPos(playerid, dealershipid, DEALERSHIP_VEHPOS_EDMODEL_CONF);
                return 1;
            }

            new message[1200];
            format(message, sizeof(message), "%sKendaraan\tHarga (oleh server)\n", message);
            Loop(i, MAX_DEALERSHIP_VEHICLEMODEL)
            {
                if(dealershipInfo[dealershipid][dealershipVehicleModel][i] > 400)
                {
                    format(message, sizeof(message), "%s"YELLOW"%s\t"LG"$%s\n", message, GetVehicleModelName(dealershipInfo[dealershipid][dealershipVehicleModel][i]), FormatMoney(GetVehicleModelPrice(dealershipInfo[dealershipid][dealershipVehicleModel][i])));
                }
                else continue;
            }
            Dialog_Show(playerid, DealershipVehPos_Model, DIALOG_STYLE_TABLIST_HEADERS, "Dealership > Model", message, "Pilih", "Tutup");
        }
        case DEALERSHIP_VEHPOS_EDMODEL_CONF:
        {
            Dialog_Show(playerid, DealershipVehPos_EdModel_Conf, DIALOG_STYLE_MSGBOX, "Dealership > Change Model", "Anda yakin akan mengubah model deler kendaraan ini? (uang akan dikembalikan sebesar "LR"50\% dari harga yang ditetapkan oleh server!)", "Ya", "Tidak");
        }
        case DEALERSHIP_VEHPOS_EDITPOS:
        {
            player_editdealer_vehposloc[playerid] = true;
            SendClientMessageEx(playerid, COLOR_REN, "DEALERSHIP-VEHPOS: "WHITE"Anda memasuki mode untuk mengedit lokasi kendaraan deler");
            SendClientMessageEx(playerid, COLOR_REN, "DEALERSHIP-VEHPOS: "WHITE"Gunakan "YELLOW"/dealership"WHITE" untuk menentukan lokasinya");
        }
        case DEALERSHIP_VEHPOS_EDITPRICE:
        {
            new dealervehposid = player_editdealer_vehposid[playerid];
            if(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel] < 400)
                return SendErrorMessage(playerid, "Anda tidak dapat mengubah harga kendaraan jika model kendaraan belum ditentukan!");

            Dialog_Show(playerid, DealershipVehPos_EditPrice, DIALOG_STYLE_INPUT, "Dealership Veh Pos > Edit > Price", ""WHITE"Masukkan harga kendaraan deler untuk digantikan\nHarga saat ini: "LG"$%s\n"WHITE"Harga oleh server: "YELLOW"$%s\n\n"GREY"Anda tidak dapat memasukan harga kurang dari harga yang telah ditetapkan oleh server", FormatMoney(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPrice]), FormatMoney(GetVehicleModelPrice(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel])));
        }
        case DEALERSHIP_VEHPOS_EDITDELETE:
        {
            Dialog_Show(playerid, DealershipVehPos_Delete, DIALOG_STYLE_MSGBOX, "Dealership Veh Pos > Delete", ""WHITE"Anda yakin akan "LR"menghapus"WHITE" lokasi model deler kendaraan ini?", "Ya", "Tidak");
        }
    }
    return 1;
}

Dialog:DealershipVehPos_List(playerid, response, listitem, inputtext[])
{
    new dealershipid = player_editdealer_id[playerid];
    if(!response) return 1;
    else
    {
        if(listitem == 0)
        {
            if(GetDealershipVehPosFreeSlot(dealershipid) == -1)
                return SendErrorMessage(playerid, "Delership ini telah mencapai batas jumlah posisi model kendaraan!");
                
            player_editdealer_cvehposloc[playerid] = true;
            SendClientMessageEx(playerid, COLOR_REN, "DEALERSHIP-VEHPOS: "WHITE"Anda telah memasuki mode untuk mengatur lokasi model deler kendaraan");
            SendClientMessageEx(playerid, COLOR_REN, "DEALERSHIP-VEHPOS: "WHITE"Gunakan "YELLOW"/dealership"WHITE" untuk mengatur lokasi model kendaraan");
        }
        else
        {
            listitem -= 1;
            player_editdealer_vehposid[playerid] = listitem;
            ShowPlayerDealershipVehPos(playerid, dealershipid, DEALERSHIP_VEHPOS_EDITMENU);
            
        }
    }
    return 1;
}

Dialog:DealershipVehPos_Menu(playerid, response, listitem, inputtext[])
{
    new dealershipid = player_editdealer_id[playerid];
    if(!response) return ShowPlayerDealershipVehPos(playerid, dealershipid, DEALERSHIP_VEHPOS_EDITLIST);
    else
    {
        switch(listitem) 
        {
            case 0: ShowPlayerDealershipVehPos(playerid, dealershipid, DEALERSHIP_VEHPOS_EDITMODEL);
            case 1: ShowPlayerDealershipVehPos(playerid, dealershipid, DEALERSHIP_VEHPOS_EDITPRICE);
            case 2: ShowPlayerDealershipVehPos(playerid, dealershipid, DEALERSHIP_VEHPOS_EDITPOS); 
            case 3: ShowPlayerDealershipVehPos(playerid, dealershipid, DEALERSHIP_VEHPOS_EDITDELETE);
        }
    }
    return 1;
}

Dialog:DealershipVehPos_EditPrice(playerid, response, listitem, inputtext[])
{
    new dealershipid = player_editdealer_id[playerid];
    if(!response) return ShowPlayerDealershipVehPos(playerid, dealershipid, DEALERSHIP_VEHPOS_EDITMENU);
    else
    {
        new dealervehposid = player_editdealer_vehposid[playerid];

        if(!IsMoneyFormat(inputtext))
            return SendErrorMessage(playerid, "Masukan harga dengan format uang!"), ShowPlayerDealershipVehPos(playerid, dealershipid, DEALERSHIP_VEHPOS_EDITPRICE);

        new price = StringToMoney(inputtext);
        if(price <= 0)
            return SendErrorMessage(playerid, "Harga minimal kendaraan adalah $%s", FormatMoney(100));

        if(price < GetVehicleModelPrice(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPrice]) || price > (GetVehicleModelPrice(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel]) + (GetVehicleModelPrice(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel]) / 2)))
            return SendErrorMessage(playerid, "Harga kendaraan tidak dapat kurang atau lebih dari 1/2 harga yang telah ditetapkan oleh server!");

        SendClientMessageEx(playerid, COLOR_REN, "DEALERSHIP-VEHPOS: "WHITE"Anda telah mengubah harga kendaraan dari "YELLOW"$%s"WHITE" menjadi "LG"$%s", FormatMoney(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPrice]), FormatMoney(price));
        dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPrice] = price;

        new query[200];
        mysql_format(sql, query, sizeof(query), "UPDATE `dealership_vehpos` SET `price` = '%d' WHERE `id` = '%d'", price, dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposDBID]);
        mysql_tquery(sql, query);
    }
    return 1;
}

Dialog:DealershipVehPos_Delete(playerid, response, listitem, inputtext[])
{
    new dealershipid = player_editdealer_id[playerid];
    if(!response) return ShowPlayerDealershipVehPos(playerid, dealershipid, DEALERSHIP_VEHPOS_EDITMENU);
    else
    {
        new dealervehposid = player_editdealer_id[playerid];
        SendClientMessageEx(playerid, COLOR_REN, "DEALERSHIP-VEHPOS: "WHITE"Anda telah menghapus model deler kendaraan");
        DeleteDealershipVehPos(dealershipid, dealervehposid);
    }
    return 1;
}

Dialog:DealershipVehPos_Model(playerid, response, listitem, inputtext[])
{
    new dealershipid = player_editdealer_id[playerid];
    new dealervehposid = player_editdealer_vehposid[playerid];
    if(!response) return 1;
    else
    {
        if(GetPlayerMoney(playerid) < GetVehicleModelPrice(dealershipInfo[dealershipid][dealershipVehicleModel][listitem]))
            return SendErrorMessage(playerid, "Uang anda tidak cukup untuk melakukan restok kendaraan model ini!"), ShowPlayerDealershipVehPos(playerid, dealershipid, DEALERSHIP_VEHPOS_EDITMODEL);

        GivePlayerMoney(playerid, -GetVehicleModelPrice(dealershipInfo[dealershipid][dealershipVehicleModel][listitem]));
        dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel] = dealershipInfo[dealershipid][dealershipVehicleModel][listitem];

        SendClientMessageEx(playerid, COLOR_REN, "DEALERSHIP: "WHITE"Anda telah menambahkan model kendaraan "YELLOW"%s"WHITE" dengan harga "LG"$%s", GetVehicleModelName(dealershipInfo[dealershipid][dealershipVehicleModel][listitem]), FormatMoney(GetVehicleModelPrice(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel])));

        new query[200];
        mysql_format(sql, query, sizeof(query), "UPDATE `dealership_vehpos` SET `model` = '%d' WHERE `id` = '%d'", dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel], dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposDBID]);
        mysql_tquery(sql, query);

        RefreshDealershipVehPos(dealershipid, dealervehposid);
    }
    return 1;
}

Dialog:DealershipVehPos_EdModel_Conf(playerid, response, listitem, inputtext[])
{
    new dealershipid = player_editdealer_id[playerid];
    new dealervehposid = player_editdealer_vehposid[playerid];
    if(!response) return 1;
    else
    {
        SendClientMessageEx(playerid, COLOR_REN, "DEALERSHIP: "WHITE"Anda telah menghilangkan model kendaraan "LR"%s", GetVehicleModelName(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel]));
        SendClientMessageEx(playerid, COLOR_REN, "DEALERSHIP: Server memberikan kompensasi sebesar 50\% dari harga kendaraan yang telah ditentukan oleh server");

        new separo;
        separo = GetVehicleModelPrice(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel]);
        separo = separo / 2;
        GivePlayerMoney(playerid, separo);

        dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel] = -1;
        RefreshDealershipVehPos(dealershipid, dealervehposid);

        new query[200];
        mysql_format(sql, query, sizeof(query), "UPDATE `dealership_vehpos` SET `model` = '%d' WHERE `id` = '%d'", dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel], dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposDBID]);
        mysql_tquery(sql, query);

        ShowPlayerDealershipVehPos(playerid, dealershipid, DEALERSHIP_VEHPOS_EDITMODEL);
    }
    return 1;
}

Dialog:BuyVehicle_Conf(playerid, response, listitem, inputtext[])
{
    if(!response)
    {
        player_buyveh_dealerid[playerid] = -1;
        player_buyveh_dealervehposid[playerid] = -1;
        RemovePlayerFromVehicle(playerid);
    }
    else
    {
        new dealershipid = player_buyveh_dealerid[playerid], dealervehposid = player_buyveh_dealervehposid[playerid];

        if(!IsPlayerInVehicle(playerid, dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposID])) return 1;
        
        Loop(i, 154)
        {
            new slot;
            slot = AddPlayerSelectionItem(playerid, dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel], GetVehicleModelName(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel]), "Warna Kendaraan");
            SetPlayerSelectionVehColor(playerid, slot, i + 1, i + 1);
        }

        ShowPlayerSelection(playerid, BuyVehicle_Color, "Warna Kendaraan");
        SendClientMessageEx(playerid, COLOR_REN, "BUY-VEHICLE: "WHITE"Pilih warna kendaraan yang akan anda pilih");
    }
    return 1;
}

Selection:BuyVehicle_Color(playerid, response, model, vehicle_color1, vehicle_color2)
{
    if(!response) return SendClientMessageEx(playerid, COLOR_REN, "BUY-VEHICLE: "WHITE"Anda telah "LR"membatalkan"WHITE" untuk membeli kendaraan");

    new dealershipid = player_buyveh_dealerid[playerid], dealervehposid = player_buyveh_dealervehposid[playerid];
	GivePlayerMoney(playerid, -dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPrice]);
    SendClientMessageEx(playerid, COLOR_REN, "BUY-VEHICLE: "WHITE"Anda telah membeli "YELLOW"%s"WHITE" dengan harga "LG"$%s", GetVehicleModelName(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel]), FormatMoney(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPrice]));
    
    RemovePlayerFromVehicle(playerid);
    SetTimerEx("BuyVeh_RemPlayer", 500, false, "ddddd", playerid, dealershipid, dealervehposid, vehicle_color1, vehicle_color2);
	return 1;
}

function BuyVeh_RemPlayer(playerid, dealershipid, dealervehposid, vehicle_color1, vehicle_color2)
{
    new vehicleid = CreateVehicle(dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel], dealershipInfo[dealershipid][dealershipSpawnPositionX], dealershipInfo[dealershipid][dealershipSpawnPositionY], dealershipInfo[dealershipid][dealershipSpawnPositionZ], dealershipInfo[dealershipid][dealershipSpawnPositionA], vehicle_color1, vehicle_color2, -1, false);
    dealershipInfo[dealershipid][dealershipMoney] += dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPrice];
    dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposModel] = -1;
    RefreshDealershipVehPos(dealershipid, dealervehposid);

    new query[800];
    
    mysql_format(sql, query, sizeof(query), "UPDATE `dealership_vehpos` SET `model` = '-1' WHERE `id` = '%d'", dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposDBID]);
    mysql_tquery(sql, query);

    mysql_format(sql, query, sizeof(query), "UPDATE `dealership` SET `money` = '%d' WHERE `id` = '%d'", dealershipInfo[dealershipid][dealershipMoney], dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposDBID]);
    mysql_tquery(sql, query);

    SetTimerEx("BuyVeh_Save", false, 1000, "dd", playerid, vehicleid);
    return 1;
}

function BuyVeh_Save(playerid, vehicleid) 
{
    /* SetVehicleSaved(vehicleid, true); */
    SetVehicleOwner(vehicleid, VEHICLE_OWNER_PLAYER, GetName(playerid));
    return 1;
}