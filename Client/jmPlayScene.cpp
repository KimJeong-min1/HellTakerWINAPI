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
		bg->GetComponent<Transform>()->SetPosition(Vector2(800.0f, 450.0f));

		image = Resources::Load<Texture>(L"PlayStage1onFirebase"
			, L"..\\Resources\\image\\Sprite\\FLAMEbase0001.png");

		BackGround* Flbaseonone = object::Instantiate<BackGround>(eLayerType::BackGround);
		SpriteRenderer* Flbaseonsr = Flbaseonone->AddComponent<SpriteRenderer>();
		Flbaseonsr->SetImage(image);
		Flbaseonsr->SetScale(Vector2(0.8f, 0.8f));
		Flbaseonone->GetComponent<Transform>()->SetPosition(Vector2(563.0f, 265.0f));

		BackGround* Flbaseontwo = object::Instantiate<BackGround>(eLayerType::BackGround);
		Flbaseonsr = Flbaseontwo->AddComponent<SpriteRenderer>();
		Flbaseonsr->SetImage(image);
		Flbaseonsr->SetScale(Vector2(0.8f, 0.8f));
		Flbaseontwo->GetComponent<Transform>()->SetPosition(Vector2(1045.0f, 465.0f));

		image = Resources::Load<Texture>(L"PlayStage1offFirebase"
			, L"..\\Resources\\image\\Sprite\\FLAMEbase0002.png");

		BackGround* Flbaseoffone = object::Instantiate<BackGround>(eLayerType::BackGround);
		SpriteRenderer* Flbaseoffsr = Flbaseoffone->AddComponent<SpriteRenderer>();
		Flbaseoffsr->SetImage(image);
		Flbaseoffsr->SetScale(Vector2(0.8f, 0.8f));
		Flbaseoffone->GetComponent<Transform>()->SetPosition(Vector2(798.0f, 180.0f));

		BackGround* Flbaseofftwo = object::Instantiate<BackGround>(eLayerType::BackGround);
		Flbaseoffsr = Flbaseofftwo->AddComponent<SpriteRenderer>();
		Flbaseoffsr->SetImage(image);
		Flbaseoffsr->SetScale(Vector2(0.8f, 0.8f));
		Flbaseofftwo->GetComponent<Transform>()->SetPosition(Vector2(480.0f, 500.0f));

		image = Resources::Load<Texture>(L"PlayUIBackGroundone"
			, L"..\\Resources\\image\\Sprite\\mainUIexport_bUI2.png");

		BackGround* uibg = object::Instantiate<BackGround>(eLayerType::BackGround);
		SpriteRenderer* uibgsr = uibg->AddComponent<SpriteRenderer>();
		uibgsr->SetImage(image);
		uibgsr->SetScale(Vector2(0.8f, 0.8f));
		uibg->GetComponent<Transform>()->SetPosition(Vector2(125.0f, 225.0f));

		image = Resources::Load<Texture>(L"PlayUIBackGroundtwo"
			, L"..\\Resources\\image\\Sprite\\mainUIexport_fUI0001.png");

		BackGround* uibgtwo = object::Instantiate<BackGround>(eLayerType::BackGround);
		SpriteRenderer* uisrbgtwo = uibgtwo->AddComponent<SpriteRenderer>();
		uisrbgtwo->SetImage(image);
		uisrbgtwo->SetScale(Vector2(0.8f, 0.8f));
		uibgtwo->GetComponent<Transform>()->SetPosition(Vector2(194.0f, 626.0f));

		/*image = Resources::Load<Texture>(L"Player"
			, L"..\\Resources\\image\\Player\\Stay");*/

		Player* player = object::Instantiate<Player>(eLayerType::Player);
		Transform* pltr = player->GetComponent<Transform>();
		pltr->SetPosition(Vector2(1000.0f, 280.0f));

		Animator* plat = player->AddComponent<Animator>();

		plat->CreateAnimationFolder(L"RightStay", L"..\\Resources\\image\\Player\\RightStay");
		plat->CreateAnimationFolder(L"RightMove", L"..\\Resources\\image\\Player\\RightMove");
		plat->CreateAnimationFolder(L"LeftStay", L"..\\Resources\\image\\Player\\LeftStay");
		plat->CreateAnimationFolder(L"LeftMove", L"..\\Resources\\image\\Player\\LeftMove");
		plat->PlayAnimation(L"RightStay", true);
		plat->SetScale(Vector2(0.8f, 0.8f));

		image = Resources::Load<Texture>(L"MosterImage"
			, L"..\\Resources\\image\\Sprite\\assets100V20225.png");

		Monster* monsterone = object::Instantiate<Monster>(eLayerType::Monster);
		SpriteRenderer* mo = monsterone->AddComponent<SpriteRenderer>();
		mo->SetImage(image);
		mo->SetScale(Vector2(0.8f, 0.8f));
		monsterone->GetComponent<Transform>()->SetPosition(Vector2(880.0f, 390.0f));
		
		Monster* monstertwo = object::Instantiate<Monster>(eLayerType::Monster);
		mo = monstertwo->AddComponent<SpriteRenderer>();
		mo->SetImage(image);
		mo->SetScale(Vector2(0.8f, 0.8f));
		monstertwo->GetComponent<Transform>()->SetPosition(Vector2(800.0f, 310.0f));

		Monster* monsterthree = object::Instantiate<Monster>(eLayerType::Monster);
		mo = monsterthree->AddComponent<SpriteRenderer>();
		mo->SetImage(image);
		mo->SetScale(Vector2(0.8f, 0.8f));
		monsterthree->GetComponent<Transform>()->SetPosition(Vector2(720.0f, 390.0f));
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