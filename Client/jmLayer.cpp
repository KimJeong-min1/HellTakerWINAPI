#include "jmLayer.h"

jm::Layer::Layer()
{
}

jm::Layer::~Layer()
{
	
}

void jm::Layer::Initialize()
{
	for (GameObject* obj : mGameObjects)
	{
		if (nullptr != obj)
		{
			delete obj;
			obj = nullptr;
		}
	}

	mGameObjects.clear();
}

void jm::Layer::Update()
{
	for (GameObject* obj : mGameObjects)
	{
		obj->Update();
	}
}

void jm::Layer::Render(HDC hdc)
{
	for (GameObject* obj : mGameObjects)
	{
		obj->Render(hdc);
	}
}
