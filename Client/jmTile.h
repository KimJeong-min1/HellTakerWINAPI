#pragma once
#include "jmGameObject.h"

namespace jm
{
	enum class ETileType
	{
		Normal,
		Wall,
		Arrive,
		Player,
		NPC,
		End
	};
	
	using namespace math;
	class Tile : public GameObject
	{
	public:
		static UINT mSelectedX;
		static UINT mSelectedY;

		Tile();
		~Tile();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		void SetSourceTileIdx(int x, int y) { mSourceIndexX = x, mSourceIndexY = y; }
		void SetTileIdx(int x, int y) { mIndexX = x; mIndexY = y; }
		Vector2 GetSourceTileIdx() { return Vector2((float)mSourceIndexX, (float)mSourceIndexY); }
		Vector2 GetTileIdx() { return Vector2((float)mIndexX, (float)mIndexY); }
		void SetAble(bool able) {  mable = able; }
		bool GetAble() { return mable; }

		ETileType GetTileType() const
		{
			return m_Type;
		}
		
		void SetTileType(ETileType type)
		{
			m_Type = type;
		}

		void SetTile(int x, int y);
	private:
		class SpriteRenderer* mSpriteRenderer;
		class GameObject* mGameObject;

		UINT mSourceIndexX;
		UINT mSourceIndexY;

		UINT mIndexX;
		UINT mIndexY;
		ETileType m_Type;
		HBRUSH mGreenBrush;
		HBRUSH mRedBrush;
		HBRUSH mBlueBrush;
		HBRUSH mWhiteBrush;
		HBRUSH mYellowBrush;
		bool mable;

	};
}

