#pragma once
#include <vector>
#include <list>
#include <map>
#include <set>
#include <functional>
#include <string>
#include <filesystem>
#include <bitset>
#include <assert.h>

#include "framework.h"
#include "jmMath.h"

#pragma comment(lib, "Msimg32.lib")

#include <mmsystem.h>
#include <dsound.h>
#include <dinput.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dsound.lib")

#define TILE_WIDTH 84
#define TILE_HEIGHT 86



namespace jm::enums
{
	enum class eLayerType
	{
		BackGround,
		Tile,
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

