#include "jmInput.h"
#include "jmApplication.h"

extern jm::Application application;

namespace jm
{
	std::vector<Input::Key> Input::mKeys = {};
	math::Vector2 Input::mMousePosition = math::Vector2::zero;

	int ASCII[(int)eKeyCode::End] =
	{
		'Q','W','E','R','T','Y','U','I','O','P',
		'A','S','D','F','G','H','J','K','L',
		'Z','X','C','V','B','N','M',
		VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT,
		VK_LBUTTON, VK_RBUTTON, VK_MBUTTON,
	};

	void Input::Initialize()
	{
		for (size_t i = 0; i < (int)eKeyCode::End; i++)
		{
			Key key = {};
			key.code = (eKeyCode)i;
			key.state = eKeyState::None;
			key.bPressed = false;

			mKeys.push_back(key);
		}
	}

	void Input::Update()
	{
		for (size_t i = 0; i < (int)eKeyCode::End; i++)
		{
			// 해당 키가 눌려졌다.
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				// 이전 프레임에도 눌려져 있었다.
				if (mKeys[i].bPressed == true)
				{
					mKeys[i].state = eKeyState::Pressed;
				}
				else
				{
					mKeys[i].state = eKeyState::Down;
				}

				mKeys[i].bPressed = true;
			}
			// 해당 키가 안눌려져 있다
			else
			{
				// 이전 프레임에 눌려져있었다.
				if (mKeys[i].bPressed == true)
				{
					mKeys[i].state = eKeyState::Up;
				}
				else
				{
					mKeys[i].state = eKeyState::None;
				}

				mKeys[i].bPressed = false;
			}
		}
		// 마우스 위치를 받기위한 포인트형 변수
		POINT mousePos = {};
		// 마우스 위치를 가져와주는 함수
		GetCursorPos(&mousePos);
		// 마우스 위치를 더욱 화면에 맞게 변환?
		ScreenToClient(application.GetHwnd(), &mousePos);
		mMousePosition.x = (float)mousePos.x;
		mMousePosition.y = (float)mousePos.y;
	}

}