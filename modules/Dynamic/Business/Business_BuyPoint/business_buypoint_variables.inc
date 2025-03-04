#define MAX_BUSINESS_BUYPOINT 10

enum BUSINESS_BUYPOINT 
{
    bool:businessbuypointExist,

    businessbuypointDBID,
    Float:businessbuypointPositionX,
    Float:businessbuypointPositionY,
    Float:businessbuypointPositionZ,
    businessbuypointWorld,
    businessbuypointInterior,

    // Unsaved
    Text3D:businessbuypointLabel,
    businessbuypointPickup
}
new businessbuypointInfo[MAX_BUSINESS][MAX_BUSINESS_BUYPOINT][BUSINESS_BUYPOINT];

enum 
{
    BUSINESS_BUYPOINT_LIST,
    BUSINESS_BUYPOINT_CREATE,
    BUSINESS_BUYPOINT_DELETE,
}

new player_buypoint_businessid[MAX_PLAYERS];
new player_buypoint_deleteid[MAX_PLAYERS];