YCMD:mechanicarea(playerid, params[], help)
{
    if(!IsPlayerAdmin(playerid, Manager))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses menggunakan command ini!");

    new action[50], string[250], bool:syntax = true;
    if(sscanf(params, "s[50]S()[250]", action, string))
    {
        syntax = false;
    }
    else
    {
        if(!strcmp(action, "list", true))
        {
            ShowPlayerMechanicAreaList(playerid);
        }
        else if(!strcmp(action, "from", true))
        {
            new Float:x, Float:y, Float:z;
            GetPlayerPos(playerid, x, y, z);

            player_create_mecharea_status[playerid] = true;
            player_create_mecharea[playerid][0][0] = x;
            player_create_mecharea[playerid][0][1] = y;
            player_create_mecharea[playerid][0][2] = z;

            RefreshPlayerCreateMechArea(playerid);
        }
        else if(!strcmp(action, "to", true))
        {
            new Float:x, Float:y, Float:z;
            GetPlayerPos(playerid, x, y, z);

            player_create_mecharea_status[playerid] = true;
            player_create_mecharea[playerid][1][0] = x;
            player_create_mecharea[playerid][1][1] = y;
            player_create_mecharea[playerid][1][2] = z;

            RefreshPlayerCreateMechArea(playerid);
        }
        else if(!strcmp(action, "confirm", true))
        {
            new bool:status = true;
            
            if(player_create_mecharea[playerid][0][0] == 0.0 || player_create_mecharea[playerid][0][1] == 0.0 || player_create_mecharea[playerid][0][2] == 0.0) status = false;
            else if(player_create_mecharea[playerid][1][0] == 0.0 || player_create_mecharea[playerid][1][1] == 0.0 || player_create_mecharea[playerid][1][2] == 0.0) status = false;
            else if(player_create_mecharea_status[playerid] == false) status = false;
            else status = true;

            if(status == false) 
                return SendErrorMessage(playerid, "Anda sebelumnya tidak mengatur posisi awal area '/mechanicarea from' atau posisi akhir area '/mechanicarea to'!");

            new areaid = -1;
            areaid = AddMechanicArea(player_create_mecharea[playerid][0][0], player_create_mecharea[playerid][0][1], player_create_mecharea[playerid][1][0], player_create_mecharea[playerid][1][1]);
            
            if(areaid == -1)
                return SendErrorMessage(playerid, "Gagal membuat area karena tidak dapat menambahkan area baru lagi!");

            if(areaid != -1)
            {
                SendClientMessageEx(playerid, COLOR_REN, "MECHANIC-AREA: "WHITE"Anda telah membuat area "YELLOW"mekanik %d", areaid);

                player_create_mecharea[playerid][0][0] = 0.0;
                player_create_mecharea[playerid][0][1] = 0.0;
                player_create_mecharea[playerid][0][2] = 0.0;
                player_create_mecharea[playerid][1][0] = 0.0;
                player_create_mecharea[playerid][1][1] = 0.0;
                player_create_mecharea[playerid][1][2] = 0.0;

                if(IsValidDynamic3DTextLabel(player_create_mecharea_label[playerid][0]))
                    DestroyDynamic3DTextLabel(player_create_mecharea_label[playerid][0]);

                if(IsValidDynamicPickup(player_create_mecharea_pickup[playerid][0]))
                    DestroyDynamicPickup(player_create_mecharea_pickup[playerid][0]);
                
                if(IsValidDynamic3DTextLabel(player_create_mecharea_label[playerid][1]))
                    DestroyDynamic3DTextLabel(player_create_mecharea_label[playerid][1]);

                if(IsValidDynamicPickup(player_create_mecharea_pickup[playerid][1]))
                    DestroyDynamicPickup(player_create_mecharea_pickup[playerid][1]);
            }
        }
        else if(!strcmp(action, "cancel", true))
        {
            new bool:status = true;
            
            if(player_create_mecharea[playerid][0][0] == 0.0 || player_create_mecharea[playerid][0][1] == 0.0 || player_create_mecharea[playerid][0][2] == 0.0) status = false;
            else if(player_create_mecharea[playerid][1][0] == 0.0 || player_create_mecharea[playerid][1][1] == 0.0 || player_create_mecharea[playerid][1][2] == 0.0) status = false;
            else if(player_create_mecharea_status[playerid] == false) status = false;
            else status = true;

            if(status == false) 
                return SendErrorMessage(playerid, "Anda sebelumnya tidak mengatur posisi awal area '/mechanicarea from' atau posisi akhir area '/mechanicarea to'!");
        
            player_create_mecharea[playerid][0][0] = 0.0;
            player_create_mecharea[playerid][0][1] = 0.0;
            player_create_mecharea[playerid][0][2] = 0.0;
            player_create_mecharea[playerid][1][0] = 0.0;
            player_create_mecharea[playerid][1][1] = 0.0;
            player_create_mecharea[playerid][1][2] = 0.0;

            SendClientMessageEx(playerid, COLOR_REN, "MECHANIC-AREA: Anda telah membatalkan untuk membuat area mekanik!");

            if(IsValidDynamic3DTextLabel(player_create_mecharea_label[playerid][0]))
                DestroyDynamic3DTextLabel(player_create_mecharea_label[playerid][0]);

            if(IsValidDynamicPickup(player_create_mecharea_pickup[playerid][0]))
                DestroyDynamicPickup(player_create_mecharea_pickup[playerid][0]);
            
            if(IsValidDynamic3DTextLabel(player_create_mecharea_label[playerid][1]))
                DestroyDynamic3DTextLabel(player_create_mecharea_label[playerid][1]);

            if(IsValidDynamicPickup(player_create_mecharea_pickup[playerid][1]))
                DestroyDynamicPickup(player_create_mecharea_pickup[playerid][1]);
        }
        else if(!strcmp(action, "delete", true))
        {
            new areaid = -1;
            foreach(new i : MechanicArea) 
            {
                if(Iter_Contains(MechanicArea, i) && IsPlayerInDynamicArea(playerid, mechanicareaInfo[i][mechanicareaID]))
                {
                    areaid = i;
                    break;
                }
            }

            if(areaid == -1)
                return SendErrorMessage(playerid, "Anda tidak berada di area mekanik, gunakan '/mechanicarea list' untuk mengetahui lokasinya!");

            SendClientMessageEx(playerid, COLOR_REN, "MECHANIC-AREA: "WHITE"Anda telah menghapus area "LR"mekanik %d", areaid);
            DeleteMechanicArea(areaid);
        }
    }
    
    if(syntax == false)
    {
        SendUsageMessage(playerid, "/mechanicarea [action]");
        SendClientMessageEx(playerid, COLOR_REN, "ACTION: list from to confirm cancel delete");
    }
    
    return 1;
}