#pragma once
#include "jmScene.h"
#include "jmGameObject.h"
#include "jmSceneManager.h"

namespace jm::object
{
	template <typename T>
	static __forceinline T* Instantiate(eLayerType type)
	{
		T* gameObject = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameObject);

		return gameObject;
	}
}