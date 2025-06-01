class CfgPatches
{
    class 43cdo_units
    {
        name = "43cdo_units";
        // if you want a unit to show up in zeus you've gotta add it here
        units[] =
        {
            "43cdo_units_soldier_zeus",
            "43cdo_units_soldier_311ic",
            "43cdo_units_soldier_medic"
        };
        // any weapons, helmets or vests equipped to any of the soldier classes
        weapons[] =
        {
            "43cdo_weapons_l403a1",
            "rhsusf_weap_glock17g4",
            "SCM_Virtus_Assaulter_1_Belt",
            "SCM_Fast_B_2"
        };
        requiredVersion = 0.1;
        addonRootClass = "43cdo_core";
        requiredAddons[] =
        {
            "43cdo_core",
            "A3_Characters_F"
        };
    };
};

class CfgVehicles
{   
    // this is the base soldier class for all 43cdo soldiers, do not change this unless necessary
    class B_Soldier_base_F;
    class 43cdo_units_soldier_base : B_Soldier_base_F
    {
        scope = 1;
        displayName = "43 Commando Base Soldier";
        faction = "43cdo_faction";
        editorSubcategory = "43cdo_faction_edsubcat_playersqm";
        author = "LCpl. BT";
        cost = 100000;
        camouflage = 1.4;
        sensitivity = 2.5;
        threat[] = {1,0.1,0.1};
        model = "\A3\Characters_F\BLUFOR\b_soldier_01.p3d";
        faceType = "Man_A3";
        glassesEnabled = 0;
        uniformClass = "SCM_G4_T_uniform";
        linkedItems[] =
        {
            "SCM_Virtus_Assaulter_1_Belt",
            "SCM_Fast_B_2",
            "ItemMap",
            "ItemCompass",
            "ItemWatch",
            "TFAR_rf7800str"
        };
        respawnLinkedItems[] =
        {
            "SCM_Virtus_Assaulter_1_Belt",
            "SCM_Fast_B_2",
            "ItemMap",
            "ItemCompass",
            "ItemWatch",
            "TFAR_rf7800str"
        };
        weapons[] =
        {
            "Throw",
            "Put",
            "Binocular"
        };
        respawnWeapons[] =
        {
            "Throw",
            "Put",
            "Binocular"
        };
        magazines[] = {};
        respawnMagazines[] = {};
        // this is what handles putting the items into the loadout
        class EventHandlers
        {
            init = "\
                private _unit = _this select 0; \
                {_unit addPrimaryWeaponItem _x;} forEach getArray (configFile >> 'CfgVehicles' >> typeOf _unit >> 'loadoutitems' >> 'loadedmagazineprimary'); \
                {_unit addHandgunItem _x;} forEach getArray (configFile >> 'CfgVehicles' >> typeOf _unit >> 'loadoutitems' >> 'loadedmagazinesecondary'); \
                {_unit removeItemFromUniform _x;} forEach uniformItems _unit; \
                {_unit removeItemFromVest _x;} forEach vestItems _unit; \
                {_unit removeItemFromBackpack _x;} forEach backpackItems _unit; \
                {_unit addItemToUniform _x;} forEach getArray (configFile >> 'CfgVehicles' >> typeOf _unit >> 'loadoutitems' >> 'itemsuniform'); \
                {_unit addItemToVest _x;} forEach getArray (configFile >> 'CfgVehicles' >> typeOf _unit >> 'loadoutitems' >> 'itemsvest'); \
                {_unit addItemToBackpack _x;} forEach getArray (configFile >> 'CfgVehicles' >> typeOf _unit >> 'loadoutitems' >> 'itemsbackpack'); \
            ";
        };
    };

    // here is an example soldier class, copy and paste this and change the values to create a new soldier
    // give your class a unique name using the format 43cdo_units_soldier_<name>
    // you will also have to update 43cdo_qm_menu_dialog.hpp to add that loadout to the qm menu
    class 43cdo_units_soldier_example : 43cdo_units_soldier_base
    {
        // Set this to 2 to make it show in 3den, as this example is in the live mod it'll be set to 1 to hide it in 3den
        scope = 1;

        // the name of the soldier in 3den and in game
        displayName = "[43CDO] Example Soldier";

        // the sub category of the soldier in the editor
        editorSubcategory = "43cdo_faction_edsubcat_playersqm";

        // who made the config for this soldier
        author = "LCpl. BT";

        // the relative threat of the soldier against soft, air and armoured enemies respectively
        threat[] = {1, 0.1, 0.1};

        // medic level, 0 = no medic, 1 = medic, 2 = doctor
        attendant = 0;

        // engineer level, 0 = no engineer, 1 = engineer, 2 = advanced engineer
        engineer = 0;
        
        // the uniform the soldier will spawn with
        uniform = "SCM_G4_T_uniform";

        // the backpack the soldier will spawn with
        backpack = "SCM_AVS_1000_Radio";

        // the weapons the soldier will spawn with, this has to include "Put" and "Throw" at a minimum and should ideally include "Binocular" or some other binoculars classname
        // the primary weapon must show up first
        // the secondary weapon must show up second
        // yes this is wrong on my configs I am going to change it later
        weapons[] = {
            "43cdo_weapons_l403a1",
            "rhsusf_weap_glock17g4",
            "Put",
            "Throw",
            "Rangefinder"
        };

        // this should be the same as weapons[]
        respawnWeapons[] =
        {
            "43cdo_weapons_l403a1",
            "rhsusf_weap_glock17g4",
            "Put",
            "Throw",
            "Rangefinder"
        };

        // the items which will be added and equipped, does not include weapons, uniform or backpack
        linkedItems[] =
        {
            "SCM_Virtus_Assaulter_1_Belt",
            "SCM_Fast_B_2",
            "ItemMap",
            "ItemCompass",
            "TFAR_microdagr",
            "TFAR_anprc152"
        };

        // this should be the same as linkedItems[]
        respawnLinkedItems[] =
        {
            "SCM_Virtus_Assaulter_1_Belt",
            "SCM_Fast_B_2",
            "ItemMap",
            "ItemCompass",
            "TFAR_microdagr",
            "TFAR_anprc152"
        };

        // this is where you set up what items get added to the various parts of the loadout
        // this is very non standard but is required for the qm menu to load the items into the correct inventory locations
        class loadoutitems
        {
            // if you want a magazine to be loaded by default, you need to add it here
            loadedmagazineprimary[] = {"Scotts_43Cdo_EMAG_Magpul_M855A1_EPR"};
            loadedmagazinesecondary[] = {"UK3CB_BAF_9_17Rnd"};

            // all the items to be added to the uniform
            // this must be a comma seperated list whith each item showing up as many times as you want it to be in the loadout
            // you cannot use a c++ macro for this unfortunately
            itemsuniform[] =
            {
                "ACE_CableTie", "ACE_CableTie", "ACE_CableTie", "ACE_CableTie",
                "ACE_Canteen",
                "ACE_Flashlight_XL50",
                "ACE_MapTools",
                "ItemcTabHCam",
                "ItemAndroid",
                "ACE_EHP",
                "ACE_splint",
                "ACE_Tourniquet", "ACE_Tourniquet", "ACE_Tourniquet", "ACE_Tourniquet",
                "ACE_MRE_BeefStew", "ACE_MRE_BeefStew"
            };

            // all the items to be added to the vest
            // this must be a comma seperated list whith each item showing up as many times as you want it to be in the loadout
            // you cannot use a c++ macro for this unfortunately
            itemsvest[] =
            {
                "rhs_mag_m67", "rhs_mag_m67",
                "UK3CB_BAF_SmokeShell", "UK3CB_BAF_SmokeShell",
                "UK3CB_BAF_SmokeShellPurple", "UK3CB_BAF_SmokeShellPurple", "UK3CB_BAF_SmokeShellPurple",
                "UK3CB_BAF_SmokeShellBlue", "UK3CB_BAF_SmokeShellBlue", "UK3CB_BAF_SmokeShellBlue",
                "UK3CB_BAF_SmokeShellRed", "UK3CB_BAF_SmokeShellRed", "UK3CB_BAF_SmokeShellRed",
                "UK3CB_BAF_SmokeShellGreen", "UK3CB_BAF_SmokeShellGreen", "UK3CB_BAF_SmokeShellGreen",
                "Scotts_43Cdo_EMAG_Magpul_M855A1_EPR", "Scotts_43Cdo_EMAG_Magpul_M855A1_EPR", "Scotts_43Cdo_EMAG_Magpul_M855A1_EPR", "Scotts_43Cdo_EMAG_Magpul_M855A1_EPR",
                "Scotts_43Cdo_EMAG_M855A1_EPR_IR_Dim", "Scotts_43Cdo_EMAG_M855A1_EPR_IR_Dim",
                "Scotts_43Cdo_EMAG_M855A1_EPR_Tracer", "Scotts_43Cdo_EMAG_M855A1_EPR_Tracer",
                "UK3CB_BAF_9_17Rnd", "UK3CB_BAF_9_17Rnd"
            };

            // all the items to be added to the backpack
            // this must be a comma seperated list whith each item showing up as many times as you want it to be in the loadout
            // you cannot use a c++ macro for this unfortunately
            itemsbackpack[] =
            {
                "ACE_EntrenchingTool",
                "ACE_epinephrine",
                "ACE_morphine",
                "ACE_bodyBag",
                "ACE_Painkillers",
                "kat_chestseal",
                "kat_guedel",
                "SCM_PVS31_C_WP",
                "UK3CB_BAF_H_Beret_RM_Bootneck",
                "Scotts_43Cdo_EMAG_Magpul_M855A1_EPR", "Scotts_43Cdo_EMAG_Magpul_M855A1_EPR", "Scotts_43Cdo_EMAG_Magpul_M855A1_EPR",
                "Scotts_43Cdo_EMAG_M855A1_EPR_Tracer", "Scotts_43Cdo_EMAG_M855A1_EPR_Tracer", "Scotts_43Cdo_EMAG_M855A1_EPR_Tracer",
                "Scotts_43Cdo_EMAG_M855A1_EPR_IR_Dim", "Scotts_43Cdo_EMAG_M855A1_EPR_IR_Dim", "Scotts_43Cdo_EMAG_M855A1_EPR_IR_Dim",
                "ACE_IR_Strobe_Item", "ACE_IR_Strobe_Item",
                "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage",
                "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
                "ACE_quikclot", "ACE_quikclot", "ACE_quikclot", "ACE_quikclot"
            };
        };
    };

    // player loadouts
    #include "\43cdo_units\loadouts\12charlie.hpp"
    #include "\43cdo_units\loadouts\12delta.hpp"
    #include "\43cdo_units\loadouts\12hq.hpp"
    #include "\43cdo_units\loadouts\12marine.hpp"
    #include "\43cdo_units\loadouts\12marksman.hpp"
    #include "\43cdo_units\loadouts\12sig.hpp"
    #include "\43cdo_units\loadouts\31gpmg.hpp"
    #include "\43cdo_units\loadouts\31hqb.hpp"
    #include "\43cdo_units\loadouts\31marine.hpp"
    #include "\43cdo_units\loadouts\31marksman.hpp"
    #include "\43cdo_units\loadouts\31medic.hpp"
    #include "\43cdo_units\loadouts\31pointman.hpp"
    #include "\43cdo_units\loadouts\31sig.hpp"
    #include "\43cdo_units\loadouts\311ic.hpp"
    #include "\43cdo_units\loadouts\312ic.hpp"
    #include "\43cdo_units\loadouts\zeus.hpp"

    //npc loadouts

    class 43cdo_units_npc_welldeckcrew : 43cdo_units_soldier_base
    {
        scope = 2;
        displayName = "Well Deck Crew";
        editorSubcategory = "43cdo_faction_edsubcat_men"
        author = "LCpl. BT";
        uniformClass = "U_B_GEN_Commander_F";
        backpack = "";
        weapons[] = {};
        respawnWeapons[] = {};
        magazines[]={};
        respawnMagazines[]={};
        linkedItems[]=
        {
            "H_Construction_earprot_yellow_F",
            "V_Safety_yellow_F"
        };
        respawnlinkedItems[]=
        {
            "H_Construction_earprot_yellow_F",
            "V_Safety_yellow_F"
        };
        items[]={};
        respawnItems[]={};
    };
    class 43cdo_units_npc_rifleman : 43cdo_units_soldier_base
    {
        scope = 2;
        displayName = "Rifleman";
        editorSubcategory = "43cdo_faction_edsubcat_men"
        author = "LCpl. BT";
        uniformClass = "";
        backpack = "";
        weapons[] = {};
        respawnWeapons[] = {};
        magazines[]={};
        respawnMagazines[]={};
        linkedItems[]=
        {
            "H_Construction_earprot_yellow_F",
            "V_Safety_yellow_F"
        };
        respawnlinkedItems[]=
        {
            "H_Construction_earprot_yellow_F",
            "V_Safety_yellow_F"
        };
        items[]={};
        respawnItems[]={};
    };
};

class CfgGroups {
    class West {
        class 43cdo_faction_edcat
        {
            name = "[43CDO] 43 Commando";
            class 43cdo_faction_group_infantry
            {
                name = "Infantry";
                // below here is where you set up the groups and the soldiers in them
                // remember that arrays start at 0, not 1
                class 43cdo_faction_group_31cd
                {
                    name = "3-1 C/D";
                    faction = "43cdo_faction";
                    editorCategory = "43cdo_faction_edcat";
			        editorSubcategory = "43cdo_faction_edsubcat_infantry";
                    icon = "\A3\ui_f\data\map\markers\nato\b_inf.paa";
                    side = 1;

                    class Unit0
                    {
                        side = 1;
                        vehicle = "43cdo_units_soldier_311ic";
                        rank = "SERGEANT";
                        position[] = {0, 0, 0};
                    };
                    class Unit1
                    {
                        side = 1;
                        vehicle = "43cdo_units_soldier_medic";
                        rank = "PRIVATE";
                        position[] = {0,-2,0};
                    };
                    class Unit2
                    {
                        side = 1;
                        vehicle = "43cdo_units_soldier_medic";
                        rank = "PRIVATE";
                        position[] = {0,-4,0};
                    };
                    class Unit3
                    {
                        side = 1;
                        vehicle = "43cdo_units_soldier_311ic";
                        rank = "CORPORAL";
                        position[] = {0,-6,0};
                    };
                    class Unit4
                    {
                        side = 1;
                        vehicle = "43cdo_units_soldier_medic";
                        rank = "PRIVATE";
                        position[] = {0,-8,0};
                    };
                    class Unit5
                    {
                        side = 1;
                        vehicle = "43cdo_units_soldier_medic";
                        rank = "PRIVATE";
                        position[] = {0,-10,0};
                    };
                };
            };
        };
    };
};