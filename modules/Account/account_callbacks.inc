#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    Loop(i, MAX_PLAYERS) 
    {
        accountInfo[i][accountIsSpawned] = false;
    }
    return 1;
}