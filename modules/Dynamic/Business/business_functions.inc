stock CreateBusiness(type, price, Float:x, Float:y, Float:z, Float:a)
{
    new businessid;
    businessid = Iter_Free(Business);

    if(businessid == -1) return 1;

    Iter_Add(Business, businessid);

    format(businessInfo[businessid][businessOwner], MAX_PLAYER_NAME, "Unknown");
    format(businessInfo[businessid][businessName], MAX_BUSINESS_NAME, "%s %s", GetLocation(x, y, z), BusinessTypeName[type]);
    businessInfo[businessid][businessPrice] = price;
    businessInfo[businessid][businessLocked] = 1;
    businessInfo[businessid][businessType] = type;
    businessInfo[businessid][businessMoney] = 0;
    businessInfo[businessid][businessInteriorID] = -1;
    format(businessInfo[businessid][businessRadio], MAX_BUSINESS_RADIOURL, "Unknown");

    businessInfo[businessid][businessExteriorX] = x;
    businessInfo[businessid][businessExteriorY] = y;
    businessInfo[businessid][businessExteriorZ] = z;
    businessInfo[businessid][businessExteriorA] = a;
    businessInfo[businessid][businessInteriorX] = 0.0;
    businessInfo[businessid][businessInteriorY] = 0.0;
    businessInfo[businessid][businessInteriorZ] = 0.0;
    businessInfo[businessid][businessInteriorA] = 0.0;

    new query[500];
    mysql_format(sql, query, sizeof(query), "INSERT INTO `business` (`id`) VALUE ('%d')", businessid);
    mysql_tquery(sql, query, "OnCreateBusiness", "dddffff", businessid, type, price, x, y, z, a);
    return businessid;
}

stock RefreshBusiness(businessid) 
{
    SetTimerEx("timer_RefreshBusiness", 3000, false, "d", businessid);
    return 1;
}

function timer_RefreshBusiness(businessid) 
{
    if(!Iter_Contains(Business, businessid)) return 1;

    UpdateBusinessData(businessid);

    if(IsValidDynamicPickup(businessInfo[businessid][businessEnterPickup]))
        DestroyDynamicPickup(businessInfo[businessid][businessEnterPickup]);
    
    if(IsValidDynamicCP(businessInfo[businessid][businessEnterCheckpoint]))
        DestroyDynamicCP(businessInfo[businessid][businessEnterCheckpoint]);

    if(IsValidDynamic3DTextLabel(businessInfo[businessid][businessEnterLabel]))
        DestroyDynamic3DTextLabel(businessInfo[businessid][businessEnterLabel]);

    if(IsValidDynamicPickup(businessInfo[businessid][businessExitPickup]))
        DestroyDynamicPickup(businessInfo[businessid][businessExitPickup]);
    
    if(IsValidDynamicCP(businessInfo[businessid][businessExitCheckpoint]))
        DestroyDynamicCP(businessInfo[businessid][businessExitCheckpoint]);

    new Float:enter_x, Float:enter_y, Float:enter_z, Float:enter_a, enter_text[1000];
    GetBusinessExterior(businessid, enter_x, enter_y, enter_z, enter_a);

    if(!strcmp(GetBusinessOwner(businessid), "Unknown"))
    {
        format(enter_text, sizeof(enter_text), ""GREY"[ID: %d]\n"LG"%s\n"WHITE"Type: "LB"%s\n"WHITE"Price: "LG"$%s\n"YELLOW"Bisnis ini dijual, gunakan '/buybusiness' untuk membeli bisnis", businessid, GetBusinessName(businessid), BusinessTypeName[GetBusinessType(businessid)], FormatMoney(GetBusinessPrice(businessid)));
    }
    else
    {
        format(enter_text, sizeof(enter_text), ""GREY"[ID: %d]\n"LG"%s\n"WHITE"Type: "LB"%s\n"WHITE"Owner: "YELLOW"%s", businessid, GetBusinessName(businessid), BusinessTypeName[GetBusinessType(businessid)], GetBusinessOwner(businessid));
    }

    businessInfo[businessid][businessEnterPickup] = CreateDynamicPickup(19133, 23, enter_x, enter_y, enter_z, 0, 0, -1);
    businessInfo[businessid][businessEnterCheckpoint] = CreateDynamicCP(enter_x, enter_y, enter_z, 2.5, 0, 0, -1, 5.0);
    businessInfo[businessid][businessEnterLabel] = CreateDynamic3DTextLabel(enter_text, COLOR_WHITE, enter_x, enter_y, enter_z + 0.3, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0);
    
    new Float:exit_x, Float:exit_y, Float:exit_z, Float:exit_a, exit_interior;
    GetBusinessInterior(businessid, exit_x, exit_y, exit_z, exit_a);
    exit_interior = GetBusinessInteriorID(businessid);
    businessInfo[businessid][businessExitPickup] = CreateDynamicPickup(19133, 23, exit_x, exit_y, exit_z, businessid, exit_interior, -1);
    businessInfo[businessid][businessExitCheckpoint] = CreateDynamicCP(exit_x, exit_y, exit_z, 2.5, businessid, exit_interior, -1, 5.0);
    return 1;
}

stock UpdateBusinessData(businessid) 
{
    new cQuery[3048];
    mysql_format(sql, cQuery, sizeof(cQuery), "UPDATE `business` SET ");
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`owner` = '%e', ", cQuery, businessInfo[businessid][businessOwner]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`name` = '%e', ", cQuery, businessInfo[businessid][businessName]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`price` = '%d', ", cQuery, businessInfo[businessid][businessPrice]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`locked` = '%d', ", cQuery, businessInfo[businessid][businessLocked]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`type` = '%d', ", cQuery, businessInfo[businessid][businessType]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`money` = '%d', ", cQuery, businessInfo[businessid][businessMoney]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`interiorid` = '%d', ", cQuery, businessInfo[businessid][businessInteriorID]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`exteriorx` = '%f', ", cQuery, businessInfo[businessid][businessExteriorX]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`exteriory` = '%f', ", cQuery, businessInfo[businessid][businessExteriorY]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`exteriorz` = '%f', ", cQuery, businessInfo[businessid][businessExteriorZ]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`exteriora` = '%f', ", cQuery, businessInfo[businessid][businessExteriorA]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`interiorx` = '%f', ", cQuery, businessInfo[businessid][businessInteriorX]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`interiory` = '%f', ", cQuery, businessInfo[businessid][businessInteriorY]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`interiorz` = '%f', ", cQuery, businessInfo[businessid][businessInteriorZ]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`interiora` = '%f', ", cQuery, businessInfo[businessid][businessInteriorA]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`fuelamount` = '%f', ", cQuery, businessInfo[businessid][businessFuelAmount]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`fuelprice` = '%d', ", cQuery, businessInfo[businessid][businessFuelPrice]);
	mysql_format(sql, cQuery, sizeof(cQuery), "%s`radio` = '%e' WHERE `id` = '%d'", cQuery, businessInfo[businessid][businessRadio], businessid);
	mysql_tquery(sql, cQuery);
	return 1;
}

stock IsPlayerHaveBusiness(playerid) 
{
    new bool:status = false;
    foreach(new i : Business)
    {
        if(!strcmp(GetBusinessName(i), playerInfo[playerid][playerName], true))
        {
            status = true;
            break;
        }
    }
    return status;
}

stock IsPlayerBusinessOwner(playerid, businessid) 
{
    new bool:status = false;
    if(!strcmp(GetBusinessName(businessid), playerInfo[playerid][playerName], true)) 
    {
        status = true;
    }
    return status;
}

stock IsBusinessHaveInterior(businessid)
{
    new Float:interior_x, Float:interior_y, Float:interior_z, Float:interior_a, interior_id, bool:status = true;

    interior_id = GetBusinessInteriorID(businessid);
    GetBusinessInterior(businessid, interior_x, interior_y, interior_z, interior_a);

    if(interior_id == -1) status = false;
    else if(interior_x == 0.0) status = false;
    else if(interior_y == 0.0) status = false;
    else if(interior_z == 0.0) status = false;
    else if(interior_a == 0.0) status = false;
    return status;
}

// -------------------------------------------------------------------------
// Core
// -------------------------------------------------------------------------
stock SetBusinessOwner(businessid, const owner_name[]) 
{
    format(businessInfo[businessid][businessOwner], MAX_PLAYER_NAME, owner_name);
    RefreshBusiness(businessid);
    return 1;
}

stock SetBusinessName(businessid, const str[]) 
{
    format(businessInfo[businessid][businessName], MAX_BUSINESS_NAME + 1, str);
    RefreshBusiness(businessid);
    return 1;
}

stock SetBusinessPrice(businessid, price) 
{
    businessInfo[businessid][businessPrice] = price;
    RefreshBusiness(businessid);
    return 1;
}

stock SetBusinessLocked(businessid, bool:locked) 
{
    if(locked == true) businessInfo[businessid][businessLocked] = 1;
    else if(locked == false) businessInfo[businessid][businessLocked] = 0;
    return 1;
}

stock SetBusinessType(businessid, type) 
{
    businessInfo[businessid][businessType] = type;
    RefreshBusiness(businessid);
    return 1;
}

stock SetBusinessMoney(businessid, money) 
{
    businessInfo[businessid][businessMoney] = money;
    UpdateBusinessData(businessid);
    return 1;
}

stock GiveBusinessMoney(businessid, amount) 
{
    businessInfo[businessid][businessMoney] += amount;
    UpdateBusinessData(businessid);
    return 1;
}

stock GiveBusinessFuel(businessid, Float:amount) 
{
    businessInfo[businessid][businessFuelAmount] += amount;
    UpdateBusinessData(businessid);
    return 1;
}

stock GetBusinessFuelPrice(businessid) 
{
    new amount = businessInfo[businessid][businessFuelPrice];
    return amount;
}

stock GetBusinessFuelAmount(businessid, &Float:amount) 
{
    amount = businessInfo[businessid][businessFuelAmount];
    return 1;
}

stock SetBusinessInteriorID(businessid, interior) 
{
    businessInfo[businessid][businessInteriorID] = interior;
    RefreshBusiness(businessid);
    return 1;
}

stock SetBusinessRadio(businessid, const radio[])
{
    format(businessInfo[businessid][businessRadio], MAX_BUSINESS_RADIOURL + 1, radio);
    RefreshBusiness(businessid);
    return 1;
}

stock SetBusinessExterior(businessid, Float:x, Float:y, Float:z, Float:a)  
{
    businessInfo[businessid][businessExteriorX] = x;
    businessInfo[businessid][businessExteriorY] = y;
    businessInfo[businessid][businessExteriorZ] = z;
    businessInfo[businessid][businessExteriorA] = a;
    RefreshBusiness(businessid);
    return 1;
}

stock SetBusinessInterior(businessid, Float:x, Float:y, Float:z, Float:a) 
{
    businessInfo[businessid][businessInteriorX] = x;
    businessInfo[businessid][businessInteriorY] = y;
    businessInfo[businessid][businessInteriorZ] = z;
    businessInfo[businessid][businessInteriorA] = a;
    RefreshBusiness(businessid);
    return 1;
}

stock GetBusinessOwner(businessid) 
{
    new owner[MAX_PLAYER_NAME + 1];
    format(owner, sizeof(owner), "%s", businessInfo[businessid][businessOwner]);
    return owner;
}

stock GetBusinessName(businessid)
{
    new name[MAX_BUSINESS_NAME + 1];
    format(name, sizeof(name), "%s", businessInfo[businessid][businessName]);
    return name;
}

stock GetBusinessPrice(businessid) 
{
    new price;
    price = businessInfo[businessid][businessPrice];
    return price;
}

stock GetBusinessLocked(businessid) 
{
    new status;
    status = businessInfo[businessid][businessLocked];
    return status;
}

stock GetBusinessType(businessid) 
{
    new type;
    type = businessInfo[businessid][businessType];
    return type; 
}

stock GetBusinessMoney(businessid) 
{
    new money;
    money = businessInfo[businessid][businessMoney];
    return money; 
}

stock GetBusinessInteriorID(businessid) 
{
    new interiorid;
    interiorid = businessInfo[businessid][businessInteriorID];
    return interiorid;
}

stock GetBusinessRadio(businessid) 
{
    new radio[MAX_BUSINESS_RADIOURL + 1];
    format(radio, sizeof(radio), "%s", businessInfo[businessid][businessRadio]);
    return radio;
}

stock GetBusinessExterior(businessid, &Float:x, &Float:y, &Float:z, &Float:a) 
{
    x = businessInfo[businessid][businessExteriorX];
    y = businessInfo[businessid][businessExteriorY];
    z = businessInfo[businessid][businessExteriorZ];
    a = businessInfo[businessid][businessExteriorA];
    return 1;
}

stock GetBusinessInterior(businessid, &Float:x, &Float:y, &Float:z, &Float:a) 
{
    x = businessInfo[businessid][businessInteriorX];
    y = businessInfo[businessid][businessInteriorY];
    z = businessInfo[businessid][businessInteriorZ];
    a = businessInfo[businessid][businessInteriorA];
    return 1;
}

stock IsValidBusiness(businessid)
{
    new bool:status = false;
    if(Iter_Contains(Business, businessid)) status = true;
    return status;
}

stock GetPlayerNearestBusiness(playerid) 
{
    new businessid = -1;

    foreach(new i : Business) 
    {
        if(IsPlayerInDynamicArea(playerid, businessInfo[i][businessEnterCheckpoint]) || playerInfo[playerid][playerInBusiness] == i)
        {
            businessid = i;
            break;
        }
    }
    return businessid;
}