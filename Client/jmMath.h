#pragma once

namespace jm::math
{
	struct Vector2
	{
		static Vector2 zero;
		static Vector2 one;
		static Vector2 right;
		static Vector2 up;
		
		float x;
		float y;

		Vector2()
			: x(0.0f)
			, y(0.0f)
		{

		}
		Vector2(float _x, float _y)
			: x(_x)
			, y(_y)
		{

		}

		Vector2 operator/(const float value)
		{
			Vector2 temp;
			temp.x = x / value;
			temp.y = y / value;
			return temp;
		}

		Vector2 operator-(const Vector2 other)
		{
			Vector2 temp;
			temp.x = x - other.x;
			temp.y = y - other.y;
			return temp;
		}
	};

	
}