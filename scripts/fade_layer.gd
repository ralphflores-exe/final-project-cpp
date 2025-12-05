extends CanvasLayer

signal on_transition_finished

@onready var anim: AnimationPlayer = $AnimationPlayer
@onready var color_rect: ColorRect = $ColorRect

func _ready() -> void:
	color_rect.visible = false
	anim.animation_finished.connect(_on_animation_finished)
	
func _on_animation_finished(anim_name):
	if anim_name == "fade_in":
		on_transition_finished.emit()
		anim.play("fade_out")
	elif anim_name == "fade_out":
		color_rect.visible = false

func transition():
	color_rect.visible = true
	anim.play("fade_in")
