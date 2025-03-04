new player_inspectveh_id[MAX_PLAYERS],
    bool:player_hasinspectveh[MAX_PLAYERS];

new player_mechmenu_componentneed[MAX_PLAYERS];
enum /* Mech Menu Type */
{
    MECHMENU_MENUS,
    MECHMENU_REPAIR,
    MECHMENU_COLOR,
    MECHMENU_UPGRADE
}

new PlayerText:mechmenu_box[MAX_PLAYERS];
new PlayerText:mechmenu_header_box[MAX_PLAYERS];
new PlayerText:mechmenu_vehinfo[MAX_PLAYERS];
new PlayerText:mechmenu_header_icon[MAX_PLAYERS];
new PlayerText:mechmenu_close[MAX_PLAYERS];
new PlayerText:mechamenu_back[MAX_PLAYERS];
new PlayerText:mechmenu_header_name[MAX_PLAYERS];

new PlayerText:mechmenu_upgrade_btn[MAX_PLAYERS];
new PlayerText:mechmenu_color_btn[MAX_PLAYERS];
new PlayerText:mechmenu_repair_btn[MAX_PLAYERS];

new PlayerText:mechmenu_repair_info[MAX_PLAYERS];
new PlayerText:mechmenu_repair_component[MAX_PLAYERS];
new PlayerText:mechmenu_repair_info2[MAX_PLAYERS];
new PlayerText:mechmenu_repair_install[MAX_PLAYERS];

new PlayerText:mechmenu_color_google[MAX_PLAYERS];
new PlayerText:mechmenu_color_component[MAX_PLAYERS];
new PlayerText:mechmenu_color_component2[MAX_PLAYERS];
new PlayerText:mechmenu_color_change[MAX_PLAYERS];
new PlayerText:mechmenu_color_componeed[MAX_PLAYERS];
new PlayerText:mechmenu_color_info[MAX_PLAYERS];

new PlayerText:mechmenu_upgrade_info[MAX_PLAYERS];
new PlayerText:mechmenu_upgrade_component2[MAX_PLAYERS];
new PlayerText:mechmenu_upgrade_install[MAX_PLAYERS];
new PlayerText:mechmenu_upgrade_next[MAX_PLAYERS];
new PlayerText:mechmenu_upgrade_component1[MAX_PLAYERS];
new PlayerText:mechmenu_upgrade_component3[MAX_PLAYERS];