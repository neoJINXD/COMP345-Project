#pragma once
#include "../Resources/Resources.h"

/*
	Global functions that are not attached to a class
*/

//Used for converting Resource enum values to a string
std::string resToStr(Resource);
std::string resToStr(Resource res) {

	switch (res) {

	case Wheat:
		return "Wheat";

	case Stone:
		return "Stone";

	case Sheep:
		return "Sheep";

	case Timber:
		return "Timber";
	}
}