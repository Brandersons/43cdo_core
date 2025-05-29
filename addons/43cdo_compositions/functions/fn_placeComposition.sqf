/*
    Places a 3DEN composition at the module's position.
*/

params ["_logic"];

if (!is3DEN) exitWith {};

private _file = "43cdo_composition_test";
private _path = format ["%1\\compositions\\%2.sqe", toLowerANSI (configSourceModPath (configFile >> 'CfgPatches' >> '43cdo_composition_test')), _file];

if !(fileExists _path) exitWith {
    systemChat format ["Composition file not found: %1", _path];
};

private _compositionData = loadFile _path;
if (_compositionData isEqualTo "") exitWith {
    systemChat format ["Composition file is empty or could not be loaded: %1", _path];
};

private _position = getPos _logic;
private _rotation = getDir _logic;

[_compositionData, _position, _rotation] call create3DENComposition;
