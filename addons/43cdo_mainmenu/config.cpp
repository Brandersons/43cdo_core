class CfgPatches
{
	class 43cdo_mainmenu
	{
		name="[43CDO] Main Menu";
		author="LCpl. BT";
		requiredAddons[]= 
		{
			"a3_ui_f",
			"a3_ui_f_aow",
			"a3_ui_f_enoch",
			"a3_ui_f_orange",
			"a3_ui_f_oldman",
			"a3_ui_f_tacops",
			"ef_ui"
		};
		requiredVersion= 0.01;
		units[]={};
		weapons[]={};
	};
};

class RscActivePicture;
class RscActivePictureKeepAspect;
class RscPicture;
class RscControlsGroup;
class RscControlsGroupNoScrollbars;
class RscControlsGroupNoHScrollbars;
class RscButton;
class RscButtonMenu;
class RscStandardDisplay;
class RscPictureKeepAspect;
class Background;
class RscText;
class RscStructuredText;
class RscHTML;
class RscTitle;
class RscButtonMenuOK;
class RscVideo;

class RscDisplayMain: RscStandardDisplay
{
	class controlsBackground
	{
		class menuBg: RscPictureKeepAspect
		{
			idc=201;
			text="43cdo_mainmenu\data\43cdo_mainmenu_background.jpg";
			x="safeZoneX";
			y="safeZoneY";
			w="safeZoneW";
			h="safeZoneH";
		};
	};

	class controls
	{
		// Delete unwanted vanilla buttons
		delete ModIcons;
		delete B_Quit;
		delete B_Expansions;
		delete B_Credits;
		delete B_Player;
		delete B_Options;
		delete B_SinglePlayer;
		delete B_MissionEditor;
		delete B_MultiPlayer;
		delete B_SingleMission;
		delete B_Campaign;
		delete Date;
		delete ModList;
		delete TrafficLight;
		delete Version;
		delete InfoDLCs;
		delete InfoVersion;
		delete Footer;
		delete InfoDLCsOwned;
	};
};

class CfgMainMenuSpotlight
{
	// clear spotlight of vanilla stuff
	// some don't get removed by this, keep them commented out for easy reference
	delete AoW_Showcase_AoW;
	delete AoW_Showcase_Future;
	delete ApexProtocol;
	delete BootCamp;
	delete Contact_Campaign;
	delete EastWind;
	delete EF_ResoluteCyclone;
	delete OldMan;
	//delete Orange_Campaign;
	delete Orange_CampaignGerman;
	delete Orange_Showcase_IDAP;
	delete Orange_Showcase_LoW;
	delete SP_FD14;
	//delete Tacops_Campaign_01;
	delete Tacops_Campaign_02;
	delete Tacops_Campaign_03;
	delete Tanks_Campaign_01;

	class serveroperations
	{
		text = "Operations Server";
		picture = "43cdo_core\data\red.paa";
		action = "connectToServer ['77.68.123.186', 2302, '43cdo#operations']";
		actionText = "[43CDO] Operations Server";
		condition = "true";
	};
	class servertraining
	{
		text = "Training Server";
		picture = "43cdo_core\data\green.paa";
		action = "connectToServer ['77.68.123.186', 2402, '43cdo#training']";
		actionText = "[43CDO] Training Server";
		condition = "true";
	};
	class serverevents
	{
		text = "Events Server";
		picture = "43cdo_core\data\blue.paa";
		action = "connectToServer ['77.68.123.186', 2502, '43cdo#events']";
		actionText = "[43CDO] Events Server";
		condition = "true";
	};
	class Tacops_Campaign_01
	{
		scope = 0;
		condition = false;
	};
	class Orange_Campaign
	{
		scope = 0;
		condition = false;
	};
};