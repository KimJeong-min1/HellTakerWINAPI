#include "jmTitleScene.h"
#include "jmBackGround.h"
#include "jmSpriteRenderer.h"
#include "jmObject.h"
#include "jmDevil.h"
#include "jmInput.h"
#include "jmTexture.h"
#include "jmResources.h"
#include "jmTransform.h"

namespace jm
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		Texture* image = Resources::Load<Texture>(L"TitleBackGroundImage"
			, L"..\\Resources\\image\\BackGround\\dialogueBG_abyss.bmp");


		BackGround* bg = object::Instantiate<BackGround>(eLayerType::BackGround);
		bg->GetComponent<Transform>()->SetPosition(Vector2(800.0f, 450.0f));
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(image);
		bgsr->SetScale(Vector2(1.0f, 2.0f));

		image = Resources::Load<Texture>(L"beelzebub"
			, L"..\\Resources\\image\\Devil\\Beelzebub\\beel_fly.bmp");

		Devil* devil = object::Instantiate<Devil>(eLayerType::Devil);
		devil->GetComponent<Transform>()->SetPosition(Vector2(836.0f, 300.0f));
		SpriteRenderer* desr = devil->AddComponent<SpriteRenderer>();
		desr->SetImage(image);
		desr->SetScale(Vector2(0.8f, 0.8f));
		
	}
	void TitleScene::Update()
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
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}
