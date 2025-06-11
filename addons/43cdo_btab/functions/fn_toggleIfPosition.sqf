/*
	Name: 43cdo_btab_fnc_toggleIfPosition
	
	Author(s):
		Gundy
	
	Description:
		Toggle position of interface (display only) from left to right or reset dialog to default position
		
	
	Parameters:
		NONE
	
	Returns:
		BOOLEAN - TRUE
	
	Example:
		[] call 43cdo_btab_fnc_toggleIfPosition;
*/

private ["_displayName"];

// bail if there is no interface open
if (isNil "cTabIfOpen") exitWith {false};

_displayName = cTabIfOpen select 1;

if ([_displayName] call 43cdo_btab_fnc_isDialog) then {
	// reset position to default
	[_displayName,[["dlgIfPosition",[]]],true,true] call 43cdo_btab_fnc_setSettings;
} else {
	_dspIfPosition = [_displayName,"dspIfPosition"] call 43cdo_btab_fnc_getSettings;
	// toggle position
	[_displayName,[["dspIfPosition",!_dspIfPosition]]] call 43cdo_btab_fnc_setSettings;
};

true
