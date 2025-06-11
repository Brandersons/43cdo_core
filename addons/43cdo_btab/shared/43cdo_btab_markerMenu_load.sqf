// 43cdo_btab - Commander's Tablet with FBCB2 Blue Force Tracking
// Battlefield tablet to access real time intel and blue force tracker.
// By - Riouken
// http://forums.bistudio.com/member.php?64032-Riouken
// You may re-use any of this work as long as you provide credit back to me.


disableSerialization;

#include "\43cdo_btab\shared\43cdo_btab_gui_macros.hpp"

43cdo_btabUserSelIcon = [[],0,0,0,""];

_mainPop = _this select 0;
_sendingCtrlArry = _this select 1;
_cntrlScreen = _sendingCtrlArry select 0;

_xpos = _sendingCtrlArry select 2;
_ypos = _sendingCtrlArry select 3;

43cdo_btabUserPos = [_xpos,_ypos];

_tempWorldPos = _cntrlScreen posScreenToWorld [_xpos,_ypos];
43cdo_btabUserSelIcon set [0,[_tempWorldPos select 0,_tempWorldPos select 1]];

_time = call 43cdo_btab_fnc_currentTime;
43cdo_btabUserSelIcon set [4,_time];

[_mainPop] call 43cdo_btab_fnc_userMenuSelect; 