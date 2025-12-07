// Godot SDK
#include <Godot/godot.hpp>
#include <Godot/classes/node.hpp>
#include <Godot/classes/area2d.hpp>
#include <Godot/classes/audio_stream_player2d.hpp>
#include <Godot/classes/label.hpp>
#include <Godot/classes/timer.hpp>
#include <Godot/classes/input.hpp>
#include <Godot/classes/collision_object2d.hpp>

#include "src/gameManager.hpp"

#include <JenovaSDK.h>

using namespace godot;
using namespace jenova::sdk;

JENOVA_SCRIPT_BEGIN

AudioStreamPlayer2D* audioPlayer = nullptr;
Label* label = nullptr;
Timer* timer = nullptr;
Node* portal = nullptr;
Node* gameState = nullptr;

void OnAwake(Caller* instance) {}
void OnDestroy(Caller* instance) {}

void OnReady(Caller* instance)
{
	Node* self = GetSelf<Node>(instance);

	audioPlayer = Object::cast_to<AudioStreamPlayer2D>(self->find_child("AudioStreamPlayer2D"));
	timer = Object::cast_to<Timer>(self->find_child("Timer"));

	// Label is one level up: $"../Label"
	Node* parent = self->get_parent();
	if (parent)
		label = Object::cast_to<Label>(parent->find_child("Label"));

	// Portal is sibling: $"../Portal"
	if (parent)
		portal = parent->find_child("Portal");

	// Autoload GameState
	gameState = GetTree()->get_root()->find_child("GameState", true, false);

	// Connect signals
	Area2D* area = GetSelf<Area2D>(instance);

	area->connect("body_entered", Callable(instance, "OnBodyEntered"));
	if (timer)
		timer->connect("timeout", Callable(instance, "OnTimerTimeout"));
}

//
// Equivalent to: func _on_body_entered(body):
//
void OnBodyEntered(Caller* instance, Node2D* body)
{
	Node* selfNode = GetSelf<Node>(instance);
	Area2D* area = GetSelf<Area2D>(instance);

	if (label) label->set_visible(true);
	selfNode->set_visible(false);

	// Disable collision mask layer 2
	area->set_collision_mask_value(2, false);

	// Play sound
	if (audioPlayer)
		audioPlayer->play();

	// Start timer
	if (timer)
		timer->start();

	// GameState.haveKey = true
	if (gameState)
		gameState->set("haveKey", true);

	// $"../Portal".open_portal()
	if (portal)
		portal->call("open_portal");
}

//
// Equivalent to: func _on_timer_timeout():
//
void OnTimerTimeout(Caller* instance)
{
	Node* self = GetSelf<Node>(instance);

	if (label) label->set_visible(false);

	self->queue_free();
}

JENOVA_SCRIPT_END
