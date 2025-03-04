hook OnGameModeInit()
{
    AddAdminCommand(Manager, "/business", "Digunakan untuk membuka menu bisnis admin");
    return 1;
}

hook OnServerAssignData()
{
    mysql_tquery(sql, "SELECT * FROM `business`", "AssignBusinessData");
    return 1;
}

hook OnCreateBusiness(businessid, type, price, Float:x, Float:y, Float:z, Float:a) 
{
    RefreshBusiness(businessid);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(IsKeyJustDown(KEY_SECONDARY_ATTACK, newkeys, oldkeys))
    {
        if(playerInfo[playerid][playerInBusiness] != -1 && Iter_Contains(Business, playerInfo[playerid][playerInBusiness]))
        {
            new businessid = playerInfo[playerid][playerInBusiness];

            if(IsPlayerInDynamicCP(playerid, businessInfo[businessid][businessExitCheckpoint]))
            {
                new Float:enter_x, Float:enter_y, Float:enter_z, Float:enter_a;
                GetBusinessExterior(businessid, enter_x, enter_y, enter_z, enter_a);

                SetPlayerPos(playerid, enter_x, enter_y, enter_z);
                SetPlayerFacingAngle(playerid, enter_a);
                SetPlayerVirtualWorld(playerid, 0);
                SetPlayerInterior(playerid, 0);
                
                playerInfo[playerid][playerInBusiness] = -1;
            }
        }
        else 
        {
            foreach(new businessid : Business) 
            {
                if(IsPlayerInDynamicCP(playerid, businessInfo[businessid][businessEnterCheckpoint]))
                {
                    if(!IsBusinessHaveInterior(businessid))
                        return GameTextForPlayer(playerid, "~r~~h~Bisnis tidak memiliki interior", 3000, 1);

                    if(GetBusinessLocked(businessid) || !strcmp(GetBusinessOwner(businessid), "Unknown", true))
                        return GameTextForPlayer(playerid, "~r~~h~Bisnis Terkunci", 3000, 1);

                    new Float:exit_x, Float:exit_y, Float:exit_z, Float:exit_a;
                    GetBusinessInterior(businessid, exit_x, exit_y, exit_z, exit_a);
                    SetPlayerVirtualWorld(playerid, businessid);
                    SetPlayerInterior(playerid, GetBusinessInteriorID(businessid));
                    SetPlayerPos(playerid, exit_x, exit_y, exit_z);
                    SetPlayerFacingAngle(playerid, exit_a);
                    
                    playerInfo[playerid][playerInBusiness] = businessid;

                    if(IsPlayerBusinessOwner(playerid, businessid))
                    {
                        SendClientMessageEx(playerid, COLOR_REN, "BUSINESS: "WHITE"Anda adalah pemilik bisnis ini, gunakan "YELLOW"/businessmenu"WHITE" atau "YELLOW"/bm"WHITE" untuk menu bisnis");
                    }
                }
            }
        }
    }
    return 1;
}

function AssignBusinessData()
{
    static businessid;

	new rows  = cache_num_rows();
 	if(rows)
  	{
		for(new i; i < rows; i++)
		{
            cache_get_value_int(i, "id", businessid);
            cache_get_value(i, "owner", businessInfo[businessid][businessOwner]);
            cache_get_value(i, "name", businessInfo[businessid][businessName]);
            cache_get_value_int(i, "price", businessInfo[businessid][businessPrice]);
            cache_get_value_int(i, "locked", businessInfo[businessid][businessLocked]);
            cache_get_value_int(i, "type", businessInfo[businessid][businessType]);
            cache_get_value_int(i, "money", businessInfo[businessid][businessMoney]);
            cache_get_value_int(i, "interiorid", businessInfo[businessid][businessInteriorID]);
            cache_get_value_float(i, "exteriorx", businessInfo[businessid][businessExteriorX]);
            cache_get_value_float(i, "exteriory", businessInfo[businessid][businessExteriorY]);
            cache_get_value_float(i, "exteriorz", businessInfo[businessid][businessExteriorZ]);
            cache_get_value_float(i, "exteriora", businessInfo[businessid][businessExteriorA]);
            cache_get_value_float(i, "interiorx", businessInfo[businessid][businessInteriorX]);
            cache_get_value_float(i, "interiory", businessInfo[businessid][businessInteriorY]);
            cache_get_value_float(i, "interiorz", businessInfo[businessid][businessInteriorZ]);
            cache_get_value_float(i, "interiora", businessInfo[businessid][businessInteriorA]);
            cache_get_value_float(i, "fuelamount", businessInfo[businessid][businessFuelAmount]);
            cache_get_value_int(i, "fuelprice", businessInfo[businessid][businessFuelPrice]);
            cache_get_value(i, "radio", businessInfo[businessid][businessRadio]);

            LoadBusinessLog(businessid);
            LoadBusinessBuyPoint(businessid);
            
            Iter_Add(Business, businessid);
            RefreshBusiness(businessid);

            #if defined DEBUG_MODE
                printf("[Dynamic Business] ID: %d Owner: %s Name: %s Price: $%s Locked: %d Type: %s Money: $%s Interior ID: %d position (x: %f y: %f z: %f a:%f intx: %f inty: %f intz: %f inta: %f) Fuel: %f FuelPrice: $%s Radio: %s", businessid, businessInfo[businessid][businessOwner], businessInfo[businessid][businessName], FormatMoney(businessInfo[businessid][businessPrice]), businessInfo[businessid][businessLocked], BusinessTypeName[businessInfo[businessid][businessType]], FormatMoney(businessInfo[businessid][businessMoney]), businessInfo[businessid][businessInteriorID], businessInfo[businessid][businessExteriorX], businessInfo[businessid][businessExteriorY], businessInfo[businessid][businessExteriorZ], businessInfo[businessid][businessExteriorA], businessInfo[businessid][businessInteriorX], businessInfo[businessid][businessInteriorY], businessInfo[businessid][businessInteriorZ], businessInfo[businessid][businessInteriorA], businessInfo[businessid][businessFuelAmount], businessInfo[businessid][businessFuelPrice], businessInfo[businessid][businessRadio]);
            #endif
		}
	}
    return 1;
}