#define MAX_GAS_PUMP 500

enum GAS_PUMP 
{
	gaspumpBusinessID,
    Float:gaspumpPositionX,
    Float:gaspumpPositionY,
    Float:gaspumpPositionZ,
    Float:gaspumpRotationX,
    Float:gaspumpRotationY,
    Float:gaspumpRotationZ,
    gaspumpWorld,
    gaspumpInterior,

    // Unsaved
	gaspumpObject,
	Text3D:gaspumpLabel
}
new gaspumpInfo[MAX_GAS_PUMP][GAS_PUMP],
    Iterator:GasPump<MAX_GAS_PUMP>;

new player_edit_gaspumpid[MAX_PLAYERS],

    player_buy_fuel_businessid[MAX_PLAYERS],
    player_buy_fuel_vehicleid[MAX_PLAYERS];