/*
	Name: 43cdo_btab_fnc_getCopilot
	
	Author(s):
		Gundy
	
	Description:
		Returns the unit in the passed vehicle's co-pilot seat
	
	Parameters: 
		Object - Vehicle
	
	Returns:
		OBJECT - Unit occupying the vehicle's co-pilot seat, objNull if there is no co-pilot
	
	Example:
		_copilot = (vehicle player) call 43cdo_btab_fnc_getCopilot;
*/

private ["_copilotTurret","_turretNumber","_turrets","_i","_turretConfigPath"];

// default co-pilot turret
_copilotTurret = 0;

// if this is a helicopter, find the turret number that has isCopilot set to 1
if (_this isKindOf "Helicopter") then {
	_turretNumber = -1;
	_copilotTurret = -1;
	// get a list of all turrets
	_turrets = configFile >> "CfgVehicles" >> (typeOf _this) >> "Turrets";
	
	// iterate through the list of turrets
	for "_i" from 0 to (count _turrets -1) do {
		_turretConfigPath = _turrets select _i;
		// filter non classes; count turrets; find out if this is the co-pilot's turret (we assume that there is just one co-pilot), if so exit the loop
		if (isClass(_turretConfigPath) && {_turretNumber = _turretNumber + 1; getNumber(_turretConfigPath >> "isCopilot") == 1}) exitWith {
			_copilotTurret = _turretNumber;
		};
	};
};

_this turretUnit [_copilotTurret]
