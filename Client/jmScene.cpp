#include "jmScene.h"
#include "jmPlayer.h"
#include "jmSpriteRenderer.h"

namespace jm
{

	Scene::Scene()
	{
		mLayers.resize((int)eLayerType::End);
	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{

	}

	void Scene::Update()
	{
		for (Layer& layer : mLayers)
		{
			layer.Update();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (Layer& layer : mLayers)
		{
			layer.Render(hdc);
		}
	}

}
