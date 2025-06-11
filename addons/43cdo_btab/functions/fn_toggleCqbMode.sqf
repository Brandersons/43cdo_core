/*
	Name: 43cdo_btab_fnc_toggleCqbMode
	
	Author(s):
		Gundy, Riouken, Raspu

	Description:
		Toggle CQB mode for separated squad markers
		When enabled: stores current distance settings, sets distance to 0, hides labels
		When disabled: restores distance settings, shows labels
		
	Parameters:
		NONE
	
	Returns:
		BOOLEAN - TRUE if CQB mode is now enabled, FALSE if disabled
	
	Example:
		call 43cdo_btab_fnc_toggleCqbMode;
*/

// Initialize CQB mode state if not already done
if (isNil "cTab_cqbModeActive") then {
	cTab_cqbModeActive = false;
	cTab_cqbMode_storedAndroidDistance = nil;
	cTab_cqbMode_storedMicroDAGRDistance = nil;
	cTab_cqbMode_storedTabletDistance = nil;
};

if (!cTab_cqbModeActive) then {
	// ENABLE CQB MODE
	
	// Store current distance settings
	if (!isNil "cTab_Android_separationDistance") then {
		cTab_cqbMode_storedAndroidDistance = cTab_Android_separationDistance;
		cTab_Android_separationDistance = 0;
	};
	if (!isNil "cTab_MicroDAGR_separationDistance") then {
		cTab_cqbMode_storedMicroDAGRDistance = cTab_MicroDAGR_separationDistance;
		cTab_MicroDAGR_separationDistance = 0;
	};
	if (!isNil "cTab_Tablet_separationDistance") then {
		cTab_cqbMode_storedTabletDistance = cTab_Tablet_separationDistance;
		cTab_Tablet_separationDistance = 0;
	};
	
	cTab_cqbModeActive = true;
	
	systemChat "CQB Mode: ON (Separated squad markers now show all members without labels)";
	
} else {
	// DISABLE CQB MODE
	
	// Restore stored distance settings
	if (!isNil "cTab_cqbMode_storedAndroidDistance") then {
		cTab_Android_separationDistance = cTab_cqbMode_storedAndroidDistance;
		cTab_cqbMode_storedAndroidDistance = nil;
	};
	if (!isNil "cTab_cqbMode_storedMicroDAGRDistance") then {
		cTab_MicroDAGR_separationDistance = cTab_cqbMode_storedMicroDAGRDistance;
		cTab_cqbMode_storedMicroDAGRDistance = nil;
	};
	if (!isNil "cTab_cqbMode_storedTabletDistance") then {
		cTab_Tablet_separationDistance = cTab_cqbMode_storedTabletDistance;
		cTab_cqbMode_storedTabletDistance = nil;
	};
	
	cTab_cqbModeActive = false;
	
	systemChat "CQB Mode: OFF (Separated squad markers restored to normal distance filtering)";
};

// Update the lists and interface immediately
if (hasInterface) then {
	call 43cdo_btab_fnc_updateLists;
	if (!isNil "cTabIfOpen") then {
		call 43cdo_btab_fnc_updateInterface;
	};
};

cTab_cqbModeActive 
