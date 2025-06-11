class 43cdo_units_soldier_31medic : 43cdo_units_soldier_base
{
    scope = 2;
    scopeCurator = 2;
    side = 1;
    displayName = "Medic";
    editorSubcategory = "43cdo_faction_edsubcat_playersqm";
    author = "Cpl. N. Monarch";
    threat[] = {1, 0.1, 0.1};

    attendant = 1;
    engineer = 0;

    uniform = "SCM_G4_T_uniform";
    backpack = "SCM_Trizip";
    weapons[] =
    {
        "43cdo_weapons_l403a1",
        "rhsusf_weap_glock17g4",
        "Put",
        "Throw",
        "Binocular"
    };
    respawnWeapons[] =
    {
        "43cdo_weapons_l403a1",
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
        loadedmagazineprimary[] = {"Scotts_43Cdo_EMAG_Magpul_M855A1_EPR"};
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
            "Scotts_43Cdo_EMAG_Magpul_M855A1_EPR", "Scotts_43Cdo_EMAG_Magpul_M855A1_EPR", "Scotts_43Cdo_EMAG_Magpul_M855A1_EPR", "Scotts_43Cdo_EMAG_Magpul_M855A1_EPR",
            "Scotts_43Cdo_EMAG_M855A1_EPR_Tracer", "Scotts_43Cdo_EMAG_M855A1_EPR_Tracer","Scotts_43Cdo_EMAG_M855A1_EPR_Tracer", "Scotts_43Cdo_EMAG_M855A1_EPR_Tracer",
            "UK3CB_BAF_9_17Rnd", "UK3CB_BAF_9_17Rnd"
        };
        itemsbackpack[] =
        {
            "ACE_EntrenchingTool",
            "ACE_surgicalKit",
            "kat_X_AED",
            "kat_accuvac",
            "kat_Pulseoximeter",
            "SCM_PVS31_C_WP",
            "UK3CB_BAF_H_Beret_RM_Bootneck",
            "kat_TXA",
            "kat_Caffeine",
            "ACE_IR_Strobe_Item",
            "ACE_adenosine","ACE_adenosine","ACE_adenosine","ACE_adenosine",
            "kat_amiodarone","kat_amiodarone","kat_amiodarone","kat_amiodarone","kat_amiodarone","kat_amiodarone",
            "kat_atropine","kat_atropine","kat_atropine","kat_atropine","kat_atropine","kat_atropine",
            "kat_epinephrineIV","kat_epinephrineIV","kat_epinephrineIV","kat_epinephrineIV","kat_epinephrineIV","kat_epinephrineIV",
            "ACE_morphine","ACE_morphine","ACE_morphine","ACE_morphine","ACE_morphine","ACE_morphine",
            "kat_naloxone","kat_naloxone",
            "ACE_Painkillers","ACE_Painkillers",
            "ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage",
            "ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage","ACE_elasticBandage",
            "ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage",
            "ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage","ACE_packingBandage",
            "ACE_quikclot","ACE_quikclot","ACE_quikclot","ACE_quikclot","ACE_quikclot""ACE_quikclot","ACE_quikclot","ACE_quikclot","ACE_quikclot","ACE_quikclot",
            "ACE_quikclot","ACE_quikclot","ACE_quikclot","ACE_quikclot","ACE_quikclot""ACE_quikclot","ACE_quikclot","ACE_quikclot","ACE_quikclot","ACE_quikclot",
            "ACE_Tourniquet","ACE_Tourniquet","ACE_Tourniquet","ACE_Tourniquet","ACE_Tourniquet","ACE_Tourniquet","ACE_Tourniquet","ACE_Tourniquet",
            "kat_larynx","kat_larynx","kat_larynx","kat_larynx","kat_larynx","kat_larynx","kat_larynx",
            "kat_guedel","kat_guedel","kat_guedel",
            "kat_chestSeal","kat_chestSeal","kat_chestSeal","kat_chestSeal","kat_chestSeal","kat_chestSeal",
            "ACE_splint","ACE_splint","ACE_splint","ACE_splint","ACE_splint","ACE_splint",
            "ACE_salineIV","ACE_salineIV","ACE_salineIV","ACE_salineIV","ACE_salineIV","ACE_salineIV",
            "ACE_salineIV_500","ACE_salineIV_500","ACE_salineIV_500","ACE_salineIV_500","ACE_salineIV_500","ACE_salineIV_500"
        };
    };
};