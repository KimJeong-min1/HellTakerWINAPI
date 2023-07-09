#include "jmLayer.h"

jm::Layer::Layer()
{
}

jm::Layer::~Layer()
{
}

void jm::Layer::Initialize()
{
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
