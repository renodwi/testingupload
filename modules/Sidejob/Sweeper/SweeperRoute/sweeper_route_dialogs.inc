enum 
{
    SWEEPER_ROUTE_LIST,
    SWEEPER_ROUTE_CREATE_POS,
    SWEEPER_ROUTE_CREATE_NAME,
    SWEEPER_ROUTE_CREATE_SALARY,
    SWEEPER_ROUTE_CREATE_CONFIRM,
}

enum 
{
    EDIT_SWEEPER_ROUTE_LIST,
    EDIT_SWEEPER_ROUTE_POSITION,
    EDIT_SWEEPER_ROUTE_NAME,
    EDIT_SWEEPER_ROUTE_SALARY,
    EDIT_SWEEPER_ROUTE_CONFIRM,
    EDIT_SWEEPER_ROUTE_MARK,
    EDIT_SWEEPER_ROUTE_DELETE,
}

stock ShowPlayerSweeperRouteMenu(playerid, show = SWEEPER_ROUTE_LIST)
{
    switch(show) 
    {
        case SWEEPER_ROUTE_LIST:
        {
            new message[3000];
            format(message, sizeof(message), "%sRoute\tGaji\tLokasi\n", message);
            format(message, sizeof(message), "%s"WHITE"< Buat Rute Baru >\n", message);
            foreach(new i : SweeperRoute)
            {
                if(Iter_Contains(SweeperRoute, i))
                {
                    format(message, sizeof(message), "%s"WHITE"%s\t"LG"$%s\t"LB"%s\n", message, sweeperrouteInfo[i][sweeperrouteName], FormatMoney(sweeperrouteInfo[i][sweeperrouteSalary]), GetLocation(sweeperrouteInfo[i][sweeperrouteLocationX], sweeperrouteInfo[i][sweeperrouteLocationY], sweeperrouteInfo[i][sweeperrouteLocationZ]));
                }
            }
            Dialog_Show(playerid, SweeperRoute_List, DIALOG_STYLE_TABLIST_HEADERS, "Sweeper Route", message, "Pilih", "Tutup");
        }
        case SWEEPER_ROUTE_CREATE_POS:
        {
            Dialog_Show(playerid, SweeperRoute_CreatePos, DIALOG_STYLE_MSGBOX, "Sweeper Route > Create > Pos", "Anda yakin anda akan membuat rute sweeper baru pada lokasi ini?", "Ya", "Tidak");
        }
        case SWEEPER_ROUTE_CREATE_NAME:
        {
            Dialog_Show(playerid, SweeperRoute_CreateName, DIALOG_STYLE_INPUT, "Sweeper Route > Create > Name", "Masukkan nama rute sweeper yang anda buat (maksimal %d karakter)", "Lanjut", "Kembali", MAX_SWEEPER_ROUTE_NAME);
        }
        case SWEEPER_ROUTE_CREATE_SALARY:
        {
            Dialog_Show(playerid, SweeperRoute_CreateSalary, DIALOG_STYLE_INPUT, "Sweeper Route > Create > Salary", "Masukkan salary untuk ditetapkan pada rute sweeper yang akan anda buat (format uang)", "Lanjut", "Kembali");
        }
        case SWEEPER_ROUTE_CREATE_CONFIRM:
        {
            new message[1000];
            format(message, sizeof(message), "%s"WHITE"Konfirmasi kembali apakah anda yakin akan membuat rute sweeper dengan\n\n", message);
            format(message, sizeof(message), "%s"WHITE"Nama Rute: "YELLOW"%s\n", message, player_createsweeperroute_name[playerid]);
            format(message, sizeof(message), "%s"WHITE"Lokasi: "LB"%s\n", message, GetLocation(player_createsweeperroute_loc[playerid][0], player_createsweeperroute_loc[playerid][1], player_createsweeperroute_loc[playerid][2]));
            format(message, sizeof(message), "%s"WHITE"Gaji: "LG"$%s", message, FormatMoney(player_createsweeperroute_gaji[playerid]));
            Dialog_Show(playerid, SweeperRoute_CreateConfirm, DIALOG_STYLE_MSGBOX, "Sweeper Route > Create > Confirm", message, "Ya", "Kembali");
        }
    }
    return 1;
}

Dialog:SweeperRoute_List(playerid, response, listitem, inputtext[]) 
{
    if(!response) return 1;
    else
    {
        if(listitem == 0)
        {
            ShowPlayerSweeperRouteMenu(playerid, SWEEPER_ROUTE_CREATE_POS);
        }
        else
        {
            listitem = listitem - 1;
            player_editsweeperroute_id[playerid] = listitem;

            format(player_editsweeperroute_name[playerid], MAX_SWEEPER_ROUTE_NAME, sweeperrouteInfo[listitem][sweeperrouteName]);
            player_editsweeperroute_gaji[playerid] = sweeperrouteInfo[listitem][sweeperrouteSalary];
            player_editsweeperroute_loc[playerid][0] = sweeperrouteInfo[listitem][sweeperrouteLocationX];
            player_editsweeperroute_loc[playerid][1] = sweeperrouteInfo[listitem][sweeperrouteLocationY];
            player_editsweeperroute_loc[playerid][2] = sweeperrouteInfo[listitem][sweeperrouteLocationZ];

            ShowPlayerEditSweeperRoute(playerid, EDIT_SWEEPER_ROUTE_LIST);
        }
    }
    return 1;
}

Dialog:SweeperRoute_CreatePos(playerid, response, listitem, inputtext[]) 
{
    if(!response) return 1;
    else
    {
        ShowPlayerSweeperRouteMenu(playerid, SWEEPER_ROUTE_CREATE_NAME);
        GetPlayerPos(playerid, player_createsweeperroute_loc[playerid][0], player_createsweeperroute_loc[playerid][1], player_createsweeperroute_loc[playerid][2]);
    }
    return 1;
}

Dialog:SweeperRoute_CreateName(playerid, response, listitem, inputtext[]) 
{
    if(!response) return ShowPlayerSweeperRouteMenu(playerid, SWEEPER_ROUTE_CREATE_POS);
    else
    {
        if(strlen(inputtext) <= 1)
            return SendErrorMessage(playerid, "Nama rute sweeper harus terdiri minimal lebih dari 1 karakter huruf"), ShowPlayerSweeperRouteMenu(playerid, SWEEPER_ROUTE_CREATE_NAME);

        format(player_createsweeperroute_name[playerid], MAX_SWEEPER_ROUTE_NAME, inputtext);
        ShowPlayerSweeperRouteMenu(playerid, SWEEPER_ROUTE_CREATE_SALARY);
    }
    return 1;
}

Dialog:SweeperRoute_CreateSalary(playerid, response, listitem, inputtext[]) 
{
    if(!response) return ShowPlayerSweeperRouteMenu(playerid, SWEEPER_ROUTE_CREATE_NAME);
    else
    {
        if(!IsMoneyFormat(inputtext))
            return SendErrorMessage(playerid, "Masukkan input dengan format uang!"), ShowPlayerSweeperRouteMenu(playerid, SWEEPER_ROUTE_CREATE_SALARY);

        player_createsweeperroute_gaji[playerid] = StringToMoney(inputtext);
        ShowPlayerSweeperRouteMenu(playerid, SWEEPER_ROUTE_CREATE_CONFIRM);
    }
    return 1;
}

Dialog:SweeperRoute_CreateConfirm(playerid, response, listitem, inputtext[]) 
{
    if(!response) return ShowPlayerSweeperRouteMenu(playerid, SWEEPER_ROUTE_CREATE_SALARY);
    else
    {
        new routeid;
        routeid = MakeSweeperRoute(player_createsweeperroute_loc[playerid][0], player_createsweeperroute_loc[playerid][1], player_createsweeperroute_loc[playerid][2], player_createsweeperroute_name[playerid], player_createsweeperroute_gaji[playerid]);
        if(routeid == -1)
            return SendErrorMessage(playerid, "Ada suatu hal yang salah...");
            
        SendClientMessageEx(playerid, COLOR_REN, "SWEEPER-ROUTE: "WHITE"Anda telah membuat rute sweeper baru dengan nama "YELLOW"%s [id: %d]", player_createsweeperroute_name[playerid], routeid);
    }
    return 1;
}

stock ShowPlayerEditSweeperRoute(playerid, show = EDIT_SWEEPER_ROUTE_LIST) 
{
    switch(show)
    {
        case EDIT_SWEEPER_ROUTE_LIST:
        {
            new message[1200];
            format(message, sizeof(message), "#\tValue\n");
            format(message, sizeof(message), "%s"WHITE"Route Name\t"YELLOW"%s\n", message, player_editsweeperroute_name[playerid]);
            format(message, sizeof(message), "%s"WHITE"Gaji\t"LG"$%s\n", message, FormatMoney(player_editsweeperroute_gaji[playerid]));
            format(message, sizeof(message), "%s"WHITE"Lokasi\t"LB"%s\n", message, GetLocation(player_editsweeperroute_loc[playerid][0], player_editsweeperroute_loc[playerid][1], player_editsweeperroute_loc[playerid][2]));
            format(message, sizeof(message), "%s"WHITE"Simpan\n\t", message);
            format(message, sizeof(message), "%s"WHITE"Edit Mark (checkpoint)\n\t", message);
            format(message, sizeof(message), "%s"LR"Delete\t", message);
            Dialog_Show(playerid, SweeperRoute_EditList, DIALOG_STYLE_TABLIST_HEADERS, "Sweeper Route > Edit", message, "Pilih", "Kembali");
        }
        case EDIT_SWEEPER_ROUTE_POSITION:
        {
            SendClientMessageEx(playerid, COLOR_REN, "SWEEPER-ROUTE: "WHITE"Anda memasuki mode edit lokasi rute sweeper, gunakan "YELLOW"/sweeper"WHITE" untuk menentukan lokasi");
            player_editingsweeperroute_loc[playerid] = true;
        }
        case EDIT_SWEEPER_ROUTE_NAME:
        {
            Dialog_Show(playerid, SweeperRoute_EditName, DIALOG_STYLE_INPUT, "Sweeper Route > Edit > Name", ""WHITE"Masukkan nama rute sweeper untuk digantikan\n\nNama saat ini: "YELLOW"%s", "Ganti", "Kembali", player_editsweeperroute_name[playerid]);
        }
        case EDIT_SWEEPER_ROUTE_SALARY:
        {
            Dialog_Show(playerid, SweeperRoute_EditSalary, DIALOG_STYLE_INPUT, "Sweeper Route > Edit > Salary", ""WHITE"Masukkan gaji rute sweeper untuk digantikan\n\nGaji saat ini: "LG"$%s", "Ganti", "Kembali", FormatMoney(player_editsweeperroute_gaji[playerid]));
        }
        case EDIT_SWEEPER_ROUTE_CONFIRM:
        {
            new message[1200], routeid = player_editsweeperroute_id[playerid];
            format(message, sizeof(message), "%s"WHITE"Konfirmasi anda akan mengubah dan menyimpanya\n\n", message);
            format(message, sizeof(message), "%s"WHITE"Route Name: "YELLOW"%s"WHITE" >> "YELLOW"%s\n", message, sweeperrouteInfo[routeid][sweeperrouteName], player_editsweeperroute_name[playerid]);
            format(message, sizeof(message), "%s"WHITE"Gaji: "LG"$%s"WHITE" >> "LG"$%s\n", message, FormatMoney(sweeperrouteInfo[routeid][sweeperrouteSalary]), FormatMoney(player_editsweeperroute_gaji[playerid]));
            format(message, sizeof(message), "%s"WHITE"Lokasi: "LB"%s"WHITE" >> "LB"%s\n", message, GetLocation(sweeperrouteInfo[routeid][sweeperrouteLocationX], sweeperrouteInfo[routeid][sweeperrouteLocationY], sweeperrouteInfo[routeid][sweeperrouteLocationZ]), GetLocation(player_editsweeperroute_loc[playerid][0], player_editsweeperroute_loc[playerid][1], player_editsweeperroute_loc[playerid][2]));
            format(message, sizeof(message), "%s"WHITE"\nApakah data diatas sudah benar?", message);
            Dialog_Show(playerid, SweeperRoute_EditConfirm, DIALOG_STYLE_MSGBOX, "Sweeper Route > Edit > Confirm", message, "Ya", "Kembali");
        }
        case EDIT_SWEEPER_ROUTE_MARK:
        {
            Dialog_Show(playerid, SweeperRoute_Mark, DIALOG_STYLE_MSGBOX, "Sweeper Route > Edit > Reset Mark", ""WHITE"Anda yakin akan membuat ulang seluruh mark (checkpoint) pada rute sweeper ini?", "Ya", "Kembali");
        }
        case EDIT_SWEEPER_ROUTE_DELETE:
        {
            Dialog_Show(playerid, SweeperRoute_Delete, DIALOG_STYLE_MSGBOX, "Sweeper Route > Edit > "LR"Delete", ""WHITE"Anda yakin akan menghapus rute sweeeper ini? (AKAN MENGHAPUS SWEEPER MARK JUGA YANG SESUAI DENGAN ROUTE INI!)", ""LR"Hapus", "Kembali");
        }
    }
    return 1;
}

Dialog:SweeperRoute_EditList(playerid, response, listitem, inputtext[]) 
{
    if(!response) return ShowPlayerSweeperRouteMenu(playerid, SWEEPER_ROUTE_LIST);
    else
    {
        switch(listitem) 
        {
            case 0: ShowPlayerEditSweeperRoute(playerid, EDIT_SWEEPER_ROUTE_NAME);
            case 1: ShowPlayerEditSweeperRoute(playerid, EDIT_SWEEPER_ROUTE_SALARY);
            case 2: ShowPlayerEditSweeperRoute(playerid, EDIT_SWEEPER_ROUTE_POSITION);
            case 3: ShowPlayerEditSweeperRoute(playerid, EDIT_SWEEPER_ROUTE_CONFIRM);
            case 4: ShowPlayerEditSweeperRoute(playerid, EDIT_SWEEPER_ROUTE_MARK);
            case 5: ShowPlayerEditSweeperRoute(playerid, EDIT_SWEEPER_ROUTE_DELETE);
        }
    }
    return 1;
}

Dialog:SweeperRoute_EditName(playerid, response, listitem, inputtext[]) 
{
    if(!response) return ShowPlayerEditSweeperRoute(playerid, EDIT_SWEEPER_ROUTE_LIST);
    else
    {
        if(strlen(inputtext) > MAX_SWEEPER_ROUTE_NAME)
            return SendErrorMessage(playerid, "Nama rute sweeper tidak dapat lebih dari %d karakter huruf", MAX_SWEEPER_ROUTE_NAME), ShowPlayerEditSweeperRoute(playerid, EDIT_SWEEPER_ROUTE_NAME);

        format(player_editsweeperroute_name[playerid], MAX_SWEEPER_ROUTE_NAME, inputtext);
        ShowPlayerEditSweeperRoute(playerid, EDIT_SWEEPER_ROUTE_LIST);
    }
    return 1;
}

Dialog:SweeperRoute_EditSalary(playerid, response, listitem, inputtext[]) 
{
    if(!response) return ShowPlayerEditSweeperRoute(playerid, EDIT_SWEEPER_ROUTE_LIST);
    else
    {
        if(!IsMoneyFormat(inputtext))
            return SendErrorMessage(playerid, "Input yang diterima hanya berformat uang atau angka saja!"), ShowPlayerEditSweeperRoute(playerid, EDIT_SWEEPER_ROUTE_SALARY);

        player_editsweeperroute_gaji[playerid] = StringToMoney(inputtext);
        ShowPlayerEditSweeperRoute(playerid, EDIT_SWEEPER_ROUTE_LIST);
    }
    return 1;
}

Dialog:SweeperRoute_EditConfirm(playerid, response, listitem, inputtext[]) 
{
    if(!response) return ShowPlayerEditSweeperRoute(playerid, EDIT_SWEEPER_ROUTE_LIST);
    else
    {
        SendClientMessageEx(playerid, COLOR_REN, "SWEEPER-ROUTE: "WHITE"Perubahan berhasil disimpan");

        new routeid = player_editsweeperroute_id[playerid];
        format(sweeperrouteInfo[routeid][sweeperrouteName], MAX_SWEEPER_ROUTE_NAME, player_editsweeperroute_name[playerid]);
        sweeperrouteInfo[routeid][sweeperrouteSalary] = player_editsweeperroute_gaji[playerid];
        sweeperrouteInfo[routeid][sweeperrouteLocationX] = player_editsweeperroute_loc[playerid][0];
        sweeperrouteInfo[routeid][sweeperrouteLocationY] = player_editsweeperroute_loc[playerid][1];
        sweeperrouteInfo[routeid][sweeperrouteLocationZ] = player_editsweeperroute_loc[playerid][2];
    }
    return 1;
}

Dialog:SweeperRoute_Mark(playerid, response, listitem, inputtext[]) 
{
    if(!response) return ShowPlayerEditSweeperRoute(playerid, EDIT_SWEEPER_ROUTE_LIST);
    else
    {
        SetPlayerEditSweeperMarkMode(playerid, player_editsweeperroute_id[playerid]);
    }
    return 1;
}

Dialog:SweeperRoute_Delete(playerid, response, listitem, inputtext[]) 
{
    if(!response) return ShowPlayerEditSweeperRoute(playerid, EDIT_SWEEPER_ROUTE_LIST);
    else
    {
        new routeid = player_editsweeperroute_id[playerid];

        SendClientMessageEx(playerid, COLOR_REN, "SWEEPER-ROUTE: "WHITE"Anda telah menghapus "LR"sweeper route %d");
        DeleteSweeperRoute(routeid);
    }
    return 1;
}

// =======================================================================================================================

Dialog:SweeperRoute_JobList(playerid, response, listitem, inputtext[]) 
{
    if(!response) return RemovePlayerFromVehicle(playerid);
    else
    {
        if(!IsPlayerInAnyVehicle(playerid) && GetVehicleModel(GetPlayerVehicleID(playerid)) != 574)
            return SendErrorMessage(playerid, "Anda tidak berada pada mobil sweeper!");

        new routeid = listitem;
        if(sweeperrouteInfo[routeid][sweeperrouteStatus] == SWEEPER_ROUTE_USED)
            return SendErrorMessage(playerid, "Rute ini sedang dikerjakan oleh seseorang!"), ShowPlayerSweeperRouteList(playerid);
            
        StartPlayerSweeperJob(playerid, listitem);
    }
    return 1;
}

Dialog:SweeperJob_Exit(playerid, response, listitem, inputtext[]) 
{
    if(!response) return 1;
    else
    {
        StopPlayerSweeperJob(playerid);
        SendClientMessageEx(playerid, COLOR_REN, "SWEEPER: "WHITE"Anda telah "LR"menggagalkan"WHITE" bekerja sebagai "YELLOW"pembersih jalan (sweeper)");
    }
    return 1;
}

// Dialog:SweeperRoute_EditList(playerid, response, listitem, inputtext[]) 
// {
//     if(!response) return 1;
//     else
//     {
        
//     }
//     return 1;
// }

// Dialog:SweeperRoute_EditList(playerid, response, listitem, inputtext[]) 
// {
//     if(!response) return 1;
//     else
//     {
        
//     }
//     return 1;
// }