stock CreateBusinessLog(businessid, const message[], {Float, _}:...)
{
    new logid = GetBusinessLogFree(businessid);

    if(logid == -1)
    {
        #define MAX_TEMP_BUSINESSLOG 10
        new temp_BusinessLogMessage[MAX_TEMP_BUSINESSLOG][MAX_BUSINESS_LOG_MESSAGE], Timestamp:temp_BusinessLogTime[MAX_TEMP_BUSINESSLOG];
        for(new i = MAX_BUSINESS_LOG - MAX_TEMP_BUSINESSLOG; i < MAX_BUSINESS_LOG; i++) 
        {
            format(temp_BusinessLogMessage[i - (MAX_BUSINESS_LOG - MAX_TEMP_BUSINESSLOG)], MAX_BUSINESS_LOG_MESSAGE + 1, "%s", businesslogInfo[businessid][i - (MAX_BUSINESS_LOG - MAX_TEMP_BUSINESSLOG)][businesslogMessage]);
            temp_BusinessLogTime[i - (MAX_BUSINESS_LOG - MAX_TEMP_BUSINESSLOG)] = businesslogInfo[businessid][i - (MAX_BUSINESS_LOG - MAX_TEMP_BUSINESSLOG)][businesslogTimestamp]; 
        }

        ResetBusinessLog(businessid, true);

        Loop(i, MAX_TEMP_BUSINESSLOG) 
        {
            businesslogInfo[businessid][i][businesslogExist] = true;
            format(businesslogInfo[businessid][logid][businesslogMessage], MAX_BUSINESS_LOG_MESSAGE, "%s", temp_BusinessLogMessage[i]);
            businesslogInfo[businessid][logid][businesslogTimestamp] = temp_BusinessLogTime[i];

            new query[500];
            mysql_format(sql, query, sizeof(query), "INSERT INTO `business_logs` (`businessid`, `timestamp`, `message`) VALUE ('%d', '%d', '%e')", businessid, _:businesslogInfo[businessid][logid][businesslogTimestamp], businesslogInfo[businessid][logid][businesslogMessage]);
            mysql_tquery(sql, query, "OnBusinessLogCreate", "dd", businessid, i);
        }
    }
    else 
    {
        new fixstring[MAX_BUSINESS_LOG_MESSAGE];
        va_format(fixstring, sizeof (fixstring), message, va_start<2>);

        businesslogInfo[businessid][logid][businesslogExist] = true;
        format(businesslogInfo[businessid][logid][businesslogMessage], MAX_BUSINESS_LOG_MESSAGE, "%s", fixstring);
        businesslogInfo[businessid][logid][businesslogTimestamp] = Now();

        new query[500];
        mysql_format(sql, query, sizeof(query), "INSERT INTO `business_logs` (`businessid`, `timestamp`, `message`) VALUE ('%d', '%d', '%e')", businessid, _:businesslogInfo[businessid][logid][businesslogTimestamp], businesslogInfo[businessid][logid][businesslogMessage]);
        mysql_tquery(sql, query, "OnBusinessLogCreate", "dd", businessid, logid);
    }
    return 1;
}

stock GetBusinessLogFree(businessid)
{
    new logid = -1;
    Loop(i, MAX_BUSINESS_LOG) 
    {
        if(businesslogInfo[businessid][i][businesslogExist] == false) 
        {
            logid = i;
            break;
        }
    }
    return logid;
}

stock ResetBusinessLog(businessid, bool:database_juga = false)
{
    Loop(i, MAX_BUSINESS_LOG)
    {
        businesslogInfo[businessid][i][businesslogExist] = false;
    }

    if(database_juga == true) 
    {
        new query[500];
        mysql_format(sql, query, sizeof(query), "DELETE FROM `business_logs` WHERE `businessid` = '%d'", businessid);
        mysql_tquery(sql, query);
    }
    return 1;
}

stock LoadBusinessLog(businessid) 
{
    ResetBusinessLog(businessid);

    new query[500];
    mysql_format(sql, query, sizeof(query), "SELECT * FROM `business_logs` WHERE `businessid` = '%d'", businessid);
    mysql_tquery(sql, query, "AssignBusinessLogData", "d", businessid);
    return 1;
}