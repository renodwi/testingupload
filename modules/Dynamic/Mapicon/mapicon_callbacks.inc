hook OnGameModeInit()
{
    AddAdminCommand(Admin2, "/mapicon", "Mengatur mapicon");
    return 1;
}

function AssignMapIconData()
{
    static mapiconid;
	new rows  = cache_num_rows();
    if(rows)
    {
		for(new i; i < rows; i++)
		{
            cache_get_value_int(i, "id", mapiconid);
            cache_get_value_float(i, "x", mapiconInfo[mapiconid][mapiconPositionX]);
            cache_get_value_float(i, "y", mapiconInfo[mapiconid][mapiconPositionY]);
            cache_get_value_float(i, "z", mapiconInfo[mapiconid][mapiconPositionZ]);
            cache_get_value_int(i, "type", mapiconInfo[mapiconid][mapiconType]);
            cache_get_value_int(i, "color", mapiconInfo[mapiconid][mapiconColor]);

            Iter_Add(MapIcon, mapiconid);
            RefreshMapIcon(mapiconid);

            #if defined DEBUG_MODE
                printf("[Dynamic Map Icon] ID: %d position (x: %f y: %f z: %f) Type: %d Color: %d", mapiconid, mapiconInfo[mapiconid][mapiconPositionX], mapiconInfo[mapiconid][mapiconPositionY], mapiconInfo[mapiconid][mapiconPositionZ], mapiconInfo[mapiconid][mapiconType], mapiconInfo[mapiconid][mapiconColor]);
            #endif
        }
    }
    return 1;
}