
#ifndef KEY_H
#define KEY_H

#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/classes/animation_player.hpp>
#include <godot_cpp/classes/area2d.hpp>
#include <godot_cpp/classes/node2d.hpp>

using namespace godot;

class key : public Area2D {
	GDCLASS(key, Area2D);
public:

protected:
	Ref<AnimationPlayer> animation_player;

public:
	void _on_body_entered(Ref<Node2D> body);
	void _ready() override;

	static void _bind_methods();
};

#endif // KEY_H
