#include "jmApplication.h"
#include "jmInput.h"
#include "Time.h"
#include "jmrand.h"

namespace jm
{
	// ������
	Application::Application()
		// ���ͷ� ������ �ʱ�ȭ
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

	// �Ҹ���
	Application::~Application()
	{
	}

	// �ʱ�ȭ ���ִ� �Լ�
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

		// ������ �ػ󵵿� ������ ��Ʈ�� ����
		mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);
		// ���� ������ ��Ʈ���� ����Ű�� DC ����
		mBackHdc = CreateCompatibleDC(mHdc);
		// ���� ������ ��Ʈ�ʰ� DC�� ���� ����
		HBITMAP defalutBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(defalutBitmap);

		Time::Initialize();
		Input::Initialize();
	}

	// �Լ��� ��������ִ� �Լ�
	void Application::Run()
	{
		Update();
		Render();
	}

	// ������Ʈ ���ִ� �Լ�
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

	// ���� �׷��ִ� �Լ�
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

	// ù��° ���� ��ġ�� ���������� �ٲ��ִ� �Լ�
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

	// �ι�° ���� ��ġ�� ���������� �ٲ��ִ� �Լ�
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
