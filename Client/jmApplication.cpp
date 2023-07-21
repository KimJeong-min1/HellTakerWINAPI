#include "jmApplication.h"
#include "jmInput.h"
#include "jmTime.h"
#include "jmrand.h"
#include "jmTitleScene.h"
#include "jmSceneManager.h"
#include "jmCollisionManager.h"

namespace jm
{
	// ������
	Application::Application()
		// ���ͷ� ������ �ʱ�ȭ
		:mHwnd(NULL) // ���� �������� �ڵ�
		, mHdc(NULL) // ��¿� �ʿ��� ������ ������ ������ ����,��ǥ �� ������ �����ϴ� ������ ����ü�� ��ġ�� �˱� ���� �ڵ� 
		, mWidth(0) // ����
		, mHeight(0) // ����
		, mBackBuffer(NULL) // �ڿ��� �����͸� �������ִ� ����?
		, mBackHdc(NULL) // �ڿ��� �ʿ��� ������ �����ϴ� ������ ����ü�� ��ġ�� �˱� ���� �ڵ�
	{
	}

	// �Ҹ���
	Application::~Application()
	{
	}

	// �ʱ�ȭ ���ִ� �Լ�
	void Application::Initialize(HWND hwnd)
	{
		// main�� �������ڵ��� ���� �������ڵ鿡 ����
		mHwnd = hwnd;
		// ���� �������ڵ鿡 ������ ����ü ��ġ�� �˱� ���� ���� �ڵ鿡 ����
		mHdc = GetDC(mHwnd);
		// ���� �� ����
		mWidth = 1600;
		// ���� �� ����
		mHeight = 900;
		// RECT class �� �����¿� ������ �������� �簢���� ����� �Լ�
		RECT rect = { 0, 0, mWidth, mHeight };
		// �������� ��Ÿ��(Ÿ��Ʋ ���� ����, Ÿ��Ʋ ���� ����, ��輱�� �β�)�� �޴��� ���� ���� ���� ����Ͽ� �۾� ������ ũ�⸦
		// ���ϴ� �Լ�
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
		// �����츦 � ��ġ�� �����ϰ� ���ִ� �Լ�
		SetWindowPos(mHwnd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, 0);
		// �����츦 ǥ���ϴ� ����� �����ϴ� �Լ�
		ShowWindow(mHwnd, true);

		// ������ �ػ󵵿� ������ ��Ʈ�� ����
		mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);
		// ���� ������ ��Ʈ���� ����Ű�� DC ����
		mBackHdc = CreateCompatibleDC(mHdc);
		// ���� ������ ��Ʈ�ʰ� DC�� ���� ����
		HBITMAP defalutBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		// ����
		DeleteObject(defalutBitmap);

		// Time Ŭ���� �ʱ�ȭ
		Time::Initialize();
		// Input Ŭ���� �ʱ�ȭ
		Input::Initialize();
		CollisionManager::Initialize();
		SceneManager::Initialize();
	}

	// �Լ��� ��������ִ� �Լ�
	void Application::Run()
	{
		// ������Ʈ ���ִ� �Լ�
		Update();
		// �׷��ִ� �Լ�
		Render();
	}

	// ������Ʈ ���ִ� �Լ�
	void Application::Update()
	{
		// Input Ŭ���� ������Ʈ ���ִ� �Լ�
		Input::Update();
		// Time Ŭ���� ������Ʈ ���ִ� �Լ�
		Time::Update();
		// Collision �� ������Ʈ ���ִ� �Լ�
		CollisionManager::Update();
		// Scene �� ������Ʈ ���ִ� �Լ�
		SceneManager::Update();
	}

	// ��ü�� �׷��ִ� �Լ�
	void Application::Render()
	{
		//Rectangle(mhdc, 100, 100, 200, 200);
		//HBRUSH brush = CreateSolidBrush(RGB(125, 125, 125));
		HBRUSH brush = CreateSolidBrush(RGB(2, 2, 27));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHdc, brush);
		
		// ȭ�� ��ü�� ������� �׷��ִ� �Լ�
		Rectangle(mBackHdc, -1, -1, mWidth + 1, mHeight + 1);
		SelectObject(mBackHdc, oldBrush);
		DeleteObject(brush);

		// ������ ����� �����쿡 �׷��ִ� �Լ�
		Time::Render(mBackHdc);
		// �浹 ������ �׷��ش�
		CollisionManager::Render(mBackHdc);
		// ���Ŵ��� Ŭ������ ���ؼ� �׸��� �׷��ش�
		SceneManager::Render(mBackHdc);
		
		// Scene �ȿ� �׷��� ��ü�� mHdc�� �׸��� �������ִ� �Լ�
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
}
