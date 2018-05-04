
class Atmo_FPSMonitor
{
	idd = 4130; // Leet Atmo - sort of!
	duration = 1e+1000;
	//onLoad = "uiNamespace setVariable ['Atmo_fpsMonitor_Display', _this select 0]";
	onLoad = "_this call Atmo_fnc_GetDisplay";
	class controls
	{
		//definitions for Atmo_FpsMonitor
		#define RightScreen 	(safeZoneW + safeZoneX)
		#define LeftScreen 		safeZoneX;
		#define TopScreen 		safeZoneY
		#define BottomScreen	(safeZoneH + safeZoneY)
		#define FPS_Monitor_x 	RightScreen - 162 * UI_GRID_W
		#define FPS_Monitor_y 	BottomScreen - 60 * UI_GRID_H
		#define FPS_Monitor_w   62 * UI_GRID_W // 62 to make grp 60 pixelgrids wide - stops overlap of bars
		#define FPS_Monitor_h 	37 * UI_GRID_H
		class Atmo_Monitor: RscControlsGroupNoScrollbars
		{
			idc = 999;
			x =  "random 1 min 0.5";
			y =  "random 1 min 0.5";
			w = FPS_Monitor_w;
			h = FPS_Monitor_h;
			class controls 
			{
				class IGUIBack_Main: IGUIBack
				{
					x = 0;
					y = 0;
					w = FPS_Monitor_w;
					h = FPS_Monitor_h;
				};
				class TXT_Expression: RscText
				{
					idc = 1000;
					style = ST_LEFT + ST_WITH_RECT;
					x = 1 * UI_GRID_W;
					y = 1 * UI_GRID_H;
					w = FPS_Monitor_w - 2 * UI_GRID_W;
					h = 4 * UI_GRID_H;
				};
				class TXT_Value: RscText
				{
					idc = 1001;
					style = ST_LEFT + ST_WITH_RECT;
					x =  1 * UI_GRID_W;
					y =  5 * UI_GRID_H;
					w = FPS_Monitor_w - 2 * UI_GRID_W;
					h = 4 * UI_GRID_H;
				};
				class IGUIBack_Graph1: IGUIBack
				{
					x = 1 * UI_GRID_W;
					y = 10 * UI_GRID_H;
					w = FPS_Monitor_w - 2 * UI_GRID_W;
					h = 8 * UI_GRID_H;
				};
				class IGUIBack_Graph2: IGUIBack
				{
					x = 1 * UI_GRID_W;
					y = 19 * UI_GRID_H;
					w = FPS_Monitor_w - 2 * UI_GRID_W;
					h = 8 * UI_GRID_H;
				};
				class IGUIBack_Graph3: IGUIBack
				{
					x = 1 * UI_GRID_W;
					y = 28 * UI_GRID_H;
					w = FPS_Monitor_w - 2 * UI_GRID_W;
					h = 8 * UI_GRID_H;
				};
				
				class GRP1: RscControlsGroupNoScrollbars
				{
					idc = 2000;
					x = 1 * UI_GRID_W;
					y = 10 * UI_GRID_H;
					w = FPS_Monitor_w - 2 * UI_GRID_W;
					h = 8 * UI_GRID_H;
				};
				class GRP2: RscControlsGroupNoScrollbars
				{
					idc = 2001;
					x = 1 * UI_GRID_W;
					y = 19 * UI_GRID_H;
					w = FPS_Monitor_w - 2 * UI_GRID_W;
					h = 8 * UI_GRID_H;
				};
				class GRP3: RscControlsGroupNoScrollbars
				{
					idc = 2002;
					x = 1 * UI_GRID_W;
					y = 28 * UI_GRID_H;
					w = FPS_Monitor_w - 2 * UI_GRID_W;
					h = 8 * UI_GRID_H;
				};
			};
		};
	};
};




