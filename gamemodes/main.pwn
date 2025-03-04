/*

		$$$$$$$\                  $$\                           $$\           $$$$$$$\                                                $$\     
		$$  __$$\                 $$ |                          $$ |          $$  __$$\                                               $$ |    
		$$ |  $$ |$$$$$$$\   $$$$$$$ |$$\  $$\  $$\  $$$$$$$\ $$$$$$\         $$ |  $$ | $$$$$$\   $$$$$$\  $$\  $$$$$$\   $$$$$$$\ $$$$$$\   
		$$$$$$$  |$$  __$$\ $$  __$$ |$$ | $$ | $$ |$$  _____|\_$$  _|        $$$$$$$  |$$  __$$\ $$  __$$\ \__|$$  __$$\ $$  _____|\_$$  _|  
		$$  __$$< $$ |  $$ |$$ /  $$ |$$ | $$ | $$ |\$$$$$$\    $$ |          $$  ____/ $$ |  \__|$$ /  $$ |$$\ $$$$$$$$ |$$ /        $$ |    
		$$ |  $$ |$$ |  $$ |$$ |  $$ |$$ | $$ | $$ | \____$$\   $$ |$$\       $$ |      $$ |      $$ |  $$ |$$ |$$   ____|$$ |        $$ |$$\ 
		$$ |  $$ |$$ |  $$ |\$$$$$$$ |\$$$$$\$$$$  |$$$$$$$  |  \$$$$  |      $$ |      $$ |      \$$$$$$  |$$ |\$$$$$$$\ \$$$$$$$\   \$$$$  |
		\__|  \__|\__|  \__| \_______| \_____\____/ \_______/    \____/       \__|      \__|       \______/ $$ | \_______| \_______|   \____/ 
																									$$\   $$ |                              
																									\$$$$$$  |                              
																									 \______/      

									-----------------------------------------------------------------   
									|				Dev. Reno Dwi Setyangga 2022					|
                                    |             There is no limit to your dreams                  |
									-----------------------------------------------------------------

𝙸 𝚗      𝚃 𝚑 𝚎      𝙽 𝚊 𝚖 𝚎      𝙾 𝚏      𝙹 𝚞 𝚜 𝚝 𝚒 𝚌 𝚎
-------------------------------------------------------------------------------------------------
  ______       _         _____ _                     _____                                          _      
 |  ____|     (_)       / ____| |                   / ____|                                        | |     
 | |__   _ __  _  ___  | |  __| | ___  _ __ _   _  | |  __  __ _ _ __ ___   ___ _ __ ___   ___   __| | ___ 
 |  __| | '_ \| |/ __| | | |_ | |/ _ \| '__| | | | | | |_ |/ _` | '_ ` _ \ / _ \ '_ ` _ \ / _ \ / _` |/ _ \
 | |____| |_) | | (__  | |__| | | (_) | |  | |_| | | |__| | (_| | | | | | |  __/ | | | | | (_) | (_| |  __/
 |______| .__/|_|\___|  \_____|_|\___/|_|   \__, |  \_____|\__,_|_| |_| |_|\___|_| |_| |_|\___/ \__,_|\___|
        | |                                  __/ |                                                         
        |_|                                 |___/                                                          

	[Terimakasih Kepada]
	* Kalcor (Kye) SAMP Developer
	* Y_Less (sscanf, YSI, dan fungsi lainnya)
	* BlueG, maddinat0r (a_mysql plugin)
	* Southclaw (Progressbar2, dan fungsi lainnya)
	* RenoDwi (scripter)
*/


/* ======================= Library ======================= */

#define CGEN_MEMORY 50000

#include <a_samp>
#include <a_mysql>
#include <streamer>
#include <YSI_Coding\y_va>
#include <YSI_Coding\y_timers>
#include <YSI_Visual\y_commands>
#include <YSI_Players\y_android>
#include <YSI_Game\y_vehicledata>
#include <sscanf2>
#include <samp_bcrypt>
#include <chrono>
#include <strlib>
#define MAX_RNDWSTSELECTION_ITEM 260
#include <rndwstLoadingBar>
#include <rndwstSelection>
#include <RndwstCL>
#include <realtime-clock>
#include <mapandreas>
#include <colour-manipulation>

#include "./extracode/easydialog.inc"
#include "./extracode/ndialog-pages.inc"
// #include "./extracode/progress2.inc"

/* ======================= Code Start ======================= */

#define function%0(%1) forward %0(%1); public %0(%1)
#define SendUsageMessage(%0,%1) SendClientMessageEx(%0, COLOR_ORANGE, "USAGE: "WHITE""%1)
#define SendServerMessage(%1,%2) SendClientMessageEx(%1, COLOR_YELLOW, "SERVER: "WHITE""%2)
#define SendInfoMessage(%1,%2) SendClientMessageEx(%1, COLOR_LIGHTBLUE, "INFO: "WHITE""%2)
#define SendErrorMessage(%1,%2) SendClientMessageEx(%1, COLOR_GREY, "ERROR: "%2),PlayerPlaySound(%1, 1085, 0.0, 0.0, 10.0)
#define Loop(%0,%1) for(new %0 = 0; %0 < %1; %0++)
#define IsPlayerAndroid IsAndroidPlayer
#define PlayMechSound(%0) PlayerPlaySound(%0, 1133, 0.0, 0.0, 10.0)
#define PlaySpraySound(%0) PlayerPlaySound(%0, 1134, 0.0, 0.0, 10.0)

#define DEBUG_MODE

#define UNKNOWN_CP_TYPE	-1	    
#define CP_TYPE_GROUND_NORMAL 0	
#define CP_TYPE_GROUND_FINISH 1	
#define CP_TYPE_GROUND_EMPTY 2	
#define CP_TYPE_AIR_NORMAL 3	
#define CP_TYPE_AIR_FINISH 4	
#define CP_TYPE_AIR_ROTATING 5	
#define CP_TYPE_AIR_STROBING 6	
#define CP_TYPE_AIR_SWINGING 7	
#define CP_TYPE_AIR_BOBBING	8	 

/*
    Sound ID List for use
    - Click enter / response dialog     = 1083
    - Click esc / !response dialog      = 1084
    - Pickup sound                      = 1150
    - Buy Car Mod                       = 1133
    - Car respray                       = 1134
    - Error                             = 1085
    - Counting                          = 1138
    - GO                                = 1056

    PO 1
    Po 2
    PO 3
    SGT 1
    SGT 2
    Liutenant
    Captent
    skertaris
    Commander
    Deputy
    Assistant Deputy
    Chief Of Police

    Next Code:
    - Quiz
*/

#define GENDER_MALE 0
#define GENDER_FEMALE 1
new MaleSkinList[185] = {
	1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
	30, 32, 33, 34, 35, 36, 37, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 57, 58, 59, 60,
	61, 62, 66, 68, 72, 73, 78, 79, 80, 81, 82, 83, 84, 94, 95, 96, 97, 98, 99, 100, 101, 102,
	103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120,
	121, 122, 123, 124, 125, 126, 127, 128, 132, 133, 134, 135, 136, 137, 142, 143, 144, 146,
	147, 153, 154, 155, 156, 158, 159, 160, 161, 162, 167, 168, 170, 171, 173, 174, 175, 176,
	177, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 200, 202, 203, 204, 206,
	208, 209, 210, 212, 213, 217, 220, 221, 222, 223, 228, 229, 230, 234, 235, 236, 239, 240,
	241, 242, 247, 248, 249, 250, 253, 254, 255, 258, 259, 260, 261, 262, 268, 272, 273, 289,
	290, 291, 292, 293, 294, 295, 296, 297, 299
};

new FemaleSkinList[77] = {
    9, 10, 11, 12, 13, 31, 38, 39, 40, 41, 53, 54, 55, 56, 63, 64, 65, 69,
    75, 76, 77, 85, 88, 89, 90, 91, 92, 93, 129, 130, 131, 138, 140, 141,
    145, 148, 150, 151, 152, 157, 169, 178, 190, 191, 192, 193, 194, 195,
    196, 197, 198, 199, 201, 205, 207, 211, 214, 215, 216, 219, 224, 225,
    226, 231, 232, 233, 237, 238, 243, 244, 245, 246, 251, 256, 257, 263,
    298
}; 

new factionNames[][] = {
    "San Andreas Police Department",
    "San Andreas Medical Department",
    "San Andreas Media Department"
};

enum
{
    EDITINGOBJECT_GATEPOSITION,
    EDITINGOBJECT_GATEMOVEPOSITION,
	EDITOBJECT_ATM,
    EDITOBJECT_GASPUMP
}

/* Job Type */
enum // Job Type
{
    JOB_NONE = 0,
    JOB_MECHANIC,
}

main() 
{
	print("\n----------------------------------------------------------------");
	print("  Indonesische Roleplay Loaded | Web: https://bit.ly/rndwstweb ");
	print("----------------------------------------------------------------\n");
}

public OnAndroidCheck(playerid, bool:isDisgustingThiefToBeBanned)
{
	if (isDisgustingThiefToBeBanned)
	{
		// Ban(playerid);
	}
}

#include "modules\server\public_enum.inc"
#include "modules\server\database_connect.inc"
#include "modules\server\initialize.inc"
#include "modules\server\server_information.inc"

#include "modules\server\colors.inc"
#include "modules\server\components.inc"
#include "modules\Fix_Code\chatbubble.inc"
#include "modules\Fix_Code\get_server_online_player.inc"
#include "modules\Fix_Code\kick.inc"
#include "modules\Fix_Code\sendrconcommand.inc"
#include "modules\Fix_Code\textdraw_cursor.inc"
#include "modules\Fix_Code\weaponname.inc"
#include "modules\Fix_Code\get_server_online_player.inc"
#include "modules\player\playerinfobox.inc"
#include "modules\Fix_Code\set_player_money.inc"
#include "modules\player\playerfooter.inc"

#include "modules\static\item\item.inc"

#include "modules\Player\playerparts.inc" // Contains new playerInfo

#include "modules\system\Disconnect3DTextLabel.inc"
#include "modules\system\RealTime.inc"
#include "modules\system\DeleteDefaultGasPumpObject.inc"
#include "modules\System\PlayerCommandError.inc"
#include "modules\System\PlayerCommands.inc"
#include "modules\System\PlayerSaying.inc"

#include "modules\Player\EditingObject\editingobject.inc"
#include "modules\Player\Animations\Animations.inc"

#include "modules\account\account_enum.inc"
#include "modules\account\account_check.inc"
#include "modules\account\Account_Register\account_register.inc"
#include "modules\account\Account_Login\account_login.inc"
#include "modules\account\account_callbacks.inc"

#include "modules\admin\admin.inc"
#include "modules\admin\admin_commandlist.inc"
#include "modules\system\weather.inc"

#include "modules\character\character_enum.inc"
#include "modules\character\character_check.inc"
#include "modules\character\character_list\character_list.inc"
#include "modules\character\character_create\character_create.inc"
#include "modules\Character\character_assigndata.inc"
#include "modules\Character\character_updatedata.inc"

#include "modules\Player\Inventory\inventory.inc"

#include "modules\System\Vehicle\vehicle.inc"

#include "modules\System\DefaultMapping\PrinsipilStreet.inc"
#include "modules\System\DefaultMapping\IdlewoodNearPrinsipilStreet.inc"
#include "modules\System\DefaultMapping\StoreFrontSaintHospital.inc"

#include "modules\player\hud\player_hud.inc"
#include "modules\Player\Hud\Speedometer\Modern\hudmode_spdo_modern.inc"
#include "modules\Player\Hud\Info\Modern\hudmode_info_modern.inc"

#include "modules\Player\PlayerLevel\playerlevel.inc"

#include "modules\player\thrist.inc"
#include "modules\player\hungry.inc"

#include "modules\dynamic\business\business.inc"
#include "modules\dynamic\business\Business_Log\business_log.inc"
#include "modules\dynamic\business\Business_BuyPoint\business_buypoint.inc"

#include "modules\Dynamic\Dealership\dealership.inc"
#include "modules\Dynamic\Dealership\DealershipVehicle\dealership_veh.inc"

#include "modules\dynamic\gaspump\gaspump.inc"
#include "modules\dynamic\droppeditem\droppeditem.inc"
#include "modules\dynamic\gate\gate.inc"
#include "modules\dynamic\savedanimation\savedanimation.inc"
#include "modules\dynamic\atm\atm.inc"
#include "modules\dynamic\pickup\pickup.inc"
#include "modules\dynamic\actor\actor.inc"
#include "Modules\Dynamic\Mapicon\mapicon.inc"
#include "modules\Dynamic\MechanicArea\mechanic_area.inc"

#include "modules\Dynamic\Mapping\valid_object.inc"
#include "modules\Dynamic\Mapping\RemoveBuildingFix.inc"
#include "modules\Dynamic\Mapping\Object\object.inc"
#include "modules\Dynamic\Mapping\RemoveObject\remove_object.inc"
#include "modules\Dynamic\Mapping\Folder\folder.inc"

#include "modules\Admin\admin_commands.inc"

#include "modules\Player\Job\player_job.inc"

#include "modules\Sidejob\Sweeper\SweeperRoute\sweeper_route.inc"
#include "modules\Sidejob\Sweeper\SweeperMark\sweeper_mark.inc"
#include "modules\Sidejob\Sweeper\sweeper.inc"


/* ======================= Code End ======================= */

YCMD:updateme(playerid, params[], help)
{
    UpdateCharacterData(playerid);
    return 1;
}

YCMD:test(playerid, params[], help) 
{
    Command_ReProcess(playerid, "/playerjob check 0", false);
    return 1;
}

LoadingBar:Test(playerid) 
{
    SendClientMessage(playerid, -1, "Kuntul");
    return 1;
}