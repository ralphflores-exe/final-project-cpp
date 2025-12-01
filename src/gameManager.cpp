#include "src/gameManager.hpp"

// Allocate singleton
GameManager* GMInstance = nullptr;

void RegisterGameManager()
{
	ClassDB::register_class<GameManager>();

	// Create instance
	GMInstance = memnew(GameManager);

	// Register as global singleton
	Engine::get_singleton()->register_singleton("GameManager", GMInstance);
}

void UnregisterGameManager()
{
	Engine::get_singleton()->unregister_singleton("GameManager");

	if (GMInstance)
		memdelete(GMInstance);

	GMInstance = nullptr;
}
