/*

==> Editing Object (Variable)
Contains Variable for the editing object system.

Credit: Rndwst
Created On: 13 January 2023

*/

#include <YSI_CODING\y_hooks>

enum 
{
    EDITOBJECT_COORDX,
    EDITOBJECT_COORDY,
    EDITOBJECT_COORDZ,
    EDITOBJECT_COORDRX,
    EDITOBJECT_COORDRY,
    EDITOBJECT_COORDRZ
}

// ------------------ Player Variabel
new player_editobject_action[MAX_PLAYERS];
new player_editobject_objectid[MAX_PLAYERS];
new Float:player_editobject_defaultposx[MAX_PLAYERS];
new Float:player_editobject_defaultposy[MAX_PLAYERS];
new Float:player_editobject_defaultposz[MAX_PLAYERS];
new Float:player_editobject_defaultrotx[MAX_PLAYERS];
new Float:player_editobject_defaultroty[MAX_PLAYERS];
new Float:player_editobject_defaultrotz[MAX_PLAYERS];
new Float:player_editobject_posx[MAX_PLAYERS];
new Float:player_editobject_posy[MAX_PLAYERS];
new Float:player_editobject_posz[MAX_PLAYERS];
new Float:player_editobject_rotx[MAX_PLAYERS];
new Float:player_editobject_roty[MAX_PLAYERS];
new Float:player_editobject_rotz[MAX_PLAYERS];
new player_editobject_setcoord[MAX_PLAYERS];

// ------------------ Textdraw Variabel
new PlayerText:editobject_editpos_forpc[MAX_PLAYERS];
new PlayerText:editobject_Confirm[MAX_PLAYERS];
new PlayerText:editobject_Cancel[MAX_PLAYERS];
new PlayerText:editobject_X_Coordinate[MAX_PLAYERS];
new PlayerText:editobject_RX_Coordinate[MAX_PLAYERS];
new PlayerText:editobject_Y_Coordinate[MAX_PLAYERS];
new PlayerText:editobject_Z_Coordinate[MAX_PLAYERS];
new PlayerText:editobject_RY_Coordinate[MAX_PLAYERS];
new PlayerText:editobject_RZ_Coordinate[MAX_PLAYERS];
new PlayerText:editobject_X_X[MAX_PLAYERS];
new PlayerText:editobject_Y_Y[MAX_PLAYERS];
new PlayerText:editobject_Z_Z[MAX_PLAYERS];
new PlayerText:editobject_RZ_Rz[MAX_PLAYERS];
new PlayerText:editobject_RY_Ry[MAX_PLAYERS];
new PlayerText:editobject_RX_Rx[MAX_PLAYERS];
new PlayerText:editobject_X_Right[MAX_PLAYERS];
new PlayerText:editobject_Y_Right[MAX_PLAYERS];
new PlayerText:editobject_Z_Right[MAX_PLAYERS];
new PlayerText:editobject_X_Left[MAX_PLAYERS];
new PlayerText:editobject_Y_Left[MAX_PLAYERS];
new PlayerText:editobject_Z_Left[MAX_PLAYERS];
new PlayerText:editobject_RX_Right[MAX_PLAYERS];
new PlayerText:editobject_RY_Right[MAX_PLAYERS];
new PlayerText:editobject_RZ_Right[MAX_PLAYERS];
new PlayerText:editobject_RX_Left[MAX_PLAYERS];
new PlayerText:editobject_RY_Left[MAX_PLAYERS];
new PlayerText:editobject_RZ_Left[MAX_PLAYERS];
new PlayerText:editobject_Information[MAX_PLAYERS];
new PlayerText:editobject_jika_cursor_hilang[MAX_PLAYERS];