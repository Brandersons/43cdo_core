class CfgPatches
{
    class 43cdo_weapons
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        addonRootClass = "43cdo_core";
        requiredAddons[] = {
            "43cdo_core",
            "A3_Characters_F",
            "scm_l403A1",
            "scm_attachments",
            "UKSF_LMT",
            "kt_optic"
        };
    };
};

class CfgWeapons
{
    class SCM_L403A1_Tan;
    class 43cdo_weapons_l403a1 : SCM_L403A1_Tan
    {
        displayName = "L403A1";
        scope = 2;
        class LinkedItems
        {
            class LinkedItemsOptic
            {
                slot = "CowsSlot";
                item = "SCM_Eleanor";
            };
            class LinkedItemsAcc
            {
                slot = "PointerSlot";
                item = "UK3CB_BAF_LLM_IR_Tan";
            };
            class LinkedItemsMuzzle
            {
                slot = "MuzzleSlot";
                item = "SCM_PRT_Cover";
            };
            class LinkedItemsUnder
            {
                slot = "UnderBarrelSlot";
                item = "rhsusf_acc_grip2_tan";
            };
        };
    };

    class 43cdo_weapons_l403a1_recce_marine : SCM_L403A1_Tan
    {
        displayName = "L403A1";
        scope = 2;
        class LinkedItems
        {
            class LinkedItemsOptic
            {
                slot = "CowsSlot";
                item = "SCM_Eleanor";
            };
            class LinkedItemsAcc
            {
                slot = "PointerSlot";
                item = "rhsusf_acc_anpeq15_wmx";
            };
            class LinkedItemsMuzzle
            {
                slot = "MuzzleSlot";
                item = "SCM_PRT_Cover";
            };
            class LinkedItemsUnder
            {
                slot = "UnderBarrelSlot";
                item = "rhs_acc_grip_rk6";
            };
        };
    };

    class 43cdo_weapons_l403a1_recce_delta : SCM_L403A1_Tan
    {
        displayName = "L403A1";
        scope = 2;
        class LinkedItems
        {
            class LinkedItemsOptic
            {
                slot = "CowsSlot";
                item = "SCM_Eleanor";
            };
            class LinkedItemsAcc
            {
                slot = "PointerSlot";
                item = "ACE_DBAL_A3_Green";
            };
            class LinkedItemsMuzzle
            {
                slot = "MuzzleSlot";
                item = "SCM_PRT_Cover";
            };
            class LinkedItemsUnder
            {
                slot = "UnderBarrelSlot";
                item = "rhs_acc_grip_rk6";
            };
        };
    };

    class UKSF_L129A2_65_Base;
    class 43cdo_weapons_l129a2 : UKSF_L129A2_65_Base
    {
        displayName = "L129A2";
        scope = 2;
        class LinkedItems
        {
            class LinkedItemsOptic
            {
                slot = "CowsSlot";
                item = "RKSL_optic_PMII_312_sunshade";
            };
            class LinkedItemsAcc
            {
                slot = "PointerSlot";
                item = "";
            };
            class LinkedItemsMuzzle
            {
                slot = "MuzzleSlot";
                item = "SCM_PRT_Cover";
            };
            class LinkedItemsUnder
            {
                slot = "UnderBarrelSlot";
                item = "sps_atlas_bipod_m_blk";
            };
        };
    };
    class 43cdo_weapons_l129a2_recce : UKSF_L129A2_65_Base
    {
        displayName = "L129A2 Recce";
        scope = 2;
        class LinkedItems
        {
            class LinkedItemsOptic
            {
                slot = "CowsSlot";
                item = "kt_25x_PMII022_msr_ti";
            };
            class LinkedItemsAcc
            {
                slot = "PointerSlot";
                item = "";
            };
            class LinkedItemsMuzzle
            {
                slot = "MuzzleSlot";
                item = "SCM_PRT_Cover";
            };
            class LinkedItemsUnder
            {
                slot = "UnderBarrelSlot";
                item = "sps_atlas_bipod_m_blk";
            };
        };
    };
};

class cfgVehicles
{
    class Weapon_arifle_SPAR_01_blk_F;
    class 43cdo_weapons_prop_base : Weapon_arifle_SPAR_01_blk_F
    {
        scope = 0;
        scopeCurator = 0;
        editorCategory = "43cdo_faction_edcat_objects";
        editorSubcategory = "43cdo_faction_edsubcat_props";
        simulation = "thing";
        selectionFireAnim = "";
        class EventHandlers
        {
            init = "\
                private _prop = _this select 0; \
                _prop setDamage 1; _prop enableSimulation false; \
            ";
        };
    };
    class 43cdo_weapons_l85a3_prop : 43cdo_weapons_prop_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "L85a3";
        model = "\UK3CB_BAF_Weapons\addons\UK3CB_BAF_Weapons_L85A3\uk3cb_L85A3.p3d";
    };
    class 43cdo_weapons_l403a1_prop : 43cdo_weapons_prop_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "L403A1";
        model = "\Scotts_L403A1\Models\KS1_tan.p3d";
    };
    class 43cdo_weapons_l403a1_prop_magazine : 43cdo_weapons_prop_base
    {
        scope = 2;
        scopeCurator = 2;
        displayname = "EMAG 30rnd 556x45 M855A1 EPR";
        model = "Scotts_EMAG\Models\EMAG_Magpul.p3d";
    };
    class 43cdo_weapons_l403a1_prop_scope : 43cdo_weapons_prop_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "[SCM] Vortex Eleanor";
        model = "Scotts_Attachments\Models\Eleanor.p3d";
    };
    class 43cdo_weapons_l403a1_prop_muzzle : 43cdo_weapons_prop_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "[SCM] KAC 556 PRT";
        model = "Scotts_Attachments\Models\PRT_Cover.p3d";
    };
    class 43cdo_weapons_l129a2_prop : 43cdo_weapons_prop_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "L129A2 6.5 Creedmoor";
        model = "UKSF_LMT\L129A2.p3d";
    };
    class 43cdo_weapons_l129a2_prop_magazine : 43cdo_weapons_prop_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "20Rnd 6.5Creedmoor Sierra Matchking ";
        model = "UKSF_LMT\PMAG_20.p3d";
    };
    class 43cdo_weapons_l7a2_prop : 43cdo_weapons_prop_base
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "L7A2";
        model = "UK3CB_BAF_Weapons\addons\UK3CB_BAF_Weapons_L7\UK3CB_L7A2.p3d";
    };
};