#include "jmSpriteRenderer.h"
#include "jmTransform.h"
#include "jmGameObject.h"

namespace jm
{
	SpriteRenderer::SpriteRenderer()
		: Component(eComponentType::SpriteRenderer)
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
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

	
		Ellipse(hdc, -50.f + pos.x, -50.f + pos.y, 50.f + pos.x, 50.f + pos.y);
	}
}