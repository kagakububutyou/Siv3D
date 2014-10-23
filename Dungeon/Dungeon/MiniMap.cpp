#include "MiniMap.h"
#include "MapRead.h"
#include "Player.h"
#include "GameManager.h"

CMiniMap::CMiniMap(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos - Point(0, CMapRead::Size / 2), Point(CMapRead::Size / CMiniMap::MapScale, CMapRead::Size / CMiniMap::MapScale), Point(0, 0)), State::Live)
{

}
void CMiniMap::Draw()
{
	auto player_pos = task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->transform.GetPos();


	Rect(transform.GetPos(), transform.GetScale()).draw(ColorF(0, 0, 255, 0.5));
}