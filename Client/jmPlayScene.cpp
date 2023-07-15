#include "jmPlayScene.h"
#include "jmPlayer.h"
#include "jmBackGround.h"
#include "jmObject.h"
#include "jmSpriteRenderer.h"
#include "jmMonster.h"
#include "jmInput.h"
#include "jmTexture.h"
#include "jmReSources.h"
#include "jmTransform.h"
#include "jmAnimator.h"

namespace jm
{
	PlayScene::PlayScene()
	{

	}
	PlayScene::~PlayScene()
	{

	}
	void PlayScene::Initialize()
	{

		Texture* image = Resources::Load<Texture>(L"PlayStage1"
			, L"..\\Resources\\image\\Chapter\\chapterBG0001.png");

		BackGround* bg = object::Instantiate<BackGround>(eLayerType::BackGround);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(image);
		bgsr->SetScale(Vector2(0.8f, 0.8f));
		bg->GetComponent<Transform>()->SetPosition(Vector2(20.0f, 0.0f));

		image = Resources::Load<Texture>(L"PlayStage1onFirebase"
			, L"..\\Resources\\image\\Sprite\\FLAMEbase0001.png");
		
		BackGround* Flbaseonone = object::Instantiate<BackGround>(eLayerType::BackGround);
		SpriteRenderer* Flbaseonsr = Flbaseonone->AddComponent<SpriteRenderer>();
		Flbaseonsr->SetImage(image);
		Flbaseonsr->SetScale(Vector2(0.8f, 0.8f));
		Flbaseonone->GetComponent<Transform>()->SetPosition(Vector2(520.0f, 215.0f));

		BackGround* Flbaseontwo = object::Instantiate<BackGround>(eLayerType::BackGround);
		Flbaseonsr = Flbaseontwo->AddComponent<SpriteRenderer>();
		Flbaseonsr->SetImage(image);
		Flbaseonsr->SetScale(Vector2(0.8f, 0.8f));
		Flbaseontwo->GetComponent<Transform>()->SetPosition(Vector2(1000.0f, 410.0f));		
		
		image = Resources::Load<Texture>(L"PlayStage1offFirebase"
			, L"..\\Resources\\image\\Sprite\\FLAMEbase0002.png");

		BackGround* Flbaseoffone = object::Instantiate<BackGround>(eLayerType::BackGround);
		SpriteRenderer* Flbaseoffsr = Flbaseoffone->AddComponent<SpriteRenderer>();
		Flbaseoffsr->SetImage(image);
		Flbaseoffsr->SetScale(Vector2(0.8f, 0.8f));
		Flbaseoffone->GetComponent<Transform>()->SetPosition(Vector2(753.0f, 130.0f));

		BackGround* Flbaseofftwo = object::Instantiate<BackGround>(eLayerType::BackGround);
		Flbaseoffsr = Flbaseofftwo->AddComponent<SpriteRenderer>();
		Flbaseoffsr->SetImage(image);
		Flbaseoffsr->SetScale(Vector2(0.8f, 0.8f));
		Flbaseofftwo->GetComponent<Transform>()->SetPosition(Vector2(435.0f, 450.0f));

		image = Resources::Load<Texture>(L"PlayUIBackGroundone"
			, L"..\\Resources\\image\\Sprite\\mainUIexport_bUI2.png");
		
		BackGround* uibg = object::Instantiate<BackGround>(eLayerType::BackGround);
		SpriteRenderer* uibgsr = uibg->AddComponent<SpriteRenderer>();
		uibgsr->SetImage(image);
		uibgsr->SetScale(Vector2(0.8f, 0.8f));
		uibg->GetComponent<Transform>()->SetPosition(Vector2(0.0f, 0.0f));
		
		image = Resources::Load<Texture>(L"PlayUIBackGroundtwo"
			, L"..\\Resources\\image\\Sprite\\mainUIexport_fUI0001.png");

		BackGround* uibgtwo = object::Instantiate<BackGround>(eLayerType::BackGround);
		SpriteRenderer* uisrbgtwo = uibgtwo->AddComponent<SpriteRenderer>();
		uisrbgtwo->SetImage(image);
		uisrbgtwo->SetScale(Vector2(0.8f, 0.8f));
		uibgtwo->GetComponent<Transform>()->SetPosition(Vector2(0.0f, 350.0f));

		/*image = Resources::Load<Texture>(L"Player"
			, L"..\\Resources\\image\\Player\\Stay");*/
	
		Player* player = object::Instantiate<Player>(eLayerType::Player);
		Transform* pltr = player->GetComponent<Transform>();
		
		pltr->SetPosition(Vector2(950.0f, 200.0f));
		

		Animator* plat = player->AddComponent<Animator>();
		plat->CreateAnimationFolder(L"Stay", L"..\\Resources\\image\\Player\\Stay");
		plat->CreateAnimationFolder(L"Move", L"..\\Resources\\image\\Player\\Move");
		plat->PlayAnimation(L"Stay", true);
	



		image = Resources::Load<Texture>(L"MosterImage"
			, L"..\\Resources\\image\\Sprite\\assets100V20225.png");

		Monster* monster = object::Instantiate<Monster>(eLayerType::Monster);
		SpriteRenderer* mo = monster->AddComponent<SpriteRenderer>();
		mo->SetImage(image);
		mo->SetScale(Vector2(0.8f, 0.8f));
		monster->GetComponent<Transform>()->SetPosition(Vector2(830.0f, 330.0f));
	}
	void PlayScene::Update()
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
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}