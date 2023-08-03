#include "jmToolScene.h"
#include "jmTitleScene.h"
#include "jmPlayer.h"
#include "jmSpriteRenderer.h"
#include "jmObject.h"
#include "jmInput.h"
#include "jmTexture.h"
#include "jmTransform.h"
#include "jmResources.h"
#include "jmBackGround.h"
#include "jmTile.h"

namespace jm
{

	ToolScene::ToolScene()
	{
	}

	ToolScene::~ToolScene()
	{
	}

	void ToolScene::Initialize()
	{
		Texture* stage = Resources::Load<Texture>(L"chapter01", L"..\\Resources\\image\\Chapter\\chapterBG0001.bmp");

		BackGround* bg = object::Instantiate<BackGround>(eLayerType::BackGround);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>(L"ToolSceneComponent");
		bgsr->SetImage(stage);
		bgsr->SetScale(Vector2(0.8f, 0.8f));
		bg->GetComponent<Transform>()->SetPosition(Vector2(800.0f, 450.0f));

		CreateTileMap(19, 11);
	}

	void ToolScene::Update()
	{
		Scene::Update();
		// 마우스왼쪽 버튼이 눌렸고 해당 윈도우 활성화가 되어있을 때
		if (Input::GetKey(eKeyCode::MouseLeft) && GetFocus())
		{
			// 마우스의 위치를 받아줄 변수를 생성하고 넣어준다
			Vector2 mousepos = Input::GetMousePosition();

			// 타일을 나눠서 나머지 값을 버려서 정확한 좌표값을 넣어준다
			int idxX = (int)mousepos.x / (TILE_WIDTH);
			int idxY = (int)mousepos.y / (TILE_HEIGHT);

			// 타일 마다 정확하게 각 타일의 중앙에 그려주기 위해서
			// offset 변수를 만들어서 타일크기의 반을 넣어준다
			// 타일형 변수를 만들고 타일로 실제 구현화를 시켜서
			// 마우스의 위치에 타일을 곱해주고 거기에 offset의 각 x, y를 더해줘서
			// 각 타일의 중앙에 그려주도록 구현을한다
			Vector2 offset = Vector2(TILE_WIDTH / 2.0f, TILE_HEIGHT / 2.0f);
			Tile* tile = object::Instantiate<Tile>(eLayerType::Tile,
				Vector2(idxX * TILE_WIDTH + offset.x
					, idxY * TILE_HEIGHT + offset.y));
			// 툴쪽의 타일을 눌러서 빈 타일에 툴쪽의 타일의 그림을 세팅해준다
			tile->SetTileIdx(idxX, idxY);
			tile->SetAble(true);
			std::wstring Name = L"";
			Name += std::to_wstring(idxX) + L",";
			Name += std::to_wstring(idxY);
			tile->SetName(Name);

			if (Input::GetKey(eKeyCode::A))
			{
				tile->SetTileType(ETileType::Wall);
			}
			if (Input::GetKey(eKeyCode::R))
			{
				tile->SetTileType(ETileType::Arrive);
			}
			if (Input::GetKey(eKeyCode::Q))
			{
				tile->SetTileType(ETileType::Player);
			}
			if (Input::GetKey(eKeyCode::W))
			{
				tile->SetTileType(ETileType::NPC);
			}

			auto iter = mTile.find(Name);
			if (iter == mTile.end())
				mTile.insert(make_pair(Name, tile));
			else
				iter->second = tile;
		}

		if (Input::GetKey(eKeyCode::S))
		{
			Save();
		}
		if (Input::GetKey(eKeyCode::L))
		{
			Load();
		}
		if (Input::GetKey(eKeyCode::P))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}

	void ToolScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		//// 가로줄 y축 기준으로 가로로 줄을 긋는다
		//int maxRow = 900 / TILE_HEIGHT + 1;
		//for (int y = 0; y < maxRow; y++)
		//{
		//	MoveToEx(hdc, -1, TILE_HEIGHT * y, NULL); // 라인(선) 시작
		//	LineTo(hdc, 1600, TILE_HEIGHT * y); // 라인(선) 끝
		//}
		//// 세로줄 x축 기준으로 세로로 줄을 긋는다
		//int maxColumn = 1600 / TILE_WIDTH + 1;
		//for (int x = 0; x < maxColumn; x++)
		//{
		//	MoveToEx(hdc, TILE_WIDTH * x, 0, NULL); // 라인(선) 시작
		//	LineTo(hdc, TILE_WIDTH * x, 900); // 라인(선) 끝
		//}
	}

	void ToolScene::Save()
	{
		OPENFILENAME ofn = {};
		wchar_t szFilePath[256] = {};

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"Tile\0*.tile\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (false == GetSaveFileName(&ofn))
			return;

		FILE* pFile = nullptr;

		_wfopen_s(&pFile, szFilePath, L"wb");
		if (pFile == nullptr)
			return;


		for (auto tile : mTile)
		{
			std::wstring TileName = tile.second->Getname();
			Vector2 sourIdx = tile.second->GetSourceTileIdx();
			Vector2 idx = tile.second->GetTileIdx();
			ETileType Tiletype = tile.second->GetTileType();
			bool able = tile.second->GetAble();

			int NameLength = (int)TileName.length();
			
			int sourceX = (int)sourIdx.x;
			int sourceY = (int)sourIdx.y;
			
			int myX = (int)idx.x;
			int myY = (int)idx.y;

			fwrite(&NameLength, sizeof(int), 1, pFile);
			fwrite(TileName.c_str(), sizeof(wchar_t), NameLength, pFile);
			fwrite(&sourceX, sizeof(int), 1, pFile);
			fwrite(&sourceY, sizeof(int), 1, pFile);
			fwrite(&myX, sizeof(int), 1, pFile);
			fwrite(&myY, sizeof(int), 1, pFile);
			fwrite(&Tiletype, sizeof(ETileType), 1, pFile);
			fwrite(&able, sizeof(bool), 1, pFile);
		}

		fclose(pFile);
	}

	void ToolScene::Load()
	{
		OPENFILENAME ofn = {};

		wchar_t szFilePath[256] = {};

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"All\0*.*\0Text\0*.TXT\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (false == GetOpenFileName(&ofn))
			return;

		FILE* pFile = nullptr;
		_wfopen_s(&pFile, szFilePath, L"rb");

		if (pFile == nullptr)
			return;

		for (auto tile : mTile)
		{
			tile.second->SetAble(false);
			tile.second->SetTileType(ETileType::Normal);
			Destroy(tile.second);
		}
		mTile.clear();

		while (true)
		{
			int sourceX = -1;
			int sourceY = -1;

			int	myX = -1;
			int myY = -1;

			int Length = 0;
			wchar_t Name[256] = {};

			std::wstring TileName = Name;

			ETileType Tiletype = ETileType::End;
			bool able = false;

			if (fread(&Length, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(Name, sizeof(wchar_t), Length, pFile) == NULL)
				break;
			if (fread(&sourceX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&sourceY, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&myX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&myY, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&Tiletype, sizeof(ETileType), 1, pFile) == NULL)
				break;
			if (fread(&able, sizeof(bool), 1, pFile) == NULL)
				break;

			Vector2 offset = Vector2(TILE_WIDTH / 2.0f, TILE_HEIGHT / 2.0f);
			Tile* tile = object::Instantiate<Tile>(eLayerType::Tile
				, Vector2(myX * TILE_WIDTH + offset.x
					, myY * TILE_HEIGHT + offset.y));

			tile->SetTile(sourceX, sourceY);
			tile->SetSourceTileIdx(sourceX, sourceY);
			tile->SetTileIdx(myX, myY);
			tile->SetName(TileName);
			tile->SetTileType(Tiletype);
			tile->SetAble(able);
			mTile.insert(make_pair(TileName, tile));
		}

		fclose(pFile);
	}

	void ToolScene::CreateTileMap(int CountX, int CountY)
	{
		Vector2 offset = Vector2(TILE_WIDTH / 2.0f, TILE_HEIGHT / 2.0f);
		for (int i = 0; i < CountY; ++i)
		{
			for (int j = 0; j < CountX; ++j)
			{
				Tile* tile = object::Instantiate<Tile>(eLayerType::Tile
					, Vector2(j * TILE_WIDTH + offset.x
						, i * TILE_HEIGHT + offset.y));

				tile->SetTileIdx(j, i);
				std::wstring Name = L"";
				Name += std::to_wstring(j) + L",";
				Name += std::to_wstring(i);
				tile->SetName(Name);
				tile->SetTileType(ETileType::Normal);

				mTile.insert(make_pair(Name, tile));
			}
		}
	}
}

