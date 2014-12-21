#include "MiniMap.h"
#include "MiniSwitchWall2.h"
#include "MapRead.h"
#include "Player.h"
#include "GameManager.h"
#include "CharacterController.h"
#include "PlayerAttack.h"

CMiniSwitchWall2::CMiniSwitchWall2(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos - Point(0, CMapRead::Size / 2), Point(CMapRead::Size / CMiniMap::MapScale, CMapRead::Size / CMiniMap::MapScale), Point(0, 0)), State::Live)
{

}
void CMiniSwitchWall2::Start()
{
	DisplayMiniSwitchWall2 = false;
}
void CMiniSwitchWall2::JudgmentDisplayMiniSwitchWall2()
{
	if (CharacterController::DisplayMiniMapKey() && task->GetComponent<CMiniMap>("mini_map", 0)->DisplayMiniMap == false
		&& task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemy3 == true)
	{
		DisplayMiniSwitchWall2 = false;
		return;
	}
	if (CharacterController::DisplayMiniMapKey() && task->GetComponent<CMiniMap>("mini_map", 0)->DisplayMiniMap == true
		&& task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemy3 == true)
	{
		DisplayMiniSwitchWall2 = true;
		return;
	}
}
void CMiniSwitchWall2::Update()
{
	JudgmentDisplayMiniSwitchWall2();
}
void CMiniSwitchWall2::Draw()
{
	if (DisplayMiniSwitchWall2)
	{
		Rect(transform.GetPos(), transform.GetScale()).draw(ColorF(0, 0, 255, 0.5));
	}
}