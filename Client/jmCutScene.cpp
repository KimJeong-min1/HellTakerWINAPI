#include "jmCutScene.h"
#include "jmText.h"
#include "jmObject.h"
#include "jmSpriteRenderer.h"
#include "jmInput.h"
#include "jmBackGround.h"
#include "jmResources.h"
#include "jmTexture.h"
#include "jmTransform.h"

namespace jm
{

	CutScene::CutScene()
	{
	}

	CutScene::~CutScene()
	{
	}

	void CutScene::Initialize()
	{
		Texture* image = Resources::Load<Texture>(L"CutScene"
			, L"..\\Resources\\image\\Cutscene\\cutscene_0002_Group-2.png");

		BackGround* bg = object::Instantiate<BackGround>(eLayerType::BackGround);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(image);
		bgsr->SetScale(Vector2(1.3f, 1.4f));
		bg->GetComponent<Transform>()->SetPosition(Vector2(800.0f, 450.0f));
	}

	void CutScene::Update()
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

	void CutScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

}