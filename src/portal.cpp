
#include "portal.hpp"

#include <godot_cpp/core/object.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

void portal::_on_body_entered(Ref<Node2D> body)
{
	UtilityFunctions::print("Next Level");
}

void portal::_bind_methods() {

}

