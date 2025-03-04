#include <YSI_Coding\y_hooks>

stock AddHungryLevel(playerid, Float:add)
{
    if(playerInfo[playerid][playerHungry] + add > 100.0) playerInfo[playerid][playerHungry] = 100.0;
    else if(playerInfo[playerid][playerHungry] + add <= 0) playerInfo[playerid][playerHungry] = 0.0;
    else playerInfo[playerid][playerHungry] = playerInfo[playerid][playerHungry] + add;
    return 1;
}

stock SetPlayerHungryLevel(playerid, Float:level)
{
    AddHungryLevel(playerid, -playerInfo[playerid][playerHungry]);
    AddHungryLevel(playerid, level);
    return 1;
}

YCMD:sethungrylevel(playerid, params[], help) 
{
    if(!IsPlayerAdmin(playerid, Admin1))
        return SendErrorMessage(playerid, "Kamu tidak memiliki akses untuk menggunakan command ini!");

    new toplayer, Float:amount;
    if(sscanf(params, "df", toplayer, amount))
        return SendUsageMessage(playerid, "/sethungrylevel [playerid / username] [Float:level]");

    if(!IsPlayerSpawned(playerid))
        return SendErrorMessage(playerid, "Player tidak terdeteksi!");

    SetPlayerHungryLevel(toplayer, amount);

    SendClientMessageEx(playerid, COLOR_REN, "THRIST: "WHITE"Kamu mengubah level hungry player "YELLOW"%s"WHITE" menjadi %f%", RemoveUnderscore(playerInfo[toplayer][playerName]), amount);
    SendClientMessageEx(toplayer, COLOR_REN, "THRIST: "WHITE"Admin "LR"%s"WHITE" mengubah level hungry kamu menjadi %f%", GetAdminName(playerid), amount);
    return 1;
}

hook OneSecond()
{
    foreach(new i : Player) 
    {
        if(IsPlayerSpawned(i))
        {
            if(playerInfo[i][playerHungry] > 0.0)
            {
                playerInfo[i][playerHungry] -= 0.008;
            }
        }
    }
    return 1;
}