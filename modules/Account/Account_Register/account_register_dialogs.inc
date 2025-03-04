stock ShowPlayerRegisterDialog(playerid, type) 
{
    switch(type) 
    {
        case REGISTER_DIALOG_PASSWORD:
        {
            new message[3000];
            format(message, sizeof(message), ""WHITE"Akun "YELLOW"%s"WHITE" tidak terdaftar\n\nMasukkan password untuk registrasi\n\n", GetName(playerid));
            format(message, sizeof(message), "%s"LG"Password harus sesuai kriteria sebagai berikut\n", message);
            format(message, sizeof(message), "%s"LG"  - Terdiri lebih dari 8 karakter huruf atau angka\n", message);
            format(message, sizeof(message), "%s"LG"  - Disarankan menggunakan kombinasi simbol atau angka\n", message);
            format(message, sizeof(message), "%s"LG"  - Tidak mengandung informasi pribadi\n", message);
            format(message, sizeof(message), "%s"LG"  - Kata sandi tidak digunakan pada platfrom lainnya\n", message);
            Dialog_Show(playerid, Register_Password, DIALOG_STYLE_PASSWORD, "Registrasi", message, "Registrasi", "Keluar");
        }
        case REGISTER_DIALOG_EMAIL:
        {
            new message[3000];
            format(message, sizeof(message), ""WHITE"Masukkan email aktif anda untuk pencadangan akun bila terjadi masalah.\n\n", GetName(playerid));
            format(message, sizeof(message), "%s"LG"Contoh email yang benar: jajangnurjana@gmail.com\n", message);
            Dialog_Show(playerid, Register_Email, DIALOG_STYLE_INPUT, "Registrasi", message, "Oke", "Kembali");
        }
        case REGISTER_CONFIRMATION:
        {
            new message[3000];
            format(message, sizeof(message), ""WHITE"Konfirmasi akan melakukan registrasi?\n\n");
            format(message, sizeof(message), "%s"WHITE"Nama Akun: "LG"%s\n", message, GetName(playerid));
            format(message, sizeof(message), "%s"WHITE"Email Akun: "YELLOW"%s\n\n", message, player_registration_email[playerid]);
            format(message, sizeof(message), "%s"WHITE"Jika anda menekan IYA maka regsitrasi akun anda akan diproses.", message);
            Dialog_Show(playerid, Register_Confirmation, DIALOG_STYLE_MSGBOX, "Registrasi", message, "IYA", "Batalkan");
        }
    }
    return 1;
}

Dialog:Register_Password(playerid, response, listitem, inputtext[])
{
    if(!response) return Kick(playerid, "Membatalkan registrasi");
    else 
    {
        if(strlen(inputtext) < 8)
        {
            ShowPlayerRegisterDialog(playerid, REGISTER_DIALOG_PASSWORD);
            SendErrorMessage(playerid, "Masukkan password lebih dari 8 karakter huruf atau angka!");
        }
        else 
        {
            bcrypt_hash(playerid, "RegistrationHashPassword", inputtext, BCRYPT_COST);
        }
    }
    return 1;
}

Dialog:Register_Email(playerid, response, listitem, inputtext[]) 
{
    if(!response) return ShowPlayerRegisterDialog(playerid, REGISTER_DIALOG_PASSWORD);
    else 
    {
        if(!IsValidEmail(inputtext))
        {
            SendErrorMessage(playerid, "Email yang anda masukkan tidak benar!");
            ShowPlayerRegisterDialog(playerid, REGISTER_DIALOG_EMAIL);
        }
        else
        {
            format(player_registration_email[playerid], 150, inputtext);

            new query[500];
            mysql_format(sql, query, sizeof(query), "SELECT * FROM `accounts` WHERE `email` = '%e'", player_registration_email[playerid]);
            mysql_tquery(sql, query, "CreateAccountCheckEmail", "d", playerid);
        }
    }
    return 1;
}

Dialog:Register_Confirmation(playerid, response, listitem, inputtext[]) 
{
    if(!response) return ShowPlayerRegisterDialog(playerid, REGISTER_DIALOG_EMAIL);
    else 
    {
        CreateAccount(GetName(playerid), player_registration_email[playerid], player_registration_password[playerid]);
        ShowPlayerInfoBoxTextDraw(playerid, INFORMASI_REGISTER_DONE, "~y~REGISTRASI", "Registrasi berhasil, mohon tunggu sebentar anda akan memasuki proses login...");
        SetTimerEx("LoginAfterRegister", 10000, false, "d", playerid);
    }
    return 1;
}