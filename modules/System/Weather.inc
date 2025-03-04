#include <YSI_Coding\y_hooks>

new weather = 0;

hook OnGameModeInit()
{
    weather = RandomMinMax(0, 20);
    SetWeather(weather);

    AddAdminCommand(Admin2, "/setweather", "Digunakan untuk mengubah weather global");
    return 1;
}

hook OnPlayerConnect(playerid)
{
    SetPlayerWeather(playerid, weather);
    return 1;
}

hook OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
    if (newinteriorid != 0)
    {
        SetPlayerWeather(playerid, 0);
    }
    else
    {
        SetPlayerWeather(playerid, weather);
    }
    return 1;
}

YCMD:setweather(playerid, params[], help) 
{
    if(!IsPlayerAdmin(playerid, Admin2))
        return SendErrorMessage(playerid, "Anda tidak memiliki akses untuk menggunakan command ini!");

    new weatherid;
    if(sscanf(params, "d", weatherid)) 
        return SendUsageMessage(playerid, "/setweather [weather id (0 - 20)]");

    if(weatherid < 0 || weatherid > 20)
        return SendErrorMessage(playerid, "Weather ID hanya dapat 0 - 20 saja");

    weather = weatherid;
    SetWeather(weather);

    foreach(new i : Player) 
    {
        if(GetPlayerInterior(i) == 0) SetPlayerWeather(playerid, weather);
    }

    SendClientMessageEx(playerid, COLOR_REN, "WEATHER: "WHITE"Changed weather to "YELLOW"%d", weatherid);
    return 1;
}