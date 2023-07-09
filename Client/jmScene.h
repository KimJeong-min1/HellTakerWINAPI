#pragma once
#include "jmEntity.h"
#include "jmLayer.h"

namespace jm
{
	using namespace jm::enums;
	
	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);

		void AddGameObject(eLayerType type, GameObject* gameObj)
		{
			mLayers[(int)type].AddGameObject(gameObj);
		}
	private:
		std::vector<Layer> mLayers;
	};
}

