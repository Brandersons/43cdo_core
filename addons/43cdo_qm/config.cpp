#include "\43cdo_qm\43cdo_qm_menu_dialog.hpp"

class CfgPatches
{
    class 43cdo_qm
    {
        name = "43cdo_qm";
        units[] = {
            "43cdo_soldier_qm"
        };
        weapons[] = {
            "SCM_Virtus_Assaulter_1_Belt",
            "SCM_Fast_B_2"
        };
        requiredVersion = 0.1;
        addonRootClass = "43cdo_core";
        requiredAddons[] = {
            "43cdo_core",
            "43cdo_units",
            "A3_Characters_F"
        };
    };
};

class CfgVehicles
{   
    class 43cdo_units_soldier_base;
    class 43cdo_soldier_qm : 43cdo_units_soldier_base
    {
        scope = 2;
        displayName = "Quartermaster";
        editorSubcategory = "43cdo_faction_edsubcat_playersqm";
        author = "LCpl. BT";
        // QM will be 0 threat to the enemy
        threat[] = {0, 0, 0};
        value = 100000;
        class loadoutitems
        {
            loadedmagazineprimary[] = {};
            loadedmagazinesecondary[] = {};
            itemsuniform[] ={};
            itemsvest[] = {};
            itemsbackpack[] = {};
        };
        // this is what makes the qm menu show as a scroll option on the qm
        class UserActions
        {
            class 43cdo_qm_menu_open
            {
                // the tooltip
                displayName = "<t size='1.2'><img image='\43cdo_core\data\43cdo_logotemp.paa' size='1'/> Open QM Menu</t>";
                // the icon which shows on the QM
                displayNameDefault = "";
                // if multiple actions are available, this will determine the order (highest first)
                priority = 100;
                // the distance from the QM where the menu will show (in meters)
                radius = 5;
                // this is the memory point for the center of the range check, it's complicated so just leave this as is
                position = "pelvis";
                // this allows the displayNameDefault to show
                showWindow = 1;
                // we want to make sure the menu doesn't dissapear after use
                hideOnUse = 0;
                // this makes the menu available to players only
                onlyForPlayer = 0;
                // the menu will only show if the QM is alive
                condition = "alive this";
                // this opens the menu
                statement = "createDialog '43cdo_qm_menu_dialog';";
            };
        };
    };
};