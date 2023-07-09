#pragma once
#include <vector>
#include <list>
#include <map>
#include <set>
#include <functional>
#include <string>

#include "framework.h"
#include "jmMath.h"


namespace jm::enums
{
	enum class eLayerType
	{
		BackGround,
		Player,
		Monster,
		Devil,
		Angel,
		Effect,
		UI,
		Text,
		End
	};

	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		End
	};
}

