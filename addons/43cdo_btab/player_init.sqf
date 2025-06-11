// 43cdo_btab - Commander's Tablet with FBCB2 Blue Force Tracking
// Battlefield tablet to access real time intel and blue force tracker.
// By - Riouken
// http://forums.bistudio.com/member.php?64032-Riouken
// You may re-use any of this work as long as you provide credit back to me.

// keys.sqf parses the userconfig
#include "functions\keys.sqf"
#include "\43cdo_btab\shared\43cdo_btab_gui_macros.hpp"

// Exit if this is machine has no interface, i.e. is a headless client (HC)
if (!hasInterface) exitWith {};

// Get a rsc layer for for our displays
43cdo_btabRscLayer = ["43cdo_btab"] call BIS_fnc_rscLayer;
43cdo_btabRscLayerMailNotification = ["43cdo_btab_mailNotification"] call BIS_fnc_rscLayer;

// Set up user markers
43cdo_btab_userMarkerTransactionId = -1;
43cdo_btab_userMarkerLists = [];
[] call 43cdo_btab_fnc_getUserMarkerList;

// Initialize CBA settings for separated squad markers
call 43cdo_btab_fnc_initSquadSeparationSettings;

// Initialize default values for separated squad markers in case CBA settings aren't ready yet
// Android device defaults
if (isNil "43cdo_btab_Android_separatedSquadMarkersEnabled") then {43cdo_btab_Android_separatedSquadMarkersEnabled = true;};
if (isNil "43cdo_btab_Android_separationDistance") then {43cdo_btab_Android_separationDistance = 200;};

// MicroDAGR device defaults
if (isNil "43cdo_btab_MicroDAGR_separatedSquadMarkersEnabled") then {43cdo_btab_MicroDAGR_separatedSquadMarkersEnabled = true;};
if (isNil "43cdo_btab_MicroDAGR_separationDistance") then {43cdo_btab_MicroDAGR_separationDistance = 200;};

// Tablet device defaults
if (isNil "43cdo_btab_Tablet_separatedSquadMarkersEnabled") then {43cdo_btab_Tablet_separatedSquadMarkersEnabled = true;};
if (isNil "43cdo_btab_Tablet_separationDistance") then {43cdo_btab_Tablet_separationDistance = 200;};

// Set up side specific encryption keys
if (isNil "43cdo_btab_encryptionKey_west") then {
	43cdo_btab_encryptionKey_west = "b";
};
if (isNil "43cdo_btab_encryptionKey_east") then {
	43cdo_btab_encryptionKey_east = "o";
};
if (isNil "43cdo_btab_encryptionKey_guer") then {
	43cdo_btab_encryptionKey_guer = call {
		if (([west,resistance] call BIS_fnc_areFriendly) and {!([east,resistance] call BIS_fnc_areFriendly)}) exitWith {
			"b"
		};
		if (([east,resistance] call BIS_fnc_areFriendly) and {!([west,resistance] call BIS_fnc_areFriendly)}) exitWith {
			"o"
		};
		"i"
	};
};
if (isNil "43cdo_btab_encryptionKey_civ") then {
	43cdo_btab_encryptionKey_civ = "c";
};

// Set up empty lists
43cdo_btabBFTmembers = [];
43cdo_btabBFTgroups = [];
43cdo_btabBFTvehicles = [];
43cdo_btabBFTseparated = [];
43cdo_btabUAVlist = [];
43cdo_btabHcamlist = [];
43cdo_btabNotificationCache = [];

// set current player object in 43cdo_btab_player and run a check on every frame to see if there is a change
43cdo_btab_player = objNull;
["43cdo_btab_checkForPlayerChange", "onEachFrame", {
	if !(43cdo_btab_player isEqualTo (missionNamespace getVariable ["BIS_fnc_moduleRemoteControl_unit",player])) then {
		43cdo_btab_player = missionNamespace getVariable ["BIS_fnc_moduleRemoteControl_unit",player];
		// close any interface that might still be open
		call 43cdo_btab_fnc_close;
		//prep the arrays that will hold 43cdo_btab data
		43cdo_btabBFTmembers = [];
		43cdo_btabBFTgroups = [];
		43cdo_btabBFTvehicles = [];
		43cdo_btabBFTseparated = [];
		43cdo_btabUAVlist = [];
		43cdo_btabHcamlist = [];
		call 43cdo_btab_fnc_updateLists;
		call 43cdo_btab_fnc_updateUserMarkerList;
		// remove msg notification
		43cdo_btabRscLayerMailNotification cutText ["", "PLAIN"];
	};
}] call BIS_fnc_addStackedEventHandler;

/*
Figure out the scaling factor based on the current map (island) being played
Requires the scale of the map control to be at 0.001
*/
call {
	private ["_displayName","_display","_mapCtrl","_mapScreenPos","_mapScreenX_left","_mapScreenH","_mapScreenY_top","_mapScreenY_middle","_mapWorldY_top","_mapWorldY_middle"];
	
	_displayName = "43cdo_btab_mapSize_dsp";
	43cdo_btabRscLayer cutRsc [_displayName,"PLAIN",0, false];
	while {isNull (uiNamespace getVariable _displayName)} do {};
	_display = uiNamespace getVariable _displayName;
	_mapCtrl = _display displayCtrl 1110;

	// get the screen postition of _mapCtrl as [x, y, w, h]
	_mapScreenPos = ctrlPosition _mapCtrl;

	// Find the screen coordinate for the left side
	_mapScreenX_left = _mapScreenPos select 0;
	// Find the screen height
	_mapScreenH	= _mapScreenPos select 3;
	// Find the screen coordinate for top Y 
	_mapScreenY_top = _mapScreenPos select 1;
	// Find the screen coordinate for middle Y 
	_mapScreenY_middle = _mapScreenY_top + _mapScreenH / 2;

	// Get world coordinate for top Y in meters
	_mapWorldY_top = (_mapCtrl ctrlMapScreenToWorld [_mapScreenX_left,_mapScreenY_top]) select 1;
	// Get world coordinate for middle Y in meters
	_mapWorldY_middle = (_mapCtrl ctrlMapScreenToWorld [_mapScreenX_left,_mapScreenY_middle]) select 1;

	// calculate the difference between top and middle world coordinates, devide by the screen height and return
	43cdo_btabMapScaleFactor = (abs(_mapWorldY_middle - _mapWorldY_top)) / _mapScreenH;

	_display closeDisplay 0;
	uiNamespace setVariable [_displayName, displayNull];
};

43cdo_btabMapScaleUAV = 0.8 / 43cdo_btabMapScaleFactor;
43cdo_btabMapScaleHCam = 0.3 / 43cdo_btabMapScaleFactor;

43cdo_btabDisplayPropertyGroups = [
	["43cdo_btab_Tablet_dlg","Tablet"],
	["43cdo_btab_Android_dlg","Android"],
	["43cdo_btab_Android_dsp","Android"],
	["43cdo_btab_FBCB2_dlg","FBCB2"],
	["43cdo_btab_TAD_dsp","TAD"],
	["43cdo_btab_TAD_dlg","TAD"],
	["43cdo_btab_microDAGR_dsp","MicroDAGR"],
	["43cdo_btab_microDAGR_dlg","MicroDAGR"]
];

43cdo_btabSettings = [];

[43cdo_btabSettings,"COMMON",[
	["mode","BFT"],
	["mapScaleMin",0.1],
	["mapScaleMax",2 ^ round(sqrt(2666 * 43cdo_btabMapScaleFactor / 1024))]
]] call BIS_fnc_setToPairs;

[43cdo_btabSettings,"Main",[
]] call BIS_fnc_setToPairs;

[43cdo_btabSettings,"Tablet",[
	["dlgIfPosition",[]],
	["mode","DESKTOP"],
	["showIconText",true],
	["mapWorldPos",[]],
	["mapScaleDsp",2],
	["mapScaleDlg",2],
	["mapTypes",[["SAT",IDC_CTAB_SCREEN],["TOPO",IDC_CTAB_SCREEN_TOPO]]],
	["mapType","SAT"],
	["uavCam",""],
	["hCam",""],
	["mapTools",true],
	["nightMode",2],
	["brightness",0.9]
]] call BIS_fnc_setToPairs;

[43cdo_btabSettings,"Android",[
	["dlgIfPosition",[]],
	["dspIfPosition",false],
	["mode","BFT"],
	["showIconText",true],
	["mapWorldPos",[]],
	["mapScaleDsp",0.4],
	["mapScaleDlg",0.4],
	["mapTypes",[["SAT",IDC_CTAB_SCREEN],["TOPO",IDC_CTAB_SCREEN_TOPO]]],
	["mapType","SAT"],
	["showMenu",false],
	["mapTools",true],
	["nightMode",2],
	["brightness",0.9]
]] call BIS_fnc_setToPairs;

[43cdo_btabSettings,"FBCB2",[
	["dlgIfPosition",[]],
	["mapWorldPos",[]],
	["showIconText",true],
	["mapScaleDsp",2],
	["mapScaleDlg",2],
	["mapTypes",[["SAT",IDC_CTAB_SCREEN],["TOPO",IDC_CTAB_SCREEN_TOPO]]],
	["mapType","SAT"],
	["mapTools",true]
]] call BIS_fnc_setToPairs;

/*
TAD setup
*/
// set icon size of own vehicle on TAD
43cdo_btabTADownIconBaseSize = 18;
43cdo_btabTADownIconScaledSize = 43cdo_btabTADownIconBaseSize / (0.86 / (safezoneH * 0.8));
// set TAD font colour to neon green
43cdo_btabTADfontColour = [57/255, 255/255, 20/255, 1];
// set TAD group colour to purple
43cdo_btabTADgroupColour = [255/255, 0/255, 255/255, 1];
// set TAD highlight colour to neon yellow
43cdo_btabTADhighlightColour = [243/255, 243/255, 21/255, 1];

[43cdo_btabSettings,"TAD",[
	["dlgIfPosition",[]],
	["dspIfPosition",false],
	["mapWorldPos",[]],
	["showIconText",true],
	["mapScaleDsp",2],
	["mapScaleDlg",2],
	["mapScaleMin",1],
	["mapTypes",[["SAT",IDC_CTAB_SCREEN],["TOPO",IDC_CTAB_SCREEN_TOPO],["BLK",IDC_CTAB_SCREEN_BLACK]]],
	["mapType","SAT"],
	["mapTools",true],
	["nightMode",0],
	["brightness",0.8]
]] call BIS_fnc_setToPairs;

/*
microDAGR setup
*/
// set MicroDAGR font colour to neon green
43cdo_btabMicroDAGRfontColour = [57/255, 255/255, 20/255, 1];
// set MicroDAGR group colour to purple
43cdo_btabMicroDAGRgroupColour = [25/255, 25/255, 112/255, 1];
// set MicroDAGR highlight colour to neon yellow
43cdo_btabMicroDAGRhighlightColour = [243/255, 243/255, 21/255, 1];

[43cdo_btabSettings,"MicroDAGR",[
	["dlgIfPosition",[]],
	["dspIfPosition",false],
	["mapWorldPos",[]],
	["showIconText",true],
	["mapScaleDsp",0.4],
	["mapScaleDlg",0.4],
	["mapTypes",[["SAT",IDC_CTAB_SCREEN],["TOPO",IDC_CTAB_SCREEN_TOPO]]],
	["mapType","SAT"],
	["mapTools",true],
	["nightMode",2],
	["brightness",0.9]
]] call BIS_fnc_setToPairs;

// set base colors from BI -- Helps keep colors matching if user changes colors in options.
_r = profilenamespace getvariable ['Map_BLUFOR_R',0];
_g = profilenamespace getvariable ['Map_BLUFOR_G',0.8];
_b = profilenamespace getvariable ['Map_BLUFOR_B',1];
_a = profilenamespace getvariable ['Map_BLUFOR_A',0.8];
43cdo_btabColorBlue = [_r,_g,_b,_a];

_r = profilenamespace getvariable ['Map_OPFOR_R',0];
_g = profilenamespace getvariable ['Map_OPFOR_G',1];
_b = profilenamespace getvariable ['Map_OPFOR_B',1];
_a = profilenamespace getvariable ['Map_OPFOR_A',0.8];
43cdo_btabColorRed = [_r,_g,_b,_a];

_r = profilenamespace getvariable ['Map_Independent_R',0];
_g = profilenamespace getvariable ['Map_Independent_G',1];
_b = profilenamespace getvariable ['Map_Independent_B',1];
_a = profilenamespace getvariable ['Map_OPFOR_A',0.8];
43cdo_btabColorGreen = [_r,_g,_b,_a];

// Define Fire-Team colors
// MAIN,RED,GREEN,BLUE,YELLOW
43cdo_btabColorTeam = [43cdo_btabColorBlue,[200/255,0,0,0.8],[0,199/255,0,0.8],[0,0,200/255,0.8],[225/255,225/255,0,0.8]];

// define vehicles that have FBCB2 monitor
if (isNil "43cdo_btab_vehicleClass_has_FBCB2") then {
	if (!isNil "43cdo_btab_vehicleClass_has_FBCB2_server") then {
		43cdo_btab_vehicleClass_has_FBCB2 = 43cdo_btab_vehicleClass_has_FBCB2_server;
	} else {
		43cdo_btab_vehicleClass_has_FBCB2 = ["MRAP_01_base_F","MRAP_02_base_F","MRAP_03_base_F","Wheeled_APC_F","Tank","Truck_01_base_F","Truck_03_base_F", "DEVAS_MEKO200TN", "DEVAS_Type209"];
	};
};
// strip list of invalid config names and duplicates to save time checking through them later
_classNames = [];
{
	if (isClass (configfile >> "CfgVehicles" >> _x) && _classNames find _x == -1) then {
		0 = _classNames pushBack _x;
	};
} count 43cdo_btab_vehicleClass_has_FBCB2;
43cdo_btab_vehicleClass_has_FBCB2 = [] + _classNames;

// define vehicles that have TAD
if (isNil "43cdo_btab_vehicleClass_has_TAD") then {
	if (!isNil "43cdo_btab_vehicleClass_has_TAD_server") then {
		43cdo_btab_vehicleClass_has_TAD = 43cdo_btab_vehicleClass_has_TAD_server;
	} else {
		43cdo_btab_vehicleClass_has_TAD = ["Helicopter","Plane"];
	};
};
// strip list of invalid config names and duplicates to save time checking through them later
_classNames = [];
{
	if (isClass (configfile >> "CfgVehicles" >> _x) && _classNames find _x == -1) then {
		0 = _classNames pushBack _x;
	};
} count 43cdo_btab_vehicleClass_has_TAD;
43cdo_btab_vehicleClass_has_TAD = [] + _classNames;

// define items that enable head cam
if (isNil "43cdo_btab_helmetClass_has_HCam") then {
	if (!isNil "43cdo_btab_helmetClass_has_HCam_server") then {
		43cdo_btab_helmetClass_has_HCam = 43cdo_btab_helmetClass_has_HCam_server;
	} else {
		43cdo_btab_helmetClass_has_HCam = ["H_HelmetB_light","H_Helmet_Kerry","H_HelmetSpecB","H_HelmetO_ocamo","BWA3_OpsCore_Fleck_Camera","BWA3_OpsCore_Schwarz_Camera","BWA3_OpsCore_Tropen_Camera"
	,"rhsusf_opscore_ut_pelt_nsw_cam","rhsusf_opscore_paint_pelt_nsw_cam","rhsusf_opscore_mc_cover_pelt_cam","rhsusf_opscore_fg_pelt_cam","rhsusf_opscore_ut_pelt_cam"];
	};
};
// strip list of invalid config names and duplicates to save time checking through them later
_classNames = [];
{
	if (isClass (configfile >> "CfgWeapons" >> _x) && _classNames find _x == -1) then {
		0 = _classNames pushBack _x;
	};
} count 43cdo_btab_helmetClass_has_HCam;
// iterate through all class names and add child classes, so we end up with a list of helmet classes that have the defined helmet classes as parents
{
	_childClasses = "inheritsFrom _x == (configfile >> 'CfgWeapons' >> '" + _x + "')" configClasses (configfile >> "CfgWeapons");
	{
		_childClassName = configName _x;
		if (_classNames find _childClassName == -1) then {
			0 = _classNames pushBack configName _x;
		};
	} count _childClasses;
} forEach _classNames;
43cdo_btab_helmetClass_has_HCam = [] + _classNames;

// add 43cdo_btab_updatePulse event handler triggered periodically by the server
["43cdo_btab_updatePulse",43cdo_btab_fnc_updateLists] call CBA_fnc_addEventHandler;

// fnc to set various text and icon sizes
43cdo_btab_fnc_update_txt_size = {
	43cdo_btabIconSize = 43cdo_btabTxtFctr * 2;
	43cdo_btabIconManSize = 43cdo_btabIconSize * 0.75;
	43cdo_btabGroupOverlayIconSize = 43cdo_btabIconSize * 1.625;
	43cdo_btabUserMarkerArrowSize = 43cdo_btabTxtFctr * 8 * 43cdo_btabMapScaleFactor;
	43cdo_btabTxtSize = 43cdo_btabTxtFctr / 12 * 0.035;
	43cdo_btabAirContactGroupTxtSize = 43cdo_btabTxtFctr / 12 * 0.060;
	43cdo_btabAirContactSize = 43cdo_btabTxtFctr / 12 * 32;
	43cdo_btabAirContactDummySize = 43cdo_btabTxtFctr / 12 * 20;
};
// Beginning text and icon size
43cdo_btabTxtFctr = 12;
call 43cdo_btab_fnc_update_txt_size;
43cdo_btabBFTtxt = true;

// Draw Map Tolls (Hook)
43cdo_btabDrawMapTools = false;

// Base defines.
43cdo_btabUavViewActive = false;
43cdo_btabUAVcams = [];
43cdo_btabCursorOnMap = false;
43cdo_btabMapCursorPos = [0,0];
43cdo_btabMapWorldPos = [];
43cdo_btabMapScale = 0.5;

// Initialize all uiNamespace variables
uiNamespace setVariable ["43cdo_btab_Tablet_dlg", displayNull];
uiNamespace setVariable ["43cdo_btab_Android_dlg", displayNull];
uiNamespace setVariable ["43cdo_btab_Android_dsp", displayNull];
uiNamespace setVariable ["43cdo_btab_FBCB2_dlg", displayNull];
uiNamespace setVariable ["43cdo_btab_TAD_dsp", displayNull];
uiNamespace setVariable ["43cdo_btab_TAD_dlg", displayNull];
uiNamespace setVariable ["43cdo_btab_microDAGR_dsp", displayNull];
uiNamespace setVariable ["43cdo_btab_microDAGR_dlg", displayNull];

// Set up the array that will hold text messages.
player setVariable ["ctab_messages",[]];

// 43cdo_btabIfOpenStart will be set to true while interface is starting and prevent further open attempts
43cdo_btabIfOpenStart = false;

/*
Function handling IF_Main keydown event
Based on player equipment and the vehicle type he might be in, open or close a 43cdo_btab device as Main interface.
No Parameters
Returns TRUE when action was taken (interface opened or closed)
Returns FALSE when no action was taken (i.e. player has no 43cdo_btab device / is not in 43cdo_btab enabled vehicle)
*/
43cdo_btab_fnc_onIfMainPressed = {
	if (43cdo_btabIfOpenStart) exitWith {false};
	_previousInterface = "";
	if (43cdo_btabUavViewActive) exitWith {
		objNull remoteControl (gunner 43cdo_btabActUav);
		vehicle 43cdo_btab_player switchCamera 'internal';
		43cdo_btabUavViewActive = false;
		call 43cdo_btab_fnc_onIfTertiaryPressed;
		true
	};
	if (!isNil "43cdo_btabIfOpen" && {43cdo_btabIfOpen select 0 == 0}) exitWith {
		// close Main
		call 43cdo_btab_fnc_close;
		true
	};
	if !(isNil "43cdo_btabIfOpen") then {
		_previousInterface = 43cdo_btabIfOpen select 1;
		// close Secondary / Tertiary
		call 43cdo_btab_fnc_close;
	};
	
	_player = 43cdo_btab_player;
	_vehicle = vehicle _player;
	_interfaceName = call {
		if ([_player,_vehicle,"TAD"] call 43cdo_btab_fnc_unitInEnabledVehicleSeat) exitWith {
			43cdo_btabPlayerVehicleIcon = getText (configFile/"CfgVehicles"/typeOf _vehicle/"Icon");
			"43cdo_btab_TAD_dsp"
		};
		if ([_player,["ItemAndroid"]] call 43cdo_btab_fnc_checkGear) exitWith {"43cdo_btab_Android_dsp"};
		if ([_player,["ItemMicroDAGR"]] call 43cdo_btab_fnc_checkGear) exitWith {
			43cdo_btabMicroDAGRmode = if ([_player,["ItemcTab"]] call 43cdo_btab_fnc_checkGear) then {0} else {2};
			"43cdo_btab_microDAGR_dsp"
		};
		if ([_player,_vehicle,"FBCB2"] call 43cdo_btab_fnc_unitInEnabledVehicleSeat) exitWith {"43cdo_btab_FBCB2_dlg"};
		if ([_player,["ItemcTab"]] call 43cdo_btab_fnc_checkGear) exitWith {"43cdo_btab_Tablet_dlg"};
		// default
		""
	};
	
	if (_interfaceName != "" && _interfaceName != _previousInterface) exitWith {
		// queue the start up of the interface as we might still have one closing down
		[{
			if (isNil "43cdo_btabIfOpen") then {
				[_this select 1] call CBA_fnc_removePerFrameHandler;
				(_this select 0) call 43cdo_btab_fnc_open;
			};
		},0,[0,_interfaceName,_player,_vehicle]] call CBA_fnc_addPerFrameHandler;
		true
	};
	
	false
};

/*
Function handling IF_Secondary keydown event
Based on player equipment and the vehicle type he might be in, open or close a 43cdo_btab device as Secondary interface.
No Parameters
Returns TRUE when action was taken (interface opened or closed)
Returns FALSE when no action was taken (i.e. player has no 43cdo_btab device / is not in 43cdo_btab enabled vehicle)
*/
43cdo_btab_fnc_onIfSecondaryPressed = {
	if (43cdo_btabIfOpenStart) exitWith {false};
	_previousInterface = "";
	if (43cdo_btabUavViewActive) exitWith {
		objNull remoteControl (gunner 43cdo_btabActUav);
		vehicle 43cdo_btab_player switchCamera 'internal';
		43cdo_btabUavViewActive = false;
		call 43cdo_btab_fnc_onIfTertiaryPressed;
		true
	};
	if (!isNil "43cdo_btabIfOpen" && {43cdo_btabIfOpen select 0 == 1}) exitWith {
		// close Secondary
		call 43cdo_btab_fnc_close;
		true
	};
	if !(isNil "43cdo_btabIfOpen") then {
		_previousInterface = 43cdo_btabIfOpen select 1;
		// close Main / Tertiary
		call 43cdo_btab_fnc_close;
	};
	
	_player = 43cdo_btab_player;
	_vehicle = vehicle _player;
	_interfaceName = call {
		if ([_player,_vehicle,"TAD"] call 43cdo_btab_fnc_unitInEnabledVehicleSeat) exitWith {
			43cdo_btabPlayerVehicleIcon = getText (configFile/"CfgVehicles"/typeOf _vehicle/"Icon");
			"43cdo_btab_TAD_dlg"
		};
		if ([_player,_vehicle,"FBCB2"] call 43cdo_btab_fnc_unitInEnabledVehicleSeat) exitWith {"43cdo_btab_FBCB2_dlg"};
		if ([_player,["ItemAndroid"]] call 43cdo_btab_fnc_checkGear) exitWith {"43cdo_btab_Android_dlg"};
		if ([_player,["ItemMicroDAGR"]] call 43cdo_btab_fnc_checkGear) exitWith {
			43cdo_btabMicroDAGRmode = if ([_player,["ItemcTab"]] call 43cdo_btab_fnc_checkGear) then {0} else {2};
			"43cdo_btab_microDAGR_dlg"
		};
		if ([_player,["ItemcTab"]] call 43cdo_btab_fnc_checkGear) exitWith {"43cdo_btab_Tablet_dlg"};
		// default
		""
	};
	
	if (_interfaceName != "" && _interfaceName != _previousInterface) exitWith {
		// queue the start up of the interface as we might still have one closing down
		[{
			if (isNil "43cdo_btabIfOpen") then {
				[_this select 1] call CBA_fnc_removePerFrameHandler;
				(_this select 0) call 43cdo_btab_fnc_open;
			};
		},0,[1,_interfaceName,_player,_vehicle]] call CBA_fnc_addPerFrameHandler;
		true
	};
	
	false
};

/*
Function handling IF_Tertiary keydown event
Based on player equipment and the vehicle type he might be in, open or close a 43cdo_btab device as Tertiary interface.
No Parameters
Returns TRUE when action was taken (interface opened or closed)
Returns FALSE when no action was taken (i.e. player has no 43cdo_btab device / is not in 43cdo_btab enabled vehicle)
*/
43cdo_btab_fnc_onIfTertiaryPressed = {
	if (43cdo_btabIfOpenStart) exitWith {false};
	_previousInterface = "";
	if (43cdo_btabUavViewActive) then {
		objNull remoteControl (gunner 43cdo_btabActUav);
		vehicle 43cdo_btab_player switchCamera 'internal';
		43cdo_btabUavViewActive = false;
		true
	};
	if (!isNil "43cdo_btabIfOpen" && {43cdo_btabIfOpen select 0 == 2}) exitWith {
		// close Tertiary
		call 43cdo_btab_fnc_close;
		true
	};
	if !(isNil "43cdo_btabIfOpen") then {
		_previousInterface = 43cdo_btabIfOpen select 1;
		// close Main / Secondary
		call 43cdo_btab_fnc_close;
	};
	
	_player = 43cdo_btab_player;
	_vehicle = vehicle _player;
	_interfaceName = call {
		if ([_player,["ItemcTab"]] call 43cdo_btab_fnc_checkGear) exitWith {"43cdo_btab_Tablet_dlg"};
		if ([_player,["ItemAndroid"]] call 43cdo_btab_fnc_checkGear) exitWith {"43cdo_btab_Android_dlg"};
		if ([_player,["ItemMicroDAGR"]] call 43cdo_btab_fnc_checkGear) exitWith {
			43cdo_btabMicroDAGRmode = if ([_player,["ItemcTab"]] call 43cdo_btab_fnc_checkGear) then {0} else {2};
			"43cdo_btab_microDAGR_dlg"
		};
		if ([_player,_vehicle,"TAD"] call 43cdo_btab_fnc_unitInEnabledVehicleSeat) exitWith {
			43cdo_btabPlayerVehicleIcon = getText (configFile/"CfgVehicles"/typeOf _vehicle/"Icon");
			"43cdo_btab_TAD_dlg"
		};
		if ([_player,_vehicle,"FBCB2"] call 43cdo_btab_fnc_unitInEnabledVehicleSeat) exitWith {"43cdo_btab_FBCB2_dlg"};
		// default
		""
	};
	
	if (_interfaceName != "" && _interfaceName != _previousInterface) exitWith {
		// queue the start up of the interface as we might still have one closing down
		[{
			if (isNil "43cdo_btabIfOpen") then {
				[_this select 1] call CBA_fnc_removePerFrameHandler;
				(_this select 0) call 43cdo_btab_fnc_open;
			};
		},0,[2,_interfaceName,_player,_vehicle]] call CBA_fnc_addPerFrameHandler;
		true
	};
	
	false
};

/*
Function handling Zoom_In keydown event
If supported 43cdo_btab interface is visible, decrease map scale
Returns TRUE when action was taken
Returns FALSE when no action was taken (i.e. no interface open, or unsupported interface)
*/
43cdo_btab_fnc_onZoomInPressed = {
	if (43cdo_btabIfOpenStart || (isNil "43cdo_btabIfOpen")) exitWith {false};
	_displayName = 43cdo_btabIfOpen select 1;
	if !([_displayName] call 43cdo_btab_fnc_isDialog) exitWith {
		_mapScale = ([_displayName,"mapScaleDsp"] call 43cdo_btab_fnc_getSettings) / 2;
		_mapScaleMin = [_displayName,"mapScaleMin"] call 43cdo_btab_fnc_getSettings;
		if (_mapScale < _mapScaleMin) then {
			_mapScale = _mapScaleMin;
		};
		_mapScale = [_displayName,[["mapScaleDsp",_mapScale]]] call 43cdo_btab_fnc_setSettings;
		true
	};
	false
};

/*
Function handling Zoom_Out keydown event
If supported 43cdo_btab interface is visible, increase map scale
Returns TRUE when action was taken
Returns FALSE when no action was taken (i.e. no interface open, or unsupported interface)
*/
43cdo_btab_fnc_onZoomOutPressed = {
	if (43cdo_btabIfOpenStart || (isNil "43cdo_btabIfOpen")) exitWith {false};
	_displayName = 43cdo_btabIfOpen select 1;
	if !([_displayName] call 43cdo_btab_fnc_isDialog) exitWith {
		_mapScale = ([_displayName,"mapScaleDsp"] call 43cdo_btab_fnc_getSettings) * 2;
		_mapScaleMax = [_displayName,"mapScaleMax"] call 43cdo_btab_fnc_getSettings;
		if (_mapScale > _mapScaleMax) then {
			_mapScale = _mapScaleMax;
		};
		_mapScale = [_displayName,[["mapScaleDsp",_mapScale]]] call 43cdo_btab_fnc_setSettings;
		true
	};
	false
};

/*
Function to toggle text next to BFT icons
Parameter 0: String of uiNamespace variable for which to toggle showIconText for
Returns TRUE
*/
43cdo_btab_fnc_iconText_toggle = {
	_displayName = _this select 0;
	if (43cdo_btabBFTtxt) then {43cdo_btabBFTtxt = false} else {43cdo_btabBFTtxt = true};
	[_displayName,[["showIconText",43cdo_btabBFTtxt]]] call 43cdo_btab_fnc_setSettings;
	true
};

/*
Function to toggle mapType to the next one in the list of available map types
Parameter 0: String of uiNamespace variable for which to toggle to mapType for
Returns TRUE
*/
43cdo_btab_fnc_mapType_toggle = {
	_displayName = _this select 0;
	_mapTypes = [_displayName,"mapTypes"] call 43cdo_btab_fnc_getSettings;
	_currentMapType = [_displayName,"mapType"] call 43cdo_btab_fnc_getSettings;
	_currentMapTypeIndex = [_mapTypes,_currentMapType] call BIS_fnc_findInPairs;
	if (_currentMapTypeIndex == count _mapTypes - 1) then {
		[_displayName,[["mapType",_mapTypes select 0 select 0]]] call 43cdo_btab_fnc_setSettings;
	} else {
		[_displayName,[["mapType",_mapTypes select (_currentMapTypeIndex + 1) select 0]]] call 43cdo_btab_fnc_setSettings;
	};
	true
};

/*
Function to toggle showMenu
Parameter 0: String of uiNamespace variable for which to toggle showMenu for
Returns TRUE
*/
43cdo_btab_fnc_showMenu_toggle = {
	_displayName = _this select 0;
	_showMenu = [_displayName,"showMenu"] call 43cdo_btab_fnc_getSettings;
	_showMenu = !_showMenu;
	[_displayName,[["showMenu",_showMenu]]] call 43cdo_btab_fnc_setSettings;
	true
};

/*
Function to toggle mode
Parameter 0: String of uiNamespace variable for which to toggle mode for
Returns TRUE
*/
43cdo_btab_fnc_mode_toggle = {
	_displayName = _this select 0;
	_mode = [_displayName,"mode"] call 43cdo_btab_fnc_getSettings;
	
	call {
		if (_displayName == "43cdo_btab_Android_dlg") exitWith {
			call {
				if (_mode != "BFT") exitWith {_mode = "BFT"};
				_mode = "MESSAGE";
			};
		};
	};
	[_displayName,[["mode",_mode]]] call 43cdo_btab_fnc_setSettings;
	true
};

/*
Function to toggle night mode
Parameter 0: String of uiNamespace variable for which to toggle nightMode for
Returns TRUE
*/
43cdo_btab_fnc_toggleNightMode = {
	_displayName = _this select 0;
	_nightMode = [_displayName,"nightMode"] call 43cdo_btab_fnc_getSettings;
	
	if (_nightMode != 2) then {
		if (_nightMode == 0) then {_nightMode = 1} else {_nightMode = 0};
		[_displayName,[["nightMode",_nightMode]]] call 43cdo_btab_fnc_setSettings;
	};
	
	true
};

/*
Function to increase brightness
Parameter 0: String of uiNamespace variable for which to increase brightness for
Returns TRUE
*/
43cdo_btab_fnc_incBrightness = {
	_displayName = _this select 0;
	_brightness = [_displayName,"brightness"] call 43cdo_btab_fnc_getSettings;
	_brightness = _brightness + 0.1;
	// make sure brightness is not larger than 1
	if (_brightness > 1) then {_brightness = 1};
	[_displayName,[["brightness",_brightness]]] call 43cdo_btab_fnc_setSettings;
	
	true
};

/*
Function to decrease brightness
Parameter 0: String of uiNamespace variable for which to decreas brightness for
Returns TRUE
*/
43cdo_btab_fnc_decBrightness = {
	_displayName = _this select 0;
	_brightness = [_displayName,"brightness"] call 43cdo_btab_fnc_getSettings;
	_brightness = _brightness - 0.1;
	// make sure brightness is not larger than 0.5
	if (_brightness < 0.5) then {_brightness = 0.5};
	[_displayName,[["brightness",_brightness]]] call 43cdo_btab_fnc_setSettings;
	
	true
};

// fnc to increase icon and text size
43cdo_btab_fnc_txt_size_inc = {
	43cdo_btabTxtFctr = 43cdo_btabTxtFctr + 1;
	call 43cdo_btab_fnc_update_txt_size;
};

// fnc to decrease icon and text size
43cdo_btab_fnc_txt_size_dec = {
	if (43cdo_btabTxtFctr > 1) then {43cdo_btabTxtFctr = 43cdo_btabTxtFctr - 1};
	call 43cdo_btab_fnc_update_txt_size;
};

// This is drawn every frame on the tablet. fnc
43cdo_btabOnDrawbft = {
	_cntrlScreen = _this select 0;
	_display = ctrlParent _cntrlScreen;
	
	43cdo_btabMapWorldPos = [_cntrlScreen] call 43cdo_btab_fnc_ctrlMapCenter;
	43cdo_btabMapScale = ctrlMapScale _cntrlScreen;

	[_cntrlScreen,true] call 43cdo_btab_fnc_drawUserMarkers;
	[_cntrlScreen,0] call 43cdo_btab_fnc_drawBftMarkers;
	
	// draw directional arrow at own location
	_veh = vehicle 43cdo_btab_player;
	_playerPos = getPosASL _veh;
	_heading = direction _veh;
	_cntrlScreen drawIcon ["\A3\ui_f\data\map\VehicleIcons\iconmanvirtual_ca.paa",43cdo_btabMicroDAGRfontColour,_playerPos,43cdo_btabTADownIconBaseSize,43cdo_btabTADownIconBaseSize,_heading,"", 1,43cdo_btabTxtSize,"TahomaB","right"];
	
	// update hook information
	if (43cdo_btabDrawMapTools) then {
		[_display,_cntrlScreen,_playerPos,43cdo_btabMapCursorPos,0,false] call 43cdo_btab_fnc_drawHook;
	};
	
	true
};

// This is drawn every frame on the vehicle display. fnc
43cdo_btabOnDrawbftVeh = {
	_cntrlScreen = _this select 0;
	_display = ctrlParent _cntrlScreen;
	
	43cdo_btabMapWorldPos = [_cntrlScreen] call 43cdo_btab_fnc_ctrlMapCenter;
	43cdo_btabMapScale = ctrlMapScale _cntrlScreen;
	
	[_cntrlScreen,true] call 43cdo_btab_fnc_drawUserMarkers;
	[_cntrlScreen,0] call 43cdo_btab_fnc_drawBftMarkers;
	
	// draw directional arrow at own location
	_veh = vehicle 43cdo_btab_player;
	_playerPos = getPosASL _veh;
	_heading = direction _veh;
	_cntrlScreen drawIcon ["\A3\ui_f\data\map\VehicleIcons\iconmanvirtual_ca.paa",43cdo_btabMicroDAGRfontColour,_playerPos,43cdo_btabTADownIconBaseSize,43cdo_btabTADownIconBaseSize,_heading,"", 1,43cdo_btabTxtSize,"TahomaB","right"];
	
	// update hook information
	if (43cdo_btabDrawMapTools) then {
		[_display,_cntrlScreen,_playerPos,43cdo_btabMapCursorPos,0,false] call 43cdo_btab_fnc_drawHook;
	};
	
	true
};

// This is drawn every frame on the TAD display. fnc
43cdo_btabOnDrawbftTAD = {
	// is disableSerialization really required? If so, not sure this is the right place to call it
	disableSerialization;
	
	_cntrlScreen = _this select 0;
	_display = ctrlParent _cntrlScreen;
	
	// current position
	_veh = vehicle 43cdo_btab_player;
	_playerPos = getPosASL _veh;
	_heading = direction _veh;
	// change scale of map and centre to player position
	_cntrlScreen ctrlMapAnimAdd [0, 43cdo_btabMapScale, _playerPos];
	ctrlMapAnimCommit _cntrlScreen;
	
	[_cntrlScreen,false] call 43cdo_btab_fnc_drawUserMarkers;
	[_cntrlScreen,1] call 43cdo_btab_fnc_drawBftMarkers;
	
	// draw vehicle icon at own location
	_cntrlScreen drawIcon [43cdo_btabPlayerVehicleIcon,43cdo_btabTADfontColour,_playerPos,43cdo_btabTADownIconBaseSize,43cdo_btabTADownIconBaseSize,_heading,"", 1,43cdo_btabTxtSize,"TahomaB","right"];
	
	// draw TAD overlay (two circles, one at full scale, the other at half scale + current heading)
	_cntrlScreen drawIcon ["\cTab\img\TAD_overlay_ca.paa",43cdo_btabTADfontColour,_playerPos,250,250,_heading,"",1,43cdo_btabTxtSize,"TahomaB","right"];
	
	true
};

// This is drawn every frame on the TAD dialog. fnc
43cdo_btabOnDrawbftTADdialog = {
	// is disableSerialization really required? If so, not sure this is the right place to call it
	disableSerialization;
	
	_cntrlScreen = _this select 0;
	_display = ctrlParent _cntrlScreen;
	
	43cdo_btabMapWorldPos = [_cntrlScreen] call 43cdo_btab_fnc_ctrlMapCenter;
	43cdo_btabMapScale = ctrlMapScale _cntrlScreen;
	
	[_cntrlScreen,true] call 43cdo_btab_fnc_drawUserMarkers;
	[_cntrlScreen,1] call 43cdo_btab_fnc_drawBftMarkers;
	
	// draw vehicle icon at own location
	_veh = vehicle 43cdo_btab_player;
	_playerPos = getPosASL _veh;
	_heading = direction _veh;
	_cntrlScreen drawIcon [43cdo_btabPlayerVehicleIcon,43cdo_btabTADfontColour,_playerPos,43cdo_btabTADownIconScaledSize,43cdo_btabTADownIconScaledSize,_heading,"", 1,43cdo_btabTxtSize,"TahomaB","right"];
	
	// update hook information
	call {
		if (43cdo_btabDrawMapTools) exitWith {
			[_display,_cntrlScreen,_playerPos,43cdo_btabMapCursorPos,0,true] call 43cdo_btab_fnc_drawHook;
		};
		[_display,_cntrlScreen,_playerPos,43cdo_btabMapCursorPos,1,true] call 43cdo_btab_fnc_drawHook;
	};
	true
};

// This is drawn every frame on the android dialog. fnc
43cdo_btabOnDrawbftAndroid = {
	_cntrlScreen = _this select 0;
	_display = ctrlParent _cntrlScreen;
	
	43cdo_btabMapWorldPos = [_cntrlScreen] call 43cdo_btab_fnc_ctrlMapCenter;
	43cdo_btabMapScale = ctrlMapScale _cntrlScreen;

	[_cntrlScreen,true] call 43cdo_btab_fnc_drawUserMarkers;
	[_cntrlScreen,0] call 43cdo_btab_fnc_drawBftMarkers;
	
	// draw directional arrow at own location
	_veh = vehicle 43cdo_btab_player;
	_playerPos = getPosASL _veh;
	_heading = direction _veh;
	_cntrlScreen drawIcon ["\A3\ui_f\data\map\VehicleIcons\iconmanvirtual_ca.paa",43cdo_btabMicroDAGRfontColour,_playerPos,43cdo_btabTADownIconBaseSize,43cdo_btabTADownIconBaseSize,_heading,"", 1,43cdo_btabTxtSize,"TahomaB","right"];
	
	// update hook information
	if (43cdo_btabDrawMapTools) then {
		[_display,_cntrlScreen,_playerPos,43cdo_btabMapCursorPos,0,false] call 43cdo_btab_fnc_drawHook;
	};
	
	true
};

// This is drawn every frame on the android display. fnc
43cdo_btabOnDrawbftAndroidDsp = {
	_cntrlScreen = _this select 0;
	_display = ctrlParent _cntrlScreen;
	
	_veh = vehicle 43cdo_btab_player;
	_playerPos = getPosASL _veh;
	_heading = direction _veh;
	
	// change scale of map and centre to player position
	_cntrlScreen ctrlMapAnimAdd [0, 43cdo_btabMapScale, _playerPos];
	ctrlMapAnimCommit _cntrlScreen;
	
	[_cntrlScreen,false] call 43cdo_btab_fnc_drawUserMarkers;
	[_cntrlScreen,0] call 43cdo_btab_fnc_drawBftMarkers;
	
	// draw directional arrow at own location
	_cntrlScreen drawIcon ["\A3\ui_f\data\map\VehicleIcons\iconmanvirtual_ca.paa",43cdo_btabMicroDAGRfontColour,_playerPos,43cdo_btabTADownIconBaseSize,43cdo_btabTADownIconBaseSize,_heading,"", 1,43cdo_btabTxtSize,"TahomaB","right"];
	
	true
};

// This is drawn every frame on the microDAGR display. fnc
43cdo_btabOnDrawbftmicroDAGRdsp = {
	_cntrlScreen = _this select 0;
	_display = ctrlParent _cntrlScreen;
	
	// current position
	_veh = vehicle 43cdo_btab_player;
	_playerPos = getPosASL _veh;
	_heading = direction _veh;
	// change scale of map and centre to player position
	_cntrlScreen ctrlMapAnimAdd [0, 43cdo_btabMapScale, _playerPos];
	ctrlMapAnimCommit _cntrlScreen;
	
	[_cntrlScreen,false] call 43cdo_btab_fnc_drawUserMarkers;
	[_cntrlScreen,43cdo_btabMicroDAGRmode] call 43cdo_btab_fnc_drawBftMarkers;
	
	// draw directional arrow at own location
	_cntrlScreen drawIcon ["\A3\ui_f\data\map\VehicleIcons\iconmanvirtual_ca.paa",43cdo_btabMicroDAGRfontColour,_playerPos,43cdo_btabTADownIconBaseSize,43cdo_btabTADownIconBaseSize,_heading,"", 1,43cdo_btabTxtSize,"TahomaB","right"];
	
	true
};

// This is drawn every frame on the microDAGR dialog. fnc
43cdo_btabOnDrawbftMicroDAGRdlg = {
	_cntrlScreen = _this select 0;
	_display = ctrlParent _cntrlScreen;
	
	43cdo_btabMapWorldPos = [_cntrlScreen] call 43cdo_btab_fnc_ctrlMapCenter;
	43cdo_btabMapScale = ctrlMapScale _cntrlScreen;
	
	// current position
	_veh = vehicle 43cdo_btab_player;
	_playerPos = getPosASL _veh;
	_heading = direction _veh;
	
	[_cntrlScreen,false] call 43cdo_btab_fnc_drawUserMarkers;
	[_cntrlScreen,43cdo_btabMicroDAGRmode] call 43cdo_btab_fnc_drawBftMarkers;
	
	// draw directional arrow at own location
	_cntrlScreen drawIcon ["\A3\ui_f\data\map\VehicleIcons\iconmanvirtual_ca.paa",43cdo_btabMicroDAGRfontColour,_playerPos,43cdo_btabTADownIconBaseSize,43cdo_btabTADownIconBaseSize,_heading,"", 1,43cdo_btabTxtSize,"TahomaB","right"];
	
	// update hook information
	if (43cdo_btabDrawMapTools) then {
		[_display,_cntrlScreen,_playerPos,43cdo_btabMapCursorPos,0,false] call 43cdo_btab_fnc_drawHook;
	};
	
	true
};

// This is drawn every frame on the tablet uav screen. fnc
43cdo_btabOnDrawUAV = {
	if (isNil '43cdo_btabActUav') exitWith {};
	if (43cdo_btabActUav == player) exitWith {};
	
	_cntrlScreen = _this select 0;
	_display = ctrlParent _cntrlScreen;
	_pos = getPosASL 43cdo_btabActUav;
	
	[_cntrlScreen,false] call 43cdo_btab_fnc_drawUserMarkers;
	[_cntrlScreen,0] call 43cdo_btab_fnc_drawBftMarkers;
	
	// draw icon at own location
	_veh = vehicle 43cdo_btab_player;
	_cntrlScreen drawIcon ["\A3\ui_f\data\map\VehicleIcons\iconmanvirtual_ca.paa",43cdo_btabMicroDAGRfontColour,getPosASL _veh,43cdo_btabTADownIconBaseSize,43cdo_btabTADownIconBaseSize,direction 43cdo_btabActUav,"", 1,43cdo_btabTxtSize,"TahomaB","right"];
	
	// draw icon at UAV location
	_cntrlScreen drawIcon ["\A3\ui_f\data\map\VehicleIcons\iconmanvirtual_ca.paa",43cdo_btabTADhighlightColour,_pos,43cdo_btabTADownIconBaseSize,43cdo_btabTADownIconBaseSize,direction 43cdo_btabActUav,"",0,43cdo_btabTxtSize,"TahomaB","right"];
	
	_cntrlScreen ctrlMapAnimAdd [0,43cdo_btabMapScaleUAV,_pos];
	ctrlMapAnimCommit _cntrlScreen;
	true
};

// This is drawn every frame on the tablet helmet cam screen. fnc
43cdo_btabOnDrawHCam = {
	if (isNil '43cdo_btabHcams') exitWith {};
	_camHost = 43cdo_btabHcams select 2;
	
	_cntrlScreen = _this select 0;
	_display = ctrlParent _cntrlScreen;
	_pos = getPosASL _camHost;
	
	[_cntrlScreen,false] call 43cdo_btab_fnc_drawUserMarkers;
	[_cntrlScreen,0] call 43cdo_btab_fnc_drawBftMarkers;
	
	// draw icon at own location
	_veh = vehicle 43cdo_btab_player;
	_cntrlScreen drawIcon ["\A3\ui_f\data\map\VehicleIcons\iconmanvirtual_ca.paa",43cdo_btabMicroDAGRfontColour,getPosASL _veh,43cdo_btabTADownIconBaseSize,43cdo_btabTADownIconBaseSize,direction _veh,"", 1,43cdo_btabTxtSize,"TahomaB","right"];
	
	// draw icon at helmet cam location
	_cntrlScreen drawIcon ["\A3\ui_f\data\map\VehicleIcons\iconmanvirtual_ca.paa",43cdo_btabTADhighlightColour,_pos,43cdo_btabTADownIconBaseSize,43cdo_btabTADownIconBaseSize,direction _camHost,"",0,43cdo_btabTxtSize,"TahomaB","right"];
	
	_cntrlScreen ctrlMapAnimAdd [0,43cdo_btabMapScaleHCam,_pos];
	ctrlMapAnimCommit _cntrlScreen;
	true
};



//Main loop to add the key handler to the unit.
[] spawn {
	waitUntil {sleep 0.1;!(IsNull (findDisplay 46))};
	
	["43cdo_btab","ifMain",["Toggle Main Interface","Open 43cdo_btab device in small overlay mode if available"],{call 43cdo_btab_fnc_onIfMainPressed},"",[43cdo_btab_key_if_main_scancode,43cdo_btab_key_if_main_modifiers],false] call cba_fnc_addKeybind;
	["43cdo_btab","ifSecondary",["Toggle Secondary Interface","Open 43cdo_btab device in interactable mode"],{call 43cdo_btab_fnc_onIfSecondaryPressed},"",[43cdo_btab_key_if_secondary_scancode,43cdo_btab_key_if_secondary_modifiers],false] call cba_fnc_addKeybind;
	["43cdo_btab","ifTertiary",["Toggle Tertiary Interface","Open private 43cdo_btab device when in a vehicle with its own 43cdo_btab device, or to open Tablet while also carrying a MicroDAGR"],{call 43cdo_btab_fnc_onIfTertiaryPressed},"",[43cdo_btab_key_if_tertiary_scancode,43cdo_btab_key_if_tertiary_modifiers],false] call cba_fnc_addKeybind;
	["43cdo_btab","zoomIn",["Zoom In","Zoom In on map while 43cdo_btab is in small overlay mode"],{call 43cdo_btab_fnc_onZoomInPressed},"",[43cdo_btab_key_zoom_in_scancode,43cdo_btab_key_zoom_in_modifiers],false] call cba_fnc_addKeybind;
	["43cdo_btab","zoomOut",["Zoom Out","Zoom Out on map while 43cdo_btab is in small overlay mode"],{call 43cdo_btab_fnc_onZoomOutPressed},"",[43cdo_btab_key_zoom_out_scancode,43cdo_btab_key_zoom_out_modifiers],false] call cba_fnc_addKeybind;
	["43cdo_btab","toggleIfPosition",["Toggle Interface Position","Toggle overlay mode interface position from left to right or reset interactive mode interface position to default"],{[] call 43cdo_btab_fnc_toggleIfPosition},"",[43cdo_btab_key_toggleIfPosition_scancode,43cdo_btab_key_toggleIfPosition_modifiers],false] call cba_fnc_addKeybind;
	["43cdo_btab","toggleCqbMode",["Toggle CQB Mode","Toggle CQB mode for separated squad markers (shows all squad members without labels)"],{call 43cdo_btab_fnc_toggleCqbMode},"",[-1,[]],false] call cba_fnc_addKeybind;
	
	// if player is curator (ZEUS), setup key handlers
	waitUntil {sleep 0.1;!(isNull player)};
	sleep 2;
	if (player in (call BIS_fnc_listCuratorPlayers)) then {	
		[] spawn {
			while {true} do {
				waitUntil {sleep 0.1;!(isNull (findDisplay 312))};			
				(findDisplay 312) displayAddEventHandler ["KeyDown","[_this,'keydown'] call 43cdo_btab_fnc_processCuratorKey"];
				(findDisplay 312) displayAddEventHandler ["KeyUp","[_this,'keyup'] call 43cdo_btab_fnc_processCuratorKey"];
				waitUntil {sleep 0.1;isNull (findDisplay 312)};
			};
		};
	};
};

43cdo_btab_msg_gui_load = {
	disableSerialization;
	_return = true;
	_display = uiNamespace getVariable (43cdo_btabIfOpen select 1);
	_playerEncryptionKey = call 43cdo_btab_fnc_getPlayerEncryptionKey;
	_msgArray = 43cdo_btab_player getVariable [format ["cTab_messages_%1",_playerEncryptionKey],[]];
	_msgControl = _display displayCtrl IDC_CTAB_MSG_LIST;
	_plrlistControl = _display displayCtrl IDC_CTAB_MSG_RECIPIENTS;
	lbClear _msgControl;
	lbClear _plrlistControl;
	_plrList = playableUnits;
	// since playableUnits will return an empty array in single player, add the player if array is empty
	if (_plrList isEqualTo []) then {_plrList pushBack 43cdo_btab_player};
	_validSides = call 43cdo_btab_fnc_getPlayerSides;
	
	// turn this on for testing, otherwise not really usefull, since sending to an AI controlled, but switchable unit will send the message to the player himself
	/*if (count _plrList < 1) then { _plrList = switchableUnits;};*/
	
	uiNamespace setVariable ['43cdo_btab_msg_playerList', _plrList];
	// Messages
	{
		_title =  _x select 0;
		_msgState = _x select 2;
		_img = call {
			if (_msgState == 0) exitWith {"\cTab\img\icoUnopenedmail.paa"};
			if (_msgState == 1) exitWith {"\cTab\img\icoOpenmail.paa"};
			if (_msgState == 2) exitWith {"\cTab\img\icon_sentMail_ca.paa"};
		};
		_index = _msgControl lbAdd _title;
		_msgControl lbSetPicture [_index,_img];
		_msgControl lbSetTooltip [_index,_title];
	} count _msgArray;
	
	{
		if ((side _x in _validSides) && {isPlayer _x} && {[_x,["ItemcTab","ItemAndroid"]] call 43cdo_btab_fnc_checkGear}) then {
			_index = _plrlistControl lbAdd format ["%1:%2 (%3)",groupId group _x,[_x] call CBA_fnc_getGroupIndex,name _x];
			_plrlistControl lbSetData [_index,str _x];
		};
	} count _plrList;
	
	lbSort [_plrlistControl, "ASC"];
	
	_return;
};

43cdo_btab_msg_get_mailTxt = {
	disableSerialization;
	_return = true;
	_index = _this select 1;
	_display = uiNamespace getVariable (43cdo_btabIfOpen select 1);
	_playerEncryptionKey = call 43cdo_btab_fnc_getPlayerEncryptionKey;
	_msgArray = 43cdo_btab_player getVariable [format ["cTab_messages_%1",_playerEncryptionKey],[]];
	_msgName = (_msgArray select _index) select 0;
	_msgtxt = (_msgArray select _index) select 1;
	_msgState = (_msgArray select _index) select 2;
	if (_msgState == 0) then {
		_msgArray set [_index,[_msgName,_msgtxt,1]];
		43cdo_btab_player setVariable [format ["cTab_messages_%1",_playerEncryptionKey],_msgArray];
	};
	
	_nop = [] call 43cdo_btab_msg_gui_load;
	
	_txtControl = _display displayCtrl IDC_CTAB_MSG_CONTENT;

	_nul = _txtControl ctrlSetText  _msgtxt;
	
	_return;
};

43cdo_btab_msg_Send = {
	private ["_return","_display","_plrLBctrl","_msgBodyctrl","_plrList","_indices","_time","_msgTitle","_msgBody","_recip","_recipientNames","_msgArray","_playerEncryptionKey"];
	disableSerialization;
	_return = true;
	_display = uiNamespace getVariable (43cdo_btabIfOpen select 1);
	_playerEncryptionKey = call 43cdo_btab_fnc_getPlayerEncryptionKey;
	_plrLBctrl = _display displayCtrl IDC_CTAB_MSG_RECIPIENTS;
	_msgBodyctrl = _display displayCtrl IDC_CTAB_MSG_COMPOSE;
	_plrList = (uiNamespace getVariable "43cdo_btab_msg_playerList");
	
	_indices = lbSelection _plrLBctrl;
	
	if (_indices isEqualTo []) exitWith {false};
	
	_time = call 43cdo_btab_currentTime;
	_msgTitle = format ["%1 - %2:%3 (%4)",_time,groupId group 43cdo_btab_player,[43cdo_btab_player] call CBA_fnc_getGroupIndex,name 43cdo_btab_player];
	_msgBody = ctrlText _msgBodyctrl;
	if (_msgBody isEqualTo "") exitWith {false};
	_recipientNames = "";
	
	{
		_data = _plrLBctrl lbData _x;
		_recip = objNull;
		{
			if (_data == str _x) exitWith {_recip = _x;};
		} count _plrList;
		
		if !(IsNull _recip) then {
			if (_recipientNames isEqualTo "") then {
				_recipientNames = format ["%1:%2 (%3)",groupId group _recip,[_recip] call CBA_fnc_getGroupIndex,name _recip];
			} else {
				_recipientNames = format ["%1; %2",_recipientNames,name _recip];
			};
			
			["43cdo_btab_msg_receive",[_recip,_msgTitle,_msgBody,_playerEncryptionKey,43cdo_btab_player]] call CBA_fnc_whereLocalEvent;
		};
	} forEach _indices;
	
	// If the message was sent
	if (_recipientNames != "") then {
		_msgArray = 43cdo_btab_player getVariable [format ["cTab_messages_%1",_playerEncryptionKey],[]];
		_msgArray pushBack [format ["%1 - %2",_time,_recipientNames],_msgBody,2];
		43cdo_btab_player setVariable [format ["cTab_messages_%1",_playerEncryptionKey],_msgArray];
	
		if (!isNil "43cdo_btabIfOpen" && {[43cdo_btabIfOpen select 1,"mode"] call 43cdo_btab_fnc_getSettings == "MESSAGE"}) then {
			call 43cdo_btab_msg_gui_load;
		};
		
		// add a notification
		["MSG","Message sent successfully",3] call 43cdo_btab_fnc_addNotification;
		playSound "cTab_mailSent";
		// remove message body
		_msgBodyctrl ctrlSetText "";
		// clear selected recipients
		_plrLBctrl lbSetCurSel -1;
	};
	
	_return;
};

["43cdo_btab_msg_receive",
	{
		_msgRecipient = _this select 0;
		_msgTitle = _this select 1;
		_msgBody = _this select 2;
		_msgEncryptionKey = _this select 3;
		_sender = _this select 4;
		_playerEncryptionKey = call 43cdo_btab_fnc_getPlayerEncryptionKey;
		_msgArray = _msgRecipient getVariable [format ["cTab_messages_%1",_msgEncryptionKey],[]];
		_msgArray pushBack [_msgTitle,_msgBody,0];
		
		_msgRecipient setVariable [format ["cTab_messages_%1",_msgEncryptionKey],_msgArray];
		
		if (_msgRecipient == 43cdo_btab_player && _sender != 43cdo_btab_player && {_playerEncryptionKey == _msgEncryptionKey} && {[43cdo_btab_player,["ItemcTab","ItemAndroid"]] call 43cdo_btab_fnc_checkGear}) then {
			playSound "cTab_phoneVibrate";
			
			if (!isNil "43cdo_btabIfOpen" && {[43cdo_btabIfOpen select 1,"mode"] call 43cdo_btab_fnc_getSettings == "MESSAGE"}) then {
				_nop = [] call 43cdo_btab_msg_gui_load;
				
				// add a notification
				["MSG",format ["New message from %1",name _sender],6] call 43cdo_btab_fnc_addNotification;
			} else {
				43cdo_btabRscLayerMailNotification cutRsc ["43cdo_btab_Mail_ico_disp", "PLAIN"]; //show
			};
		};
	}
] call CBA_fnc_addLocalEventHandler;
	
43cdo_btab_msg_delete_all = {
	_playerEncryptionKey = call 43cdo_btab_fnc_getPlayerEncryptionKey;
	43cdo_btab_player setVariable [format ["cTab_messages_%1",_playerEncryptionKey],[]];
};

/*
Function to execute the correct action when btnACT is pressed on Tablet
No Parameters
Returns TRUE
*/
43cdo_btab_Tablet_btnACT = {
	_mode = ["43cdo_btab_Tablet_dlg","mode"] call 43cdo_btab_fnc_getSettings;
	call {
		if (_mode == "UAV") exitWith {[] call 43cdo_btab_fnc_remoteControlUav;};
		if (_mode == "HCAM") exitWith {["43cdo_btab_Tablet_dlg",[["mode","HCAM_FULL"]]] call 43cdo_btab_fnc_setSettings;};
		if (_mode == "HCAM_FULL") exitWith {["43cdo_btab_Tablet_dlg",[["mode","HCAM"]]] call 43cdo_btab_fnc_setSettings;};
	};
	true
};

/*
Function called when DELETE button is pressed in messaging mode
Parameter 0: Name of uiNameSpace variable of display
Returns false if nothing was selected for deletion, else returns true
*/
43cdo_btab_fnc_onMsgBtnDelete = {
	_displayName = _this select 0;
	_display = uiNamespace getVariable _displayName;
	_msgLbCtrl = _display displayCtrl IDC_CTAB_MSG_LIST;
	_msgLbSelection = lbSelection _msgLbCtrl;
	
	if (count _msgLbSelection == 0) exitWith {false};
	_playerEncryptionKey = call 43cdo_btab_fnc_getPlayerEncryptionKey;
	_msgArray = 43cdo_btab_player getVariable [format ["cTab_messages_%1",_playerEncryptionKey],[]];
	
	// run through the selection backwards as otherwise the indices won't match anymore
	for "_i" from (count _msgLbSelection) to 0 step -1 do {
		_msgArray deleteAt (_msgLbSelection select _i);
	};
	43cdo_btab_player setVariable [format ["cTab_messages_%1",_playerEncryptionKey],_msgArray];
	
	_msgTextCtrl = _display displayCtrl IDC_CTAB_MSG_CONTENT;
	_msgTextCtrl ctrlSetText "No Message Selected";
	_nop = [] call 43cdo_btab_msg_gui_load;
	true
};
