/*
 	Name: 43cdo_btab_fnc_checkGear
 	
 	Author(s):
		Gundy

 	Description:
		Check if unit is carrying specified items
	
	Parameters:
		0: OBJECT - Unit to test
		1: ARRAY  - Items to test for
 	
 	Returns:
		BOOLEAN - TRUE if unit has at least one item from the list
 	
 	Example:
		_playerHasCtabItem = [player,["Item43cdo_btab","ItemAndroid","ItemMicroDAGR"]] call 43cdo_btab_fnc_checkGear;
*/

private ["_unit","_itemsToCheck"];

_unit = _this select 0;
_itemsToCheck = _this select 1;

_return = false;

{
	if (_x in assigneditems _unit) then {_return = true};
} count _itemsToCheck;

_return
