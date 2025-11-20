
#include "key.hpp"

#include <godot_cpp/core/object.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

void key::_on_body_entered(Ref<Node2D> body)
{
	label->set_visible(true);
	visible = false;
	set_collision_mask_value(2, false);
	audio_stream_player_2d->play();
	timer->start();
	GameState->set_haveKey(true);
	get_node("../Portal")->open_portal();
}

void key::_on_timer_timeout()
{
	label->set_visible(false);
	queue_free();
}

void key::_ready()
{
	audio_stream_player_2d = get_node("AudioStreamPlayer2D");
	label = get_node("../Label");
	timer = get_node("Timer");
}

void key::_bind_methods() {

}

