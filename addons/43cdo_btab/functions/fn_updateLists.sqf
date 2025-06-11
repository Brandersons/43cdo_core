/*
	Name: 43cdo_btab_fnc_updateLists
	
	Author(s):
		Gundy

	Description:
		Update lists with information of all units that have 43cdo_btab items

	Parameters:
		ARRAY - _this select 0: BOOLEAN: force interface update (optional, default: true)
		
	Description (list variables):
		43cdo_btabBFTmembers --- BFT MEMBERS
		List will contain units from the same side that are not in a vehicle, are not UAVs and have either a 43cdo_btab item and are not dead.
		List will not contain the player or the player's group members, since there are seperate group lists.

		43cdo_btabBFTgroups --- BFT GROUP MEMBERS
		43cdo_btabHcamlist
		
		List format (all except 43cdo_btabHcamlist):
		[[<unit>,<icon>,<bft text>,<short text>,<group text>],...]

	Parameters:
		NONE
	
	Returns:
		NOTHING
	
	Example:
		call 43cdo_btab_fnc_updateLists;
*/

private ["_43cdo_btabBFTmembers","_43cdo_btabBFTgroups","_43cdo_btabBFTvehicles","_43cdo_btabBFTseparated","_43cdo_btabUAVlist","_43cdo_btabHcamlist","_validSides","_playerEncryptionKey","_playerVehicle","_playerGroup","_updateInterface"];

_updateInterface = if (count _this > 0) then {_this select 0} else {true};

_43cdo_btabBFTmembers = [];
_43cdo_btabBFTgroups = [];
_43cdo_btabBFTvehicles = [];
_43cdo_btabBFTseparated = [];  // separated squad members 
_43cdo_btabUAVlist = [];  // all UAVs
_43cdo_btabHcamlist = [];  // units with a helmet cam

_validSides = call 43cdo_btab_fnc_getPlayerSides;

_playerVehicle = vehicle 43cdo_btab_player;
_playerGroup = group 43cdo_btab_player;

// 43cdo_btabBFTmembers --- BFT MEMBERS
// Units on the same side that are not in a vehicle, are not UAVs and have 43cdo_btab
{
	// put only units that are not the player, not in the players group and are alive in the list.
	if ((_x != 43cdo_btab_player) && {[_x,["Item43cdo_btab","ItemAndroid","ItemMicroDAGR"]] call 43cdo_btab_fnc_checkGear}) then {
		0 = _43cdo_btabBFTmembers pushBack [_x,_x call 43cdo_btab_fnc_getInfMarkerIcon,"",name _x,str([_x] call CBA_fnc_getGroupIndex)];
	};
} count units 43cdo_btab_player;

// 43cdo_btabBFTgroups --- BFT GROUP MEMBERS
// Group members on foot that have 43cdo_btab items
{
	_groupLeader = objNull;
	_groupMembers = units _x;
	// Find a leader within the group that has a tablet or android (required to place group markers)
	{
		if ([leader _x,["Item43cdo_btab","ItemAndroid"]] call 43cdo_btab_fnc_checkGear) exitWith {_groupLeader = leader _x;};
		{
			if ([_x,["Item43cdo_btab","ItemAndroid"]] call 43cdo_btab_fnc_checkGear) exitWith {_groupLeader = _x;};
		} count _groupMembers;
	} count _groupMembers;
	
	// group must have leader with equipment to show on map
	if (!isNull _groupLeader) then {
		{
			// put only units that are not dead in the list (player can be in this list)
			if (alive _x && {_x != _groupLeader}) then {
				0 = _43cdo_btabBFTgroups pushBack [_x,_x call 43cdo_btab_fnc_getInfMarkerIcon,"",name _x,groupId _x];
			};
		} count _groupMembers;
	};
} count allGroups;

// Handle separated squad member logic
// This section populates _43cdo_btabBFTseparated with squad members from other groups who are separated from their leaders
_separationDistance = 0;
_enableSeparatedMarkers = false;

// Check player's equipment to determine settings to use (priority: Tablet > Android > MicroDAGR)
call {
	if ([43cdo_btab_player,["Item43cdo_btab"]] call 43cdo_btab_fnc_checkGear) exitWith {
		_separationDistance = missionNamespace getVariable ["43cdo_btab_Tablet_separationDistance", 200];
		_enableSeparatedMarkers = missionNamespace getVariable ["43cdo_btab_Tablet_separatedSquadMarkersEnabled", true];
	};
	if ([43cdo_btab_player,["ItemAndroid"]] call 43cdo_btab_fnc_checkGear) exitWith {
		_separationDistance = missionNamespace getVariable ["43cdo_btab_Android_separationDistance", 200];
		_enableSeparatedMarkers = missionNamespace getVariable ["43cdo_btab_Android_separatedSquadMarkersEnabled", true];
	};
	if ([43cdo_btab_player,["ItemMicroDAGR"]] call 43cdo_btab_fnc_checkGear) exitWith {
		_separationDistance = missionNamespace getVariable ["43cdo_btab_MicroDAGR_separationDistance", 200];
		_enableSeparatedMarkers = missionNamespace getVariable ["43cdo_btab_MicroDAGR_separatedSquadMarkersEnabled", true];
	};
	// If player has no 43cdo_btab equipment, disable the feature
	_enableSeparatedMarkers = false;
};

// Process separated squad members if enabled and distance > 0
if (_enableSeparatedMarkers && _separationDistance > 0) then {
	{
		_group = _x;
		_groupLeader = leader _group;
		_groupMembers = units _group;
		
		// Only process groups that are not the player's group and have a leader with proper equipment
		if (_group != _playerGroup && {[_groupLeader,["Item43cdo_btab","ItemAndroid","ItemMicroDAGR"]] call 43cdo_btab_fnc_checkGear}) then {
			{
				// Check if squad member is separated from their leader
				if (_x != _groupLeader && {[_x,["Item43cdo_btab","ItemAndroid","ItemMicroDAGR"]] call 43cdo_btab_fnc_checkGear}) then {
					_distance = _x distance _groupLeader;
					
					// If member is farther than separation distance from leader, add to separated list
					if (_distance > _separationDistance) then {
						0 = _43cdo_btabBFTseparated pushBack [_x,_x call 43cdo_btab_fnc_getInfMarkerIcon,"",name _x,str([_x] call CBA_fnc_getGroupIndex)];
					};
				};
			} count _groupMembers;
		};
	} count allGroups;
};

// 43cdo_btabBFTvehicles --- BFT VEHICLES
// Vehicles with people in them that are on the same side.
{
	if (alive _x) then {
		_veh = vehicle _x;
		// To make sure we don't have the same vehicle twice, check if it's not in the array already
		if ((_veh != _x) && {[43cdo_btabBFTvehicles,_veh] call BIS_fnc_findInPairs == -1}) then {
			0 = _43cdo_btabBFTvehicles pushBack [_veh,"b_mech_inf"];
		};
	};
} count units 43cdo_btab_player;

// 43cdo_btabUAVlist --- UAVS
// UAVs on the same side regardless of their AI status.
{
	if ((side _x in _validSides) && alive _x) then {
		0 = _43cdo_btabUAVlist pushBack _x;
	};
} count allUnitsUAV;

/*
43cdo_btabHcamlist --- HELMET CAMS
Units on our side, that have either helmets that have been specified to include a helmet cam, or Item43cdo_btabHCAM in their inventory.
*/
{
	// only put players in a 43cdo_btab list if they are alive and have a defined helmet cam
	if (headgear _x in 43cdo_btab_helmetClass_has_HCam || {[_x,["Item43cdo_btabHCam"]] call 43cdo_btab_fnc_checkGear}) then {
		0 = _43cdo_btabHcamlist pushBack _x;
	};
} count units 43cdo_btab_player;

// populate the list of players with helmet cams. This is used to create the Hcam UI selection list
{
	// only put players in a 43cdo_btab list if they are alive
	if (alive _x) then {
		_helmet = headgear _x;
		_camera = false;
		if (headgear _x != "") then {_camera = [_x,["Item43cdo_btabHCam"]] call 43cdo_btab_fnc_checkGear};
		if (_helmet in 43cdo_btab_helmetClass_has_HCam || _camera || {[_x,["Item43cdo_btabHCam"]] call 43cdo_btab_fnc_checkGear}) then {0 = _43cdo_btabHcamlist pushBack _x;};
	};
} count playableUnits;

// Compare arrays to current ones and update only when they have changed
// 43cdo_btabBFTmembers
if !(43cdo_btabBFTmembers isEqualTo _43cdo_btabBFTmembers) then {
	43cdo_btabBFTmembers = [] + _43cdo_btabBFTmembers;
	if (!_updateInterface) then {_updateInterface = true};
};
// 43cdo_btabBFTgroups
if !(43cdo_btabBFTgroups isEqualTo _43cdo_btabBFTgroups) then {
	43cdo_btabBFTgroups = [] + _43cdo_btabBFTgroups;
	if (!_updateInterface) then {_updateInterface = true};
};
// 43cdo_btabBFTseparated
if !(43cdo_btabBFTseparated isEqualTo _43cdo_btabBFTseparated) then {
	43cdo_btabBFTseparated = [] + _43cdo_btabBFTseparated;
	if (!_updateInterface) then {_updateInterface = true};
};
// 43cdo_btabBFTvehicles
if !(43cdo_btabBFTvehicles isEqualTo _43cdo_btabBFTvehicles) then {
	43cdo_btabBFTvehicles = [] + _43cdo_btabBFTvehicles;
	if (!_updateInterface) then {_updateInterface = true};
};
// 43cdo_btabUAVlist
if !(43cdo_btabUAVlist isEqualTo _43cdo_btabUAVlist) then {
	43cdo_btabUAVlist = [] + _43cdo_btabUAVlist;
	if (!_updateInterface) then {_updateInterface = true};
};
// 43cdo_btabHcamlist
if !(43cdo_btabHcamlist isEqualTo _43cdo_btabHcamlist) then {
	43cdo_btabHcamlist = [] + _43cdo_btabHcamlist;
	if (!_updateInterface) then {_updateInterface = true};
};

// call interface updates
if (count _updateInterface > 0) then {
	[_updateInterface] call 43cdo_btab_fnc_updateInterface;
};
