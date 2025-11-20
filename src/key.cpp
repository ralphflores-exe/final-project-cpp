
#include "key.hpp"

#include <godot_cpp/core/object.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

void key::_on_body_entered(Ref<Node2D> body)
{
	UtilityFunctions::print("Level Key Acquired!");
	animation_player->play("pickup");
}

void key::_ready()
{
	animation_player = get_node("AnimationPlayer");
}

void key::_bind_methods() {

}

