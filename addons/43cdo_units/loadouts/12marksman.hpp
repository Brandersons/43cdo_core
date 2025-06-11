class 43cdo_units_soldier_12marksman : 43cdo_units_soldier_base
{
    scope = 2;
    scopeCurator = 2;
    side = 1;
    displayName = "1-2 Marksman";
    editorSubcategory = "43cdo_faction_edsubcat_playersqm";
    author = "Cpl. N. Monarch";
    threat[] = {1, 0.1, 0.1};

    attendant = 0;
    engineer = 0;

    uniform = "SCM_PCU_uniform";
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
        loadedmagazineprimary[] = {"UKSF_65Creedmoor_Base_SMK"};
        loadedmagazinesecondary[] = {"UK3CB_BAF_9_17Rnd"};
        itemsuniform[] =
        {
            "ItemcTabHCam",
            "ItemAndroid",
            "kat_guedel",
            "ACE_Kestrel4500",
            "ACE_Flashlight_XL50",
            "ACE_MapTools",
            "ACE_RangeCard",
            "ACE_painkillers",
            "kat_Caffeine",
            "ACE_IR_Strobe_Item", "ACE_IR_Strobe_Item",
            "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet",
            "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage",
            "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
            "ACE_quikclot", "ACE_quikclot", "ACE_quikclot", "ACE_quikclot", "ACE_quikclot", "ACE_quikclot", "ACE_quikclot", "ACE_quikclot",
            "ACE_CableTie", "ACE_CableTie"
        };
        itemsvest[] = {
            "rhs_mag_m67", "rhs_mag_m67",
            "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell",
            "UK3CB_BAF_SmokeShellGreen", "UK3CB_BAF_SmokeShellGreen",
            "UKSF_65Creedmoor_Base_SMK", "UKSF_65Creedmoor_Base_SMK", "UKSF_65Creedmoor_Base_SMK", "UKSF_65Creedmoor_Base_SMK", "UKSF_65Creedmoor_Base_SMK",
            "UKSF_65Creedmoor_Base_SMK_IR", "UKSF_65Creedmoor_Base_SMK_IR",
            "UKSF_65Creedmoor_Base_SMK_Tracer", "UKSF_65Creedmoor_Base_SMK_Tracer", "UKSF_65Creedmoor_Base_SMK_Tracer",
            "UK3CB_BAF_9_17Rnd", "UK3CB_BAF_9_17Rnd", "UK3CB_BAF_9_17Rnd"
        };
        itemsbackpack[] =
        {
            "ACE_EntrenchingTool",
            "ACE_Canteen",
            "ACE_Tripod",
            "ACE_EHP",
            "SCM_PVS31_C_WP",
            "UK3CB_BAF_H_Beret_RM_Bootneck",
            "SCM_Eleanor",
            "ACE_salineIV_250", "ACE_salineIV_250", "ACE_salineIV_250", "ACE_salineIV_250",
            "ACE_MRE_BeefStew", "ACE_MRE_BeefStew"
        };
    };
};