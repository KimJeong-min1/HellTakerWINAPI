// �׳� enum���� �ٸ� enum���� ��������� �̸��� ��ġ�� �ߺ�ó���� �ż� ������ �ȵȴ�
// class�� ����ٸ� �ϳ��� Ŭ������ �ν��� �ȴ�
// Ǯ������ eKeystate::Down �̷� ���̴�.
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
	// enum �� ���ڸ� ���ڷ� �ٲ۴� (�����ϰ� ����)
	// Ű����ȿ� Ű�迭
	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		End
	};
	// Ű�� ����
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
		// inline �� ����ȭ �ɼ��̴�.
		// �Լ����� �ϸ鼭 �Լ��ȿ� ���� �ҽ��ڵ带 ���� ��Ű�� ������ �͵� �ð��̴�
		// �׷��� inline�� ������ �ش� �Լ� ���� ���ϰ��� �׳� �Լ��ȿ� �����ʰ� ������ ��Ų��
		// ������ inline�� �տ� �����ٰ��ؼ� ������ �Ǵ� ���� �ƴϰ� visual�� �˾Ƽ� �������� �ϸ鼭
		// �۵��� �ȴ�.
		// ������ ����ȭ�� �ؾ��Ѵ�
		// __forceinline�� ���� ������ ����ȭ�� �Ѵ�
		__forceinline static bool GetKeyDown(eKeyCode code) { return mKeys[(int)code].state == eKeyState::Down; }
		__forceinline static bool GetKeyUp(eKeyCode code) { return mKeys[(int)code].state == eKeyState::Up; }
		__forceinline static bool GetKey(eKeyCode code) { return mKeys[(int)code].state == eKeyState::Pressed; }

	private:
		// static �������� ó�� ������ �ϵ� Ŭ�������ο� �۵��ϰ��ϰ� ���� ��������
		// ������������ ��쿡�� ���쿡�� ����������
		// Ŭ���� ������ static ������ Ŭ���� ������ �������������ڸ� ���� �ֳ� ������ ����
		static std::vector<Key> mKeys;
	};

}
