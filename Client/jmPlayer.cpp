#include "jmPlayer.h"
#include "jmTransform.h"
#include "jmInput.h"
#include "jmTime.h"
#include "jmAnimator.h"

namespace jm
{
	Player::Player()
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
		Vector2 pos = tr->GetPosition();
		Animator* anim = GetComponent<Animator>();

		if (Input::GetKey(eKeyCode::W))
		{
			if (anim->IsActiveAnimaition(L"RightStay") == true)
			{
				anim->PlayAnimation(L"RightMove", true);
			}
			else if (anim->IsActiveAnimaition(L"LeftStay") == true)
			{
				anim->PlayAnimation(L"LeftMove", true);
			}
			pos.y -= 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::A))
		{
			anim->PlayAnimation(L"LeftMove", true);
			pos.x -= 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S))
		{
			if (anim->IsActiveAnimaition(L"RightStay") == true)
			{
				anim->PlayAnimation(L"RightMove", true);
			}
			else if (anim->IsActiveAnimaition(L"LeftStay") == true)
			{
				anim->PlayAnimation(L"LeftMove", true);
			}
			pos.y += 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::D))
		{
			anim->PlayAnimation(L"RightMove", true);
			pos.x += 300.0f * Time::DeltaTime();
		}

		if (Input::GetKeyUp(eKeyCode::W))
		{
			if (anim->IsActiveAnimaition(L"RightMove") == true)
			{
				anim->PlayAnimation(L"RightStay", true);
			}
			else if (anim->IsActiveAnimaition(L"LeftMove") == true)
			{
				anim->PlayAnimation(L"LeftStay", true);
			}
		}
		else if (Input::GetKeyUp(eKeyCode::A))
		{
			anim->PlayAnimation(L"LeftStay", true);
		}
		else if (Input::GetKeyUp(eKeyCode::S))
		{
			if (anim->IsActiveAnimaition(L"RightMove") == true)
			{
				anim->PlayAnimation(L"RightStay", true);
			}
			else if (anim->IsActiveAnimaition(L"LeftMove") == true)
			{
				anim->PlayAnimation(L"LeftStay", true);
			}
		}
		else if (Input::GetKeyUp(eKeyCode::D))
		{
			anim->PlayAnimation(L"RightStay", true);
		}

		tr->SetPosition(pos);
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
