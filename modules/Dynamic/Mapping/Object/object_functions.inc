stock RefreshDynamicObjectLabel(slot)
{
    if(!IsValidDynamicObject(DynamicObject[slot]))
    {
        if(IsValidDynamic3DTextLabel(DynamicObjectLabel[slot]))
            DestroyDynamic3DTextLabel(DynamicObjectLabel[slot]);
    }
    else 
    {
        if(IsValidDynamic3DTextLabel(DynamicObjectLabel[slot]))
            DestroyDynamic3DTextLabel(DynamicObjectLabel[slot]);

        new label_format[500], model, Float:cPos[3], Float:cRot[3];
        model = Streamer_GetIntData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_MODEL_ID);
        Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_X, cPos[0]);
        Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_Y, cPos[1]);
        Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_Z, cPos[2]);
        Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_R_X, cRot[0]);
        Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_R_Y, cRot[1]);
        Streamer_GetFloatData(STREAMER_TYPE_OBJECT, DynamicObject[slot], E_STREAMER_R_Z, cRot[2]);
        format(label_format, sizeof(label_format), ""GREY"[ID: %d]\n"WHITE"Model: "YELLOW"%d (%s)\n"GREY"X: %f Y: %f Z: %f\n"GREY"RX: %f RY: %f RZ: %f", slot, model, GetObjectModelName(model), cPos[0], cPos[1], cPos[2], cRot[0], cRot[1], cRot[2]);
        DynamicObjectLabel[slot] = CreateDynamic3DTextLabel(label_format, COLOR_WHITE, cPos[0], cPos[1], cPos[2], 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID);
    }
    return 1;
}