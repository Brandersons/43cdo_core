#include "\a3\ui_f\hpp\defineCommonGrids.inc"
#include "\a3\ui_f\hpp\defineCommonColors.inc"

class ScrollBar;
class RscObject;
class RscText;
class RscFrame;
class RscLine;
class RscProgress;
class RscPicture;
class RscPictureKeepAspect;
class RscVideo;
class RscHTML;
class RscButton;
class RscShortcutButton;
class RscEdit;
class RscCombo;
class RscListBox;
class RscListNBox;
class RscXListBox;
class RscTree;
class RscSlider;
class RscXSliderH;
class RscActiveText;
class RscActivePicture;
class RscActivePictureKeepAspect;
class RscStructuredText;
class RscToolbox;
class RscControlsGroup;
class RscControlsGroupNoScrollbars;
class RscControlsGroupNoHScrollbars;
class RscControlsGroupNoVScrollbars;
class RscButtonTextOnly;
class RscButtonMenu;
class RscButtonMenuOK;
class RscButtonMenuCancel;
class RscButtonMenuSteam;
class RscMapControl;
class RscMapControlEmpty;
class RscCheckBox;
class RscBackground;

// I cannot remember what this does, I tried removing it and stuff broke so leave it alone
class Default
{
    idd = -1;
    fadein = 0;
    fadeout = 0;
    duration = 0;
};

// this is how you add a new loadout to the QM menu
class 43cdo_qm_loadoutfilters
{
    // this is where the text strings for the sections are stored, their order MUST match the filters below
    sections[] = {"1-2 HQ", "1-2 C/D", "3-1 HQ", "3-1 C/D", "3-1 E/F", "3-1 I/J", "Misc", "Test"};
    class filters
    {
        // for each section, put the classnames of the soldiers that should be shown in that section
        // the loadouts will show in the order which you place them in here
        // you can add and remove sections by removing both their entry above and the filter below, just make sure the indexes of the filters match up
        class 43cdo_qm_loadoutfilter_12hq { classes[] = {"43cdo_units_soldier_12hq", "43cdo_units_soldier_12sig"}; };
        class 43cdo_qm_loadoutfilter_12cd { classes[] = {"43cdo_units_soldier_12c", "43cdo_units_soldier_12d", "43cdo_units_soldier_12cdmarine", "43cdo_units_soldier_12marksman", "43cdo_units_soldier_12sig"}; };
        class 43cdo_qm_loadoutfilter_31hq { classes[] = {"43cdo_units_soldier_31hqa", "43cdo_units_soldier_31hqb", "43cdo_units_soldier_31sig"}; };
        class 43cdo_qm_loadoutfilter_31cd { classes[] = {"43cdo_units_soldier_311ic", "43cdo_units_soldier_312ic", "43cdo_units_soldier_31pointman", "43cdo_units_soldier_31medic", "43cdo_units_soldier_marine"}; };
        class 43cdo_qm_loadoutfilter_31ef { classes[] = {"43cdo_units_soldier_311ic", "43cdo_units_soldier_312ic", "43cdo_units_soldier_31pointman", "43cdo_units_soldier_31medic", "43cdo_units_soldier_marine"}; };
        class 43cdo_qm_loadoutfilter_31ij { classes[] = {"43cdo_units_soldier_311ic", "43cdo_units_soldier_312ic", "43cdo_units_soldier_31gpmg", "43cdo_units_soldier_31marksman", "43cdo_units_soldier_31medic"}; };
        class 43cdo_qm_loadoutfilter_misc { classes[] = {"43cdo_units_soldier_31gpmg", "43cdo_units_soldier_31marine", "43cdo_units_soldier_31marksman", "43cdo_units_soldier_31medic", "43cdo_units_soldier_31pointman"}; };
        class 43cdo_qm_loadoutfilter_test { classes[] = {"43cdo_units_soldier_zeus"}; };
    };
};

// I am unsure if this is required in the current version of the mod, but it's here just in case
class RscTitles
{
    titles[] = {};
};

class 43cdo_qm_menu_dialog
{
    // the unique id for the dialog window
    idd = 4300;
    // this disables being able to drag the window around
    movingEnable = 0;
    // "Specifies whether the game continues while the dialog is shown or not."
    enableSimulation = 1;
    // this sets up the list of sections based on the array above
    onLoad = "_display = _this select 0; _sectionsList = _display displayCtrl 1500; _sections = getArray (configFile >> '43cdo_qm_loadoutfilters' >> 'sections'); {_sectionsList lbAdd _x} forEach _sections;";
    // if for some reason you want to run code when the windows is closed, use this
    onUnload = "";
    
    class controlsBackground
    {
        // this is the background of the dialog window
        class MainBackground: RscBackground
        {
            idc = -1;
            x = 0.288906 * safezoneW + safezoneX;
            y = 0.216 * safezoneH + safezoneY;
            w = 0.422187 * safezoneW;
            h = 0.568 * safezoneH;
            colorBackground[] = {0.1,0.1,0.1,0.8};
        };
        // this is the frame aroudn the of the dialog window
        class MainFrame: RscFrame
        {
            idc = -1;
            x = 0.288906 * safezoneW + safezoneX;
            y = 0.216 * safezoneH + safezoneY;
            w = 0.422187 * safezoneW;
            h = 0.568 * safezoneH;
            colorBackground[] = {0.1,0.1,0.1,0.8};
        };
    };
    
    class controls
    {
        class 43cdo_qm_menu_scrollsections: RscListbox
        {
            idc = 1500;
            x = 0.298906 * safezoneW + safezoneX;
            y = 0.236 * safezoneH + safezoneY;
            w = 0.0996 * safezoneW;
            h = 0.528 * safezoneH;
            onLBSelChanged = "params ['_control', '_index']; private _loadoutsList = (ctrlParent _control) displayCtrl 1501; lbClear _loadoutsList; _loadoutsList lbSetCurSel -1; private _sections = getArray (configFile >> '43cdo_qm_loadoutfilters' >> 'sections'); if (_index >= 0 && _index < count _sections) then { private _filterClasses = []; private _filtersConfig = configFile >> '43cdo_qm_loadoutfilters' >> 'filters'; for '_i' from 0 to (count _filtersConfig - 1) do { _filterClasses pushBack (configName (_filtersConfig select _i)); }; if (_index < count _filterClasses) then { private _filterClass = _filterClasses select _index; private _loadoutClasses = getArray (configFile >> '43cdo_qm_loadoutfilters' >> 'filters' >> _filterClass >> 'classes'); { if (_x != '') then { private _config = configFile >> 'CfgVehicles' >> _x; if (isClass _config) then { private _displayName = getText (_config >> 'displayName'); if (_displayName != '') then { private _idx = _loadoutsList lbAdd _displayName; _loadoutsList lbSetData [_idx, _x]; }; }; }; } forEach _loadoutClasses; }; };";
        }; 
        
        class 43cdo_qm_menu_scrollloadouts: RscListbox
        {
            idc = 1501;
            x = 0.4085 * safezoneW + safezoneX;
            y = 0.236 * safezoneH + safezoneY;
            w = 0.0996 * safezoneW;
            h = 0.528 * safezoneH;
            onLBSelChanged = "\
                params ['_control', '_index'];\
                private _itemsList = (ctrlParent _control) displayCtrl 1502;\
                lbClear _itemsList;\
                private _selectedLoadout = _control lbData _index;\
                if (_selectedLoadout != '') then {\
                    private _config = configFile >> 'CfgVehicles' >> _selectedLoadout;\
                    private _weapons = getArray (_config >> 'weapons') - ['Put', 'Throw', 'Binocular'];\
                    private _equipped = getArray (_config >> 'linkedItems') - ['ItemCompass', 'ItemMap', 'ItemWatch', 'TFAR_rf7800str'];\
                    private _itemsUniform = getArray (_config >> 'loadoutitems' >> 'itemsuniform');\
                    private _itemsVest = getArray (_config >> 'loadoutitems' >> 'itemsvest');\
                    private _itemsBackpack = getArray (_config >> 'loadoutitems' >> 'itemsbackpack');\
                    private _loadedPrimary = getArray (_config >> 'loadoutitems' >> 'loadedmagazineprimary');\
                    private _loadedSecondary = getArray (_config >> 'loadoutitems' >> 'loadedmagazinesecondary');\
                    private _carried = _itemsUniform + _itemsVest + _itemsBackpack + _loadedPrimary + _loadedSecondary;\
                    \
                    private _fnc_groupAndAdd = {\
                        params ['_arr', '_cfgPath', '_sectionName'];\
                        private _counts = createHashMap;\
                        { if (_x != '') then { _counts set [_x, (_counts getOrDefault [_x, 0]) + 1]; }; } forEach _arr;\
                        if (count _arr > 0) then {\
                            _itemsList lbAdd _sectionName;\
                            _itemsList lbSetColor [(lbSize _itemsList) - 1, [1, 0.5, 0, 1]];\
                        };\
                        { \
                            private _count = _y;\
                            if (_count > 0) then {\
                                private _displayName = getText (configFile >> 'CfgWeapons' >> _x >> 'displayName');\
                                if (_displayName == '') then { _displayName = getText (configFile >> 'CfgMagazines' >> _x >> 'displayName'); };\
                                if (_displayName == '') then { _displayName = _x; };\
                                private _idx = _itemsList lbAdd (if (_count > 1) then { format ['%1x %2', _count, _displayName] } else { _displayName });\
                                _itemsList lbSetData [_idx, _x];\
                                private _desc = getText (configFile >> 'CfgWeapons' >> _x >> 'descriptionShort');\
                                if (_desc == '') then { _desc = getText (configFile >> 'CfgMagazines' >> _x >> 'descriptionShort'); };\
                                private _tooltip = _displayName;\
                                if (_desc != '') then { _tooltip = format ['%1\n\n%2', _displayName, _desc]; };\
                                _itemsList lbSetTooltip [_idx, _tooltip];\
                            };\
                        } forEach _counts;\
                        if (count _arr > 0) then { _itemsList lbAdd ''; };\
                    };\
                    \
                    [_weapons, 'CfgWeapons', 'WEAPONS'] call _fnc_groupAndAdd;\
                    [_equipped, 'CfgWeapons', 'EQUIPPED'] call _fnc_groupAndAdd;\
                    [_carried, 'CfgWeapons', 'CARRIED ITEMS'] call _fnc_groupAndAdd;\
                };\
            ";
        };

        class 43cdo_qm_menu_scrollitems: RscListbox
        {
            idc = 1502;
            x = 0.5181 * safezoneW + safezoneX;
            y = 0.236 * safezoneH + safezoneY;
            w = 0.0996 * safezoneW;
            h = 0.528 * safezoneH;
            onLBSelChanged = "";
        };
        
        class 43cdo_qm_menu_buttonload: RscButtonMenu
        {
            idc = 2403;
            style = 2;
            text = "Load";
            x = 0.6277 * safezoneW + safezoneX;
            y = 0.709 * safezoneH + safezoneY;
            w = 0.073393 * safezoneW;
            h = 0.055 * safezoneH;
            action = "[] spawn {\
                _display = findDisplay 4300;\
                _loadoutsList = _display displayCtrl 1501;\
                _selectedLoadout = _loadoutsList lbData (lbCurSel _loadoutsList);\
                if (_selectedLoadout != '') then {\
                    player setVariable ['43cdo_qm_savedloadout', _selectedLoadout, true];\
                    player setVariable ['lastloadedkit', getText (configFile >> 'CfgVehicles' >> _selectedLoadout >> 'displayName')];\
                    _playerFacewear = goggles player;\
                    player setUnitLoadout (configFile >> 'EmptyLoadout');\
                    player setUnitLoadout (configFile >> 'CfgVehicles' >> _selectedLoadout);\
                    uiSleep 0.1;\
                    { player addItemToUniform _x; } forEach getArray (configFile >> 'CfgVehicles' >> _selectedLoadout >> 'loadoutitems' >> 'itemsuniform');\
                    { player addItemToVest _x; } forEach getArray (configFile >> 'CfgVehicles' >> _selectedLoadout >> 'loadoutitems' >> 'itemsvest');\
                    { player addItemToBackpack _x; } forEach getArray (configFile >> 'CfgVehicles' >> _selectedLoadout >> 'loadoutitems' >> 'itemsbackpack');\
                    { player addPrimaryWeaponItem _x; } forEach getArray (configFile >> 'CfgVehicles' >> _selectedLoadout >> 'loadoutitems' >> 'loadedmagazineprimary');\
                    { player addHandgunItem _x; } forEach getArray (configFile >> 'CfgVehicles' >> _selectedLoadout >> 'loadoutitems' >> 'loadedmagazinesecondary');\
                    if (_playerFacewear != '') then { player addGoggles _playerFacewear; };\
                    private _medicLevel = getNumber (configFile >> 'CfgVehicles' >> _selectedLoadout >> 'attendant');\
                    private _engineerLevel = getNumber (configFile >> 'CfgVehicles' >> _selectedLoadout >> 'engineer');\
                    player setVariable ['ace_medical_medicclass', _medicLevel, true];\
                    player setVariable ['ACE_IsEngineer', _engineerLevel, true];\
                    ['TaskSucceeded', ['', format['%1 Loadout Applied', getText (configFile >> 'CfgVehicles' >> _selectedLoadout >> 'displayName')]]] call BIS_fnc_showNotification;\
                } else {\
                    ['TaskSucceeded', ['', 'No loadout selected!']] call BIS_fnc_showNotification;\
                };\
            };";
        };
        
        class 43cdo_qm_menu_buttonarsenal: RscButtonMenu
        {
            idc = 2400;
            style = 2;
            text = "Arsenal";
            x = 0.6277 * safezoneW + safezoneX;
            y = 0.634 * safezoneH + safezoneY;
            w = 0.073393 * safezoneW;
            h = 0.055 * safezoneH;
            action = "closeDialog 0; [player, player, false] call ace_arsenal_fnc_openBox;";
        };
        
        class 43cdo_qm_menu_buttonrestore: RscButtonMenu
        {
            idc = 2404;
            style = 2;
            text = "Restore";
            x = 0.6277 * safezoneW + safezoneX;
            y = 0.484 * safezoneH + safezoneY;
            w = 0.073393 * safezoneW;
            h = 0.055 * safezoneH;
            action = "[] spawn {\
                if (KitSaved isEqualTo false) then {\
                    ['TaskFailed', ['You do not have a saved kit']] call BIS_fnc_showNotification;\
                } else {\
                    player setUnitLoadout (player getVariable ['Saved_Loadout',[]]);\
                    player setVariable ['ace_medical_medicclass', trainingmedic, true];\
                    player setVariable ['ACE_IsEngineer', trainingengineer, true];\
                    ['TaskSucceeded', ['', format['%1 kit loaded!', player getVariable ['kitname', 'Unknown']]]] call BIS_fnc_showNotification;\
                };\
            };";
        };
        
        class 43cdo_qm_menu_buttonsave: RscButtonMenu
        {
            idc = 2401;
            style = 2;
            text = "Save";
            x = 0.6277 * safezoneW + safezoneX;
            y = 0.559 * safezoneH + safezoneY;
            w = 0.073393 * safezoneW;
            h = 0.055 * safezoneH;
            action = "[] spawn { \
                _display = findDisplay 4300; \
                _loadoutsList = _display displayCtrl 1501; \
                _selectedLoadout = _loadoutsList lbData (lbCurSel _loadoutsList); \
                if (_selectedLoadout != '') then { \
                    player setVariable ['Saved_Loadout',getUnitLoadout player]; \
                    player setVariable ['kitname', player getVariable 'lastloadedkit']; \
                    trainingmedic = player getVariable 'ace_medical_medicclass'; \
                    trainingengineer = player getVariable 'ACE_IsEngineer'; \
                    KitSaved = true; \
                    ['TaskSucceeded', ['', format['%1 Loadout Saved', player getVariable 'lastloadedkit']]] call BIS_fnc_showNotification; \
                } else { \
                    player setVariable ['Saved_Loadout',getUnitLoadout player]; \
                    ['TaskSucceeded', ['', 'Current Loadout Saved!']] call BIS_fnc_showNotification; \
                }; \
            };";
        };
        
        class 43cdo_qm_menu_buttonclose: RscButtonMenu
        {
            idc = 2402;
            style = 2;
            text = "Close";
            x = 0.6277 * safezoneW + safezoneX;
            y = 0.236 * safezoneH + safezoneY;
            w = 0.073393 * safezoneW;
            h = 0.055 * safezoneH;
            action = "closeDialog 0;";
        };

        class 43cdo_qm_menu_logo: RscPictureKeepAspect
        {
            idc = -1;
            text = "\43cdo_core\data\43cdo_logotemp.paa";
            x = 0.6277 * safezoneW + safezoneX;
            y = 0.311 * safezoneH + safezoneY;
            w = 0.073393 * safezoneW;
            h = 0.073393 * safezoneW;
            colorBackground[] = {0,0,0,0};
        };
    };
};