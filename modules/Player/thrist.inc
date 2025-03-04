#include <YSI_Coding\y_hooks>

stock AddThristLevel(playerid, Float:add)
{
    if(playerInfo[playerid][playerThrist] + add > 100.0) playerInfo[playerid][playerThrist] = 100.0;
    else if(playerInfo[playerid][playerThrist] + add <= 0) playerInfo[playerid][playerThrist] = 0.0;
    else playerInfo[playerid][playerThrist] = playerInfo[playerid][playerThrist] + add;
    return 1;
}

stock SetPlayerThristLevel(playerid, Float:level)
{
    AddThristLevel(playerid, -playerInfo[playerid][playerThrist]);
    AddThristLevel(playerid, level);
    return 1;
}

YCMD:setthristlevel(playerid, params[], help) 
{
    if(!IsPlayerAdmin(playerid, Admin1))
        return SendErrorMessage(playerid, "Kamu tidak memiliki akses untuk menggunakan command ini!");

    new toplayer, Float:amount;
    if(sscanf(params, "df", toplayer, amount))
        return SendUsageMessage(playerid, "/setthristlevel [playerid / username] [Float:level]");

    if(!IsPlayerSpawned(playerid))
        return SendErrorMessage(playerid, "Player tidak terdeteksi!");

    SetPlayerThristLevel(toplayer, amount);

    SendClientMessageEx(playerid, COLOR_REN, "THRIST: "WHITE"Kamu mengubah level thrist player "YELLOW"%s"WHITE" menjadi %f\%", RemoveUnderscore(playerInfo[toplayer][playerName]), amount);
    SendClientMessageEx(toplayer, COLOR_REN, "THRIST: "WHITE"Admin "LR"%s"WHITE" mengubah level thrist kamu menjadi %f\%", GetAdminName(playerid), amount);
    return 1;
}

hook OneSecond()
{
    foreach(new i : Player) 
    {
        if(IsPlayerSpawned(i))
        {
            if(playerInfo[i][playerThrist] > 0.0)
            {
                playerInfo[i][playerThrist] -= 0.009;
            }
            
        }
    }
    return 1;
}