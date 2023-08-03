#include "jmTile.h"
#include "jmSpriteRenderer.h"
#include "jmCollider.h"
#include "jmTexture.h"
#include "jmResources.h"
#include "jmInput.h"

namespace jm
{
	UINT Tile::mSelectedX = 0;
	UINT Tile::mSelectedY = 0;


	Tile::Tile()
		: mSpriteRenderer(nullptr)
		, mSourceIndexX(0)
		, mSourceIndexY(0)
		, mIndexX(0)
		, mIndexY(0)
		, m_Type(ETileType::Normal)
		, mable(false)
	{
	}
	Tile::~Tile()
	{
	}
	void Tile::Initialize()
	{
		mSpriteRenderer = AddComponent<SpriteRenderer>(L"TileSpriteRendererComponent");

		Texture* stage = Resources::Find<Texture>(L"chapter01");

		mSpriteRenderer->SetScale(Vector2(0.0f, 0.0f));
		if (!mGreenBrush)
			mGreenBrush = CreateSolidBrush(RGB(0, 255, 0));
		if (!mRedBrush)
			mRedBrush = CreateSolidBrush(RGB(255, 0, 0));
		if (!mBlueBrush)
			mBlueBrush = CreateSolidBrush(RGB(0, 0, 255));
		if (!mWhiteBrush)
			mWhiteBrush = CreateSolidBrush(RGB(255, 255, 255));
		if (!mYellowBrush)
			mYellowBrush = CreateSolidBrush(RGB(255, 255, 0));
	}
	void Tile::Update()
	{
		GameObject::Update();
	}
	void Tile::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		HBRUSH Brush = 0;

		switch(m_Type)
		{
		case ETileType::Normal:
			Brush = mGreenBrush;
			break;
		case ETileType::Wall:
			Brush = mRedBrush;
			break;
		case ETileType::Arrive:
			Brush = mBlueBrush;
			break;
		case ETileType::Player:
			Brush = mWhiteBrush;
			break;
		case ETileType::NPC:
			Brush = mYellowBrush;
			break;
		}
		
		Vector2 offset = Vector2(TILE_WIDTH / 2.0f, TILE_HEIGHT / 2.0f);
		// RECT가 LONG타입여서 형변환을 해준다.
		// 각 위치에서 카메라 위치를 빼주면 카메라가 적용이 된다.
		RECT	rc;
		rc.left = (LONG)mIndexX * TILE_WIDTH;
		rc.top = (LONG)mIndexY * TILE_HEIGHT;
		rc.right = (LONG)mIndexX * TILE_WIDTH + TILE_WIDTH;
		rc.bottom = (LONG)mIndexY * TILE_HEIGHT + TILE_HEIGHT;
		
		if (mable == false)
		{
			FrameRect(hdc, &rc, Brush);
		}
		else
		{
			FillRect(hdc, &rc, Brush);
		}
	}
	void Tile::SetTile(int x, int y)
	{
		mSpriteRenderer->SetTile(x, y);
	}
}