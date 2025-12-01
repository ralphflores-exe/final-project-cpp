#pragma once

// Godot SDK
#include <Godot/godot.hpp>
#include <Godot/classes/object.hpp>
#include <Godot/classes/engine.hpp>

using namespace godot;

class GameManager : public Object
{
	GDCLASS(GameManager, Object)

private:
	bool dead = false;
	bool haveKey = false;
	int deaths = 0;

protected:
	static void _bind_methods()
	{
		ClassDB::bind_method(D_METHOD("is_dead"), &GameManager::IsDead);
		ClassDB::bind_method(D_METHOD("set_dead", "value"), &GameManager::SetDead);

		ClassDB::bind_method(D_METHOD("has_key"), &GameManager::HasKey);
		ClassDB::bind_method(D_METHOD("set_have_key", "value"), &GameManager::SetHaveKey);

		ClassDB::bind_method(D_METHOD("get_deaths"), &GameManager::GetDeaths);
		ClassDB::bind_method(D_METHOD("set_deaths", "value"), &GameManager::SetDeaths);
	}

public:

	bool IsDead() const { return dead; }
	void SetDead(bool v) { dead = v; }

	bool HasKey() const { return haveKey; }
	void SetHaveKey(bool v) { haveKey = v; }

	int GetDeaths() const { return deaths; }
	void SetDeaths(int v) { deaths = v; }
};

// Singleton instance
extern GameManager* GMInstance;

// Register functions
void RegisterGameManager();
void UnregisterGameManager();
