stock ShowPlayerRegisterOption(playerid)
{
	new message[MAX_PLAYER_NAME + 5];
	format(message, sizeof(message), "~y~~h~%s", GetName(playerid));
	ShowPlayerInfoBoxTextDraw(playerid, INFORMASI_REGISTER, message, "Akun anda tidak terdaftar pada server! Apakah anda ingin melakukan registrasi?", "Registrasi", "Keluar");
    return 1;
}

stock CreateAccount(const name[], const email[], const password[])
{
    new query[1000];
    mysql_format(sql, query, sizeof(query), "INSERT INTO `accounts` (`username`, `email`, `password`, `registerdate`) VALUES ('%e', '%e', '%e', '%d')", name, email, password, _:Now());
    mysql_tquery(sql, query);
    return 1;
}