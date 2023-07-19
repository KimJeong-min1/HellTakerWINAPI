#include "jmBackGround.h"
#include "jmTransform.h"
#include "jmInput.h"
#include "jmTime.h"
#include "jmSpriteRenderer.h"

namespace jm
{
	BackGround::BackGround()
	{

	}

	BackGround::~BackGround()
	{

	}

	void BackGround::Initialize()
	{

	}

	void BackGround::Update()
	{
		GameObject::Update();

		//SpriteRenderer* sr = GetComponent<SpriteRenderer>();
	}

	void BackGround::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

}
