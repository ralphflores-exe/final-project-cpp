extends Node

@onready var timer: Timer = $Timer
@onready var death_sound: AudioStreamPlayer2D = $"death sound"

func _on_body_entered(body: Node2D) -> void:
	GameState.dead = true
	GameState.deaths += 1
	death_sound.play()
	timer.start()

func _on_timer_timeout() -> void:
	GameState.haveKey = false
	GameState.dead = false
	get_tree().reload_current_scene() # Replace with function body.
