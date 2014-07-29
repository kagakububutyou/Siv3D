#include "Enemy.h"


CEnemy::CEnemy()
{
	Pos = Float3(-136, 348, 0);

	Velocity = Float3(0, 0, 0);

	Size = Float3(64, 64, 16);

	color = Color(171, 91, 0);
}
void CEnemy::Update()
{

}
void CEnemy::Draw()
{
	Box(Pos, Size).draw(color);

}
