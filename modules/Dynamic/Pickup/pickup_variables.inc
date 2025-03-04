#define MAX_PICKUP_NAME 100
#define MAX_PICKUP_DESCRIPTION 250

enum PICKUP
{
    pickupModel,
    pickupType,
    Float:pickupPositionX,
    Float:pickupPositionY,
    Float:pickupPositionZ,
    pickupWorld,
    pickupInterior,

    // Unsaved
    pickupID,
    Text3D:pickupLabel,
}
new pickupInfo[MAX_PICKUPS][PICKUP],
    Iterator:Pickup<MAX_PICKUPS>;

new player_createpickup_model[MAX_PLAYERS];

enum
{
    PICKUPTYPE_SELLFISH,
    PICKUPTYPE_JOINJOB_MECHANIC
}
enum E_PICKUPINFO
{
    e_pickupname[50],
    e_pickupdescription[250],
}
new e_pickupinfo[][E_PICKUPINFO] = {
    {"Pelelangan Ikan", "Jual ikan, klik "LR"N"WHITE" atau gunakan command /sellfish"},
    {"Pekerjaan Mekanik", "Gabung pekerjaan mekanik, klik "LR"N"WHITE" atau gunakan command /joinjob"}
};  