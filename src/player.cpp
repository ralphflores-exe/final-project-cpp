// Godot SDK
#include <Godot/godot.hpp>
#include <Godot/classes/node.hpp>
#include <Godot/variant/variant.hpp>
#include <Godot/classes/character_body2d.hpp>
#include <Godot/classes/animated_sprite2d.hpp>
#include <Godot/classes/audio_stream_player2d.hpp>
#include <Godot/classes/input.hpp>
#include <Godot/classes/scene_tree.hpp>
#include <Godot/classes/engine.hpp>
#include <Godot/classes/window.hpp>
#include "src/gameManager.hpp"


#include <JenovaSDK.h>

// Namespaces
using namespace godot;
using namespace jenova::sdk;

// Jenova Script Block Start
JENOVA_SCRIPT_BEGIN

const double speed = 150.0;
const double jumpVelocity = -280.0;
AnimatedSprite2D* animation = nullptr;
AudioStreamPlayer2D* runSound = nullptr;
AudioStreamPlayer2D* jumpSound = nullptr;
Node* my_autoload = nullptr;

// Routines
void OnAwake(Caller* instance)
{
	
}
void OnDestroy(Caller* instance)
{

}
void OnReady(Caller* instance)
{
	Node* thisNode = GetSelf<Node>(instance);
	animation = Object::cast_to<AnimatedSprite2D>(thisNode->find_child("AnimatedSprite2D"));
	runSound = Object::cast_to<AudioStreamPlayer2D>(thisNode->find_child("run"));
	jumpSound = Object::cast_to<AudioStreamPlayer2D>(thisNode->find_child("jump"));
	my_autoload = Object::cast_to<Node>(GetTree()->get_root()->find_child("GameState", true, false));

}
void OnProcess(Caller* instance, double _delta)
{

}

void OnPhysicsProcess(Caller* instance, double _delta)
{
	CharacterBody2D* thisNode = GetSelf<CharacterBody2D>(instance);

	Vector2 vel = thisNode->get_velocity();
	Input* input = Input::get_singleton();

	bool dead = false;
	if (my_autoload)
	{
		Variant v = my_autoload->get("dead");
		dead = v.operator bool();
	}	
	// ----------------------
	// DEATH LOGIC
	// ----------------------
	if (dead)
	{
		vel.x = 0;
		if (runSound->is_playing()) {
			runSound->stop();
		}

		if (!thisNode->is_on_floor())
			vel += thisNode->get_gravity() * _delta;

		if (animation) animation->play("death");

		thisNode->set_velocity(vel);
		thisNode->move_and_slide();
		return;
	}

	if (!thisNode->is_on_floor()) {
		vel += thisNode->get_gravity() * _delta;
	}
	if (input->is_action_just_pressed("jump") && thisNode->is_on_floor()) {
		vel.y += jumpVelocity;
		jumpSound->play();
	}

	double direction = input->get_axis("move_left", "move_right");

	if (direction > 0) animation->set_flip_h(false);
	else if (direction < 0) animation->set_flip_h(true);

	if (!thisNode->is_on_floor()) animation->play("jump");
	else if (direction == 0) animation->play("idle");
	else animation->play("run");

	if (direction) vel.x = direction * speed;
	else {
		if (vel.x > 0) vel.x = std::max(vel.x - speed, 0.0);
		else if (vel.x < 0) vel.x = std::min(vel.x + speed, 0.0);
	}
	if (direction != 0 && thisNode->is_on_floor()) {
		if (!runSound->is_playing()) {
			runSound->play();
		}
	}
	else {
		if (runSound->is_playing()) {
			runSound->stop();
		}
	}


	thisNode->set_velocity(vel);
	thisNode->move_and_slide();
}
			

// Jenova Script Block End
JENOVA_SCRIPT_END
