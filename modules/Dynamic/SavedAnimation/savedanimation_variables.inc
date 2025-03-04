#define MAX_SAVED_ANIMATION 1000
enum SAVED_ANIMATION
{
    savedanimationName[50],
    savedanimationCreator[200],
    savedanimationAnimLibrary[100],
    savedanimationAnimName[100],
    savedanimationLooping
}
new savedanimationInfo[MAX_SAVED_ANIMATION][SAVED_ANIMATION],
    Iterator:SavedAnimation<MAX_SAVED_ANIMATION>;