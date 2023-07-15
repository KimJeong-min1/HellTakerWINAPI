#pragma once
#include "jmGameObject.h"


namespace jm
{
	class Text : public GameObject
	{
	public:
		Text();
		virtual ~Text();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:

	};
}