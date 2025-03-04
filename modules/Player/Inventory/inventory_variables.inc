#define MAX_PLAYER_INVENTORY 50
enum PLAYER_INVENTORY
{
    bool:pinventoryExist,
    pinventoryDBID,
    
    pinventoryAmount,
    pinventoryType,

}
new pinventoryInfo[MAX_PLAYERS][MAX_PLAYER_INVENTORY][PLAYER_INVENTORY];