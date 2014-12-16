#include "MapRead.h"
#include "Scroll.h"
#include "GameApplication.h"
#include "SnakeCopter1Attack.h"
#include "CharacterController.h"
#include "SnakeCopter1.h"
#include "GameManager.h"
#include "EnemyManager.h"
#include "SnakeCopter1Move.h"

#include "Player.h"
#include "PlayerAttack.h"

CSnakeCopter1Attack::CSnakeCopter1Attack(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos + Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2 - CMapRead::Size / 2), Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), State::Live),
isCollision(false)
{

}
void CSnakeCopter1Attack::Create()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto SnakeCopter1 = (task->GetComponent<CSnakeCopter1>(CEnemyManager::SnakeCopter1, 0));
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());

	if (/*player.x > SnakeCopter1->transform.GetPos().x - SnakeCopter1->transform.GetScale().x / 2 - pos.x - CMapRead::Size
		&&player.x < SnakeCopter1->transform.GetPos().x + SnakeCopter1->transform.GetScale().x / 2 - pos.x + CMapRead::Size
		&&player.y > SnakeCopter1->transform.GetPos().y - SnakeCopter1->transform.GetScale().y / 2 - pos.y - CMapRead::Size
		&&player.y < SnakeCopter1->transform.GetPos().y + SnakeCopter1->transform.GetScale().y / 2 - pos.y + CMapRead::Size
		&&*/task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isCollision
		&& task->GetComponent<CSnakeCopter1>(CEnemyManager::SnakeCopter1,0)->GetState() != State::None)
	{
		isCollision = true;
		return;
	}
	isCollision = false;

}
void CSnakeCopter1Attack::Left()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter1 = (task->GetComponent<CSnakeCopter1>(CEnemyManager::SnakeCopter1, 0));

	if (player.x < SnakeCopter1->transform.GetPos().x - SnakeCopter1->transform.GetScale().x / 2 - pos->transform.GetPos().x)
	{
		transform.TransformPoint(Point(SnakeCopter1->transform.GetPos().x - SnakeCopter1->transform.GetScale().x, SnakeCopter1->transform.GetPos().y) - pos->transform.GetPos());
	}
}
void CSnakeCopter1Attack::Right()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter1 = (task->GetComponent<CSnakeCopter1>(CEnemyManager::SnakeCopter1, 0));

	if (player.x > SnakeCopter1->transform.GetPos().x + SnakeCopter1->transform.GetScale().x / 2 - pos->transform.GetPos().x)
	{
		transform.TransformPoint(Point(SnakeCopter1->transform.GetPos().x + SnakeCopter1->transform.GetScale().x, SnakeCopter1->transform.GetPos().y) - pos->transform.GetPos());
	}
}
void CSnakeCopter1Attack::Up()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter1 = (task->GetComponent<CSnakeCopter1>(CEnemyManager::SnakeCopter1, 0));

	if (player.y < SnakeCopter1->transform.GetPos().y - SnakeCopter1->transform.GetScale().y / 2 - pos->transform.GetPos().y)
	{
		transform.TransformPoint(Point(SnakeCopter1->transform.GetPos().x, SnakeCopter1->transform.GetPos().y - SnakeCopter1->transform.GetScale().y) - pos->transform.GetPos());
	}
}
void CSnakeCopter1Attack::Down()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter1 = (task->GetComponent<CSnakeCopter1>(CEnemyManager::SnakeCopter1, 0));

	if (player.y > SnakeCopter1->transform.GetPos().y + SnakeCopter1->transform.GetScale().y / 2 - pos->transform.GetPos().y)
	{
		transform.TransformPoint(Point(SnakeCopter1->transform.GetPos().x, SnakeCopter1->transform.GetPos().y + SnakeCopter1->transform.GetScale().y) - pos->transform.GetPos());
	}
}
void CSnakeCopter1Attack::Update()
{
	Left();
	Right();
	Up();
	Down();

	Create();
}

void CSnakeCopter1Attack::Draw()
{

	//font(transform.GetPos()).draw();

	if (isCollision)
	{
		//Rect(transform.GetPos(), transform.GetScale()).draw(ColorF(Palette::Red, 0.5));
	}
}