#pragma once
#include "jmGameObject.h"


namespace jm
{
	class Devil : public GameObject
	{
	public:
		Devil();
		virtual ~Devil();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:

	};
}