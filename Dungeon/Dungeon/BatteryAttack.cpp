#include "MapRead.h"
#include "Scroll.h"
#include "GameApplication.h"
#include "BatteryAttack.h"
#include "CharacterController.h"
#include "Battery.h"
#include "GameManager.h"
#include "EnemyManager.h"
#include "BatteryMove.h"

#include "Player.h"
#include "PlayerAttack.h"

CBatteryAttack::CBatteryAttack(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos + Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2 - CMapRead::Size / 2), Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), State::Live),
isCollision(false)
{

}
void CBatteryAttack::Create()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto Battery = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0));
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());

	if (/*player.x > Battery->transform.GetPos().x - Battery->transform.GetScale().x / 2 - pos.x - CMapRead::Size
		&&player.x < Battery->transform.GetPos().x + Battery->transform.GetScale().x / 2 - pos.x + CMapRead::Size
		&&player.y > Battery->transform.GetPos().y - Battery->transform.GetScale().y / 2 - pos.y - CMapRead::Size
		&&player.y < Battery->transform.GetPos().y + Battery->transform.GetScale().y / 2 - pos.y + CMapRead::Size
		&&*/task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isCollision
		&&  task->GetComponent<CBattery>(CEnemyManager::Battery, 0)->GetState() != State::None)
	{
		isCollision = true;
		return;
	}
	isCollision = false;

}
void CBatteryAttack::Left()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto Battery = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0));

	if (player.x < Battery->transform.GetPos().x - Battery->transform.GetScale().x / 2 - pos->transform.GetPos().x)
	{
		transform.TransformPoint(Point(Battery->transform.GetPos().x - Battery->transform.GetScale().x, Battery->transform.GetPos().y) - pos->transform.GetPos());
	}
}
void CBatteryAttack::Right()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto Battery = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0));

	if (player.x > Battery->transform.GetPos().x + Battery->transform.GetScale().x / 2 - pos->transform.GetPos().x)
	{
		transform.TransformPoint(Point(Battery->transform.GetPos().x + Battery->transform.GetScale().x, Battery->transform.GetPos().y) - pos->transform.GetPos());
	}
}
void CBatteryAttack::Up()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto Battery = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0));

	if (player.y < Battery->transform.GetPos().y - Battery->transform.GetScale().y / 2 - pos->transform.GetPos().y)
	{
		transform.TransformPoint(Point(Battery->transform.GetPos().x, Battery->transform.GetPos().y - Battery->transform.GetScale().y) - pos->transform.GetPos());
	}
}
void CBatteryAttack::Down()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto Battery = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0));

	if (player.y > Battery->transform.GetPos().y + Battery->transform.GetScale().y / 2 - pos->transform.GetPos().y)
	{
		transform.TransformPoint(Point(Battery->transform.GetPos().x, Battery->transform.GetPos().y + Battery->transform.GetScale().y) - pos->transform.GetPos());
	}
}
void CBatteryAttack::Update()
{
	Left();
	Right();
	Up();
	Down();

	Create();
}

void CBatteryAttack::Draw()
{

	//font(transform.GetPos()).draw();

	if (isCollision)
	{
		Rect(transform.GetPos(), transform.GetScale()).draw(ColorF(Palette::Red, 0.5));
	}
}