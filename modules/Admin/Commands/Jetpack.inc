YCMD:jetpack(playerid, params[], help)
{
    if(!IsPlayerAdmin(playerid, Volunteer))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");

    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USEJETPACK);
    SendClientMessageEx(playerid, COLOR_REN, "JETPACK: "WHITE"Anda sekarang telah menggunakan "YELLOW"jetpack");
    return 1;
}