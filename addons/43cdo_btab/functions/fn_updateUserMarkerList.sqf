/*
	Name: 43cdo_btab_fnc_updateUserMarkerList
	
	Author(s):
		Gundy

	Description:
		Update lists of user markers by finding extracting all the user markers with the right encryption key and then translate the marker data in to a format so that it can be drawn quicker.
		
	Parameters:
		NONE
	
	Returns:
		BOOLEAN - Always TRUE
	
	Example:
		call 43cdo_btab_fnc_updateUserMarkerList;
*/

private ["_playerEncryptionKey","_tempList"];

_playerEncryptionKey = call 43cdo_btab_fnc_getPlayerEncryptionKey;

_tempList = [];
{
	0 = _tempList pushBack [_x select 0,_x select 1 call 43cdo_btab_fnc_translateUserMarker];
} count ([cTab_userMarkerLists,_playerEncryptionKey,[]] call 43cdo_btab_fnc_getFromPairs);

cTabUserMarkerList = _tempList;

true
