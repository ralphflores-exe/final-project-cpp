
#include "player.hpp"

#include <godot_cpp/core/object.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

void player::_physics_process(double delta)
{

	// Add the gravity.
	if(!is_on_floor())
	{
		velocity += get_gravity() * delta;
	}

	// Handle jump.
	if(Input::get_singleton()->is_action_just_pressed("jump") && is_on_floor())
	{
		velocity.y = JUMP_VELOCITY;
	}

	// Get the input direction and handle the movement/deceleration.
	double direction = Input::get_singleton()->get_axis("move_left", "move_right");

	//Flip Sprite
	if(direction > 0)
	{
		animated_sprite->set_flip_h(false);
	}
	else if(direction < 0)
	{
		animated_sprite->set_flip_h(true);
	}

	//Play Animation
	if(is_on_floor())
	{
		if(direction == 0)
		{
			animated_sprite->play("idle");
		}
		else
		{
			animated_sprite->play("run");
		}
	}
	else
	{
		animated_sprite->play("jump");
	}

	if(direction)
	{
		velocity.x = direction * SPEED;
	}
	else
	{
		velocity.x = Math::move_toward(velocity.x, 0, SPEED);
	}

	move_and_slide();
}

void player::_ready()
{
	animated_sprite = get_node("AnimatedSprite2D");
}

void player::_bind_methods() {

}

