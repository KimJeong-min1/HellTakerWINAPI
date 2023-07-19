#include "jmSpriteRenderer.h"
#include "jmTransform.h"
#include "jmGameObject.h"

namespace jm
{
	SpriteRenderer::SpriteRenderer()
		: Component(eComponentType::SpriteRenderer)
		, mScale(Vector2::one)
		, mTexture(nullptr)
		, mAlpha(1.0f)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::Render(HDC hdc)
	{
		if (mTexture == nullptr)
			return;

		GameObject* gameobj = GetOwner();
		Transform* tr = gameobj->GetComponent<Transform>();
		mTexture->Render(hdc
			, tr->GetPosition()
			, Vector2(mTexture->GetWidth(), mTexture->GetHeight())
			, Vector2(0.0f, 0.0f)
			, Vector2(mTexture->GetWidth(), mTexture->GetHeight())
			, Vector2::zero
			, mScale
			, mAlpha
			, tr->GetRotation());
	}

}