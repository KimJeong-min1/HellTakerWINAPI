#pragma once
#include "Commoninclude.h"

namespace jm
{
#define LAYER_MAX (UINT)eLayerType::End
	union ColliderID
	{
		struct
		{
			UINT left;
			UINT right;
		};
		UINT64 id;
	};
	
	using namespace enums;
	class CollisionManager
	{

	};

}
