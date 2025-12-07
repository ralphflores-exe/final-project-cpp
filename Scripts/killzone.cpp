// Godot SDK
#include <Godot/godot.hpp>
#include <Godot/classes/node.hpp>
#include <Godot/classes/timer.hpp>
#include <Godot/classes/audio_stream_player2d.hpp>
#include <Godot/classes/scene_tree.hpp>

#include "src/gameManager.hpp"

#include <JenovaSDK.h>

using namespace godot;
using namespace jenova::sdk;

JENOVA_SCRIPT_BEGIN

Timer* timer = nullptr;
AudioStreamPlayer2D* deathSound = nullptr;
Node* gameState = nullptr;

void OnAwake(Caller* instance) {}
void OnDestroy(Caller* instance) {}

void OnReady(Caller* instance)
{
	Node* self = GetSelf<Node>(instance);

	timer = Object::cast_to<Timer>(self->find_child("Timer"));
	deathSound = Object::cast_to<AudioStreamPlayer2D>(self->find_child("death sound"));

	// Autoload GameState
	gameState = GetTree()->get_root()->find_child("GameState", true, false);

	// Connect signals
	self->connect("body_entered", Callable(instance, "OnBodyEntered"));
	if (timer)
		timer->connect("timeout", Callable(instance, "OnTimerTimeout"));
}

//
// Equivalent to:
// func _on_body_entered(body):
//
void OnBodyEntered(Caller* instance, Node2D* body)
{
	if (gameState) {
		gameState->set("dead", true);

		// GameState.deaths += 1
		Variant deathsVar = gameState->get("deaths");
		int deaths = (int)deathsVar;
		gameState->set("deaths", deaths + 1);
	}

	if (deathSound)
		deathSound->play();

	if (timer)
		timer->start();
}

//
// Equivalent to:
// func _on_timer_timeout():
//
void OnTimerTimeout(Caller* instance)
{
	if (gameState) {
		gameState->set("haveKey", false);
		gameState->set("dead", false);
	}

	// get_tree().reload_current_scene()
	GetTree()->reload_current_scene();
}

JENOVA_SCRIPT_END
