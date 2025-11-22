extends Control
@onready var start: Button = $Start
@onready var quit: Button = $Quit

func _ready():
	# Connect buttons to functions
	$Start.pressed.connect(_on_start_game_pressed)
	$Quit.pressed.connect(_on_quit_pressed)
func _on_start_pressed() -> void:
	get_tree().change_scene_to_file("res://scenes/lvl_1(temp).tscn")	
	
func _on_start_game_pressed():
	LevelManager.goto_next_level()

func _on_quit_pressed():
	get_tree().quit()
