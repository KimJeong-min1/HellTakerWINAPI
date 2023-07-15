#include "jmEndingScene.h"
#include "jmText.h"
#include "jmTexture.h"
#include "jmObject.h"
#include "jmSpriteRenderer.h"
#include "jmInput.h"
#include "jmReSources.h"
#include "jmBackGround.h"

namespace jm
{

	EndingScene::EndingScene()
	{
	}

	EndingScene::~EndingScene()
	{
	}

	void EndingScene::Initialize()
	{

		Texture* image = Resources::Load<Texture>(L"BadEnding"
			, L"..\\Resources\\image\\Texture2D\\dialogueDeathExport0009.png");

		BackGround* bg = object::Instantiate<BackGround>(eLayerType::BackGround);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(image);
		bgsr->SetScale(Vector2(1.1f, 1.9f));
		
		//Text* text = object::Instantiate<Text>(eLayerType::Text);
	}

	void EndingScene::Update()
	{
		Scene::Update();


		if (Input::GetKeyDown(eKeyCode::T))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
		if (Input::GetKeyDown(eKeyCode::P))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
		if (Input::GetKeyDown(eKeyCode::C))
		{
			SceneManager::LoadScene(L"CutScene");
		}
		if (Input::GetKeyDown(eKeyCode::E))
		{
			SceneManager::LoadScene(L"EndingScene");
		}
	}

	void EndingScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

}
