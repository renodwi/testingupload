enum ActorInfo
{
    actorName[100],
    actorSkinID,
    Float:actorPositionX,
    Float:actorPositionY,
    Float:actorPositionZ,
    Float:actorPositionA,

    actorAnimLib[100],
    actorAnimName[100],

    actorWorldID,
    actorInteriorID,
    
    // Unsaved
    actorID,
    Text3D:actorLabel
}
new actorInfo[MAX_ACTORS][ActorInfo],
    Iterator:Actors<MAX_ACTORS>;