extends Node

var current_level: int = 0   # starts at level0.tscn or main menu

func goto_next_level():
	GameState.haveKey = false
	current_level += 1
	var path := "res://levels/level_%d.tscn" % current_level
	if current_level == 1:
		get_tree().change_scene_to_file(path)
	else:
		TransitionManager.go_to_scene(path)
