#include <YSI_Coding\y_hooks>

enum SERVER
{
    serverName[125],
    serverGamemode[125],
    serverMapName[125],
    serverLanguage[125],
    serverPassword[120],
    serverMotd[200],
    serverAdminMotd[200],
}
new serverInfo[SERVER];

stock LoadServerInformation()
{
    mysql_tquery(sql, "SELECT * FROM `server_information`", "AssignServerInformation");
    return 1;
}

function AssignServerInformation()
{
    cache_get_value(0, "name", serverInfo[serverName]);
    cache_get_value(0, "gamemode", serverInfo[serverGamemode]);
    cache_get_value(0, "mapname", serverInfo[serverMapName]);
    cache_get_value(0, "language", serverInfo[serverLanguage]);
    cache_get_value(0, "password", serverInfo[serverPassword]);
    cache_get_value(0, "motd", serverInfo[serverMotd]);
    cache_get_value(0, "adminmotd", serverInfo[serverAdminMotd]);
    UpdateServerInformation();
    return 1;
}

stock UpdateServerInformation()
{
    SendRconCommand("hostname %s", serverInfo[serverName]);
    SendRconCommand("gamemodetext %s", serverInfo[serverGamemode]);
    SendRconCommand("mapname %s", serverInfo[serverMapName]);
    SendRconCommand("language %s", serverInfo[serverLanguage]);

    if(strcmp(serverInfo[serverPassword], "0", true))
    {
        SendRconCommand("password %s", serverInfo[serverPassword]);
    }

    print("[Server Information - Success] Server information has been updated.");

    new fetchChars[3060];  
    mysql_format(sql, fetchChars, sizeof(fetchChars), "UPDATE `server_information` SET");
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `name` = '%e', ", fetchChars, serverInfo[serverName]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `gamemode` = '%e', ", fetchChars, serverInfo[serverGamemode]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `mapname` = '%e', ", fetchChars, serverInfo[serverMapName]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `language` = '%e', ", fetchChars, serverInfo[serverLanguage]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `password` = '%e', ", fetchChars, serverInfo[serverPassword]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `motd` = '%e', ", fetchChars, serverInfo[serverMotd]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `adminmotd` = '%e', ", fetchChars, serverInfo[serverAdminMotd]);
    mysql_format(sql, fetchChars, sizeof(fetchChars), "%s `name` = '%e'", fetchChars, serverInfo[serverName]);
    mysql_tquery(sql, fetchChars);
    return 1;
}