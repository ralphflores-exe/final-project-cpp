
#include "killzone.hpp"

#include <godot_cpp/core/object.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

void killzone::_on_body_entered(Ref<Node2D> body)
{
	UtilityFunctions::print("You died!");
	death_sound->play();
	Engine::get_singleton()->set_time_scale(0.5);
	body->get_node("CollisionShape2D")->queue_free();
	timer->start();
}

void killzone::_on_timer_timeout()
{
	Engine::get_singleton()->set_time_scale(1.0);
	get_tree()->reload_current_scene();
}

void killzone::_ready()
{
	timer = get_node("Timer");
	death_sound = get_node("death sound");
}

void killzone::_bind_methods() {

}

