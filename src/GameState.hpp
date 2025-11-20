
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/classes/node.hpp>

using namespace godot;

class GameState : public Node {
	GDCLASS(GameState, Node);
public:

protected:
	bool haveKey = false;

};

#endif // GAMESTATE_H
