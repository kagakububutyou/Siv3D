#include "Staircase.h"
#include "MapRead.h"
#include "Player.h"
#include "GameManager.h"


CStaircase::CStaircase(std::shared_ptr<CTask> task, Float3 pos) :
CActor(task, Transform(pos - Float3(0, CMapRead::Size / 2, 0), Float3(CMapRead::Size, CMapRead::Size, 0), Float3(0, 0, 0)), State::Live)
{

}

void CStaircase::Draw()
{
	Box(transform.GetPos(), transform.GetScale()).draw(Palette::Green);
}