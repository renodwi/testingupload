stock ShowPlayerBusinessLog(playerid, businessid)
{
    AddDialogListitem(playerid, "Tanggal\tPesan");
    for(new i = MAX_BUSINESS_LOG - 1; i >= 0; i--)
    {
        if(businesslogInfo[businessid][i][businesslogExist] == true) 
        {
            AddDialogListitem(playerid, ""WHITE"%s %s\t%s", TimestampToDateString(businesslogInfo[businessid][i][businesslogTimestamp]), TimestampToTimeString(businesslogInfo[businessid][i][businesslogTimestamp]),  businesslogInfo[businessid][i][businesslogMessage]);
        }
        else continue;
    } 
    ShowPlayerDialogPages(playerid, "BusinessLog_List", DIALOG_STYLE_TABLIST_HEADERS, "Log Bisnis", "Tutup", "", 20);
    return 1;
}

DialogPages:BusinessLog_List(playerid, response, listitem, inputtext[])
{
	return 1;
}
