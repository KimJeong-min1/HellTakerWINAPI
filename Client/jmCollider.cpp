#include "jmCollider.h"
namespace jm
{
	Collider::Collider()
		:Component(eComponentType::Collider)
		,mSize(Vector2::zero)
		,mOffset(Vector2::zero)
	{
	}
	Collider::~Collider()
	{
	}
	void Collider::Initialize()
	{
	}
	void Collider::Update()
	{
	}
	void Collider::Render(HDC hdc)
	{
	}
}