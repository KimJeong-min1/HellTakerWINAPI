#pragma once
#include "jmScene.h"
#include "jmGameObject.h"
#include "jmSceneManager.h"
#include "jmTransform.h"

namespace jm::object
{
	template <typename T>
	static __forceinline T* Instantiate(eLayerType type)
	{
		T* gameObject = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameObject);
		gameObject->Initialize();
		gameObject->SetScene(scene);

		return gameObject;
	}
	
	template <typename T>
	static __forceinline T* Instantiate(eLayerType type, const std::wstring& Name)
	{
		T* gameObject = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameObject);
		gameObject->Initialize();
		gameObject->SetScene(scene);
		gameObject->SetName(Name);

		return gameObject;
	}

	template <typename T>
	static __forceinline T* Instantiate(eLayerType type, Vector2 position)
	{
		T* gameObject = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameObject);
		gameObject->Initialize();
		gameObject->GetComponent<Transform>()->SetPosition(position);
		gameObject->SetScene(scene);

		return gameObject;
	}
}