hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(IsKeyJustDown(KEY_NO, newkeys, oldkeys))
    {
        if(player_loopinganimation[playerid] == true)
        {
            StopPlayerAnimation(playerid);
        }
    }
    return 1;
}

hook OnPlayerConnect(playerid)
{
    LoadPlayerAnimationTextDraw(playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reasons)
{
    DestroyPlayerAnimationTextDraw(playerid);
    return 1;
}

hook OnPlayerSpawn(playerid)
{
    LoadPlayerAllAnimation(playerid);
    return 1;
}