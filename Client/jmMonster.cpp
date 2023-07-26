#include "jmMonster.h"
#include "jmAnimator.h"
#include "jmInput.h"

namespace jm
{
	Monster::Monster()
		:mState(eState::Idle)
	{
	}
	Monster::~Monster()
	{
	}
	void Monster::Initialize()
	{
	}
	void Monster::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case jm::Monster::eState::Idle:
			Idle();
			break;
		case jm::Monster::eState::Hit:
			Hit();
			break;
		case jm::Monster::eState::End:
			break;
		default:
			break;
		}

	}
	void Monster::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Monster::OnCollisionEnter(Collider* othher)
	{
	}
	void Monster::OnCollisionStay(Collider* othher)
	{
		Animator* animator = GetComponent<Animator>();

		if (Input::GetKeyDown(eKeyCode::A))
		{
			if (animator->IsActiveAnimaition(L"MonsterRightStay"))
			{
				animator->PlayAnimation(L"MonsterRightHit", false);
				mState = eState::Hit;
			}
			else if (animator->IsActiveAnimaition(L"MonsterLeftStay"))
			{
				animator->PlayAnimation(L"MonsterRightHit", false);
				mState = eState::Hit;
			}
		}
		else if(Input::GetKeyDown(eKeyCode::D))
		{
			if (animator->IsActiveAnimaition(L"MonsterRightStay"))
			{
				animator->PlayAnimation(L"MonsterLeftHit", false);
				mState = eState::Hit;
			}
			else if (animator->IsActiveAnimaition(L"MonsterLeftStay"))
			{
				animator->PlayAnimation(L"MonsterLeftHit", false);
				mState = eState::Hit;
			}
		}
		else if (Input::GetKeyDown(eKeyCode::S) || Input::GetKeyDown(eKeyCode::W))
		{
			if (animator->IsActiveAnimaition(L"MonsterRightStay"))
			{
				animator->PlayAnimation(L"MonsterRightHit", false);
				mState = eState::Hit;
			}
			else if (animator->IsActiveAnimaition(L"MonsterLeftStay"))
			{
				animator->PlayAnimation(L"MonsterLeftHit", false);
				mState = eState::Hit;
			}
		}
	}
	void Monster::OnCollisionExit(Collider* othher)
	{
	}
	void Monster::Idle()
	{
	}
	void Monster::Hit()
	{
		Animator* animator = GetComponent<Animator>();


		if (animator->IsActiveAnimaition(L"MonsterLeftHit"))
		{
			if (animator->IsActiveAnimaitionComplete())
			{
				animator->PlayAnimation(L"MonsterLeftStay", true);
				mState = eState::Idle;
			}
		}
		else if (animator->IsActiveAnimaition(L"MonsterRightHit"))
		{
			if (animator->IsActiveAnimaitionComplete())
			{
				animator->PlayAnimation(L"MonsterRightStay", true);
				mState = eState::Idle;
			}
		}
	}
}
