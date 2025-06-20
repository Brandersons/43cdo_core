// 43cdo_btab - Commander's Tablet with FBCB2 Blue Force Tracking
// Battlefield tablet to access real time intel and blue force tracker.
// By - Riouken
// http://forums.bistudio.com/member.php?64032-Riouken
// You may re-use any of this work as long as you provide credit back to me.

// define vehicles that have FBCB2 monitor and broadcast it
if (isArray (ConfigFile >> "43cdo_btab_settings" >> "43cdo_btab_vehicleClass_has_FBCB2")) then {
	43cdo_btab_vehicleClass_has_FBCB2_server = getArray (ConfigFile >> "43cdo_btab_settings" >> "43cdo_btab_vehicleClass_has_FBCB2");
} else {
	43cdo_btab_vehicleClass_has_FBCB2_server = ["MRAP_01_base_F","MRAP_02_base_F","MRAP_03_base_F","Wheeled_APC_F","Tank","Truck_01_base_F","Truck_03_base_F", "DEVAS_MEKO200TN", "DEVAS_Type209"];
};
publicVariable "43cdo_btab_vehicleClass_has_FBCB2_server";

// define vehicles that have TAD  and broadcast it
if (isArray (ConfigFile >> "43cdo_btab_settings" >> "43cdo_btab_vehicleClass_has_TAD")) then {
	43cdo_btab_vehicleClass_has_TAD_server = getArray (ConfigFile >> "43cdo_btab_settings" >> "43cdo_btab_vehicleClass_has_TAD");
} else {
	43cdo_btab_vehicleClass_has_TAD_server = ["Helicopter","Plane"];
};
publicVariable "43cdo_btab_vehicleClass_has_TAD_server";

// define items that have a helmet camera and broadcast it
if (isArray (ConfigFile >> "43cdo_btab_settings" >> "43cdo_btab_helmetClass_has_HCam")) then {
	43cdo_btab_helmetClass_has_HCam_server = getArray (ConfigFile >> "43cdo_btab_settings" >> "43cdo_btab_helmetClass_has_HCam");
} else {
	43cdo_btab_helmetClass_has_HCam_server = ["H_HelmetB_light","H_Helmet_Kerry","H_HelmetSpecB","H_HelmetO_ocamo","BWA3_OpsCore_Fleck_Camera","BWA3_OpsCore_Schwarz_Camera","BWA3_OpsCore_Tropen_Camera"
	,"rhsusf_opscore_ut_pelt_nsw_cam","rhsusf_opscore_paint_pelt_nsw_cam","rhsusf_opscore_mc_cover_pelt_cam","rhsusf_opscore_fg_pelt_cam","rhsusf_opscore_ut_pelt_cam"];
};
publicVariable "43cdo_btab_helmetClass_has_HCam_server";

43cdo_btab_userMarkerLists = [];
43cdo_btab_userMarkerTransactionId = -1;

[] spawn {
	waituntil {time > 0};
	sleep .1;
	
	while {true} do {
		["43cdo_btab_updatePulse"] call CBA_fnc_globalEvent;
		sleep 30;
	};
};
