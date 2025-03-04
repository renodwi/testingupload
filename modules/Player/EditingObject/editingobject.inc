/*

==> Editing Object (Main Code)
This code includes all the code from the object editing system.

Credit: Rndwst
Created On: 13 January 2023


ShowPlayerEditObjectPosition(playerid, action, objectid, info[] = " ");                                                 >> For start editing object
OnEditObjectResponse(playerid, action, response, objectid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz);    >> Response from ShowPlayerEditObjectPosition

*/

#include "Modules\Player\EditingObject\editingobject_variables.inc"
#include "Modules\Player\EditingObject\editingobject_textdraws.inc"
#include "Modules\Player\EditingObject\editingobject_functions.inc"
#include "Modules\Player\EditingObject\editingobject_callbacks.inc"
#include "Modules\Player\EditingObject\editingobject_dialogs.inc"