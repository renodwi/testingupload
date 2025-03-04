/*

==> Editing Object (Callbacks)
Contains Callbacks for the editing object system.

Credit: Rndwst
Created On: 13 January 2023

*/

#include <YSI_CODING\y_hooks>

forward OnEditObjectResponse(playerid, action, response, objectid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz);

hook OnPlayerConnect(playerid)
{
    player_editobject_objectid[playerid] = -1;
    player_editobject_setcoord[playerid] = -1;
    SetTimerEx("EditObject_MakeTextdraw", 2000, false, "i", playerid);
    return 1;
} 

hook OnPlayerDisconnect(playerid, reason)
{
    ObjectEdit_DestroyTextdraw(playerid);
    return 1;
}

hook OnPlayerSelectDynObject(playerid, objectid, modelid, Float:x, Float:y, Float:z)
{
    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if(playertextid == editobject_editpos_forpc[playerid])
    {
        if(IsPlayerAndroid(playerid)) return SendErrorMessage(playerid, "Kamu bukan player PC!");
        ObjectEdit_HideTextdraw(playerid);
        EditDynamicObject(playerid, player_editobject_objectid[playerid]);
    }
    if(playertextid == editobject_X_Left[playerid]) player_editobject_posx[playerid] = player_editobject_posx[playerid] - 0.1000, UpdateEditObjectPosition(playerid);
    if(playertextid == editobject_X_Coordinate[playerid]) ShowEditObjectSetCoord(playerid, EDITOBJECT_COORDX);
    if(playertextid == editobject_X_Right[playerid]) player_editobject_posx[playerid] = player_editobject_posx[playerid] + 0.1000, UpdateEditObjectPosition(playerid);

    if(playertextid == editobject_Y_Left[playerid]) player_editobject_posy[playerid] = player_editobject_posy[playerid] - 0.1000, UpdateEditObjectPosition(playerid);
    if(playertextid == editobject_Y_Coordinate[playerid]) ShowEditObjectSetCoord(playerid, EDITOBJECT_COORDY);
    if(playertextid == editobject_Y_Right[playerid]) player_editobject_posy[playerid] = player_editobject_posy[playerid] + 0.1000, UpdateEditObjectPosition(playerid);

    if(playertextid == editobject_Z_Left[playerid]) player_editobject_posz[playerid] = player_editobject_posz[playerid] - 0.1000, UpdateEditObjectPosition(playerid);
    if(playertextid == editobject_Z_Coordinate[playerid]) ShowEditObjectSetCoord(playerid, EDITOBJECT_COORDZ);
    if(playertextid == editobject_Z_Right[playerid]) player_editobject_posz[playerid] = player_editobject_posz[playerid] + 0.1000, UpdateEditObjectPosition(playerid);

    if(playertextid == editobject_RX_Left[playerid]) player_editobject_rotx[playerid] = player_editobject_rotx[playerid] - 1.0000, UpdateEditObjectPosition(playerid);
    if(playertextid == editobject_RX_Coordinate[playerid]) ShowEditObjectSetCoord(playerid, EDITOBJECT_COORDRX);
    if(playertextid == editobject_RX_Right[playerid]) player_editobject_rotx[playerid] = player_editobject_rotx[playerid] + 1.0000, UpdateEditObjectPosition(playerid);

    if(playertextid == editobject_RY_Left[playerid]) player_editobject_roty[playerid] = player_editobject_roty[playerid] - 1.0000, UpdateEditObjectPosition(playerid);
    if(playertextid == editobject_RY_Coordinate[playerid]) ShowEditObjectSetCoord(playerid, EDITOBJECT_COORDRY);
    if(playertextid == editobject_RY_Right[playerid]) player_editobject_roty[playerid] = player_editobject_roty[playerid] + 1.000, UpdateEditObjectPosition(playerid);

    if(playertextid == editobject_RZ_Left[playerid]) player_editobject_rotz[playerid] = player_editobject_rotz[playerid] - 1.000, UpdateEditObjectPosition(playerid);
    if(playertextid == editobject_RZ_Coordinate[playerid]) ShowEditObjectSetCoord(playerid, EDITOBJECT_COORDRZ);
    if(playertextid == editobject_RZ_Right[playerid]) player_editobject_rotz[playerid] = player_editobject_rotz[playerid] + 1.000, UpdateEditObjectPosition(playerid);

    if(playertextid == editobject_Cancel[playerid]) 
    {
        ObjectEdit_HideTextdraw(playerid);

        new response = EDIT_RESPONSE_CANCEL;
        SetEditObjectDefaultPosition(playerid);
        player_editobject_posx[playerid] = player_editobject_defaultposx[playerid];
        player_editobject_posy[playerid] = player_editobject_defaultposy[playerid];
        player_editobject_posz[playerid] = player_editobject_defaultposz[playerid];
        player_editobject_rotx[playerid] = player_editobject_defaultrotx[playerid];
        player_editobject_roty[playerid] = player_editobject_defaultroty[playerid];
        player_editobject_rotz[playerid] = player_editobject_defaultrotz[playerid];
        CallRemoteFunction("OnEditObjectResponse", "iiiffffff", playerid, response, player_editobject_objectid[playerid], player_editobject_posx[playerid], player_editobject_posy[playerid], player_editobject_posz[playerid], player_editobject_rotx[playerid], player_editobject_roty[playerid], player_editobject_rotz[playerid]);
        player_editobject_objectid[playerid] = -1;
    }
    if(playertextid == editobject_Confirm[playerid])
    {
        ObjectEdit_HideTextdraw(playerid);

        new response = EDIT_RESPONSE_FINAL;
        CallRemoteFunction("OnEditObjectResponse", "iiiiffffff", playerid, player_editobject_action[playerid], response, player_editobject_objectid[playerid], player_editobject_posx[playerid], player_editobject_posy[playerid], player_editobject_posz[playerid], player_editobject_rotx[playerid], player_editobject_roty[playerid], player_editobject_rotz[playerid]);
        player_editobject_objectid[playerid] = -1;
    }
    return 0;
}

hook OnPlayerEditDynamicObj(playerid, objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
    if(player_editobject_objectid[playerid] != -1)
    {
        if(response == EDIT_RESPONSE_CANCEL) return 1;
        else if(response == EDIT_RESPONSE_FINAL)
        {
            player_editobject_posx[playerid] = x;
            player_editobject_posy[playerid] = y;
            player_editobject_posz[playerid] = z;
            player_editobject_rotx[playerid] = rx;
            player_editobject_roty[playerid] = ry;
            player_editobject_rotz[playerid] = rz;
            UpdateEditObjectPosition(playerid);

            new response_fix = EDIT_RESPONSE_FINAL;
            CallRemoteFunction("OnEditObjectResponse", "iiiiffffff", playerid, player_editobject_action[playerid], response_fix, player_editobject_objectid[playerid], player_editobject_posx[playerid], player_editobject_posy[playerid], player_editobject_posz[playerid], player_editobject_rotx[playerid], player_editobject_roty[playerid], player_editobject_rotz[playerid]);
            ObjectEdit_HideTextdraw(playerid);
            player_editobject_objectid[playerid] = -1;
        }
        else if(response == EDIT_RESPONSE_CANCEL)
        {
            UpdateEditObjectPosition(playerid);
            ObjectEdit_ShowTextdraw(playerid);
        }
        else if(response == EDIT_RESPONSE_UPDATE)
        {
            new response_fix = EDIT_RESPONSE_UPDATE;
            CallRemoteFunction("OnEditObjectResponse", "iiiiffffff", playerid, player_editobject_action[playerid], response_fix, player_editobject_objectid[playerid], x, y, z, rx, ry, rz);
        }
    }
    return 1;
}

