/*
 	Name: 43cdo_btab_fnc_initSquadSeparationSettings
 	
 	Author(s):
		Gundy, Riouken, Raspu

 	Description:
		Initialize CBA settings for separated squad member markers for each device

	Parameters:
		NONE
 	
 	Returns:
		BOOLEAN - Always TRUE
 	
 	Example:
		call 43cdo_btab_fnc_initSquadSeparationSettings;
*/

// ==================== ANDROID DEVICE SETTINGS ====================

// Setting for enabling/disabling separated squad member markers on Android
[
	"43cdo_btab_Android_separatedSquadMarkersEnabled", // Internal setting name
	"CHECKBOX", // setting type
	["Enable Separated Squad Markers", "Show markers for squad members from other groups who are separated from their leader"], // Pretty name
	["43cdo_btab", "Android - Squad Markers"], // Category
	true, // default value
	false, // client-side only
	{
		// Code executed when setting is changed
		if (hasInterface) then {
			call 43cdo_btab_fnc_updateLists;
		};
	}
] call CBA_Settings_fnc_init;

// Setting for separation distance threshold on Android
[
	"43cdo_btab_Android_separationDistance", // Internal setting name
	"SLIDER", // setting type
	["Separation Distance", "Distance in meters to consider a squad member as separated from their leader"], // Pretty name
	["43cdo_btab", "Android - Squad Markers"], // Category
	[0, 5000, 200, 0], // [min, max, default, decimals]
	false, // client-side only
	{
		// Code executed when setting is changed
		if (hasInterface) then {
			call 43cdo_btab_fnc_updateLists;
		};
	}
] call CBA_Settings_fnc_init;

// ==================== MICRODAGR DEVICE SETTINGS ====================

// Setting for enabling/disabling separated squad member markers on MicroDAGR
[
	"43cdo_btab_MicroDAGR_separatedSquadMarkersEnabled", // Internal setting name
	"CHECKBOX", // setting type
	["Enable Separated Squad Markers", "Show markers for squad members from other groups who are separated from their leader"], // Pretty name
	["43cdo_btab", "MicroDAGR - Squad Markers"], // Category
	true, // default value
	false, // client-side only
	{
		// Code executed when setting is changed
		if (hasInterface) then {
			call 43cdo_btab_fnc_updateLists;
		};
	}
] call CBA_Settings_fnc_init;

// Setting for separation distance threshold on MicroDAGR
[
	"43cdo_btab_MicroDAGR_separationDistance", // Internal setting name
	"SLIDER", // setting type
	["Separation Distance", "Distance in meters to consider a squad member as separated from their leader"], // Pretty name
	["43cdo_btab", "MicroDAGR - Squad Markers"], // Category
	[0, 5000, 200, 0], // [min, max, default, decimals]
	false, // client-side only
	{
		// Code executed when setting is changed
		if (hasInterface) then {
			call 43cdo_btab_fnc_updateLists;
		};
	}
] call CBA_Settings_fnc_init;

// ==================== TABLET (CTAB) DEVICE SETTINGS ====================

// Setting for enabling/disabling separated squad member markers on Tablet
[
	"43cdo_btab_Tablet_separatedSquadMarkersEnabled", // Internal setting name
	"CHECKBOX", // setting type
	["Enable Separated Squad Markers", "Show markers for squad members from other groups who are separated from their leader"], // Pretty name
	["43cdo_btab", "Tablet - Squad Markers"], // Category
	true, // default value
	false, // client-side only
	{
		// Code executed when setting is changed
		if (hasInterface) then {
			call 43cdo_btab_fnc_updateLists;
		};
	}
] call CBA_Settings_fnc_init;

// Setting for separation distance threshold on Tablet
[
	"43cdo_btab_Tablet_separationDistance", // Internal setting name
	"SLIDER", // setting type
	["Separation Distance", "Distance in meters to consider a squad member as separated from their leader"], // Pretty name
	["43cdo_btab", "Tablet - Squad Markers"], // Category
	[0, 5000, 200, 0], // [min, max, default, decimals]
	false, // client-side only
	{
		// Code executed when setting is changed
		if (hasInterface) then {
			call 43cdo_btab_fnc_updateLists;
		};
	}
] call CBA_Settings_fnc_init;

true 
