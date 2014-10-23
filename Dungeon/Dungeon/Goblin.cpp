#include "Goblin.h"

CGoblin::CGoblin(std::shared_ptr<CTask> task) :
CActor(task, Transform(Float3(1600, 656, 0), Float3(32, 32, 0), Float3(0, 0, 0)), State::Live)
{
}

void CGoblin::Start()
{

}

void CGoblin::Update()
{

}

void CGoblin::Draw()
{
	Box(transform.GetPos(), transform.GetScale()).draw(Palette::Blue);
}