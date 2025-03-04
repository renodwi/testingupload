hook OnGameModeInit()
{
    AddAdminCommand(Admin1, "/saveanim", "Digunakan untuk menyimpan animasi (dapat diakses oleh player namun dengan batas)");
    AddAdminCommand(Admin1, "/deleteanim", "Digunakan untuk menghapus animasi (dapat diakses oleh player namun dengan batas)");
    return 1;
}

hook OnServerAssignData()
{
    LoadSavedAnimation();
    return 1;
}