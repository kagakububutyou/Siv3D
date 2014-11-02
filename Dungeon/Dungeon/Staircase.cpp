#include "Staircase.h"
#include "MapRead.h"
#include "Player.h"
#include "GameManager.h"
#include "GameApplication.h"
#include "GameManager.h"
#include "Scroll.h"


CStaircase::CStaircase(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos + Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2) - Point(0, CMapRead::Size / 2), Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), State::Live)
{

}

void CStaircase::Draw()
{
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());

	Rect(transform.GetPos() - pos, transform.GetScale()).draw(Palette::Green);
}