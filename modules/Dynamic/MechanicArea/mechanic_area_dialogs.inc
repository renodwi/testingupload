stock ShowPlayerMechanicAreaList(playerid) 
{
    new message[3000];
    format(message, sizeof(message), "ID\tFrom X\tFrom Y\tTo X\tTo Y\n");
    foreach(new i : MechanicArea) 
    {
        if(Iter_Contains(MechanicArea, i))
        {
            format(message, sizeof(message), "%s%d\t%f\t%f\t%f\t%f\n", message, i, mechanicareaInfo[i][mechanicareaFrom][0], mechanicareaInfo[i][mechanicareaFrom][1], mechanicareaInfo[i][mechanicareaTo][0], mechanicareaInfo[i][mechanicareaTo][1]);
        }
    }
    Dialog_Show(playerid, MehcanicArea_List, DIALOG_STYLE_TABLIST_HEADERS, "Mechanic Area", message, "Pilih", "Tutup");
    return 1;
}

Dialog:MehcanicArea_List(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    else
    {
        if(!Iter_Contains(MechanicArea, listitem)) return 1;
        else
        {
            new Float:x_mid = (mechanicareaInfo[listitem][mechanicareaFrom][0] + mechanicareaInfo[listitem][mechanicareaTo][0]) / 2,
                Float:y_mid = (mechanicareaInfo[listitem][mechanicareaFrom][1] + mechanicareaInfo[listitem][mechanicareaTo][1]) / 2;

            SetPlayerPosFindZ(playerid, x_mid, y_mid, 1000.0);
            SetPlayerVirtualWorld(playerid, 0);
            SetPlayerInterior(playerid, 0);
            
            SendClientMessageEx(playerid, COLOR_REN, "MECHANIC-AREA: "WHITE"Anda telah teleportasi ke "YELLOW"mekanik %d", listitem);
        }
    }
    return 1;
}