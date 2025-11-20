
#include "portal.hpp"

#include <godot_cpp/core/object.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

void portal::open_portal()
{
	animated_sprite_2d->play("open");
	set_collision_mask_value(2, true);
	is_open = true;
}

void portal::close_portal()
{
	animated_sprite_2d->play("closed");
	set_collision_mask_value(2, false);
}

void portal::_ready()
{
	animated_sprite_2d = get_node("AnimatedSprite2D");
	if(GameState->get_haveKey())
	{
		open_portal();
	}
	else
	{
		close_portal();
	}
}

void portal::_on_body_entered(Ref<Node2D> body)
{
	get_tree()->change_scene_to_file("res://levels/level_2.tscn");
}

void portal::_bind_methods() {
	ClassDB::bind_method(D_METHOD("open_portal"), &portal::open_portal);
	ClassDB::bind_method(D_METHOD("close_portal"), &portal::close_portal);

}

