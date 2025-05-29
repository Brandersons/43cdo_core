class CfgPatches
{
	class 43cdo_vehicles
	{
		name="[43CDO] Vehicles";
		author="LCpl. BT";
        url="";
        addonRootClass = "43cdo_core";
		requiredAddons[]= 
		{

		};
		requiredVersion= 0.01;
		units[]=
        {
            "43cdo_vehicles_jackal_hmg_d_test"
        };
		weapons[]={};
		magazines[]={};
	};
};

class CfgVehicles
{
    class UK3CB_BAF_Jackal2_L111A1_D;
    class UK3CB_BAF_Jackal2_L111A1_W;
    class UK3CB_BAF_Jackal2_L134A1_D;
    class UK3CB_BAF_Jackal2_L134A1_W;

    class 43cdo_vehicles_jackal_hmg_d_test : UK3CB_BAF_Jackal2_L111A1_D
    {
        displayName = "Test Jackal HMG (D)";
        author = "LCpl. BT";
        faction = "43cdo_faction";
        editorSubcategory = "43cdo_faction_edsubcat_cars";
        scope = 2;
        scopeCurator = 2;
        editorPreview = "\UK3CB_BAF_Vehicles\addons\UK3CB_BAF_Vehicles_Coyote_Jackal\data\ui\UK3CB_BAF_Jackal2_L111A1_D.jpg";
        icon = "\UK3CB_BAF_Vehicles\addons\UK3CB_BAF_Vehicles_Coyote_Jackal\data\ui\icon_jackal_L2A1_ca.paa";
        hiddenSelections[] = {"camo1","camo2","camo3","camo4","id1","id2","id3"};
        hiddenSelectionsTextures[] =
        {
            "\UK3CB_BAF_Vehicles\addons\UK3CB_BAF_Vehicles_Coyote_Jackal\data\jackal_base_co.paa",
            "\UK3CB_BAF_Vehicles\addons\UK3CB_BAF_Vehicles_Coyote_Jackal\data\jackal_mount_co.paa",
            "\UK3CB_BAF_Vehicles\addons\UK3CB_BAF_Vehicles_Coyote_Jackal\data\jackal_adds_co.paa",
            "\UK3CB_BAF_Vehicles\addons\UK3CB_BAF_Vehicles_Coyote_Jackal\data\jackal_bar_co.paa",
            "",
            "",
            ""
        };
        typicalCargo[] = {"43cdo_units_npc_rifleman "};
        transportItems[] = {};
        transportMagazines[] = {};
        transportWeapons[] = {};
    };
    class 43cdo_vehicles_jackal_hmg_w_test : UK3CB_BAF_Jackal2_L111A1_W
    {
        displayName = "Test Jackal HMG (W)";
        author = "LCpl. BT";
        faction = "43cdo_faction";
        editorSubcategory = "43cdo_faction_edsubcat_cars";
        scope = 2;
        scopeCurator = 2;
        editorPreview = "\UK3CB_BAF_Vehicles\addons\UK3CB_BAF_Vehicles_Coyote_Jackal\data\ui\UK3CB_BAF_Jackal2_L111A1_D.jpg";
        icon = "\UK3CB_BAF_Vehicles\addons\UK3CB_BAF_Vehicles_Coyote_Jackal\data\ui\icon_jackal_L2A1_ca.paa";
        hiddenSelections[] = {"camo1","camo2","camo3","camo4","id1","id2","id3"};
        hiddenSelectionsTextures[] =
        {
            "\UK3CB_BAF_Vehicles\addons\UK3CB_BAF_Vehicles_Coyote_Jackal\data\jackal_base_co.paa",
            "\UK3CB_BAF_Vehicles\addons\UK3CB_BAF_Vehicles_Coyote_Jackal\data\jackal_mount_co.paa",
            "\UK3CB_BAF_Vehicles\addons\UK3CB_BAF_Vehicles_Coyote_Jackal\data\jackal_adds_co.paa",
            "\UK3CB_BAF_Vehicles\addons\UK3CB_BAF_Vehicles_Coyote_Jackal\data\jackal_bar_co.paa",
            "",
            "",
            ""
        };
        typicalCargo[] = {"43cdo_units_npc_rifleman"};
        transportItems[] = {};
        transportMagazines[] = {};
        transportWeapons[] = {};
    };
};