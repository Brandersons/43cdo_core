#include "\43cdo_logistics\43cdo_logistics_menu_dialog.hpp"

class CfgPatches
{
	class 43cdo_logistics
	{
		name="[43CDO] Logistics";
		author="LCpl. BT";
        url="";
        addonRootClass = "43cdo_core";
		requiredAddons[]= 
		{
		    "43cdo_core",
            "A3_Data_F_Loadorder",
            "A3_Weapons_F",
            "ace_logistics_wirecutter",
            "ace_explosives",
            "ace_medical_treatment",
            "cba_xeh",
            "rhsusf_c_weapons",
			"UK3CB_BAF_Weapons_LoadOrder",
			"UK3CB_BAF_Equipment",
			"UK3CB_BAF_Vehicles_LoadOrder",
            "3CB_L115A3_338"
		};
		requiredVersion= 0.01;
		units[]=
        {
            "43cdo_logistics_box_suppliesinfantry",
            "43cdo_logistics_box_suppliesrecce",
            "43cdo_logistics_box_suppliesmss",
            "43cdo_logistics_box_launchersnlaw",
            "43cdo_logistics_box_launchersilaw",
            "43cdo_logistics_box_launchersasm",
            "43cdo_logistics_box_sniperrifle",
            "43cdo_logistics_box_wirecutter",
            "43cdo_logistics_box_demo",
            "43cdo_logistics_box_breaching",
            "43cdo_logistics_box_flashbang",
            "43cdo_logistics_box_medical",
            "43cdo_logistics_box_ration"
        };
		weapons[]={};
		magazines[]={};
	};
};

class CfgVehicles
{
    class 43cdo_units_soldier_base;
    class 43cdo_soldier_logi : 43cdo_units_soldier_base
    {
        scope = 2;
        displayName = "Logi Man";
        editorSubcategory = "43cdo_faction_edsubcat_playersqm";
        author = "LCpl. BT";
        // QM will be 0 threat to the enemy
        threat[] = {0, 0, 0};
        value = 100000;
        class loadoutitems
        {
            loadedmagazineprimary[] = {};
            loadedmagazinesecondary[] = {};
            itemsuniform[] ={};
            itemsvest[] = {};
            itemsbackpack[] = {};
        };
        // this is what makes the qm menu show as a scroll option on the qm
        class UserActions
        {
            class 43cdo_logistics_menu_open
            {
                // the tooltip
                displayName = "<t size='1.2'><img image='\43cdo_core\data\43cdo_logotemp.paa' size='1'/> Open Logistics Menu</t>";
                // the icon which shows on the QM
                displayNameDefault = "";
                // if multiple actions are available, this will determine the order (highest first)
                priority = 100;
                // the distance from the QM where the menu will show (in meters)
                radius = 5;
                // this is the memory point for the center of the range check, it's complicated so just leave this as is
                position = "pelvis";
                // this allows the displayNameDefault to show
                showWindow = 1;
                // we want to make sure the menu doesn't dissapear after use
                hideOnUse = 0;
                // this makes the menu available to players only
                onlyForPlayer = 0;
                // the menu will only show if the QM is alive
                condition = "alive this";
                // this opens the menu
                statement = "createDialog '43cdo_logistics_menu_dialog';";
            };
        };
    };
	class VR_Area_01_square_2x2_yellow_F;
	class 43cdo_logistics_spawnpos : VR_Area_01_square_2x2_yellow_F
	{
		displayName = "Logistics Spawn Position";
		editorCategory = "43cdo_faction_edcat_objects";
		editorSubcategory = "43cdo_faction_edsubcat_supplies";
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\VR_Area_01_square_2x2_yellow_F.jpg";
		side = 3;
		mapSize = 2;		
		class EventHandlers
		{
			init = "(_this select 0) setVariable ['hasObject', false, true]; _trigger = (_this select 0); _trigger setTriggerArea [2, 2, 0, false]; _trigger setTriggerActivation ['ANY', 'PRESENT', true]; _trigger setTriggerStatements ['count (thisList select {_x != thisTrigger}) > 0', 'thisTrigger setVariable [""hasObject"", true, true]', 'thisTrigger setVariable [""hasObject"", false, true]'];";
		};
	}
    class NATO_Box_Base;
    class 43cdo_logistics_box_base : NATO_Box_Base
    {
        scope = 0;
        scopeCurator = 0;
        author = "LCpl. BT";
        displayname = "Supply Box Base";
        model = "\A3\weapons_F\AmmoBoxes\AmmoBox_F";
        hiddenSelections[] = {"Camo_Signs","Camo"};
        hiddenSelectionsTextures[] = {"A3\Weapons_F\Ammoboxes\data\AmmoBox_signs_CA.paa","A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"};
        icon = "iconCrateAmmo";
        editorCategory = "43cdo_faction_edcat_objects";
        editorSubcategory = "43cdo_faction_edsubcat_supplies";
        editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Box_NATO_WpsLaunch_F.jpg";
        side = 3;
        mapSize = 2;
        transportMaxWeapons = 10;
        transportMaxMagazines = 50;
        transportMaxItems = 30;
    };
    class 43cdo_logistics_box_example : 43cdo_logistics_box_base
    {
        scope = 0;
        scopeCurator = 0;
        author = "LCpl. BT";
        displayname = "[43Cdo] Empty Box";
        model = "\A3\weapons_F\AmmoBoxes\WpnsBox_long_F";
        hiddenSelectionsTextures[]=
		{
			"43cdo_core\data\blue.paa",
			"A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"
		};
		class TransportMagazines{};
        class TransportWeapons
        {
			class xx_launch_NLAW_F
			{
				weapon = "launch_NLAW_F";
				count = 1;
			};
        };
        class TransportItems{};
	};
    class 43cdo_logistics_box_suppliesinfantry : 43cdo_logistics_box_base
    {
        scope = 2;
        author = "LCpl. BT";
        displayname = "[43Cdo] Section Supplies";
        model = "\A3\weapons_F\AmmoBoxes\WpnsBox_F";
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Box_NATO_Wps_F.jpg";
        hiddenSelectionsTextures[]=
		{
			"43cdo_logistics\data\box_asm_inf.paa",
			"A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"
		};
		class TransportMagazines
		{
			class xx_UK3CB_BAF_9_17Rnd
			{
				magazine = "UK3CB_BAF_9_17Rnd";
				count = 18;
			};
			class xx_Scotts_43Cdo_EMAG_Magpul_M855A1_EPR
			{
				magazine = "Scotts_43Cdo_EMAG_Magpul_M855A1_EPR";
				count = 24;
			};
			class xx_Scotts_43Cdo_EMAG_M855A1_EPR_Tracer
			{
				magazine = "Scotts_43Cdo_EMAG_M855A1_EPR_Tracer";
				count = 24;
			};
			class xx_HandGrenade
			{
				magazine = "HandGrenade";
				count = 12;
			};
			class xx_UK3CB_BAF_SmokeShell
			{
				magazine = "UK3CB_BAF_SmokeShell";
				count = 12;
			};
			class xx_UK3CB_BAF_SmokeShellRed
			{
				magazine = "UK3CB_BAF_SmokeShellRed";
				count = 2;
			};
			class xx_UK3CB_BAF_SmokeShellGreen
			{
				magazine = "UK3CB_BAF_SmokeShellGreen";
				count = 2;
			};
			class xx_UK3CB_BAF_SmokeShellBlue
			{
				magazine = "UK3CB_BAF_SmokeShellBlue";
				count = 2;
			};
			class xx_UK3CB_BAF_1Rnd_HE_Grenade_Shell
			{
				magazine = "UK3CB_BAF_1Rnd_HE_Grenade_Shell";
				count = 8;
			};
			class xx_UK3CB_BAF_1Rnd_HEDP_Grenade_shell
			{
				magazine = "UK3CB_BAF_1Rnd_HEDP_Grenade_shell";
				count = 8;
			};
			class xx_UK3CB_BAF_1Rnd_Smoke_Grenade_shell
			{
				magazine = "UK3CB_BAF_1Rnd_Smoke_Grenade_shell";
				count = 8;
			};
			class xx_UK3CB_BAF_1Rnd_SmokeRed_Grenade_shell
			{
				magazine = "UK3CB_BAF_1Rnd_SmokeRed_Grenade_shell";
				count = 2;
			};
			class xx_UK3CB_BAF_1Rnd_SmokeGreen_Grenade_shell
			{
				magazine = "UK3CB_BAF_1Rnd_SmokeGreen_Grenade_shell";
				count = 2;
			};
			class xx_UK3CB_BAF_1Rnd_SmokeBlue_Grenade_shell
			{
				magazine = "UK3CB_BAF_1Rnd_SmokeBlue_Grenade_shell";
				count = 2;
			};
			class xx_UK3CB_BAF_1Rnd_SmokePurple_Grenade_shell
			{
				magazine = "UK3CB_BAF_1Rnd_SmokePurple_Grenade_shell";
				count = 2;
			};
			class xx_ACE_HuntIR_M203
			{
				magazine = "ACE_HuntIR_M203";
				count = 2;
			};
		};
        class TransportWeapons{};
        class TransportItems{};
	};
	class 43cdo_logistics_box_suppliesrecce : 43cdo_logistics_box_base
	{
		scope = 2;
		scopeCurator = 2;
		author = "LCpl. BT";
		displayName = "[43Cdo] Recce Supplies";
		model = "\A3\weapons_F\AmmoBoxes\WpnsBox_F";
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Box_NATO_Wps_F.jpg";
		hiddenSelectionsTextures[]=
		{
			"43cdo_logistics\data\box_ilaw_recce.paa",
			"A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"
		};
		class TransportMagazines
		{
			class xx_UK3CB_BAF_9_17Rnd
			{
				magazine = "UK3CB_BAF_9_17Rnd";
				count = 12;
			};
			class xx_Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue
			{
				magazine = "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_Blue";
				count = 16;
			};
			class xx_Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_IR
			{
				magazine = "Scotts_43Cdo_EMAG_Mk262_BeVLDT_AP_IR";
				count = 16;
			};
			class xx_UKSF_65Creedmoor_Base_SMK
			{
				magazine = "UKSF_65Creedmoor_Base_SMK";
				count = 16
			};
			class xx_UKSF_65Creedmoor_Base_SMK_IR
			{
				magazine = "UKSF_65Creedmoor_Base_SMK_IR";
				count = 16
			};
			class xx_HandGrenade
			{
				magazine = "HandGrenade";
				count = 8;
			};
			class xx_UK3CB_BAF_SmokeShell
			{
				magazine = "UK3CB_BAF_SmokeShell";
				count = 8;
			};
			class xx_UK3CB_BAF_SmokeShellRed
			{
				magazine = "UK3CB_BAF_SmokeShellRed";
				count = 2;
			};
			class xx_UK3CB_BAF_SmokeShellGreen
			{
				magazine = "UK3CB_BAF_SmokeShellGreen";
				count = 2;
			};
			class xx_UK3CB_BAF_SmokeShellBlue
			{
				magazine = "UK3CB_BAF_SmokeShellBlue";
				count = 2;
			};
			class xx_ACE_M14
			{
				magazine = "ACE_M14";
				count = 6;
			};
		};
		class TransportItems{};
		class TransportWeapons{};
	};
	class 43cdo_logistics_box_suppliesmss : 43cdo_logistics_box_base
	{
		scope = 2;
		scopeCurator = 2;
		author = "LCpl. BT";
		displayName = "[43Cdo] MSS Supplies";
		model = "\A3\weapons_F\AmmoBoxes\WpnsBox_F";
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Box_NATO_Wps_F.jpg";
		hiddenSelectionsTextures[]=
		{
			"43cdo_logistics\data\box_nlaw_mss.paa",
			"A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"
		};
		class TransportMagazines
		{
			class xx_UK3CB_BAF_9_17Rnd
			{
				magazine = "UK3CB_BAF_9_17Rnd";
				count = 18;
			};
			class xx_Scotts_43Cdo_EMAG_Magpul_M855A1_EPR
			{
				magazine = "Scotts_43Cdo_EMAG_Magpul_M855A1_EPR";
				count = 8;
			};
			class xx_Scotts_43Cdo_EMAG_M855A1_EPR_Tracer
			{
				magazine = "Scotts_43Cdo_EMAG_M855A1_EPR_Tracer";
				count = 8;
			};
			class xx_UK3CB_BAF_762_100Rnd
			{
				magazine = "UK3CB_BAF_762_100Rnd";
				count = 12;
			};
			class xx_UKSF_65Creedmoor_Base_SMK
			{
				magazine = "UKSF_65Creedmoor_Base_SMK";
				count = 8;
			};
			class xx_UKSF_65Creedmoor_Base_SMK_Tracer
			{
				magazine = "UKSF_65Creedmoor_Base_SMK_Tracer";
				count = 8;
			};
			class xx_HandGrenade
			{
				magazine = "HandGrenade";
				count = 12;
			};
			class xx_UK3CB_BAF_SmokeShell
			{
				magazine = "UK3CB_BAF_SmokeShell";
				count = 12;
			};
			class xx_UK3CB_BAF_SmokeShellRed
			{
				magazine = "UK3CB_BAF_SmokeShellRed";
				count = 2;
			};
			class xx_UK3CB_BAF_SmokeShellGreen
			{
				magazine = "UK3CB_BAF_SmokeShellGreen";
				count = 2;
			};
			class xx_UK3CB_BAF_SmokeShellBlue
			{
				magazine = "UK3CB_BAF_SmokeShellBlue";
				count = 2;
			};
			class xx_UK3CB_BAF_1Rnd_HE_Grenade_Shell
			{
				magazine = "UK3CB_BAF_1Rnd_HE_Grenade_Shell";
				count = 8;
			};
			class xx_UK3CB_BAF_1Rnd_HEDP_Grenade_shell
			{
				magazine = "UK3CB_BAF_1Rnd_HEDP_Grenade_shell";
				count = 8;
			};
			class xx_UK3CB_BAF_1Rnd_Smoke_Grenade_shell
			{
				magazine = "UK3CB_BAF_1Rnd_Smoke_Grenade_shell";
				count = 8;
			};
			class xx_UK3CB_BAF_1Rnd_SmokeRed_Grenade_shell
			{
				magazine = "UK3CB_BAF_1Rnd_SmokeRed_Grenade_shell";
				count = 2;
			};
			class xx_UK3CB_BAF_1Rnd_SmokeGreen_Grenade_shell
			{
				magazine = "UK3CB_BAF_1Rnd_SmokeGreen_Grenade_shell";
				count = 2;
			};
			class xx_UK3CB_BAF_1Rnd_SmokeBlue_Grenade_shell
			{
				magazine = "UK3CB_BAF_1Rnd_SmokeBlue_Grenade_shell";
				count = 2;
			};
			class xx_UK3CB_BAF_1Rnd_SmokePurple_Grenade_shell
			{
				magazine = "UK3CB_BAF_1Rnd_SmokePurple_Grenade_shell";
				count = 2;
			};
			class xx_ACE_HuntIR_M203
			{
				magazine = "ACE_HuntIR_M203";
				count = 2;
			};
		};
		class TransportWeapons{};
		class TransportItems{};

	};
    class 43cdo_logistics_box_launchersnlaw : 43cdo_logistics_box_base
    {
        scope = 2;
        scopeCurator = 2;
        author = "LCpl. BT";
        displayname = "[43Cdo] Launchers (NLAW)";
        model = "\A3\weapons_F\AmmoBoxes\WpnsBox_long_F";
        hiddenSelectionsTextures[]=
		{
			"43cdo_logistics\data\box_nlaw_mss.paa",
			"A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"
		};
		class TransportMagazines{};
        class TransportWeapons
        {
			class xx_launch_NLAW_F
			{
				weapon = "launch_NLAW_F";
				count = 2;
			};
        };
        class TransportItems{};
    };
    class 43cdo_logistics_box_launchersilaw : 43cdo_logistics_box_base
    {
        scope = 2;
        scopeCurator = 2;
        author = "LCpl. BT";
        displayname = "[43Cdo] Launchers (ILAW)";
        model = "\A3\weapons_F\AmmoBoxes\WpnsBox_long_F";
        hiddenSelectionsTextures[]=
		{
			"43cdo_logistics\data\box_ilaw_recce.paa",
			"A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"
		};
		class TransportMagazines{};
        class TransportWeapons
        {
			class xx_UK3CB_BAF_AT4_CS_AT_Launcher
			{
				weapon = "UK3CB_BAF_AT4_CS_AT_Launcher";
				count = 2;
			};
        };
        class TransportItems{};
	};
    class 43cdo_logistics_box_launchersasm : 43cdo_logistics_box_base
    {
        scope = 2;
        scopeCurator = 2;
        author = "LCpl. BT";
        displayname = "[43Cdo] Launchers (ASM)";
        model = "\A3\weapons_F\AmmoBoxes\WpnsBox_long_F";
        hiddenSelectionsTextures[]=
		{
			"43cdo_logistics\data\box_asm_inf.paa",
			"A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"
		};
        class TransportItems
		{
			class xx_RW_Launch_ASM_AS
			{
				name = "RW_Launch_ASM_AS_Loaded";
				count = 2;
			};
		};
		class TransportMagazines{};
        class TransportWeapons{};
	};
    class 43cdo_logistics_box_sniperrifle : 43cdo_logistics_box_base
    {
        scope = 2;
        scopeCurator = 2;
        author = "LCpl. BT";
        displayname = "[43Cdo] Sniper Rifles";
        model = "\A3\weapons_F\AmmoBoxes\WpnsBox_large_F";
        hiddenSelectionsTextures[]=
		{
			"43cdo_logistics\data\box_asm_inf.paa",
			"A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"
		};
		class TransportMagazines
        {
            class xx_L115_5Rnd_338_Scenar_Mag
            {
                magazine = "L115_5Rnd_338_Scenar_Mag";
                count = 8;
            };
            class xx_L115_5Rnd_338_Scenar_Mag_IR
            {
                magazine = "L115_5Rnd_338_Scenar_Mag_IR";
                count = 8;
            };
            class xx_L115_5Rnd_338_Scenar_Mag_TR
            {
                magazine = "L115_5Rnd_338_Scenar_Mag_TR";
                count = 8;
            };
        };
        class TransportWeapons
        {
			class xx_UK3CB_BAF_L115A3_DE
			{
				weapon = "UK3CB_BAF_L115A3_DE";
				count = 2;
			};
        };
        class TransportItems
        {
            class xx_UK3CB_underbarrel_acc_bipod
            {
                name = "UK3CB_underbarrel_acc_bipod";
                count = 2;
            };
            class xx_UK3CB_BAF_Silencer_L115A3
            {
                name = "UK3CB_BAF_Silencer_L115A3";
                count = 2;
            };
            class xx_kt_25x_PMII022_msr_ti
            {
                name = "kt_25x_PMII022_msr_ti";
                count = 2;
            };
        };
	};
	class 43cdo_logistics_box_wirecutter : 43cdo_logistics_box_base
	{
		scope = 2;
		scopeCurator = 2;
		author = "LCpl. BT";
		displayName = "[43Cdo] Wirecutters";
		model = "\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d";
		editorPreview = "\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_small_olive_F.jpg";
		hiddenSelections[] = {"Camo","Camo2"};
		hiddenSelectionsTextures[] =
		{
			"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa"
		};
		class TransportItems
		{
			class xx_ACE_wirecutter
			{
				name = "ACE_wirecutter";
				count = 4;
			};
		};
		class TransportMagazines{};
		class TransportWeapons{};
	};
	class 43cdo_logistics_box_demo : 43cdo_logistics_box_base
	{
		scope = 2;
		scopeCurator = 2;
		author = "LCpl. BT";
		displayName = "[43Cdo] Demolition Supplies";
		model = "\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d";
		editorPreview = "\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_small_olive_F.jpg";
		hiddenSelections[] = {"Camo","Camo2"};
		hiddenSelectionsTextures[] =
		{
			"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa"
		};
		class TransportItems
		{
			class xx_ACE_M26_Clacker
			{
				name = "ACE_M26_Clacker";
				count = 2;
			};
		};
		class TransportMagazines
		{
			class xx_DemoCharge_Remote_Mag
			{
				magazine = "DemoCharge_Remote_Mag";
				count = 8;
			};
		};
		class TransportWeapons{};
	};
	class 43cdo_logistics_box_breaching : 43cdo_logistics_box_base
	{
		scope = 2;
		scopeCurator = 2;
		author = "LCpl. BT";
		displayName = "[43Cdo] Breaching Supplies";
		model = "\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d";
		editorPreview = "\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_small_olive_F.jpg";
		hiddenSelections[] = {"Camo","Camo2"};
		hiddenSelectionsTextures[] =
		{
			"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa"
		};
		class TransportMagazines
		{
			class xx_tsp_breach_package_mag
			{
				magazine = "tsp_breach_package_mag";
				count = 5;
			};
			class xx_tsp_breach_stick_mag
			{
				magazine = "tsp_breach_stick_mag";
				count = 5;
			};
		};
		class TransportItems{};
		class TransportWeapons{};
	};
	class 43cdo_logistics_box_flashbang : 43cdo_logistics_box_base
	{
		scope = 2;
		scopeCurator = 2;
		author = "LCpl. BT";
		displayName = "[43Cdo] Flashbangs";
		model = "\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d";
		editorPreview = "\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_small_olive_F.jpg";
		hiddenSelections[] = {"Camo","Camo2"};
		hiddenSelectionsTextures[] =
		{
			"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa"
		};
		class TransportMagazines
		{
			class xx_tsp_flashbang_cts2
			{
				magazine = "tsp_flashbang_cts2";
				count = 20;
			};
		};
		class TransportItems{};
		class TransportWeapons{};
	};
	class 43cdo_logistics_box_medical : 43cdo_logistics_box_base
	{
		scope = 2;
		scopeCurator = 2;
		author = "LCpl. BT";
		displayName = "[43Cdo] Section Medical Supplies";
		model = "\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d";
		editorPreview = "\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_medium_olive_F.jpg";
		hiddenSelections[] = {"Camo","Camo2"};
		hiddenSelectionsTextures[] =
		{
			"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa",
			"43cdo_logistics\data\box_medical.paa"
		};
		class TransportItems
		{
			class xx_ACE_elasticBandage
			{
				name = "ACE_elasticBandage";
				count = 40;
			};
			class xx_ACE_quikclot
			{
				name = "ACE_quikclot";
				count = 40;
			};
			class xx_ACE_epinephrine
			{
				name = "ACE_epinephrine";
				count = 20;
			};
			class xx_ACE_morphine
			{
				name = "ACE_morphine";
				count = 20;
			};
			class xx_ACE_splint
			{
				name = "ACE_splint";
				count = 20;
			};
			class xx_ACE_salineIV
			{
				name = "ACE_salineIV";
				count = 15;
			};
			class xx_ACE_salineIV_250
			{
				name = "ACE_salineIV_250";
				count = 15;
			};
			class xx_ACE_salineIV_500
			{
				name = "ACE_salineIV_500";
				count = 15;
			};
			class xx_ACE_adenosine
			{
				name = "ACE_adenosine";
				count = 10;
			};
			class xx_ACE_packingBandage
			{
				name = "ACE_packingBandage";
				count = 40;
			};
			class xx_ACE_fieldDressing
			{
				name = "ACE_fieldDressing";
				count = 40;
			};
			class xx_ACE_bodyBag
			{
				name = "ACE_bodyBag";
				count = 10;
			};
			class xx_ACE_Tourniquet
			{
				name = "ACE_Tourniquet";
				count = 10;
			};
			class xx_kat_amiodarone
			{
				name = "kat_amiodarone";
				count = 10;
			};
			class xx_kat_atropine
			{
				name = "kat_atropine";
				count = 10;
			};
			class xx_ACE_CableeTie
			{
				name = "ACE_CableTie";
				count = 15;
			};
			class xx_kat_larynx
			{
				name = "kat_larynx";
				count = 20;
			};
			class xx_kat_guedel
			{
				name = "kat_guedel";
				count = 10;
			};
			class xx_kat_chestSeal
			{
				name = "kat_chestSeal";
				count = 15;
			};
			class xx_kat_naloxone
			{
				name = "kat_naloxone";
				count = 5;
			};
			class xx_kat_TXA
			{
				name = "kat_TXA";
				count = 5;
			};
		};
	};
	class 43cdo_logistics_box_ration : 43cdo_logistics_box_base
	{
		scope = 2;
		scopeCurator = 2;
		author = "LCpl. BT";
		displayName = "[43Cdo] Rations";
		model = "\A3\Props_F_Orange\Humanitarian\Supplies\PaperBox_01_small_closed_F.p3d";
		editorPreview = "\A3\EditorPreviews_F_Orange\Data\CfgVehicles\Land_PaperBox_01_small_closed_brown_F.jpg";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] =
		{
			"\A3\Props_F_Orange\Humanitarian\Supplies\Data\PaperBox_01_small_brown_CO.paa"
		};
		class TransportItems
		{
			class xx_ACE_Canteen
			{
				name = "ACE_Canteen";
				count = 20;
			};
			class xx_ACE_MRE_BeefStew
			{
				name = "ACE_MRE_BeefStew";
				count = 20;
			};
		};
		class TransportMagazines{};
		class TransportWeapons{};
	};
};