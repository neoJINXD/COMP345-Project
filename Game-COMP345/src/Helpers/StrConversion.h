#pragma once
#include "../Resources/Resources.h"
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