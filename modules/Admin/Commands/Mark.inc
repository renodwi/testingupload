#include <YSI_Coding\y_hooks>

new Float:player_markposition[MAX_PLAYERS][3];
new player_markinterior[MAX_PLAYERS], player_markworld[MAX_PLAYERS];

hook OnPlayerConnect(playerid) 
{
    player_markposition[playerid][0] = 0.0;
    player_markposition[playerid][1] = 0.0;
    player_markposition[playerid][2] = 0.0;
    return 1;
}

YCMD:mark(playerid, params[], help)
{
    if(!IsPlayerAdmin(playerid, Volunteer))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");

    GetPlayerPos(playerid, player_markposition[playerid][0], player_markposition[playerid][1], player_markposition[playerid][2]);
    player_markinterior[playerid] = GetPlayerInterior(playerid);
    player_markworld[playerid] = GetPlayerVirtualWorld(playerid);
    SendClientMessageEx(playerid, COLOR_REN, "MARK: "WHITE"Posisi anda telah ditandai, gunakan "YELLOW"/gotomark"WHITE" untuk teleport");
    return 1;
}

YCMD:gotomark(playerid, params[], help)
{
    if(!IsPlayerAdmin(playerid, Volunteer))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");
        
    if(player_markposition[playerid][0] == 0.0 && player_markposition[playerid][1] == 0.0 && player_markposition[playerid][2] == 0.0)
        return SendErrorMessage(playerid, "Anda sebelumnya belum menandai posisi (/mark)");
    
    SetPlayerPos(playerid, player_markposition[playerid][0], player_markposition[playerid][1], player_markposition[playerid][2]);
    SetPlayerVirtualWorld(playerid, player_markworld[playerid]);
    SetPlayerInterior(playerid, player_markinterior[playerid]);
    SendClientMessageEx(playerid, COLOR_REN, "TELEPORT: "WHITE"Teleportasi ke tempat yang anda tandai.");
    return 1;
}