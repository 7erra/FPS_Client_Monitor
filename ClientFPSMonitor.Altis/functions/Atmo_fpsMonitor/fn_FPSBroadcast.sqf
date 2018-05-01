scriptName "Atmo_FPSBroadccast";
while {true} do {
	missionNamespace setVariable ["Atmo_FPSMonitor_ServerFPS", diag_fps, true];	
	sleep 1;
};
