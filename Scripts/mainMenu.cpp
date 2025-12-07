/* Jenova C++ Default Script */

// Godot SDK
#include <Godot/godot.hpp>
#include <Godot/classes/control.hpp>
#include<Godot/classes/input_event.hpp>
#include <Godot/classes/audio_stream_player2d.hpp>

// Jenova SDK
#include <JenovaSDK.h>

// Namespaces
using namespace godot;
using namespace jenova::sdk;

// Jenova Script Block Start
JENOVA_SCRIPT_BEGIN

int pendingAction = -1;
AudioStreamPlayer2D* clickSound = nullptr;
JENOVA_PROPERTY(int, buttonState, 0, Hint:PROPERTY_HINT_ENUM, HintString : "Play, Quit", HintUsage : PROPERTY_USAGE_EDITOR)


void OnReady(Caller* instance) {
	Node* thisNode = GetSelf<Node>(instance);
	clickSound = Object::cast_to<AudioStreamPlayer2D>(thisNode->find_child("clickSound"));


	if (clickSound) {
		// Connect AudioStreamPlayer2D::finished → OnClickSoundFinished
		clickSound->connect(
			"finished",
			Callable(thisNode, "OnClickSoundFinished")
		);
	}
}

void OnClickSoundFinished(Caller* instance)
{
	Node* thisNode = GetSelf<Node>(instance);   // ✔ Correct way to get node

	if (pendingAction == 0) {
		thisNode->get_tree()->change_scene_to_file("res://levels/level_1.tscn");
	}
	else if (pendingAction == 1) {
		thisNode->get_tree()->quit();
	}

	pendingAction = -1;
}

void clickPlay(Node* thisNode) {
	pendingAction = 0;
	clickSound->play();
}


void clickQuit(Node* thisNode) {
	pendingAction = 1;
	clickSound->play();
}

void OnUserInterfaceInput(Caller* instance, InputEvent* p_event)
{
	if (!p_event->is_pressed()) return;

	Node* thisNode = GetSelf<Node>(instance);

	switch (buttonState) {
	case 0: clickPlay(thisNode); break;
	case 1: clickQuit(thisNode); break;
	}
}

// Jenova Script Block End
JENOVA_SCRIPT_END
