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
#include "jmUI.h"
#include "jmCollisionManager.h"

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
			, L"..\\Resources\\image\\Chapter\\chapterBG0001.bmp");

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

		image = Resources::Load<Texture>(L"PlayUIBackGroundLefttop"
			, L"..\\Resources\\image\\UI\\mainUIexport_Lefttop.bmp");

		UI* uiLefttopbg = object::Instantiate<UI>(eLayerType::UI);
		SpriteRenderer* uibgsr = uiLefttopbg->AddComponent<SpriteRenderer>();
		uibgsr->SetImage(image);
		uibgsr->SetScale(Vector2(0.8f, 0.8f));
		uiLefttopbg->GetComponent<Transform>()->SetPosition(Vector2(125.0f, 225.0f));

		image = Resources::Load<Texture>(L"PlayUIBackGroundLeftbottom"
			, L"..\\Resources\\image\\UI\\mainUIexport_Leftbottom.bmp");

		UI* uiLeftbottombg = object::Instantiate<UI>(eLayerType::UI);
		SpriteRenderer* uisrbgtwo = uiLeftbottombg->AddComponent<SpriteRenderer>();
		uisrbgtwo->SetImage(image);
		uisrbgtwo->SetScale(Vector2(0.8f, 0.8f));
		uiLeftbottombg->GetComponent<Transform>()->SetPosition(Vector2(194.0f, 626.0f));

		image = Resources::Load<Texture>(L"PlayUIBackGroundRighttop"
			, L"..\\Resources\\image\\UI\\mainUIexport_Righttop.bmp");

		UI* uiRighttopbg = object::Instantiate<UI>(eLayerType::UI);
		SpriteRenderer* uisrbgthree = uiRighttopbg->AddComponent<SpriteRenderer>();
		uisrbgthree->SetImage(image);
		uisrbgthree->SetScale(Vector2(0.8f, 0.8f));
		uiRighttopbg->GetComponent<Transform>()->SetPosition(Vector2(1475.0f, 225.0f));


		image = Resources::Load<Texture>(L"PlayUIBackGroundRightbottom"
			, L"..\\Resources\\image\\UI\\mainUIexport_Rightbottom.bmp");

		UI* uiRightbottombg = object::Instantiate<UI>(eLayerType::UI);
		SpriteRenderer* uisrbgfour = uiRightbottombg->AddComponent<SpriteRenderer>();
		uisrbgfour->SetImage(image);
		uisrbgfour->SetScale(Vector2(0.8f, 0.8f));
		uiRightbottombg->GetComponent<Transform>()->SetPosition(Vector2(1406.0f, 626.0f));

		Player* player = object::Instantiate<Player>(eLayerType::Player);
		Transform* tr = player->GetComponent<Transform>();
		tr->SetPosition(Vector2(960.0f, 230.0f));

		Animator* at = player->AddComponent<Animator>();

		at->CreateAnimationFolder(L"PlayerRightStay", L"..\\Resources\\image\\Player\\PlayerRightStay"
			, Vector2(0.0f, 0.0f), 0.05f);
		at->CreateAnimationFolder(L"PlayerRightMove", L"..\\Resources\\image\\Player\\PlayerRightMove"
			, Vector2(0.0f, 0.0f), 0.05f);
		at->CreateAnimationFolder(L"PlayerLeftStay", L"..\\Resources\\image\\Player\\PlayerLeftStay"
			, Vector2(0.0f, 0.0f), 0.05f);
		at->CreateAnimationFolder(L"PlayerLeftMove", L"..\\Resources\\image\\Player\\PlayerLeftMove"
			, Vector2(0.0f, 0.0f), 0.05f);
		at->CreateAnimationFolder(L"PlayerLeftKick", L"..\\Resources\\image\\Player\\PlayerLeftKick"
			, Vector2(0.0f, 0.0f), 0.05f);
		at->CreateAnimationFolder(L"PlayerRightKick", L"..\\Resources\\image\\Player\\PlayerRightKick"
			, Vector2(0.0f, 0.0f), 0.05f);
		at->CreateAnimationFolder(L"PlayerDeath", L"..\\Resources\\image\\Player\\PlayerDeath");
		at->PlayAnimation(L"PlayerRightStay", true);
		at->SetScale(Vector2(0.8f, 0.8f));

		Collider* col = player->AddComponent<Collider>();
		col->SetSize(Vector2(100.0f, 100.0f));

		Monster* monsterone = object::Instantiate<Monster>(eLayerType::Monster);
		tr = monsterone->GetComponent<Transform>();
		tr->SetPosition(Vector2(885.0f, 390.0f));

		at = monsterone->AddComponent<Animator>();
		at->CreateAnimationFolder(L"MonsterRightStay", L"..\\Resources\\image\\Monster\\MonsterRightStay"
			, Vector2(0.0f, 0.0f), 0.05f);
		at->CreateAnimationFolder(L"MonsterLeftStay", L"..\\Resources\\image\\Monster\\MonsterLeftStay"
			, Vector2(0.0f, 0.0f), 0.05f);
		at->CreateAnimationFolder(L"MonsterRightHit", L"..\\Resources\\image\\Monster\\MonsterRightHit"
			, Vector2(0.0f, 0.0f), 0.05f);
		at->CreateAnimationFolder(L"MonsterLeftHit", L"..\\Resources\\image\\Monster\\MonsterLeftHit"
			, Vector2(0.0f, 0.0f), 0.05f);
		at->PlayAnimation(L"MonsterRightStay", true);
		at->SetScale(Vector2(0.8f, 0.8f));

		col = monsterone->AddComponent<Collider>();
		col->SetSize(Vector2(100.0f, 100.0f));

		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);

		Monster* monstertwo = object::Instantiate<Monster>(eLayerType::Monster);
		tr = monstertwo->GetComponent<Transform>();
		tr->SetPosition(Vector2(805.0f, 310.0f));

		at = monstertwo->AddComponent<Animator>();
		at->CreateAnimationFolder(L"MonsterRightStaytwo", L"..\\Resources\\image\\Monster\\MonsterRightStay"
			, Vector2(0.0f, 0.0f), 0.05f);
		at->PlayAnimation(L"MonsterRightStaytwo", true);
		at->SetScale(Vector2(0.8f, 0.8f));

		col = monstertwo->AddComponent<Collider>();
		col->SetSize(Vector2(100.0f, 100.0f));

		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);

		Monster* monsterthree = object::Instantiate<Monster>(eLayerType::Monster);
		tr = monsterthree->GetComponent<Transform>();
		tr->SetPosition(Vector2(725.0f, 390.0f));

		at = monsterthree->AddComponent<Animator>();
		at->CreateAnimationFolder(L"MonsterRightStaythree", L"..\\Resources\\image\\Monster\\MonsterRightStay"
			, Vector2(0.0f, 0.0f), 0.05f);
		at->PlayAnimation(L"MonsterRightStaythree", true);
		at->SetScale(Vector2(0.8f, 0.8f));

		col = monsterthree->AddComponent<Collider>();
		col->SetSize(Vector2(100.0f, 100.0f));

		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);

		BackGround* fireone = object::Instantiate<BackGround>(eLayerType::BackGround);
		tr = fireone->GetComponent<Transform>();
		tr->SetPosition(Vector2(563.0f, 235.0f));

		at = fireone->AddComponent<Animator>();
		at->CreateAnimationFolder(L"fireone", L"..\\Resources\\image\\BackGround\\fire"
			, Vector2(0.0f, 0.0f), 0.05f);
		at->PlayAnimation(L"fireone", true);
		at->SetScale(Vector2(0.5f, 0.5f));

		BackGround* firetwo = object::Instantiate<BackGround>(eLayerType::BackGround);
		tr = firetwo->GetComponent<Transform>();
		tr->SetPosition(Vector2(1045.0f, 435.0f));

		at = firetwo->AddComponent<Animator>();
		at->CreateAnimationFolder(L"firetwo", L"..\\Resources\\image\\BackGround\\fire"
			, Vector2(0.0f, 0.0f), 0.05f);
		at->PlayAnimation(L"firetwo", true);
		at->SetScale(Vector2(0.5f, 0.5f));
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