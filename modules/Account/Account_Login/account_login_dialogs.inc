stock ShowPlayerLoginDialog(playerid, dialog) 
{
    switch(dialog) 
    {
        case LOGIN_DIALOG_PASSWORD:
        {
            HidePlayerInfoBoxTextDraw(playerid);
            
            new message[3000];
            format(message, sizeof(message), "%s"WHITE"Akun anda "YELLOW"%s"WHITE" terdaftar!\n\n", message, GetName(playerid));
            format(message, sizeof(message), "%s"WHITE"Masukkan password akun anda untuk memasuki game...\n", message);
            format(message, sizeof(message), "%s"WHITE"Password Gagal: "LR"%d/%d\n", message, player_login_attemp[playerid], MAX_PLAYER_LOGIN_ATTEMP);
            Dialog_Show(playerid, Login_Password, DIALOG_STYLE_PASSWORD, "Login", message, "Login", "Keluar");
        }
    }
    return 1;
}

Dialog:Login_Password(playerid, response, listitem, inputtext[]) 
{
    if(!response) return Kick(playerid, "Membatalkan proses login");
    else 
    {
        bcrypt_verify(playerid, "LoginPasswordVerify", inputtext, accountInfo[playerid][accountPassword]);
    }
    return 1;
}