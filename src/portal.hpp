
#ifndef PORTAL_H
#define PORTAL_H

#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/classes/animated_sprite2d.hpp>
#include <godot_cpp/classes/area2d.hpp>
#include <godot_cpp/classes/node2d.hpp>

using namespace godot;

class portal : public Area2D {
	GDCLASS(portal, Area2D);
public:

protected:
	Ref<AnimatedSprite2D> animated_sprite_2d;

	bool is_open = false;

public:
	void open_portal();

	void close_portal();

	void _ready() override;

	void _on_body_entered(Ref<Node2D> body);

	static void _bind_methods();
};

#endif // PORTAL_H
