/*

==> Gate (Variable)
Contains variables for the gate system.

Credit: Rndwst
Created On: 14 January 2023

*/

#define MAX_GATE 1000
enum GATE
{
    gateOwnerType,
    gateOwnerName[120],
    gatePassword[8],
    gateModel,
    gatePrice,
    gateInterior,
    gateVirtualWorld,

    Float:gatePositionX,
    Float:gatePositionY,
    Float:gatePositionZ,
    Float:gateRotationX,
    Float:gateRotationY,
    Float:gateRotationZ,
    Float:gateMovePositionX,
    Float:gateMovePositionY,
    Float:gateMovePositionZ,
    Float:gateMoveRotationX,
    Float:gateMoveRotationY,
    Float:gateMoveRotationZ,
    Float:gateSpeed,

    // Unsaved
    gateStatus,
    gateObject
}
new gateInfo[MAX_GATE][GATE],
    Iterator: Gate<MAX_GATE>;

enum // Gate Owner Type
{
    GATEOWNER_PUBLIC,
    GATEOWNER_PLAYER,
    GATEOWNER_FACTION,
    GATEOWNER_TOLL,
}
new ownertypeString[][] = {
    "Public", "Player", "Faction", "Toll"
};

enum // Gate Editing
{
    GATEEDIT_LIST,
    GATEEDIT_OWNERTYPE,
    GATEEDIT_OWNERPLAYER,
    GATEEDIT_OWNERFACTION,
    GATEEDIT_PASSWORD,
    GATEEDIT_MODEL,
    GATEEDIT_PRICE,
    GATEEDIT_POSITION,
    GATEEDIT_MOVEPOSITION,
}

enum // Gate Status
{
    GATESTATUS_CLOSED,
    GATESTATUS_MOVECLOSE,
    GATESTATUS_OPENED,
    GATESTATUS_MOVEOPEN,
}