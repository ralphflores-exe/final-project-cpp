
#ifndef PLAYER_H
#define PLAYER_H

#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/classes/animated_sprite2d.hpp>
#include <godot_cpp/classes/character_body2d.hpp>

using namespace godot;

class player : public CharacterBody2D {
	GDCLASS(player, CharacterBody2D);
public:

protected:
	const double SPEED = 150.0;
	const double JUMP_VELOCITY =  - 280.0;

	Ref<AnimatedSprite2D> animated_sprite;

public:
	void _physics_process(double delta) override;
	void _ready() override;

	static void _bind_methods();
};

#endif // PLAYER_H
