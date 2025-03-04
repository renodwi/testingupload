#include <YSI_Coding\y_hooks>

enum ACCOUNT_INFO
{
    accountDBID,
    accountName[MAX_PLAYER_NAME + 1],
    accountPassword[200],
    accountEmail[200],
    accountIP[100],
    accountAdminLevel,
    accountAdminName[MAX_PLAYER_NAME + 1],
    Timestamp:accountRegisterDate,

    bool:accountIsSpawned,
}
new accountInfo[MAX_PLAYERS][ACCOUNT_INFO];