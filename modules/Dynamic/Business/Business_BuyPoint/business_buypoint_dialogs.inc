stock ShowPlayerBusinessBuypoint(playerid, businessid, show = BUSINESS_BUYPOINT_LIST)
{
    switch(show) 
    {
        case BUSINESS_BUYPOINT_LIST:
        {
            new message[3000];

            format(message, sizeof(message), ""YELLOW"< Buat Buypoint Baru >\n");
            Loop(i, MAX_BUSINESS_BUYPOINT)
            {
                if(businessbuypointInfo[businessid][i][businessbuypointExist] == true)
                {
                    format(message, sizeof(message), "%s"WHITE"Buypoint %d\t"WHITE"%.2f, %.2f, %.2f\n", message, i, businessbuypointInfo[businessid][i][businessbuypointPositionX], businessbuypointInfo[businessid][i][businessbuypointPositionY], businessbuypointInfo[businessid][i][businessbuypointPositionZ]);
                }
            }
            Dialog_Show(playerid, BusinessBuyPoint_List, DIALOG_STYLE_TABLIST, "Business Buy Point", message, "Pilih", "Tutup");
        }
        case BUSINESS_BUYPOINT_DELETE:
        {
            Dialog_Show(playerid, BusinessBuyPoint_Delete, DIALOG_STYLE_MSGBOX, "Delete Business Buy Point", va_return(""WHITE"Yakin anda akan menghapus "LR"business buypoint %d"WHITE"?", player_buypoint_deleteid[playerid]), "Pilih", "Tutup");
        }
        case BUSINESS_BUYPOINT_CREATE:
        {
            new Float:x, Float:y, Float:z, interior, world, id;
            GetPlayerPos(playerid, x, y, z);
            interior = GetPlayerInterior(playerid);
            world = GetPlayerVirtualWorld(playerid);

            id = CreateBusinessBuyPoint(businessid, interior, world, x, y, z);
            SendClientMessageEx(playerid, COLOR_REN, "BUSINESS-BUYPOINT: "WHITE"Anda telah membuat business "YELLOW"buypoint %d", id);
            CreateBusinessLog(businessid, "Admin "RED"%s"WHITE" membuat buypoint bisnis %d", GetAdminName(playerid), id);
        }
    }

    player_buypoint_businessid[playerid] = businessid;
    return 1;
}

Dialog:BusinessBuyPoint_List(playerid, response, listitem, inputtext) 
{
    if(!response) return 1;
    else 
    {
        if(listitem == 0)
        {
            new businessid = player_buypoint_businessid[playerid];
            ShowPlayerBusinessBuypoint(playerid, businessid, BUSINESS_BUYPOINT_CREATE);
        }
        else 
        {
            new businessid = player_buypoint_businessid[playerid];
            listitem = listitem - 1;
            
            player_buypoint_deleteid[playerid] = listitem;
            ShowPlayerBusinessBuypoint(playerid, businessid, BUSINESS_BUYPOINT_DELETE);
        }
    }
    return 1;
}

Dialog:BusinessBuyPoint_Delete(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    else 
    {
        new businessid = player_buypoint_businessid[playerid], buypointid = player_buypoint_deleteid[playerid];
        DeleteBusinessBuyPoint(businessid, buypointid);
        SendClientMessageEx(playerid, COLOR_REN, "BUSINESS-BUYPOINT: "WHITE"Anda telah menghapus "LR"buypoint %d", buypointid);
        CreateBusinessLog(businessid, "Admin "RED"%s"WHITE" menghapus "LR"buypoint %d", GetAdminName(playerid), buypointid);
    }
    return 1;
}