extends Area2D

@onready var audio_stream_player_2d: AudioStreamPlayer2D = $AudioStreamPlayer2D
@onready var label: Label = $"../Label"
@onready var timer: Timer = $Timer

func _on_body_entered(body: Node2D) -> void:
	label.visible = true
	visible = false
	set_collision_mask_value(2,false)
	audio_stream_player_2d.play()
	timer.start()
	GameState.haveKey = true
	$"../Portal".open_portal()
	
func _on_timer_timeout() -> void:
	label.visible = false
	queue_free()
