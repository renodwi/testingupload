YCMD:id(playerid, params[])
{
    new toplayer;
    if(sscanf(params, "u", toplayer))
        return SendErrorMessage(playerid, "/id [player name / playerid]");

    if(!IsPlayerSpawned(toplayer))
        return SendErrorMessage(playerid, "Player tidak terdeteksi!");
    
    SendClientMessageEx(playerid, COLOR_REN, "FITUR BELUM SELESAI DIBUAT");
    return 1;
}