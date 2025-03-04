stock AddRemovedObject(model, Float:x, Float:y, Float:z, Float:radius) 
{
    new slot = Iter_Free(RemoveObject);
    if(slot == cellmax) return -1;

    removeobjectInfo[slot][removeobjectModel] = model;
    removeobjectInfo[slot][removeobjectPositionX] = x;
    removeobjectInfo[slot][removeobjectPositionY] = y;
    removeobjectInfo[slot][removeobjectPositionZ] = z;
    removeobjectInfo[slot][removeobjectRadius] = radius;

    Iter_Add(RemoveObject, slot);
    return 1;
}

stock CancelRemoveObject(slot) 
{
    if(!Iter_Contains(RemoveObject, slot)) return -1;
    Iter_Remove(RemoveObject, slot);
    return 1;
}

stock RefreshRemovedObjectForPlayer(toplayer) 
{
    new count = 0;
    foreach(new slot : RemoveObject)
    {
        if(Iter_Contains(RemoveObject, slot))
        {
            count++;
            RemoveBuildingForPlayer(toplayer, removeobjectInfo[slot][removeobjectModel], removeobjectInfo[slot][removeobjectPositionX], removeobjectInfo[slot][removeobjectPositionY], removeobjectInfo[slot][removeobjectPositionZ], removeobjectInfo[slot][removeobjectRadius]);
        }
    }
    SendClientMessageEx(toplayer, COLOR_REN, "REMOVE-OBJECT: "WHITE"Refresh object yang dihapus, "LG"jumlah: %d", count);
    SendClientMessageEx(toplayer, COLOR_REN, "REMOVE-OBJECT: Object yang dihapus hanya pada tampilan anda saja, simpan mapping untuk mengubah pada seluruh player!");
    return 1;
}