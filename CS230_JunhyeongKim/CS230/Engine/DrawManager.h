#pragma once
#include "Vec2.h"
#include "Matrix.h"
#include "Texture.h"
#include "Rect.h"

namespace CS230
{
	class DrawManager
	{
	public:
		void Update(const Math::ivec2& windowSize);
		Math::TransformationMatrix GetMatrix(CS230::Texture* texture, const Math::vec2& pos, const Math::vec2& size);
		bool RectCollision(const Math::vec2& pos, const Math::vec2& size, const Math::vec2& mouse);
		bool CircleCollision(const Math::vec2& pos, const Math::vec2& size, const Math::vec2& mouse);
		Math::vec2 Vec(const Math::vec2& vec);

	private:
		Math::vec2 unit;
		Math::vec2 windowRate{ 1400.0, 800.0 };
	};
}