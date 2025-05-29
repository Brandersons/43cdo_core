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
            "43cdo_core",
            "43cdo_units"
		};
		requiredVersion= 0.01;
		units[]=
        {
            "43cdo_vehicles_jackal_hmg_d_31cd"
        };
		weapons[]={};
		magazines[]={};
	};
};

class CfgVehicles
{
    class UK3CB_BAF_Jackal2_L111A1_D;
    class UK3CB_BAF_Jackal2_L134A1_D;

    class 43cdo_vehicles_jackal_hmg_base : UK3CB_BAF_Jackal2_L111A1_D
    {
        displayName = "Jackal Base (HMG)";
        author = "LCpl. BT";
        faction = "43cdo_faction";
        editorSubcategory = "43cdo_faction_edsubcat_cars";
        scope = 0;
        scopeCurator = 0;
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
        crew = "43cdo_units_npc_rifleman";
        typicalCargo[] = {"43cdo_units_npc_rifleman"};
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
        class UserActions
        {
            class Flag1_Show
            {
                displayName = "Raise Flag";
                textToolTip = "";
                shortcut = "";
                priority = 2.9;
                position = "";
                radius = 5;
                showWindow = 0;
                onlyForPlayer = 1;
                condition = "(getForcedFlagTexture this == """") AND (driver this == player) AND (alive this)";
                statement = "this forceFlagTexture '43cdo_core\data\blue.paa';";
            };
        };
    };
    class 43cdo_vehicles_jackal_gmg_base : UK3CB_BAF_Jackal2_L134A1_D
    {
        displayName = "Jackal Base (GMG)";
        author = "LCpl. BT";
        faction = "43cdo_faction";
        editorSubcategory = "43cdo_faction_edsubcat_cars";
        scope = 0;
        scopeCurator = 0;
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
        crew = "43cdo_units_npc_rifleman";
        typicalCargo[] = {"43cdo_units_npc_rifleman"};
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
        class UserActions
        {
            class Flag1_Show
            {
                displayName = "Raise Flag";
                textToolTip = "";
                shortcut = "";
                priority = 2.9;
                position = "";
                radius = 5;
                showWindow = 0;
                onlyForPlayer = 1;
                condition = "(getForcedFlagTexture this == """") AND (driver this == player) AND (alive this)";
                statement = "this forceFlagTexture '43cdo_core\data\blue.paa';";
            };
        };
    };
    class 43cdo_vehicles_jackal_hmg_d_31cd : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "Jackal HMG (3-1 C/D)";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_carsdesert";
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
    };
};