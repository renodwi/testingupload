#define MAX_BUSINESS_LOG 50
#define MAX_BUSINESS_LOG_MESSAGE 500
enum BUSINESS_LOG 
{
    bool:businesslogExist,
    businesslogDBID,
    
    businesslogMessage[MAX_BUSINESS_LOG_MESSAGE],
    Timestamp:businesslogTimestamp,
}
new businesslogInfo[MAX_BUSINESS][MAX_BUSINESS_LOG][BUSINESS_LOG];