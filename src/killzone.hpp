
#ifndef KILLZONE_H
#define KILLZONE_H

#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/classes/area2d.hpp>
#include <godot_cpp/classes/audio_stream_player2d.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/timer.hpp>

using namespace godot;

class killzone : public Area2D {
	GDCLASS(killzone, Area2D);
public:

protected:
	Ref<Timer> timer;
	Ref<AudioStreamPlayer2D> death_sound;

public:
	void _on_body_entered(Ref<Node2D> body);

// Replace with function body.
	void _on_timer_timeout();
	void _ready() override;

	static void _bind_methods();
};

#endif // KILLZONE_H
