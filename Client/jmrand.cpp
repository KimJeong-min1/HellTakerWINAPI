#include "jmrand.h"
namespace jm
{
	RanDom::RanDom()
	{
		// 0���� RAND_MAX(32767) ������ ������ ���� �߻�
		// int n = rand(); 
		// ������ �� ���� �ٸ� �������� �߻���Ű�� ���� seed����
		srand((unsigned)time(0));
	}
	// 0���� RAND_MAX(32767) ������ ������ ������ �������ִ� �Լ�
	int RanDom::next()
	{
		return rand();
	}
	// x���� y������ ������ ������ �������ִ� �Լ�
	int RanDom::nextInRange(int x, int y)
	{
		return rand() % (y - x + 1) + x;
	}


	/*void Application::MoveFunc2(int _Rand1, int _Rand2, int _Max)
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
	}*/

	/*void Application::MoveFunc1(int _Rand1, int _Rand2, int _Max)
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
	}*/

	/*if (m_able == true)
	{
		Time::Render(mBackHdc);
		Ellipse(mBackHdc, -50.f + mPlayerPos2.x, -50.f + mPlayerPos2.y, 50.f + mPlayerPos2.x, 50.f + mPlayerPos2.y);
	}*/
}
