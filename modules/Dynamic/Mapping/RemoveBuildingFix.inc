#include <YSI_Coding\y_hooks>

#define MAX_REMOVED_BUILDINGS 1000

// Enum untuk menyimpan data bangunan yang dihapus
enum E_REMOVE_BUILDING 
{
    bool:RemovedBuildingExist,
    RemovedBuildingModel,
    Float:RemovedBuildingX,
    Float:RemovedBuildingY,
    Float:RemovedBuildingZ,
    Float:RemovedBuildingRadius,
}
new RemoveBuildingData[MAX_REMOVED_BUILDINGS][E_REMOVE_BUILDING],
    Iterator:RemovedBuildings<MAX_REMOVED_BUILDINGS>;

// Fungsi untuk menambahkan bangunan ke daftar remove
stock AddRemoveBuilding(model, Float:x, Float:y, Float:z, Float:radius) 
{
    new i = Iter_Free(RemovedBuildings);
    
    RemoveBuildingData[i][RemovedBuildingExist] = true;
    RemoveBuildingData[i][RemovedBuildingModel] = model;
    RemoveBuildingData[i][RemovedBuildingX] = x;
    RemoveBuildingData[i][RemovedBuildingY] = y;
    RemoveBuildingData[i][RemovedBuildingZ] = z;
    RemoveBuildingData[i][RemovedBuildingRadius] = radius;
            
    Iter_Add(RemovedBuildings, i);
    return -1; // Jika penuh
}

// Fungsi untuk menerapkan penghapusan bangunan kepada pemain
stock RefreshRemoveBuildings(playerid) 
{
    foreach (new i : RemovedBuildings) 
    {
        if (Iter_Contains(RemovedBuildings, i)) 
        {
            RemoveBuildingForPlayer(playerid, RemoveBuildingData[i][RemovedBuildingModel], RemoveBuildingData[i][RemovedBuildingX], RemoveBuildingData[i][RemovedBuildingY], RemoveBuildingData[i][RemovedBuildingZ], RemoveBuildingData[i][RemovedBuildingRadius]);
        }
    }
    return 1;
}

hook OnPlayerConnect(playerid) 
{
    RefreshRemoveBuildings(playerid);
    return 1;
}
