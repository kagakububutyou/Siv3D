#pragma once
#include <Siv3D.hpp>

class Collision
{
public:
	static bool IsCollisionBox(Float3 Pos1, Float3 Size1, Float3 Pos2, Float3 Size2);
};

