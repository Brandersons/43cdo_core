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

// this will disable the plate textures from spawning by default
//class Extended_Init_EventHandlers
//{
//    class 43cdo_vehicles_jackal_hmg_base
//    {
//        class UK3CB_BAF_Jackal_Base_init
//        {
//            init = "";
//        };
//    };
//    class 43cdo_vehicles_jackal_gmg_base
//    {
//        class UK3CB_BAF_Jackal_Base_init
//        {
//            init = "";
//        };
//    };
//};
//    class 43cdo_vehicles_coyote_hmg_base
//    {
//        class UK3CB_BAF_Jackal_Base_init
//        {
//            init = "";
//        };
//    };
//    class 43cdo_vehicles_coyote_gmg_base
//    {
//        class UK3CB_BAF_Jackal_Base_init
//        {
//            init = "";
//        };
//    };
//};

class CfgVehicles
{
    class UK3CB_BAF_Jackal2_L111A1_D;
    class UK3CB_BAF_Jackal2_L134A1_D;
    class UK3CB_BAF_Coyote_Passenger_L111A1_D;
    class UK3CB_BAF_Coyote_Passenger_L134A1_D;
// base class jackals
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
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_base_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_base_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_base_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_base_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
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
			class Flag1_Hide: Flag1_Show
			{
				displayName="Lower Flag";
				condition="!(getForcedFlagTexture this == """") AND (driver this == player) AND (alive this)";
				statement="this forceFlagTexture """";";
			};
			class Servicing_GUI
			{
				displayName="Servicing Menu";
				displayNameDefault="";
				position="";
				radius=4;
				onlyForplayer=1;
				condition="[this] call UK3CB_BAF_Vehicles_Weapons_fnc_can_service_ground_vehicle";
				statement="createDialog 'UK3CB_Servicing_GUI_Dialog'";
				priority=6;
			};
			class Logistics_GUI
			{
				displayName="Logistics Menu";
				displayNameDefault="";
				position="";
				radius=4;
				onlyForplayer=1;
				condition="[this] call UK3CB_BAF_Vehicles_Weapons_fnc_can_load_vehicle";
				statement="createDialog 'UK3CB_Logistics_GUI_Dialog'";
				priority=5.9899998;
			};
            class CloseBackLeftDoor
            {
                displayName = "Open/Close Rear Door";
                position = "door_axis_left_rear";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'LeftDoorBack') == 1)";
                statement = "[this, 'LeftDoorBack'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_close_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
            class CloseBackRightDoor
            {
                displayName = "Open/Close Rear Door";
                position = "door_axis_right_rear";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'RightDoorBack') == 1)";
                statement = "[this, 'RightDoorBack'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_close_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
            class CloseLeftDoor
            {
                displayName = "Open/Close Front Door";
                position = "door_axis_left_front";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'LeftDoor') == 1)";
                statement = "[this, 'LeftDoor'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_close_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
            class CloseRightDoor
            {
                displayName = "Open/Close Front Door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                position = "door_axis_right_front";
                priority = 5.2;
                radius = 2;
                condition = "alive this && (!(player in this)) && ((this animationPhase 'RightDoor') == 1)";
                statement = "[this, 'RightDoor'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_close_door";
                onlyforplayer = 1;
            };
            class DismountLeft
            {
                displayName = "<t color='#8080ff'>Dismount Left</t>";
                priority = 5.91;
                condition = "[this, 1] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_canDismount";
                statement = "[this, 1] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_dismount";
                displayNameDefault = "<img image='\a3\ui_f\data\igui\cfg\actions\getout_ca.paa' size='1.8' shadow=2 />";
                position = "crew_center";
                radius = 4;
                showwindow = 0;
                onlyforplayer = 1;
            };
            class DismountRight
            {
                displayName = "<t color='#ff8080'>Dismount Right</t>";
                displayNameDefault = "<img image='\a3\ui_f\data\igui\cfg\actions\getout_ca.paa' size='1.8' shadow=2 />";
                position = "crew_center";
                radius = 4;
                priority = 5.9;
                showwindow = 0;
                condition = "[this, 0] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_canDismount";
                statement = "[this, 0] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_dismount";
                onlyforplayer = 1;
            };
            class OpenBackLeftDoor
            {
                displayName = "Open/Close Rear Door";
                position = "door_axis_left_rear";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'LeftDoorBack') == 0)";
                statement = "[this, 'LeftDoorBack'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_open_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
            class OpenBackRightDoor
            {
                displayName = "Open/Close Rear Door";
                position = "door_axis_right_rear";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'RightDoorBack') == 0)";
                statement = "[this, 'RightDoorBack'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_open_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
            class OpenCloseLeftDoor
            {
                displayName = "Open/Close Left Door";
                priority = 5.81;
                condition = "[this, 1] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_canDismount";
                statement = "[this, 1] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_open_close_door";
                displayNameDefault = "<img image='\a3\ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                position = "crew_center";
                radius = 2;
                showwindow = 0;
                onlyforplayer = 1;
            };
            class OpenCloseRightDoor
            {
                displayName = "Open/Close Right Door";
                displayNameDefault = "<img image='\a3\ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                position = "crew_center";
                radius = 2;
                priority = 5.8;
                showwindow = 0;
                condition = "[this, 0] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_canDismount";
                statement = "[this, 0] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_open_close_door";
                onlyforplayer = 1;
            };
            class OpenLeftDoor
            {
                displayName = "Open/Close Front Door";
                position = "door_axis_left_front";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'LeftDoor') == 0)";
                statement = "[this, 'LeftDoor'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_open_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
            class OpenRightDoor
            {
                displayName = "Open/Close Front Door";
                position = "door_axis_right_front";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'RightDoor') == 0)";
                statement = "[this, 'RightDoor'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_open_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
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
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_base_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_base_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_base_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_base_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
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
			class Flag1_Hide: Flag1_Show
			{
				displayName="Lower Flag";
				condition="!(getForcedFlagTexture this == """") AND (driver this == player) AND (alive this)";
				statement="this forceFlagTexture """";";
			};
			class Servicing_GUI
			{
				displayName="Servicing Menu";
				displayNameDefault="";
				position="";
				radius=4;
				onlyForplayer=1;
				condition="[this] call UK3CB_BAF_Vehicles_Weapons_fnc_can_service_ground_vehicle";
				statement="createDialog 'UK3CB_Servicing_GUI_Dialog'";
				priority=6;
			};
			class Logistics_GUI
			{
				displayName="Logistics Menu";
				displayNameDefault="";
				position="";
				radius=4;
				onlyForplayer=1;
				condition="[this] call UK3CB_BAF_Vehicles_Weapons_fnc_can_load_vehicle";
				statement="createDialog 'UK3CB_Logistics_GUI_Dialog'";
				priority=5.9899998;
			};
            class CloseBackLeftDoor
            {
                displayName = "Open/Close Rear Door";
                position = "door_axis_left_rear";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'LeftDoorBack') == 1)";
                statement = "[this, 'LeftDoorBack'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_close_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
            class CloseBackRightDoor
            {
                displayName = "Open/Close Rear Door";
                position = "door_axis_right_rear";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'RightDoorBack') == 1)";
                statement = "[this, 'RightDoorBack'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_close_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
            class CloseLeftDoor
            {
                displayName = "Open/Close Front Door";
                position = "door_axis_left_front";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'LeftDoor') == 1)";
                statement = "[this, 'LeftDoor'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_close_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
            class CloseRightDoor
            {
                displayName = "Open/Close Front Door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                position = "door_axis_right_front";
                priority = 5.2;
                radius = 2;
                condition = "alive this && (!(player in this)) && ((this animationPhase 'RightDoor') == 1)";
                statement = "[this, 'RightDoor'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_close_door";
                onlyforplayer = 1;
            };
            class DismountLeft
            {
                displayName = "<t color='#8080ff'>Dismount Left</t>";
                priority = 5.91;
                condition = "[this, 1] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_canDismount";
                statement = "[this, 1] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_dismount";
                displayNameDefault = "<img image='\a3\ui_f\data\igui\cfg\actions\getout_ca.paa' size='1.8' shadow=2 />";
                position = "crew_center";
                radius = 4;
                showwindow = 0;
                onlyforplayer = 1;
            };
            class DismountRight
            {
                displayName = "<t color='#ff8080'>Dismount Right</t>";
                displayNameDefault = "<img image='\a3\ui_f\data\igui\cfg\actions\getout_ca.paa' size='1.8' shadow=2 />";
                position = "crew_center";
                radius = 4;
                priority = 5.9;
                showwindow = 0;
                condition = "[this, 0] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_canDismount";
                statement = "[this, 0] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_dismount";
                onlyforplayer = 1;
            };
            class OpenBackLeftDoor
            {
                displayName = "Open/Close Rear Door";
                position = "door_axis_left_rear";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'LeftDoorBack') == 0)";
                statement = "[this, 'LeftDoorBack'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_open_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
            class OpenBackRightDoor
            {
                displayName = "Open/Close Rear Door";
                position = "door_axis_right_rear";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'RightDoorBack') == 0)";
                statement = "[this, 'RightDoorBack'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_open_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
            class OpenCloseLeftDoor
            {
                displayName = "Open/Close Left Door";
                priority = 5.81;
                condition = "[this, 1] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_canDismount";
                statement = "[this, 1] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_open_close_door";
                displayNameDefault = "<img image='\a3\ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                position = "crew_center";
                radius = 2;
                showwindow = 0;
                onlyforplayer = 1;
            };
            class OpenCloseRightDoor
            {
                displayName = "Open/Close Right Door";
                displayNameDefault = "<img image='\a3\ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                position = "crew_center";
                radius = 2;
                priority = 5.8;
                showwindow = 0;
                condition = "[this, 0] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_canDismount";
                statement = "[this, 0] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_open_close_door";
                onlyforplayer = 1;
            };
            class OpenLeftDoor
            {
                displayName = "Open/Close Front Door";
                position = "door_axis_left_front";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'LeftDoor') == 0)";
                statement = "[this, 'LeftDoor'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_open_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
            class OpenRightDoor
            {
                displayName = "Open/Close Front Door";
                position = "door_axis_right_front";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'RightDoor') == 0)";
                statement = "[this, 'RightDoor'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_open_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
        };
    };
    class 43cdo_vehicles_coyote_hmg_base : UK3CB_BAF_Coyote_Passenger_L111A1_D
    {
        displayName = "Coyote Base (HMG)";
        author = "LCpl. BT";
        faction = "43cdo_faction";
        editorSubcategory = "43cdo_faction_edsubcat_cars";
        scope = 0;
        scopeCurator = 0;
        editorPreview = "\UK3CB_BAF_Vehicles\addons\UK3CB_BAF_Vehicles_Coyote_Jackal\data\ui\UK3CB_BAF_Coyote_Passenger_L111A1_D.jpg";
        icon = "\UK3CB_BAF_Vehicles\addons\UK3CB_BAF_Vehicles_Coyote_Jackal\data\ui\Icon_Coyote_L2A1_CA.paa";
        hiddenSelections[] = {"camo1","camo2","camo3","camo4","id1","id2","id3"};
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_base_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_base_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_base_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_base_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
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
			class Flag1_Hide: Flag1_Show
			{
				displayName="Lower Flag";
				condition="!(getForcedFlagTexture this == """") AND (driver this == player) AND (alive this)";
				statement="this forceFlagTexture """";";
			};
			class Servicing_GUI
			{
				displayName="Servicing Menu";
				displayNameDefault="";
				position="";
				radius=4;
				onlyForplayer=1;
				condition="[this] call UK3CB_BAF_Vehicles_Weapons_fnc_can_service_ground_vehicle";
				statement="createDialog 'UK3CB_Servicing_GUI_Dialog'";
				priority=6;
			};
			class Logistics_GUI
			{
				displayName="Logistics Menu";
				displayNameDefault="";
				position="";
				radius=4;
				onlyForplayer=1;
				condition="[this] call UK3CB_BAF_Vehicles_Weapons_fnc_can_load_vehicle";
				statement="createDialog 'UK3CB_Logistics_GUI_Dialog'";
				priority=5.9899998;
			};
            class CloseBackLeftDoor
            {
                displayName = "Open/Close Rear Door";
                position = "door_axis_left_rear";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'LeftDoorBack') == 1)";
                statement = "[this, 'LeftDoorBack'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_close_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
            class CloseBackRightDoor
            {
                displayName = "Open/Close Rear Door";
                position = "door_axis_right_rear";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'RightDoorBack') == 1)";
                statement = "[this, 'RightDoorBack'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_close_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
            class CloseLeftDoor
            {
                displayName = "Open/Close Front Door";
                position = "door_axis_left_front";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'LeftDoor') == 1)";
                statement = "[this, 'LeftDoor'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_close_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
            class CloseRightDoor
            {
                displayName = "Open/Close Front Door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                position = "door_axis_right_front";
                priority = 5.2;
                radius = 2;
                condition = "alive this && (!(player in this)) && ((this animationPhase 'RightDoor') == 1)";
                statement = "[this, 'RightDoor'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_close_door";
                onlyforplayer = 1;
            };
            class DismountLeft
            {
                displayName = "<t color='#8080ff'>Dismount Left</t>";
                priority = 5.91;
                condition = "[this, 1] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_canDismount";
                statement = "[this, 1] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_dismount";
                displayNameDefault = "<img image='\a3\ui_f\data\igui\cfg\actions\getout_ca.paa' size='1.8' shadow=2 />";
                position = "crew_center";
                radius = 4;
                showwindow = 0;
                onlyforplayer = 1;
            };
            class DismountRight
            {
                displayName = "<t color='#ff8080'>Dismount Right</t>";
                displayNameDefault = "<img image='\a3\ui_f\data\igui\cfg\actions\getout_ca.paa' size='1.8' shadow=2 />";
                position = "crew_center";
                radius = 4;
                priority = 5.9;
                showwindow = 0;
                condition = "[this, 0] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_canDismount";
                statement = "[this, 0] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_dismount";
                onlyforplayer = 1;
            };
            class OpenBackLeftDoor
            {
                displayName = "Open/Close Rear Door";
                position = "door_axis_left_rear";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'LeftDoorBack') == 0)";
                statement = "[this, 'LeftDoorBack'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_open_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
            class OpenBackRightDoor
            {
                displayName = "Open/Close Rear Door";
                position = "door_axis_right_rear";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'RightDoorBack') == 0)";
                statement = "[this, 'RightDoorBack'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_open_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
            class OpenCloseLeftDoor
            {
                displayName = "Open/Close Left Door";
                priority = 5.81;
                condition = "[this, 1] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_canDismount";
                statement = "[this, 1] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_open_close_door";
                displayNameDefault = "<img image='\a3\ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                position = "crew_center";
                radius = 2;
                showwindow = 0;
                onlyforplayer = 1;
            };
            class OpenCloseRightDoor
            {
                displayName = "Open/Close Right Door";
                displayNameDefault = "<img image='\a3\ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                position = "crew_center";
                radius = 2;
                priority = 5.8;
                showwindow = 0;
                condition = "[this, 0] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_canDismount";
                statement = "[this, 0] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_open_close_door";
                onlyforplayer = 1;
            };
            class OpenLeftDoor
            {
                displayName = "Open/Close Front Door";
                position = "door_axis_left_front";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'LeftDoor') == 0)";
                statement = "[this, 'LeftDoor'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_open_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
            class OpenRightDoor
            {
                displayName = "Open/Close Front Door";
                position = "door_axis_right_front";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'RightDoor') == 0)";
                statement = "[this, 'RightDoor'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_open_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
        };
    };
    class 43cdo_vehicles_coyote_gmg_base : UK3CB_BAF_Coyote_Passenger_L134A1_D
    {
        displayName = "Coyote Base (GMG)";
        author = "LCpl. BT";
        faction = "43cdo_faction";
        editorSubcategory = "43cdo_faction_edsubcat_cars";
        scope = 0;
        scopeCurator = 0;
        editorPreview = "\UK3CB_BAF_Vehicles\addons\UK3CB_BAF_Vehicles_Coyote_Jackal\data\ui\UK3CB_BAF_Coyote_Passenger_L134A1_D.jpg";
        icon = "\UK3CB_BAF_Vehicles\addons\UK3CB_BAF_Vehicles_Coyote_Jackal\data\ui\Icon_Coyote_L2A1_CA.paa";
        hiddenSelections[] = {"camo1","camo2","camo3","camo4","id1","id2","id3"};
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_base_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_base_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_base_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_base_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
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
			class Flag1_Hide: Flag1_Show
			{
				displayName="Lower Flag";
				condition="!(getForcedFlagTexture this == """") AND (driver this == player) AND (alive this)";
				statement="this forceFlagTexture """";";
			};
			class Servicing_GUI
			{
				displayName="Servicing Menu";
				displayNameDefault="";
				position="";
				radius=4;
				onlyForplayer=1;
				condition="[this] call UK3CB_BAF_Vehicles_Weapons_fnc_can_service_ground_vehicle";
				statement="createDialog 'UK3CB_Servicing_GUI_Dialog'";
				priority=6;
			};
			class Logistics_GUI
			{
				displayName="Logistics Menu";
				displayNameDefault="";
				position="";
				radius=4;
				onlyForplayer=1;
				condition="[this] call UK3CB_BAF_Vehicles_Weapons_fnc_can_load_vehicle";
				statement="createDialog 'UK3CB_Logistics_GUI_Dialog'";
				priority=5.9899998;
			};
            class CloseBackLeftDoor
            {
                displayName = "Open/Close Rear Door";
                position = "door_axis_left_rear";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'LeftDoorBack') == 1)";
                statement = "[this, 'LeftDoorBack'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_close_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
            class CloseBackRightDoor
            {
                displayName = "Open/Close Rear Door";
                position = "door_axis_right_rear";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'RightDoorBack') == 1)";
                statement = "[this, 'RightDoorBack'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_close_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
            class CloseLeftDoor
            {
                displayName = "Open/Close Front Door";
                position = "door_axis_left_front";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'LeftDoor') == 1)";
                statement = "[this, 'LeftDoor'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_close_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
            class CloseRightDoor
            {
                displayName = "Open/Close Front Door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                position = "door_axis_right_front";
                priority = 5.2;
                radius = 2;
                condition = "alive this && (!(player in this)) && ((this animationPhase 'RightDoor') == 1)";
                statement = "[this, 'RightDoor'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_close_door";
                onlyforplayer = 1;
            };
            class DismountLeft
            {
                displayName = "<t color='#8080ff'>Dismount Left</t>";
                priority = 5.91;
                condition = "[this, 1] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_canDismount";
                statement = "[this, 1] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_dismount";
                displayNameDefault = "<img image='\a3\ui_f\data\igui\cfg\actions\getout_ca.paa' size='1.8' shadow=2 />";
                position = "crew_center";
                radius = 4;
                showwindow = 0;
                onlyforplayer = 1;
            };
            class DismountRight
            {
                displayName = "<t color='#ff8080'>Dismount Right</t>";
                displayNameDefault = "<img image='\a3\ui_f\data\igui\cfg\actions\getout_ca.paa' size='1.8' shadow=2 />";
                position = "crew_center";
                radius = 4;
                priority = 5.9;
                showwindow = 0;
                condition = "[this, 0] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_canDismount";
                statement = "[this, 0] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_dismount";
                onlyforplayer = 1;
            };
            class OpenBackLeftDoor
            {
                displayName = "Open/Close Rear Door";
                position = "door_axis_left_rear";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'LeftDoorBack') == 0)";
                statement = "[this, 'LeftDoorBack'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_open_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
            class OpenBackRightDoor
            {
                displayName = "Open/Close Rear Door";
                position = "door_axis_right_rear";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'RightDoorBack') == 0)";
                statement = "[this, 'RightDoorBack'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_open_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
            class OpenCloseLeftDoor
            {
                displayName = "Open/Close Left Door";
                priority = 5.81;
                condition = "[this, 1] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_canDismount";
                statement = "[this, 1] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_open_close_door";
                displayNameDefault = "<img image='\a3\ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                position = "crew_center";
                radius = 2;
                showwindow = 0;
                onlyforplayer = 1;
            };
            class OpenCloseRightDoor
            {
                displayName = "Open/Close Right Door";
                displayNameDefault = "<img image='\a3\ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                position = "crew_center";
                radius = 2;
                priority = 5.8;
                showwindow = 0;
                condition = "[this, 0] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_canDismount";
                statement = "[this, 0] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_open_close_door";
                onlyforplayer = 1;
            };
            class OpenLeftDoor
            {
                displayName = "Open/Close Front Door";
                position = "door_axis_left_front";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'LeftDoor') == 0)";
                statement = "[this, 'LeftDoor'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_open_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
            class OpenRightDoor
            {
                displayName = "Open/Close Front Door";
                position = "door_axis_right_front";
                condition = "alive this && (!(player in this)) && ((this animationPhase 'RightDoor') == 0)";
                statement = "[this, 'RightDoor'] call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_open_door";
                displayNameDefault = "<img image='\a3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
                priority = 5.2;
                radius = 2;
                onlyforplayer = 1;
            };
        };
    };
// 1-2 HQ Jackals and Coyotes
    class 43cdo_vehicles_jackal_hmg_d_12hq : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(1-2 HQ) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackaldesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12hq.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_hmg_g_12hq : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(1-2 HQ) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalgreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12hq.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_hmg_w_12hq : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(1-2 HQ) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalwoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12hq.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_d_12hq : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(1-2 HQ) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackaldesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12hq.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_g_12hq : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(1-2 HQ) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalgreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12hq.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_w_12hq : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(1-2 HQ) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalwoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12hq.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_d_12hq : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(1-2 HQ) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotedesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12hq.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_g_12hq : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(1-2 HQ) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotegreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12hq.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_w_12hq : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(1-2 HQ) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotewoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12hq.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_d_12hq : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(1-2 HQ) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotedesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12hq.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_g_12hq : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(1-2 HQ) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotegreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12hq.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_w_12hq : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(1-2 HQ) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotewoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12hq.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
// 1-2 A/B Jackals and Coyotes
    class 43cdo_vehicles_jackal_hmg_d_12ab : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(1-2 A/B) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackaldesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ab.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_hmg_g_12ab : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(1-2 A/B) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalgreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ab.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_hmg_w_12ab : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(1-2 A/B) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalwoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ab.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_d_12ab : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(1-2 A/B) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackaldesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ab.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_g_12ab : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(1-2 A/B) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalgreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ab.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_w_12ab : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(1-2 A/B) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalwoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ab.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_d_12ab : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(1-2 A/B) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotedesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ab.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_g_12ab : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(1-2 A/B) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotegreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ab.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_w_12ab : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(1-2 A/B) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotewoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ab.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_d_12ab : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(1-2 A/B) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotedesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ab.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_g_12ab : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(1-2 A/B) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotegreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ab.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_w_12ab : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(1-2 A/B) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotewoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ab.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
// 1-2 C/D Jackals and Coyotes
    class 43cdo_vehicles_jackal_hmg_d_12cd : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(1-2 C/D) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackaldesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12cd.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_hmg_g_12cd : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(1-2 C/D) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalgreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12cd.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_hmg_w_12cd : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(1-2 C/D) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalwoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12cd.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_d_12cd : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(1-2 C/D) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackaldesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12cd.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_g_12cd : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(1-2 C/D) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalgreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12cd.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_w_12cd : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(1-2 C/D) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalwoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12cd.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_d_12cd : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(1-2 C/D) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotedesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12cd.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_g_12cd : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(1-2 C/D) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotegreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12cd.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_w_12cd : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(1-2 C/D) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotewoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12cd.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_d_12cd : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(1-2 C/D) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotedesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12cd.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_g_12cd : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(1-2 C/D) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotegreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12cd.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_w_12cd : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(1-2 C/D) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotewoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12cd.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
// 1-2 E/F Jackals and Coyotes
    class 43cdo_vehicles_jackal_hmg_d_12ef : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(1-2 E/F) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackaldesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ef.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_hmg_g_12ef : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(1-2 E/F) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalgreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ef.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_hmg_w_12ef : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(1-2 E/F) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalwoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ef.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_d_12ef : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(1-2 E/F) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackaldesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ef.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_g_12ef : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(1-2 E/F) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalgreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ef.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_w_12ef : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(1-2 E/F) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalwoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ef.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_d_12ef : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(1-2 E/F) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotedesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ef.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_g_12ef : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(1-2 E/F) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotegreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ef.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_w_12ef : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(1-2 E/F) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotewoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ef.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_d_12ef : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(1-2 E/F) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotedesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ef.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_g_12ef : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(1-2 E/F) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotegreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ef.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_w_12ef : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(1-2 E/F) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotewoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ef.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
// 1-2 G/H Jackals and Coyotes
    class 43cdo_vehicles_jackal_hmg_d_12gh : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(1-2 G/H) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackaldesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12gh.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_hmg_g_12gh : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(1-2 G/H) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalgreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12gh.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_hmg_w_12gh : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(1-2 G/H) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalwoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12gh.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_d_12gh : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(1-2 G/H) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackaldesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12gh.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_g_12gh : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(1-2 G/H) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalgreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12gh.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_w_12gh : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(1-2 G/H) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalwoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12gh.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_d_12gh : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(1-2 G/H) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotedesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12gh.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_g_12gh : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(1-2 G/H) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotegreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12gh.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_w_12gh : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(1-2 G/H) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotewoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12gh.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_d_12gh : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(1-2 G/H) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotedesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12gh.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_g_12gh : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(1-2 G/H) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotegreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12gh.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_w_12gh : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(1-2 G/H) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotewoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12gh.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
// 1-2 I/J Jackals and Coyotes
    class 43cdo_vehicles_jackal_hmg_d_12ij : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(1-2 I/J) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackaldesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ij.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_hmg_g_12ij : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(1-2 I/J) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalgreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ij.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_hmg_w_12ij : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(1-2 I/J) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalwoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ij.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_d_12ij : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(1-2 I/J) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackaldesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ij.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_g_12ij : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(1-2 I/J) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalgreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ij.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_w_12ij : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(1-2 I/J) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalwoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ij.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_d_12ij : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(1-2 I/J) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotedesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ij.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_g_12ij : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(1-2 I/J) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotegreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ij.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_w_12ij : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(1-2 I/J) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotewoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ij.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_d_12ij : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(1-2 I/J) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotedesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ij.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_g_12ij : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(1-2 I/J) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotegreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ij.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_w_12ij : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(1-2 I/J) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotewoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ij.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_12ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
// 3-1 HQ Jackals and Coyotes
    class 43cdo_vehicles_jackal_hmg_d_31hq : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(3-1 HQ) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackaldesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31hq.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_hmg_g_31hq : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(3-1 HQ) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalgreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31hq.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_hmg_w_31hq : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(3-1 HQ) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalwoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31hq.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_d_31hq : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(3-1 HQ) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackaldesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31hq.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_g_31hq : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(3-1 HQ) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalgreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31hq.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_w_31hq : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(3-1 HQ) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalwoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31hq.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_d_31hq : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(3-1 HQ) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotedesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31hq.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_g_31hq : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(3-1 HQ) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotegreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31hq.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_w_31hq : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(3-1 HQ) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotewoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31hq.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_d_31hq : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(3-1 HQ) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotedesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31hq.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_g_31hq : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(3-1 HQ) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotegreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31hq.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_w_31hq : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(3-1 HQ) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotewoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31hq.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31hq.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
// 3-1 A/B Jackals and Coyotes
    class 43cdo_vehicles_jackal_hmg_d_31ab : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(3-1 A/B) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackaldesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ab.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_hmg_g_31ab : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(3-1 A/B) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalgreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ab.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_hmg_w_31ab : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(3-1 A/B) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalwoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ab.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_d_31ab : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(3-1 A/B) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackaldesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ab.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_g_31ab : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(3-1 A/B) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalgreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ab.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_w_31ab : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(3-1 A/B) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalwoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ab.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_d_31ab : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(3-1 A/B) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotedesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ab.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_g_31ab : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(3-1 A/B) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotegreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ab.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_w_31ab : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(3-1 A/B) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotewoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ab.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_d_31ab : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(3-1 A/B) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotedesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ab.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_g_31ab : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(3-1 A/B) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotegreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ab.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_w_31ab : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(3-1 A/B) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotewoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ab.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ab.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
// 3-1 C/D Jackals and Coyotes
    class 43cdo_vehicles_jackal_hmg_d_31cd : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(3-1 C/D) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackaldesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31cd.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_hmg_g_31cd : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(3-1 C/D) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalgreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31cd.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_hmg_w_31cd : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(3-1 C/D) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalwoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31cd.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_d_31cd : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(3-1 C/D) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackaldesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31cd.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_g_31cd : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(3-1 C/D) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalgreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31cd.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_w_31cd : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(3-1 C/D) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalwoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31cd.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_d_31cd : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(3-1 C/D) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotedesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31cd.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_g_31cd : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(3-1 C/D) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotegreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31cd.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_w_31cd : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(3-1 C/D) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotewoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31cd.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_d_31cd : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(3-1 C/D) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotedesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31cd.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_g_31cd : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(3-1 C/D) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotegreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31cd.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_w_31cd : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(3-1 C/D) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotewoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31cd.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31cd.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
// 3-1 E/F Jackals and Coyotes
    class 43cdo_vehicles_jackal_hmg_d_31ef : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(3-1 E/F) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackaldesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ef.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_hmg_g_31ef : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(3-1 E/F) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalgreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ef.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_hmg_w_31ef : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(3-1 E/F) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalwoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ef.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_d_31ef : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(3-1 E/F) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackaldesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ef.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_g_31ef : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(3-1 E/F) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalgreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ef.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_w_31ef : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(3-1 E/F) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalwoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ef.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_d_31ef : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(3-1 E/F) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotedesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ef.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_g_31ef : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(3-1 E/F) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotegreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ef.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_w_31ef : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(3-1 E/F) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotewoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ef.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_d_31ef : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(3-1 E/F) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotedesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ef.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_g_31ef : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(3-1 E/F) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotegreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ef.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_w_31ef : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(3-1 E/F) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotewoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ef.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ef.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
// 3-1 G/H Jackals and Coyotes
    class 43cdo_vehicles_jackal_hmg_d_31gh : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(3-1 G/H) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackaldesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31gh.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_hmg_g_31gh : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(3-1 G/H) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalgreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31gh.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_hmg_w_31gh : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(3-1 G/H) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalwoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31gh.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_d_31gh : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(3-1 G/H) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackaldesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31gh.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_g_31gh : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(3-1 G/H) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalgreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31gh.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_w_31gh : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(3-1 G/H) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalwoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31gh.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_d_31gh : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(3-1 G/H) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotedesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31gh.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_g_31gh : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(3-1 G/H) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotegreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31gh.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_w_31gh : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(3-1 G/H) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotewoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31gh.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_d_31gh : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(3-1 G/H) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotedesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31gh.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_g_31gh : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(3-1 G/H) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotegreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31gh.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_w_31gh : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(3-1 G/H) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotewoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31gh.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31gh.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
// 3-1 I/J Jackals and Coyotes
    class 43cdo_vehicles_jackal_hmg_d_31ij : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(3-1 I/J) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackaldesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ij.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_hmg_g_31ij : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(3-1 I/J) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalgreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ij.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_hmg_w_31ij : 43cdo_vehicles_jackal_hmg_base
    {
        displayName = "(3-1 I/J) Jackal HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalwoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ij.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_d_31ij : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(3-1 I/J) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackaldesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ij.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_g_31ij : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(3-1 I/J) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalgreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ij.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_jackal_gmg_w_31ij : 43cdo_vehicles_jackal_gmg_base
    {
        displayName = "(3-1 I/J) Jackal GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_jackalwoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ij.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_d_31ij : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(3-1 I/J) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotedesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ij.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_g_31ij : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(3-1 I/J) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotegreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ij.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_hmg_w_31ij : 43cdo_vehicles_coyote_hmg_base
    {
        displayName = "(3-1 I/J) Coyote HMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotewoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ij.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_d_31ij : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(3-1 I/J) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotedesert";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ij.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_g_31ij : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(3-1 I/J) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotegreen";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ij.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
    class 43cdo_vehicles_coyote_gmg_w_31ij : 43cdo_vehicles_coyote_gmg_base
    {
        displayName = "(3-1 I/J) Coyote GMG";
        scope = 2;
        scopeCurator = 2;
        editorSubcategory = "43cdo_faction_edsubcat_coyotewoodland";
        hiddenSelectionsTextures[] =
        {
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ij.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
            "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
            "",
            "",
            ""
        };
        class TextureSources
        {
            class Desert
            {
                displayName = "Desert";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_desert_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Green
            {
                displayName = "Green";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_green_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
            class Woodland
            {
                displayName = "Woodland";
                author = "www.3commandobrigade.com";
                textures[] =
                {
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_31ij.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_mount_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_adds_generic.paa",
                    "\43cdo_vehicles\data\jackal\43cdo_vehicles_jackal_woodland_bar_generic.paa",
                    "",
                    "",
                    ""
                };
                factions[] = {};
            };
        };
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};
    };
};