#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
namespace jm
{
	class RanDom
	{
	public:
		RanDom();
		int next();
		int nextInRange(int x, int y);
	};
}

