#pragma once
#include "jmScene.h"

namespace jm
{

	class CutScene : public Scene
	{
	public:
		CutScene();
		virtual ~CutScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:


	};

}
