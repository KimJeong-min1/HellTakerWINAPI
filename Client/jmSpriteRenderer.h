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
		float GetAlpha() { return mAlpha; }
		void SetAlpha(float alpha) { mAlpha = alpha; }
		void SetTile(int x, int y) { mbTile = true; mTileIndexX = x; mTileIndexY = y; }
	
	private:
		bool mbTile;
		int mTileIndexX;
		int mTileIndexY;
		//Gdiplus::Image* mTexture;
		Texture* mTexture;
		Vector2 mScale;
		float mAlpha;
	};
}

