new vehicle_modification[MAX_VEHICLES][14];
new bool:player_vtunetd_showed[MAX_PLAYERS];
new player_vtune_carmodtype[MAX_PLAYERS];

/* Vehicle Tuning (Menyimpan data sementara jika tune dibatalkan) */
new default_vehicle_color[MAX_VEHICLES][2];
new default_vehicle_paintjob[MAX_VEHICLES];
new default_vehicle_component[MAX_VEHICLES];

#define PLAYER_TUNE_NONE 0
#define PLAYER_TUNE_PAINTJOB 1
#define PLAYER_TUNE_COLOR 2
#define PLAYER_TUNE_COMPONENT 3

enum PLAYER_VTUNE_INFO
{
    bool:playervtuneStatus,
    playervtuneID,
    playervtuneType,
    playervtuneVehID
}
new playervtuneInfo[MAX_PLAYERS][PLAYER_VTUNE_INFO];

enum // Dialog
{
    VEHICLE_TUNE_LIST,
    VEHICLE_TUNE_PAINTJOB,
    VEHICLE_TUNE_COLOR,
    VEHICLE_TUNE_EXHAUST,
    VEHICLE_TUNE_FRONTBUMPER,
    VEHICLE_TUNE_REARBUMBER,
    VEHICLE_TUNE_ROOF,
    VEHICLE_TUNE_SPOILERS,
    VEHICLE_TUNE_SIDESKIRT,
    VEHICLE_TUNE_WHEEL,
    VEHICLE_TUNE_HYDRAULICS,
    VEHICLE_TUNE_NITRO
}

enum COMPONENT_INFO {
	componentID,
    componentNeeds,
	componentName[40],
	componentType
};
#define MAX_COMPONENTS	194
new
	componentInfo[MAX_COMPONENTS][COMPONENT_INFO] = {
	{1000, 10, "Pro Spoiler", CARMODTYPE_SPOILER},
	{1001, 10, "Win Spoiler", CARMODTYPE_SPOILER},
	{1002, 10, "Drag Spoiler", CARMODTYPE_SPOILER},
	{1003, 10, "Alpha Spoiler", CARMODTYPE_SPOILER},
	{1004, 10, "Champ Scoop Hood", CARMODTYPE_HOOD},
	{1005, 10, "Fury Scoop Hood", CARMODTYPE_HOOD},
	{1006, 10, "Roof Scoop Roof", CARMODTYPE_ROOF},
	{1007, 10, "Right Sideskirt", CARMODTYPE_SIDESKIRT},
	{1008, 10, "5x Nitrous", CARMODTYPE_NITRO},
	{1009, 10, "2x Nitrous", CARMODTYPE_NITRO},
	{1010, 10, "10x Nitrous", CARMODTYPE_NITRO},
	{1011, 10, "Race Scoop Hood", CARMODTYPE_HOOD},
	{1012, 10, "Worx Scoop Hood", CARMODTYPE_HOOD},
	{1013, 10, "Round Fog Lamp", CARMODTYPE_LAMPS},
	{1014, 10, "Champ Spoiler", CARMODTYPE_SPOILER},
	{1015, 10, "Race Spoiler", CARMODTYPE_SPOILER},
	{1016, 10, "Worx Spoiler", CARMODTYPE_SPOILER},
	{1017, 10, "Left Sideskirt", CARMODTYPE_SIDESKIRT},
	{1018, 10, "Upswept Exhaust", CARMODTYPE_EXHAUST},
	{1019, 10, "Twin Exhaust", CARMODTYPE_EXHAUST},
	{1020, 10, "Large Exhaust", CARMODTYPE_EXHAUST},
	{1021, 10, "Medium Exhaust", CARMODTYPE_EXHAUST},
	{1022, 10, "Small Exhaust", CARMODTYPE_EXHAUST},
	{1023, 10, "Fury Spoiler", CARMODTYPE_SPOILER},
	{1024, 10, "Square Fog Lamp", CARMODTYPE_LAMPS},
	{1025, 10, "Offroad Wheels", CARMODTYPE_WHEELS},
	{1026, 10, "Right Alien Sideskirt", CARMODTYPE_SIDESKIRT},
	{1027, 10, "Left Alien Sideskirt", CARMODTYPE_SIDESKIRT},
	{1028, 10, "Alien Exhaust", CARMODTYPE_EXHAUST},
	{1029, 10, "X-Flow Exhaust", CARMODTYPE_EXHAUST},
	{1030, 10, "Left X-Flow Sideskirt", CARMODTYPE_SIDESKIRT},
	{1031, 10, "Right X-Flow Sideskirt", CARMODTYPE_SIDESKIRT},
	{1032, 10, "Alien Roof Vent", CARMODTYPE_ROOF},
	{1033, 10, "X-Flow Roof Vent", CARMODTYPE_ROOF},
	{1034, 10, "Alien Exhaust", CARMODTYPE_EXHAUST},
	{1035, 10, "X-Flow Roof Vent", CARMODTYPE_ROOF},
	{1036, 10, "Right Alien Sideskirt", CARMODTYPE_SIDESKIRT},
	{1037, 10, "X-Flow Exhaust", CARMODTYPE_EXHAUST},
	{1038, 10, "Alien Roof Vent", CARMODTYPE_ROOF},
	{1039, 10, "Left X-Flow Sideskirt", CARMODTYPE_SIDESKIRT},
	{1040, 10, "Left Alien Sideskirt", CARMODTYPE_SIDESKIRT},
	{1041, 10, "Right X-Flow Sideskirt", CARMODTYPE_SIDESKIRT},
	{1042, 10, "Right Chrome Sideskirt", CARMODTYPE_SIDESKIRT},
	{1043, 10, "Slamin Exhaust", CARMODTYPE_EXHAUST},
	{1044, 10, "Chrome Exhaust", CARMODTYPE_EXHAUST},
	{1045, 10, "X-Flow Exhaust", CARMODTYPE_EXHAUST},
	{1046, 10, "Alien Exhaust", CARMODTYPE_EXHAUST},
	{1047, 10, "Right Alien Sideskirt", CARMODTYPE_SIDESKIRT},
	{1048, 10, "Right X-Flow Sideskirt", CARMODTYPE_SIDESKIRT},
	{1049, 10, "Alien Spoiler", CARMODTYPE_SPOILER},
	{1050, 10, "X-Flow Spoiler", CARMODTYPE_SPOILER},
	{1051, 10, "Left Alien Sideskirt", CARMODTYPE_SPOILER},
	{1052, 10, "Left X-Flow Sideskirt", CARMODTYPE_SPOILER},
	{1053, 10, "X-Flow Roof", CARMODTYPE_ROOF},
	{1054, 10, "Alien Roof", CARMODTYPE_ROOF},
	{1055, 10, "Alien Roof", CARMODTYPE_ROOF},
	{1056, 10, "Right Alien Sideskirt", CARMODTYPE_SIDESKIRT},
	{1057, 10, "Right X-Flow Sideskirt", CARMODTYPE_SIDESKIRT},
	{1058, 10, "Alien Spoiler", CARMODTYPE_SPOILER},
	{1059, 10, "X-Flow Exhaust", CARMODTYPE_EXHAUST},
	{1060, 10, "X-Flow Spoiler", CARMODTYPE_SPOILER},
	{1061, 10, "X-Flow Roof", CARMODTYPE_ROOF},
	{1062, 10, "Left Alien Sideskirt", CARMODTYPE_SIDESKIRT},
	{1063, 10, "Left X-Flow Sideskirt", CARMODTYPE_SIDESKIRT},
	{1064, 10, "Alien Exhaust", CARMODTYPE_EXHAUST},
	{1065, 10, "Alien Exhaust", CARMODTYPE_EXHAUST},
	{1066, 10, "X-Flow Exhaust", CARMODTYPE_EXHAUST},
	{1067, 10, "Alien Roof", CARMODTYPE_ROOF},
	{1068, 10, "X-Flow Roof", CARMODTYPE_ROOF},
	{1069, 10, "Right Alien Sideskirt", CARMODTYPE_SIDESKIRT},
	{1070, 10, "Right X-Flow Sideskirt", CARMODTYPE_SIDESKIRT},
	{1071, 10, "Left Alien Sideskirt", CARMODTYPE_SIDESKIRT},
	{1072, 10, "Left X-Flow Sideskirt", CARMODTYPE_SIDESKIRT},
	{1073, 10, "Shadow Wheels", CARMODTYPE_WHEELS},
	{1074, 10, "Mega Wheels", CARMODTYPE_WHEELS},
	{1075, 10, "Rimshine Wheels", CARMODTYPE_WHEELS},
	{1076, 10, "Wires Wheels", CARMODTYPE_WHEELS},
	{1077, 10, "Classic Wheels", CARMODTYPE_WHEELS},
	{1078, 10, "Twist Wheels", CARMODTYPE_WHEELS},
	{1079, 10, "Cutter Wheels", CARMODTYPE_WHEELS},
	{1080, 10, "Switch Wheels", CARMODTYPE_WHEELS},
	{1081, 10, "Grove Wheels", CARMODTYPE_WHEELS},
	{1082, 10, "Import Wheels", CARMODTYPE_WHEELS},
	{1083, 10, "Dollar Wheels", CARMODTYPE_WHEELS},
	{1084, 10, "Trance Wheels", CARMODTYPE_WHEELS},
	{1085, 10, "Atomic Wheels", CARMODTYPE_WHEELS},
	{1086, 10, "Stereo Wheels", CARMODTYPE_STEREO},
	{1087, 10, "Hydraulics", CARMODTYPE_HYDRAULICS},
	{1088, 10, "Alien Roof", CARMODTYPE_ROOF},
	{1089, 10, "X-Flow Exhaust", CARMODTYPE_EXHAUST},
	{1090, 10, "Right Alien Sideskirt", CARMODTYPE_SIDESKIRT},
	{1091, 10, "X-Flow Roof", CARMODTYPE_ROOF},
	{1092, 10, "Alien Exhaust", CARMODTYPE_EXHAUST},
	{1093, 10, "Right X-Flow Sideskirt", CARMODTYPE_SIDESKIRT},
	{1094, 10, "Left Alien Sideskirt", CARMODTYPE_SIDESKIRT},
	{1095, 10, "Right X-Flow Sideskirt", CARMODTYPE_SIDESKIRT},
	{1096, 10, "Ahab Wheels", CARMODTYPE_WHEELS},
	{1097, 10, "Virtual Wheels", CARMODTYPE_WHEELS},
	{1098, 10, "Access Wheels", CARMODTYPE_WHEELS},
	{1099, 10, "Left Chrome Sideskirt", CARMODTYPE_SIDESKIRT},
	{1100, 10, "Chrome Grill", -1}, // Bullbar
	{1101, 10, "Left `Chrome Flames` Sideskirt", CARMODTYPE_SIDESKIRT},
	{1102, 10, "Left `Chrome Strip` Sideskirt", CARMODTYPE_SIDESKIRT},
	{1103, 10, "Covertible Roof", CARMODTYPE_ROOF},
	{1104, 10, "Chrome Exhaust", CARMODTYPE_EXHAUST},
	{1105, 10, "Slamin Exhaust", CARMODTYPE_EXHAUST},
	{1106, 10, "Right `Chrome Arches`", CARMODTYPE_SIDESKIRT},
	{1107, 10, "Left `Chrome Strip` Sideskirt", CARMODTYPE_SIDESKIRT},
	{1108, 10, "Right `Chrome Strip` Sideskirt", CARMODTYPE_SIDESKIRT},
	{1109, 10, "Chrome", -1}, // Bullbar
	{1110, 10, "Slamin", -1}, // Bullbar
	{1111, 10, "Little Sign?", -1}, // sig
	{1112, 10, "Little Sign?", -1}, // sig
	{1113, 10, "Chrome Exhaust", CARMODTYPE_EXHAUST},
	{1114, 10, "Slamin Exhaust", CARMODTYPE_EXHAUST},
	{1115, 10, "Chrome", -1}, // Bullbar
	{1116, 10, "Slamin", -1}, // Bullbar
	{1117, 10, "Chrome Front Bumper", CARMODTYPE_FRONT_BUMPER},
	{1118, 10, "Right `Chrome Trim` Sideskirt", CARMODTYPE_SIDESKIRT},
	{1119, 10, "Right `Wheelcovers` Sideskirt", CARMODTYPE_SIDESKIRT},
	{1120, 10, "Left `Chrome Trim` Sideskirt", CARMODTYPE_SIDESKIRT},
	{1121, 10, "Left `Wheelcovers` Sideskirt", CARMODTYPE_SIDESKIRT},
	{1122, 10, "Right `Chrome Flames` Sideskirt", CARMODTYPE_SIDESKIRT},
	{1123, 10, "Bullbar Chrome Bars", -1}, // Bullbar
	{1124, 10, "Left `Chrome Arches` Sideskirt", CARMODTYPE_SIDESKIRT},
	{1125, 10, "Bullbar Chrome Lights", -1}, // Bullbar
	{1126, 10, "Chrome Exhaust", CARMODTYPE_EXHAUST},
	{1127, 10, "Slamin Exhaust", CARMODTYPE_EXHAUST},
	{1128, 10, "Vinyl Hardtop", CARMODTYPE_ROOF},
	{1129, 10, "Chrome Exhaust", CARMODTYPE_EXHAUST},
	{1130, 10, "Hardtop Roof", CARMODTYPE_ROOF},
	{1131, 10, "Softtop Roof", CARMODTYPE_ROOF},
	{1132, 10, "Slamin Exhaust", CARMODTYPE_EXHAUST},
	{1133, 10, "Right `Chrome Strip` Sideskirt", CARMODTYPE_SIDESKIRT},
	{1134, 10, "Right `Chrome Strip` Sideskirt", CARMODTYPE_SIDESKIRT},
	{1135, 10, "Slamin Exhaust", CARMODTYPE_EXHAUST},
	{1136, 10, "Chrome Exhaust", CARMODTYPE_EXHAUST},
	{1137, 10, "Left `Chrome Strip` Sideskirt", CARMODTYPE_SIDESKIRT},
	{1138, 10, "Alien Spoiler", CARMODTYPE_SPOILER},
	{1139, 10, "X-Flow Spoiler", CARMODTYPE_SPOILER},
	{1140, 10, "X-Flow Rear Bumper", CARMODTYPE_REAR_BUMPER},
	{1141, 10, "Alien Rear Bumper", CARMODTYPE_REAR_BUMPER},
	{1142, 10, "Left Oval Vents", CARMODTYPE_VENT_LEFT},
	{1143, 10, "Right Oval Vents", CARMODTYPE_VENT_RIGHT},
	{1144, 10, "Left Square Vents", CARMODTYPE_VENT_LEFT},
	{1145, 10, "Right Square Vents", CARMODTYPE_VENT_RIGHT},
	{1146, 10, "X-Flow Spoiler", CARMODTYPE_SPOILER},
	{1147, 10, "Alien Spoiler", CARMODTYPE_SPOILER},
	{1148, 10, "X-Flow Rear Bumper", CARMODTYPE_REAR_BUMPER},
	{1149, 10, "Alien Rear Bumper", CARMODTYPE_REAR_BUMPER},
	{1150, 10, "Alien Rear Bumper", CARMODTYPE_REAR_BUMPER},
	{1151, 10, "X-Flow Rear Bumper", CARMODTYPE_REAR_BUMPER},
	{1152, 10, "X-Flow Front Bumper", CARMODTYPE_FRONT_BUMPER},
	{1153, 10, "Alien Front Bumper", CARMODTYPE_FRONT_BUMPER},
	{1154, 10, "Alien Rear Bumper", CARMODTYPE_REAR_BUMPER},
	{1155, 10, "Alien Front Bumper", CARMODTYPE_FRONT_BUMPER},
	{1156, 10, "X-Flow Rear Bumper", CARMODTYPE_REAR_BUMPER},
	{1157, 10, "X-Flow Front Bumper", CARMODTYPE_FRONT_BUMPER},
	{1158, 10, "X-Flow Spoiler", CARMODTYPE_SPOILER},
	{1159, 10, "Alien Rear Bumper", CARMODTYPE_REAR_BUMPER},
	{1160, 10, "Alien Front Bumper", CARMODTYPE_FRONT_BUMPER},
	{1161, 10, "X-Flow Rear Bumper", CARMODTYPE_REAR_BUMPER},
	{1162, 10, "Alien Spoiler", CARMODTYPE_SPOILER},
	{1163, 10, "X-Flow Spoiler", CARMODTYPE_SPOILER},
	{1164, 10, "Alien Spoiler", CARMODTYPE_SPOILER},
	{1165, 10, "X-Flow Front Bumper", CARMODTYPE_FRONT_BUMPER},
	{1166, 10, "Alien Front Bumper", CARMODTYPE_FRONT_BUMPER},
	{1167, 10, "X-Flow Rear Bumper", CARMODTYPE_REAR_BUMPER},
	{1168, 10, "Alien Rear Bumper", CARMODTYPE_REAR_BUMPER},
	{1169, 10, "Alien Front Bumper", CARMODTYPE_FRONT_BUMPER},
	{1170, 10, "X-Flow Front Bumper", CARMODTYPE_FRONT_BUMPER},
	{1171, 10, "Alien Front Bumper", CARMODTYPE_FRONT_BUMPER},
	{1172, 10, "X-Flow Front Bumper", CARMODTYPE_FRONT_BUMPER},
	{1173, 10, "X-Flow Front Bumper", CARMODTYPE_FRONT_BUMPER},
	{1174, 10, "Chrome Front Bumper", CARMODTYPE_FRONT_BUMPER},
	{1175, 10, "Slamin Front Bumper", CARMODTYPE_FRONT_BUMPER},
	{1176, 10, "Chrome Rear Bumper", CARMODTYPE_REAR_BUMPER},
	{1177, 10, "Slamin Rear Bumper", CARMODTYPE_REAR_BUMPER},
	{1178, 10, "Slamin Rear Bumper", CARMODTYPE_REAR_BUMPER},
	{1179, 10, "Chrome Front Bumper", CARMODTYPE_FRONT_BUMPER},
	{1180, 10, "Chrome Rear Bumper", CARMODTYPE_REAR_BUMPER},
	{1181, 10, "Slamin Front Bumper", CARMODTYPE_FRONT_BUMPER},
	{1182, 10, "Chrome Front Bumper", CARMODTYPE_FRONT_BUMPER},
	{1183, 10, "Slamin Rear Bumper", CARMODTYPE_REAR_BUMPER},
	{1184, 10, "Chrome Rear Bumper", CARMODTYPE_REAR_BUMPER},
	{1185, 10, "Slamin Front Bumper", CARMODTYPE_FRONT_BUMPER},
	{1186, 10, "Slamin Rear Bumper", CARMODTYPE_REAR_BUMPER},
	{1187, 10, "Chrome Rear Bumper", CARMODTYPE_REAR_BUMPER},
	{1188, 10, "Slamin Front Bumper", CARMODTYPE_FRONT_BUMPER},
	{1189, 10, "Chrome Front Bumper", CARMODTYPE_FRONT_BUMPER},
	{1190, 10, "Slamin Front Bumper", CARMODTYPE_FRONT_BUMPER},
	{1191, 10, "Chrome Front Bumper", CARMODTYPE_FRONT_BUMPER},
	{1192, 10, "Chrome Rear Bumper", CARMODTYPE_REAR_BUMPER},
	{1193, 10, "Slamin Rear Bumper", CARMODTYPE_REAR_BUMPER}
};

enum PAINTJOB_INFO {
	paintjobModel,
	paintjobNeeds,
	paintjobID,
	paintjobName[12]
};
#define NUMBER_TYPE_PAINTJOB 	36
new
	paintjobInfo[NUMBER_TYPE_PAINTJOB][PAINTJOB_INFO] = {
	{483, 10, 0, "Paintjob 1"},
	{534, 10, 0, "Paintjob 1"},
	{534, 10, 1, "Paintjob 2"},
	{534, 10, 2, "Paintjob 3"},
	{535, 10, 0, "Paintjob 1"},
	{535, 10, 1, "Paintjob 2"},
	{535, 10, 2, "Paintjob 3"},
	{536, 10, 0, "Paintjob 1"},
	{536, 10, 1, "Paintjob 2"},
	{536, 10, 2, "Paintjob 3"},
	{558, 10, 0, "Paintjob 1"},
	{558, 10, 1, "Paintjob 2"},
	{558, 10, 2, "Paintjob 3"},
	{559, 10, 0, "Paintjob 1"},
	{559, 10, 1, "Paintjob 2"},
	{559, 10, 2, "Paintjob 3"},
	{560, 10, 0, "Paintjob 1"},
	{560, 10, 1, "Paintjob 2"},
	{560, 10, 2, "Paintjob 3"},
	{561, 10, 0, "Paintjob 1"},
	{561, 10, 1, "Paintjob 2"},
	{561, 10, 2, "Paintjob 3"},
	{562, 10, 0, "Paintjob 1"},
	{562, 10, 1, "Paintjob 2"},
	{562, 10, 2, "Paintjob 3"},
	{565, 10, 0, "Paintjob 1"},
	{565, 10, 1, "Paintjob 2"},
	{565, 10, 2, "Paintjob 3"},
	{567, 10, 0, "Paintjob 1"},
	{567, 10, 1, "Paintjob 2"},
	{567, 10, 2, "Paintjob 3"},
	{575, 10, 0, "Paintjob 1"},
	{575, 10, 1, "Paintjob 2"},
	{576, 10, 0, "Paintjob 1"},
	{576, 10, 1, "Paintjob 2"},
	{576, 10, 2, "Paintjob 3"}
};

new PlayerText:td_vtune_box[MAX_PLAYERS];
new PlayerText:td_vtune_line[MAX_PLAYERS];
new PlayerText:td_vtune_title[MAX_PLAYERS];
new PlayerText:td_vtune_name[MAX_PLAYERS];
new PlayerText:td_vtune_needs[MAX_PLAYERS];
new PlayerText:td_vtune_storage[MAX_PLAYERS];
new PlayerText:td_vtune_instal[MAX_PLAYERS];
new PlayerText:td_vtune_next[MAX_PLAYERS];
new PlayerText:td_vtune_previous[MAX_PLAYERS];
new PlayerText:td_vtune_close[MAX_PLAYERS];