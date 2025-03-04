hook OnInformasiResponse(playerid, infoid, response)
{
	if(infoid == INFORMASI_REGISTER)
	{
		if(!response) Kick(playerid, "Menolak untuk registrasi");
		else 
		{
			ShowPlayerRegisterDialog(playerid, REGISTER_DIALOG_PASSWORD);
		}
	}
	return 1;
}

function RegistrationHashPassword(playerid)
{
    new pw[BCRYPT_HASH_LENGTH];
    bcrypt_get_hash(pw);

    format(player_registration_password[playerid], 150, pw);

    ShowPlayerRegisterDialog(playerid, REGISTER_DIALOG_EMAIL);
    return 1;
}

function LoginAfterRegister(playerid)
{
    SetTimerEx("CheckPlayerAccount", 500, false, "d", playerid);
    return 1;
}

function CreateAccountCheckEmail(playerid) 
{
	if(cache_num_rows())
	{
		SendErrorMessage(playerid, "Email yang anda masukkan telah digunakan!");
		ShowPlayerRegisterDialog(playerid, REGISTER_DIALOG_EMAIL);
	}
	else 
	{
		ShowPlayerRegisterDialog(playerid, REGISTER_CONFIRMATION);
	}
	return 1;
}