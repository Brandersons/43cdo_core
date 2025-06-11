class CfgPatches
{
	class 43cdo_core
	{
		name="[43CDO] Core";
		author="LCpl. BT";
		url="";
		requiredAddons[]=
		{
			"3DEN",
			"A3_Characters_F",
			"a3_ui_f",
			"a3_ui_f_aow",
			"a3_ui_f_enoch",
			"a3_ui_f_orange",
			"a3_ui_f_oldman",
			"a3_ui_f_tacops",
			"ef_ui",
			"scm_l403A1",
			"scm_attachments",
			"UKSF_LMT"
		};
		requiredVersion= 0.01;
		units[]={};
		weapons[]={};
		magazines[]={};
	};
};

class CfgFactionClasses
{
    class 43cdo_faction
    {
        displayName = "[43CDO] 43 Commando";
        priority = -25;
        side = 1;
        icon = "";
    };
};

class CfgEditorCategories
{
    class 43cdo_faction_edcat
    {
        displayName = "[43CDO] 43 Commando";
    };
    class 43cdo_faction_edcat_objects
    {
        displayName = "[43CDO] Objects";
    };
};

class CfgEditorSubcategories
{
    class 43cdo_faction_edsubcat_men
    {
        displayName = "[43CDO] Men";
    };
    class 43cdo_faction_edsubcat_playersqm
    {
        displayName = "[43CDO] Players & QM";
    };
    class 43cdo_faction_edsubcat_props
    {
        displayName = "[43CDO] Props";
    };
    class 43cdo_faction_edsubcat_supplies
    {
        displayName = "[43CDO] Supplies";
    };
    class 43cdo_faction_edsubcat_cars
    {
        displayName = "[43CDO] Cars";
    };
    class 43cdo_faction_edsubcat_carsdesert
    {
        displayName = "[43CDO] Cars (Desert)";
    };
    class 43cdo_faction_edsubcat_carsgreen
    {
        displayName = "[43CDO] Cars (Green)";
    };
    class 43cdo_faction_edsubcat_carswoodland
    {
        displayName = "[43CDO] Cars (Woodland)";
    };
    class 43cdo_faction_edsubcat_jackaldesert
    {
        displayName = "[43CDO] Jackals (Desert)";
    };
    class 43cdo_faction_edsubcat_jackalgreen
    {
        displayName = "[43CDO] Jackals (Green)";
    };
    class 43cdo_faction_edsubcat_jackalwoodland
    {
        displayName = "[43CDO] Jackals (Woodland)";
    };
    class 43cdo_faction_edsubcat_coyotedesert
    {
        displayName = "[43CDO] Coyotes (Desert)";
    };
    class 43cdo_faction_edsubcat_coyotegreen
    {
        displayName = "[43CDO] Coyotes (Green)";
    };
    class 43cdo_faction_edsubcat_coyotewoodland
    {
        displayName = "[43CDO] Coyotes (Woodland)";
    };
};