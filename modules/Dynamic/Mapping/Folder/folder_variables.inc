#define MAX_MAPPING_FOLDER 1000
#define MAX_MAPPING_FOLDER_NAME 50
#define MAX_MAPPING_OBJECT 1000

enum MAPPING_FOLDER
{
    bool:mappingLoaded,
    mappingName[MAX_MAPPING_FOLDER_NAME],
    mappingCreator[MAX_PLAYER_NAME],
    Timestamp:mappingCreateAt,
    Float:mappingLocationX,
    Float:mappingLocationY,
    Float:mappingLocationZ,
    mappingInterior,
    mappingWorld,
    mappingObjectTotal,
    mappingRemovedObjectTotal,
}
new mappingInfo[MAX_MAPPING_FOLDER][MAPPING_FOLDER],
    Iterator:MappingFolder<MAX_MAPPING_FOLDER>;

new ObjectIDFromMappingFolder[MAX_MAPPING_FOLDER][MAX_MAPPING_OBJECT];
new player_delete_mappingname[MAX_PLAYERS][MAX_MAPPING_FOLDER_NAME];