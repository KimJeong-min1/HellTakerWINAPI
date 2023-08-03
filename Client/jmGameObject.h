#pragma once
#include "jmEntity.h"
#include "jmComponent.h"

namespace jm
{
	class GameObject : public Entity
	{
		friend class Scene;

	public:
		enum class eState
		{
			Active,
			Pause,
			Dead,
			End,
		};

		friend static __forceinline void Destroy(GameObject* gameObject);

		GameObject();
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);

		template <typename T>
		T* GetComponent()
		{
			// T* comp = nullptr 을 한 이유는 내가 얻어올 컴포넌트를 담아서 리턴하기 위한 변수선언
			T* comp = nullptr;
			// 내가 찾고자 하는 컴포넌트를 얻기위해서 반복문을 돌린다
			// 범위지정 반복문
			// c 에 mComponents 에 들어가 있는 컴포넌트들을 하나씩 넣는다
			// mComponents에 들어있는 수 만큼  for문을 실행시킨다
			for (Component* c : mComponents)
			{
				// comp에 T형*(내가넣는 클래스타입)로 형변환을 시킨다음에 대입을한다
				comp = dynamic_cast<T*>(c);
				// 해당 값이 null이 아니라면 리턴
				if (comp != nullptr)
					return comp;
			}
			// 여기까지 온거라면 comp는 못찾은 것
			// comp == nullptr
			return comp;
		}

		template <typename T>
		T* AddComponent(const std::wstring& name)
		{
			// T형의 포인터 변수를 하나 만들고 동적할당을 해준다
			T* comp = new T();
			// mComponents에 comp를 대입
			// mComponents 는 vector형 이기때문에 push_back을 이용하여 저장
			mComponents.push_back(comp);
			// comp에 GameObject형식을 넣어준다.
			comp->SetOwner(this);
			// comp에 name을 넣어준다
			comp->SetName(name);

			return comp;
		}

		virtual void OnCollisionEnter(class Collider* other);
		virtual void OnCollisionStay(class Collider* other);
		virtual void OnCollisionExit(class Collider* other);

		eState GetState() { return mState; }
		void Pause() { mState = eState::Pause; }
	private:
		void Death() { mState = eState::Dead; }
	private:
		std::vector<Component*> mComponents;
		eState mState;
		class Scene* mScene;
	public:
		void SetScene(class Scene* scene);
		class Scene* GetScene() const;
	};

	static __forceinline void Destroy(GameObject* gameObject)
	{
		gameObject->Death();
	}
}


