#define MAX_DROPPED_ITEM 200

enum DROPPED_ITEM
{
    droppeditemType,
    Float:droppeditemPositionX,
    Float:droppeditemPositionY,
    Float:droppeditemPositionZ,
    Float:droppeditemAngle,
    droppeditemInterior,
    droppeditemWorld,
    Timestamp:droppeditemDeletedAt,
    droppeditemAmount,

    droppeditemObject,
    Text3D:droppeditemLabel,
}
new droppeditemInfo[MAX_DROPPED_ITEM][DROPPED_ITEM],
    Iterator:DroppedItem<MAX_DROPPED_ITEM>;

new player_droppeditemcreate_type[MAX_PLAYERS],
    player_droppeditemcreate_amount[MAX_PLAYERS];
    
enum 
{
    DROPPEDITEM_CREATE_TYPE,
    DROPPEDITEM_CREATE_AMOUNT,
}