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
}
