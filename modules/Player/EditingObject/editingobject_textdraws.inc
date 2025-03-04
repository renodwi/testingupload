/*

==> Editing Object (TextDraw)
Contains TextDraw for the editing object system.

Credit: Rndwst
Created On: 13 January 2023

*/

#include <YSI_CODING\y_hooks>

stock ObjectEdit_HideTextdraw(playerid)
{
    PlayerTextDrawHide(playerid, editobject_editpos_forpc[playerid]);
	PlayerTextDrawHide(playerid, editobject_Confirm[playerid]);
	PlayerTextDrawHide(playerid, editobject_Cancel[playerid]);
	PlayerTextDrawHide(playerid, editobject_X_Coordinate[playerid]);
	PlayerTextDrawHide(playerid, editobject_RX_Coordinate[playerid]);
	PlayerTextDrawHide(playerid, editobject_Y_Coordinate[playerid]);
	PlayerTextDrawHide(playerid, editobject_Z_Coordinate[playerid]);
	PlayerTextDrawHide(playerid, editobject_RY_Coordinate[playerid]);
	PlayerTextDrawHide(playerid, editobject_RZ_Coordinate[playerid]);
	PlayerTextDrawHide(playerid, editobject_X_X[playerid]);
	PlayerTextDrawHide(playerid, editobject_Y_Y[playerid]);
	PlayerTextDrawHide(playerid, editobject_Z_Z[playerid]);
	PlayerTextDrawHide(playerid, editobject_RZ_Rz[playerid]);
	PlayerTextDrawHide(playerid, editobject_RY_Ry[playerid]);
	PlayerTextDrawHide(playerid, editobject_RX_Rx[playerid]);
	PlayerTextDrawHide(playerid, editobject_X_Right[playerid]);
	PlayerTextDrawHide(playerid, editobject_Y_Right[playerid]);
	PlayerTextDrawHide(playerid, editobject_Z_Right[playerid]);
	PlayerTextDrawHide(playerid, editobject_X_Left[playerid]);
	PlayerTextDrawHide(playerid, editobject_Y_Left[playerid]);
	PlayerTextDrawHide(playerid, editobject_Z_Left[playerid]);
	PlayerTextDrawHide(playerid, editobject_RX_Right[playerid]);
	PlayerTextDrawHide(playerid, editobject_RY_Right[playerid]);
	PlayerTextDrawHide(playerid, editobject_RZ_Right[playerid]);
	PlayerTextDrawHide(playerid, editobject_RX_Left[playerid]);
	PlayerTextDrawHide(playerid, editobject_RY_Left[playerid]);
	PlayerTextDrawHide(playerid, editobject_RZ_Left[playerid]);
	PlayerTextDrawHide(playerid, editobject_Information[playerid]);
	PlayerTextDrawHide(playerid, editobject_jika_cursor_hilang[playerid]);
	CancelSelectTextDraw(playerid);
    return 1;
}

stock ObjectEdit_ShowTextdraw(playerid)
{
	new string[300];
	format(string, sizeof(string), "%0.4f", player_editobject_posx[playerid]);
	PlayerTextDrawSetString(playerid, editobject_X_Coordinate[playerid], string);
	
	format(string, sizeof(string), "%0.4f", player_editobject_posy[playerid]);
	PlayerTextDrawSetString(playerid, editobject_Y_Coordinate[playerid], string);
	
	format(string, sizeof(string), "%0.4f", player_editobject_posz[playerid]);
	PlayerTextDrawSetString(playerid, editobject_Z_Coordinate[playerid], string);
	
	format(string, sizeof(string), "%0.4f", player_editobject_rotx[playerid]);
	PlayerTextDrawSetString(playerid, editobject_RX_Coordinate[playerid], string);
	
	format(string, sizeof(string), "%0.4f", player_editobject_roty[playerid]);
	PlayerTextDrawSetString(playerid, editobject_RY_Coordinate[playerid], string);
	
	format(string, sizeof(string), "%0.4f", player_editobject_rotz[playerid]);
	PlayerTextDrawSetString(playerid, editobject_RZ_Coordinate[playerid], string);

    PlayerTextDrawShow(playerid, editobject_editpos_forpc[playerid]);
	PlayerTextDrawShow(playerid, editobject_Confirm[playerid]);
	PlayerTextDrawShow(playerid, editobject_Cancel[playerid]);
	PlayerTextDrawShow(playerid, editobject_X_Coordinate[playerid]);
	PlayerTextDrawShow(playerid, editobject_RX_Coordinate[playerid]);
	PlayerTextDrawShow(playerid, editobject_Y_Coordinate[playerid]);
	PlayerTextDrawShow(playerid, editobject_Z_Coordinate[playerid]);
	PlayerTextDrawShow(playerid, editobject_RY_Coordinate[playerid]);
	PlayerTextDrawShow(playerid, editobject_RZ_Coordinate[playerid]);
	PlayerTextDrawShow(playerid, editobject_X_X[playerid]);
	PlayerTextDrawShow(playerid, editobject_Y_Y[playerid]);
	PlayerTextDrawShow(playerid, editobject_Z_Z[playerid]);
	PlayerTextDrawShow(playerid, editobject_RZ_Rz[playerid]);
	PlayerTextDrawShow(playerid, editobject_RY_Ry[playerid]);
	PlayerTextDrawShow(playerid, editobject_RX_Rx[playerid]);
	PlayerTextDrawShow(playerid, editobject_X_Right[playerid]);
	PlayerTextDrawShow(playerid, editobject_Y_Right[playerid]);
	PlayerTextDrawShow(playerid, editobject_Z_Right[playerid]);
	PlayerTextDrawShow(playerid, editobject_X_Left[playerid]);
	PlayerTextDrawShow(playerid, editobject_Y_Left[playerid]);
	PlayerTextDrawShow(playerid, editobject_Z_Left[playerid]);
	PlayerTextDrawShow(playerid, editobject_RX_Right[playerid]);
	PlayerTextDrawShow(playerid, editobject_RY_Right[playerid]);
	PlayerTextDrawShow(playerid, editobject_RZ_Right[playerid]);
	PlayerTextDrawShow(playerid, editobject_RX_Left[playerid]);
	PlayerTextDrawShow(playerid, editobject_RY_Left[playerid]);
	PlayerTextDrawShow(playerid, editobject_RZ_Left[playerid]);
	PlayerTextDrawShow(playerid, editobject_Information[playerid]);
	PlayerTextDrawShow(playerid, editobject_jika_cursor_hilang[playerid]);
    SelectTextDraw(playerid, 0xFFFF00FF);
    return 1;
}

stock ObjectEdit_DestroyTextdraw(playerid)
{
    PlayerTextDrawDestroy(playerid, editobject_editpos_forpc[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_Confirm[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_Cancel[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_X_Coordinate[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_RX_Coordinate[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_Y_Coordinate[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_Z_Coordinate[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_RY_Coordinate[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_RZ_Coordinate[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_X_X[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_Y_Y[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_Z_Z[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_RZ_Rz[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_RY_Ry[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_RX_Rx[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_X_Right[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_Y_Right[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_Z_Right[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_X_Left[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_Y_Left[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_Z_Left[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_RX_Right[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_RY_Right[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_RZ_Right[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_RX_Left[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_RY_Left[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_RZ_Left[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_Information[playerid]);
	PlayerTextDrawDestroy(playerid, editobject_jika_cursor_hilang[playerid]);
    return 1;
}

stock ObjectEdit_LoadTextdraw(playerid)
{
    editobject_editpos_forpc[playerid] = CreatePlayerTextDraw(playerid, 325.000000, 376.000000, "Edit Position (For PC Players)");
	PlayerTextDrawFont(playerid, editobject_editpos_forpc[playerid], 2);
	PlayerTextDrawLetterSize(playerid, editobject_editpos_forpc[playerid], 0.258332, 1.649999);
	PlayerTextDrawTextSize(playerid, editobject_editpos_forpc[playerid], 16.500000, 215.500000);
	PlayerTextDrawSetOutline(playerid, editobject_editpos_forpc[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_editpos_forpc[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_editpos_forpc[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_editpos_forpc[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, editobject_editpos_forpc[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_editpos_forpc[playerid], 647430073);
	PlayerTextDrawUseBox(playerid, editobject_editpos_forpc[playerid], 1);
	PlayerTextDrawSetProportional(playerid, editobject_editpos_forpc[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_editpos_forpc[playerid], 1);

	editobject_Confirm[playerid] = CreatePlayerTextDraw(playerid, 237.000000, 349.000000, "Confirm");
	PlayerTextDrawFont(playerid, editobject_Confirm[playerid], 2);
	PlayerTextDrawLetterSize(playerid, editobject_Confirm[playerid], 0.258332, 1.649999);
	PlayerTextDrawTextSize(playerid, editobject_Confirm[playerid], 16.500000, 97.000000);
	PlayerTextDrawSetOutline(playerid, editobject_Confirm[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_Confirm[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_Confirm[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_Confirm[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, editobject_Confirm[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_Confirm[playerid], 16711865);
	PlayerTextDrawUseBox(playerid, editobject_Confirm[playerid], 1);
	PlayerTextDrawSetProportional(playerid, editobject_Confirm[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_Confirm[playerid], 1);

	editobject_Cancel[playerid] = CreatePlayerTextDraw(playerid, 413.000000, 349.000000, "Cancel");
	PlayerTextDrawFont(playerid, editobject_Cancel[playerid], 2);
	PlayerTextDrawLetterSize(playerid, editobject_Cancel[playerid], 0.258332, 1.649999);
	PlayerTextDrawTextSize(playerid, editobject_Cancel[playerid], 16.500000, 97.000000);
	PlayerTextDrawSetOutline(playerid, editobject_Cancel[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_Cancel[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_Cancel[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_Cancel[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, editobject_Cancel[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_Cancel[playerid], -16777031);
	PlayerTextDrawUseBox(playerid, editobject_Cancel[playerid], 1);
	PlayerTextDrawSetProportional(playerid, editobject_Cancel[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_Cancel[playerid], 1);

	editobject_X_Coordinate[playerid] = CreatePlayerTextDraw(playerid, 95.000000, 185.000000, "0.0000");
	PlayerTextDrawFont(playerid, editobject_X_Coordinate[playerid], 2);
	PlayerTextDrawLetterSize(playerid, editobject_X_Coordinate[playerid], 0.258332, 1.649999);
	PlayerTextDrawTextSize(playerid, editobject_X_Coordinate[playerid], 16.500000, 80.000000);
	PlayerTextDrawSetOutline(playerid, editobject_X_Coordinate[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_X_Coordinate[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_X_Coordinate[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_X_Coordinate[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, editobject_X_Coordinate[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_X_Coordinate[playerid], -764862791);
	PlayerTextDrawUseBox(playerid, editobject_X_Coordinate[playerid], 1);
	PlayerTextDrawSetProportional(playerid, editobject_X_Coordinate[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_X_Coordinate[playerid], 1);

	editobject_RX_Coordinate[playerid] = CreatePlayerTextDraw(playerid, 555.000000, 185.000000, "0.0000");
	PlayerTextDrawFont(playerid, editobject_RX_Coordinate[playerid], 2);
	PlayerTextDrawLetterSize(playerid, editobject_RX_Coordinate[playerid], 0.258332, 1.649999);
	PlayerTextDrawTextSize(playerid, editobject_RX_Coordinate[playerid], 16.500000, 80.000000);
	PlayerTextDrawSetOutline(playerid, editobject_RX_Coordinate[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_RX_Coordinate[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_RX_Coordinate[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_RX_Coordinate[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, editobject_RX_Coordinate[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_RX_Coordinate[playerid], 9109689);
	PlayerTextDrawUseBox(playerid, editobject_RX_Coordinate[playerid], 1);
	PlayerTextDrawSetProportional(playerid, editobject_RX_Coordinate[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_RX_Coordinate[playerid], 1);

	editobject_Y_Coordinate[playerid] = CreatePlayerTextDraw(playerid, 95.000000, 225.000000, "0.0000");
	PlayerTextDrawFont(playerid, editobject_Y_Coordinate[playerid], 2);
	PlayerTextDrawLetterSize(playerid, editobject_Y_Coordinate[playerid], 0.258332, 1.649999);
	PlayerTextDrawTextSize(playerid, editobject_Y_Coordinate[playerid], 16.500000, 80.000000);
	PlayerTextDrawSetOutline(playerid, editobject_Y_Coordinate[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_Y_Coordinate[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_Y_Coordinate[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_Y_Coordinate[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, editobject_Y_Coordinate[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_Y_Coordinate[playerid], -764862791);
	PlayerTextDrawUseBox(playerid, editobject_Y_Coordinate[playerid], 1);
	PlayerTextDrawSetProportional(playerid, editobject_Y_Coordinate[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_Y_Coordinate[playerid], 1);

	editobject_Z_Coordinate[playerid] = CreatePlayerTextDraw(playerid, 95.000000, 265.000000, "0.0000");
	PlayerTextDrawFont(playerid, editobject_Z_Coordinate[playerid], 2);
	PlayerTextDrawLetterSize(playerid, editobject_Z_Coordinate[playerid], 0.258332, 1.649999);
	PlayerTextDrawTextSize(playerid, editobject_Z_Coordinate[playerid], 16.500000, 80.000000);
	PlayerTextDrawSetOutline(playerid, editobject_Z_Coordinate[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_Z_Coordinate[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_Z_Coordinate[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_Z_Coordinate[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, editobject_Z_Coordinate[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_Z_Coordinate[playerid], -764862791);
	PlayerTextDrawUseBox(playerid, editobject_Z_Coordinate[playerid], 1);
	PlayerTextDrawSetProportional(playerid, editobject_Z_Coordinate[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_Z_Coordinate[playerid], 1);

	editobject_RY_Coordinate[playerid] = CreatePlayerTextDraw(playerid, 555.000000, 225.000000, "0.0000");
	PlayerTextDrawFont(playerid, editobject_RY_Coordinate[playerid], 2);
	PlayerTextDrawLetterSize(playerid, editobject_RY_Coordinate[playerid], 0.258332, 1.649999);
	PlayerTextDrawTextSize(playerid, editobject_RY_Coordinate[playerid], 16.500000, 80.000000);
	PlayerTextDrawSetOutline(playerid, editobject_RY_Coordinate[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_RY_Coordinate[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_RY_Coordinate[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_RY_Coordinate[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, editobject_RY_Coordinate[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_RY_Coordinate[playerid], 9109689);
	PlayerTextDrawUseBox(playerid, editobject_RY_Coordinate[playerid], 1);
	PlayerTextDrawSetProportional(playerid, editobject_RY_Coordinate[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_RY_Coordinate[playerid], 1);

	editobject_RZ_Coordinate[playerid] = CreatePlayerTextDraw(playerid, 555.000000, 265.000000, "0.0000");
	PlayerTextDrawFont(playerid, editobject_RZ_Coordinate[playerid], 2);
	PlayerTextDrawLetterSize(playerid, editobject_RZ_Coordinate[playerid], 0.258332, 1.649999);
	PlayerTextDrawTextSize(playerid, editobject_RZ_Coordinate[playerid], 16.500000, 80.000000);
	PlayerTextDrawSetOutline(playerid, editobject_RZ_Coordinate[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_RZ_Coordinate[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_RZ_Coordinate[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_RZ_Coordinate[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, editobject_RZ_Coordinate[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_RZ_Coordinate[playerid], 9109689);
	PlayerTextDrawUseBox(playerid, editobject_RZ_Coordinate[playerid], 1);
	PlayerTextDrawSetProportional(playerid, editobject_RZ_Coordinate[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_RZ_Coordinate[playerid], 1);

	editobject_X_X[playerid] = CreatePlayerTextDraw(playerid, 95.000000, 165.000000, "X");
	PlayerTextDrawFont(playerid, editobject_X_X[playerid], 1);
	PlayerTextDrawLetterSize(playerid, editobject_X_X[playerid], 0.570833, 2.200000);
	PlayerTextDrawTextSize(playerid, editobject_X_X[playerid], 16.500000, 80.000000);
	PlayerTextDrawSetOutline(playerid, editobject_X_X[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_X_X[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_X_X[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_X_X[playerid], -2686721);
	PlayerTextDrawBackgroundColor(playerid, editobject_X_X[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_X_X[playerid], -764862791);
	PlayerTextDrawUseBox(playerid, editobject_X_X[playerid], 0);
	PlayerTextDrawSetProportional(playerid, editobject_X_X[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_X_X[playerid], 0);

	editobject_Y_Y[playerid] = CreatePlayerTextDraw(playerid, 95.000000, 205.000000, "Y");
	PlayerTextDrawFont(playerid, editobject_Y_Y[playerid], 1);
	PlayerTextDrawLetterSize(playerid, editobject_Y_Y[playerid], 0.570833, 2.200000);
	PlayerTextDrawTextSize(playerid, editobject_Y_Y[playerid], 16.500000, 80.000000);
	PlayerTextDrawSetOutline(playerid, editobject_Y_Y[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_Y_Y[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_Y_Y[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_Y_Y[playerid], -2686721);
	PlayerTextDrawBackgroundColor(playerid, editobject_Y_Y[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_Y_Y[playerid], -764862791);
	PlayerTextDrawUseBox(playerid, editobject_Y_Y[playerid], 0);
	PlayerTextDrawSetProportional(playerid, editobject_Y_Y[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_Y_Y[playerid], 0);

	editobject_Z_Z[playerid] = CreatePlayerTextDraw(playerid, 95.000000, 245.000000, "Z");
	PlayerTextDrawFont(playerid, editobject_Z_Z[playerid], 1);
	PlayerTextDrawLetterSize(playerid, editobject_Z_Z[playerid], 0.570833, 2.200000);
	PlayerTextDrawTextSize(playerid, editobject_Z_Z[playerid], 16.500000, 80.000000);
	PlayerTextDrawSetOutline(playerid, editobject_Z_Z[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_Z_Z[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_Z_Z[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_Z_Z[playerid], -2686721);
	PlayerTextDrawBackgroundColor(playerid, editobject_Z_Z[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_Z_Z[playerid], -764862791);
	PlayerTextDrawUseBox(playerid, editobject_Z_Z[playerid], 0);
	PlayerTextDrawSetProportional(playerid, editobject_Z_Z[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_Z_Z[playerid], 0);

	editobject_RZ_Rz[playerid] = CreatePlayerTextDraw(playerid, 555.000000, 245.000000, "RZ");
	PlayerTextDrawFont(playerid, editobject_RZ_Rz[playerid], 1);
	PlayerTextDrawLetterSize(playerid, editobject_RZ_Rz[playerid], 0.570833, 2.200000);
	PlayerTextDrawTextSize(playerid, editobject_RZ_Rz[playerid], 16.500000, 80.000000);
	PlayerTextDrawSetOutline(playerid, editobject_RZ_Rz[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_RZ_Rz[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_RZ_Rz[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_RZ_Rz[playerid], 9109759);
	PlayerTextDrawBackgroundColor(playerid, editobject_RZ_Rz[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_RZ_Rz[playerid], -764862791);
	PlayerTextDrawUseBox(playerid, editobject_RZ_Rz[playerid], 0);
	PlayerTextDrawSetProportional(playerid, editobject_RZ_Rz[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_RZ_Rz[playerid], 0);

	editobject_RY_Ry[playerid] = CreatePlayerTextDraw(playerid, 555.000000, 205.000000, "RY");
	PlayerTextDrawFont(playerid, editobject_RY_Ry[playerid], 1);
	PlayerTextDrawLetterSize(playerid, editobject_RY_Ry[playerid], 0.570833, 2.200000);
	PlayerTextDrawTextSize(playerid, editobject_RY_Ry[playerid], 16.500000, 80.000000);
	PlayerTextDrawSetOutline(playerid, editobject_RY_Ry[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_RY_Ry[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_RY_Ry[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_RY_Ry[playerid], 9109759);
	PlayerTextDrawBackgroundColor(playerid, editobject_RY_Ry[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_RY_Ry[playerid], -764862791);
	PlayerTextDrawUseBox(playerid, editobject_RY_Ry[playerid], 0);
	PlayerTextDrawSetProportional(playerid, editobject_RY_Ry[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_RY_Ry[playerid], 0);

	editobject_RX_Rx[playerid] = CreatePlayerTextDraw(playerid, 555.000000, 165.000000, "RX");
	PlayerTextDrawFont(playerid, editobject_RX_Rx[playerid], 1);
	PlayerTextDrawLetterSize(playerid, editobject_RX_Rx[playerid], 0.570833, 2.200000);
	PlayerTextDrawTextSize(playerid, editobject_RX_Rx[playerid], 16.500000, 80.000000);
	PlayerTextDrawSetOutline(playerid, editobject_RX_Rx[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_RX_Rx[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_RX_Rx[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_RX_Rx[playerid], 9109759);
	PlayerTextDrawBackgroundColor(playerid, editobject_RX_Rx[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_RX_Rx[playerid], -764862791);
	PlayerTextDrawUseBox(playerid, editobject_RX_Rx[playerid], 0);
	PlayerTextDrawSetProportional(playerid, editobject_RX_Rx[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_RX_Rx[playerid], 0);

	editobject_X_Right[playerid] = CreatePlayerTextDraw(playerid, 155.000000, 179.000000, "ld_beat:right");
	PlayerTextDrawFont(playerid, editobject_X_Right[playerid], 4);
	PlayerTextDrawLetterSize(playerid, editobject_X_Right[playerid], 0.258332, 1.649999);
	PlayerTextDrawTextSize(playerid, editobject_X_Right[playerid], 22.500000, 28.500000);
	PlayerTextDrawSetOutline(playerid, editobject_X_Right[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_X_Right[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_X_Right[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_X_Right[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, editobject_X_Right[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_X_Right[playerid], -764862791);
	PlayerTextDrawUseBox(playerid, editobject_X_Right[playerid], 0);
	PlayerTextDrawSetProportional(playerid, editobject_X_Right[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_X_Right[playerid], 1);

	editobject_Y_Right[playerid] = CreatePlayerTextDraw(playerid, 155.000000, 220.000000, "ld_beat:right");
	PlayerTextDrawFont(playerid, editobject_Y_Right[playerid], 4);
	PlayerTextDrawLetterSize(playerid, editobject_Y_Right[playerid], 0.258332, 1.649999);
	PlayerTextDrawTextSize(playerid, editobject_Y_Right[playerid], 22.500000, 28.500000);
	PlayerTextDrawSetOutline(playerid, editobject_Y_Right[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_Y_Right[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_Y_Right[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_Y_Right[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, editobject_Y_Right[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_Y_Right[playerid], -764862791);
	PlayerTextDrawUseBox(playerid, editobject_Y_Right[playerid], 0);
	PlayerTextDrawSetProportional(playerid, editobject_Y_Right[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_Y_Right[playerid], 1);

	editobject_Z_Right[playerid] = CreatePlayerTextDraw(playerid, 155.000000, 260.000000, "ld_beat:right");
	PlayerTextDrawFont(playerid, editobject_Z_Right[playerid], 4);
	PlayerTextDrawLetterSize(playerid, editobject_Z_Right[playerid], 0.258332, 1.649999);
	PlayerTextDrawTextSize(playerid, editobject_Z_Right[playerid], 22.500000, 28.500000);
	PlayerTextDrawSetOutline(playerid, editobject_Z_Right[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_Z_Right[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_Z_Right[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_Z_Right[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, editobject_Z_Right[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_Z_Right[playerid], -764862791);
	PlayerTextDrawUseBox(playerid, editobject_Z_Right[playerid], 0);
	PlayerTextDrawSetProportional(playerid, editobject_Z_Right[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_Z_Right[playerid], 1);

	editobject_X_Left[playerid] = CreatePlayerTextDraw(playerid, 15.000000, 179.000000, "ld_beat:left");
	PlayerTextDrawFont(playerid, editobject_X_Left[playerid], 4);
	PlayerTextDrawLetterSize(playerid, editobject_X_Left[playerid], 0.258332, 1.649999);
	PlayerTextDrawTextSize(playerid, editobject_X_Left[playerid], 22.500000, 28.500000);
	PlayerTextDrawSetOutline(playerid, editobject_X_Left[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_X_Left[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_X_Left[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_X_Left[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, editobject_X_Left[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_X_Left[playerid], -764862791);
	PlayerTextDrawUseBox(playerid, editobject_X_Left[playerid], 0);
	PlayerTextDrawSetProportional(playerid, editobject_X_Left[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_X_Left[playerid], 1);

	editobject_Y_Left[playerid] = CreatePlayerTextDraw(playerid, 15.000000, 220.000000, "ld_beat:left");
	PlayerTextDrawFont(playerid, editobject_Y_Left[playerid], 4);
	PlayerTextDrawLetterSize(playerid, editobject_Y_Left[playerid], 0.258332, 1.649999);
	PlayerTextDrawTextSize(playerid, editobject_Y_Left[playerid], 22.500000, 28.500000);
	PlayerTextDrawSetOutline(playerid, editobject_Y_Left[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_Y_Left[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_Y_Left[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_Y_Left[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, editobject_Y_Left[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_Y_Left[playerid], -764862791);
	PlayerTextDrawUseBox(playerid, editobject_Y_Left[playerid], 0);
	PlayerTextDrawSetProportional(playerid, editobject_Y_Left[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_Y_Left[playerid], 1);

	editobject_Z_Left[playerid] = CreatePlayerTextDraw(playerid, 15.000000, 260.000000, "ld_beat:left");
	PlayerTextDrawFont(playerid, editobject_Z_Left[playerid], 4);
	PlayerTextDrawLetterSize(playerid, editobject_Z_Left[playerid], 0.258332, 1.649999);
	PlayerTextDrawTextSize(playerid, editobject_Z_Left[playerid], 22.500000, 28.500000);
	PlayerTextDrawSetOutline(playerid, editobject_Z_Left[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_Z_Left[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_Z_Left[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_Z_Left[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, editobject_Z_Left[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_Z_Left[playerid], -764862791);
	PlayerTextDrawUseBox(playerid, editobject_Z_Left[playerid], 0);
	PlayerTextDrawSetProportional(playerid, editobject_Z_Left[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_Z_Left[playerid], 1);

	editobject_RX_Right[playerid] = CreatePlayerTextDraw(playerid, 615.000000, 179.000000, "ld_beat:right");
	PlayerTextDrawFont(playerid, editobject_RX_Right[playerid], 4);
	PlayerTextDrawLetterSize(playerid, editobject_RX_Right[playerid], 0.258332, 1.649999);
	PlayerTextDrawTextSize(playerid, editobject_RX_Right[playerid], 22.500000, 28.500000);
	PlayerTextDrawSetOutline(playerid, editobject_RX_Right[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_RX_Right[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_RX_Right[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_RX_Right[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, editobject_RX_Right[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_RX_Right[playerid], -764862791);
	PlayerTextDrawUseBox(playerid, editobject_RX_Right[playerid], 0);
	PlayerTextDrawSetProportional(playerid, editobject_RX_Right[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_RX_Right[playerid], 1);

	editobject_RY_Right[playerid] = CreatePlayerTextDraw(playerid, 615.000000, 220.000000, "ld_beat:right");
	PlayerTextDrawFont(playerid, editobject_RY_Right[playerid], 4);
	PlayerTextDrawLetterSize(playerid, editobject_RY_Right[playerid], 0.258332, 1.649999);
	PlayerTextDrawTextSize(playerid, editobject_RY_Right[playerid], 22.500000, 28.500000);
	PlayerTextDrawSetOutline(playerid, editobject_RY_Right[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_RY_Right[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_RY_Right[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_RY_Right[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, editobject_RY_Right[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_RY_Right[playerid], -764862791);
	PlayerTextDrawUseBox(playerid, editobject_RY_Right[playerid], 0);
	PlayerTextDrawSetProportional(playerid, editobject_RY_Right[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_RY_Right[playerid], 1);

	editobject_RZ_Right[playerid] = CreatePlayerTextDraw(playerid, 615.000000, 260.000000, "ld_beat:right");
	PlayerTextDrawFont(playerid, editobject_RZ_Right[playerid], 4);
	PlayerTextDrawLetterSize(playerid, editobject_RZ_Right[playerid], 0.258332, 1.649999);
	PlayerTextDrawTextSize(playerid, editobject_RZ_Right[playerid], 22.500000, 28.500000);
	PlayerTextDrawSetOutline(playerid, editobject_RZ_Right[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_RZ_Right[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_RZ_Right[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_RZ_Right[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, editobject_RZ_Right[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_RZ_Right[playerid], -764862791);
	PlayerTextDrawUseBox(playerid, editobject_RZ_Right[playerid], 0);
	PlayerTextDrawSetProportional(playerid, editobject_RZ_Right[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_RZ_Right[playerid], 1);

	editobject_RX_Left[playerid] = CreatePlayerTextDraw(playerid, 475.000000, 179.000000, "ld_beat:left");
	PlayerTextDrawFont(playerid, editobject_RX_Left[playerid], 4);
	PlayerTextDrawLetterSize(playerid, editobject_RX_Left[playerid], 0.258332, 1.649999);
	PlayerTextDrawTextSize(playerid, editobject_RX_Left[playerid], 22.500000, 28.500000);
	PlayerTextDrawSetOutline(playerid, editobject_RX_Left[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_RX_Left[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_RX_Left[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_RX_Left[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, editobject_RX_Left[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_RX_Left[playerid], -764862791);
	PlayerTextDrawUseBox(playerid, editobject_RX_Left[playerid], 0);
	PlayerTextDrawSetProportional(playerid, editobject_RX_Left[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_RX_Left[playerid], 1);

	editobject_RY_Left[playerid] = CreatePlayerTextDraw(playerid, 475.000000, 220.000000, "ld_beat:left");
	PlayerTextDrawFont(playerid, editobject_RY_Left[playerid], 4);
	PlayerTextDrawLetterSize(playerid, editobject_RY_Left[playerid], 0.258332, 1.649999);
	PlayerTextDrawTextSize(playerid, editobject_RY_Left[playerid], 22.500000, 28.500000);
	PlayerTextDrawSetOutline(playerid, editobject_RY_Left[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_RY_Left[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_RY_Left[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_RY_Left[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, editobject_RY_Left[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_RY_Left[playerid], -764862791);
	PlayerTextDrawUseBox(playerid, editobject_RY_Left[playerid], 0);
	PlayerTextDrawSetProportional(playerid, editobject_RY_Left[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_RY_Left[playerid], 1);

	editobject_RZ_Left[playerid] = CreatePlayerTextDraw(playerid, 475.000000, 260.000000, "ld_beat:left");
	PlayerTextDrawFont(playerid, editobject_RZ_Left[playerid], 4);
	PlayerTextDrawLetterSize(playerid, editobject_RZ_Left[playerid], 0.258332, 1.649999);
	PlayerTextDrawTextSize(playerid, editobject_RZ_Left[playerid], 22.500000, 28.500000);
	PlayerTextDrawSetOutline(playerid, editobject_RZ_Left[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_RZ_Left[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_RZ_Left[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_RZ_Left[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, editobject_RZ_Left[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_RZ_Left[playerid], -764862791);
	PlayerTextDrawUseBox(playerid, editobject_RZ_Left[playerid], 0);
	PlayerTextDrawSetProportional(playerid, editobject_RZ_Left[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_RZ_Left[playerid], 1);

	editobject_Information[playerid] = CreatePlayerTextDraw(playerid, 113.000000, 317.000000, "adawwadwa");
	PlayerTextDrawFont(playerid, editobject_Information[playerid], 1);
	PlayerTextDrawLetterSize(playerid, editobject_Information[playerid], 0.329165, 1.350000);
	PlayerTextDrawTextSize(playerid, editobject_Information[playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, editobject_Information[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_Information[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_Information[playerid], 1);
	PlayerTextDrawColor(playerid, editobject_Information[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, editobject_Information[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_Information[playerid], 50);
	PlayerTextDrawUseBox(playerid, editobject_Information[playerid], 0);
	PlayerTextDrawSetProportional(playerid, editobject_Information[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_Information[playerid], 0);

	editobject_jika_cursor_hilang[playerid] = CreatePlayerTextDraw(playerid, 246.000000, 411.000000, "(( Jika cursor hilang, Gunakan command ~y~/cursor~w~ ))");
	PlayerTextDrawFont(playerid, editobject_jika_cursor_hilang[playerid], 1);
	PlayerTextDrawLetterSize(playerid, editobject_jika_cursor_hilang[playerid], 0.224999, 1.250000);
	PlayerTextDrawTextSize(playerid, editobject_jika_cursor_hilang[playerid], 400.000000, 233.500000);
	PlayerTextDrawSetOutline(playerid, editobject_jika_cursor_hilang[playerid], 1);
	PlayerTextDrawSetShadow(playerid, editobject_jika_cursor_hilang[playerid], 0);
	PlayerTextDrawAlignment(playerid, editobject_jika_cursor_hilang[playerid], 2);
	PlayerTextDrawColor(playerid, editobject_jika_cursor_hilang[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, editobject_jika_cursor_hilang[playerid], 255);
	PlayerTextDrawBoxColor(playerid, editobject_jika_cursor_hilang[playerid], 50);
	PlayerTextDrawUseBox(playerid, editobject_jika_cursor_hilang[playerid], 0);
	PlayerTextDrawSetProportional(playerid, editobject_jika_cursor_hilang[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, editobject_jika_cursor_hilang[playerid], 0);
    return 1;
}