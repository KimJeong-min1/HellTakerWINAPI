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

		// 초기화
		virtual void Initialize() override;
		// 업데이트
		virtual void Update() override;
		// 랜더
		virtual void Render(HDC hdc) override;

		// 충돌이 되었을 때
		virtual void OnCollisionEnter(class Collider* othher) override;
		// 충돌중 일때
		virtual void OnCollisionStay(class Collider* othher) override;
		// 충돌에서 빠져나갈 때
		virtual void OnCollisionExit(class Collider* othher) override;

		void Idle();
		void Move();
		void Kick();
		void Dead();

		//class Texture* mFloorTexture;

	private:
		eState mState;
	};
}