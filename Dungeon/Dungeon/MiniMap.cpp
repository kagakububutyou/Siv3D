#include "MiniMap.h"
#include "MapRead.h"
#include "Player.h"
#include "GameManager.h"

CMiniMap::CMiniMap(std::shared_ptr<CTask> task, Float3 pos) :
CActor(task, Transform(pos - Float3(0, CMapRead::Size / 2, 0), Float3(CMapRead::Size / 10, CMapRead::Size / 10, 0), Float3(0, 0, 0)), State::Live)
{

}
void CMiniMap::Draw()
{
	auto player_pos = task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->transform.GetPos();


	Box(transform.GetPos(), transform.GetScale()+Float3(1,1,1)).draw(ColorF(0,0,255,0.25));
}