#include "jmPlayer.h"
#include "jmTransform.h"
#include "jmInput.h"
#include "jmTime.h"
#include "jmAnimator.h"

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

	void Player::Idle()
	{
		Animator* animator = GetComponent<Animator>();

		if (Input::GetKey(eKeyCode::W))
		{
			if (animator->IsActiveAnimaition(L"PlayerRightStay") == true)
			{
				animator->PlayAnimation(L"PlayerRightMove", true);
				mState = eState::Move;
			}
			else if (animator->IsActiveAnimaition(L"PlayerLeftStay") == true)
			{
				animator->PlayAnimation(L"PlayerLeftMove", true);
				mState = eState::Move;
			}
		}
		else if (Input::GetKey(eKeyCode::A))
		{
			animator->PlayAnimation(L"PlayerLeftMove", true);
			mState = eState::Move;
		}
		else if (Input::GetKey(eKeyCode::S))
		{
			if (animator->IsActiveAnimaition(L"PlayerRightStay") == true)
			{
				animator->PlayAnimation(L"PlayerRightMove", true);
				mState = eState::Move;
			}
			else if (animator->IsActiveAnimaition(L"PlayerLeftStay") == true)
			{
				animator->PlayAnimation(L"PlayerLeftMove", true);
				mState = eState::Move;
			}
		}
		else if (Input::GetKey(eKeyCode::D))
		{
			animator->PlayAnimation(L"PlayerRightMove", true);
			mState = eState::Move;
		}

		if (Input::GetKey(eKeyCode::K))
		{
			if (animator->IsActiveAnimaition(L"PlayerRightStay") == true)
			{
				animator->PlayAnimation(L"PlayerRightKick", false);
				mState = eState::Kick;
			}
			else if (animator->IsActiveAnimaition(L"PlayerLeftStay") == true)
			{
				animator->PlayAnimation(L"PlayerLeftKick", false);
				mState = eState::Kick;
			}
		}
	}

	void Player::Move()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::W))
		{
			pos.y -= 300.0f * Time::DeltaTime();
		}
		else if (Input::GetKey(eKeyCode::A))
		{
			pos.x -= 300.0f * Time::DeltaTime();
		}
		else if (Input::GetKey(eKeyCode::S))
		{
			pos.y += 300.0f * Time::DeltaTime();
		}
		else if (Input::GetKey(eKeyCode::D))
		{
			pos.x += 300.0f * Time::DeltaTime();
		}
		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::W) || Input::GetKeyUp(eKeyCode::A)
			|| Input::GetKeyUp(eKeyCode::S) || Input::GetKeyUp(eKeyCode::D))
		{
			Animator* animator = GetComponent<Animator>();
			if (animator->IsActiveAnimaition(L"PlayerLeftMove") == true)
			{
				animator->PlayAnimation(L"PlayerLeftStay", true);
				mState = eState::Idle;
			}
			else if (animator->IsActiveAnimaition(L"PlayerRightMove") == true)
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
	}
}
