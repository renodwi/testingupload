hook OnPlayerConnect(playerid) 
{
    player_login_attemp[playerid] = 0;
    return 1;
}

function LoginPasswordVerify(playerid, bool:success)
{
    if(success)
    {
        LoadPlayerCharacters(playerid);
        SetPlayerSelectCharacterCamera(playerid);
        ShowPlayerSelectCharacterInfoLd(playerid, 0);
    }
    else 
    {
        ShowPlayerLoginDialog(playerid, LOGIN_DIALOG_PASSWORD);
        SendErrorMessage(playerid, "Password yang anda masukkan salah!");
        player_login_attemp[playerid] ++;

        if(player_login_attemp[playerid] == MAX_PLAYER_LOGIN_ATTEMP) 
        {
            Kick(playerid, "Mencoba login namun dengan password yang salah lebih dari %d kali", player_login_attemp[playerid]);
        }
    }
    return 1;
}