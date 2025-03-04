#define MAX_SWEEPER_ROUTE 10
#define MAX_SWEEPER_ROUTE_NAME 20
#define SWEEPER_ROUTE_USED 1
#define SWEEPER_ROUTE_UNUSED 0

enum SWEEPER_ROUTE 
{
    sweeperrouteName[MAX_SWEEPER_ROUTE_NAME],
    sweeperrouteSalary,
    Float:sweeperrouteLocationX,
    Float:sweeperrouteLocationY,
    Float:sweeperrouteLocationZ,

    // Unsaved
    sweeperrouteStatus
}
new sweeperrouteInfo[MAX_SWEEPER_ROUTE][SWEEPER_ROUTE],
    Iterator:SweeperRoute<MAX_SWEEPER_ROUTE>;

new Float:player_createsweeperroute_loc[MAX_PLAYERS][3],
    player_createsweeperroute_gaji[MAX_PLAYERS],
    player_createsweeperroute_name[MAX_PLAYERS][MAX_SWEEPER_ROUTE_NAME],
    
    player_editsweeperroute_id[MAX_PLAYERS],
    player_editsweeperroute_name[MAX_PLAYERS][MAX_SWEEPER_ROUTE_NAME],
    player_editsweeperroute_gaji[MAX_PLAYERS],
    Float:player_editsweeperroute_loc[MAX_PLAYERS][3],
    bool:player_editingsweeperroute_loc[MAX_PLAYERS],
    
    player_startsweeperroute_id[MAX_PLAYERS],
    player_startsweeperroute_vehid[MAX_PLAYERS];