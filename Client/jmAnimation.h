#pragma once
#include "jmResource.h"


namespace jm
{
	using namespace math;
	class Texture;
	class Animator;
	class Animation : public Resource
	{
	public:
		struct Sprite
		{
			Vector2 leftTop;
			Vector2 size;
			Vector2 offset;
			float duration;

			Sprite()
				: leftTop(Vector2::zero)
				, size(Vector2::zero)
				, offset(Vector2::zero)
				, duration(0.0f)
			{

			}
		};

		Animation();
		~Animation();

		void Update();
		void Render(HDC hdc);

		virtual HRESULT Load(const std::wstring& path) { return S_FALSE; };

		void Create(const std::wstring& name
			, class Texture* texture
			, Vector2 leftTop, Vector2 size, Vector2 offset
			, UINT spriteLength, float duration);

		void Reset();

		bool IsComplete() { return mbComplete; }
		void SetAnimator(Animator* animator) { mAnimator = animator; }


	private:
		Animator* mAnimator;
		Texture* mTexture;

		std::vector<Sprite> mSpriteSheet;
		int mIndex;
		float mTime;
		bool mbComplete;

	};
}
