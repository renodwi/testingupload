#define MAX_PLAYER_JOB 50

new player_quitjob_slot[MAX_PLAYERS];
new player_joinjob_offertype[MAX_PLAYERS];

new player_jobduty_type[MAX_PLAYERS];
enum PLAYER_JOB
{
    playerjobDBID,
    bool:playerjobExist,
    playerjobType,
    Timestamp:playerjobDelayUntil,
}
new playerjobInfo[MAX_PLAYERS][MAX_PLAYER_JOB][PLAYER_JOB];

enum /* Player Job Dialog */
{
    PLAYERJOB_LIST,
    PLAYERJOB_EXIT,
}

/* Job Type Moved To main.pwn */

new job_name[][] = {
    "None", "Mechanic"
};