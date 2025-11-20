extends Area2D
@onready var animated_sprite_2d: AnimatedSprite2D = $AnimatedSprite2D

var is_open: bool = false

func open_portal():
	animated_sprite_2d.play("open")
	set_collision_mask_value(2, true)
	is_open = true

func close_portal():
	animated_sprite_2d.play("closed")
	set_collision_mask_value(2, false)

func _ready():
	if GameState.haveKey:
		open_portal()
	else:
		close_portal()

func _on_body_entered(body: Node2D) -> void:
	LevelManager.goto_next_level()
