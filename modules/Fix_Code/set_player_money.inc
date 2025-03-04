#include <YSI_Coding\y_hooks>

stock SetPlayerMoney(playerid, money) 
{
    new oldmoney = 0;
    oldmoney = GetPlayerMoney(playerid);

    GivePlayerMoney(playerid, -oldmoney);
    GivePlayerMoney(playerid, money);
    return 1;
}