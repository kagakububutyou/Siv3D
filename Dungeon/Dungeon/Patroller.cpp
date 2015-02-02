#include "Patroller.h"
#include "PatrollerAnimation.h"
#include "PatrollerMove.h"
#include "PatrollerAttack.h"
#include "MapRead.h"
#include "MiniMap.h"
#include "Scroll.h"
#include "GameManager.h"
#include "EnemyManager.h"

#include "Player.h"
#include "PlayerMove.h"
#include "Collision.h"
#include "PlayerAttack.h"


CPatroller::CPatroller(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos, Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), State::Live),
anime(std::make_unique<CPatrollerAnimation>(task)),
move(std::make_unique<CPatrollerMove>(task)),
isCollision(false),
HP(4)
{
}
///	初期化
void CPatroller::Start()
{
	anime->Start();
	move->Start();
	task->GetComponent<CPatrollerAttack>(CEnemyManager::PatrollerAttack, 0)->Start();
}
void CPatroller::OnCollision()
{
	auto atk = task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	auto patroller = task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0);

	if (Collision::RectToRect(patroller->transform.GetPos() - pos, patroller->transform.GetScale(), atk->transform.GetPos(), atk->transform.GetScale())
		&& atk->isCollision)
	{
		patroller->HitAttack();
	}
	if (patroller->GetHP() <= 0)
	{
		state = State::None;
	}
	if (state == State::None)
	{
		atk->isEnemys[CPlayerAttack::EnemyName::Patroller] = true;
	}
}
///	更新
void CPatroller::Update()
{
	if (state != State::None)
	{
		anime->Update();
		move->Update();
		OnCollision();
		task->GetComponent<CPatrollerAttack>(CEnemyManager::PatrollerAttack,0)->Update();
	}

	
}
void CPatroller::Draw()
{
	if (state != State::None)
	{
		move->Draw();
		anime->Draw();
		task->GetComponent<CPatrollerAttack>(CEnemyManager::PatrollerAttack, 0)->Draw();
	}
}