#pragma once
#include "jmComponent.h"

namespace jm
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		virtual ~SpriteRenderer();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
	
	private:

	};
}

