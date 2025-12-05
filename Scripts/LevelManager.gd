extends Node

var current_level: int = 1

func goto_next_level():
	GameState.haveKey = false
	current_level += 1
	var path := "res://levels/level_%d.tscn" % current_level
	
	FadeLayer.transition()
	await FadeLayer.on_transition_finished
	get_tree().change_scene_to_file(path)
