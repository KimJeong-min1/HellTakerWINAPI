#pragma once
#include "jmComponent.h"
#include "jmTexture.h"

namespace jm
{
	using namespace math;
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		virtual ~SpriteRenderer();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
	
		void SetImage(Texture* image) { mTexture = image; }
		void SetScale(Vector2 scale) {	mScale = scale; }
	private:
		//Gdiplus::Image* mTexture;
		Texture* mTexture;
		Vector2 mScale;
		float mAlpha;
	};
}

