#include <YSI_Coding\y_hooks>

// Kode ini, berisikan kode yang digunakan dalam (EVF2.inc) yang telah dimodifikasi untuk penggunaan YSI
#define MAX_VEHICLE_MODELS						212
#define MAX_VEHICLE_PARAMS						7

#define GetVehicleModelTopSpeed(%0)				TopSpeed[((%0)-400)]
#define SetVehicleInterior LinkVehicleToInterior

enum e_OffsetTypes {
	VEHICLE_OFFSET_BOOT,
	VEHICLE_OFFSET_HOOD,
	VEHICLE_OFFSET_ROOF
};

enum 
{
	VEHICLE_PARAMS_ENGINE,
	VEHICLE_PARAMS_LIGHTS,
    VEHICLE_PARAMS_ALARM,
	VEHICLE_PARAMS_DOORS,
	VEHICLE_PARAMS_BONNET,
	VEHICLE_PARAMS_BOOT,
	VEHICLE_PARAMS_OBJECTIVE
};

new const Float:TopSpeed[MAX_VEHICLE_MODELS] = {
	157.0, 147.0, 186.0, 110.0, 133.0, 164.0, 110.0, 148.0, 100.0, 158.0, 129.0, 221.0, 168.0, 110.0, 105.0, 192.0, 154.0, 270.0, 115.0, 149.0,
	145.0, 154.0, 140.0, 99.0,  135.0, 270.0, 173.0, 165.0, 157.0, 201.0, 190.0, 130.0, 94.0,  110.0, 167.0, 0.0,   149.0, 158.0, 142.0, 168.0,
	136.0, 145.0, 139.0, 126.0, 110.0, 164.0, 270.0, 270.0, 111.0, 0.0,   0.0,   193.0, 270.0, 60.0,  135.0, 157.0, 106.0, 95.0,  157.0, 136.0,
	270.0, 160.0, 111.0, 142.0, 145.0, 145.0, 147.0, 140.0, 144.0, 270.0, 157.0, 110.0, 190.0, 190.0, 149.0, 173.0, 270.0, 186.0, 117.0, 140.0,
	184.0, 73.0,  156.0, 122.0, 190.0, 99.0,  64.0,  270.0, 270.0, 139.0, 157.0, 149.0, 140.0, 270.0, 214.0, 176.0, 162.0, 270.0, 108.0, 123.0,
	140.0, 145.0, 216.0, 216.0, 173.0, 140.0, 179.0, 166.0, 108.0, 79.0,  101.0, 270.0,	270.0, 270.0, 120.0, 142.0, 157.0, 157.0, 164.0, 270.0, 
	270.0, 160.0, 176.0, 151.0, 130.0, 160.0, 158.0, 149.0, 176.0, 149.0, 60.0,  70.0,  110.0, 167.0, 168.0, 158.0, 173.0, 0.0,   0.0,   270.0,
	149.0, 203.0, 164.0, 151.0, 150.0, 147.0, 149.0, 142.0, 270.0, 153.0, 145.0, 157.0, 121.0, 270.0, 144.0, 158.0, 113.0, 113.0, 156.0, 178.0,
	169.0, 154.0, 178.0, 270.0, 145.0, 165.0, 160.0, 173.0, 146.0, 0.0,   0.0,   93.0,  60.0,  110.0, 60.0,  158.0, 158.0, 270.0, 130.0, 158.0,
	153.0, 151.0, 136.0, 85.0,  0.0,   153.0, 142.0, 165.0, 108.0, 162.0, 0.0,   0.0,   270.0, 270.0, 130.0, 190.0, 175.0, 175.0, 175.0, 158.0,
	151.0, 110.0, 169.0, 171.0, 148.0, 152.0, 0.0,   0.0,   0.0,   108.0, 0.0,   0.0
};

new const CarColors[][]={
	{16, 004, 001, 123, 001, 113, 001, 101, 001, 075, 001, 062, 001, 040, 001, 036, 001},
	{16, 041, 041, 047, 047, 052, 052, 066, 066, 074, 074, 087, 087, 091, 091, 113, 113},
	{16, 010, 010, 013, 013, 022, 022, 030, 030, 039, 039, 090, 090, 098, 098, 110, 110},
	{16, 036, 001, 037, 001, 030, 001, 028, 001, 025, 001, 040, 001, 101, 001, 113, 001},
	{16, 113, 039, 119, 050, 123, 092, 109, 100, 101, 101, 095, 105, 083, 110, 066, 025},
	{16, 011, 001, 024, 001, 036, 001, 040, 001, 075, 001, 091, 001, 123, 001, 004, 001},
	{2, 001, 001},
	{2, 003, 001},
	{2, 026, 026},
	{2, 001, 001},
	{16, 004, 001, 009, 001, 010, 001, 025, 001, 036, 001, 040, 001, 045, 001, 084, 001},
	{16, 012, 001, 064, 001, 123, 001, 116, 001, 112, 001, 106, 001, 080, 001, 075, 001},
	{16, 009, 001, 010, 008, 011, 001, 025, 008, 027, 001, 029, 008, 030, 001, 037, 008},
	{16, 087, 001, 088, 001, 091, 001, 105, 001, 109, 001, 119, 001, 004, 001, 025, 001},
	{16, 025, 001, 028, 001, 043, 001, 067, 001, 072, 001, 009, 001, 095, 001, 024, 001},
	{16, 020, 001, 025, 001, 036, 001, 040, 001, 062, 001, 075, 001, 092, 001, 000, 001},
	{2, 001, 003},
	{0, 000, 000},
	{16, 119, 119, 117, 227, 114, 114, 108, 108, 095, 095, 081, 081, 061, 061, 041, 041},
	{16, 045, 075, 047, 076, 033, 075, 013, 076, 054, 075, 069, 076, 059, 075, 087, 076},
	{2, 006, 001},
	{16, 004, 001, 013, 001, 025, 001, 030, 001, 036, 001, 040, 001, 075, 001, 095, 001},
	{14, 096, 025, 097, 025, 101, 025, 111, 031, 113, 036, 083, 057, 067, 059},
	{12, 001, 016, 001, 056, 001, 017, 001, 053, 001, 005, 001, 035},
	{16, 001, 000, 002, 002, 003, 002, 003, 006, 006, 016, 015, 030, 024, 053, 035, 061},
	{2, 043, 000},
	{16, 037, 037, 042, 042, 053, 053, 062, 062, 007, 007, 010, 010, 011, 011, 015, 015},
	{2, 000, 001},
	{2, 004, 075},
	{16, 012, 012, 013, 013, 014, 014, 001, 002, 002, 001, 001, 003, 003, 001, 010, 010},
	{2, 046, 026},
	{16, 071, 059, 075, 059, 092, 072, 047, 074, 055, 083, 059, 083, 071, 087, 082, 087},
	{2, 043, 000},
	{2, 043, 000},
	{14, 001, 001, 012, 012, 002, 002, 006, 006, 004, 004, 046, 046, 053, 053},
	{2, 001, 001},
	{14, 083, 001, 087, 001, 092, 001, 095, 001, 109, 001, 119, 045, 011, 001},
	{16, 054, 007, 079, 007, 087, 007, 095, 016, 098, 020, 105, 020, 123, 020, 125, 021},
	{2, 006, 076},
	{16, 057, 008, 008, 017, 043, 021, 054, 038, 067, 008, 037, 078, 065, 079, 025, 078},
	{16, 034, 034, 032, 032, 020, 020, 110, 110, 066, 066, 084, 084, 118, 118, 121, 121},
	{16, 002, 096, 079, 042, 082, 054, 067, 086, 126, 096, 070, 096, 110, 054, 067, 098},
	{16, 000, 000, 011, 105, 025, 109, 036, 000, 040, 036, 075, 036, 000, 036, 000, 109},
	{16, 004, 001, 020, 001, 024, 001, 025, 001, 036, 001, 040, 001, 054, 001, 084, 001},
	{12, 032, 036, 032, 042, 032, 053, 032, 066, 032, 014, 032, 032},
	{16, 034, 034, 035, 035, 037, 037, 039, 039, 041, 041, 043, 043, 045, 045, 047, 047},
	{32, 000, 000, 000, 001, 001, 005, 001, 001, 003, 003, 000, 001, 001, 022, 001, 001, 001, 035, 001, 001, 001, 044, 001, 001, 001, 053, 001, 001, 001, 057, 001, 001},
	{2, 075, 002},
	{2, 001, 003},
	{2, 001, 074},
	{2, 001, 001},
	{16, 123, 123, 125, 125, 036, 036, 016, 016, 018, 018, 046, 046, 061, 061, 075, 075},
	{16, 001, 003, 001, 005, 001, 016, 001, 022, 001, 035, 001, 044, 001, 053, 001, 057},
	{2, 056, 056},
	{2, 026, 026},
	{16, 084, 015, 084, 058, 084, 031, 032, 074, 043, 031, 001, 031, 077, 031, 032, 074},
	{16, 084, 063, 091, 063, 102, 065, 105, 072, 110, 093, 121, 093, 012, 095, 023, 001},
	{16, 058, 001, 002, 001, 063, 001, 018, 001, 032, 001, 045, 001, 013, 001, 034, 001},
	{16, 091, 001, 101, 001, 109, 001, 113, 001, 004, 001, 025, 001, 030, 001, 036, 001},
	{16, 026, 026, 028, 028, 044, 044, 051, 051, 057, 057, 072, 072, 106, 106, 112, 112},
	{16, 001, 003, 001, 009, 001, 018, 001, 030, 017, 023, 046, 023, 046, 032, 057, 034},
	{16, 036, 001, 037, 001, 043, 001, 053, 001, 061, 001, 075, 001, 079, 001, 088, 001},
	{16, 012, 012, 013, 013, 014, 014, 001, 002, 002, 001, 001, 003, 003, 001, 010, 010},
	{16, 079, 079, 084, 084, 007, 007, 011, 011, 019, 019, 022, 022, 036, 036, 053, 053},
	{2, 014, 075},
	{2, 014, 075},
	{16, 067, 076, 068, 076, 078, 076, 002, 076, 016, 076, 018, 076, 025, 076, 045, 088},
	{16, 051, 001, 058, 008, 060, 001, 068, 008, 002, 001, 013, 008, 022, 001, 036, 008},
	{8, 006, 006, 046, 046, 053, 053, 003, 003},
	{0, 000, 000},
	{2, 043, 000},
	{16, 120, 117, 103, 111, 120, 114, 074, 091, 120, 112, 074, 083, 120, 113, 066, 071},
	{4, 056, 015, 056, 053},
	{4, 056, 015, 056, 053},
	{16, 097, 001, 081, 001, 105, 001, 110, 001, 091, 001, 074, 001, 084, 001, 083, 001},
	{16, 002, 039, 009, 039, 017, 001, 021, 001, 033, 000, 037, 000, 041, 029, 056, 029},
	{16, 006, 007, 007, 006, 001, 006, 089, 091, 119, 117, 103, 102, 077, 087, 071, 077},
	{16, 092, 001, 094, 001, 101, 001, 121, 001, 000, 001, 022, 001, 036, 001, 075, 001},
	{16, 072, 001, 066, 001, 059, 001, 045, 001, 040, 001, 039, 001, 035, 001, 020, 001},
	{16, 027, 036, 059, 036, 060, 035, 055, 041, 054, 031, 049, 023, 045, 032, 040, 029},
	{14, 073, 045, 012, 012, 002, 002, 006, 006, 004, 004, 046, 046, 053, 053},
	{16, 001, 001, 003, 003, 006, 006, 046, 046, 065, 009, 014, 001, 012, 009, 026, 001},
	{16, 041, 041, 048, 048, 052, 052, 064, 064, 071, 071, 085, 085, 010, 010, 062, 062},
	{32, 001, 031, 001, 000, 001, 031, 001, 000, 001, 020, 003, 000, 001, 005, 000, 000, 000, 006, 003, 000, 003, 006, 003, 000, 016, 000, 008, 000, 017, 000, 120, 000},
	{8, 012, 035, 050, 032, 040, 026, 066, 036},
	{14, 001, 073, 001, 074, 001, 075, 001, 076, 001, 077, 001, 078, 001, 079},
	{2, 001, 001},
	{16, 026, 014, 029, 042, 026, 057, 054, 029, 026, 003, 003, 029, 012, 039, 074, 035},
	{4, 002, 026, 002, 029},
	{12, 013, 118, 014, 123, 120, 123, 112, 120, 084, 110, 076, 102},
	{2, 000, 000},
	{12, 040, 065, 071, 072, 052, 066, 064, 072, 030, 072, 060, 072},
	{16, 030, 026, 077, 026, 081, 027, 024, 055, 028, 056, 049, 059, 052, 069, 071, 107},
	{2, 036, 013},
	{16, 007, 094, 036, 088, 051, 075, 053, 075, 058, 067, 075, 067, 075, 061, 079, 062},
	{16, 123, 124, 119, 122, 118, 117, 116, 115, 114, 108, 101, 106, 088, 099, 005, 006},
	{16, 074, 072, 066, 072, 053, 056, 037, 019, 022, 022, 020, 020, 009, 014, 000, 000},
	{2, 000, 001},
	{16, 011, 123, 013, 120, 020, 117, 024, 112, 027, 107, 036, 105, 037, 107, 043, 093},
	{16, 109, 025, 109, 032, 112, 032, 010, 032, 030, 044, 032, 052, 084, 066, 084, 069},
	{16, 075, 084, 040, 084, 040, 110, 028, 119, 025, 119, 021, 119, 013, 119, 004, 119},
	{2, 014, 075},
	{16, 083, 066, 087, 074, 087, 075, 098, 083, 101, 100, 103, 101, 117, 116, 123, 036},
	{16, 036, 117, 036, 013, 042, 030, 042, 033, 054, 036, 075, 079, 092, 101, 098, 109},
	{16, 051, 039, 057, 038, 045, 029, 034, 009, 065, 009, 014, 001, 012, 009, 026, 001},
	{12, 013, 118, 014, 123, 120, 123, 112, 120, 084, 110, 076, 102},
	{10, 003, 003, 006, 006, 007, 007, 052, 052, 076, 076},
	{16, 037, 037, 042, 042, 053, 053, 062, 062, 007, 007, 010, 010, 011, 011, 015, 015},
	{2, 001, 001},
	{16, 007, 001, 074, 001, 061, 001, 016, 001, 025, 001, 030, 001, 036, 001, 053, 001},
	{16, 043, 043, 046, 046, 039, 039, 028, 028, 016, 016, 006, 006, 005, 005, 002, 002},
	{16, 003, 090, 004, 090, 007, 068, 008, 066, 012, 060, 027, 097, 034, 051, 037, 051},
	{16, 017, 039, 015, 123, 032, 112, 045, 088, 052, 071, 057, 067, 061, 096, 096, 096},
	{16, 038, 051, 021, 036, 021, 034, 030, 034, 054, 034, 055, 020, 048, 018, 051, 006},
	{16, 010, 001, 025, 001, 028, 001, 036, 001, 040, 001, 054, 001, 075, 001, 113, 001},
	{16, 013, 076, 024, 077, 063, 078, 042, 076, 054, 077, 039, 078, 011, 076, 062, 077},
	{16, 116, 001, 119, 001, 122, 001, 004, 001, 009, 001, 024, 001, 027, 001, 036, 001},
	{16, 037, 036, 036, 036, 040, 036, 043, 041, 047, 041, 051, 072, 054, 075, 055, 084},
	{16, 002, 039, 009, 039, 017, 001, 021, 001, 033, 000, 037, 000, 041, 029, 056, 029},
	{2, 001, 001},
	{0, 000, 000},
	{16, 074, 074, 075, 013, 087, 118, 092, 003, 115, 118, 025, 118, 036, 000, 118, 118},
	{16, 003, 003, 003, 008, 006, 025, 007, 079, 008, 082, 036, 105, 039, 106, 051, 118},
	{0, 000, 000},
	{32, 060, 024, 023, 000, 061, 027, 123, 000, 065, 031, 031, 000, 061, 061, 030, 000, 081, 035, 023, 000, 062, 061, 062, 000, 083, 066, 064, 000, 083, 064, 064, 000},
	{14, 001, 001, 017, 020, 018, 020, 022, 030, 036, 043, 044, 051, 052, 054},
	{16, 002, 039, 009, 039, 017, 001, 021, 001, 033, 000, 037, 000, 041, 029, 056, 029},
	{16, 052, 001, 053, 001, 066, 001, 075, 001, 076, 001, 081, 001, 095, 001, 109, 001},
	{0, 000, 000},
	{16, 037, 037, 042, 042, 053, 053, 062, 062, 007, 007, 010, 010, 011, 011, 015, 015},
	{16, 110, 001, 111, 001, 112, 001, 114, 001, 119, 001, 122, 001, 004, 001, 013, 001},
	{12, 002, 035, 036, 002, 051, 053, 091, 002, 011, 022, 040, 035},
	{0, 000, 000},
	{16, 073, 001, 074, 001, 075, 001, 077, 001, 079, 001, 083, 001, 084, 001, 091, 001},
	{16, 037, 037, 042, 042, 053, 053, 062, 062, 007, 007, 010, 010, 011, 011, 015, 015},
	{16, 003, 001, 028, 001, 031, 001, 055, 001, 066, 001, 097, 001, 123, 001, 118, 001},
	{16, 009, 001, 012, 001, 026, 096, 030, 096, 032, 001, 037, 001, 057, 096, 071, 096},
	{2, 001, 001},
	{2, 001, 001},
	{14, 096, 067, 086, 070, 079, 074, 070, 086, 061, 098, 075, 075, 075, 091},
	{16, 037, 037, 042, 042, 053, 053, 062, 062, 007, 007, 010, 010, 011, 011, 015, 015},
	{16, 051, 001, 058, 008, 060, 001, 068, 008, 002, 001, 013, 008, 022, 001, 036, 008},
	{16, 013, 118, 024, 118, 031, 093, 032, 092, 045, 092, 113, 092, 119, 113, 122, 113},
	{16, 076, 008, 032, 008, 043, 008, 067, 008, 011, 011, 008, 090, 002, 002, 083, 013},
	{2, 003, 001},
	{16, 050, 001, 047, 001, 044, 096, 040, 096, 039, 001, 030, 001, 028, 096, 009, 096},
	{16, 062, 037, 078, 038, 002, 062, 003, 087, 002, 078, 113, 078, 119, 062, 007, 078},
	{16, 122, 001, 123, 001, 125, 001, 010, 001, 024, 001, 037, 001, 055, 001, 066, 001},
	{2, 001, 001},
	{16, 074, 039, 072, 039, 075, 039, 079, 039, 083, 036, 084, 036, 089, 035, 091, 035},
	{16, 037, 037, 042, 042, 053, 053, 062, 062, 007, 007, 010, 010, 011, 011, 015, 015},
	{16, 067, 001, 072, 001, 075, 001, 083, 001, 091, 001, 101, 001, 109, 001, 020, 001},
	{6, 056, 056, 049, 049, 026, 124},
	{16, 038, 009, 055, 023, 061, 074, 071, 087, 091, 087, 098, 114, 102, 119, 111, 003},
	{16, 053, 032, 015, 032, 045, 032, 034, 030, 065, 032, 014, 032, 012, 032, 043, 032},
	{16, 051, 001, 058, 001, 060, 001, 068, 001, 002, 001, 013, 001, 022, 001, 036, 001},
	{2, 001, 001},
	{2, 001, 001},
	{16, 112, 001, 116, 001, 117, 001, 024, 001, 030, 001, 035, 001, 036, 001, 040, 001},
	{16, 051, 001, 058, 008, 060, 001, 068, 008, 002, 001, 013, 008, 022, 001, 036, 008},
	{16, 052, 039, 009, 039, 017, 001, 021, 001, 033, 000, 037, 000, 041, 029, 056, 029},
	{16, 057, 008, 008, 017, 043, 021, 054, 038, 067, 008, 037, 078, 065, 079, 025, 078},
	{16, 036, 001, 035, 001, 017, 001, 011, 001, 116, 001, 113, 001, 101, 001, 092, 001},
	{2, 001, 006},
	{0, 000, 000},
	{16, 037, 037, 042, 042, 053, 053, 062, 062, 007, 007, 010, 010, 011, 011, 015, 015},
	{16, 109, 001, 030, 008, 095, 001, 084, 008, 083, 001, 072, 008, 071, 001, 052, 008},
	{16, 097, 096, 088, 064, 090, 096, 093, 064, 097, 096, 099, 081, 102, 114, 114, 001},
	{16, 002, 039, 009, 039, 017, 001, 021, 001, 033, 000, 037, 000, 041, 029, 056, 029},
	{0, 000, 000},
	{2, 001, 001},
	{12, 002, 035, 036, 002, 051, 053, 091, 002, 011, 022, 040, 035},
	{16, 094, 001, 101, 001, 116, 001, 117, 001, 004, 001, 025, 001, 030, 001, 037, 001},
	{16, 091, 038, 115, 043, 085, 006, 079, 007, 078, 008, 077, 018, 079, 018, 086, 024},
	{2, 026, 026},
	{16, 012, 001, 019, 096, 031, 064, 025, 096, 038, 001, 051, 096, 057, 001, 066, 096},
	{16, 067, 001, 068, 096, 072, 001, 074, 008, 075, 096, 076, 008, 079, 001, 084, 096},
	{12, 001, 003, 008, 007, 008, 010, 008, 016, 023, 031, 040, 044},
	{2, 001, 001},
	{16, 037, 037, 042, 042, 053, 053, 062, 062, 007, 007, 010, 010, 011, 011, 015, 015},
	{18, 092, 092, 081, 081, 067, 067, 066, 066, 061, 061, 053, 053, 051, 051, 047, 047, 043, 043},
	{16, 054, 001, 058, 001, 066, 001, 072, 001, 075, 001, 087, 001, 101, 001, 036, 001},
	{16, 041, 010, 041, 020, 049, 011, 056, 123, 110, 113, 112, 116, 114, 118, 119, 101},
	{2, 001, 001},
	{2, 001, 001},
	{16, 037, 037, 042, 042, 053, 053, 062, 062, 007, 007, 010, 010, 011, 011, 015, 015},
	{16, 119, 001, 122, 001, 008, 001, 010, 001, 013, 001, 025, 001, 027, 001, 032, 001},
	{16, 036, 001, 040, 001, 043, 001, 053, 001, 072, 001, 075, 001, 095, 001, 101, 001},
	{2, 001, 001},
	{16, 037, 037, 031, 031, 023, 023, 022, 022, 007, 007, 124, 124, 114, 114, 112, 112},
	{0, 000, 000},
	{2, 001, 001},
	{2, 001, 001},
	{16, 051, 001, 058, 008, 060, 001, 068, 008, 002, 001, 013, 008, 022, 001, 036, 008},
	{0, 000, 000},
	{2, 112, 020},
	{2, 000, 001},
	{2, 000, 001},
	{2, 000, 001},
	{2, 000, 001},
	{16, 081, 008, 032, 008, 043, 008, 067, 008, 011, 011, 008, 090, 002, 002, 083, 013},
	{2, 001, 001},
	{16, 058, 001, 069, 001, 075, 077, 018, 001, 032, 001, 045, 045, 013, 001, 034, 001},
	{16, 058, 001, 069, 001, 075, 077, 018, 001, 032, 001, 045, 045, 013, 001, 034, 001},
	{16, 067, 076, 068, 076, 078, 076, 002, 076, 016, 076, 018, 076, 025, 076, 045, 088},
	{16, 061, 008, 032, 008, 043, 008, 067, 008, 011, 011, 008, 090, 002, 002, 083, 013},
	{0, 000, 000},
	{0, 000, 000},
	{2, 001, 001},
	{2, 036, 036},
	{0, 000, 000},
	{0, 000, 000}
};

new const VehicleName[MAX_VEHICLE_MODELS][] = {
	"Landstalker", "Bravura", "Buffalo", "Linerunner", "Perrenial", "Sentinel", "Dumper", "Firetruck", "Trashmaster", "Stretch",
	"Manana", "Infernus", "Voodoo", "Pony", "Mule", "Cheetah", "Ambulance", "Leviathan", "Moonbeam", "Esperanto", "Taxi", 
	"Washington", "Bobcat", "Mr Whoopee", "BF Injection", "Hunter", "Premier", "Enforcer", "Securicar", "Banshee", "Predator",
	"Bus", "Rhino", "Barracks", "Hotknife", "Trailer 1", "Previon", "Coach", "Cabbie", "Stallion", "Rumpo", "RC Bandit", "Romero",
	"Packer", "Monster", "Admiral", "Squalo", "Seasparrow", "Pizzaboy", "Tram", "Trailer 2", "Turismo", "Speeder", "Reefer", "Tropic",
	"Flatbed", "Yankee", "Caddy", "Solair", "Berkley's RC Van", "Skimmer", "PCJ-600", "Faggio", "Freeway", "RC Baron", "RC Raider",
	"Glendale", "Oceanic", "Sanchez", "Sparrow", "Patriot", "Quad", "Coastguard", "Dinghy", "Hermes", "Sabre", "Rustler", "ZR-350",
	"Walton", "Regina", "Comet", "BMX", "Burrito", "Camper", "Marquis", "Baggage", "Dozer", "Maverick", "News Chopper", "Rancher",
	"FBI Rancher", "Virgo", "Greenwood", "Jetmax", "Hotring", "Sandking", "Blista Compact", "Police Maverick", "Boxville", "Benson",
	"Mesa", "RC Goblin", "Hotring Racer A", "Hotring Racer B", "Bloodring Banger", "Rancher", "Super GT", "Elegant", "Journey",
	"Bike", "Mountain Bike", "Beagle", "Cropdust", "Stunt", "Tanker", "Roadtrain", "Nebula", "Majestic", "Buccaneer", "Shamal",
	"Hydra", "FCR-900", "NRG-500", "HPV1000", "Cement Truck", "Tow Truck", "Fortune", "Cadrona", "FBI Truck", "Willard", "Forklift",
	"Tractor", "Combine", "Feltzer", "Remington", "Slamvan", "Blade", "Freight", "Streak", "Vortex", "Vincent", "Bullet", "Clover",
	"Sadler", "Firetruck LA", "Hustler", "Intruder", "Primo", "Cargobob", "Tampa", "Sunrise", "Merit", "Utility", "Nevada", "Yosemite",
	"Windsor", "Monster A", "Monster B", "Uranus", "Jester", "Sultan", "Stratum", "Elegy", "Raindance", "RC Tiger", "Flash", "Tahoma",
	"Savanna", "Bandito", "Freight Flat", "Streak Carriage", "Kart", "Mower", "Duneride", "Sweeper", "Broadway", "Tornado", "AT-400",
	"DFT-30", "Huntley", "Stafford", "BF-400", "Newsvan", "Tug", "Trailer 3", "Emperor", "Wayfarer", "Euros", "Hotdog", "Club",
	"Freight Carriage", "Trailer 3", "Andromada", "Dodo", "RC Cam", "Launch", "Police Car (LSPD)", "Police Car (SFPD)",
	"Police Car (LVPD)", "Police Ranger", "Picador", "S.W.A.T. Tank", "Alpha", "Phoenix", "Glendale", "Sadler", "Luggage Trailer A",
	"Luggage Trailer B", "Stair Trailer", "Boxville", "Farm Plow", "Utility Trailer"
};

new Float:VehicleMass[MAX_VEHICLE_MODELS] = {
	1700.0,
	1300.0,
	1500.0,
	3800.0,
	1200.0,
	1600.0,
	20000.0,
	6500.0,
	5500.0,
	2200.0,
	1000.0,
	1400.0,
	1800.0,
	2600.0,
	3500.0,
	1200.0,
	2600.0,
	15000.0,
	2000.0,
	1800.0,
	1450.0,
	1850.0,
	1700.0,
	1700.0,
	1200.0,
	10000.0,
	1600.0,
	4000.0,
	7000.0,
	1400.0,
	2200.0,
	5500.0,
	25000.0,
	10500.0,
	1400.0,
	3800.0,
	1400.0,
	9500.0,
	1750.0,
	1600.0,
	2000.0,
	100.0,
	2500.0,
	8000.0,
	5000.0,
	1650.0,
	2200.0,
	3000.0,
	350.0,
	1900.0,
	3800.0,
	1400.0,
	2200.0,
	5000.0,
	2200.0,
	8500.0,
	4500.0,
	1000.0,
	2000.0,
	1900.0,
	5000.0,
	500.0,
	350.0,
	800.0,
	100.0,
	100.0,
	1600.0,
	1900.0,
	500.0,
	2500.0,
	2500.0,
	400.0,
	1200.0,
	800.0,
	1950.0,
	1700.0,
	5000.0,
	1400.0,
	1850.0,
	1500.0,
	1400.0,
	100.0,
	1900.0,
	1900.0,
	5000.0,
	1000.0,
	10000.0,
	5000.0,
	3500.0,
	2500.0,
	3500.0,
	1700.0,
	1600.0,
	3000.0,
	1600.0,
	2000.0,
	1000.0,
	4500.0,
	5500.0,
	3500.0,
	1300.0,
	100.0,
	1600.0,
	1600.0,
	2100.0,
	2500.0,
	1400.0,
	2200.0,
	3500.0,
	100.0,
	100.0,
	10000.0,
	5000.0,
	5000.0,
	3800.0,
	5000.0,
	1400.0,
	1400.0,
	1700.0,
	15000.0,
	9000.0,
	500.0,
	400.0,
	500.0,
	5500.0,
	3500.0,
	1700.0,
	1200.0,
	4000.0,
	1800.0,
	1000.0,
	2000.0,
	8500.0,
	1600.0,
	1800.0,
	1950.0,
	1500.0,
	5500.0,
	5500.0,
	1900.0,
	1800.0,
	1200.0,
	1600.0,
	1700.0,
	6500.0,
	1700.0,
	1800.0,
	1600.0,
	20000.0,
	1700.0,
	1600.0,
	1800.0,
	2600.0,
	25000.0,
	3000.0,
	1500.0,
	5000.0,
	5000.0,
	1400.0,
	1500.0,
	1400.0,
	1800.0,
	1500.0,
	10000.0,
	100.0,
	1400.0,
	1800.0,
	1500.0,
	1000.0,
	5500.0,
	5500.0,
	300.0,
	800.0,
	10000.0,
	800.0,
	1700.0,
	1700.0,
	60000.0,
	5500.0,
	2500.0,
	2200.0,
	500.0,
	1900.0,
	800.0,
	3800.0,
	1800.0,
	800.0,
	1400.0,
	5500.0,
	1400.0,
	5500.0,
	3800.0,
	40000.0,
	5000.0,
	100.0,
	2200.0,
	1600.0,
	1600.0,
	1600.0,
	2500.0,
	1600.0,
	5000.0,
	1500.0,
	1500.0,
	1600.0,
	1700.0,
	1000.0,
	1000.0,
	1000.0,
	5500.0,
	400.0,
	1000.0
};

new VehiclePrice[MAX_VEHICLE_MODELS] = {
	160000, // Landstalker
	130000, // Bravura
	450000, // Buffalo
	170000, // Linerunner
	140000, // Perrenial
	150000, // Sentinel
	0, // Dumper
	0, // Firetruck
	0, // Trashmaster
	0, // Stretch
	130000, // Manana
	1700000, // Infernus
	200000, // Voodoo
	160000, // Pony
	150000, // Mule
	600000, // Cheetah
	0, // Ambulance
	0, // Leviathan
	140000, // Moonbeam
	140000, // Esperanto
	120000, // Taxi
	200000, // Washington
	140000, // Bobcat
	0, // Mr Whoopee
	300000, // BF Injection
	0, // Hunter
	300000, // Premier
	0, // Enforcer
	0, // Securicar
	600000, // Banshee
	0, // Predator
	0, // Bus
	0, // Rhino
	0, // Barracks
	0, // Hotknife
	0, // Trailer 1
	210000, // Previon
	0, // Coach
	120000, // Cabbie
	250000, // Stallion
	160000, // Rumpo
	0, // RC Bandit
	160000, // Romero
	0, // Packer
	0, // Monster
	240000, // Admiral
	300000, // Squalo
	0, // Seasparrow
	0, // Pizzaboy
	0, // Tram
	0, // Trailer 2
	1700000, // Turismo
	250000, // Speeder
	150000, // Reefer
	350000, // Tropic
	150000, // Flatbed
	150000, // Yankee
	0, // Caddy
	230000, // Solair
	180000, // Berkley's RC Van
	0, // Skimmer
	110000, // PCJ-600
	95000, // Faggio
	160000, // Freeway
	0, // RC Baron
	0, // RC Raider
	230000, // Glendale
	230000, // Oceanic
	160000, // Sanchez
	0, // Sparrow
	260000, // Patriot
	140000, // Quad
	0, // Coastguard
	120000, // Dinghy
	240000, // Hermes
	190000, // Sabre
	0, // Rustler
	650000, // ZR-350
	150000, // Walton
	220000, // Regina
	570000, // Comet
	20000, // BMX
	240000, // Burrito
	240000, // Camper
	320000, // Marquis
	0, // Baggage
	0, // Dozer
	1000000, // Maverick
	0, // News Chopper
	300000, // Rancher
	0, // FBI Rancher
	280000, // Virgo
	300000, // Greenwood
	340000, // Jetmax
	1500000, // Hotring
	1300000, // Sandking
	220000, // Blista Compact
	0, // Police Maverick
	150000, // Boxville
	150000, // Benson
	1200000, // Mesa
	0, // RC Goblin
	1500000, // Hotring Racer A
	1500000, // Hotring Racer B
	0, // Bloodring Banger
	320000, // Rancher
	700000, // Super GT
	300000, // Elegant
	240000, // Journey
	15000, // Bike
	30000, // Mountain Bike
	0, // Beagle
	0, // Cropdust
	0, // Stunt
	200000, // Tanker
	400000, // Roadtrain
	300000, // Nebula
	250000, // Majestic
	250000, // Buccaneer
	0, // Shamal
	0, // Hydra
	180000, // FCR-900
	2000000, // NRG-500
	0, // HPV1000
	0, // Cement Truck
	100000, // Tow Truck
	130000, // Fortune
	140000, // Cadrona
	0, // FBI Truck
	140000, // Willard
	0, // Forklift
	0, // Tractor
	0, // Combine
	230000, // Feltzer
	230000, // Remington
	400000, // Slamvan
	240000, // Blade
	0, // Freight
	0, // Streak
	0, // Vortex
	260000, // Vincent
	1500000, // Bullet
	230000, // Clover
	160000, // Sadler
	0, // Firetruck LA
	1350000, // Hustler
	220000, // Intruder
	220000, // Primo
	0, // Cargobob
	180000, // Tampa
	240000, // Sunrise
	220000, // Merit
	0, // Utility
	0, // Nevada
	250000, // Yosemite
	280000, // Windsor
	0, // Monster A
	0, // Monster B
	480000, // Uranus
	490000, // Jester
	500000, // Sultan
	470000, // Stratum
	500000, // Elegy
	0, // Raindance
	0, // RC Tiger
	490000, // Flash
	300000, // Tahoma
	310000, // Savanna
	0, // Bandito
	0, // Freight Flat
	0, // Streak Carriage
	0, // Kart
	0, // Mower
	1500000, // Duneride
	0, // Sweeper
	240000, // Broadway
	240000, // Tornado
	0, // AT-400
	0, // DFT-30
	400000, // Huntley
	440000, // Stafford
	160000, // BF-400
	0, // Newsvan
	0, // Tug
	0, // Trailer 3
	200000, // Emperor
	150000, // Wayfarer
	330000, // Euros
	0, // Hotdog
	410000, // Club
	0, // Freight Carriage
	0, // Trailer 3
	0, // Andromada
	0, // Dodo
	0, // RC Cam
	0, // Launch
	0, // Police Car (LSPD)
	0, // Police Car (SFPD)
	0, // Police Car (LVPD)
	0, // Police Ranger
	220000, // Picador
	0, // S.W.A.T. Tank
	270000, // Alpha
	380000, // Phoenix
	0, // Glendale
	0, // Sadler
	0, // Luggage Trailer A
	0, // Luggage Trailer B
	0, // Stair Trailer
	150000, // Boxville
	0, // Farm Plow
	0 // Utility Trailer
};

#define IsValidVehicleModelID(%0)				(400 <= (%0) <= 611)
#define GetVehicleModelName(%0)					VehicleName[((%0)-400)]
#define GetVehicleName(%0)						GetVehicleModelName(GetVehicleModel(%0))
#define GetVehicleModelPrice(%0)				VehiclePrice[((%0) - 400)]
#define GetVehiclePrice(%0)						GetVehicleModelPrice(GetvehicleModel(%0))
#define GetVehicleMass(%0)						VehicleMass[((%0)-400)]

stock GetVehicleDriver(vehicleid)
{
	new driver = INVALID_PLAYER_ID;
    foreach(new i : Player)
	{
		if(/* IsPlayerSpawned(i) &&  */GetPlayerState(i) == PLAYER_STATE_DRIVER && IsPlayerInVehicle(i,vehicleid)) {
			driver = i;
			break;
		}
	}
	return driver;
}

stock GetVehicleRandomColors(modelid,&color1,&color2)
{
	if(!IsValidVehicleModelID(modelid)) return 0;
	new index = 0;
	
	color1 = color2 = 0;
	
	modelid -= 400;
	
	if(!CarColors[modelid][0]) return 0;
	
	if(CarColors[modelid][0] == 2){
		color1 = CarColors[modelid][1];
		color2 = CarColors[modelid][2];
	} else {
		index = random(CarColors[modelid][0]) & -2;
		color1 = CarColors[modelid][++index];
		color2 = CarColors[modelid][++index];
	}
	return 1;
}

stock Float:GetVehicleSpeed(vehicleid)
{
	new Float: vx, Float: vy, Float: vz, Float: vel;
    vel = GetVehicleVelocity(vehicleid, vx, vy, vz);
    vel = (floatsqroot(((vx*vx)+(vy*vy))+(vz*vz)) * 181.5);
    return vel;
}

stock GetVehicleParams(vehicleid,type){
	new params[MAX_VEHICLE_PARAMS];
	GetVehicleParamsEx(vehicleid,params[0],params[1],params[2],params[3],params[4],params[5],params[6]);
	return (!(params[type] <= 0));
}

stock SetVehicleParams(vehicleid,type,bool:status){
	new params[MAX_VEHICLE_PARAMS];
	if(GetVehicleParamsEx(vehicleid,params[0],params[1],params[2],params[3],params[4],params[5],params[6])){
		if(status == true) params[type] = 1;
		else params[type] = 0;
		SetVehicleParamsEx(vehicleid,params[0],params[1],params[2],params[3],params[4],params[5],params[6]);
		return 1;
	}
	return 0;
}

stock IsVehicleHasEngine(vehicleid)
{
	static const g_aEngineStatus[] = {
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
		1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0
	};
    new modelid = GetVehicleModel(vehicleid);

    if (modelid < 400 || modelid > 611)
        return 0;

    return (g_aEngineStatus[modelid - 400]);
}

stock GetVehicleOffset(vehicleid, type, &Float:x, &Float:y, &Float:z)
{
    new Float:fPos[4], Float:fSize[3];

	if (!IsValidVehicle(vehicleid))
	{
		x = 0.0;
		y = 0.0;
		z = 0.0;

		return 0;
	}
	else
	{
		GetVehiclePos(vehicleid, fPos[0], fPos[1], fPos[2]);
		GetVehicleZAngle(vehicleid, fPos[3]);
		GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_SIZE, fSize[0], fSize[1], fSize[2]);

		switch (type)
		{
		    case VEHICLE_OFFSET_BOOT:
		    {
				x = fPos[0] - (floatsqroot(fSize[1] + fSize[1]) * floatsin(-fPos[3], degrees));
				y = fPos[1] - (floatsqroot(fSize[1] + fSize[1]) * floatcos(-fPos[3], degrees));
 				z = fPos[2];
			}
			case VEHICLE_OFFSET_HOOD:
			{
			    x = fPos[0] + (floatsqroot(fSize[1] + fSize[1]) * floatsin(-fPos[3], degrees));
				y = fPos[1] + (floatsqroot(fSize[1] + fSize[1]) * floatcos(-fPos[3], degrees));
	 			z = fPos[2];
			}
			case VEHICLE_OFFSET_ROOF:
			{
			    x = fPos[0];
			    y = fPos[1];
			    z = fPos[2] + floatsqroot(fSize[2]);
			}
		}
	}
	return 1;
}

stock IsPlayerNearVehicle(playerid, vehicleid, Float:range)
{
	new Float:x, Float:y, Float:z;
	GetVehiclePos(vehicleid, x, y, z);
	if(IsPlayerInRangeOfPoint(playerid, range, x, y, z))
	{
	    return 1;
	}
	return 0;
}