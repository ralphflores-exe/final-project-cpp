extends Control
@onready var start: Button = $NinePatchRect/VBoxContainer/Start
@onready var options: Button = $NinePatchRect/VBoxContainer/Options
@onready var quit: Button = $NinePatchRect/VBoxContainer/Quit
@onready var press_sound: AudioStreamPlayer2D = $pressSound

var pending_action := ""

func _ready():
	# Connect buttons to functions
	$NinePatchRect/VBoxContainer/Start.pressed.connect(_on_start_game_pressed)
	$NinePatchRect/VBoxContainer/Quit.pressed.connect(_on_quit_pressed)
	
	press_sound.finished.connect(_on_press_sound_finished)
	
func _on_start_game_pressed():
	pending_action = "start"
	press_sound.play()

func _on_quit_pressed():
	pending_action = "quit"
	press_sound.play()
	
func _on_press_sound_finished():
	if pending_action == "start":
		LevelManager.goto_next_level()
	elif pending_action == "quit":
		get_tree().quit()
		
	pending_action = ""
