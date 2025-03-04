#define MAX_SWEEPER_MARK 100
enum SWEEPER_MARK 
{
    sweepermarkDBID,

    bool:sweepermarkExist,
    sweepermarkRouteID,
    
    Float:sweepermarkLocationX,
    Float:sweepermarkLocationY,
    Float:sweepermarkLocationZ,
}
new sweepermarkInfo[MAX_SWEEPER_ROUTE][MAX_SWEEPER_MARK][SWEEPER_MARK],
    player_sweepermark_routeid[MAX_PLAYERS],
    bool:player_sweepermark_editmode[MAX_PLAYERS],
    player_sweepermark_step[MAX_PLAYERS];