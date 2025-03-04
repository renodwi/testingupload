stock ShowPlayerHudMenu(playerid)
{
    new message[2000];
    format(message, sizeof(message), "%s"WHITE"Hud Status\t%s\n", message, player_hud_status[playerid] ? ""LG"Shown" : ""RED"Hidden");
    format(message, sizeof(message), "%s"WHITE"Hud Mode\t%s\n", message, GetHudModeName(playerInfo[playerid][playerHudMode]));
    Dialog_Show(playerid, Hud_Menu, DIALOG_STYLE_TABLIST, "Hud", message, "Pilih", "Tutup");
    return 1;
}

Dialog:Hud_Menu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    else 
    {
        switch(listitem) 
        {
            case 0:
            {
                if(player_hud_status[playerid] == true) SetPlayerHudStatus(playerid, false);
                else SetPlayerHudStatus(playerid, true);
            }
            case 1:
            {
                new message[200];
                Loop(i, sizeof(hud_name))
                {
                    if(!strcmp(GetHudModeName(i), GetHudModeName(GetPlayerHudMode(playerid)), true)) 
                    {
                        format(message, sizeof(message), "%s"LG"%s (aktif)\n", message, GetHudModeName(i));
                    }
                    else
                    {
                        format(message, sizeof(message), "%s"WHITE"%s\n", message, GetHudModeName(i));
                    }
                    Dialog_Show(playerid, Hud_ModeList, DIALOG_STYLE_LIST, "Hud", message, "Pilih", "Tutup");
                }
            }
        }
    }
    return 1;
}

Dialog:Hud_ModeList(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    else 
    {
        playerInfo[playerid][playerHudMode] = listitem;
    }
    return 1;
}