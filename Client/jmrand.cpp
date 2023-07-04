#include "jmrand.h"
namespace jm
{
	RanDom::RanDom()
	{
		// 0에서 RAND_MAX(32767) 사이의 랜덤한 정수 발생
		// int n = rand(); 
		// 시작할 때 마다 다른 랜덤수를 발생시키기 위한 seed설정
		srand((unsigned)time(0));
	}
	// 0에서 RAND_MAX(32767) 사이의 랜덤한 정수를 리턴해주는 함수
	int RanDom::next()
	{
		return rand();
	}
	// x에서 y사이의 랜덤한 정수를 리턴해주는 함수
	int RanDom::nextInRange(int x, int y)
	{
		return rand() % (y - x + 1) + x;
	}
}
