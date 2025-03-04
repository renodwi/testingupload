/*

==> Gate (Callbacks)
Contains Callbacks for the gate system.

Credit: Rndwst
Created On: 14 January 2023

*/

hook OnGameModeInit()
{
    AddAdminCommand(Admin3, "/gates", "Digunakan untuk membuka menu gate admin");
    return 1;
}

hook OnServerAssignData()
{
    mysql_tquery(sql, "SELECT * FROM `gates`", "AssignGateDatabase");
    return 1;
}

hook OnEditObjectResponse(playerid, action, response, objectid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
    if(action == EDITINGOBJECT_GATEPOSITION)
    {
        if(GetPlayerEditGateID(playerid) != -1)
        {
            new gate_id = GetPlayerEditGateID(playerid);
            if(response == EDIT_RESPONSE_CANCEL)
            {
                new Float:before_x, Float:before_y, Float:before_z, Float:before_rx, Float:before_ry, Float:before_rz;
                GetGatePosition(gate_id, before_x, before_y, before_z);
                GetGateRotation(gate_id, before_rx, before_ry, before_rz);

                SetGatePosition(gate_id, before_x, before_y, before_z);
                SetGateRotation(gate_id, before_rx, before_ry, before_rz);
            }
            else if(response == EDIT_RESPONSE_FINAL)
            {
                SetGatePosition(gate_id, x, y, z);
                SetGateRotation(gate_id, rx, ry, rz);
            }
        }
    }

    if(action == EDITINGOBJECT_GATEMOVEPOSITION)
    {
        if(GetPlayerEditGateID(playerid) != -1)
        {
            new gate_id = GetPlayerEditGateID(playerid);
            if(response == EDIT_RESPONSE_CANCEL)
            {
                new Float:before_x_move, Float:before_y_move, Float:before_z_move, Float:before_rx_move, Float:before_ry_move, Float:before_rz_move;
                GetGateMovePosition(gate_id, before_x_move, before_y_move, before_z_move);
                GetGateMoveRotation(gate_id, before_rx_move, before_ry_move, before_rz_move);

                SetGateMovePosition(gate_id, before_x_move, before_y_move, before_z_move);
                SetGateMoveRotation(gate_id, before_rx_move, before_ry_move, before_rz_move);

                new Float:before_x_pos, Float:before_y_pos, Float:before_z_pos, Float:before_rx_pos, Float:before_ry_pos, Float:before_rz_pos;
                GetGatePosition(gate_id, before_x_pos, before_y_pos, before_z_pos);
                GetGateRotation(gate_id, before_rx_pos, before_ry_pos, before_rz_pos);

                SetDynamicObjectPos(GetGateObjectID(gate_id), before_x_pos, before_y_pos, before_z_pos);
                SetDynamicObjectRot(GetGateObjectID(gate_id), before_rx_pos, before_ry_pos, before_rz_pos);
            }
            else if(response == EDIT_RESPONSE_FINAL)
            {
                SetGateMovePosition(gate_id, x, y, z);
                SetGateMoveRotation(gate_id, rx, ry, rz);

                new Float:before_x_pos, Float:before_y_pos, Float:before_z_pos, Float:before_rx_pos, Float:before_ry_pos, Float:before_rz_pos;
                GetGatePosition(gate_id, before_x_pos, before_y_pos, before_z_pos);
                GetGateRotation(gate_id, before_rx_pos, before_ry_pos, before_rz_pos);

                SetDynamicObjectPos(GetGateObjectID(gate_id), before_x_pos, before_y_pos, before_z_pos);
                SetDynamicObjectRot(GetGateObjectID(gate_id), before_rx_pos, before_ry_pos, before_rz_pos);
            }
        }
    }
    return 1;
}

hook OnDynamicObjectMoved(objectid)
{
    foreach(new gateid : Gate)
    {
        if(gateInfo[gateid][gateStatus] == GATESTATUS_MOVEOPEN)
        {
            gateInfo[gateid][gateStatus] = GATESTATUS_OPENED;
            SetTimerEx("timer_CloseGate", 5000, false, "d", gateid);
        }
        else if(gateInfo[gateid][gateStatus] == GATESTATUS_MOVECLOSE)
        {
            gateInfo[gateid][gateStatus] = GATESTATUS_CLOSED;
        }
    }
    return 1;
}

function timer_CloseGate(gateid)
{
    CloseGate(gateid);
    return 1;
}