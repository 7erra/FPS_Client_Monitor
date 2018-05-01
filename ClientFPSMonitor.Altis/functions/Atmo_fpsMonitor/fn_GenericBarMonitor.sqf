disableSerialization;

params ["_display"];

if (isNull _display) exitWith {73001 cutRsc ["Atmo_SweepingBar", "PLAIN"];};

#define CTRL(VAR,IDC) VAR = _display displayCtrl IDC;
CTRL(_TXTfps, 1000)
CTRL(_GRPframes, 2302)

_expression = "diag_fps";
_code = compile _expression;
_maxValue = 65;

_maxBars = 60;
_barArray = [];
for "_i" from 1 to _maxBars do {
	_bar = _display ctrlCreate ["RscVProgress", -1 , _GRPframes];
	_barArray pushBack _bar;
};

_maxWidth 	= ctrlPosition _GRPframes select 2;
_maxHeight 	= 0.9 * (ctrlPosition _GRPframes select 3);
_width =  _maxWidth / _maxBars;
_delay = 0.1; // sec

_frame = 0;
while {!isNull _display} do {
	_value = call _code;
	
	_TXTfps ctrlSetText format ["fps : %1", _value toFixed 2];
	
	_bar = _barArray select _frame;
	_bar ctrlSetPosition [_frame * _width, 0,  _width, _maxHeight];
	_bar ctrlSetFade 0;
	_bar ctrlCommit 0;
	_bar progressSetPosition (_value / _maxValue);
	_bar ctrlSetFade 0.8 ;
	_bar ctrlCommit _delay * _maxBars;
	
	_frame = (_frame + 1) mod _maxBars;
	sleep _delay;
	
};