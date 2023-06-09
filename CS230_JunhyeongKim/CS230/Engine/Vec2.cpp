/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Vec2.cpp
Project:    GAM150
Author:     Junhyeong Kim
Created:    March 24, 2023
*/

#include "Vec2.h"

bool Math::vec2::operator== (const vec2& v)
{
	if (x == v.x && y == v.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Math::vec2::operator!= (const vec2& v)
{
	if (x == v.x && y == v.y)
	{
		return false;
	}
	else
	{
		return true;
	}
}

Math::vec2 Math::vec2::operator+(const vec2& v)
{
	return vec2(x + v.x, y + v.y);
}

Math::vec2& Math::vec2::operator+=(const vec2& v)
{
	x += v.x;
	y += v.y;
	return *this;
}

Math::vec2 Math::vec2::operator-(const vec2& v)
{
	return vec2(x - v.x, y - v.y);
}

Math::vec2& Math::vec2::operator-=(const vec2& v)
{
	x -= v.x;
	y -= v.y;
	return *this;

}




Math::vec2 Math::vec2::operator*(double scale)
{
	return vec2(x * scale, y * scale);
}

Math::vec2& Math::vec2::operator*=(double scale)
{
	x *= scale;
	y *= scale;
	return *this;

}

Math::vec2 Math::vec2::operator*(const vec2& v)
{
	return vec2(x * v.x, y * v.y);
}




Math::vec2 Math::vec2::operator/(double scale)
{
	return vec2(x / scale, y / scale);
}

Math::vec2& Math::vec2::operator/=(double scale)
{
	x /= scale;
	y /= scale;
	return *this;
}

Math::vec2 Math::operator*(double scale, const vec2& v)
{
	return vec2(scale * v.x, scale * v.y);
}




bool Math::ivec2::operator== (const ivec2& v)
{
	if (x == v.x && y == v.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Math::ivec2::operator!= (const ivec2& v)
{
	if (x == v.x && y == v.y)
	{
		return false;
	}
	else
	{
		return true;
	}
}

Math::ivec2 Math::ivec2::operator+(const ivec2& v)
{
	return ivec2(x + v.x, y + v.y);
}

Math::ivec2& Math::ivec2::operator+=(const ivec2& v)
{
	x += v.x;
	y += v.y;
	return *this;
}

Math::ivec2 Math::ivec2::operator-(const ivec2& v)
{
	return ivec2(x - v.x, y - v.y);
}

Math::ivec2& Math::ivec2::operator-=(const ivec2& v)
{
	x -= v.x;
	y -= v.y;
	return *this;

}

Math::ivec2 Math::ivec2::operator*(int scale)
{
	return ivec2(x * scale, y * scale);
}

Math::ivec2& Math::ivec2::operator*=(int scale)
{
	x *= scale;
	y *= scale;
	return *this;

}

Math::ivec2 Math::ivec2::operator/(int scale)
{
	return ivec2(x / scale, y / scale);
}

Math::ivec2& Math::ivec2::operator/=(int scale)
{
	x /= scale;
	y /= scale;
	return *this;
}

Math::vec2 Math::ivec2::operator*(double scale)
{
	return vec2(scale * static_cast<double>(x), scale * static_cast<double>(y));
}

Math::vec2 Math::ivec2::operator/(double divisor)
{
	return vec2(static_cast<double>(x)/divisor, static_cast<double>(y) / divisor);
}