/*

==> Gate (Function)
Contains Function for the gate system.

Credit: Rndwst
Created On: 14 January 2023

*/

stock CreateGate(Float:posx, Float:posy, Float:posz, interior, world)
{
    new gate_id = Iter_Free(Gate);

    SetGateOwner(gate_id, GATEOWNER_PUBLIC, "Public");
    SetGatePassword(gate_id, " ");
    SetGateModel(gate_id, 19870);
    SetGatePrice(gate_id, 0);
    SetGateInterior(gate_id, interior);
    SetGateVirtualWorld(gate_id, world);
    SetGatePosition(gate_id, posx, posy, posz);
    SetGateRotation(gate_id, 0.0, 0.0, 0.0);
    SetGateMovePosition(gate_id, posx + 2.0, posy + 2.0, posz);
    SetGateMoveRotation(gate_id, 0.0, 0.0, 0.0);
    SetGateSpeed(gate_id, 2.5);

    gateInfo[gate_id][gateObject] = -1;
    gateInfo[gate_id][gateStatus] = GATESTATUS_CLOSED;

    new query[100];
    mysql_format(sql, query, sizeof query, "INSERT INTO `gates` (`id`) VALUES ('%d')", gate_id);
    mysql_tquery(sql, query);

    Iter_Add(Gate, gate_id);
    RefreshGate(gate_id);
    return gate_id;
}

stock ShowPlayerGateModel(playerid)
{
    AddPlayerSelectionItem(playerid, 19870, "", "");
    AddPlayerSelectionItem(playerid, 989, "", "");
    AddPlayerSelectionItem(playerid, 988, "", "");
    AddPlayerSelectionItem(playerid, 980, "", "");
    AddPlayerSelectionItem(playerid, 19912, "", "");
    AddPlayerSelectionItem(playerid, 985, "", "");
    AddPlayerSelectionItem(playerid, 2933, "", "");
    AddPlayerSelectionItem(playerid, 2990, "", "");
    AddPlayerSelectionItem(playerid, 975, "", "");
    AddPlayerSelectionItem(playerid, 969, "", "");
    AddPlayerSelectionItem(playerid, 19861, "", "");
    AddPlayerSelectionItem(playerid, 19861, "", "");
    ShowPlayerSelection(playerid, GateModel, "Select Gate Model");
    return 1;
}

Selection:GateModel(playerid, response, model, vehicle_color1, vehicle_color2)
{
    new gate_id = GetPlayerEditGateID(playerid);
    if(!response) return ShowPlayerEditGate(playerid, gate_id, GATEEDIT_LIST);
    else 
    {
        SetGateModel(gate_id, model);
        SendClientMessageEx(playerid, COLOR_REN, "GATE-MODEL: "WHITE"Changed "YELLOW"gate %d"WHITE" model to "LG"%d", gate_id, model);
    }
	return 1;
}

function gate_ToMovePositionTest(gate_id)
{
    MoveDynamicObject(gateInfo[gate_id][gateObject], gateInfo[gate_id][gatePositionX], gateInfo[gate_id][gatePositionY], gateInfo[gate_id][gatePositionZ], gateInfo[gate_id][gateSpeed], gateInfo[gate_id][gateRotationX], gateInfo[gate_id][gateRotationY], gateInfo[gate_id][gateRotationZ]);
    return 1;
}

stock RefreshGate(gate_id)
{
    if(!Iter_Contains(Gate, gate_id)) return 1;

    if(IsValidDynamicObject(gateInfo[gate_id][gateObject])) DestroyDynamicObject(gateInfo[gate_id][gateObject]);
    gateInfo[gate_id][gateObject] = CreateDynamicObject(gateInfo[gate_id][gateModel], gateInfo[gate_id][gatePositionX], gateInfo[gate_id][gatePositionY], gateInfo[gate_id][gatePositionZ], gateInfo[gate_id][gateRotationX], gateInfo[gate_id][gateRotationY], gateInfo[gate_id][gateRotationZ], gateInfo[gate_id][gateVirtualWorld], gateInfo[gate_id][gateInterior]);

    UpdateGateDatabase(gate_id);
    return 1;
}

stock DeleteGate(gate_id)
{
    if(!Iter_Contains(Gate, gate_id)) return 1;

    if(IsValidDynamicObject(gateInfo[gate_id][gateObject])) DestroyDynamicObject(gateInfo[gate_id][gateObject]);
    Iter_Remove(Gate, gate_id);

    new query[100];
    mysql_format(sql, query, sizeof query, "DELETE FROM `gates` WHERE `id` = '%d'", gate_id);
    mysql_tquery(sql, query);
    return 1;
}

stock SendPlayerToGate(playerid, gate_id)
{
    SetPlayerPos(playerid, gateInfo[gate_id][gatePositionX], gateInfo[gate_id][gatePositionY], gateInfo[gate_id][gatePositionZ]);
    SetPlayerInterior(playerid, gateInfo[gate_id][gateInterior]);
    SetPlayerVirtualWorld(playerid, gateInfo[gate_id][gateVirtualWorld]);
    RefreshGate(gate_id);
    return 1;
}

stock SetGatePosition(gate_id, Float:x, Float:y, Float:z)
{
    gateInfo[gate_id][gatePositionX] = x;
    gateInfo[gate_id][gatePositionY] = y;
    gateInfo[gate_id][gatePositionZ] = z;
    RefreshGate(gate_id);
    return 1;
}

stock SetGateRotation(gate_id, Float:x, Float:y, Float:z)
{
    gateInfo[gate_id][gateRotationX] = x;
    gateInfo[gate_id][gateRotationY] = y;
    gateInfo[gate_id][gateRotationZ] = z;
    RefreshGate(gate_id);
    return 1;
}

stock SetGateMovePosition(gate_id, Float:x, Float:y, Float:z)
{
    gateInfo[gate_id][gateMovePositionX] = x;
    gateInfo[gate_id][gateMovePositionY] = y;
    gateInfo[gate_id][gateMovePositionZ] = z;
    RefreshGate(gate_id);
    return 1;
}

stock SetGateMoveRotation(gate_id, Float:x, Float:y, Float:z)
{
    gateInfo[gate_id][gateMoveRotationX] = x;
    gateInfo[gate_id][gateMoveRotationY] = y;
    gateInfo[gate_id][gateMoveRotationZ] = z;
    RefreshGate(gate_id);
    return 1;
}

stock SetGateInterior(gate_id, interior)
{
    gateInfo[gate_id][gateInterior] = interior;
    RefreshGate(gate_id);
    return 1;
}

stock SetGateVirtualWorld(gate_id, world)
{
    gateInfo[gate_id][gateVirtualWorld] = world;
    RefreshGate(gate_id);
    return 1;
}

stock SetGatePrice(gate_id, price)
{
    gateInfo[gate_id][gatePrice] = price;
    RefreshGate(gate_id);
    return 1;
}

stock SetGateModel(gate_id, model)
{
    gateInfo[gate_id][gateModel] = model;
    RefreshGate(gate_id);
    return 1;
}

stock SetGatePassword(gate_id, const password[])
{
    format(gateInfo[gate_id][gatePassword], 8, password);
    RefreshGate(gate_id);
    return 1;
}

stock SetGateOwner(gate_id, ownertype, const ownername[])
{
    gateInfo[gate_id][gateOwnerType] = ownertype;
    format(gateInfo[gate_id][gateOwnerName], 120, ownername);
    RefreshGate(gate_id);
    return 1;
}

stock SetGateSpeed(gate_id, Float:speed)
{
    gateInfo[gate_id][gateSpeed] = speed;
    RefreshGate(gate_id);
    return 1;
}

stock GetGateObjectID(gate_id)
{
    return gateInfo[gate_id][gateObject];
}

stock GetGatePosition(gate_id, &Float:x, &Float:y, &Float:z)
{
    x = gateInfo[gate_id][gatePositionX];
    y = gateInfo[gate_id][gatePositionY];
    z = gateInfo[gate_id][gatePositionZ];
    return 1;
}

stock GetGateRotation(gate_id, &Float:x, &Float:y, &Float:z)
{
    x = gateInfo[gate_id][gateRotationX];
    y = gateInfo[gate_id][gateRotationY];
    z = gateInfo[gate_id][gateRotationZ];
    return 1;
}

stock GetGateMovePosition(gate_id, &Float:x, &Float:y, &Float:z)
{
    x = gateInfo[gate_id][gateMovePositionX];
    y = gateInfo[gate_id][gateMovePositionY];
    z = gateInfo[gate_id][gateMovePositionZ];
    return 1;
}

stock GetGateMoveRotation(gate_id, &Float:x, &Float:y, &Float:z)
{
    x = gateInfo[gate_id][gateMoveRotationX];
    y = gateInfo[gate_id][gateMoveRotationY];
    z = gateInfo[gate_id][gateMoveRotationZ];
    return 1;
}

stock GetGateOwnerType(gate_id)
{
    return gateInfo[gate_id][gateOwnerType];
}

stock GetGateOwnerName(gate_id)
{
    return gateInfo[gate_id][gateOwnerName];
}

stock IsPlayerNearGate(playerid)
{
    new bool:status = false;
    foreach(new i : Gate)
    {
        if(IsPlayerInRangeOfPoint(playerid, 10.0, gateInfo[i][gatePositionX], gateInfo[i][gatePositionY], gateInfo[i][gatePositionZ]) && GetPlayerInterior(playerid) == gateInfo[i][gateInterior] && GetPlayerVirtualWorld(playerid) == gateInfo[i][gateVirtualWorld])
        {
            status = true;
            break;
        }
    }
    return status;
}

stock GetNearestGate(playerid)
{
    if(!IsPlayerNearGate(playerid)) return 1;

    new gateid;
    foreach(new i : Gate)
    {
        if(IsPlayerInRangeOfPoint(playerid, 10.0, gateInfo[i][gatePositionX], gateInfo[i][gatePositionY], gateInfo[i][gatePositionZ]) && GetPlayerInterior(playerid) == gateInfo[i][gateInterior] && GetPlayerVirtualWorld(playerid) == gateInfo[i][gateVirtualWorld])
        {
            gateid = i;
            break;
        }
    }
    return gateid;
}

stock OpenGate(gateid)
{
    if(gateInfo[gateid][gateStatus] == GATESTATUS_CLOSED)
    {
        MoveDynamicObject(gateInfo[gateid][gateObject], gateInfo[gateid][gateMovePositionX], gateInfo[gateid][gateMovePositionY], gateInfo[gateid][gateMovePositionZ], gateInfo[gateid][gateSpeed], gateInfo[gateid][gateMoveRotationX], gateInfo[gateid][gateMoveRotationY], gateInfo[gateid][gateMoveRotationZ]);
        gateInfo[gateid][gateStatus] = GATESTATUS_MOVEOPEN;
    }
    return 1;
}

stock CloseGate(gateid)
{
    if(gateInfo[gateid][gateStatus] == GATESTATUS_OPENED)
    {
        MoveDynamicObject(gateInfo[gateid][gateObject], gateInfo[gateid][gatePositionX], gateInfo[gateid][gatePositionY], gateInfo[gateid][gatePositionZ], gateInfo[gateid][gateSpeed], gateInfo[gateid][gateRotationX], gateInfo[gateid][gateRotationY], gateInfo[gateid][gateRotationZ]);
        gateInfo[gateid][gateStatus] = GATESTATUS_MOVECLOSE;
    }
    return 1;
}

stock IsGateOpened(gateid)
{
    new status = false;
    if(gateInfo[gateid][gateStatus] == GATESTATUS_OPENED) status = true;
    else status = false;
    return status;
}

stock IsGateClosed(gateid)
{
    new status = false;
    if(gateInfo[gateid][gateStatus] == GATESTATUS_CLOSED) status = true;
    else status = false;
    return status;
}

stock UpdateGateDatabase(gateid)
{
    new fetchChars[3060];  
    mysql_format(sql, fetchChars, sizeof(fetchChars), "UPDATE `gates` SET");
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `ownertype` = '%d', ", fetchChars, gateInfo[gateid][gateOwnerType]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `ownername` = '%e', ", fetchChars, gateInfo[gateid][gateOwnerName]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `password` = '%e', ", fetchChars, gateInfo[gateid][gatePassword]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `model` = '%d', ", fetchChars, gateInfo[gateid][gateModel]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `price` = '%d', ", fetchChars, gateInfo[gateid][gatePrice]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `interior` = '%d', ", fetchChars, gateInfo[gateid][gateInterior]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `virtualworld` = '%d', ", fetchChars, gateInfo[gateid][gateVirtualWorld]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `positionx` = '%f', ", fetchChars, gateInfo[gateid][gatePositionX]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `positiony` = '%f', ", fetchChars, gateInfo[gateid][gatePositionY]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `positionz` = '%f', ", fetchChars, gateInfo[gateid][gatePositionZ]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `rotationx` = '%f', ", fetchChars, gateInfo[gateid][gateRotationX]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `rotationy` = '%f', ", fetchChars, gateInfo[gateid][gateRotationY]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `rotationz` = '%f', ", fetchChars, gateInfo[gateid][gateRotationZ]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `movepositionx` = '%f', ", fetchChars, gateInfo[gateid][gateMovePositionX]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `movepositiony` = '%f', ", fetchChars, gateInfo[gateid][gateMovePositionY]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `movepositionz` = '%f', ", fetchChars, gateInfo[gateid][gateMovePositionZ]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `moverotationx` = '%f', ", fetchChars, gateInfo[gateid][gateMoveRotationX]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `moverotationy` = '%f', ", fetchChars, gateInfo[gateid][gateMoveRotationY]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `moverotationz` = '%f', ", fetchChars, gateInfo[gateid][gateMoveRotationZ]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `speed` = '%f', ", fetchChars, gateInfo[gateid][gateSpeed]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `ownertype` = '%d' WHERE `id` = '%d'", fetchChars, gateInfo[gateid][gateOwnerType], gateid);
    mysql_tquery(sql, fetchChars);
    return 1;
}

function AssignGateDatabase()
{
    static gateid;
    new rows;
    rows = cache_num_rows();
    if(rows)
    {
        for(new i = 0; i < rows; i++)
        {
            cache_get_value_int(i, "id", gateid);
            cache_get_value_int(i, "ownertype", gateInfo[gateid][gateOwnerType]);
            cache_get_value(i, "ownername", gateInfo[gateid][gateOwnerName]);
            cache_get_value(i, "password", gateInfo[gateid][gatePassword]);
            cache_get_value_int(i, "model", gateInfo[gateid][gateModel]);
            cache_get_value_int(i, "price", gateInfo[gateid][gatePrice]);
            cache_get_value_int(i, "interior", gateInfo[gateid][gateInterior]);
            cache_get_value_int(i, "virtualworld", gateInfo[gateid][gateVirtualWorld]);
            cache_get_value_float(i, "positionx", gateInfo[gateid][gatePositionX]);
            cache_get_value_float(i, "positiony", gateInfo[gateid][gatePositionY]);
            cache_get_value_float(i, "positionz", gateInfo[gateid][gatePositionZ]);
            cache_get_value_float(i, "rotationx", gateInfo[gateid][gateRotationX]);
            cache_get_value_float(i, "rotationy", gateInfo[gateid][gateRotationY]);
            cache_get_value_float(i, "rotationz", gateInfo[gateid][gateRotationZ]);
            cache_get_value_float(i, "movepositionx", gateInfo[gateid][gateMovePositionX]);
            cache_get_value_float(i, "movepositiony", gateInfo[gateid][gateMovePositionY]);
            cache_get_value_float(i, "movepositionz", gateInfo[gateid][gateMovePositionZ]);
            cache_get_value_float(i, "moverotationx", gateInfo[gateid][gateMoveRotationX]);
            cache_get_value_float(i, "moverotationy", gateInfo[gateid][gateMoveRotationY]);
            cache_get_value_float(i, "moverotationz", gateInfo[gateid][gateMoveRotationZ]);
            cache_get_value_float(i, "speed", gateInfo[gateid][gateSpeed]);

            Iter_Add(Gate, gateid);
            RefreshGate(gateid);

            #if defined DEBUG_MODE
                printf("[Dynamic Gate] ID: %d Owner Type: %d Owner Name: %s Password: %s Model: %d Price: %s Interior ID: %d World ID: %d position (x: %f y: %f z: %f rx: %f ry: %f rz: %f) move to (x: %f y: %f z: %f rx: %f ry: %f rz: %f) Speed: %f", gateid, gateInfo[gateid][gateOwnerType], gateInfo[gateid][gateOwnerName], gateInfo[gateid][gatePassword], gateInfo[gateid][gateModel], FormatMoney(gateInfo[gateid][gatePrice]),   gateInfo[gateid][gateInterior], gateInfo[gateid][gateVirtualWorld], gateInfo[gateid][gatePositionX], gateInfo[gateid][gatePositionY], gateInfo[gateid][gatePositionZ], gateInfo[gateid][gateRotationX], gateInfo[gateid][gateRotationY], gateInfo[gateid][gateRotationZ], gateInfo[gateid][gateMovePositionX], gateInfo[gateid][gateMovePositionY], gateInfo[gateid][gateMovePositionZ], gateInfo[gateid][gateMoveRotationX], gateInfo[gateid][gateMoveRotationY], gateInfo[gateid][gateMoveRotationZ], gateInfo[gateid][gateSpeed]);
            #endif
        }
    }
    return 1;
}