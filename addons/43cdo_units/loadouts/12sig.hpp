class 43cdo_units_soldier_12sig : 43cdo_units_soldier_base
{
    scope = 2;
    scopeCurator = 2;
    side = 1;
    displayName = "1-2 Signaller";
    editorSubcategory = "43cdo_faction_edsubcat_playersqm";
    author = "Cpl. N. Monarch";
    threat[] = {1, 0.1, 0.1};

    attendant = 1;
    engineer = 0;

    uniform = "SCM_G4_RS_Undershirt_GRY_uniform";
    backpack = "SCM_Trizip";
    weapons[] =
    {
        "43cdo_weapons_l403a1",
        "rhsusf_weap_glock17g4",
        "Put",
        "Throw",
        "ACE_Vector"
    };
    respawnWeapons[] =
    {
        "43cdo_weapons_l403a1",
        "rhsusf_weap_glock17g4",
        "Put",
        "Throw",
        "ACE_Vector"
    };
    linkedItems[] =
    {
        "SCM_Virtus_Medic_1_Belt",
        "SCM_Fast_B_2",
        "ItemMap",
        "ItemCompass",
        "KAT_Katmin",
        "TFAR_anprc152"
    };
    respawnLinkedItems[] =
    {
        "SCM_Virtus_Medic_1_Belt",
        "SCM_Fast_B_2",
        "ItemMap",
        "ItemCompass",
        "KAT_Katmin",
        "TFAR_anprc152"
    };

    class loadoutitems
    {
        loadedmagazineprimary[] = {"Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Tracer_Blue"};
        loadedmagazinesecondary[] = {"rhsusf_mag_17Rnd_9x19_JHP"};
        itemsuniform[] =
        {
            "ACE_Canteen",
            "ACE_Flashlight_XL50",
            "ACE_MapTools",
            "ItemcTabHCam",
            "ACE_EHP",
            "ACE_IR_Strobe_Item",
            "ACE_microDAGR",
            "ItemAndroid",
            "kat_Caffeine",
            "ACE_painkillers",
            "ACE_CableTie", "ACE_CableTie",
            "ACE_MRE_BeefStew", "ACE_MRE_BeefStew",
            "kat_TXA", "kat_TXA"
        };
        itemsvest[] =
        {
            "ItemcTab",
            "ACE_RangeCard",
            "kt_25x_PMII022_msr_ti",
            "UK3CB_BAF_SmokeShellPurple",
            "MiniGrenade", "MiniGrenade", "MiniGrenade",
            "tsp_flashbang_cts2", "tsp_flashbang_cts2",
            "UK3CB_BAF_SmokeShellGreen", "UK3CB_BAF_SmokeShellGreen",
            "UK3CB_BAF_SmokeShellRed", "UK3CB_BAF_SmokeShellRed",
            "UK3CB_BAF_SmokeShellBlue", "UK3CB_BAF_SmokeShellBlue",
            "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell",
            "rhsusf_mag_17Rnd_9x19_JHP", "rhsusf_mag_17Rnd_9x19_JHP", "rhsusf_mag_17Rnd_9x19_JHP",
            "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Tracer_Blue", "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Tracer_Blue", "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Tracer_Blue", "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Tracer_Blue",
            "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue", "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue", "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue", "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue", "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue",
            "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
            "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage",
            "ACE_quikclot", "ACE_quikclot",
            "ACE_salineIV", "ACE_salineIV"
        };
        itemsbackpack[] =
        {
            "kat_accuvac",
            "ACE_surgicalKit",
            "kat_X_AED",
            "ACE_EntrenchingTool",
            "kat_Pulseoximeter",
            "Item_JammerVolnorez",
            "ACE_morphine", "ACE_morphine",
            "ACE_salineIV", "ACE_salineIV", "ACE_salineIV", "ACE_salineIV",
            "ACE_salineIV_500", "ACE_salineIV_500", "ACE_salineIV_500", "ACE_salineIV_500",
            "ACE_splint", "ACE_splint", "ACE_splint", "ACE_splint",
            "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
            "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
            "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage",
            "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage",
            "kat_larynx", "kat_larynx", "kat_larynx", "kat_larynx", "kat_larynx",
            "kat_amiodarone", "kat_amiodarone", "kat_amiodarone", "kat_amiodarone", "kat_amiodarone",
            "kat_atropine", "kat_atropine", "kat_atropine", "kat_atropine", "kat_atropine",
            "ACE_quikclot", "ACE_quikclot", "ACE_quikclot", "ACE_quikclot", "ACE_quikclot",
            "ACE_quikclot", "ACE_quikclot", "ACE_quikclot", "ACE_quikclot", "ACE_quikclot",
            "kat_naloxone", "kat_naloxone",
            "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet", "ACE_tourniquet",
            "kat_epinephrineIV", "kat_epinephrineIV", "kat_epinephrineIV", "kat_epinephrineIV", "kat_epinephrineIV",
            "kat_chestSeal", "kat_chestSeal", "kat_chestSeal", "kat_chestSeal", "kat_chestSeal",
            "ACE_adenosine", "ACE_adenosine", "ACE_adenosine", "ACE_adenosine",
            "immersion_pops_poppack", "immersion_pops_poppack", "immersion_pops_poppack", "immersion_pops_poppack", "immersion_pops_poppack"
        };
    };
};