class 43cdo_units_soldier_31b : 43cdo_units_soldier_base
{
    scope = 2;
    scopeCurator = 2;
    side = 1;
    displayName = "3-1 Bravo";
    editorSubcategory = "43cdo_faction_edsubcat_playersqm";
    author = "Cpl. N. Monarch";
    threat[] = {1, 0.1, 0.1};

    attendant = 0;
    engineer = 0;

    uniform = "SCM_G4_T_uniform";
    backpack = "SCM_Delta_Radio";
    weapons[] =
    {
        "43cdo_weapons_l403a1",
        "rhsusf_weap_glock17g4",
        "Put",
        "Throw",
        "Rangefinder"
    };
    respawnWeapons[] =
    {
        "43cdo_weapons_l403a1",
        "rhsusf_weap_glock17g4",
        "Put",
        "Throw",
        "Rangefinder"
    };
    linkedItems[] =
    {
        "SCM_Virtus_Assaulter_1_Belt",
        "SCM_Fast_B_2",
        "ItemMap",
        "ItemCompass",
        "TFAR_microdagr",
        "TFAR_anprc152"
    };
    respawnLinkedItems[] =
    {
        "SCM_Virtus_Assaulter_1_Belt",
        "SCM_Fast_B_2",
        "ItemMap",
        "ItemCompass",
        "TFAR_microdagr",
        "TFAR_anprc152"
    };

    class loadoutitems
    {
        loadedmagazineprimary[] = {"Scotts_43Cdo_EMAG_Magpul_M855A1_EPR"};
        loadedmagazinesecondary[] = {"UK3CB_BAF_9_17Rnd"};
        itemsuniform[] =
        {   
            "ACE_Flashlight_XL50",
            "ACE_MapTools",
            "ItemcTabHCam",
            "ItemcTab",
            "ACE_splint",
            "ACE_EHP",
            "ACE_CableTie", "ACE_CableTie", "ACE_CableTie", "ACE_CableTie",
            "ACE_Tourniquet", "ACE_Tourniquet", "ACE_Tourniquet", "ACE_Tourniquet"
        };
        itemsvest[] = {
            "ACE_HuntIR_monitor",
            "UK3CB_BAF_1Rnd_SmokeBlue_Grenade_shell", "UK3CB_BAF_1Rnd_SmokeBlue_Grenade_shell", "UK3CB_BAF_1Rnd_SmokeBlue_Grenade_shell",
            "UK3CB_BAF_1Rnd_SmokeGreen_Grenade_shell", "UK3CB_BAF_1Rnd_SmokeGreen_Grenade_shell", "UK3CB_BAF_1Rnd_SmokeGreen_Grenade_shell",
            "UK3CB_BAF_1Rnd_SmokePurple_Grenade_shell", "UK3CB_BAF_1Rnd_SmokePurple_Grenade_shell", "UK3CB_BAF_1Rnd_SmokePurple_Grenade_shell",
            "rhs_mag_m67", "rhs_mag_m67",
            "Scotts_43Cdo_EMAG_Magpul_M855A1_EPR", "Scotts_43Cdo_EMAG_Magpul_M855A1_EPR", "Scotts_43Cdo_EMAG_Magpul_M855A1_EPR",
            "Scotts_43Cdo_EMAG_M855A1_EPR_Tracer", "Scotts_43Cdo_EMAG_M855A1_EPR_Tracer", "Scotts_43Cdo_EMAG_M855A1_EPR_Tracer", "Scotts_43Cdo_EMAG_M855A1_EPR_Tracer",
            "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell",
            "UK3CB_BAF_9_17Rnd", "UK3CB_BAF_9_17Rnd"
        };
        itemsbackpack[] =
        {
            "ACE_EntrenchingTool",
            "ACE_epinephrine",
            "ACE_morphine",
            "ACE_bodyBag",
            "UK3CB_BAF_SmokeShellPurple",
            "UK3CB_BAF_SmokeShellGreen",
            "UK3CB_BAF_SmokeShellRed",
            "UK3CB_BAF_SmokeShellBlue",
            "ACE_Painkillers",
            "kat_chestSeal",
            "kat_guedel",
            "SCM_PVS31_C_WP",
            "ItemAndroid",
            "UK3CB_BAF_H_Beret_RM_Officer_PRR",
            "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell",
            "Scotts_43Cdo_EMAG_Magpul_M855A1_EPR", "Scotts_43Cdo_EMAG_Magpul_M855A1_EPR", "Scotts_43Cdo_EMAG_Magpul_M855A1_EPR",
            "Scotts_43Cdo_EMAG_M855A1_EPR_Tracer", "Scotts_43Cdo_EMAG_M855A1_EPR_Tracer", "Scotts_43Cdo_EMAG_M855A1_EPR_Tracer",
            "ACE_IR_Strobe_Item", "ACE_IR_Strobe_Item",
            "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage",
            "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
            "ACE_quikclot", "ACE_quikclot", "ACE_quikclot", "ACE_quikclot",
            "ACE_Canteen",
            "ACE_MRE_BeefStew", "ACE_MRE_BeefStew"
        };
    };
};