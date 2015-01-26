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
#include "PlayerMove.h"
#include "Collision.h"
#include "PlayerAttack.h"


CBattery::CBattery(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos + Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2 - CMapRead::Size / 2), Point(CMapRead::Size/* / CMiniMap::MapScale*/, CMapRead::Size/* / CMiniMap::MapScale*/), Point(0, 0)), State::Live),
anime(std::make_unique<CBatteryAnimation>(task)),
move(std::make_unique<CBatteryMove>(task)),
isCollision(false),
HP(10)
{
}

void CBattery::Start()
{
	//transform.TransformPoint(Point(transform.GetPos().x / CMiniMap::MapScale + CGameApplication::ScreenWidth / 2 - (CMapRead::Width * CMapRead::Size / CMiniMap::MapScale) / 2,
	//transform.GetPos().y / CMiniMap::MapScale + CGameApplication::ScreenHeight / 2 - (CMapRead::Height * CMapRead::Size / CMiniMap::MapScale) / 2 - (CMapRead::Size / CMiniMap::MapScale) * 7 / 2));

	anime->Start();
	move->Start();
}
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
void CBattery::Draw()
{
	//auto pos = (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->transform.GetPos());
	//auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	//auto pos = (transform.GetPos() - scroll + Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2 - CMapRead::Size / 2), transform.GetScale());

	//Rect(transform.GetPos(), transform.GetScale()).draw(ColorF(0, 255, 0));

	//isCollision = true;
	if (state != State::None)
	{
		move->Draw();
		anime->Draw();
		task->GetComponent<CBatteryAttack>(CEnemyManager::BatteryAttack, 0)->Draw();
	}
}