#include "Enemy.h"


CEnemy::CEnemy(std::shared_ptr<CTask> task):
CActor(task, Transform(Float3(100,100, 0), Float3(32,32,0),Float3(0,0,0)),State::Live)
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
	Box(transform.GetPos(), transform.GetScale()).draw(Palette::Red);
}