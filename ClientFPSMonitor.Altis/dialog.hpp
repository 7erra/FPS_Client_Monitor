class RscTitles
{
	class Atmo_FPSMonitor
	{
		idd = 73001;
		duration = 1e+1000;
		onLoad = "uiNamespace setVariable ['Atmo_fpsMonitor_Display', _this select 0]";
		class controls
		{
			class IGUIBack_2201: IGUIBack
			{
				idc = 2200;
				x = 0.7475 * safezoneW + safezoneX;
				y = 0.324 * safezoneH + safezoneY;
				w = 0.242344 * safezoneW;
				h = 0.297 * safezoneH;
			};
			class IGUIBack_2202: IGUIBack
			{
				idc = 2201;
				x = 0.762969 * safezoneW + safezoneX;
				y = 0.346 * safezoneH + safezoneY;
				w = 0.211406 * safezoneW;
				h = 0.055 * safezoneH;
			};
			class IGUIBack_2203: IGUIBack
			{
				idc = 2201;
				x = 0.762969 * safezoneW + safezoneX;
				y = 0.41 * safezoneH + safezoneY;
				w = 0.211406 * safezoneW;
				h = 0.055 * safezoneH;
			};
			class IGUIBack_2204: IGUIBack
			{
				idc = 2201;
				x = 0.762969 * safezoneW + safezoneX;
				y = 0.47 * safezoneH + safezoneY;
				w = 0.211406 * safezoneW;
				h = 0.055 * safezoneH;
			};
			class TXT_fps: RscText
			{
				idc = 1000;
				text = "FPS: 60.00";
				x = 0.762969 * safezoneW + safezoneX;
				y = 0.346 * safezoneH + safezoneY;
				w = 0.211406 * safezoneW;
				h = 0.055 * safezoneH;
			};
			class GRP1: RscControlsGroupNoScrollbars
			{
				idc = 2302;
				x = 0.762969 * safezoneW + safezoneX;
				y = 0.346 * safezoneH + safezoneY;
				w = 0.211406 * safezoneW;
				h = 0.055 * safezoneH;
			};
			class GRP2: RscControlsGroupNoScrollbars
			{
				idc = 2303;
				x = 0.762969 * safezoneW + safezoneX;
				y = 0.41 * safezoneH + safezoneY;
				w = 0.211406 * safezoneW;
				h = 0.055 * safezoneH;
			};
			class GRP3: RscControlsGroupNoScrollbars
			{
				idc = 2304;
				x = 0.762969 * safezoneW + safezoneX;
				y = 0.47 * safezoneH + safezoneY;
				w = 0.211406 * safezoneW;
				h = 0.055 * safezoneH;
			};
			class myProgressBar: RscVProgress
			{
				idc = 2305;
				colorBar[] =
				{
					"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
					"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
					"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
					"(profilenamespace getvariable ['GUI_BCG_RGB_A',1])"
				};
			}
		};
	};
};

