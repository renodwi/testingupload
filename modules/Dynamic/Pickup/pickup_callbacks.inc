hook OnGameModeInit()
{
    AddAdminCommand(Manager, "/pickup [option]", "Mengatur dynamic pickup");
    return 1;
}

hook OnServerAssignData()
{
    LoadPickups();
    return 1;
}