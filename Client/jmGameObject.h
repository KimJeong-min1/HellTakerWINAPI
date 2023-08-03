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
			// T* comp = nullptr �� �� ������ ���� ���� ������Ʈ�� ��Ƽ� �����ϱ� ���� ��������
			T* comp = nullptr;
			// ���� ã���� �ϴ� ������Ʈ�� ������ؼ� �ݺ����� ������
			// �������� �ݺ���
			// c �� mComponents �� �� �ִ� ������Ʈ���� �ϳ��� �ִ´�
			// mComponents�� ����ִ� �� ��ŭ  for���� �����Ų��
			for (Component* c : mComponents)
			{
				// comp�� T��*(�����ִ� Ŭ����Ÿ��)�� ����ȯ�� ��Ų������ �������Ѵ�
				comp = dynamic_cast<T*>(c);
				// �ش� ���� null�� �ƴ϶�� ����
				if (comp != nullptr)
					return comp;
			}
			// ������� �°Ŷ�� comp�� ��ã�� ��
			// comp == nullptr
			return comp;
		}

		template <typename T>
		T* AddComponent(const std::wstring& name)
		{
			// T���� ������ ������ �ϳ� ����� �����Ҵ��� ���ش�
			T* comp = new T();
			// mComponents�� comp�� ����
			// mComponents �� vector�� �̱⶧���� push_back�� �̿��Ͽ� ����
			mComponents.push_back(comp);
			// comp�� GameObject������ �־��ش�.
			comp->SetOwner(this);
			// comp�� name�� �־��ش�
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


