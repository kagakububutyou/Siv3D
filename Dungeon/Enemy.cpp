#include "Enemy.h"


CEnemy::CEnemy(std::shared_ptr<CTask> task):
CActor(task, Transform(Point(1600,656), Point(32,32),Point(0,0)),State::Live)
{
}

void CEnemy::Start()
{

}

void CEnemy::Update()
{

}

void CEnemy::Draw()
{
	Rect(transform.GetPos(), transform.GetScale()).draw(Palette::Blue);
}