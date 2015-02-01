#include "Battery.h"
#include "BatteryAnimation.h"
#include "BatteryMove.h"
#include "BatteryAttack.h"
#include "MapRead.h"
#include "MiniMap.h"
#include "Scroll.h"
#include "GameManager.h"
#include "GameApplication.h"
#include "EnemyManager.h"

#include "Player.h"
#include "Collision.h"
#include "PlayerAttack.h"


CBattery::CBattery(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos + Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2 - CMapRead::Size / 2), Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), State::Live),
anime(std::make_unique<CBatteryAnimation>(task)),
move(std::make_unique<CBatteryMove>(task)),
isCollision(false),
HP(10)
{
}
///	初めに呼ぶ関数　初期化系
void CBattery::Start()
{
	anime->Start();
	move->Start();
	task->GetComponent<CBatteryAttack>(CEnemyManager::BatteryAttack, 0)->Start();
}
///	当たり判定だとおもう　なんでここでやってんだ？
void CBattery::OnCollision()
{
	auto atk = task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	auto Battery = task->GetComponent<CBattery>(CEnemyManager::Battery, 0);

	if (Collision::RectToRect(Battery->transform.GetPos() - pos, Battery->transform.GetScale(), atk->transform.GetPos(), atk->transform.GetScale())
		&& atk->isCollision)
	{
		Battery->HitAttack();
	}
	if (Battery->GetHP() <= 0)
	{
		state = State::None;
	}
	if (state == State::None)
	{
		atk->isEnemys[CPlayerAttack::EnemyName::Battery] = true;
	}
}
///	毎フレーム呼ぶ関数　更新が必要な関数
void CBattery::Update()
{
	if (state != State::None)
	{
		anime->Update();
		move->Update();
		task->GetComponent<CBatteryAttack>(CEnemyManager::BatteryAttack, 0)->Update();
	}

	OnCollision();
}
///	描画関係の関数　描画したい奴はここへ
void CBattery::Draw()
{
	if (state != State::None)
	{
		move->Draw();
		anime->Draw();
		task->GetComponent<CBatteryAttack>(CEnemyManager::BatteryAttack, 0)->Draw();
	}
}