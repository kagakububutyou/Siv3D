#include "MapRead.h"
#include "Scroll.h"
#include "GameApplication.h"
#include "PatrollerAttack.h"
#include "CharacterController.h"
#include "Patroller.h"
#include "GameManager.h"
#include "EnemyManager.h"
#include "PatrollerMove.h"

#include "Player.h"
#include "PlayerAttack.h"

CPatrollerAttack::CPatrollerAttack(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos + Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2 - CMapRead::Size / 2), Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), State::Live),
isCollision(false)
{

}
void CPatrollerAttack::Create()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto Patroller = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0));
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());

	if (/*player.x > Patroller->transform.GetPos().x - Patroller->transform.GetScale().x / 2 - pos.x - CMapRead::Size
	&&player.x < Patroller->transform.GetPos().x + Patroller->transform.GetScale().x / 2 - pos.x + CMapRead::Size
	&&player.y > Patroller->transform.GetPos().y - Patroller->transform.GetScale().y / 2 - pos.y - CMapRead::Size
	&&player.y < Patroller->transform.GetPos().y + Patroller->transform.GetScale().y / 2 - pos.y + CMapRead::Size
	&&*/task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isCollision)
	{
		isCollision = true;
		return;
	}
	isCollision = false;
	
}
void CPatrollerAttack::Left()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto Patroller = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0));
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());

	if (player.x < Patroller->transform.GetPos().x - Patroller->transform.GetScale().x / 2 - pos.x - CMapRead::Size)
	{
		transform.TransformPoint(Point(Patroller->transform.GetPos().x - Patroller->transform.GetScale().x, Patroller->transform.GetPos().y) - pos);
	}
}
void CPatrollerAttack::Right()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto Patroller = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0));
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());

	if (player.x > Patroller->transform.GetPos().x + Patroller->transform.GetScale().x / 2 - pos.x + CMapRead::Size)
	{
		transform.TransformPoint(Point(Patroller->transform.GetPos().x + Patroller->transform.GetScale().x, Patroller->transform.GetPos().y) - pos);
	}
}
void CPatrollerAttack::Up()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto Patroller = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0));
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());

	if (player.y < Patroller->transform.GetPos().y - Patroller->transform.GetScale().y / 2 - pos.y - CMapRead::Size)
	{
		transform.TransformPoint(Point(Patroller->transform.GetPos().x, Patroller->transform.GetPos().y - Patroller->transform.GetScale().y) - pos);
	}
}
void CPatrollerAttack::Down()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto Patroller = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0));
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());

	if (player.y > Patroller->transform.GetPos().y + Patroller->transform.GetScale().y / 2 - pos.y + CMapRead::Size)
	{
		transform.TransformPoint(Point(Patroller->transform.GetPos().x, Patroller->transform.GetPos().y + Patroller->transform.GetScale().y) - pos);
	}
}
void CPatrollerAttack::Update()
{
	Left();
	Right();
	Up();
	Down();

	Create();
}

void CPatrollerAttack::Draw()
{

	//font(transform.GetPos()).draw();

	if (isCollision)
	{
		Rect(transform.GetPos(), transform.GetScale()).draw(ColorF(Palette::Blue,0.5));
	}
}