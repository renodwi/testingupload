#include <YSI_Coding\y_hooks>

stock fixed_GetWeaponName(weaponid)
{
    new
        weaponName[32];

    GetWeaponName(weaponid, weaponName, sizeof(weaponName));
    return weaponName;
}

#if defined _ALS_GetWeaponName
	#undef GetWeaponName
#else
	#define _ALS_GetWeaponName
#endif
#define GetWeaponName fixed_GetWeaponName