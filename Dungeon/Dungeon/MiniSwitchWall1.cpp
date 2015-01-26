#include "MiniMap.h"
#include "MiniSwitchWall1.h"
#include "MapRead.h"
#include "Player.h"
#include "GameManager.h"
#include "CharacterController.h"
#include "PlayerAttack.h"

CMiniSwitchWall1::CMiniSwitchWall1(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos - Point(0, CMapRead::Size / 2), Point(CMapRead::Size / CMiniMap::MapScale, CMapRead::Size / CMiniMap::MapScale), Point(0, 0)), State::Live)
{

}
void CMiniSwitchWall1::Start()
{
	DisplayMiniSwitchWall1 = false;
}
void CMiniSwitchWall1::JudgmentDisplayMiniSwitchWall1()
{
	if (CharacterController::DisplayMiniMapKey() && task->GetComponent<CMiniMap>("mini_map", 0)->DisplayMiniMap == false
		&& task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemys[CPlayerAttack::EnemyName::SnakeCopter] == true)
	{
		DisplayMiniSwitchWall1 = false;
		return;
	}
	if (CharacterController::DisplayMiniMapKey() && task->GetComponent<CMiniMap>("mini_map", 0)->DisplayMiniMap == true
		&& task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemys[CPlayerAttack::EnemyName::SnakeCopter] == true)
	{
		DisplayMiniSwitchWall1 = true;
		return;
	}
}
void CMiniSwitchWall1::Update()
{
	JudgmentDisplayMiniSwitchWall1();
}
void CMiniSwitchWall1::Draw()
{
	if (DisplayMiniSwitchWall1)
	{
		Rect(transform.GetPos(), transform.GetScale()).draw(ColorF(0, 0, 255, 0.5));
	}
}