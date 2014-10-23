#include "Staircase.h"
#include "MapRead.h"
#include "Player.h"
#include "GameManager.h"


CStaircase::CStaircase(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos - Point(0, CMapRead::Size / 2), Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), State::Live)
{

}

void CStaircase::Draw()
{
	Rect(transform.GetPos(), transform.GetScale()).draw(Palette::Green);
}