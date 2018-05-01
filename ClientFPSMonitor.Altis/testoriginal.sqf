disableSerialization;
params ["_display"];
#define CTRL(VAR,IDC) VAR = _display displayCtrl IDC;
//CTRL(_GRPframes,9901)
CTRL(_TXTfps,1000)
CTRL(_GRPframes, 2300)


_iteration = 0;
_barArray = [];
_maxFps = 65;
_maxWidth = ctrlPosition _GRPframes select 2;
_width =  _maxWidth/60;
_prevBar = controlNull;
while {!isNull _display} do {
	_frames = diag_fps;
	_TXTfps ctrlSetText format ["FPS: %1",_frames toFixed 2];
	_newBar = _display ctrlCreate ["RscVProgress",-1,_GRPframes];
	{
		_x ctrlSetPosition [_maxWidth-((_forEachIndex+2)*_width),0];
		_x ctrlCommit 0;
	} forEach _barArray;
	_barArray = [_newBar] +_barArray;
	_newBar ctrlSetPosition [
		_maxWidth-_width,
		0,
		_width,
		0.252 * safezoneH
	];
	_prevBar = _newBar;
	_firstCtrl = _barArray select (count _barArray -1);
	_newBar ctrlCommit 0;
	_newBar progressSetPosition (_frames/_maxFps);
	if ((ctrlPosition _firstCtrl) select 0 < 0) then {
		ctrlDelete _firstCtrl;
		_barArray = _barArray -[_firstCtrl];
	};
	sleep 1;
};