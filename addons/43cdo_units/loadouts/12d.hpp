class 43cdo_units_soldier_12d : 43cdo_units_soldier_base
{
    scope = 2;
    scopeCurator = 2;
    side = 1;
    displayName = "1-2 Delta";
    editorSubcategory = "43cdo_faction_edsubcat_playersqm";
    author = "Cpl. N. Monarch";
    threat[] = {1, 0.1, 0.1};

    attendant = 1;
    engineer = 0;

    uniform = "SCM_Windliner_uniform";
    backpack = "SCM_Trizip";
    weapons[] =
    {
        "43cdo_weapons_l403a1_recce_delta",
        "rhsusf_weap_glock17g4",
        "Put",
        "Throw",
        "ACE_Vector"
    };
    respawnWeapons[] =
    {
        "43cdo_weapons_l403a1_recce_delta",
        "rhsusf_weap_glock17g4",
        "Put",
        "Throw",
        "ACE_Vector"
    };
    linkedItems[] =
    {
        "SCM_Virtus_Medic_1",
        "SCM_Fast_B_2",
        "ItemMap",
        "ItemCompass",
        "KAT_Katmin",
        "TFAR_anprc152"
    };
    respawnLinkedItems[] =
    {
        "SCM_Virtus_Medic_1",
        "SCM_Fast_B_2",
        "ItemMap",
        "ItemCompass",
        "KAT_Katmin",
        "TFAR_anprc152"
    };

    class loadoutitems
    {
        loadedmagazineprimary[] = {"Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue"};
        loadedmagazinesecondary[] = {"UK3CB_BAF_9_17Rnd"};
        itemsuniform[] =
        {
            "ItemcTabHCam",
            "ACE_Kestrel4500",
            "ACE_Flashlight_XL50",
            "ACE_MapTools",
            "ACE_RangeCard",
            "ACE_microDAGR",
            "kat_Pulseoximeter",
            "ACE_painkillers",
            "kat_Caffeine",
            "ACE_IR_Strobe_Item", "ACE_IR_Strobe_Item",
            "ACE_Tourniquet", "ACE_Tourniquet", "ACE_Tourniquet", "ACE_Tourniquet",
            "ACE_CableTie", "ACE_CableTie", "ACE_CableTie", "ACE_CableTie",
            "ACE_splint", "ACE_splint", "ACE_splint",
            "kat_larynx", "kat_larynx", "kat_larynx",
            "kat_amiodarone", "kat_amiodarone", "kat_amiodarone",
            "kat_atropine", "kat_atropine", "kat_atropine",
            "kat_epinephrineIV", "kat_epinephrineIV", "kat_epinephrineIV", "kat_epinephrineIV", "kat_epinephrineIV", "kat_epinephrineIV", "kat_epinephrineIV",
            "ACE_morphine", "ACE_morphine", "ACE_morphine", "ACE_morphine",
            "kat_naloxone", "kat_naloxone"
        };
        itemsvest[] =
        {
            "ItemAndroid",
            "rhs_mag_m67", "rhs_mag_m67", "rhs_mag_m67",
            "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell",
            "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue", "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue", "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue", "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue", "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue",
            "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue_IR", "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue_IR", "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue_IR", "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue_IR",
            "ACE_M14", "ACE_M14",
            "tsp_flashbang_cts2", "tsp_flashbang_cts2", "tsp_flashbang_cts2", "tsp_flashbang_cts2", "tsp_flashbang_cts2", "tsp_flashbang_cts2",
            "UK3CB_BAF_9_17Rnd", "UK3CB_BAF_9_17Rnd"
        };
        itemsbackpack[] =
        {
            "ACE_EntrenchingTool",
            "kat_accuvac",
            "ACE_Canteen",
            "ACE_surgicalKit",
            "kt_25x_PMII022_msr_ti",
            "ACE_EHP",
            "SCM_PVS31_W_MC_WP",
            "H_Booniehat_khk_hs",
            "UK3CB_BAF_SmokeShellPurple",
            "UK3CB_BAF_SmokeShellGreen",
            "UK3CB_BAF_SmokeShellRed",
            "UK3CB_BAF_SmokeShellBlue",
            "ItemcTab",
            "kat_TXA",
            "ACE_Tripod",
            "Row_Row_Your_Nun",
            "ACE_MRE_BeefStew", "ACE_MRE_BeefStew",
            "kat_chestSeal", "kat_chestSeal", "kat_chestSeal", "kat_chestSeal",
            "ACE_salineIV", "ACE_salineIV", "ACE_salineIV", "ACE_salineIV",
            "ACE_salineIV_500", "ACE_salineIV_500", "ACE_salineIV_500", "ACE_salineIV_500",
            "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage",
            "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
            "ACE_quikclot", "ACE_quikclot", "ACE_quikclot", "ACE_quikclot", "ACE_quikclot""ACE_quikclot", "ACE_quikclot", "ACE_quikclot",
            "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell"
        };
    };
};