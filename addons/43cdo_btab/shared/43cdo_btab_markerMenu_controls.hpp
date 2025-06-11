class MainSubmenu: 43cdo_btab_RscControlsGroup
{
	#ifndef 43cdo_btab_IS_TABLET
		#define 43cdo_btab_MENU_MAX_ELEMENTS 4
	#else
		#define 43cdo_btab_MENU_MAX_ELEMENTS 5
	#endif
	idc = 3300;
	x = MENU_X;
	y = MENU_Y;
	w = MENU_W;
	h = MENU_H(43cdo_btab_MENU_MAX_ELEMENTS);
	class controls
	{
		class mainbg: 43cdo_btab_IGUIBack
		{
			idc = IDC_USRMN_MAINBG;
			x = 0;
			y = 0;
			w = MENU_W;
			h = MENU_H(43cdo_btab_MENU_MAX_ELEMENTS);
		};
		class op4btn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_OP4BTN;
			text = "Enemy SALUTE"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(1);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "[11] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class medbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_MEDBTN;
			text = "Medical"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(2);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "[21] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class genbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_GENBTN;
			text = "General"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(3);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "[31] call 43cdo_btab_fnc_userMenuSelect;";
		};
		#ifdef 43cdo_btab_IS_TABLET
			class lockUavCam: 43cdo_btab_MenuItem
			{
				idc = -1;
				text = "Lock UAV Cam"; //--- ToDo: Localize;
				toolTip = "Lock UAV Cam to this position, a UAV has to be previously selected";
				x = 0;
				y = MENU_elementY(4);
				w = MENU_W;
				h = MENU_elementH;
				sizeEx = MENU_sizeEx;
				action = "[2] call 43cdo_btab_fnc_userMenuSelect;";
			};
		#endif
		class exit: 43cdo_btab_MenuExit
		{
			idc = -1;
			text = "Exit"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(43cdo_btab_MENU_MAX_ELEMENTS);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "[0] call 43cdo_btab_fnc_userMenuSelect;";
		};
	};
};

class EnemySub1: 43cdo_btab_RscControlsGroup
{
	#define 43cdo_btab_MENU_MAX_ELEMENTS 9
	idc = 3301;
	x = MENU_X;
	y = MENU_Y;
	w = MENU_W;
	h = MENU_H(43cdo_btab_MENU_MAX_ELEMENTS);
	class controls
	{
		class IGUIBack_2201: 43cdo_btab_IGUIBack
		{
			idc = IDC_USRMN_IGUIBACK_2202;
			x = 0;
			y = 0;
			w = MENU_W;
			h = MENU_H(43cdo_btab_MENU_MAX_ELEMENTS);
		};
		class infbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_INFBTN;
			text = "Infantry"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(1);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,0];[12] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class mecinfbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_MECINFBTN;
			text = "Mechanized Inf"; //--- ToDo: Localize;
			toolTip = "Equipped with APCs/IFVs";
			x = 0;
			y = MENU_elementY(2);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,1];[12] call 43cdo_btab_fnc_userMenuSelect;";
		};

		class motrinfbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_MOTRINFBTN;
			text = "Motorized Inf"; //--- ToDo: Localize;
			toolTip = "Equipped with un-protected vehicles";
			x = 0;
			y = MENU_elementY(3);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,2];[12] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class amrbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_AMRBTN;
			text = "Armor"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(4);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,3];[12] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class helibtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_HELIBTN;
			text = "Helicopter"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(5);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,4];[12] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class plnbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_PLNBTN;
			text = "Plane"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(6);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,5];[12] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class navybtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_UKNBTN;
			text = "Naval"; //--- ToDo: Localize;
			toolTip = "Ships, boats and submarines";
			x = 0;
			y = MENU_elementY(7);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,41];[12] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class uknbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_UKNBTN;
			text = "Unknown"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(8);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,6];[12] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class exit: 43cdo_btab_MenuExit
		{
			idc = -1;
			text = "Exit"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(43cdo_btab_MENU_MAX_ELEMENTS);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "[0] call 43cdo_btab_fnc_userMenuSelect;";
		};
	};
};

class EnemySub2: 43cdo_btab_RscControlsGroup
{
	#define 43cdo_btab_MENU_MAX_ELEMENTS 6
	idc = 3303;
	x = MENU_X;
	y = MENU_Y;
	w = MENU_W;
	h = MENU_H(43cdo_btab_MENU_MAX_ELEMENTS);
	class controls
	{
		class IGUIBack_2202: 43cdo_btab_IGUIBack
		{
			idc = IDC_USRMN_IGUIBACK_2202;
			x = 0;
			y = 0;
			w = MENU_W;
			h = MENU_H(43cdo_btab_MENU_MAX_ELEMENTS);
		};
		class ftbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_FTBTN;
			text = "Singular"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(1);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "[14] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class patbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_PATBTN;
			text = "Patrol"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(2);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [2,1];[13] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class sqdbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_SQDBTN;
			text = "Squad"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(3);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [2,2];[13] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class sctbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_SCTBTN;
			text = "Section"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(4);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [2,3];[13] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class pltnbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_PLTNBTN;
			text = "Platoon"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(5);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [2,4];[13] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class exit: 43cdo_btab_MenuExit
		{
			idc = -1;
			text = "Exit"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(43cdo_btab_MENU_MAX_ELEMENTS);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "[0] call 43cdo_btab_fnc_userMenuSelect;";
		};
	};
};

class EnemySub3: 43cdo_btab_RscControlsGroup
{
	#define 43cdo_btab_MENU_MAX_ELEMENTS 10
	idc = 3304;
	x = MENU_X;
	y = MENU_Y;
	w = MENU_W;
	h = MENU_H(43cdo_btab_MENU_MAX_ELEMENTS);
	class controls
	{
		class IGUIBack_2203: 43cdo_btab_IGUIBack
		{
			idc = IDC_USRMN_IGUIBACK_2203;
			x = 0;
			y = 0;
			w = MENU_W;
			h = MENU_H(43cdo_btab_MENU_MAX_ELEMENTS);
		};
		class stnbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_STNBTN;
			text = "Stationary"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(1);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "[1] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class nthbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_NTHBTN;
			text = "N"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(2);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [3,1];[1] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class nebtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_NEBTN;
			text = "NE"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(3);
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [3,2];[1] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class ebtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_EBTN;
			text = "E"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(4);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [3,3];[1] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class sebtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_SEBTN;
			text = "SE"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(5);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [3,4];[1] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class sbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_SBTN;
			text = "S"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(6);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [3,5];[1] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class swbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_SWBTN;
			text = "SW"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(7);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [3,6];[1] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class wbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_WBTN;
			text = "W"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(8);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [3,7];[1] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class RscText_1022: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_RSCTEXT_1022;
			text = "NW"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(9);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [3,8];[1] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class exit: 43cdo_btab_MenuExit
		{
			idc = -1;
			text = "Exit"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(43cdo_btab_MENU_MAX_ELEMENTS);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "[0] call 43cdo_btab_fnc_userMenuSelect;";
		};
	};
};

class EnemySub4: 43cdo_btab_RscControlsGroup
{
	#define 43cdo_btab_MENU_MAX_ELEMENTS 8
	idc = 3307;
	x = MENU_X;
	y = MENU_Y;
	w = MENU_W;
	h = MENU_H(43cdo_btab_MENU_MAX_ELEMENTS);
	class controls
	{
		class IGUIBack_2202: 43cdo_btab_IGUIBack
		{
			idc = IDC_USRMN_IGUIBACK_2202;
			x = 0;
			y = 0;
			w = MENU_W;
			h = MENU_H(43cdo_btab_MENU_MAX_ELEMENTS);
		};
		class rifle_btn: 43cdo_btab_MenuItem
		{
			idc = -1;
			text = "Rifle"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(1);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,7];[13] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class lmg_btn: 43cdo_btab_MenuItem
		{
			idc = -1;
			text = "MG"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(2);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,8];[13] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class at_btn: 43cdo_btab_MenuItem
		{
			idc = -1;
			text = "AT"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(3);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,9];[13] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class mmg_btn: 43cdo_btab_MenuItem
		{
			idc = -1;
			text = "Static MG"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(4);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,10];[13] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class mat_btn: 43cdo_btab_MenuItem
		{
			idc = -1;
			text = "Static AT"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(5);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,11];[13] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class aa_btn: 43cdo_btab_MenuItem
		{
			idc = -1;
			text = "Static AA"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(6);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,13];[13] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class mmortar_btn: 43cdo_btab_MenuItem
		{
			idc = -1;
			text = "Mortar"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(7);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,12];[13] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class exit: 43cdo_btab_MenuExit
		{
			idc = -1;
			text = "Exit"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(43cdo_btab_MENU_MAX_ELEMENTS);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "[0] call 43cdo_btab_fnc_userMenuSelect;";
		};
	};
};

class CasulSub1: 43cdo_btab_RscControlsGroup
{
	#define 43cdo_btab_MENU_MAX_ELEMENTS 5
	idc = 3305;
	x = MENU_X;
	y = MENU_Y;
	w = MENU_W;
	h = MENU_H(43cdo_btab_MENU_MAX_ELEMENTS);
	class controls
	{
		class IGUIBack_2204: 43cdo_btab_IGUIBack
		{
			idc = IDC_USRMN_IGUIBACK_2204;
			x = 0;
			y = 0;
			w = MENU_W;
			h = MENU_H(43cdo_btab_MENU_MAX_ELEMENTS);
		};
		class casltybtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_CASLTYBTN;
			text = "Casualty"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(1);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,20];[1] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class ccpbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_CCPBTN;
			text = "CCP"; //--- ToDo: Localize;
			toolTip = "Casualty Collection Point";
			x = 0;
			y = MENU_elementY(2);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,21];[1] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class basbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_BASBTN;
			text = "BAS"; //--- ToDo: Localize;
			toolTip = "Battalion Aid Station";
			x = 0;
			y = MENU_elementY(3);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,22];[1] call 43cdo_btab_fnc_userMenuSelect;";
		};
		// Mass Casualty Incident
		class mcibtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_MCIBTN;
			text = "MCI"; //--- ToDo: Localize;
			toolTip = "Mass Casualty Incident";
			x = 0;
			y = MENU_elementY(4);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,23];[1] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class exit: 43cdo_btab_MenuExit
		{
			idc = -1;
			text = "Exit"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(43cdo_btab_MENU_MAX_ELEMENTS);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "[0] call 43cdo_btab_fnc_userMenuSelect;";
		};
	};
};

class GenSub1: 43cdo_btab_RscControlsGroup
{
	//#define 43cdo_btab_MENU_MAX_ELEMENTS 3
	#define 43cdo_btab_MENU_MAX_ELEMENTS 11
	idc = 3306;
	x = MENU_X;
	y = MENU_Y;
	w = MENU_W;
	h = MENU_H(43cdo_btab_MENU_MAX_ELEMENTS);
	class controls
	{
		class IGUIBack_2205: 43cdo_btab_IGUIBack
		{
			idc = IDC_USRMN_IGUIBACK_2205;
			x = 0;
			y = 0;
			w = MENU_W;
			h = MENU_H(43cdo_btab_MENU_MAX_ELEMENTS);
		};
		class hqbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_HQBTN;
			text = "HQ"; //--- ToDo: Localize;
			toolTip = "Headquaters";
			x = 0;
			y = MENU_elementY(1);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,30];[1] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class lzbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_LZBTN;
			text = "LZ"; //--- ToDo: Localize;
			toolTip = "Landing Zone";
			x = 0;
			y = MENU_elementY(2);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,31];[1] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class lrpbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_LZBTN;
			text = "LRP"; //--- ToDo: Localize;
			toolTip = "Logistic Resupply Point";
			x = 0;
			y = MENU_elementY(3);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,32];[1] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class rlypbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_LZBTN;
			text = "RlyP"; //--- ToDo: Localize;
			toolTip = "Rally Point";
			x = 0;
			y = MENU_elementY(4);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,34];[1] call 43cdo_btab_fnc_userMenuSelect;";
		};
		class epbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_LZBTN;
			text = "EP"; //--- ToDo: Localize;
			toolTip = "Extraction Point";
			x = 0;
			y = MENU_elementY(5);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,36];[1] call 43cdo_btab_fnc_userMenuSelect;";
		};

		class spbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_LZBTN;
			text = "SP"; //--- ToDo: Localize;
			toolTip = "Start Point";
			x = 0;
			y = MENU_elementY(6);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,38];[1] call 43cdo_btab_fnc_userMenuSelect;";
		};

		class ckpbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_LZBTN;
			text = "CKP"; //--- ToDo: Localize;
			toolTip = "Check Point";
			x = 0;
			y = MENU_elementY(7);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,37];[1] call 43cdo_btab_fnc_userMenuSelect;";
		};

		class rpbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_LZBTN;
			text = "RP"; //--- ToDo: Localize;
			toolTip = "Release Point";
			x = 0;
			y = MENU_elementY(8);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,40];[1] call 43cdo_btab_fnc_userMenuSelect;";
		};

		class aapbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_LZBTN;
			text = "AA"; //--- ToDo: Localize;
			toolTip = "Assembly Area";
			x = 0;
			y = MENU_elementY(9);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,39];[1] call 43cdo_btab_fnc_userMenuSelect;";
		};

		class aopbtn: 43cdo_btab_MenuItem
		{
			idc = IDC_USRMN_LZBTN;
			text = "AO"; //--- ToDo: Localize;
			toolTip = "Objective";
			x = 0;
			y = MENU_elementY(10);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "43cdo_btabUserSelIcon set [1,35];[1] call 43cdo_btab_fnc_userMenuSelect;";
		};

		class exit: 43cdo_btab_MenuExit
		{
			idc = -1;
			text = "Exit"; //--- ToDo: Localize;
			x = 0;
			y = MENU_elementY(43cdo_btab_MENU_MAX_ELEMENTS);
			w = MENU_W;
			h = MENU_elementH;
			sizeEx = MENU_sizeEx;
			action = "[0] call 43cdo_btab_fnc_userMenuSelect;";
		};
	};
};
