#include "jmPlayer.h"
#include "jmTransform.h"
#include "jmInput.h"
#include "jmTime.h"
#include "jmAnimator.h"
#include "jmCollider.h"
#include "jmMonster.h"

namespace jm
{
	Player::Player()
		:mState(eState::Idle)
	{
	}
	Player::~Player()
	{
	}
	void Player::Initialize()
	{
	}
	void Player::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		//pixel ����
		//COLORREF rgb = mFloorTexture->GetTexturePixel(tr->GetPosition().x, tr->GetPosition().y + 48);
		
		switch (mState)
		{
		case Player::eState::Idle:
			Idle();
			break;
		case Player::eState::Move:
			Move();
			break;
		case Player::eState::Kick:
			Kick();
			break;
		case Player::eState::Death:
			Dead();
			break;
		case Player::eState::End:
			break;
		default:
			break;
		}
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	// other = �÷��̾��� �浹ü�� �浹�� �ٸ� �浹ü
	void Player::OnCollisionEnter(Collider* other)
	{
		Monster* CollisionMonster = (Monster*)other->GetOwner();
		Animator* animator = GetComponent<Animator>();
		if (animator->IsActiveAnimaition(L"PlayerLeftKick"))
		{
			CollisionMonster->Hit();
		}
	}

	void Player::OnCollisionStay(Collider* other)
	{
		Animator* animator = GetComponent<Animator>();

		if (Input::GetKeyDown(eKeyCode::A))
		{
			if (animator->IsActiveAnimaition(L"PlayerRightStay"))
			{
				animator->PlayAnimation(L"PlayerLeftKick", false);
				mState = eState::Kick;
			}
			else if (animator->IsActiveAnimaition(L"PlayerLeftStay"))
			{
				animator->PlayAnimation(L"PlayerLeftKick", false);
				mState = eState::Kick;
			}
		}
		else if (Input::GetKeyDown(eKeyCode::D))
		{
			if (animator->IsActiveAnimaition(L"PlayerRightStay"))
			{
				animator->PlayAnimation(L"PlayerRightKick", false);
				mState = eState::Kick;
			}
			else if (animator->IsActiveAnimaition(L"PlayerLeftStay"))
			{
				animator->PlayAnimation(L"PlayerRightKick", false);
				mState = eState::Kick;
			}
		}
		else if (Input::GetKeyDown(eKeyCode::S) || Input::GetKeyDown(eKeyCode::W))
		{
			if (animator->IsActiveAnimaition(L"PlayerRightStay"))
			{
				animator->PlayAnimation(L"PlayerRightKick", false);
				mState = eState::Kick;
			}
			else if (animator->IsActiveAnimaition(L"PlayerLeftStay"))
			{
				animator->PlayAnimation(L"PlayerLeftKick", false);
				mState = eState::Kick;
			}
		}
	}

	void Player::OnCollisionExit(Collider* othher)
	{
	}

	void Player::Idle()
	{
		Animator* animator = GetComponent<Animator>();

		if (Input::GetKey(eKeyCode::W) || Input::GetKey(eKeyCode::Up))
		{
			if (animator->IsActiveAnimaition(L"PlayerRightStay"))
			{
				animator->PlayAnimation(L"PlayerRightMove", true);
				mState = eState::Move;
			}
			else if (animator->IsActiveAnimaition(L"PlayerLeftStay"))
			{
				animator->PlayAnimation(L"PlayerLeftMove", true);
				mState = eState::Move;
			}
		}
		else if (Input::GetKey(eKeyCode::A)|| Input::GetKey(eKeyCode::Left))
		{
			animator->PlayAnimation(L"PlayerLeftMove", true);
			mState = eState::Move;
		}
		else if (Input::GetKey(eKeyCode::S) || Input::GetKey(eKeyCode::Down))
		{
			if (animator->IsActiveAnimaition(L"PlayerRightStay"))
			{
				animator->PlayAnimation(L"PlayerRightMove", true);
				mState = eState::Move;
			}
			else if (animator->IsActiveAnimaition(L"PlayerLeftStay"))
			{
				animator->PlayAnimation(L"PlayerLeftMove", true);
				mState = eState::Move;
			}
		}
		else if (Input::GetKey(eKeyCode::D) || Input::GetKey(eKeyCode::Right))
		{
			animator->PlayAnimation(L"PlayerRightMove", true);
			mState = eState::Move;
		}

		if (Input::GetKeyDown(eKeyCode::V))
		{
			animator->PlayAnimation(L"PlayerDeath", false);
			mState = eState::Death;
		}
	}

	void Player::Move()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::W) || Input::GetKey(eKeyCode::Up))
		{
			pos.y -= 300.0f * Time::DeltaTime();
		}
		else if (Input::GetKey(eKeyCode::A) || Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 300.0f * Time::DeltaTime();
		}
		else if (Input::GetKey(eKeyCode::S) || Input::GetKey(eKeyCode::Down))
		{
			pos.y += 300.0f * Time::DeltaTime();
		}
		else if (Input::GetKey(eKeyCode::D) || Input::GetKey(eKeyCode::Right))
		{
			pos.x += 300.0f * Time::DeltaTime();
		}
		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::W) || Input::GetKeyUp(eKeyCode::A)
			|| Input::GetKeyUp(eKeyCode::S) || Input::GetKeyUp(eKeyCode::D)
			|| Input::GetKey(eKeyCode::Up) || Input::GetKey(eKeyCode::Left)
			|| Input::GetKey(eKeyCode::Down) || Input::GetKey(eKeyCode::Right))
		{
			Animator* animator = GetComponent<Animator>();
			if (animator->IsActiveAnimaition(L"PlayerLeftMove"))
			{
				animator->PlayAnimation(L"PlayerLeftStay", true);
				mState = eState::Idle;
			}
			else if (animator->IsActiveAnimaition(L"PlayerRightMove"))
			{
				animator->PlayAnimation(L"PlayerRightStay", true);
				mState = eState::Idle;
			}
		}
	}

	void Player::Kick()
	{
		Animator* animator = GetComponent<Animator>();


		if (animator->IsActiveAnimaition(L"PlayerRightKick"))
		{
			if (animator->IsActiveAnimaitionComplete())
			{
				animator->PlayAnimation(L"PlayerRightStay", true);
				mState = eState::Idle;
			}
		}
		else if (animator->IsActiveAnimaition(L"PlayerLeftKick"))
		{
			if (animator->IsActiveAnimaitionComplete())
			{
				animator->PlayAnimation(L"PlayerLeftStay", true);
				mState = eState::Idle;
			}
		}
	}

	void Player::Dead()
	{
		Animator* animator = GetComponent<Animator>();
		
		if (animator->IsActiveAnimaition(L"PlayerDeath"))
		{
			if (animator->IsActiveAnimaitionComplete())
			{
				animator->PlayAnimation(L"PlayerRightStay", true);
				mState = eState::Idle;
			}
		}
	}
}
