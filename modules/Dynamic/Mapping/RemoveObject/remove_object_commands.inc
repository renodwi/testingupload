YCMD:removeobject(playerid, params[], help)
{
    new action[50], string[250], bool:syntax = true;
    if(sscanf(params, "s[50]S()[250]", action, string))
    {
        syntax = false;
    }
    else
    {
        if (!strcmp(action, "add", true))
        {
            new model, Float:radius, Float:x, Float:y, Float:z;
            if (sscanf(string, "df", model, radius))
            {
                SendUsageMessage(playerid, "/removeobject add [model] [radius]");
                return 1;
            }

            if(!IsValidObjectModel(model))
                return SendErrorMessage(playerid, "Model dengan ID %d tidak ada!", model);

            GetPlayerPos(playerid, x, y, z);
            new query[200];
            mysql_format(sql, query, sizeof(query), "SELECT Model, X, Y, Z FROM buildings WHERE Model = %d AND SQRT(POW(X - %f, 2) + POW(Y - %f, 2) + POW(Z - %f, 2)) <= %f", model, x, y, z, radius);
            mysql_tquery(sql, query, "OnPlayerAddRemoveObject", "ddf", playerid, model, radius);
        }
        else if (!strcmp(action, "cancel", true))
        {
            new model, Float:radius;
            if (sscanf(string, "df", model, radius))
            {
                SendUsageMessage(playerid, "/removeobject cancel [model] [radius]");
                return 1;
            }

            new Float:x, Float:y, Float:z;
            GetPlayerPos(playerid, x, y, z);

            new count = 0; // Untuk menghitung jumlah object yang berhasil dihapus

            foreach(new slot : RemoveObject)
            {
                if (removeobjectInfo[slot][removeobjectModel] == model)
                {
                    new Float:ox = removeobjectInfo[slot][removeobjectPositionX];
                    new Float:oy = removeobjectInfo[slot][removeobjectPositionY];
                    new Float:oz = removeobjectInfo[slot][removeobjectPositionZ];

                    // Hitung jarak Euclidean
                    new Float:distance = floatsqroot((ox - x) * (ox - x) + (oy - y) * (oy - y) + (oz - z) * (oz - z));

                    if (distance <= radius)
                    {
                        if (CancelRemoveObject(slot) != -1)
                        {
                            count++;
                            SendClientMessageEx(playerid, COLOR_REN, "REMOVE-OBJECT: "WHITE"Membatalkan hapus object dengan model "LG"%s (%d)"WHITE".", GetObjectModelName(model), model);
                        }
                    }
                }
            }

            if (count > 0)
            {
                RefreshRemovedObjectForPlayer(playerid);
                SendClientMessageEx(playerid, COLOR_REN, "REMOVE-OBJECT: "WHITE"Total object batal untuk dihapus: "YELLOW"%d", count);
                SendClientMessageEx(playerid, COLOR_REN, "REMOVE-OBJECT: Pemulihan object yang batal dihapus harus melalui relog terlebih dahulu!");
            }
            else
            {
                SendErrorMessage(playerid, "Tidak ada object yang dihapus dengan model %d dalam radius %f", model, radius);
            }
        }
        else if(!strcmp(action, "save", true))
        {
            SendClientMessageEx(playerid, COLOR_REN, "REMOVE-OBJECT: Penyimpanan object yang dihapus telah terintegrasi dengan '/object save'");
        }
        else syntax = false;
    }
    
    if(syntax == false)
    {
        SendUsageMessage(playerid, "/removeobject [action]");
        SendClientMessageEx(playerid, COLOR_REN, "ACTION: add cancel save");
    }
    
    return 1;
}