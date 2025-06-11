/*
 	Name: 43cdo_btab_fnc_drawHook
 	
 	Author(s):
		Gundy

 	Description:
		Calculate and draw hook distance, direction, grid, elevation and arrow
	
	Parameters:
		0: OBJECT  - Display used to write hook direction, distance and grid to
		0: OBJECT  - Map control to draw arrow on
		2: ARRAY   - Position A
		3: ARRAY   - Position B
		4: INTEGER - Mode, 0 = Reference is A, 1 = Reference is B
		5: BOOLEAN - TAD, TRUE = TAD
 	
 	Returns:
		BOOLEAN - Always TRUE
 	
 	Example:
		[_display,_ctrlScreen,_playerPos,cTabMapCursorPos,0,false] call 43cdo_btab_fnc_drawHook;
*/

#include "\cTab\shared\cTab_gui_macros.hpp"

private ["_display","_ctrlScreen","_pos","_secondPos","_dirToSecondPos","_dstToSecondPos"];

_display = _this select 0;
_ctrlScreen = _this select 1;
_pos = _this select 2;
_secondPos = _this select 3;
// draw arrow from current position to map centre
_dirToSecondPos = call {
	if (_this select 4 == 0) exitWith {
		_ctrlScreen drawArrow [_pos,_secondPos,cTabMicroDAGRhighlightColour];
		[_pos,_secondPos] call 43cdo_btab_fnc_dirTo
	};
	_ctrlScreen drawArrow [_secondPos,_pos,cTabMicroDAGRhighlightColour];
	[_secondPos,_pos] call 43cdo_btab_fnc_dirTo
};
_dstToSecondPos = [_pos,_secondPos] call 43cdo_btab_fnc_distance2D;
call {
	// Call this if we are drawing for a TAD
	if (_this select 5) exitWith {
		_grid8Fig = [_secondPos] call {
			_pos = _this select 0;
			_grid6 = mapGridPosition _pos;
			if (_grid6 == "") exitWith {""};
			
			// Get the exact coordinates
			_x = _pos select 0;
			_y = _pos select 1;
			
			// Calculate the additional precision within the 100m square
			_extraX = floor((_x % 100) / 10);
			_extraY = floor((_y % 100) / 10);
			
			// Split the 6-figure grid into X and Y parts (first 3 and last 3 digits)
			_xPart = _grid6 select [0, 3];  // First 3 digits (X/Easting)
			_yPart = _grid6 select [3, 3];  // Last 3 digits (Y/Northing)
			
			// Combine: X part + extra X digit + "-" + Y part + extra Y digit
			_xPart + str(_extraX) + "-" + _yPart + str(_extraY)
		};
		(_display displayCtrl IDC_CTAB_OSD_HOOK_GRID) ctrlSetText format ["%1",_grid8Fig];
		(_display displayCtrl IDC_CTAB_OSD_HOOK_ELEVATION) ctrlSetText format ["%1m",[round getTerrainHeightASL _secondPos,3] call CBA_fnc_formatNumber];
		//(_display displayCtrl IDC_CTAB_OSD_HOOK_DIR) ctrlSetText format ["%1°/%2",   [_dirToSecondPos,3] call CBA_fnc_formatNumber,[_dstToSecondPos / 1000,2,1] call CBA_fnc_formatNumber];
		if(_dstToSecondPos >=1000) then
		{
			(_display displayCtrl IDC_CTAB_OSD_HOOK_DIR) ctrlSetText format ["%1°/%2km",[_dirToSecondPos,3] call CBA_fnc_formatNumber,[_dstToSecondPos / 1000,2,1] call CBA_fnc_formatNumber];
		}
	    else
	    {
	    	(_display displayCtrl IDC_CTAB_OSD_HOOK_DIR) ctrlSetText format ["%1°/%2m",[_dirToSecondPos,3] call CBA_fnc_formatNumber,[_dstToSecondPos,1,0] call CBA_fnc_formatNumber];
		}
	};
	_grid8Fig = [_secondPos] call {
		_pos = _this select 0;
		_grid6 = mapGridPosition _pos;
		if (_grid6 == "") exitWith {""};
		
		// Get the exact coordinates
		_x = _pos select 0;
		_y = _pos select 1;
		
		// Calculate the additional precision within the 100m square
		_extraX = floor((_x % 100) / 10);
		_extraY = floor((_y % 100) / 10);
		
		// Split the 6-figure grid into X and Y parts (first 3 and last 3 digits)
		_xPart = _grid6 select [0, 3];  // First 3 digits (X/Easting)
		_yPart = _grid6 select [3, 3];  // Last 3 digits (Y/Northing)
		
		// Combine: X part + extra X digit + "-" + Y part + extra Y digit
		_xPart + str(_extraX) + "-" + _yPart + str(_extraY)
	};
	(_display displayCtrl IDC_CTAB_OSD_HOOK_GRID) ctrlSetText format ["%1",_grid8Fig];
	(_display displayCtrl IDC_CTAB_OSD_HOOK_ELEVATION) ctrlSetText format ["%1m",round getTerrainHeightASL _secondPos];
	(_display displayCtrl IDC_CTAB_OSD_HOOK_DIR) ctrlSetText format ["%1° %2",[_dirToSecondPos,3] call CBA_fnc_formatNumber,[_dirToSecondPos] call 43cdo_btab_fnc_degreeToOctant];
	if(_dstToSecondPos >=1000) then
	{
		(_display displayCtrl IDC_CTAB_OSD_HOOK_DST) ctrlSetText format ["%1km",[_dstToSecondPos / 1000,1,2] call CBA_fnc_formatNumber];
	}
	else 
	{
		(_display displayCtrl IDC_CTAB_OSD_HOOK_DST) ctrlSetText format ["%1m",[_dstToSecondPos,1,0] call CBA_fnc_formatNumber];	
	};
};

true
