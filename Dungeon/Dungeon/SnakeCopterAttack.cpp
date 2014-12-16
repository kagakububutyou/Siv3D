#include "MapRead.h"
#include "Scroll.h"
#include "GameApplication.h"
#include "SnakeCopterAttack.h"
#include "CharacterController.h"
#include "SnakeCopter.h"
#include "GameManager.h"
#include "EnemyManager.h"
#include "SnakeCopterMove.h"

#include "Player.h"
#include "PlayerAttack.h"

CSnakeCopterAttack::CSnakeCopterAttack(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos + Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2 - CMapRead::Size / 2), Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), State::Live),
isCollision(false)
{

}
void CSnakeCopterAttack::Create()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto SnakeCopter = (task->GetComponent<CSnakeCopter>(CEnemyManager::SnakeCopter, 0));
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());

	if (/*player.x > SnakeCopter->transform.GetPos().x - SnakeCopter->transform.GetScale().x / 2 - pos.x - CMapRead::Size
		&&player.x < SnakeCopter->transform.GetPos().x + SnakeCopter->transform.GetScale().x / 2 - pos.x + CMapRead::Size
		&&player.y > SnakeCopter->transform.GetPos().y - SnakeCopter->transform.GetScale().y / 2 - pos.y - CMapRead::Size
		&&player.y < SnakeCopter->transform.GetPos().y + SnakeCopter->transform.GetScale().y / 2 - pos.y + CMapRead::Size
		&&*/task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isCollision
		&& task->GetComponent<CSnakeCopter>(CEnemyManager::SnakeCopter,0)->GetState() != State::None)
	{
		isCollision = true;
		return;
	}
	isCollision = false;

}
void CSnakeCopterAttack::Left()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter = (task->GetComponent<CSnakeCopter>(CEnemyManager::SnakeCopter, 0));

	if (player.x < SnakeCopter->transform.GetPos().x - SnakeCopter->transform.GetScale().x / 2 - pos->transform.GetPos().x)
	{
		transform.TransformPoint(Point(SnakeCopter->transform.GetPos().x - SnakeCopter->transform.GetScale().x, SnakeCopter->transform.GetPos().y) - pos->transform.GetPos());
	}
}
void CSnakeCopterAttack::Right()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter = (task->GetComponent<CSnakeCopter>(CEnemyManager::SnakeCopter, 0));

	if (player.x > SnakeCopter->transform.GetPos().x + SnakeCopter->transform.GetScale().x / 2 - pos->transform.GetPos().x)
	{
		transform.TransformPoint(Point(SnakeCopter->transform.GetPos().x + SnakeCopter->transform.GetScale().x, SnakeCopter->transform.GetPos().y) - pos->transform.GetPos());
	}
}
void CSnakeCopterAttack::Up()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter = (task->GetComponent<CSnakeCopter>(CEnemyManager::SnakeCopter, 0));

	if (player.y < SnakeCopter->transform.GetPos().y - SnakeCopter->transform.GetScale().y / 2 - pos->transform.GetPos().y)
	{
		transform.TransformPoint(Point(SnakeCopter->transform.GetPos().x, SnakeCopter->transform.GetPos().y - SnakeCopter->transform.GetScale().y) - pos->transform.GetPos());
	}
}
void CSnakeCopterAttack::Down()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter = (task->GetComponent<CSnakeCopter>(CEnemyManager::SnakeCopter, 0));

	if (player.y > SnakeCopter->transform.GetPos().y + SnakeCopter->transform.GetScale().y / 2 - pos->transform.GetPos().y)
	{
		transform.TransformPoint(Point(SnakeCopter->transform.GetPos().x, SnakeCopter->transform.GetPos().y + SnakeCopter->transform.GetScale().y) - pos->transform.GetPos());
	}
}
void CSnakeCopterAttack::Update()
{
	Left();
	Right();
	Up();
	Down();

	Create();
}

void CSnakeCopterAttack::Draw()
{

	//font(transform.GetPos()).draw();

	if (isCollision)
	{
		//Rect(transform.GetPos(), transform.GetScale()).draw(ColorF(Palette::Red, 0.5));
	}
}