#include <YSI_Coding\y_hooks>

#define MAX_ADMIN_COMMAND 200
enum ADMIN_COMMAND_LIST
{
    bool:admincommandExist,

    admincommandLevel,
    admincommandName[50],
    admincommandDescription[500]
}
new admincommandInfo[MAX_ADMIN_COMMAND][ADMIN_COMMAND_LIST];

hook OnGameModeInit()
{
    AddAdminCommand(Volunteer, "/ahelp", "Digunakan untuk melihat daftar command admin yang tersedia");
    return 1;
}
stock AddAdminCommand(adminlevel, const command[], const description[])
{
    new admincommandid;
    Loop(i, MAX_ADMIN_COMMAND) {
        if(admincommandInfo[i][admincommandExist] == false) {
            admincommandid = i;
            break;
        }
    }

    admincommandInfo[admincommandid][admincommandLevel] = adminlevel;
    format(admincommandInfo[admincommandid][admincommandName], 50, command);
    format(admincommandInfo[admincommandid][admincommandDescription], 500, description);
    admincommandInfo[admincommandid][admincommandExist] = true;
    return 1;
}

YCMD:ahelp(playerid, params[], help)
{
    new header[100], cmdregistered = 0;
    Loop(i, MAX_ADMIN_COMMAND) {
        if(admincommandInfo[i][admincommandExist] == true) {
            cmdregistered = cmdregistered + 1;
        }
    }
    format(header, sizeof(header), "Admin Command (%d/%d Command)", cmdregistered, MAX_ADMIN_COMMAND);

    new message[3000];
    if(IsPlayerAdmin(playerid, Volunteer)) format(message, sizeof(message), "%sVolunteer\n", message);
    if(IsPlayerAdmin(playerid, JuniorHelper)) format(message, sizeof(message), "%sJunior Helper\n", message);
    if(IsPlayerAdmin(playerid, Helper)) format(message, sizeof(message), "%sHelper\n", message);
    if(IsPlayerAdmin(playerid, Admin1)) format(message, sizeof(message), "%sAdmin Level 1\n", message);
    if(IsPlayerAdmin(playerid, Admin2)) format(message, sizeof(message), "%sAdmin Level 2\n", message);
    if(IsPlayerAdmin(playerid, Admin3)) format(message, sizeof(message), "%sAdmin Level 3\n", message);
    if(IsPlayerAdmin(playerid, Manager)) format(message, sizeof(message), "%sManager\n", message);
    if(IsPlayerAdmin(playerid, Developer)) format(message, sizeof(message), "%sDeveloper\n", message);
    Dialog_Show(playerid, AdminCommandList, DIALOG_STYLE_LIST, header, message, "Select", "Close");
    return 1;
}

Dialog:AdminCommandList(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    else 
    {
        new message[3000], count = 0;
        AddDialogListitem(playerid, "#\tCommand\tDescription\n");
        Loop(i, MAX_ADMIN_COMMAND) {
            if(admincommandInfo[i][admincommandExist] == true) {
                if(admincommandInfo[i][admincommandLevel] == listitem +1) {
                    count = count +1;
                    format(message, sizeof(message), ""GREY"#%d\t"YELLOW"%s\t"BLUE"%s", count, admincommandInfo[i][admincommandName], admincommandInfo[i][admincommandDescription]);
                    AddDialogListitem(playerid, message);
                }
            }
        }
        ShowPlayerDialogPages(playerid, "Dialog_AdminCommandList", DIALOG_STYLE_TABLIST_HEADERS, "{FFFFFF}Admin Command List", "Select", "", 15);
    }
    return 1;
}