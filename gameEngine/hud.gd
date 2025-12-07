extends Control

@onready var label: Label = $Label
@onready var label_2: Label = $Label2


# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	label.text = "Deaths: %d" % GameState.deaths
	
	var t = Stopwatch.time_elapsed
	var minutes = int(t / 60)
	var seconds = int(t) % 60
	var ms = int((t - int(t)) * 100)
	
	label_2.text = "Time: %02d:%02d.%02d" % [minutes, seconds, ms]
	
