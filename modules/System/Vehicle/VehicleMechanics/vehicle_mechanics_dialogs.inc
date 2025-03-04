Dialog:InspectVehicle(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    else
    {
        player_hasinspectveh[playerid] = false;
        ShowPlayerLoadingBar(playerid, InspectVehicle, "Memeriksa Kondisi Mesin", Random(5000, 7000));
    }
    return 1;
}