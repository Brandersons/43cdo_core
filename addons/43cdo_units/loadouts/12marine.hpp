class 43cdo_units_soldier_12marine : 43cdo_units_soldier_base
{
    scope = 2;
    scopeCurator = 2;
    side = 1;
    displayName = "1-2 Marine";
    editorSubcategory = "43cdo_faction_edsubcat_playersqm";
    author = "Cpl. N. Monarch";
    threat[] = {1, 0.1, 0.1};

    attendant = 0;
    engineer = 0;

    uniform = "SCM_G4_RS_Undershirt_uniform";
    backpack = "SCM_Trizip";
    weapons[] =
    {
        "43cdo_weapons_l403a1_recce_marine",
        "rhs_weap_M320",
        "Put",
        "Throw",
        "Rangefinder"
    };
    respawnWeapons[] =
    {
        "43cdo_weapons_l403a1_recce_marine",
        "rhs_weap_M320",
        "Put",
        "Throw",
        "Rangefinder"
    };
    linkedItems[] =
    {
        "SCM_Virtus_Assaulter_1",
        "SCM_Fast_B_2",
        "ItemMap",
        "ItemCompass",
        "KAT_Katmin",
        "TFAR_anprc152"
    };
    respawnLinkedItems[] =
    {
        "SCM_Virtus_Assaulter_1",
        "SCM_Fast_B_2",
        "ItemMap",
        "ItemCompass",
        "KAT_Katmin",
        "TFAR_anprc152"
    };

    class loadoutitems
    {
        loadedmagazineprimary[] = {"Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue"};
        loadedmagazinesecondary[] = {"UK3CB_BAF_1Rnd_HE_Grenade_Shell"};
        itemsuniform[] =
        {
            "ItemcTabHCam",
            "ItemAndroid",
            "ACE_Flashlight_XL50",
            "ACE_MapTools",
            "ACE_RangeCard",
            "ACE_painkillers",
            "kat_Caffeine",
            "kat_larynx", "kat_larynx", "kat_larynx", "kat_larynx",
            "ACE_IR_Strobe_Item", "ACE_IR_Strobe_Item",
            "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet",
            "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage",
            "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage",
            "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage",
            "ACE_CableTie", "ACE_CableTie"
        };
        itemsvest[] =
        {
            "ACE_HuntIR_monitor",
            "rhs_mag_m67", "rhs_mag_m67",
            "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell",
            "UK3CB_BAF_SmokeShellGreen", "UK3CB_BAF_SmokeShellGreen",
            "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue", "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue", "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue", "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue", "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue",
            "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue", "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue", "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue", "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue",
            "ACE_M14", "ACE_M14",
            "tsp_flashbang_cts2", "tsp_flashbang_cts2", "tsp_flashbang_cts2", "tsp_flashbang_cts2"
        };
        itemsbackpack[] =
        {
            "ACE_EntrenchingTool",
            "ACE_Canteen",
            "ACE_EHP",
            "kt_25x_PMII022_msr_ti",
            "ACE_Tripod",
            "SCM_crossbow_tan_tinted",
            "SCM_PVS31_W_MC_WP",
            "UK3CB_BAF_H_Beret_RM_Bootneck",
            "ItemcTab",
            "ACE_MRE_BeefStew", "ACE_MRE_BeefStew",
            "ACE_salineIV_250", "ACE_salineIV_250", "ACE_salineIV_250", "ACE_salineIV_250",
            "UK3CB_BAF_1Rnd_HE_Grenade_Shell", "UK3CB_BAF_1Rnd_HE_Grenade_Shell", "UK3CB_BAF_1Rnd_HE_Grenade_Shell", "UK3CB_BAF_1Rnd_HE_Grenade_Shell", "UK3CB_BAF_1Rnd_HE_Grenade_Shell",
            "UK3CB_BAF_1Rnd_HEDP_Grenade_Shell", "UK3CB_BAF_1Rnd_HEDP_Grenade_Shell", "UK3CB_BAF_1Rnd_HEDP_Grenade_Shell", "UK3CB_BAF_1Rnd_HEDP_Grenade_Shell", "UK3CB_BAF_1Rnd_HEDP_Grenade_Shell",
            "UK3CB_BAF_UGL_FlareCIR_F", "UK3CB_BAF_UGL_FlareCIR_F", "UK3CB_BAF_UGL_FlareCIR_F", "UK3CB_BAF_UGL_FlareCIR_F",
            "UK3CB_BAF_1Rnd_SmokeRed_Grenade_shell", "UK3CB_BAF_1Rnd_SmokeRed_Grenade_shell",
            "ACE_HuntIR_M203", "ACE_HuntIR_M203",
            "UK3CB_BAF_1Rnd_SmokeGreen_Grenade_shell", "UK3CB_BAF_1Rnd_SmokeGreen_Grenade_shell",
            "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_IR", "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_IR", "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_IR", "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_IR"
        };
    };
};