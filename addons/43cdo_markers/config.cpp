class CfgPatches
{
	class 43cdo_markers
	{
		name="[43CDO] Markers";
		author="LCpl. BT";
		addonRootClass = "43cdo_core";
		requiredAddons[]= 
		{
			"43cdo_core",
			"a3_ui_f"
		};
		requiredVersion= 0.01;
		units[]={};
		weapons[]={};
	};
};

class CfgMarkerClasses
{
	class 43cdo_markers_markerclass
	{
		displayName = "[43CDO] Markers";
	};
};

class CfgMarkers
{
	class 43cdo_marker_43cdo
	{
		name="[43CDO] 43 Commando";
		icon="43cdo_markers\data\RA_Flag.paa";
		scope = 2;
		curatorScope = 2;
		markerClass = "43cdo_markers_markerclass";
		colorName = "ColorWhite";
		color[]={1,1,1,1};
		size= 32;
		shadow = 0;
		showEditorMarkerColor = 0;
	};
	class 43cdo_marker_12ab : 43cdo_marker_43cdo
	{
		name="[43CDO] 1-2 A/B";
		icon="43cdo_markers\data\RA_Flag.paa";
	};
	class 43cdo_marker_12cd : 43cdo_marker_43cdo
	{
		name="[43CDO] 1-2 C/D";
		icon="43cdo_markers\data\RA_Flag.paa";
	};
	class 43cdo_marker_12sig : 43cdo_marker_43cdo
	{
		name="[43CDO] 1-2 Signaller";
		icon="43cdo_markers\data\RA_Flag.paa";
	};
	class 43cdo_marker_31ab : 43cdo_marker_43cdo
	{
		name="[43CDO] 3-1 A/B";
		icon="43cdo_markers\data\RA_Flag.paa";
	};
	class 43cdo_marker_31cd : 43cdo_marker_43cdo
	{
		name="[43CDO] 3-1 C/D";
		icon="43cdo_markers\data\RA_Flag.paa";
	};
	class 43cdo_marker_31ef : 43cdo_marker_43cdo
	{
		name="[43CDO] 3-1 E/F";
		icon="43cdo_markers\data\RA_Flag.paa";
	};
	class 43cdo_marker_31gh : 43cdo_marker_43cdo
	{
		name="[43CDO] 3-1 G/H";
		icon="43cdo_markers\data\RA_Flag.paa";
	};
	class 43cdo_marker_31ij : 43cdo_marker_43cdo
	{
		name="[43CDO] 3-1 I/J";
		icon="43cdo_markers\data\RA_Flag.paa";
	};
	class 43cdo_marker_31sig : 43cdo_marker_43cdo
	{
		name="[43CDO] 3-1 Signaller";
		icon="43cdo_markers\data\RA_Flag.paa";
	};
};