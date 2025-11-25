extends Node

@onready var animated_sprite_2d: AnimatedSprite2D = $AnimatedSprite2D
var transition_scene := preload("res://scenes/transition.tscn")
var active_transition: Node = null
var input_blocked: bool = false

func go_to_scene(next_scene_path: String) -> void:
	# Instantiate the transition scene
	active_transition = transition_scene.instantiate()
	get_tree().root.add_child(active_transition)

	animated_sprite_2d = active_transition.get_node("AnimatedSprite2D")

	# Play transition_out
	animated_sprite_2d.play("out")
	await animated_sprite_2d.animation_finished
	input_blocked = true

	# Change to the next scene
	get_tree().change_scene_to_file(next_scene_path)

	# Play transition_in
	animated_sprite_2d.play("in")
	await animated_sprite_2d.animation_finished

	# Cleanup and allow input
	active_transition.queue_free()
	active_transition = null
	input_blocked = false
