Dialog:EditingObject_SetCoord(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    else {
        new Float:coord;
        if(sscanf(inputtext, "f", coord))
            return ShowEditObjectSetCoord(playerid, player_editobject_setcoord[playerid]);
        new set = player_editobject_setcoord[playerid];
        if(set == EDITOBJECT_COORDX) {
            if(GetPlayerDistanceFromPoint(playerid, coord, player_editobject_posy[playerid], player_editobject_posz[playerid]) > 10.0) return SendErrorMessage(playerid, "Kamu tidak dapat merubah posisi object lebih dari 10.0 langkah dari posisi mu saat ini"), ShowEditObjectSetCoord(playerid, player_editobject_setcoord[playerid]);
        }
        if(set == EDITOBJECT_COORDY) {
            if(GetPlayerDistanceFromPoint(playerid, player_editobject_posx[playerid], coord, player_editobject_posz[playerid]) > 10.0) return SendErrorMessage(playerid, "Kamu tidak dapat merubah posisi object lebih dari 10.0 langkah dari posisi mu saat ini"), ShowEditObjectSetCoord(playerid, player_editobject_setcoord[playerid]);
        }
        if(set == EDITOBJECT_COORDZ) {
            if(GetPlayerDistanceFromPoint(playerid, player_editobject_posx[playerid], player_editobject_posy[playerid], coord) > 10.0) return SendErrorMessage(playerid, "Kamu tidak dapat merubah posisi object lebih dari 10.0 langkah dari posisi mu saat ini"), ShowEditObjectSetCoord(playerid, player_editobject_setcoord[playerid]);
        }
        if(set == EDITOBJECT_COORDX) player_editobject_posx[playerid] = coord;
        if(set == EDITOBJECT_COORDY) player_editobject_posy[playerid] = coord;
        if(set == EDITOBJECT_COORDZ) player_editobject_posz[playerid] = coord;
        if(set == EDITOBJECT_COORDRX) player_editobject_rotx[playerid] = coord;
        if(set == EDITOBJECT_COORDRY) player_editobject_roty[playerid] = coord;
        if(set == EDITOBJECT_COORDRZ) player_editobject_rotz[playerid] = coord;
        UpdateEditObjectPosition(playerid);
        ObjectEdit_ShowTextdraw(playerid);
    }
    return 1;
}