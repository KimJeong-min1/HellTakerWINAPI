#include "jmGameObject.h"
#include "jmTransform.h"
#include "jmSpriteRenderer.h"
#include "jmScene.h"

namespace jm
{
	GameObject::GameObject()
		: mState(eState::Active)
	{
		AddComponent<Transform>(L"TransformComponent");
	}

	GameObject::~GameObject()
	{
		for (Component* comp : mComponents)
		{
			if (nullptr != comp)
			{
				delete comp;
				comp = nullptr;
			}
		}

		mComponents.clear();
	}

	void GameObject::Initialize()
	{
	}

	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			comp->Update();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : mComponents)
		{
			comp->Render(hdc);
		}
	}

	void GameObject::OnCollisionEnter(Collider* other)
	{
	}

	void GameObject::OnCollisionStay(Collider* other)
	{
	}

	void GameObject::OnCollisionExit(Collider* other)
	{
	}

	void GameObject::SetScene(Scene* scene)
	{
		mScene = scene;
	}

	Scene* GameObject::GetScene() const
	{
		return mScene;
	}

}