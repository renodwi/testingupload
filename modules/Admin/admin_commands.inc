#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    AddAdminCommand(Volunteer, "/jetpack", "Memunculkan jetpack untuk digunakan admin");
    AddAdminCommand(Volunteer, "/mark", "Menandai lokasi untuk digunakan pada /gotomark");
    AddAdminCommand(Volunteer, "/gotomark", "Teleportasi ke lokasi yang ditandai menggunakan /mark");

    AddAdminCommand(Volunteer, "/lt [opt: jarak]", "Teleportasi ke kiri dengan jarak opsional");
    AddAdminCommand(Volunteer, "/rt [opt: jarak]", "Teleportasi ke kanan dengan jarak opsional");
    AddAdminCommand(Volunteer, "/ft [opt: jarak]", "Teleportasi ke depan dengan jarak opsional");
    AddAdminCommand(Volunteer, "/bt [opt: jarak]", "Teleportasi ke belakang dengan jarak opsional");
    AddAdminCommand(Volunteer, "/up [opt: jarak]", "Teleportasi ke atas dengan jarak opsional");
    AddAdminCommand(Volunteer, "/dn [opt: jarak]", "Teleportasi ke bawah dengan jarak opsional");
    
    AddAdminCommand(Developer, "/setmoney [player name / player id] [money]", "Mengatur jumlah uang yang dimiliki oleh player");
    AddAdminCommand(Developer, "/givemoney [player name / player id] [money]", "Memberikan sejumlah uang pada player");
    return 1;
}

#include "modules\Admin\Commands\Jetpack.inc"
#include "modules\Admin\Commands\Mark.inc"
#include "modules\Admin\Commands\Position.inc"
#include "modules\Admin\Commands\SetMoney.inc"
#include "modules\Admin\Commands\GiveMoney.inc"