 if (isServer) then {
	[] spawn Atmo_fnc_FPSBroadcast;
};

if (hasInterface) then {
	[] spawn Atmo_fnc_FPSMonitor;
};