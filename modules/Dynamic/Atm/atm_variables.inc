#define MAX_ATM 200
enum ATM
{
    Float:atmPositionX,
    Float:atmPositionY,
    Float:atmPositionZ,
    Float:atmRotationX,
    Float:atmRotationY,
    Float:atmRotationZ,
    atmWorld,
    atmInterior,

    atmObjectID
}
new atmInfo[MAX_ATM][ATM],
	Iterator: Atm<MAX_ATM>;

new player_edit_atmid[MAX_PLAYERS];