#include "jmTransform.h"
#include "jmInput.h"
#include "jmTime.h"

namespace jm
{
	Transform::Transform()
		: Component(eComponentType::Transform)
		, mRotation(0.0f)
	{
	}
	Transform::~Transform()
	{
	}
	void Transform::Initialize()
	{
	}
	void Transform::Update()
	{
		
	}
	void Transform::Render(HDC hdc)
	{
	}
}
