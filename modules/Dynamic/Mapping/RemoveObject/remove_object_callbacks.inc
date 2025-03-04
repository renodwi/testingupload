function OnPlayerAddRemoveObject(playerid, model, Float:radius)
{
    new rows = cache_num_rows();
    if(rows > 0)
    {
        new Float:ox, Float:oy, Float:oz, tmpmodel, result, count = 0;

        for(new i = 0; i < rows; i++)
        {
            cache_get_value_int(i, "Model", tmpmodel);
            cache_get_value_float(i, "X", ox);
            cache_get_value_float(i, "Y", oy);
            cache_get_value_float(i, "Z", oz);

            result = AddRemovedObject(model, ox, oy, oz, 7.0);
            if(result)
            {
                count++;
                SendClientMessageEx(playerid, COLOR_REN, "REMOVE-OBJECT: "WHITE"Object dengan model "LR"%s (%d)"WHITE" berhasil dihapus.", GetObjectModelName(model), model);
            }
            else
            {
                SendErrorMessage(playerid, "Gagal menghapus object! Slot penuh.");
            }
        }

        if(count > 0)
        {
            RefreshRemovedObjectForPlayer(playerid);
        }
    }
    else
    {
        SendErrorMessage(playerid, "Tidak ada object dengan model %d dalam radius %f", model, radius);
    }
    return 1;
}