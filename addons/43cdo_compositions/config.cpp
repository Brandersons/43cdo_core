class CfgPatches {
    class 43cdo_compositions
	{
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        addonRootClass = "43cdo_core";
        requiredAddons[] = {
			"43cdo_core",
			"3DEN"
		};
    };
};

class Cfg3DEN
{
	class Compositions
	{
		class 43cdo_composition_playerspawn
		{
			path = "43cdo_compositions\compositions\legacy_spawn";	// pbo path to a folder containing header.sqe/composition.sqe files
			side = 1;											// 0 opfor, 1 blufor, 2 indfor, 3 civ, 8 Empty/Props
			editorCategory = "43cdo_faction_edcat";						// link to CfgEditorCategories
			editorSubcategory = "43cdo_faction_edsubcat_playersqm";				// link to CfgEditorSubcategories
			displayName = "[43CDO] Player Spawn (Legacy)";
			icon = "\A3\ui_f\data\map\markers\nato\b_inf.paa";	// left side icon in groups list
			useSideColorOnIcon = 1;								// 1 == icon is always colored in faction color
		};
	};
};