#include "jmSceneManager.h"
#include "jmTitleScene.h"

namespace jm
{
	std::map<std::wstring, Scene*> SceneManager::mScenes = {};
	Scene* SceneManager::mActiveScene = nullptr;
	
	void SceneManager::Initialize()
	{
		CreateScene<TitleScene>(L"TitleScene");

		LoadScene(L"TitleScene");
	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}

	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		std::map<std::wstring, Scene*>::iterator Iter
			= mScenes.find(name);

		if (Iter == mScenes.end())
			return nullptr;

		mActiveScene = Iter->second;
		return Iter->second;
	}

}