new 
    bool:player_create_mecharea_status[MAX_PLAYERS],
    Float:player_create_mecharea[MAX_PLAYERS][2][3],
    player_create_mecharea_pickup[MAX_PLAYERS][2],
    Text3D:player_create_mecharea_label[MAX_PLAYERS][2];

#define MAX_MECHANIC_AREA 100
enum MECHANIC_AREA
{
    mechanicareaDBID,
    Float:mechanicareaFrom[2],
    Float:mechanicareaTo[2],
    mechanicareaID,
}
new mechanicareaInfo[MAX_MECHANIC_AREA][MECHANIC_AREA],
    Iterator:MechanicArea<MAX_MECHANIC_AREA>;

