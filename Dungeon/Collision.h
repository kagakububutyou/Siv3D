/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include <Siv3D.hpp>

namespace Collision
{
	// Rect And Rect Collision
	bool RectToRect(const Point &pos, const Point &size, const Point &col_pos, const Point &col_size);
}