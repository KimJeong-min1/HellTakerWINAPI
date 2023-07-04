// 그냥 enum문은 다른 enum문을 만들었을때 이름이 겹치면 중복처리가 돼서 실행이 안된다
// class로 만든다면 하나의 클래스로 인식이 된다
// 풀네임은 eKeystate::Down 이런 식이다.
/*enum eKeyState
{
	Down,
	Up,
	Pressedm,
	None,
};

enum eKeyState2
{
	Down,
	Up,
	Pressedm,
	None,
};*/
#pragma once
#include "Commoninclude.h"
namespace jm
{
	// enum 은 숫자를 글자로 바꾼다 (간단하게 설명)
	// 키보드안에 키배열
	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		End
	};
	// 키의 상태
	enum class eKeyState
	{
		Down,
		Up,
		Pressed,
		None,
	};


	class Input
	{
	public:
		struct Key
		{
			eKeyCode code;
			eKeyState state;
			bool bPressed;
		};

		static void Initialize();
		static void Update();
		// inline 은 최적화 옵션이다.
		// 함수실행 하면서 함수안에 들어가서 소스코드를 실행 시키고 나오는 것도 시간이다
		// 그래서 inline을 붙히면 해당 함수 안의 리턴값을 그냥 함수안에 들어가지않고 실행을 시킨다
		// 무조건 inline을 앞에 붙힌다고해서 실행이 되는 것은 아니고 visual이 알아서 컴파일을 하면서
		// 작동이 된다.
		// 무조건 최적화를 해야한다
		// __forceinline을 쓰면 강제로 최적화를 한다
		__forceinline static bool GetKeyDown(eKeyCode code) { return mKeys[(int)code].state == eKeyState::Down; }
		__forceinline static bool GetKeyUp(eKeyCode code) { return mKeys[(int)code].state == eKeyState::Up; }
		__forceinline static bool GetKey(eKeyCode code) { return mKeys[(int)code].state == eKeyState::Pressed; }

	private:
		// static 전역변수 처럼 동작은 하되 클래스내부에 작동하게하고 싶은 전역변수
		// 전역변수같은 경우에는 어떤경우에든 쓸수있지만
		// 클래스 내부의 static 변수는 클래스 내부의 접근제한지정자를 쓸수 있냐 없냐의 차이
		static std::vector<Key> mKeys;
	};

}
