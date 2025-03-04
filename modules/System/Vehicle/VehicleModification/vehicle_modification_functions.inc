stock n_AddVehicleComponent(vehicleid, componentid)
{
    new slot = GetVehicleComponentType(componentid);
    vehicle_modification[vehicleid][slot] = componentid;

    if(vehicle_modification[vehicleid][slot] != -1) AddVehicleComponent(vehicleid, componentid);
    else RemoveVehicleComponent(vehicleid, componentid);
    return 1;
}

#if defined _ALS_AddVehicleComponent
	#undef AddVehicleComponent
#else
	#define _ALS_AddVehicleComponent
#endif
#define AddVehicleComponent n_AddVehicleComponent

stock IsComponentidCompatible(modelid, componentid) {
    if( componentid == 1025 || componentid == 1073 || componentid == 1074 || componentid == 1075 || componentid == 1076 ||
		componentid == 1077 || componentid == 1078 || componentid == 1079 || componentid == 1080 || componentid == 1081 ||
        componentid == 1082 || componentid == 1083 || componentid == 1084 || componentid == 1085 || componentid == 1096 ||
        componentid == 1097 || componentid == 1098 || componentid == 1087 || componentid == 1086 ) {
        return componentid;
	}

    switch(modelid) {
        case 400: if( componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1013 || componentid == 1024 || componentid == 1008 || componentid == 1009 || componentid == 1010 ) return componentid;
        case 401: if( componentid == 1005 || componentid == 1004 || componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 114 || componentid == 1020 || componentid == 1019 || componentid == 1013 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1003 || componentid == 1017 || componentid == 1007) return componentid;
        case 402: if( componentid == 1009 || componentid == 1009 || componentid == 1010 ) return componentid;
        case 404: if( componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1013 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1002 || componentid == 1016 || componentid == 1000 || componentid == 1017 || componentid == 1007) return componentid;
        case 405: if( componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1001 || componentid == 1014 || componentid == 1023 || componentid == 1000) return componentid;
        case 409: if( componentid == 1009 ) return componentid;
        case 410: if( componentid == 1019 || componentid == 1021 || componentid == 1020 || componentid == 1013 || componentid == 1024 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1001 || componentid == 1023 || componentid == 1003 || componentid == 1017 || componentid == 1007) return componentid;
        case 411: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 412: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 415: if( componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1001 || componentid == 1023 || componentid == 1003 || componentid == 1017 || componentid == 1007) return componentid;
        case 418: if( componentid == 1020 || componentid == 1021 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1002 || componentid == 1016) return componentid;
        case 419: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 420: if( componentid == 1005 || componentid == 1004 || componentid == 1021 || componentid == 1019 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1001 || componentid == 1003) return componentid;
        case 421: if( componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1014 || componentid == 1023 || componentid == 1016 || componentid == 1000) return componentid;
        case 422: if( componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1013 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1017 || componentid == 1007) return componentid;
        case 426: if( componentid == 1005 || componentid == 1004 || componentid == 1021 || componentid == 1019 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1003) return componentid;
        case 429: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 436: if( componentid == 1020 || componentid == 1021 || componentid == 1022 || componentid == 1019 || componentid == 1013 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1003 || componentid == 1017 || componentid == 1007) return componentid;
        case 438: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 439: if( componentid == 1003 || componentid == 1023 || componentid == 1001 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1017 || componentid == 1007 || componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1013) return componentid;
        case 442: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 445: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 451: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 458: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 466: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 467: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 474: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 475: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 477: if( componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1017 || componentid == 1007) return componentid;
        case 478: if( componentid == 1005 || componentid == 1004 || componentid == 1012 || componentid == 1020 || componentid == 1021 || componentid == 1022 || componentid == 1013 || componentid == 1024 || componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 479: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 480: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 489: if( componentid == 1005 || componentid == 1004 || componentid == 1020 || componentid == 1019 || componentid == 1018 || componentid == 1013 || componentid == 1024 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1002 || componentid == 1016 || componentid == 1000) return componentid;
        case 491: if( componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1014 || componentid == 1023 || componentid == 1003 || componentid == 1017 || componentid == 1007) return componentid;
        case 492: if( componentid == 1005 || componentid == 1004 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1016 || componentid == 1000) return componentid;
        case 496: if( componentid == 1006 || componentid == 1017 || componentid == 1007 || componentid == 1011 || componentid == 1019 || componentid == 1023 || componentid == 1001 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1003 || componentid == 1002 || componentid == 1142 || componentid == 1143 || componentid == 1020) return componentid;
        case 500: if( componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1013 || componentid == 1024 || componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 506: if( componentid == 1009) return componentid;
        case 507: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 516: if( componentid == 1004 || componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1002 || componentid == 1015 || componentid == 1016 || componentid == 1000 || componentid == 1017 || componentid == 1007) return componentid;
        case 517: if( componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1002 || componentid == 1023 || componentid == 1016 || componentid == 1003 || componentid == 1017 || componentid == 1007) return componentid;
        case 518: if( componentid == 1005 || componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1018 || componentid == 1013 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1023 || componentid == 1003 || componentid == 1017 || componentid == 1007) return componentid;
        case 526: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 527: if( componentid == 1021 || componentid == 1020 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1001 || componentid == 1014 || componentid == 1015 || componentid == 1017 || componentid == 1007) return componentid;
        case 529: if( componentid == 1012 || componentid == 1011 || componentid == 1020 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1023 || componentid == 1003 || componentid == 1017 || componentid == 1007) return componentid;
        case 533: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 534: if( componentid == 1126 || componentid == 1127 || componentid == 1179 || componentid == 1185 || componentid == 1100 || componentid == 1123 || componentid == 1125 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1180 || componentid == 1178 || componentid == 1101 || componentid == 1122 || componentid == 1124 || componentid == 1106) return componentid;
        case 535: if( componentid == 1109 || componentid == 1110 || componentid == 1113 || componentid == 1114 || componentid == 1115 || componentid == 1116 || componentid == 1117 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1120 || componentid == 1118 || componentid == 1121 || componentid == 1119) return componentid;
        case 536: if( componentid == 1104 || componentid == 1105 || componentid == 1182 || componentid == 1181 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1184 || componentid == 1183 || componentid == 1128 || componentid == 1103 || componentid == 1107 || componentid == 1108) return componentid;
        case 540: if( componentid == 1004 || componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1019 || componentid == 1018 || componentid == 1024 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1023 || componentid == 1017 || componentid == 1007) return componentid;
        case 541: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 542: if( componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1014 || componentid == 1015) return componentid;
        case 545: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 546: if( componentid == 1004 || componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1019 || componentid == 1018 || componentid == 1024 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1002 || componentid == 1001 || componentid == 1023 || componentid == 1017 || componentid == 1007) return componentid;
        case 547: if( componentid == 1142 || componentid == 1143 || componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1016 || componentid == 1003 || componentid == 1000) return componentid;
        case 549: if( componentid == 1012 || componentid == 1011 || componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1001 || componentid == 1023 || componentid == 1003 || componentid == 1017 || componentid == 1007) return componentid;
        case 550: if( componentid == 1005 || componentid == 1004 || componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1023 || componentid == 1003) return componentid;
        case 551: if( componentid == 1005 || componentid == 1020 || componentid == 1021 || componentid == 1019 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1002 || componentid == 1023 || componentid == 1016 || componentid == 1003) return componentid;
        case 555: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 558: if( componentid == 1092 || componentid == 1089 || componentid == 1166 || componentid == 1165 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1168 || componentid == 1167 || componentid == 1088 || componentid == 1091 || componentid == 1164 || componentid == 1163 || componentid == 1094 || componentid == 1090 || componentid == 1095 || componentid == 1093) return componentid;
        case 559: if( componentid == 1065 || componentid == 1066 || componentid == 1160 || componentid == 1173 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1159 || componentid == 1161 || componentid == 1162 || componentid == 1158 || componentid == 1067 || componentid == 1068 || componentid == 1071 || componentid == 1069 || componentid == 1072 || componentid == 1070 || componentid == 1009) return componentid;
        case 560: if( componentid == 1028 || componentid == 1029 || componentid == 1169 || componentid == 1170 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1141 || componentid == 1140 || componentid == 1032 || componentid == 1033 || componentid == 1138 || componentid == 1139 || componentid == 1027 || componentid == 1026 || componentid == 1030 || componentid == 1031) return componentid;
        case 561: if( componentid == 1064 || componentid == 1059 || componentid == 1155 || componentid == 1157 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1154 || componentid == 1156 || componentid == 1055 || componentid == 1061 || componentid == 1058 || componentid == 1060 || componentid == 1062 || componentid == 1056 || componentid == 1063 || componentid == 1057) return componentid;
        case 562: if( componentid == 1034 || componentid == 1037 || componentid == 1171 || componentid == 1172 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1149 || componentid == 1148 || componentid == 1038 || componentid == 1035 || componentid == 1147 || componentid == 1146 || componentid == 1040 || componentid == 1036 || componentid == 1041 || componentid == 1039) return componentid;
        case 565: if( componentid == 1046 || componentid == 1045 || componentid == 1153 || componentid == 1152 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1150 || componentid == 1151 || componentid == 1054 || componentid == 1053 || componentid == 1049 || componentid == 1050 || componentid == 1051 || componentid == 1047 || componentid == 1052 || componentid == 1048) return componentid;
        case 566: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 567: if( componentid == 1129 || componentid == 1132 || componentid == 1189 || componentid == 1188 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1187 || componentid == 1186 || componentid == 1130 || componentid == 1131 || componentid == 1102 || componentid == 1133) return componentid;
        case 575: if( componentid == 1044 || componentid == 1043 || componentid == 1174 || componentid == 1175 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1176 || componentid == 1177 || componentid == 1099 || componentid == 1042) return componentid;
        case 576: if( componentid == 1136 || componentid == 1135 || componentid == 1191 || componentid == 1190 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1192 || componentid == 1193 || componentid == 1137 || componentid == 1134) return componentid;
        case 579: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 580: if( componentid == 1020 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1023 || componentid == 1017 || componentid == 1007) return componentid;
        case 585: if( componentid == 1142 || componentid == 1143 || componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1019 || componentid == 1018 || componentid == 1013 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1023 || componentid == 1003 || componentid == 1017 || componentid == 1007) return componentid;
        case 587: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 589: if( componentid == 1005 || componentid == 1004 || componentid == 1144 || componentid == 1145 || componentid == 1020 || componentid == 1018 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1024 || componentid == 1013 || componentid == 1006 || componentid == 1016 || componentid == 1000 || componentid == 1017 || componentid == 1007) return componentid;
        case 600: if( componentid == 1005 || componentid == 1004 || componentid == 1020 || componentid == 1022 || componentid == 1018 || componentid == 1013 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1017 || componentid == 1007) return componentid;
        case 602: if( componentid == 1008 || componentid == 1009 || componentid == 1010) return componentid;
        case 603: if( componentid == 1144 || componentid == 1145 || componentid == 1142 || componentid == 1143 || componentid == 1020 || componentid == 1019 || componentid == 1018 || componentid == 1024 || componentid == 1008 || componentid == 1009 || componentid == 1010 || componentid == 1006 || componentid == 1001 || componentid == 1023 || componentid == 1017 || componentid == 1007) return componentid;
    }
    return false;
}

stock GetVehicleCameraPos(vehicleid, &Float:x, &Float:y, &Float:z, Float:xoff=0.0, Float:yoff=0.0, Float:zoff=0.0) 
{
    new Float:rot;
    GetVehicleZAngle( vehicleid, rot );
    rot = 360 - rot;
    GetVehiclePos( vehicleid, x, y, z );
    x = floatsin( rot, degrees ) * yoff + floatcos( rot, degrees ) * xoff + x;
    y = floatcos( rot, degrees ) * yoff - floatsin( rot, degrees ) * xoff + y;
    z = zoff + z;
}

stock ResetPlayerTuneInfo(playerid) 
{
    playervtuneInfo[playerid][playervtuneStatus] = false;
    playervtuneInfo[playerid][playervtuneID] = -1;
    playervtuneInfo[playerid][playervtuneType] = PLAYER_TUNE_NONE;
    playervtuneInfo[playerid][playervtuneVehID] = INVALID_VEHICLE_ID;
    return 1;
}

stock SetPlayerTuneInfo(playerid, tuneid, type, vehicleid) 
{
    playervtuneInfo[playerid][playervtuneStatus] = true;
    playervtuneInfo[playerid][playervtuneID] = tuneid;
    playervtuneInfo[playerid][playervtuneType] = type;
    playervtuneInfo[playerid][playervtuneVehID] = vehicleid;
    return 1;
}

stock GetPlayerTuneInfo(playerid, &tuneid, &type, &vehicleid) 
{
    tuneid = playervtuneInfo[playerid][playervtuneID];
    type = playervtuneInfo[playerid][playervtuneType];
    vehicleid = playervtuneInfo[playerid][playervtuneVehID];
    return 1;
}

stock VTuneCarmod(playerid, vehicleid, carmod)
{
	new componentid = -1;
    Loop(i, MAX_COMPONENTS) 
    {
        if(componentInfo[i][componentType] == carmod) 
        {
            if(componentInfo[i][componentID] == IsComponentidCompatible(GetVehicleModel(vehicleid), componentInfo[i][componentID])) {
                componentid = i;
            }
			else continue;
        } 
        else continue;
    }

    if(GetVehicleComponentInSlot(vehicleid, carmod) != 0) default_vehicle_component[vehicleid] = GetVehicleComponentInSlot(vehicleid, carmod);
    AddVehicleComponent(vehicleid, componentInfo[componentid][componentID]);

    SetPlayerTuneInfo(playerid, componentid, PLAYER_TUNE_COMPONENT, vehicleid);

    TogglePlayerControllable(playerid, false);
    ShowPlayerVTuneTD(playerid, GetVehicleModelName(GetVehicleModel(vehicleid)), componentInfo[componentid][componentName], componentInfo[componentid][componentNeeds]);
	
	player_vtune_carmodtype[playerid] = carmod;
	return 1;
}
/* TEXTDRAWS */

stock ShowPlayerVTuneTD(playerid, const vmodelname[], const component_name[], needs, storage = 0)
{
	PlayerTextDrawSetString(playerid, td_vtune_title[playerid], va_return("%s Modification", vmodelname));
	PlayerTextDrawSetString(playerid, td_vtune_name[playerid], va_return("%s", component_name));
	PlayerTextDrawSetString(playerid, td_vtune_needs[playerid], va_return("~b~~h~Component Needs: %d", needs));
	PlayerTextDrawSetString(playerid, td_vtune_storage[playerid], va_return("~y~Storage: 2345 components", storage));

	PlayerTextDrawShow(playerid, td_vtune_box[playerid]);
	PlayerTextDrawShow(playerid, td_vtune_line[playerid]);
	PlayerTextDrawShow(playerid, td_vtune_title[playerid]);
	PlayerTextDrawShow(playerid, td_vtune_name[playerid]);
	PlayerTextDrawShow(playerid, td_vtune_needs[playerid]);
	PlayerTextDrawShow(playerid, td_vtune_storage[playerid]);
	PlayerTextDrawShow(playerid, td_vtune_instal[playerid]);
	PlayerTextDrawShow(playerid, td_vtune_next[playerid]);
	PlayerTextDrawShow(playerid, td_vtune_previous[playerid]);
	PlayerTextDrawShow(playerid, td_vtune_close[playerid]);

	SelectTextDraw(playerid, COLOR_ORANGE);
	player_vtunetd_showed[playerid] = true;
    return 1;
}

stock HidePlayerVTuneTD(playerid) 
{
	PlayerTextDrawHide(playerid, td_vtune_box[playerid]);
	PlayerTextDrawHide(playerid, td_vtune_line[playerid]);
	PlayerTextDrawHide(playerid, td_vtune_title[playerid]);
	PlayerTextDrawHide(playerid, td_vtune_name[playerid]);
	PlayerTextDrawHide(playerid, td_vtune_needs[playerid]);
	PlayerTextDrawHide(playerid, td_vtune_storage[playerid]);
	PlayerTextDrawHide(playerid, td_vtune_instal[playerid]);
	PlayerTextDrawHide(playerid, td_vtune_next[playerid]);
	PlayerTextDrawHide(playerid, td_vtune_previous[playerid]);
	PlayerTextDrawHide(playerid, td_vtune_close[playerid]);

	CancelSelectTextDraw(playerid);
	player_vtunetd_showed[playerid] = false;
	return 1;
}

stock LoadPlayerVTuneTD(playerid) 
{
    td_vtune_box[playerid] = CreatePlayerTextDraw(playerid, 501.000000, 252.000000, "_");
	PlayerTextDrawFont(playerid, td_vtune_box[playerid], 1);
	PlayerTextDrawLetterSize(playerid, td_vtune_box[playerid], 0.600000, 7.850000);
	PlayerTextDrawTextSize(playerid, td_vtune_box[playerid], 298.500000, 152.500000);
	PlayerTextDrawSetOutline(playerid, td_vtune_box[playerid], 1);
	PlayerTextDrawSetShadow(playerid, td_vtune_box[playerid], 0);
	PlayerTextDrawAlignment(playerid, td_vtune_box[playerid], 2);
	PlayerTextDrawColor(playerid, td_vtune_box[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, td_vtune_box[playerid], 255);
	PlayerTextDrawBoxColor(playerid, td_vtune_box[playerid], 135);
	PlayerTextDrawUseBox(playerid, td_vtune_box[playerid], 1);
	PlayerTextDrawSetProportional(playerid, td_vtune_box[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, td_vtune_box[playerid], 0);

	td_vtune_line[playerid] = CreatePlayerTextDraw(playerid, 505.000000, 266.000000, "-");
	PlayerTextDrawFont(playerid, td_vtune_line[playerid], 1);
	PlayerTextDrawLetterSize(playerid, td_vtune_line[playerid], 11.770853, 0.549997);
	PlayerTextDrawTextSize(playerid, td_vtune_line[playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, td_vtune_line[playerid], 1);
	PlayerTextDrawSetShadow(playerid, td_vtune_line[playerid], 0);
	PlayerTextDrawAlignment(playerid, td_vtune_line[playerid], 2);
	PlayerTextDrawColor(playerid, td_vtune_line[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, td_vtune_line[playerid], 255);
	PlayerTextDrawBoxColor(playerid, td_vtune_line[playerid], 50);
	PlayerTextDrawUseBox(playerid, td_vtune_line[playerid], 0);
	PlayerTextDrawSetProportional(playerid, td_vtune_line[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, td_vtune_line[playerid], 0);

	td_vtune_title[playerid] = CreatePlayerTextDraw(playerid, 501.000000, 254.000000, "Premier vtune");
	PlayerTextDrawFont(playerid, td_vtune_title[playerid], 1);
	PlayerTextDrawLetterSize(playerid, td_vtune_title[playerid], 0.312500, 1.299999);
	PlayerTextDrawTextSize(playerid, td_vtune_title[playerid], 400.000000, 118.500000);
	PlayerTextDrawSetOutline(playerid, td_vtune_title[playerid], 1);
	PlayerTextDrawSetShadow(playerid, td_vtune_title[playerid], 0);
	PlayerTextDrawAlignment(playerid, td_vtune_title[playerid], 2);
	PlayerTextDrawColor(playerid, td_vtune_title[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, td_vtune_title[playerid], 255);
	PlayerTextDrawBoxColor(playerid, td_vtune_title[playerid], 50);
	PlayerTextDrawUseBox(playerid, td_vtune_title[playerid], 0);
	PlayerTextDrawSetProportional(playerid, td_vtune_title[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, td_vtune_title[playerid], 0);

	td_vtune_name[playerid] = CreatePlayerTextDraw(playerid, 428.000000, 270.000000, "Right X-Flow Sideskirt");
	PlayerTextDrawFont(playerid, td_vtune_name[playerid], 2);
	PlayerTextDrawLetterSize(playerid, td_vtune_name[playerid], 0.191666, 1.000000);
	PlayerTextDrawTextSize(playerid, td_vtune_name[playerid], 578.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, td_vtune_name[playerid], 0);
	PlayerTextDrawSetShadow(playerid, td_vtune_name[playerid], 0);
	PlayerTextDrawAlignment(playerid, td_vtune_name[playerid], 1);
	PlayerTextDrawColor(playerid, td_vtune_name[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, td_vtune_name[playerid], 255);
	PlayerTextDrawBoxColor(playerid, td_vtune_name[playerid], 50);
	PlayerTextDrawUseBox(playerid, td_vtune_name[playerid], 0);
	PlayerTextDrawSetProportional(playerid, td_vtune_name[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, td_vtune_name[playerid], 0);

	td_vtune_needs[playerid] = CreatePlayerTextDraw(playerid, 428.000000, 280.000000, "~b~~h~Component Needs: 200");
	PlayerTextDrawFont(playerid, td_vtune_needs[playerid], 2);
	PlayerTextDrawLetterSize(playerid, td_vtune_needs[playerid], 0.191666, 1.000000);
	PlayerTextDrawTextSize(playerid, td_vtune_needs[playerid], 578.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, td_vtune_needs[playerid], 0);
	PlayerTextDrawSetShadow(playerid, td_vtune_needs[playerid], 0);
	PlayerTextDrawAlignment(playerid, td_vtune_needs[playerid], 1);
	PlayerTextDrawColor(playerid, td_vtune_needs[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, td_vtune_needs[playerid], 255);
	PlayerTextDrawBoxColor(playerid, td_vtune_needs[playerid], 50);
	PlayerTextDrawUseBox(playerid, td_vtune_needs[playerid], 0);
	PlayerTextDrawSetProportional(playerid, td_vtune_needs[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, td_vtune_needs[playerid], 0);

	td_vtune_storage[playerid] = CreatePlayerTextDraw(playerid, 428.000000, 290.000000, "~y~Storage: 2345 components");
	PlayerTextDrawFont(playerid, td_vtune_storage[playerid], 2);
	PlayerTextDrawLetterSize(playerid, td_vtune_storage[playerid], 0.191666, 1.000000);
	PlayerTextDrawTextSize(playerid, td_vtune_storage[playerid], 578.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, td_vtune_storage[playerid], 0);
	PlayerTextDrawSetShadow(playerid, td_vtune_storage[playerid], 0);
	PlayerTextDrawAlignment(playerid, td_vtune_storage[playerid], 1);
	PlayerTextDrawColor(playerid, td_vtune_storage[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, td_vtune_storage[playerid], 255);
	PlayerTextDrawBoxColor(playerid, td_vtune_storage[playerid], 50);
	PlayerTextDrawUseBox(playerid, td_vtune_storage[playerid], 0);
	PlayerTextDrawSetProportional(playerid, td_vtune_storage[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, td_vtune_storage[playerid], 0);

	td_vtune_instal[playerid] = CreatePlayerTextDraw(playerid, 501.000000, 301.000000, "instal");
	PlayerTextDrawFont(playerid, td_vtune_instal[playerid], 3);
	PlayerTextDrawLetterSize(playerid, td_vtune_instal[playerid], 0.474999, 2.099998);
	PlayerTextDrawTextSize(playerid, td_vtune_instal[playerid], 16.500000, 56.000000);
	PlayerTextDrawSetOutline(playerid, td_vtune_instal[playerid], 1);
	PlayerTextDrawSetShadow(playerid, td_vtune_instal[playerid], 0);
	PlayerTextDrawAlignment(playerid, td_vtune_instal[playerid], 2);
	PlayerTextDrawColor(playerid, td_vtune_instal[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, td_vtune_instal[playerid], 255);
	PlayerTextDrawBoxColor(playerid, td_vtune_instal[playerid], 200);
	PlayerTextDrawUseBox(playerid, td_vtune_instal[playerid], 0);
	PlayerTextDrawSetProportional(playerid, td_vtune_instal[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, td_vtune_instal[playerid], 1);

	td_vtune_next[playerid] = CreatePlayerTextDraw(playerid, 553.000000, 301.000000, "ld_beat:right");
	PlayerTextDrawFont(playerid, td_vtune_next[playerid], 4);
	PlayerTextDrawLetterSize(playerid, td_vtune_next[playerid], 0.474999, 2.099998);
	PlayerTextDrawTextSize(playerid, td_vtune_next[playerid], 21.500000, 22.500000);
	PlayerTextDrawSetOutline(playerid, td_vtune_next[playerid], 1);
	PlayerTextDrawSetShadow(playerid, td_vtune_next[playerid], 0);
	PlayerTextDrawAlignment(playerid, td_vtune_next[playerid], 2);
	PlayerTextDrawColor(playerid, td_vtune_next[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, td_vtune_next[playerid], 255);
	PlayerTextDrawBoxColor(playerid, td_vtune_next[playerid], 200);
	PlayerTextDrawUseBox(playerid, td_vtune_next[playerid], 0);
	PlayerTextDrawSetProportional(playerid, td_vtune_next[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, td_vtune_next[playerid], 1);

	td_vtune_previous[playerid] = CreatePlayerTextDraw(playerid, 429.000000, 301.000000, "ld_beat:left");
	PlayerTextDrawFont(playerid, td_vtune_previous[playerid], 4);
	PlayerTextDrawLetterSize(playerid, td_vtune_previous[playerid], 0.474999, 2.099998);
	PlayerTextDrawTextSize(playerid, td_vtune_previous[playerid], 21.500000, 22.500000);
	PlayerTextDrawSetOutline(playerid, td_vtune_previous[playerid], 1);
	PlayerTextDrawSetShadow(playerid, td_vtune_previous[playerid], 0);
	PlayerTextDrawAlignment(playerid, td_vtune_previous[playerid], 2);
	PlayerTextDrawColor(playerid, td_vtune_previous[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, td_vtune_previous[playerid], 255);
	PlayerTextDrawBoxColor(playerid, td_vtune_previous[playerid], 200);
	PlayerTextDrawUseBox(playerid, td_vtune_previous[playerid], 0);
	PlayerTextDrawSetProportional(playerid, td_vtune_previous[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, td_vtune_previous[playerid], 1);

	td_vtune_close[playerid] = CreatePlayerTextDraw(playerid, 565.000000, 240.000000, "ld_beat:cross");
	PlayerTextDrawFont(playerid, td_vtune_close[playerid], 4);
	PlayerTextDrawLetterSize(playerid, td_vtune_close[playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, td_vtune_close[playerid], 22.500000, 22.000000);
	PlayerTextDrawSetOutline(playerid, td_vtune_close[playerid], 1);
	PlayerTextDrawSetShadow(playerid, td_vtune_close[playerid], 0);
	PlayerTextDrawAlignment(playerid, td_vtune_close[playerid], 1);
	PlayerTextDrawColor(playerid, td_vtune_close[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, td_vtune_close[playerid], 255);
	PlayerTextDrawBoxColor(playerid, td_vtune_close[playerid], 50);
	PlayerTextDrawUseBox(playerid, td_vtune_close[playerid], 1);
	PlayerTextDrawSetProportional(playerid, td_vtune_close[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, td_vtune_close[playerid], 1);
    return 1;
}

stock DestroyPlayerVTuneTD(playerid) 
{
	PlayerTextDrawDestroy(playerid, td_vtune_box[playerid]);
	PlayerTextDrawDestroy(playerid, td_vtune_line[playerid]);
	PlayerTextDrawDestroy(playerid, td_vtune_title[playerid]);
	PlayerTextDrawDestroy(playerid, td_vtune_name[playerid]);
	PlayerTextDrawDestroy(playerid, td_vtune_needs[playerid]);
	PlayerTextDrawDestroy(playerid, td_vtune_storage[playerid]);
	PlayerTextDrawDestroy(playerid, td_vtune_instal[playerid]);
	PlayerTextDrawDestroy(playerid, td_vtune_next[playerid]);
	PlayerTextDrawDestroy(playerid, td_vtune_previous[playerid]);
	PlayerTextDrawDestroy(playerid, td_vtune_close[playerid]);
	return 1;
}