#include "jmCollisionManager.h"
#include "jmScene.h"
#include "jmSceneManager.h"

namespace jm
{
	std::map<UINT64, bool> CollisionManager::mCollisionMap = {};
	std::bitset<LAYER_MAX> CollisionManager::mLayerMasks[LAYER_MAX] = {};


	void CollisionManager::Initialize()
	{
	}
	void CollisionManager::Update()
	{
		Scene* activeScene = SceneManager::GetActiveScene();
		for (size_t row = 0; row < LAYER_MAX; row++)
		{
			for (size_t col = 0; col < LAYER_MAX; col++)
			{
				if (mLayerMasks[row][col] == true)
				{
					LayerCollision(activeScene, (eLayerType)row, (eLayerType)col);
				}
			}
		}
	}
	void CollisionManager::Render(HDC hdc)
	{
	}
	void CollisionManager::Release()
	{
	}
	void CollisionManager::Clear()
	{
		mLayerMasks->reset();
		mCollisionMap.clear();
	}
	void CollisionManager::CollisionLayerCheck(eLayerType left, eLayerType right, bool enable)
	{
		int row = -1;
		int col = -1;

		if (left > right)
		{
			row = (UINT)left;
			col = (UINT)right;
		}
		else
		{
			col = (UINT)left;
			row = (UINT)right;
		}

		mLayerMasks[row][col] = enable;
	}
	
	void CollisionManager::LayerCollision(Scene* scene, eLayerType left, eLayerType right)
	{
		// fidns left layer objects
		Layer& leftLayer = scene->GetLayer(left);
		std::vector<GameObject*>& lefts = leftLayer.GetGameObjects();

		// fidns right layer objects
		Layer& rightLayer = scene->GetLayer(right);
		std::vector<GameObject*>& rights = rightLayer.GetGameObjects();

		for (GameObject* left : lefts)
		{
			Collider* leftcol = left->GetComponent<Collider>();
			if (leftcol == nullptr)
				continue;

			for (GameObject* right : rights)
			{
				Collider* rightcol = right->GetComponent<Collider>();
				if (rightcol == nullptr)
					continue;
				if (left == right)
					continue;

				ColliderCollision(leftcol, rightcol);
			}
		}
	}
	void CollisionManager::ColliderCollision(Collider* left, Collider* right)
	{
		// 두 충돌체의 ID를 확인
		ColliderID ID;
		ID.left = (UINT)left->GetCollisionNumber();
		ID.right = (UINT)right->GetCollisionNumber();

		// 이전 충돌체의 정보를 가져와서 확인한다.
		std::map<UINT64, bool>::iterator iter = mCollisionMap.find(ID.id);

		// 만약 충돌정보가 없다면 생성해주면 된다.
		if (iter == mCollisionMap.end())
		{
			mCollisionMap.insert(std::make_pair(ID.id, false));
			iter = mCollisionMap.find(ID.id);
		}

		// 충돌함수 호출
		if (Intersect(left, right))
		{
			// 처음 충돌인 상태
			if (iter->second == false)
			{
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);

				iter->second = true;
			}
			else // 충돌중 인 상태
			{
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}
		}
		else
		{
			if (iter->second == true)
			{
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);

				iter->second = false;
			}
		}
	}
	bool CollisionManager::Intersect(Collider* left, Collider* right)
	{
		Vector2 leftPos = left->GetPosition();
		Vector2 rightPos = right->GetPosition();

		Vector2 leftSize = left->GetSize();
		Vector2 rightSize = right->GetSize();

		if (fabs(leftPos.x - rightPos.x) < fabs(leftSize.x / 2.0f + rightSize.x / 2.0f)
			&& fabs(leftPos.y - rightPos.y) < fabs(leftSize.y / 2.0f + rightSize.y / 2.0f))
		{
			return true;
		}


		return false;
	}
}