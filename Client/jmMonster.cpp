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
		if (!mMonsterAnimator)
		{
			mMonsterAnimator = GetComponent<Animator>();
		}
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
		
	}
	void Monster::OnCollisionExit(Collider* othher)
	{
	}
	void Monster::ChagenAnimation(const std::wstring& AnimName)
	{
	}
	void Monster::Idle()
	{
	}
	void Monster::Hit()
	{

		if (mMonsterAnimator->IsActiveAnimaition(L"MonsterLeftHit"))
		{
			if (mMonsterAnimator->IsActiveAnimaitionComplete())
			{
				mMonsterAnimator->PlayAnimation(L"MonsterLeftStay", true);
				mState = eState::Idle;
			}
		}
		else if (mMonsterAnimator->IsActiveAnimaition(L"MonsterRightHit"))
		{
			if (mMonsterAnimator->IsActiveAnimaitionComplete())
			{
				mMonsterAnimator->PlayAnimation(L"MonsterRightStay", true);
				mState = eState::Idle;
			}
		}
	}
}
