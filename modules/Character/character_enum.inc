#include <YSI_Coding\y_hooks>

#define MAX_PLAYER_CHARACTER 5
enum PLAYER_CHARACTERS
{
    bool:playercharacterExist,
    playercharacterName[MAX_PLAYER_NAME + 1],
    playercharacterLevel,
    playercharacterSkin,
    playercharacterMoney,
    playercharacterGender,
    Timestamp:playercharacterLastSeen,
    Float:playercharacterLastSeenPosX,
    Float:playercharacterLastSeenPosY,
    Float:playercharacterLastSeenPosZ,

    Float:playerHealth,
    Float:playerArmour, 
    playerVirtualWorld,
    playerInterior,
}
new playercharacterInfo[MAX_PLAYERS][MAX_PLAYER_CHARACTER][PLAYER_CHARACTERS];

