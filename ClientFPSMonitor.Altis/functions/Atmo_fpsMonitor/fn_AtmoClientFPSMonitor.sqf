disableSerialization;

private _layer 		= ("Atmo_FPSMonitor_layer" call BIS_fnc_rscLayer) cutRsc ["Atmo_FPSMonitor", "PLAIN"];
private _display 	= uiNamespace getVariable "Atmo_FPSMonitor_Display";

// Add a show/fade action - bound to the User1 action.
player addAction [	"<t color='#00FF00'>Toggle fps Monitor",
					{	
						_display = uiNamespace getVariable "Atmo_fpsMonitor_Display";
						{
							// Can't seem to find how to hide the dialog? but this is actually quite good
							_scale = ctrlScale _x;
							if (_scale < 0.1) then {
								_x ctrlSetScale 1; // Show
							} else {
								_x ctrlSetScale 0; // Hide
							};
							_x ctrlCommit 0;
						} forEach allControls _display;
					},
					nil,
					0,
					false,
					true,
					"User1" ];

// Get the controls in the display
private _TXTfps = _display displayCtrl 1000;
private _Graph1	= _display displayCtrl 2302;
private _Graph2	= _display displayCtrl 2303;
private _Graph3 = _display displayCtrl 2304;
//private _myProgressBar = _display displayCtrl 2305;
//private _myGUIBack =  _display displayCtrl 2306;

// The sweep duration of the first graph
private _delay = 1.0/60.0; // 1 second sweep

// Set the variables needed and create the Progress bars for graph1
_Graph1_maxValue = 100;
_Graph1_maxBars = 60; // 1 secs
_Graph1_maxWidth 	= ctrlPosition _Graph1 select 2;
_Graph1_maxHeight 	= 0.9 * (ctrlPosition _Graph1 select 3);
_Graph1_barWidth =  _Graph1_maxWidth / _Graph1_maxBars;
_Graph1_bars = [];
// Create the progress bars
for "_i" from 1 to _Graph1_maxBars do {
	_bar = _display ctrlCreate ["RscVProgress", -1 , _Graph1];
	_bar ctrlSetPosition [(_i-1) * _Graph1_barWidth, 0,  _Graph1_barWidth, _Graph1_maxHeight];
	_Graph1_bars pushBack _bar;
};

// Set the variables needed and create the Progress bars for graph2
_Graph2_maxValue = _Graph1_maxValue;
_Graph2_maxBars = 60; // 1 minute
_Graph2_maxWidth 	= ctrlPosition _Graph2 select 2;
_Graph2_maxHeight 	= 0.9 * (ctrlPosition _Graph2 select 3);
_Graph2_barWidth =  _Graph2_maxWidth / _Graph2_maxBars;
_Graph2_bars = [];
// Create the progress bars
for "_i" from 1 to _Graph2_maxBars do {
	_bar = _display ctrlCreate ["RscVProgress", -1 , _Graph2];
	_bar ctrlSetPosition [(_i-1) * _Graph2_barWidth, 0,  _Graph2_barWidth, _Graph2_maxHeight];
	_Graph2_bars pushBack _bar;
};

// Set the variables needed and create the Progress bars for graph3
_Graph3_maxValue = _Graph1_maxValue;
_Graph3_maxBars = 60; // 1 hr
_Graph3_maxWidth 	= ctrlPosition _Graph3 select 2;
_Graph3_maxHeight 	= 0.9 * (ctrlPosition _Graph3 select 3);
_Graph3_barWidth =  _Graph3_maxWidth / _Graph3_maxBars;
_Graph3_bars = [];
// Create the progress bars
for "_i" from 1 to _Graph3_maxBars do {
	_bar = _display ctrlCreate ["RscVProgress", -1 , _Graph3];
	_bar ctrlSetPosition [(_i-1) * _Graph3_barWidth, 0,  _Graph3_barWidth, _Graph3_maxHeight];
	_Graph3_bars pushBack _bar;
};


private _Graph1_frame = 0;
private _Graph2_frame = 0;
private _Graph3_frame = 0;
private _Graph1_total = 0;
private _Graph2_total = 0;
private _Graph2_total = 0;

while {true} do {
	
	_value = diag_fps;
	_Graph1_total = _Graph1_total + _value;
	_bar = _Graph1_bars select _Graph1_frame;
	_bar ctrlSetFade 0;
	_bar ctrlCommit 0;
	_bar progressSetPosition (_value / _Graph1_maxValue);
	_bar ctrlSetFade 0.9 ;
	_bar ctrlCommit _delay * _Graph1_maxBars;
	_TXTfps ctrlSetText format ["fps : %1", _value toFixed 2]; // Set the text
	
	// Set a bar in Graph2
	if (_Graph1_frame == _Graph1_maxBars - 1) then {
		_value = _Graph1_total / _Graph1_maxBars;
		_Graph2_total = _Graph2_total + _value;
		_bar = _Graph2_bars select _Graph2_frame;
		_bar ctrlSetFade 0;
		_bar ctrlCommit 0;
		_bar progressSetPosition (_value / _Graph2_maxValue);
		_bar ctrlSetFade 0.9 ;
		_bar ctrlCommit _delay * _Graph2_maxBars * _Graph1_maxBars;
		
		if (_Graph2_frame == _Graph2_maxBars - 1) then {
			_value = _Graph2_total / _Graph2_maxBars;
			_bar = _Graph3_bars select _Graph3_frame;
			_bar ctrlSetFade 0;
			_bar ctrlCommit 0;
			_bar progressSetPosition (_value / _Graph3_maxValue);
			_bar ctrlSetFade 0.9 ;
			_bar ctrlCommit _delay * _Graph3_maxBars * _Graph2_maxBars * _Graph1_maxBars;
			_Graph3_frame = (_Graph3_frame + 1) mod _Graph3_maxBars;
			_Graph2_total = 0; // Reset the total for the second graph	
		};
	
		_Graph2_frame = (_Graph2_frame + 1) mod _Graph2_maxBars;
		_Graph1_total = 0; // Reset the total for the first graph
	
	};
	
	_Graph1_frame = (_Graph1_frame + 1) mod _Graph1_maxBars;
	uisleep _delay; // Doesn't slow on client frame rate drop?
	
};