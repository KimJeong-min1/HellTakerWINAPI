#include "jmApplication.h"
#include "jmInput.h"
#include "jmTime.h"
#include "jmrand.h"
#include "jmTitleScene.h"
#include "jmSceneManager.h"
#include "jmCollisionManager.h"

namespace jm
{
	// 생성자
	Application::Application()
		// 리터럴 라이즈 초기화
		:mHwnd(NULL) // 나의 윈도우즈 핸들
		, mHdc(NULL) // 출력에 필요한 정보를 가지는 데이터 구조,좌표 등 정보를 저장하는 데이터 구조체의 위치를 알기 위한 핸들 
		, mWidth(0) // 가로
		, mHeight(0) // 세로
		, mBackBuffer(NULL) // 뒤에서 데이터를 보관해주는 변수?
		, mBackHdc(NULL) // 뒤에서 필요한 정보를 저장하는 데이터 구조체의 위치를 알기 위한 핸들
	{
	}

	// 소멸자
	Application::~Application()
	{
	}

	// 초기화 해주는 함수
	void Application::Initialize(HWND hwnd)
	{
		// main에 윈도우핸들을 나의 윈도우핸들에 대입
		mHwnd = hwnd;
		// 나의 윈도우핸들에 데이터 구조체 위치를 알기 위한 나의 핸들에 대입
		mHdc = GetDC(mHwnd);
		// 가로 값 대입
		mWidth = 1600;
		// 세로 값 대입
		mHeight = 900;
		// RECT class 는 상하좌우 기준을 바탕으로 사각형을 만드는 함수
		RECT rect = { 0, 0, mWidth, mHeight };
		// 윈도우의 스타일(타이틀 바의 유무, 타이틀 바의 높이, 경계선의 두께)와 메뉴의 존재 여부 등을 고려하여 작업 영역의 크기를
		// 정하는 함수
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
		// 윈도우를 어떤 위치에 생성하게 해주는 함수
		SetWindowPos(mHwnd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, 0);
		// 윈도우를 표시하는 방법을 제어하는 함수
		ShowWindow(mHwnd, true);

		// 윈도우 해상도와 동일한 비트맵 생성
		mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);
		// 새로 생성한 비트맵을 가르키는 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc);
		// 새로 생성한 비트맵과 DC를 서로 연결
		HBITMAP defalutBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		// 삭제
		DeleteObject(defalutBitmap);

		// Time 클래스 초기화
		Time::Initialize();
		// Input 클래스 초기화
		Input::Initialize();
		CollisionManager::Initialize();
		SceneManager::Initialize();
	}

	// 함수를 실행시켜주는 함수
	void Application::Run()
	{
		// 업데이트 해주는 함수
		Update();
		// 그려주는 함수
		Render();
	}

	// 업데이트 해주는 함수
	void Application::Update()
	{
		// Input 클래스 업데이트 해주는 함수
		Input::Update();
		// Time 클래스 업데이트 해주는 함수
		Time::Update();
		// Collision 을 업데이트 해주는 함수
		CollisionManager::Update();
		// Scene 을 업데이트 해주는 함수
		SceneManager::Update();
	}

	// 객체를 그려주는 함수
	void Application::Render()
	{
		//Rectangle(mhdc, 100, 100, 200, 200);
		//HBRUSH brush = CreateSolidBrush(RGB(125, 125, 125));
		HBRUSH brush = CreateSolidBrush(RGB(2, 2, 27));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHdc, brush);
		
		// 화면 전체를 흰색으로 그려주는 함수
		Rectangle(mBackHdc, -1, -1, mWidth + 1, mHeight + 1);
		SelectObject(mBackHdc, oldBrush);
		DeleteObject(brush);

		// 프레임 계산을 윈도우에 그려주는 함수
		Time::Render(mBackHdc);
		// 충돌 범위를 그려준다
		CollisionManager::Render(mBackHdc);
		// 씬매니저 클래스를 통해서 그림을 그려준다
		SceneManager::Render(mBackHdc);
		
		// Scene 안에 그려진 객체를 mHdc에 그림을 복사해주는 함수
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
}
