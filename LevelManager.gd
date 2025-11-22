extends Node

var current_level: int = 0   # starts at Level1.tscn

func goto_next_level():
	GameState.haveKey = false
	current_level += 1
	var path := "res://levels/level_%d.tscn" % current_level
	get_tree().change_scene_to_file(path)
