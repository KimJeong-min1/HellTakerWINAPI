#pragma once
#include "jmScene.h"
#include "jmTile.h"

namespace jm
{
	class ToolScene : public Scene
	{
	public:
		ToolScene();
		virtual ~ToolScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		void Save();
		void Load();
	private:
		void CreateTileMap(int CountX, int CountY);
		std::map<std::wstring, class Tile*> mTile;
	};
}

