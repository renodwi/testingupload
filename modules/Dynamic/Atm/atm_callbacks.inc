hook OnGameModeInit()
{
    AddAdminCommand(Manager, "/atms", "Digunakan untuk membuka menu atm admin");
    return 1;
}

hook OnServerAssignData()
{
    mysql_tquery(sql, "SELECT * FROM `atms`", "AssignAtmData");
    return 1;
}

hook OnPlayerConnect(playerid)
{
    player_edit_atmid[playerid] = -1;
    return 1;
}

hook OnEditObjectResponse(playerid, action, response, objectid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
    if(action == EDITOBJECT_ATM)
    {
        if(player_edit_atmid[playerid] != -1)
        {
            new atmid = player_edit_atmid[playerid];
            if(response == EDIT_RESPONSE_CANCEL)
            {
                RefreshAtm(atmid);
            }
            else if(response == EDIT_RESPONSE_FINAL)
            {
                atmInfo[atmid][atmPositionX] = x;
                atmInfo[atmid][atmPositionY] = y;
                atmInfo[atmid][atmPositionZ] = z;
                atmInfo[atmid][atmRotationX] = rx;
                atmInfo[atmid][atmRotationY] = ry;
                atmInfo[atmid][atmRotationZ] = rz;
                RefreshAtm(atmid);
            }
        }
    }
    return 1;
}