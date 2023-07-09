#include "jmTitleScene.h"
#include "jmPlayer.h"
#include "jmSpriteRenderer.h"
#include "jmObject.h"

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
		Player* player = object::Instantiate<Player>(eLayerType::Player);
		player->AddComponent<SpriteRenderer>();
	}
	void TitleScene::Update()
	{
		Scene::Update();
	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}
