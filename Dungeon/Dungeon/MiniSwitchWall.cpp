#include "MiniMap.h"
#include "MiniSwitchWall.h"
#include "MapRead.h"
#include "Player.h"
#include "GameManager.h"
#include "CharacterController.h"
#include "PlayerAttack.h"

CMiniSwitchWall::CMiniSwitchWall(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos - Point(0, CMapRead::Size / 2), Point(CMapRead::Size / CMiniMap::MapScale, CMapRead::Size / CMiniMap::MapScale), Point(0, 0)), State::Live)
{

}
void CMiniSwitchWall::Start()
{
	DisplayMiniSwitchWall = false;
}
void CMiniSwitchWall::JudgmentDisplayMiniSwitchWall()
{
	if (CharacterController::DisplayMiniMapKey() && task->GetComponent<CMiniMap>("mini_map", 0)->DisplayMiniMap == false
		&& task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemy1 == true)
	{
		DisplayMiniSwitchWall = false;
		return;
	}
	if (CharacterController::DisplayMiniMapKey() && task->GetComponent<CMiniMap>("mini_map",0)->DisplayMiniMap == true
		&& task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemy1 == true)
	{
		DisplayMiniSwitchWall = true;
		return;
	}
}
void CMiniSwitchWall::Update()
{
	JudgmentDisplayMiniSwitchWall();
}
void CMiniSwitchWall::Draw()
{
	if (DisplayMiniSwitchWall)
	{
		Rect(transform.GetPos(), transform.GetScale()).draw(ColorF(0, 0, 255, 0.5));
	}
}