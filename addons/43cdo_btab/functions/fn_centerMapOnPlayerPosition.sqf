/*
 	Name: 43cdo_btab_fnc_centerMapOnPlayerPosition
 	
 	Author(s):
		Gundy

 	Description:
		Center BFT Map on current player position
	
	Parameters:
		0: STRING - Name of uiNamespace display / dialog variable
 	
 	Returns:
		BOOLEAN - TRUE
 	
 	Example:
		['cTab_TAD_dlg'] call 43cdo_btab_fnc_centerMapOnPlayerPosition;
*/

private [];

[_this select 0,[["mapWorldPos",getPosASL vehicle cTab_player]],true,true] call 43cdo_btab_fnc_setSettings;

true
