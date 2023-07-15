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
				anim->PlayAnimation(L"Move", true);

				pos.y -= 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::A))
		{
			anim->PlayAnimation(L"Move", true);

			pos.x -= 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S))
		{
			anim->PlayAnimation(L"Move", true);

			pos.y += 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::D))
		{
			anim->PlayAnimation(L"Move", true);

			pos.x += 300.0f * Time::DeltaTime();
		}

		if (Input::GetKeyUp(eKeyCode::W))
		{
			anim->PlayAnimation(L"Stay", true);
		}
		if (Input::GetKeyUp(eKeyCode::A))
		{
			anim->PlayAnimation(L"Stay", true);
		}
		if (Input::GetKeyUp(eKeyCode::S))
		{
			anim->PlayAnimation(L"Stay", true);
		}
		if (Input::GetKeyUp(eKeyCode::D))
		{
			anim->PlayAnimation(L"Stay", true);
		}

		tr->SetPosition(pos);
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
