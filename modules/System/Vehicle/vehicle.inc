#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    ManualVehicleEngineAndLights();
    return 1;
}

new vehicle_interior[MAX_VEHICLES];
new vehicle_color[MAX_VEHICLES][2];
new vehicle_paintjob[MAX_VEHICLES];

/* Owner Type */
enum // Vehicle Owner Type
{
    VEHICLE_OWNER_UNKNOWN,
    
    VEHICLE_OWNER_ADMIN,
    VEHICLE_OWNER_PLAYER,

    VEHICLE_OWNER_SAPD,
    VEHICLE_OWNER_SAMD,
    VEHICLE_OWNER_SANEWS,

    VEHICLE_OWNER_SWEEPER,
    VEHICLE_OWNER_DEALERSHIP,
}

hook OnPlayerStateChange(playerid, PLAYER_STATE:newstate, PLAYER_STATE:oldstate)
{
    if (oldstate == PLAYER_STATE_ONFOOT && newstate == PLAYER_STATE_DRIVER) // Player entered a vehicle as a driver
    {
        new vehicleid = GetPlayerVehicleID(playerid);
        CallLocalFunction("OnPlayerInVehicle", "dd", playerid, vehicleid);
    }
    else if (oldstate == PLAYER_STATE_DRIVER && newstate == PLAYER_STATE_ONFOOT) // Player exited a vehicle as a driver
    {
        new vehicleid = GetPlayerVehicleID(playerid);
        CallLocalFunction("OnPlayerOutVehicle", "dd", playerid, vehicleid);
    }
    return 1;
}

stock n_LinkVehicleToInterior(vehicleid, interiorid)
{
    LinkVehicleToInterior(vehicleid, interiorid);
    vehicle_interior[vehicleid] = interiorid;
    return interiorid;
}

#if defined _ALS_LinkVehicleToInterior
	#undef LinkVehicleToInterior
#else
	#define _ALS_LinkVehicleToInterior
#endif
#define LinkVehicleToInterior n_LinkVehicleToInterior
#define SetVehicleInterior LinkVehicleToInterior

stock GetVehicleInterior(vehicleid) 
{
    new value = vehicle_interior[vehicleid];
    return value;
}

stock n_CreateVehicle(vehicletype, Float:x, Float:y, Float:z, Float:rotation, color1, color2, respawn_delay, bool:addsiren)
{
    new vehicleid = CreateVehicle(vehicletype, x, y, z, rotation, color1, color2, respawn_delay, addsiren);
    CallLocalFunction("OnVehicleCreated", "d", vehicleid);

    vehicle_color[vehicleid][0] = color1;
    vehicle_color[vehicleid][1] = color2;
    vehicle_paintjob[vehicleid] = -1;
    vehicle_interior[vehicleid] = 0;
    return vehicleid;
}

#if defined _ALS_CreateVehicle
	#undef CreateVehicle
#else
	#define _ALS_CreateVehicle
#endif
#define CreateVehicle n_CreateVehicle

stock n_DestroyVehicle(vehicleid)
{
    if(!IsValidVehicle(vehicleid)) return 1;
    DestroyVehicle(vehicleid);

    CallLocalFunction("OnVehicleDestroyed", "d", vehicleid);
    return vehicleid;
}

#if defined _ALS_DestroyVehicle
	#undef DestroyVehicle
#else
	#define _ALS_DestroyVehicle
#endif
#define DestroyVehicle n_DestroyVehicle

stock n_ChangeVehicleColor(vehicleid, color1, color2) 
{
    if(!IsValidVehicle(vehicleid)) return 1;

    vehicle_color[vehicleid][0] = color1;
    vehicle_color[vehicleid][1] = color2;
    ChangeVehicleColor(vehicleid, color1, color2);
    return 1;
}

#if defined _ALS_ChangeVehicleColor
	#undef ChangeVehicleColor
#else
	#define _ALS_ChangeVehicleColor
#endif
#define ChangeVehicleColor n_ChangeVehicleColor

stock GetVehicleColor(vehicleid, &color1, &color2) 
{
    color1 = vehicle_color[vehicleid][0];
    color2 = vehicle_color[vehicleid][1];
    return 1;
}

stock n_ChangeVehiclePaintjob(vehicleid, paintjobid)
{
    ChangeVehiclePaintjob(vehicleid, paintjobid);
    vehicle_paintjob[vehicleid] = paintjobid;
    return 1;
}

#if defined _ALS_ChangeVehiclePaintjob
	#undef ChangeVehiclePaintjob
#else
	#define _ALS_ChangeVehiclePaintjob
#endif
#define ChangeVehiclePaintjob n_ChangeVehiclePaintjob

stock GetVehiclePaintjob(vehicleid, &paintjobid) 
{
    paintjobid = vehicle_paintjob[vehicleid];
    return 1;
}

#include "modules\System\Vehicle\vehicle_global_library.inc"
#include "modules\System\Vehicle\VehicleHealth\vehicle_health.inc"
#include "modules\System\Vehicle\VehicleFuel\vehicle_fuel.inc"
#include "modules\System\Vehicle\VehicleLight\vehicle_light.inc"
#include "modules\System\Vehicle\VehicleEngine\vehicle_engine.inc"
#include "modules\System\Vehicle\VehicleOwner\vehicle_owner.inc"
#include "modules\System\Vehicle\VehicleSpawnPos\vehicle_spawnpos.inc"
#include "modules\System\Vehicle\VehicleLocked\vehicle_locked.inc"
#include "modules\System\Vehicle\VehiclePlate\vehicle_plate.inc"
#include "modules\System\Vehicle\VehicleUpgrade\vehicle_upgrade.inc"
#include "modules\System\Vehicle\VehicleModification\vehicle_modification.inc"
#include "modules\System\Vehicle\VehicleMechanics\vehicle_mechanics.inc"

#include "modules\System\Vehicle\vehicle_commands.inc"  

YCMD:sultan(playerid, params[], help) 
{
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);

    CreateVehicle(560, x, y, z, 90.0, 2, 2, 0, true);
    return 1;
}

YCMD:nrg(playerid, params[], help) 
{
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);

    CreateVehicle(522, x, y, z, 90.0, 2, 2, 0, true);
    return 1;
}