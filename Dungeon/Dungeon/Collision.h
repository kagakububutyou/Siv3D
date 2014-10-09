/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include <Siv3D.hpp>

namespace Collision
{
	bool IsCollisionBox(const Float3 &Pos1, const Float3 &Size1,const  Float3 &Pos2, const Float3 &Size2);
}