extends CharacterBody2D


const SPEED = 150.0
const JUMP_VELOCITY = -280.0

@onready var animated_sprite: AnimatedSprite2D = $AnimatedSprite2D
@onready var jump: AudioStreamPlayer2D = $jump
@onready var run: AudioStreamPlayer2D = $run

func _physics_process(delta: float) -> void:
	if GameState.dead:
		# Stop horizontal movement, but allow vertical (gravity) to continue
		velocity.x = 0
		
		# Apply gravity so player can fall
		if not is_on_floor():
			velocity += get_gravity() * delta
		
		# Play death animation (loop if you want)
		animated_sprite.play("death")
		
		# Apply movement
		move_and_slide()
		return
		
	# Add the gravity.
	if not is_on_floor():
		velocity += get_gravity() * delta

	# Handle jump.
	if Input.is_action_just_pressed("jump") and is_on_floor():
		velocity.y = JUMP_VELOCITY
		jump.play() #Plays the jump sound

	# Get the input direction and handle the movement/deceleration.
	var direction := Input.get_axis("move_left", "move_right")
	
	#Flip Sprite
	if direction > 0:
		animated_sprite.flip_h = false
	elif direction < 0:
		animated_sprite.flip_h = true
	
	#Play Animation
	if is_on_floor():
		if direction == 0:
			animated_sprite.play("idle")
		else:
			animated_sprite.play("run")
	else:
		animated_sprite.play("jump")
	
	if direction:
		velocity.x = direction * SPEED

	else:
		velocity.x = move_toward(velocity.x, 0, SPEED)

	#Plays the running sound
	if direction and is_on_floor():
		if not run.playing:
			run.play()
	else:
		run.stop()
		

	move_and_slide()
