// 43cdo_btab - Commander's Tablet with FBCB2 Blue Force Tracking
// Battlefield tablet to access real time intel and blue force tracker.
// By - Riouken
// http://forums.bistudio.com/member.php?64032-Riouken
// You may re-use any of this work as long as you provide credit back to me.


#define PREFIX 43cdo_btab
#define MAJOR 2
#define MINOR 3
#define PATCHLVL 0
#define BUILD 0
#define VERSION MAJOR.MINOR.PATCHLVL.BUILD
#define VERSION_AR MAJOR,MINOR,PATCHLVL,BUILD
#define VERSION_STR MAJOR.MINOR.PATCHLVL.BUILD
#define REQUIRED_VERSION 1.32
#include "script_macros_common.hpp"
#define AUTHOR "Gundy, Riouken, Raspu"


class CfgPatches
{
	class PREFIX  // 43cdo_btab
		{
			units[] = {Box_43cdo_btab_items};
			weapons[] = {Item43cdo_btab,ItemAndroid,ItemMicroDAGR,Item43cdo_btabHCam};
			requiredVersion = REQUIRED_VERSION;
			requiredAddons[] = {"CBA_MAIN"};
			versionDesc = "43cdo_btab";
			VERSION_CONFIG;
			authors[] = {"Gundy","Riouken","Raspu"};
			authorUrl = "https://github.com/Riouken/cTab";
		};
};

class CfgSettings 
{
	class CBA 
	{
		class Versioning 
		{
			class PREFIX 
			{
				main_addon = PREFIX;
				class Dependencies 
				{
					CBA[] = {"cba_main", { 1,0,0 },"true"};
				};
			};
		};
	};
};

class CfgMods {
	class PREFIX {
		dir = "@43cdo_btab";
		name = "43cdo_btab - Blue Force Tracking";
		picture = "\43cdo_btab\img\43cdo_btab_BFT_ico.paa";
		hidePicture = "True";
		hideName = "True";
		actionName = "Website";
		action = "https://github.com/Riouken/cTab";
		overview = "Commander's Tablet / FBCB2 - Blue Force Tracking\nBattlefield tablet to access real time intel and blue force tracker.";
		tooltip = "Commander's Tablet / FBCB2 - Blue Force Tracking";
		author = AUTHOR;
	};
};

#include "\43cdo_btab\CfgFunctions.h"
#include "userconfig\43cdo_btab\43cdo_btab_settings.hpp"

class Extended_PostInit_EventHandlers
{
	class PREFIX
	{
		clientInit = QUOTE(call COMPILE_FILE2(\43cdo_btab\player_init.sqf));

		serverInit = QUOTE(call COMPILE_FILE2(\43cdo_btab\server_init.sqf));
	};
};

#include "\43cdo_btab\shared\43cdo_btab_gui_macros.hpp"
#include "\43cdo_btab\shared\43cdo_btab_base_gui_classes.hpp"

#include <\43cdo_btab\tablet\43cdo_btab_Tablet_dialog.hpp>
#include <\43cdo_btab\android\43cdo_btab_android_dialog.hpp>
#include <\43cdo_btab\FBCB2\43cdo_btab_FBCB2_dialog.hpp>
#include <\43cdo_btab\TAD\43cdo_btab_TAD_dialog.hpp>
#include <\43cdo_btab\microDAGR\43cdo_btab_microDAGR_dialog.hpp>

class CfgWeapons
{	
	/*class ItemCore;
	class Item43cdo_btab_GPS: ItemCore
	{
		descriptionshort="DK10 Rugged Tablet PC (GPS)";
		descriptionuse="<t color='#9cf953'>Use: </t>Show Commander's Tablet";
		displayname="Rugged Tablet (GPS Slot)";
		picture="\43cdo_btab\img\icon_dk10.paa";
		model="\43cdo_btab\data\itemDK10.p3d";
		scope=2;
		simulation="ItemGPS";
		class ItemInfo
		{
			mass=12;
		};
		author="Gundy-Riouken-Raspu";
	};

	class ItemAndroid_GPS: Item43cdo_btab_GPS
	{
		descriptionshort="Android Tactical Assault Kit (GPS)";
		descriptionuse="<t color='#9cf953'>Use: </t>Show Android Based BFT";
		displayname="Galaxy S20 Tactical Edition (GPS Slot)";
		picture="\43cdo_btab\img\icon_Android.paa";
		model="\43cdo_btab\data\itemAndroid.p3d";
		class ItemInfo
		{
			mass=4;
		};
		author="Gundy-Riouken-Raspu";
	};
	class ItemMicroDAGR_GPS: Item43cdo_btab_GPS
	{
		descriptionshort="HNV-2930 Micro Defense Advanced GPS Receiver (GPS)";
		descriptionuse="<t color='#9cf953'>Use: </t>Show Android Based BFT";
		displayname="MicroDAGR (GPS Slot)";
		picture="\43cdo_btab\img\icon_MicroDAGR.paa";
		model="\43cdo_btab\data\itemMicroDAGR.p3d";
		class ItemInfo
		{
			mass=2;
		};
		author="Gundy-Riouken-Raspu";
	};
*/
	class CBA_MiscItem;
	class CBA_MiscItem_ItemInfo;
	class Item43cdo_btab: CBA_MiscItem
	{
		descriptionshort="DK10 Rugged Tablet PC";
		descriptionuse="<t color='#9cf953'>Use: </t>Show Commander's Tablet";
		displayname="Rugged Tablet";
		picture="\43cdo_btab\img\icon_dk10.paa";
		model="\43cdo_btab\data\itemDK10.p3d";
		scope=2;
		author="Gundy-Riouken-Raspu";
		simulation="Weapon";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=12;
		};
	};

	class ItemAndroid: Item43cdo_btab
	{
		descriptionshort="Android Tactical Assault Kit";
		descriptionuse="<t color='#9cf953'>Use: </t>Show Android Based BFT";
		displayname="Galaxy S20 Tactical Edition";
		picture="\43cdo_btab\img\icon_Android.paa";
		model="\43cdo_btab\data\itemAndroid.p3d";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=4;
		};
		author="Gundy-Riouken-Raspu";
	};

	class ItemMicroDAGR: Item43cdo_btab
	{
		descriptionshort="HNV-2930 Micro Defense Advanced GPS Receiver";
		descriptionuse="<t color='#9cf953'>Use: </t>Show Android Based BFT";
		displayname="MicroDAGR";
		picture="\43cdo_btab\img\icon_MicroDAGR.paa";
		model="\43cdo_btab\data\itemMicroDAGR.p3d";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=2;
		};
		author="Gundy-Riouken-Raspu";
	};

	class Item43cdo_btabHCam: CBA_MiscItem
	{
		descriptionshort = "HD Helmet Mounted Camera";
		descriptionuse = "<t color='#9cf953'>Use: </t>Used to record and stream video";
		displayname = "Helmet Camera";
		picture = "\43cdo_btab\img\43cdo_btab_helmetCam_ico.paa";
		scope = 2;
		author="Gundy-Riouken-Raspu";
		simulation = "Weapon";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=2;
		};
	};
};

class CfgNotifications
{
	
	class 43cdo_btabUavNotAval
	{
		title = "43cdo_btab";
		iconPicture = "\43cdo_btab\img\15th_rugged_tab_ico.paa";
		iconText = "";
		color[] = {1,1,1,1};
		description = "%1";
		duration = 5;
		priority = 7;
		difficulty[] = {};
	};
	
	class 43cdo_btabNewMsg
	{
		title = "43cdo_btab";
		iconPicture = "\43cdo_btab\img\icoUnopenedmail.paa";
		iconText = "";
		color[] = {1,1,1,1};
		description = "%1";
		duration = 4;
		priority = 7;
		difficulty[] = {};
	};

	class 43cdo_btabMsgSent
	{
		title = "43cdo_btab";
		iconPicture = "\43cdo_btab\img\icoUnopenedmail.paa";
		iconText = "";
		color[] = {1,1,1,1};
		description = "Your message has been sent.";
		duration = 4;
		priority = 7;
		difficulty[] = {};
	};	

};

class RscTitles
{
	titles[]={};
	#include "\43cdo_btab\shared\43cdo_btab_mapSize_title.hpp"
	#include "\43cdo_btab\shared\43cdo_btab_mail_title.hpp"
	#include <\43cdo_btab\TAD\43cdo_btab_TAD_display.hpp>
	#include <\43cdo_btab\microDAGR\43cdo_btab_microDAGR_display.hpp>
	#include <\43cdo_btab\android\43cdo_btab_android_display.hpp>
};


class CfgVehicles
{

	class Box_NATO_WpsSpecial_F;
	class Box_43cdo_btab_items : Box_NATO_WpsSpecial_F {
		displayname = "[43cdo_btab] Computer Gear";
		icon = "iconCrateLarge";
		model = "\A3\weapons_F\AmmoBoxes\WpnsBox_large_F";
		scope = 2;
		transportmaxmagazines = 64;
		transportmaxweapons = 12;

		class TransportItems {
			class _xx_Item43cdo_btab {
				count = 5;
				name = "Item43cdo_btab";
			};
			class _xx_ItemAndroid {
				count = 15;
				name = "ItemAndroid";
			};
			class _xx_ItemMicroDAGR {
				count = 25;
				name = "ItemMicroDAGR";
			};
			class _xx_Item43cdo_btabHCam {
				count = 25;
				name = "Item43cdo_btabHCam";
			};
		};
	
	
		class TransportMagazines {};
		class TransportWeapons {};
	
	};
	
};

class CfgSounds
{
	sounds[] = {};
	class 43cdo_btab_phoneVibrate
	{
		// filename, volume, pitch
		sound[] = {"\43cdo_btab\sounds\phoneVibrate.wss",1,1};
		// subtitle delay in seconds, subtitle text 
		titles[] = {};
	};
	class 43cdo_btab_mailSent
	{
		sound[] = {"\43cdo_btab\sounds\mailSent.wss",1,1};
		titles[] = {};
	};
};
