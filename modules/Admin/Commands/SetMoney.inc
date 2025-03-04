#include <YSI_Coding\y_hooks>

YCMD:setmoney(playerid, params[], help) 
{
    if(!IsPlayerAdmin(playerid, Developer))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");

    new toplayer, money_string[50];
    if(sscanf(params, "us[50]", toplayer, money_string))
        return SendUsageMessage(playerid, "/setmoney [player name / player id] [money (support money format)]");

    if(!IsMoneyFormat(money_string))
        return SendErrorMessage(playerid, "Masukkan input dengan tipe uang!");

    if(!IsPlayerSpawned(toplayer))
        return SendErrorMessage(playerid, "Player tujuan tidak terdeteksi");
    
    new money = StringToMoney(money_string);
    SendClientMessageEx(toplayer, COLOR_REN, "SET-MONEY: "WHITE"Admin "LR"%s"WHITE" telah mengatur uang anda menjadi "LG"$%s", GetAdminName(playerid), FormatMoney(money));
    SendClientMessageEx(playerid, COLOR_REN, "SET-MONEY: "WHITE"Anda telah mengatur uang "YELLOW"%s"WHITE" menjadi "LG"$%s", RemoveUnderscore(playerInfo[toplayer][playerName]), FormatMoney(money));

    GivePlayerMoney(toplayer, -playerInfo[toplayer][playerMoney]);
    GivePlayerMoney(toplayer, money);
    return 1;
}