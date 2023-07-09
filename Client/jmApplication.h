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
	
	private:
		HWND mHwnd;
		HDC mHdc;

		UINT mWidth;
		UINT mHeight;

		HDC mBackHdc;
		HBITMAP mBackBuffer;
	};
}

