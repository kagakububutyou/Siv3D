#include "Goblin.h"

CGoblin::CGoblin(std::shared_ptr<CTask> task) :
CActor(task, Transform(Point(1600, 656), Point(32, 32), Point(0, 0)), State::Live)
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
	Rect(transform.GetPos(), transform.GetScale()).draw(Palette::Blue);
}