/*

==> Editing Object (Function)
Contains Function for the editing object system.

Credit: Rndwst
Created On: 13 January 2023

*/

function EditObject_MakeTextdraw(playerid)
{
    ObjectEdit_LoadTextdraw(playerid);
    return 1;
}

stock ShowPlayerEditObjectPosition(playerid, action, objectid, const info[] = " ")
{
    new Float:x, Float:y, Float:z,
        Float:rx, Float:ry, Float:rz;

    player_editobject_action[playerid] = action;
    player_editobject_objectid[playerid] = objectid;

    GetDynamicObjectPos(objectid, x, y, z);
    GetDynamicObjectRot(objectid, rx, ry, rz);

    player_editobject_defaultposx[playerid] = x;
    player_editobject_defaultposy[playerid] = y;
    player_editobject_defaultposz[playerid] = z;
    player_editobject_defaultrotx[playerid] = rx;
    player_editobject_defaultroty[playerid] = ry;
    player_editobject_defaultrotz[playerid] = rz;
    player_editobject_posx[playerid] = x;
    player_editobject_posy[playerid] = y;
    player_editobject_posz[playerid] = z;
    player_editobject_rotx[playerid] = rx;
    player_editobject_roty[playerid] = ry;
    player_editobject_rotz[playerid] = rz;

    PlayerTextDrawSetString(playerid, editobject_Information[playerid], info);
    ObjectEdit_ShowTextdraw(playerid);
    return 1;
}

stock ShowEditObjectSetCoord(playerid, coord)
{
    player_editobject_setcoord[playerid] = coord;

    new message[3000];
    if(coord == EDITOBJECT_COORDX) format(message, sizeof(message), "Masukkan kordinat X untuk menggantikan\nKordinat saat ini: %0.4f", player_editobject_posx[playerid]);
    if(coord == EDITOBJECT_COORDY) format(message, sizeof(message), "Masukkan kordinat Y untuk menggantikan\nKordinat saat ini: %0.4f", player_editobject_posy[playerid]);
    if(coord == EDITOBJECT_COORDZ) format(message, sizeof(message), "Masukkan kordinat Z untuk menggantikan\nKordinat saat ini: %0.4f", player_editobject_posz[playerid]);
    if(coord == EDITOBJECT_COORDRX) format(message, sizeof(message), "Masukkan kordinat RX untuk menggantikan\nKordinat saat ini: %0.4f", player_editobject_rotx[playerid]);
    if(coord == EDITOBJECT_COORDRY) format(message, sizeof(message), "Masukkan kordinat RY untuk menggantikan\nKordinat saat ini: %0.4f", player_editobject_roty[playerid]);
    if(coord == EDITOBJECT_COORDRZ) format(message, sizeof(message), "Masukkan kordinat RZ untuk menggantikan\nKordinat saat ini: %0.4f", player_editobject_rotz[playerid]);
    Dialog_Show(playerid, EditingObject_SetCoord, DIALOG_STYLE_INPUT, "Edit Object Coordinate", message, "Edit", "Close");
    return 1;
}

stock UpdateEditObjectPosition(playerid)
{
    new objectid = player_editobject_objectid[playerid];
    SetDynamicObjectPos(objectid, player_editobject_posx[playerid], player_editobject_posy[playerid], player_editobject_posz[playerid]);
    SetDynamicObjectRot(objectid, player_editobject_rotx[playerid], player_editobject_roty[playerid], player_editobject_rotz[playerid]);
    ObjectEdit_ShowTextdraw(playerid);

    new response_fix = EDIT_RESPONSE_UPDATE;
    CallRemoteFunction("OnEditObjectResponse", "iiiiffffff", playerid, player_editobject_action[playerid], response_fix, player_editobject_objectid[playerid], player_editobject_posx[playerid], player_editobject_posy[playerid], player_editobject_posz[playerid], player_editobject_rotx[playerid], player_editobject_roty[playerid], player_editobject_rotz[playerid]);
    return 1;
}

stock SetEditObjectDefaultPosition(playerid)
{
    new objectid = player_editobject_objectid[playerid];
    SetDynamicObjectPos(objectid, player_editobject_defaultposx[playerid], player_editobject_defaultposy[playerid], player_editobject_defaultposz[playerid]);
    SetDynamicObjectRot(objectid, player_editobject_defaultrotx[playerid], player_editobject_defaultroty[playerid], player_editobject_defaultrotz[playerid]);
    return 1;
}