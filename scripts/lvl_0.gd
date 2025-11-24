extends Control
@onready var start: Button = $NinePatchRect/VBoxContainer/Start
@onready var options: Button = $NinePatchRect/VBoxContainer/Options
@onready var quit: Button = $NinePatchRect/VBoxContainer/Quit

func _ready():
	# Connect buttons to functions
	$NinePatchRect/VBoxContainer/Start.pressed.connect(_on_start_game_pressed)
	$NinePatchRect/VBoxContainer/Quit.pressed.connect(_on_quit_pressed)
func _on_start_pressed() -> void:
	get_tree().change_scene_to_file("res://levels/level_1.tscn")	
	
func _on_start_game_pressed():
	LevelManager.goto_next_level()

func _on_quit_pressed():
	get_tree().quit()
