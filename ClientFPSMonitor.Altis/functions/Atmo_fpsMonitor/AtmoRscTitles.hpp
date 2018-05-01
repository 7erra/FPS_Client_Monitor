class myProgressBar: RscVProgress
{
	colorBar[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_A',0])"
	};
	shadow = 0;
	texture = "#(argb,8,8,3)color(1,1,1,1)";
};



class Atmo_FPSMonitor
{
	idd = 73001;
	duration = 1e+1000;
	onLoad = "uiNamespace setVariable ['Atmo_fpsMonitor_Display', _this select 0]";
	class controls
	{
		//definitions for Atmo_FpsMonitor
		#define RightScreen 	(safeZoneW + safeZoneX)
		#define LeftScreen 		safeZoneX;
		#define TopScreen 		safeZoneY
		#define BottomScreen	(safeZoneH + safeZoneY)
		#define FPS_Monitor_x 	RightScreen - 62 * UI_GRID_W
		#define FPS_Monitor_y 	BottomScreen - 60 * UI_GRID_H
		#define FPS_Monitor_w   62 * UI_GRID_W // 62 to make grp 60 pixelgrids wide - stops overlap of bars
		#define FPS_Monitor_h 	28 * UI_GRID_H
		class IGUIBack_Main: IGUIBack
		{
			x = FPS_Monitor_x;
			y = FPS_Monitor_y;
			w = FPS_Monitor_w;
			h = FPS_Monitor_h;
		};
		class IGUIBack_Graph1: IGUIBack
		{
			x = FPS_Monitor_x + 1 * UI_GRID_W;
			y = FPS_Monitor_y + 1 * UI_GRID_H;
			w = FPS_Monitor_w - 2 * UI_GRID_W;
			h = 8 * UI_GRID_H;
		};
		class IGUIBack_Graph2: IGUIBack
		{
			x = FPS_Monitor_x + 1 * UI_GRID_W;
			y = FPS_Monitor_y + 10 * UI_GRID_H;
			w = FPS_Monitor_w - 2 * UI_GRID_W;
			h = 8 * UI_GRID_H;
		};
		class IGUIBack_Graph3: IGUIBack
		{
			x = FPS_Monitor_x + 1 * UI_GRID_W;
			y = FPS_Monitor_y + 19 * UI_GRID_H;
			w = FPS_Monitor_w - 2 * UI_GRID_W;
			h = 8 * UI_GRID_H;
		};
		
		class GRP1: RscControlsGroupNoScrollbars
		{
			idc = 2000;
			x = FPS_Monitor_x + 1 * UI_GRID_W;
			y = FPS_Monitor_y + 1 * UI_GRID_H;
			w = FPS_Monitor_w - 2 * UI_GRID_W;
			h = 8 * UI_GRID_H;
		};
		class GRP2: RscControlsGroupNoScrollbars
		{
			idc = 2001;
			x = FPS_Monitor_x + 1 * UI_GRID_W;
			y = FPS_Monitor_y + 10 * UI_GRID_H;
			w = FPS_Monitor_w - 2 * UI_GRID_W;
			h = 8 * UI_GRID_H;
		};
		class GRP3: RscControlsGroupNoScrollbars
		{
			idc = 2002;
			x = FPS_Monitor_x + 1 * UI_GRID_W;
			y = FPS_Monitor_y + 19 * UI_GRID_H;
			w = FPS_Monitor_w - 2 * UI_GRID_W;
			h = 8 * UI_GRID_H;
		};
		class TXT_fps: RscText
		{
			idc = 1000;
			text = "Client FPS: 60.00, Max: 0 "; //--- ToDo: Localize;
			x = FPS_Monitor_x + 1 * UI_GRID_W;
			y = FPS_Monitor_y + 1 * UI_GRID_H;
			w = FPS_Monitor_w - 2 * UI_GRID_W;
			h = 8 * UI_GRID_H;
		};


	};
};



