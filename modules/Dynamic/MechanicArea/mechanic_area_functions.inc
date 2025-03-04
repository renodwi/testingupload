stock AddMechanicArea(Float:fx, Float:fy, Float:tx, Float:ty) 
{
    new areaid = Iter_Free(MechanicArea);
    if(areaid == cellmax) return -1;

    mechanicareaInfo[areaid][mechanicareaFrom][0] = fx;
    mechanicareaInfo[areaid][mechanicareaFrom][1] = fy;
    mechanicareaInfo[areaid][mechanicareaTo][0] = tx;
    mechanicareaInfo[areaid][mechanicareaTo][1] = ty;

    Iter_Add(MechanicArea, areaid);

    new query[700];
    mysql_format(sql, query, sizeof(query), "INSERT INTO `mechanic_area` (`id`, `fromx`, `fromy`, `tox`, `toy`) VALUES ('%d', '%f', '%f', '%f', '%f')", areaid, fx, fy, tx, ty);
    mysql_tquery(sql, query, "OnMechanicAreaCreated", "d", areaid);

    RefreshMechanicArea(areaid);
    return areaid;
}

stock LoadMechanicArea()
{
    Iter_Clear(MechanicArea);
    mysql_tquery(sql, "SELECT * FROM `mechanic_area`", "AssignMechanicAreaData");
    return 1;
}

stock DeleteMechanicArea(areaid) 
{
    if(!Iter_Contains(MechanicArea, areaid)) return 1;

    new query[700];
    mysql_format(sql, query, sizeof(query), "DELETE FROM `mechanic_area` WHERE `id` = '%d'", mechanicareaInfo[areaid][mechanicareaDBID]);
    mysql_tquery(sql, query);

    Iter_Remove(MechanicArea, areaid);

    LoadMechanicArea();
    return 1;
}

stock RefreshMechanicArea(areaid) 
{
    if(!Iter_Contains(MechanicArea, areaid)) return 1;

    if(IsValidDynamicArea(mechanicareaInfo[areaid][mechanicareaID]))
        DestroyDynamicArea(mechanicareaInfo[areaid][mechanicareaID]);
    
    mechanicareaInfo[areaid][mechanicareaID] = CreateDynamicRectangle(mechanicareaInfo[areaid][mechanicareaFrom][0], mechanicareaInfo[areaid][mechanicareaFrom][1], mechanicareaInfo[areaid][mechanicareaTo][0], mechanicareaInfo[areaid][mechanicareaTo][1]);
    return 1;
}

stock RefreshPlayerCreateMechArea(playerid) 
{
    if(IsValidDynamic3DTextLabel(player_create_mecharea_label[playerid][0]))
        DestroyDynamic3DTextLabel(player_create_mecharea_label[playerid][0]);

    if(IsValidDynamicPickup(player_create_mecharea_pickup[playerid][0]))
        DestroyDynamicPickup(player_create_mecharea_pickup[playerid][0]);
    
    if(IsValidDynamic3DTextLabel(player_create_mecharea_label[playerid][1]))
        DestroyDynamic3DTextLabel(player_create_mecharea_label[playerid][1]);

    if(IsValidDynamicPickup(player_create_mecharea_pickup[playerid][1]))
        DestroyDynamicPickup(player_create_mecharea_pickup[playerid][1]);

    new message[500];
    format(message, sizeof(message), ""LB"Create Mechanic Area\n"YELLOW"[From X: %f] [From Y: %f]\n"YELLOW"[To X: %f] [To Y: %f]", player_create_mecharea[playerid][0][0], player_create_mecharea[playerid][0][1], player_create_mecharea[playerid][1][0], player_create_mecharea[playerid][1][1]);
    player_create_mecharea_label[playerid][0] = CreateDynamic3DTextLabel(message, COLOR_WHITE, player_create_mecharea[playerid][0][0], player_create_mecharea[playerid][0][1], player_create_mecharea[playerid][0][2], 10.0);
    player_create_mecharea_label[playerid][1] = CreateDynamic3DTextLabel(message, COLOR_WHITE, player_create_mecharea[playerid][1][0], player_create_mecharea[playerid][1][1], player_create_mecharea[playerid][1][2], 10.0);
    player_create_mecharea_pickup[playerid][0] = CreateDynamicPickup(1239, 23, player_create_mecharea[playerid][0][0], player_create_mecharea[playerid][0][1], player_create_mecharea[playerid][0][2]);
    player_create_mecharea_pickup[playerid][1] = CreateDynamicPickup(1239, 23, player_create_mecharea[playerid][1][0], player_create_mecharea[playerid][1][1], player_create_mecharea[playerid][1][2]);

    Streamer_Update(playerid);
    return 1;
}