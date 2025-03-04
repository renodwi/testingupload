#include <YSI_Coding\y_hooks>

#define MYSQL_HOST              "127.0.0.1"
#define MYSQL_NAME              "root"
#define MYSQL_DATABASE_PASSWORD ""
#define MYSQL_DATABASE_NAME     "eggamemode"

new MySQL:sql;
stock ConnectServerToDatabase()
{
    new result;
    sql = mysql_connect(MYSQL_HOST, MYSQL_NAME, MYSQL_DATABASE_PASSWORD, MYSQL_DATABASE_NAME);
    if(mysql_errno() != 0) print("[Connect Database - Warning] Server is not connected to the database!"), result = 0;
    else print("[Connect Database - Success] Server connects to database."), result = 1;
    mysql_log(ERROR);
    return result;
}