#pragma once
#include "jmGameObject.h"


namespace jm
{
	class Player : public GameObject
	{
	public:
		enum class eState
		{
			Idle,
			Move,
			Kick,
			Death,
			End,
		};
		Player();
		virtual ~Player();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		void Idle();
		void Move();
		void Kick();
		void Dead();

	private:
		eState mState;
	};
}