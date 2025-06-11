class 43cdo_units_soldier_31gpmg : 43cdo_units_soldier_base
{
    scope = 2;
    scopeCurator = 2;
    side = 1;
    displayName = "GPMG";
    editorSubcategory = "43cdo_faction_edsubcat_playersqm";
    author = "Cpl. N. Monarch";
    threat[] = {1, 0.1, 0.1};

    attendant = 0;
    engineer = 0;

    uniform = "SCM_G4_T_uniform";
    backpack = "SCM_Trizip";
    weapons[] =
    {
        "UK3CB_BAF_L7A2",
        "rhsusf_weap_glock17g4",
        "Put",
        "Throw",
        "Binocular"
    };
    respawnWeapons[] =
    {
        "UK3CB_BAF_L7A2",
        "rhsusf_weap_glock17g4",
        "Put",
        "Throw",
        "Binocular"
    };
    linkedItems[] =
    {
        "SCM_Virtus_Assaulter_1_Belt",
        "SCM_Fast_B_2",
        "ItemMap",
        "ItemCompass",
        "TFAR_microdagr",
        "TFAR_rf7800str"
    };
    respawnLinkedItems[] =
    {
        "SCM_Virtus_Assaulter_1_Belt",
        "SCM_Fast_B_2",
        "ItemMap",
        "ItemCompass",
        "TFAR_microdagr",
        "TFAR_rf7800str"
    };

    class loadoutitems
    {
        loadedmagazineprimary[] = {"UK3CB_BAF_762_200Rnd"};
        loadedmagazinesecondary[] = {"UK3CB_BAF_9_17Rnd"};
        itemsuniform[] =
        {
            "ACE_Canteen",
            "ACE_Flashlight_XL50",
            "ACE_MapTools",
            "ItemcTabHCam",
            "ItemMicroDAGR",
            "ACE_splint",
            "ACE_EHP",
            "ACE_CableTie", "ACE_CableTie", "ACE_CableTie", "ACE_CableTie",
            "ACE_Tourniquet", "ACE_Tourniquet", "ACE_Tourniquet", "ACE_Tourniquet",
            "ACE_MRE_BeefStew", "ACE_MRE_BeefStew"
        };
        itemsvest[] =
        {
            "rhs_mag_m67", "rhs_mag_m67",
            "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell",
            "UK3CB_BAF_762_200Rnd", "UK3CB_BAF_762_200Rnd",
            "UK3CB_BAF_762_100Rnd", "UK3CB_BAF_762_100Rnd",
            "UK3CB_BAF_9_17Rnd", "UK3CB_BAF_9_17Rnd"
        };
        itemsbackpack[] =
        {
            "ACE_EntrenchingTool",
            "ACE_epinephrine",
            "ACE_morphine",
            "ACE_bodyBag",
            "ACE_Painkillers",
            "kat_chestSeal",
            "kat_guedel",
            "SCM_PVS31_C_WP",
            "UK3CB_BAF_H_Beret_RM_Bootneck",
            "UK3CB_BAF_762_200Rnd",
            "ACE_IR_Strobe_Item", "ACE_IR_Strobe_Item",
            "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage",
            "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
            "ACE_quikclot", "ACE_quikclot", "ACE_quikclot", "ACE_quikclot"
        };
    };
};