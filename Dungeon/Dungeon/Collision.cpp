// ------------------------------------------------
//			‚ ‚½‚è”»’è
//					code by shinnnosuke hiratsuka
// ------------------------------------------------
#include "Collision.h"

namespace Collision
{
	bool IsCollisionBox(const Float3 &Pos1, const Float3 &Size1, const  Float3 &Pos2, const Float3 &Size2)
	{
		if (Abs(Pos1.x - Pos2.x) > ((Size1.x / 2 - 1) + (Size2.x / 2) - 1))return false;
		if (Abs(Pos1.y - Pos2.y) > ((Size1.y / 2 - 1) + (Size2.y / 2) - 1))return false;
		if (Abs(Pos1.z - Pos2.z) > ((Size1.z / 2 - 1) + (Size2.z / 2) - 1))return false;

		return true;
	}
}