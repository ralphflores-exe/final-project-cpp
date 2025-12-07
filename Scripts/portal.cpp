// Godot SDK
#include <Godot/godot.hpp>
#include <Godot/classes/area2d.hpp>
#include <Godot/classes/animated_sprite2d.hpp>
#include <Godot/classes/audio_stream_player2d.hpp>
#include <Godot/classes/node.hpp>
#include <Godot/classes/scene_tree.hpp>

#include "src/gameManager.hpp"

#include <JenovaSDK.h>

using namespace godot;
using namespace jenova::sdk;

JENOVA_SCRIPT_BEGIN

AnimatedSprite2D* animatedSprite = nullptr;
AudioStreamPlayer2D* audioPlayer = nullptr;
Node* gameState = nullptr;
Node* levelManager = nullptr;

bool is_open = false;

void OnAwake(Caller* instance) {}
void OnDestroy(Caller* instance) {}

void OnReady(Caller* instance)
{
	Area2D* self = GetSelf<Area2D>(instance);

	animatedSprite = Object::cast_to<AnimatedSprite2D>(self->find_child("AnimatedSprite2D"));
	audioPlayer = Object::cast_to<AudioStreamPlayer2D>(self->find_child("AudioStreamPlayer2D"));

	// Autoloads
	Node* root = GetTree()->get_root();
	gameState = root->find_child("GameState", true, false);
	levelManager = root->find_child("LevelManager", true, false);

	// Connect signal
	self->connect("body_entered", Callable(instance, "OnBodyEntered"));

	// GDScript _ready()
	bool haveKey = false;
	if (gameState)
		haveKey = (bool)gameState->get("haveKey");

	if (haveKey) {
		// open_portal()
		if (animatedSprite) animatedSprite->play("open");
		self->set_collision_mask_value(2, true);
		is_open = true;
	} else {
		// close_portal()
		if (animatedSprite) animatedSprite->play("closed");
		self->set_collision_mask_value(2, false);
		is_open = false;
	}
}

//
// open_portal()
//
void open_portal(Area2D* self)
{
	if (animatedSprite)
		animatedSprite->play("open");

	self->set_collision_mask_value(2, true);
	is_open = true;
}

//
// close_portal()
//
void close_portal(Area2D* self)
{
	if (animatedSprite)
		animatedSprite->play("closed");

	self->set_collision_mask_value(2, false);
	is_open = false;
}

//
// func _on_body_entered(body):
//
void OnBodyEntered(Caller* instance, Node2D* body)
{
	// LevelManager.goto_next_level()
	if (levelManager)
		levelManager->call("goto_next_level");
}

JENOVA_SCRIPT_END
