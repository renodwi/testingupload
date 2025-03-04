YCMD:dealership(playerid, params[], help)
{
    if(!IsPlayerAdmin(playerid, Manager))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");

    if(player_editdealer_position[playerid] == true) 
    {
        new dealershipid = player_editdealer_id[playerid], Float:x, Float:y, Float:z;
        
        GetPlayerPos(playerid, x, y, z);

        dealershipInfo[dealershipid][dealershipPositionX] = x;
        dealershipInfo[dealershipid][dealershipPositionY] = y;
        dealershipInfo[dealershipid][dealershipPositionZ] = z;

        SendClientMessageEx(playerid, COLOR_REN, "DEALERSHIP: "WHITE"Anda telah mengubah lokasi "YELLOW"deler kendaraan %d", dealershipid);
        RefreshDealership(dealershipid);

        player_editdealer_position[playerid] = false;
        return 1;
    }
    else if(player_editdealer_vehposition[playerid] == true) 
    {
        new dealershipid = player_editdealer_id[playerid], Float:x, Float:y, Float:z, Float:a;
        
        GetPlayerPos(playerid, x, y, z);

        dealershipInfo[dealershipid][dealershipSpawnPositionX] = x;
        dealershipInfo[dealershipid][dealershipSpawnPositionY] = y;
        dealershipInfo[dealershipid][dealershipSpawnPositionZ] = z;
        dealershipInfo[dealershipid][dealershipSpawnPositionA] = a;

        SendClientMessageEx(playerid, COLOR_REN, "DEALERSHIP: "WHITE"Anda telah mengubah lokasi "YELLOW"spawn deler kendaraan %d", dealershipid);
        RefreshDealership(dealershipid);

        player_editdealer_vehposition[playerid] = false;
        return 1;
    }
    else if(player_editdealer_vehposloc[playerid] == true) 
    {
        new dealervehposid = player_editdealer_vehposid[playerid], dealershipid = player_editdealer_id[playerid];

        new Float:x, Float:y, Float:z, Float:a;
        GetPlayerPos(playerid, x, y, z);
        GetPlayerFacingAngle(playerid, a);
        
        dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPositionX] = x;
        dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPositionY] = y;
        dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPositionZ] = z;
        dealershipvehposInfo[dealershipid][dealervehposid][dealershipvehposPositionA] = a;

        SendClientMessageEx(playerid, COLOR_REN, "DEALERSHIP-VEHPOS: "WHITE"Anda telah mengubah lokasi model kendaran deler");
        player_editdealer_vehposloc[playerid] = false;

        RefreshDealershipVehPos(dealershipid, dealervehposid);
        return 1;
    }
    else if(player_editdealer_cvehposloc[playerid] == true)
    {
        new Float:x, Float:y, Float:z, Float:a, dealershipid = player_editdealer_id[playerid];
        GetPlayerPos(playerid, x, y, z);
        GetPlayerFacingAngle(playerid, a);
        MakeDealershipVehPos(dealershipid, x, y, z, a);

        SendClientMessageEx(playerid, COLOR_REN, "DEALERSHIP-VEHPOS: "WHITE"Anda telah membuat model deler kendaraan");
        player_editdealer_cvehposloc[playerid] = false; 
        return 1;
    }
    else
    {
        new action[50], string[200], bool:syntax = true; 
        if(sscanf(params, "s[50]S()[200]", action, string))
        {
            syntax = false;
        }
        else
        {
            if(!strcmp(action, "create", true))
            {
                new Float:x, Float:y, Float:z, sprice[20], dealershipid;
                if(sscanf(string, "s[20]", sprice))
                    return SendUsageMessage(playerid, "/dealership create [price]");

                if(!IsMoneyFormat(sprice))
                    return SendErrorMessage(playerid, "Masukan harga dengan format uang!");

                new price = StringToMoney(sprice);

                if(price <= 0)
                    return SendErrorMessage(playerid, "Harga deler kendaraan harus lebih dari $1!");

                if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0)
                    return SendErrorMessage(playerid, "Anda harus berada pada interior: 0 dan virtual world: 0");

                GetPlayerPos(playerid, x, y, z);
                dealershipid = MakeDealership(playerInfo[playerid][playerName], va_return("%s Dealership", GetLocation(x, y, z)), price, x, y, z);
                SendClientMessageEx(playerid, COLOR_REN, "DEALERSHIP: "WHITE"Anda telah membuat "YELLOW"deler kendaraan %d", dealershipid);        
            }
            else if(!strcmp(action, "edit", true)) 
            {
                new near_dealershipid = -1;
                
                foreach(new i : Dealership) {
                    if(IsPlayerInRangeOfPoint(playerid, 5.0, dealershipInfo[i][dealershipPositionX], dealershipInfo[i][dealershipPositionY], dealershipInfo[i][dealershipPositionZ])) {
                        near_dealershipid = i;
                        break;
                    }
                }

                if(near_dealershipid == -1 && sscanf(string, "d", near_dealershipid))
                    return SendUsageMessage(playerid, "/dealership edit [dealership id]");

                if(!Iter_Contains(Dealership, near_dealershipid))
                    return SendErrorMessage(playerid, "Invalid dealership ID!");

                ShowPlayerEditDealership(playerid, near_dealershipid, DEALERSHIP_EDIT_LIST);
            }
            else if(!strcmp(action, "goto", true))
            {
                new dealershipid;
                if(sscanf(string, "d", dealershipid))
                    return SendUsageMessage(playerid, "/dealership goto [dealershipid]");

                if(!Iter_Contains(Dealership, dealershipid))
                    return SendErrorMessage(playerid, "Invalid dealership ID!");

                SetPlayerInterior(playerid, 0);
                SetPlayerVirtualWorld(playerid, 0);
                SetPlayerPos(playerid, dealershipInfo[dealershipid][dealershipPositionX], dealershipInfo[dealershipid][dealershipPositionY], dealershipInfo[dealershipid][dealershipPositionZ]);
            }
            else if(!strcmp(action, "delete", true)) 
            {
                new near_dealershipid = -1;
                
                foreach(new i : Dealership) {
                    if(IsPlayerInRangeOfPoint(playerid, 5.0, dealershipInfo[i][dealershipPositionX], dealershipInfo[i][dealershipPositionY], dealershipInfo[i][dealershipPositionZ])) {
                        near_dealershipid = i;
                        break;
                    }
                }

                if(near_dealershipid == -1 && sscanf(string, "d", near_dealershipid))
                    return SendUsageMessage(playerid, "/dealership delete [dealership id]");

                if(!Iter_Contains(Dealership, near_dealershipid))
                    return SendErrorMessage(playerid, "Invalid dealership ID!");

                ShowPlayerEditDealership(playerid, near_dealershipid, DEALERSHIP_EDIT_DELETE);
            }
            else syntax = false;
        }

        if(syntax == false) 
        {
            SendUsageMessage(playerid, "/dealership [action]");
            SendClientMessageEx(playerid, COLOR_REN, "ACTION: create edit delete");
            return 1;
        }
    }
    return 1;
}