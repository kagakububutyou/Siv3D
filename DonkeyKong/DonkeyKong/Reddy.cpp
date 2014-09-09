#include "Reddy.h"
#include "Stage.h"
#include "Collision.h"

CReddy::CReddy()
{
	Pos = Float3(0,376,0);
	Size = Float3(16, 24, 16);

	color = Palette::Pink;
}
void CReddy::Collision()
{
	if (Collision::IsCollisionBox(Pos, Size, stage->player->Pos, stage->player->Size))
	{
		stage->GameClear();
	}

}
void CReddy::Update()
{
	Collision();
}
void CReddy::Draw()
{
	Box(Pos, Size).draw(color);
}