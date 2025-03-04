#define MAX_MAPICON 100
enum MAPICON
{
    Float:mapiconPositionX,
    Float:mapiconPositionY,
    Float:mapiconPositionZ,
    mapiconType,
    mapiconColor,

    // Unsaved
    mapiconID
}
new mapiconInfo[MAX_MAPICON][MAPICON],
    Iterator:MapIcon<MAX_MAPICON>;
