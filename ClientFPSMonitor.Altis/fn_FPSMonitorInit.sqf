Params ["_expression"];

 if (isServer) then {
	[_expression] spawn Atmo_fnc_FPSBroadcast;
};

if (hasInterface) then {
	[_expression] spawn Atmo_fnc_FPSMonitor;
};