#pragma once
#include "Commoninclude.h"

namespace jm
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring& name) { mName = name; }
		std::wstring& Getname() { return mName; }

	private:
		std::wstring mName;
	};
}

