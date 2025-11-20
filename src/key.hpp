
#ifndef KEY_H
#define KEY_H

#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/classes/area2d.hpp>
#include <godot_cpp/classes/audio_stream_player2d.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/timer.hpp>

using namespace godot;

class key : public Area2D {
	GDCLASS(key, Area2D);
public:

protected:
	Ref<AudioStreamPlayer2D> audio_stream_player_2d;
	Ref<Label> label;
	Ref<Timer> timer;

public:
	void _on_body_entered(Ref<Node2D> body);

	void _on_timer_timeout();
	void _ready() override;

	static void _bind_methods();
};

#endif // KEY_H
