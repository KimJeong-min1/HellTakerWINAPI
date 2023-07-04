#pragma once
#include "Commoninclude.h"


namespace jm
{
	// 선언부만 작성한다.
	using namespace math;
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();
		void Update();
		void Render();
		void MoveFunc1(int _Rand1, int _Rand2, int _Max);
		void MoveFunc2(int _Rand1, int _Rand2, int _Max);

	private:
		HWND mHwnd;
		HDC mHdc;
		HDC mBackHdc;

		UINT mWidth;
		UINT mHeight;

		HBITMAP mBackBuffer;

		float PlayerSpeed;
		float m_Time;

		bool m_able;

		Vector2 mPlayerPos;
		Vector2 mPlayerPos2;
	};
}

