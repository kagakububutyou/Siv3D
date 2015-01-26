#include "MiniMap.h"
#include "MiniSwitchWall3.h"
#include "MapRead.h"
#include "Player.h"
#include "GameManager.h"
#include "CharacterController.h"
#include "PlayerAttack.h"

CMiniSwitchWall3::CMiniSwitchWall3(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos - Point(0, CMapRead::Size / 2), Point(CMapRead::Size / CMiniMap::MapScale, CMapRead::Size / CMiniMap::MapScale), Point(0, 0)), State::Live)
{

}
void CMiniSwitchWall3::Start()
{
	DisplayMiniSwitchWall3 = false;
}
void CMiniSwitchWall3::JudgmentDisplayMiniSwitchWall3()
{
	if (CharacterController::DisplayMiniMapKey() && task->GetComponent<CMiniMap>("mini_map", 0)->DisplayMiniMap == false
		&& task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemys[CPlayerAttack::EnemyName::Battery] == true)
	{
		DisplayMiniSwitchWall3 = false;
		return;
	}
	if (CharacterController::DisplayMiniMapKey() && task->GetComponent<CMiniMap>("mini_map", 0)->DisplayMiniMap == true
		&& task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemys[CPlayerAttack::EnemyName::Battery] == true)
	{
		DisplayMiniSwitchWall3 = true;
		return;
	}
}
void CMiniSwitchWall3::Update()
{
	JudgmentDisplayMiniSwitchWall3();
}
void CMiniSwitchWall3::Draw()
{
	if (DisplayMiniSwitchWall3)
	{
		Rect(transform.GetPos(), transform.GetScale()).draw(ColorF(0, 0, 255, 0.5));
	}
}