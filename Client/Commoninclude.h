#pragma once
#include <vector>
#include <list>
#include <map>
#include <set>
#include <functional>
#include <string>
#include <filesystem>
#include <bitset>

#include "framework.h"
#include "jmMath.h"

#pragma comment(lib, "Msimg32.lib")



namespace jm::enums
{
	enum class eLayerType
	{
		BackGround,
		Player,
		Monster,
		Wall,
		Devil,
		Angel,
		Effect,
		Text,
		UI,
		End
	};

	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Animation,
		Animator,
		Collider,
		End
	};
}

