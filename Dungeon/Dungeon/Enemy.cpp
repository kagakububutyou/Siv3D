#include "Enemy.h"


CEnemy::CEnemy(std::shared_ptr<CTask> task, Float3 pos):
CActor(task, Transform(pos, Float3(100,100,100),Float3(0,0,0)),State::Live)
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

}