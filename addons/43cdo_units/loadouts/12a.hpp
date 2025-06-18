class 43cdo_units_soldier_12a : 43cdo_units_soldier_base
{
    scope = 2;
    scopeCurator = 2;
    side = 1;
    displayName = "1-2 Alpha";
    editorSubcategory = "43cdo_faction_edsubcat_playersqm";
    author = "Cpl. N. Monarch";
    threat[] = {1, 0.1, 0.1};

    attendant = 1;
    engineer = 0;

    uniform = "SCM_Windliner_uniform";
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
        "UK3CB_BAF_H_Beret_RM_Officer_PRR",
        "ItemMap",
        "ItemCompass",
        "KAT_Katmin",
        "TFAR_anprc152"
    };
    respawnLinkedItems[] =
    {
        "SCM_Virtus_Support_1",
        "UK3CB_BAF_H_Beret_RM_Officer_PRR",
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
            "ACE_painkillers",
            "kat_Caffeine",
            "ItemcTab",
            "ACE_IR_Strobe_Item", "ACE_IR_Strobe_Item", "ACE_IR_Strobe_Item", "ACE_IR_Strobe_Item",
            "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet",
            "ACE_CableTie", "ACE_CableTie", "ACE_CableTie", "ACE_CableTie"
        };
        itemsvest[] =
        {
            "UK3CB_BAF_SmokeShellPurple", "UK3CB_BAF_SmokeShellPurple",
            "UK3CB_BAF_SmokeShellGreen", "UK3CB_BAF_SmokeShellGreen",
            "UK3CB_BAF_SmokeShellRed", "UK3CB_BAF_SmokeShellRed",
            "UK3CB_BAF_SmokeShellBlue", "UK3CB_BAF_SmokeShellBlue",
            "rhs_mag_m67", "rhs_mag_m67",
            "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell",
            "UKSF_65Creedmoor_Base_SMK", "UKSF_65Creedmoor_Base_SMK", "UKSF_65Creedmoor_Base_SMK", "UKSF_65Creedmoor_Base_SMK", "UKSF_65Creedmoor_Base_SMK",
            "UKSF_65Creedmoor_Base_SMK_Tracer", "UKSF_65Creedmoor_Base_SMK_Tracer", "UKSF_65Creedmoor_Base_SMK_Tracer", "UKSF_65Creedmoor_Base_SMK_Tracer",
            "UK3CB_BAF_9_17Rnd", "UK3CB_BAF_9_17Rnd"
        };
        itemsbackpack[] =
        {
            "ACE_EntrenchingTool",
            "ACE_Canteen",
            "SCM_Eleanor",
            "ACE_EHP",
            "SCM_PVS31_W_MC_WP",
            "SCOTT_Fast_Patches_B",
            "ACE_Tripod",
            "SOMETHING_really_Dumb",
            "kat_chestSeal", "kat_chestSeal", "kat_chestSeal", "kat_chestSeal",
            "ACE_MRE_BeefStew", "ACE_MRE_BeefStew",
            "kat_larynx", "kat_larynx", "kat_larynx", "kat_larynx",
            "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet",
            "kat_epinephrineIV", "kat_epinephrineIV",
            "ACE_morphine", "ACE_morphine",
            "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage",
            "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
            "ACE_quikclot", "ACE_quikclot", "ACE_quikclot", "ACE_quikclot", "ACE_quikclot", "ACE_quikclot", "ACE_quikclot", "ACE_quikclot"
        };
    };
};