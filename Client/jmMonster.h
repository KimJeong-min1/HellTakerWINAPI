#pragma once
#include "jmGameObject.h"


namespace jm
{
	class Monster : public GameObject
	{
	public:
		enum class eState
		{
			Idle,
			Hit,
			End
		};
		Monster();
		virtual ~Monster();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class Collider* othher) override;
		virtual void OnCollisionStay(class Collider* othher) override;
		virtual void OnCollisionExit(class Collider* othher) override;

		void Idle();
		void Hit();

	private:
		eState mState;
	};
}