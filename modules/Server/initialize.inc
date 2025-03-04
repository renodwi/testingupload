#include <YSI_Coding\y_hooks>

new bool:server_initializing = false;
new bool:player_connect_srvrinitialize[MAX_PLAYERS];

hook OnGameModeInit()
{
    EnableTirePopping(0);
	EnableStuntBonusForAll(0);
	ShowPlayerMarkers(false);
	DisableInteriorEnterExits();
	ShowNameTags(false);
	SetNameTagDrawDistance(20.0);
	LimitPlayerMarkerRadius(20.0);
	AllowInteriorWeapons(1); 
	ManualVehicleEngineAndLights();
    Command_SetDeniedReturn(false);
    
    ServerInitialize();
    return 0;
}

hook OnPlayerRequestClass(playerid, classid)
{
    player_connect_srvrinitialize[playerid] = false;

    if(server_initializing == true)
    {
        player_connect_srvrinitialize[playerid] = true;
        SendClientMessage(playerid, -1, "Anda terkoneksi kedalam server saat server sedang menginisialisasi, mohon tunggu sebentar...");
        ShowPlayerInfoBoxTextDraw(playerid, INFORMASI_SERVER_INITIALIZING, "~p~~h~Server Initializing", "Anda terkoneksi kedalam server saat server sedang menginisialisasi, mohon tunggu sebentar...", " ", "");
    }
    return 1;
}

stock ServerInitialize()
{
    SetTimer("OnServerConnectToDatabase", 1000, false);
    SendRconCommand("hostname [EG:GM] Initialize");

    new password[100], pw = RandomMinMax(111111, 999999);
    format(password, sizeof(password), "password egrpinitialize_%d", pw);
    SendRconCommand(password);
    server_initializing = true;
    return 1;
}

function OnServerConnectToDatabase()
{
    new connect_database = ConnectServerToDatabase();
    if(connect_database == 0)
    {
        print("               __          ");
        print("|\\/|   _ _ |  |_  _ _ _  _ ");
        print("|  |\\/_)(_||  |__| | (_)|  ");
        print("    /     |                ");
        print("Mysql could not connect to the database, the server system was discontinued.");
    }
    else if(connect_database == 1)
    {
        SetTimer("OneSecond", 1000, true);
        SetTimer("OnServerReady", 5000, false);
        SetTimer("OnServerAssignData", 5000, false);
    }
    return 1;
}

function OnServerReady()
{
    SendRconCommand("password 0");
    LoadServerInformation();

    foreach(new playerid : Player)
    {
        if(IsPlayerConnected(playerid))
        {
            if(player_connect_srvrinitialize[playerid] == true) 
            {
                SetTimerEx("PlayerConnectBackToServer", 5000, false, "d", playerid);
                CallRemoteFunction("OnPlayerDisconnect", "ii", playerid, 2);
            }
        }
    }
    return 1;
}

function PlayerConnectBackToServer(playerid)
{
    CallRemoteFunction("OnPlayerConnect", "i", playerid);
    SetTimerEx("OnPlayerRequestClass", 2000, false, "dd", playerid, 0);
    return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
	return 1;
}