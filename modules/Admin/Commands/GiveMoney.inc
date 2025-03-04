#include <YSI_Coding\y_hooks>

YCMD:givemoney(playerid, params[], help) 
{
    if(!IsPlayerAdmin(playerid, Developer))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");

    new toplayer, money_string[50];
    if(sscanf(params, "us[50]", toplayer, money_string))
        return SendUsageMessage(playerid, "/givemoney [player name / player id] [money (support money format)]");

    if(!IsMoneyFormat(money_string))
        return SendErrorMessage(playerid, "Masukkan input dengan tipe uang!");

    if(!IsPlayerSpawned(toplayer))
        return SendErrorMessage(playerid, "Player tujuan tidak terdeteksi");
    
    new money = StringToMoney(money_string);
    SendClientMessageEx(toplayer, COLOR_REN, "MONEY: "WHITE"Admin "LR"%s"WHITE" telah memberi uang anda sebesar "LG"$%s", GetAdminName(playerid), FormatMoney(money));
    SendClientMessageEx(playerid, COLOR_REN, "MONEY: "WHITE"Anda memberi uang kepada "YELLOW"%s"WHITE" sebesar "LG"$%s", RemoveUnderscore(playerInfo[toplayer][playerName]), FormatMoney(money));

    GivePlayerMoney(toplayer, money);
    return 1;
}