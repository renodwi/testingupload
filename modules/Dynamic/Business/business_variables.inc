#define MAX_BUSINESS 200
#define MAX_BUSINESS_NAME 200
#define MAX_BUSINESS_RADIOURL 200

enum BUSINESS
{
	businessOwner[MAX_PLAYER_NAME],
	businessName[MAX_BUSINESS_NAME],
	businessPrice,
	businessLocked,
	businessType,
	businessMoney,
	businessInteriorID,
    businessRadio[100],

	Float:businessExteriorX,
	Float:businessExteriorY,
	Float:businessExteriorZ,
	Float:businessExteriorA,
	Float:businessInteriorX,
	Float:businessInteriorY,
	Float:businessInteriorZ,
	Float:businessInteriorA,

	Float:businessFuelAmount,
	businessFuelPrice,
	// Un Saved //
	businessEnterPickup,
	Text3D:businessEnterLabel,
    businessEnterCheckpoint,
	businessExitPickup,
    businessExitCheckpoint,

    bool:businessExist
}
new businessInfo[MAX_BUSINESS][BUSINESS],
    Iterator: Business<MAX_BUSINESS>;

new BusinessTypeName[][] = { 
	"Minimarket",
	"Gym",
	"Clothes Store",
	"Restaurant",
	"Electronic Store",
	"Sport Store",
    "Furniture Store"
};

enum // BUSINESS TYPE
{
    BUSINESS_MINIMARKET,
    BUSINESS_GYM,
    BUSINESS_CLOTHES,
    BUSINESS_RESTAURANT,
    BUSINESS_ELECTRONIC,
    BUSINESS_SPORT,
    BUSINESS_FURNITURE
}

enum // Admin Edit Business
{
	EDIT_BUSINESS_LIST,
	EDIT_BUSINESS_OWNER,
	EDIT_BUSINESS_NAME,
	EDIT_BUSINESS_PRICE,
	EDIT_BUSINESS_LOCKED,
	EDIT_BUSINESS_TYPE,
	EDIT_BUSINESS_MONEY,
	EDIT_BUSINESS_RADIO,
	EDIT_BUSINESS_EXTERIORPOS,
	EDIT_BUSINESS_INTERIORPOS,
	EDIT_BUSINESS_FUEL,
	EDIT_BUSINESS_FUELPRICE,
}

enum // Player Edit Business
{
	BUSINESS_MENU_BUY,

	BUSINESS_MENU_LIST,
	BUSINESS_MENU_NAME,
	BUSINESS_MENU_LOCKED,
	BUSINESS_MENU_MONEY,
	BUSINESS_MENU_RADIO,
}

new player_edit_business[MAX_PLAYERS];
new player_buybusiness_id[MAX_PLAYERS];
new player_businessmenu_id[MAX_PLAYERS];