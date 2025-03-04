#define MAX_DEALERSHIP 50
#define MAX_DEALERSHIP_NAME 45
#define MAX_DEALERSHIP_VEHICLEMODEL 10

enum DEALERSHIP
{
    dealershipOwner[MAX_PLAYER_NAME],
    dealershipName[MAX_DEALERSHIP_NAME],
    dealershipMoney,
    dealershipPrice,
    bool:dealershipLocked,
    Float:dealershipPositionX,
    Float:dealershipPositionY,
    Float:dealershipPositionZ,
    Float:dealershipSpawnPositionX,
    Float:dealershipSpawnPositionY,
    Float:dealershipSpawnPositionZ,
    Float:dealershipSpawnPositionA,
    dealershipVehicleModel[MAX_DEALERSHIP_VEHICLEMODEL],

    /* Unsaved */
    dealershipPickup,
    Text3D:dealershipLabel,
}
new dealershipInfo[MAX_DEALERSHIP][DEALERSHIP],
    Iterator:Dealership<MAX_DEALERSHIP>;

new player_editdealer_id[MAX_PLAYERS],
    bool:player_editdealer_position[MAX_PLAYERS],
    bool:player_editdealer_vehposition[MAX_PLAYERS],
    player_editdealer_vmodelslot[MAX_PLAYERS];
    
/* For dealership vehpos */
new 
    bool:player_editdealer_vehposloc[MAX_PLAYERS],
    bool:player_editdealer_cvehposloc[MAX_PLAYERS],
    player_editdealer_vehposid[MAX_PLAYERS],
    
    player_buyveh_dealerid[MAX_PLAYERS],
    player_buyveh_dealervehposid[MAX_PLAYERS];
    
enum 
{
    DEALERSHIP_EDIT_LIST,
    DEALERSHIP_EDIT_OWNER,
    DEALERSHIP_EDIT_NAME,
    DEALERSHIP_EDIT_MONEY,
    DEALERSHIP_EDIT_PRICE,
    DEALERSHIP_EDIT_LOCKED,
    DEALERSHIP_EDIT_POSITION,
    DEALERSHIP_EDIT_DELETE,
    DEALERSHIP_EDIT_VEHICLEMODEL,
    DEALERSHIP_EDIT_SPAWNPOSITION,
}

/* Veh Pos */
#define MAX_DEALERSHIP_VEHPOS 10
enum DEALERSHIP_VEHPOS
{
    dealershipvehposDBID,

    bool:dealershipvehposExist,
    Float:dealershipvehposPositionX,
    Float:dealershipvehposPositionY,
    Float:dealershipvehposPositionZ,
    Float:dealershipvehposPositionA,
    dealershipvehposModel,
    dealershipvehposPrice,

    dealershipvehposID,
    dealershipvehposPickup,
    Text3D:dealershipvehposLabel,
}
new dealershipvehposInfo[MAX_DEALERSHIP][MAX_DEALERSHIP_VEHPOS][DEALERSHIP_VEHPOS];

enum 
{
    DEALERSHIP_VEHPOS_EDITLIST,
    DEALERSHIP_VEHPOS_EDITMENU,
    DEALERSHIP_VEHPOS_EDITPOS,
    DEALERSHIP_VEHPOS_EDITMODEL,
    DEALERSHIP_VEHPOS_EDMODEL_CONF,
    DEALERSHIP_VEHPOS_EDITPRICE,
    DEALERSHIP_VEHPOS_EDITDELETE,
}