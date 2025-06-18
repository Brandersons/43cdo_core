class 43cdo_units_soldier_12c : 43cdo_units_soldier_base
{
    scope = 2;
    scopeCurator = 2;
    side = 1;
    displayName = "1-2 Charlie";
    editorSubcategory = "43cdo_faction_edsubcat_playersqm";
    author = "Cpl. N. Monarch";
    threat[] = {1, 0.1, 0.1};

    attendant = 1;
    engineer = 0;

    uniform = "SCM_PCU_NH_uniform";
    backpack = "SCM_Trizip";
    weapons[] =
    {
        "43cdo_weapons_l129a2_recce",
        "rhsusf_weap_glock17g4",
        "Put",
        "Throw",
        "Rangefinder"
    };
    respawnWeapons[] =
    {
        "43cdo_weapons_l129a2_recce",
        "rhsusf_weap_glock17g4",
        "Put",
        "Throw",
        "Rangefinder"
    };
    linkedItems[] =
    {
        "SCM_Virtus_Support_1",
        "SCM_Fast_B_2",
        "ItemMap",
        "ItemCompass",
        "KAT_Katmin",
        "TFAR_anprc152"
    };
    respawnLinkedItems[] =
    {
        "SCM_Virtus_Support_1",
        "SCM_Fast_B_2",
        "ItemMap",
        "ItemCompass",
        "KAT_Katmin",
        "TFAR_anprc152"
    };

    class loadoutitems
    {
        loadedmagazineprimary[] = {"UKSF_65Creedmoor_Base_SMK"};
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
            "ACE_CableTie", "ACE_CableTie", "ACE_CableTie", "ACE_CableTie",
            "ACE_Tourniquet", "ACE_Tourniquet", "ACE_Tourniquet", "ACE_Tourniquet",
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
            "UK3CB_BAF_SmokeShellPurple",
            "UK3CB_BAF_SmokeShellGreen",
            "UK3CB_BAF_SmokeShellRed",
            "UK3CB_BAF_SmokeShellBlue",
            "rhs_mag_m67", "rhs_mag_m67", "rhs_mag_m67",
            "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell",
            "UKSF_65Creedmoor_Base_SMK", "UKSF_65Creedmoor_Base_SMK", "UKSF_65Creedmoor_Base_SMK", "UKSF_65Creedmoor_Base_SMK", "UKSF_65Creedmoor_Base_SMK",
            "UKSF_65Creedmoor_Base_SMK_IR", "UKSF_65Creedmoor_Base_SMK_IR",
            "UKSF_65Creedmoor_Base_SMK_Tracer", "UKSF_65Creedmoor_Base_SMK_Tracer",
            "tsp_flashbang_cts2", "tsp_flashbang_cts2", "tsp_flashbang_cts2", "tsp_flashbang_cts2", "tsp_flashbang_cts2", "tsp_flashbang_cts2",
            "UK3CB_BAF_9_17Rnd", "UK3CB_BAF_9_17Rnd", "UK3CB_BAF_9_17Rnd"
        };
        itemsbackpack[] =
        {
            "ACE_EntrenchingTool",
            "kat_accuvac",
            "ACE_Canteen",
            "ACE_surgicalKit",
            "SCM_Eleanor",
            "ACE_EHP",
            "SCM_PVS31_W_MC_WP",
            "H_Booniehat_khk_hs",
            "kat_TXA",
            "kat_X_AED",
            "ACE_Tripod",
            "ACE_MRE_BeefStew", "ACE_MRE_BeefStew",
            "kat_chestSeal", "kat_chestSeal", "kat_chestSeal", "kat_chestSeal",
            "ACE_salineIV", "ACE_salineIV", "ACE_salineIV", "ACE_salineIV",
            "ACE_salineIV_500", "ACE_salineIV_500", "ACE_salineIV_500", "ACE_salineIV_500",
            "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage",
            "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
            "ACE_quikclot", "ACE_quikclot", "ACE_quikclot", "ACE_quikclot", "ACE_quikclot""ACE_quikclot", "ACE_quikclot", "ACE_quikclot"
        };
    };
};