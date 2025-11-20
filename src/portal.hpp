
#ifndef PORTAL_H
#define PORTAL_H

#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/classes/area2d.hpp>
#include <godot_cpp/classes/node2d.hpp>

using namespace godot;

class portal : public Area2D {
	GDCLASS(portal, Area2D);
public:

	void _on_body_entered(Ref<Node2D> body);

	static void _bind_methods();
};

#endif // PORTAL_H
