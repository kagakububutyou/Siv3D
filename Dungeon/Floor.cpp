#include "Floor.h"
#include "MapRead.h"
#include "GameManager.h"
#include "GameApplication.h"
#include "Player.h"
#include "PlayerMove.h"
#include "Scroll.h"


CFloor::CFloor(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos - Point(0, CMapRead::Size / 2), Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), State::Live)
{

}
void CFloor::Update()
{

}
void CFloor::Draw()
{
	auto player_pos = task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos();

	Rect(transform.GetPos() - player_pos + Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2), transform.GetScale()).draw(Palette::Red);
}