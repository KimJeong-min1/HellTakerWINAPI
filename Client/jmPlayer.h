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

		// �ʱ�ȭ
		virtual void Initialize() override;
		// ������Ʈ
		virtual void Update() override;
		// ����
		virtual void Render(HDC hdc) override;

		// �浹�� �Ǿ��� ��
		virtual void OnCollisionEnter(class Collider* othher) override;
		// �浹�� �϶�
		virtual void OnCollisionStay(class Collider* othher) override;
		// �浹���� �������� ��
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