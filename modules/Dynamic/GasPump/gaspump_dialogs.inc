enum
{
    EDIT_GASPUMP_LIST,
    EDIT_GASPUMP_POSITION,
    EDIT_GASPUMP_BUSINESS,
    EDIT_GASPUMP_DELETE,
}

stock ShowEditGasPumpMenu(playerid, gaspumpid, type = EDIT_GASPUMP_LIST) 
{
    if(!Iter_Contains(GasPump, gaspumpid)) return 1;

    switch(type) 
    {
        case EDIT_GASPUMP_LIST:
        {
            new message[500];
            format(message, sizeof(message), "%s"WHITE"Position\n", message);
            if(gaspumpInfo[gaspumpid][gaspumpBusinessID] != -1) format(message, sizeof(message), "%s"WHITE"Business "YELLOW"Connected to business id %d\n", message, gaspumpInfo[gaspumpid][gaspumpBusinessID]);
            else format(message, sizeof(message), "%s"WHITE"Business "RED"tidak terkoneksi ke bisnis\n", message);
            format(message, sizeof(message), "%s"RED"Delete Gaspump\n", message);
            Dialog_Show(playerid, EditGasPump_List, DIALOG_STYLE_LIST, "Edit Gas Pump", message, "Pilih", "Tutup");
        }
        case EDIT_GASPUMP_POSITION:
        {
            ShowPlayerEditObjectPosition(playerid, EDITOBJECT_GASPUMP, gaspumpInfo[gaspumpid][gaspumpObject]);
        }
        case EDIT_GASPUMP_BUSINESS:
        {
            Dialog_Show(playerid, EditGasPump_Business, DIALOG_STYLE_INPUT, "Connect Gas Pump to Business", "Masukkan dengan input id bisnis untuk mengkoneksikannya", "Ubah", "Kembali");
        }
        case EDIT_GASPUMP_DELETE:
        {
            DeleteGasPump(gaspumpid);
        }
    }
    player_edit_gaspumpid[playerid] = gaspumpid;
    return 1;
}

Dialog:EditGasPump_List(playerid, response, listitem, inputtext[]) 
{
    if(!response) return 1;
    else 
    {
        switch(listitem) 
        {
            case 0: ShowEditGasPumpMenu(playerid, player_edit_gaspumpid[playerid], EDIT_GASPUMP_POSITION);
            case 1: ShowEditGasPumpMenu(playerid, player_edit_gaspumpid[playerid], EDIT_GASPUMP_BUSINESS);
            case 2: ShowEditGasPumpMenu(playerid, player_edit_gaspumpid[playerid], EDIT_GASPUMP_DELETE);
        }
    }
    return 1;
}

Dialog:EditGasPump_Business(playerid, response, listitem, inputtext[]) 
{
    if(!response) return 1;
    else
    {
        new gaspumpid = player_edit_gaspumpid[playerid], businessid;
        
        if(sscanf(inputtext, "d", businessid))
            return ShowEditGasPumpMenu(playerid, gaspumpid, EDIT_GASPUMP_BUSINESS);

        if(!IsValidBusiness(businessid))
            return SendErrorMessage(playerid, "Invalid business ID!"), ShowEditGasPumpMenu(playerid, gaspumpid, EDIT_GASPUMP_BUSINESS);

        gaspumpInfo[gaspumpid][gaspumpBusinessID] = businessid;
        RefreshGasPump(gaspumpid);
    }
    return 1;
}

stock ShowBuyFuelMenu(playerid, vehicleid, businessid) 
{
    new Float:amount;
    GetBusinessFuelAmount(businessid, amount);

    if(amount == 0.0) 
        return SendErrorMessage(playerid, "Stok bahan bakar kosong!");

    new Float:oldfuel, Float:maxfuel;
    GetVehicleFuel(vehicleid, oldfuel);
    GetVehicleMaxFuel(vehicleid, maxfuel);

    new message[3000];
    format(message, sizeof(message), "%s"YELLOW"%s\n\n", message, GetBusinessName(businessid));
    format(message, sizeof(message), "%s"WHITE"Masukkan jumlah bahan bakar yang ingin anda beli (satuan liter)\n", message);
    format(message, sizeof(message), "%s"WHITE"Harga per liter: "LG"$%s\n\n", message, FormatMoney(GetBusinessFuelPrice(businessid)));
    format(message, sizeof(message), "%s"LB"bahan bakar kendaraan saat ini %.2f Liter / %.2f\n", message, oldfuel, maxfuel);
    Dialog_Show(playerid, BuyFuel, DIALOG_STYLE_INPUT, "Bahan Bakar", message, "Beli", "Tutup");

    player_buy_fuel_businessid[playerid] = businessid;
    player_buy_fuel_vehicleid[playerid] = vehicleid;
    return 1;
}

Dialog:BuyFuel(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    else
    {
        new businessid = player_buy_fuel_businessid[playerid];
        new vehicleid = player_buy_fuel_vehicleid[playerid];

        new fuel_price = GetBusinessFuelPrice(businessid);
        new Float:amount = 0.0;
        new price;

        if(sscanf(inputtext, "f", amount))
            return SendErrorMessage(playerid, "Masukkan jumlah bahan bakar yang ingin dibeli dengan sesuai."), ShowBuyFuelMenu(playerid, vehicleid, businessid);

        if(amount <= 0.0)
            return SendErrorMessage(playerid, "Masukkan jumlah bahan bakar yang ingin dibeli dengan sesuai."), ShowBuyFuelMenu(playerid, vehicleid, businessid);

        new Float:business_fuel;
        GetBusinessFuelAmount(businessid, business_fuel);
        if(business_fuel < amount) 
            return SendErrorMessage(playerid, "Stok bahan bakar tidak ada sebanyak itu!");

        new Float:oldfuel, Float:maxfuel;
        GetVehicleFuel(vehicleid, oldfuel);
        GetVehicleMaxFuel(vehicleid, maxfuel);

        if(oldfuel + amount > maxfuel) amount = maxfuel - oldfuel;

        price = fuel_price * floatround(amount, floatround_ceil);

        if(GetPlayerMoney(playerid) < price)
            return SendErrorMessage(playerid, "Uang anda tidak cukup!");
        
        SendClientMessageEx(playerid, COLOR_REN, "FUEL: "WHITE"Memulai mengisi bahan bakar kendaraan.");

        GivePlayerMoney(playerid, -price);
        GiveBusinessMoney(businessid, price);

        GiveBusinessFuel(businessid, -amount);
        SetVehicleRefueling(vehicleid, amount);
    }
    return 1;
}