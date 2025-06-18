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
class 43cdo_logistics_supplyfilters
{
    // this is where the text strings for the sections are stored, their order MUST match the filters below
    sections[] = {"1-2 HQ", "Recce", "Misc", "Test"};
    class filters
    {
        // for each section, put the classnames of the soldiers that should be shown in that section
        // the loadouts will show in the order which you place them in here
        // you can add and remove sections by removing both their entry above and the filter below, just make sure the indexes of the filters match up
        class 43cdo_logistics_supplyfilter_12hq { classes[] = {""}; };
        class 43cdo_logistics_supplyfilter_recce { classes[] = {"43cdo_logistics_box_suppliesrecce", "43cdo_logistics_box_launchersnlaw", "43cdo_logistics_box_medical", "43cdo_logistics_box_demo", "43cdo_logistics_box_breaching"}; };
        class 43cdo_logistics_supplyfilter_misc { classes[] = {"43cdo_logistics_box_medical"}; };
        class 43cdo_logistics_supplyfilter_test { classes[] = {"43cdo_logistics_box_medical", "43cdo_logistics_box_demo", "43cdo_logistics_box_breaching"}; };
    };
};

// I am unsure if this is required in the current version of the mod, but it's here just in case
class RscTitles
{
    titles[] = {};
};

class 43cdo_logistics_menu_dialog
{
    // the unique id for the dialog window
    idd = 4300;
    // this disables being able to drag the window around
    movingEnable = 0;
    // "Specifies whether the game continues while the dialog is shown or not."
    enableSimulation = 1;
    // this sets up the list of sections based on the array above
    onLoad = "_display = _this select 0; _sectionsList = _display displayCtrl 1500; _sections = getArray (configFile >> '43cdo_logistics_supplyfilters' >> 'sections'); {_sectionsList lbAdd _x} forEach _sections;";
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
        class 43cdo_logistics_menu_scrollsections: RscListbox
        {
            idc = 1500;
            x = 0.298906 * safezoneW + safezoneX;
            y = 0.236 * safezoneH + safezoneY;
            w = 0.0996 * safezoneW;
            h = 0.528 * safezoneH;
            onLBSelChanged = "params ['_control', '_index']; private _loadoutsList = (ctrlParent _control) displayCtrl 1501; lbClear _loadoutsList; _loadoutsList lbSetCurSel -1; private _sections = getArray (configFile >> '43cdo_logistics_supplyfilters' >> 'sections'); if (_index >= 0 && _index < count _sections) then { private _filterClasses = []; private _filtersConfig = configFile >> '43cdo_logistics_supplyfilters' >> 'filters'; for '_i' from 0 to (count _filtersConfig - 1) do { _filterClasses pushBack (configName (_filtersConfig select _i)); }; if (_index < count _filterClasses) then { private _filterClass = _filterClasses select _index; private _loadoutClasses = getArray (configFile >> '43cdo_logistics_supplyfilters' >> 'filters' >> _filterClass >> 'classes'); { if (_x != '') then { private _config = configFile >> 'CfgVehicles' >> _x; if (isClass _config) then { private _displayName = getText (_config >> 'displayName'); if (_displayName != '') then { _displayName = _displayName select [7]; private _idx = _loadoutsList lbAdd _displayName; _loadoutsList lbSetData [_idx, _x]; }; }; }; } forEach _loadoutClasses; }; };";
        }; 
        
        class 43cdo_logistics_menu_scrollloadouts: RscListbox
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
                    \
                    private _fnc_addTransportItems = {\
                        params ['_config', '_sectionName'];\
                        private _items = [];\
                        for '_i' from 0 to (count _config - 1) do {\
                            private _item = _config select _i;\
                            if (isClass _item) then {\
                                private _name = getText (_item >> 'name');\
                                if (_name == '') then { _name = getText (_item >> 'weapon'); };\
                                if (_name == '') then { _name = getText (_item >> 'magazine'); };\
                                private _count = getNumber (_item >> 'count');\
                                if (_count > 0) then {\
                                    _items pushBack [_name, _count];\
                                };\
                            };\
                        };\
                        if (count _items > 0) then {\
                            _itemsList lbAdd _sectionName;\
                            _itemsList lbSetColor [(lbSize _itemsList) - 1, [1, 0.5, 0, 1]];\
                            {\
                                private _name = _x select 0;\
                                private _count = _x select 1;\
                                private _displayName = getText (configFile >> 'CfgWeapons' >> _name >> 'displayName');\
                                if (_displayName == '') then { _displayName = getText (configFile >> 'CfgMagazines' >> _name >> 'displayName'); };\
                                if (_displayName == '') then { _displayName = _name; };\
                                private _idx = _itemsList lbAdd (format ['%1x %2', _count, _displayName]);\
                                _itemsList lbSetData [_idx, _name];\
                                private _desc = getText (configFile >> 'CfgWeapons' >> _name >> 'descriptionShort');\
                                if (_desc == '') then { _desc = getText (configFile >> 'CfgMagazines' >> _name >> 'descriptionShort'); };\
                                private _tooltip = _displayName;\
                                if (_desc != '') then { _tooltip = format ['%1\n\n%2', _displayName, _desc]; };\
                                _itemsList lbSetTooltip [_idx, _tooltip];\
                            } forEach _items;\
                            _itemsList lbAdd '';\
                        };\
                    };\
                    \
                    [_config >> 'TransportWeapons', 'WEAPONS'] call _fnc_addTransportItems;\
                    [_config >> 'TransportMagazines', 'MAGAZINES'] call _fnc_addTransportItems;\
                    [_config >> 'TransportItems', 'ITEMS'] call _fnc_addTransportItems;\
                };\
            ";
        };

        class 43cdo_logistics_menu_scrollitems: RscListbox
        {
            idc = 1502;
            x = 0.5181 * safezoneW + safezoneX;
            y = 0.236 * safezoneH + safezoneY;
            w = 0.0996 * safezoneW;
            h = 0.528 * safezoneH;
            onLBSelChanged = "";
        };
        
        class 43cdo_logistics_menu_buttonspawn: RscButtonMenu
        {
            idc = 2403;
            style = 2;
            text = "Spawn Box";
            x = 0.6277 * safezoneW + safezoneX;
            y = 0.709 * safezoneH + safezoneY;
            w = 0.073393 * safezoneW;
            h = 0.055 * safezoneH;
            action = "[] spawn { _display = findDisplay 4300; _loadoutsList = _display displayCtrl 1501; _selectedLoadout = _loadoutsList lbData (lbCurSel _loadoutsList); if (_selectedLoadout != '') then { private _logisticsPos = nearestObject [player, '43cdo_logistics_spawnpos']; private _radius = 2; private _nearby = nearestObjects [_logisticsPos, ['All'], _radius]; _nearby = _nearby select { _x != _logisticsPos }; if (count _nearby > 0) then { ['TaskFailed', ['', 'Spawn area is occupied!']] call BIS_fnc_showNotification; } else { private _box = createVehicle [_selectedLoadout, _logisticsPos, [], 0, 'CAN_COLLIDE']; _box setDir (direction _logisticsPos); ['TaskSucceeded', ['', format['%1 Box Spawned', getText (configFile >> 'CfgVehicles' >> _selectedLoadout >> 'displayName') select [7]]]] call BIS_fnc_showNotification; }; } else { ['TaskFailed', ['', 'No box selected!']] call BIS_fnc_showNotification; }; };";
        };
        
        class 43cdo_logistics_menu_buttonclose: RscButtonMenu
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

        class 43cdo_logistics_menu_logo: RscPictureKeepAspect
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