#define MAX_EDITING_OBJECT                  1000
#define MAX_OBJECT_MATERIAL_SLOT	        10

#define OBJECT_MATERIAL_TYPE_NONE		    0
#define OBJECT_MATERIAL_TYPE_TEXTURE	    1
#define OBJECT_MATERIAL_TYPE_MESSAGE	    2

#define OBJECT_SELECT_EDITOR	1
#define OBJECT_SELECT_DELETE	2
#define OBJECT_SELECT_PAINT		3
#define OBJECT_SELECT_CLEAN		4

new Iterator:DynamicObjects<MAX_EDITING_OBJECT>;
new DynamicObject[MAX_EDITING_OBJECT];
new Text3D:DynamicObjectLabel[MAX_EDITING_OBJECT];
new DynamicObjectMaterial[MAX_EDITING_OBJECT][MAX_OBJECT_MATERIAL_SLOT];
new EditDynamicObjectMode[MAX_PLAYERS];
new ObjectEditor[MAX_EDITING_OBJECT];
new player_editing_object_id[MAX_PLAYERS];
new player_editing_object_index[MAX_PLAYERS];

// create remove clear clone x y z rx ry rz edit select goto gethere
// model material textprop resetmaterial deletemode paintbrush cleanbrush 

new const WinFonts[15][20] = {
    {"Arial"},
    {"Calibri"},
    {"Comic Sans MS"},
    {"Georgia"},
    {"Times New Roman"},
    {"Consolas"},
    {"Constantia"},
    {"Corbel"},
    {"Courier New"},
    {"Impact"},
    {"Lucida Console"},
    {"Palatino Linotype"},
    {"Tahoma"},
    {"Trebuchet MS"},
    {"Verdana"}
};

#define MAX_REMOVED_OBJECT                  1000

enum REMOVED_OBJECT
{
    removeobjectModel,
    Float:removeobjectPositionX,
    Float:removeobjectPositionY,
    Float:removeobjectPositionZ,
    Float:removeobjectRadius,
}
new removeobjectInfo[MAX_REMOVED_OBJECT][REMOVED_OBJECT],
    Iterator:RemoveObject<MAX_REMOVED_OBJECT>;