#include "jmWall.h"
namespace jm
{
	Wall::Wall()
	{
	}
	Wall::~Wall()
	{
	}
	void Wall::Initialize()
	{
	}
	void Wall::Update()
	{
		GameObject::Update();
	}
	void Wall::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}