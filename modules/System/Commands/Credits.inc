YCMD:credits(playerid, params[], help)
{
    new message[1200];
    format(message, sizeof(message), "%sIndonesische Roleplay\n", message);
    format(message, sizeof(message), "%s\n", message);
    format(message, sizeof(message), "%s* Kalcor (Kye) SAMP Developer\n", message);
    format(message, sizeof(message), "%s* Y_Less (sscanf, YSI, dan fungsi lainnya)\n", message);
    format(message, sizeof(message), "%s* BlueG, maddinat0r (a_mysql plugin)\n", message);
    format(message, sizeof(message), "%s* Southclaw (Progressbar2, dan fungsi lainnya)\n", message);
    format(message, sizeof(message), "%s* RenoDwi (scripter)\n", message);
    format(message, sizeof(message), "%s\n", message);
    format(message, sizeof(message), "%sTerimakasih kepada %s telah bermain di server ini!\n", message, RemoveUnderscore(playerInfo[playerid][playerName]));
    Dialog_Show(playerid, Credits, DIALOG_STYLE_MSGBOX, "Credits", message, "Close", "");
    return 1;
}