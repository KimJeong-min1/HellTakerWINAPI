#include "jmApplication.h"
#include "jmInput.h"
#include "Time.h"
#include "jmrand.h"

namespace jm
{
	// 생성자
	Application::Application()
		// 리터럴 라이즈 초기화
		:mHwnd(NULL)
		, mHdc(NULL)
		, PlayerSpeed(600.f)
		, m_Time(3.f)
		, m_able(false)
		, mWidth(0)
		, mHeight(0)
		, mBackBuffer(NULL)
		, mBackHdc(NULL)
	{
	}

	// 소멸자
	Application::~Application()
	{
	}

	// 초기화 해주는 함수
	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);
		mWidth = 1600;
		mHeight = 900;
		mPlayerPos.x = 50.f;
		mPlayerPos.y = 50.f;
		mPlayerPos2.x = 50.f;
		mPlayerPos2.y = 50.f;
		RECT rect = { 0, 0, mWidth, mHeight };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		SetWindowPos(mHwnd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, 0);

		ShowWindow(mHwnd, true);

		// 윈도우 해상도와 동일한 비트맵 생성
		mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);
		// 새로 생성한 비트맵을 가르키는 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc);
		// 새로 생성한 비트맵과 DC를 서로 연결
		HBITMAP defalutBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(defalutBitmap);

		Time::Initialize();
		Input::Initialize();
	}

	// 함수를 실행시켜주는 함수
	void Application::Run()
	{
		Update();
		Render();
	}

	// 업데이트 해주는 함수
	void Application::Update()
	{
		RanDom r;
		int ran1 = r.nextInRange(0, 15);
		int ran2 = r.nextInRange(0, 15);
		Input::Update();
		Time::Update();
		MoveFunc1(ran1, ran2, 8);

		if (m_Time >= 0)
		{
			m_Time -= Time::DeltaTime();
		}
		else if (m_able == false)
		{
			m_able = true;
		}

		if (m_able == true)
		{
			int ran3 = r.nextInRange(0, 15);
			int ran4 = r.nextInRange(0, 15);
			MoveFunc2(ran3, ran4, 8);
		}
	}

	// 원을 그려주는 함수
	void Application::Render()
	{
		//Rectangle(mhdc, 100, 100, 200, 200);


		Time::Render(mBackHdc);

		Rectangle(mBackHdc, -1, -1, mWidth + 1, mHeight + 1);

		Ellipse(mBackHdc, -50.f + mPlayerPos.x, -50.f + mPlayerPos.y, 50.f + mPlayerPos.x, 50.f + mPlayerPos.y);

		if (m_able == true)
		{
			Time::Render(mBackHdc);
			Ellipse(mBackHdc, -50.f + mPlayerPos2.x, -50.f + mPlayerPos2.y, 50.f + mPlayerPos2.x, 50.f + mPlayerPos2.y);
		}

		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}

	// 첫번째 원의 위치를 랜덤적으로 바꿔주는 함수
	void Application::MoveFunc1(int _Rand1, int _Rand2, int _Max)
	{
		float RatioX = (float)_Rand1 / (float)_Max - 1;
		float RatioY = (float)_Rand2 / (float)_Max - 1;
		if (mPlayerPos.x - 50.f < 0)
		{
			mPlayerPos.x += PlayerSpeed * Time::DeltaTime() * 1;
		}
		if (mPlayerPos.x + 50.f > 1584)
		{
			mPlayerPos.x -= PlayerSpeed * Time::DeltaTime() * 1;
		}
		if (mPlayerPos.y - 50.f < 0)
		{
			mPlayerPos.y += PlayerSpeed * Time::DeltaTime() * 1;
		}
		if (mPlayerPos.y + 50.f > 842)
		{
			mPlayerPos.y -= PlayerSpeed * Time::DeltaTime() * 1;
		}
		mPlayerPos.x += PlayerSpeed * Time::DeltaTime() * RatioX;
		mPlayerPos.y += PlayerSpeed * Time::DeltaTime() * RatioY;
	}

	// 두번째 원의 위치를 랜덤적으로 바꿔주는 함수
	void Application::MoveFunc2(int _Rand1, int _Rand2, int _Max)
	{
		float RatioX = (float)_Rand1 / (float)_Max - 1;
		float RatioY = (float)_Rand2 / (float)_Max - 1;
		if (mPlayerPos2.x - 50.f < 0)
		{
			mPlayerPos2.x += PlayerSpeed * Time::DeltaTime() * 1;
		}
		if (mPlayerPos2.x + 50.f > 1584)
		{
			mPlayerPos2.x -= PlayerSpeed * Time::DeltaTime() * 1;
		}
		if (mPlayerPos2.y - 50.f < 0)
		{
			mPlayerPos2.y += PlayerSpeed * Time::DeltaTime() * 1;
		}
		if (mPlayerPos2.y + 50.f > 842)
		{
			mPlayerPos2.y -= PlayerSpeed * Time::DeltaTime() * 1;
		}
		mPlayerPos2.x += PlayerSpeed * Time::DeltaTime() * RatioX;
		mPlayerPos2.y += PlayerSpeed * Time::DeltaTime() * RatioY;
	}
}
