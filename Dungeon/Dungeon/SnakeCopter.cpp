#include "SnakeCopter.h"
#include "SnakeCopterAnimation.h"
#include "SnakeCopterMove.h"
#include "MapRead.h"
#include "MiniMap.h"
#include "Scroll.h"
#include "GameManager.h"
#include "EnemyManager.h"

#include "Player.h"
#include "PlayerMove.h"
#include "Collision.h"
#include "PlayerAttack.h"


CSnakeCopter::CSnakeCopter(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos, Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), State::Live),
anime(std::make_unique<CSnakeCopterAnimation>(task)),
move(std::make_unique<CSnakeCopterMove>(task)),
isCollision(false),
HP(2)
{
}

void CSnakeCopter::Start()
{
	//transform.TransformPoint(Point(transform.GetPos().x / CMiniMap::MapScale + CGameApplication::ScreenWidth / 2 - (CMapRead::Width * CMapRead::Size / CMiniMap::MapScale) / 2,
	//transform.GetPos().y / CMiniMap::MapScale + CGameApplication::ScreenHeight / 2 - (CMapRead::Height * CMapRead::Size / CMiniMap::MapScale) / 2 - (CMapRead::Size / CMiniMap::MapScale) * 7 / 2));

	anime->Start();
	move->Start();
}
void CSnakeCopter::OnCollision()
{
	auto atk = task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	auto SnakeCopter = task->GetComponent<CSnakeCopter>(CEnemyManager::SnakeCopter, 0);

	if (Collision::RectToRect(SnakeCopter->transform.GetPos() - pos, SnakeCopter->transform.GetScale(), atk->transform.GetPos(), atk->transform.GetScale())
		&& atk->isCollision)
	{
		SnakeCopter->HitAttack();
	}
	if (SnakeCopter->GetHP() <= 0)
	{
		state = State::None;
	}
	if (state == State::None)
	{
		atk->isEnemys[CPlayerAttack::EnemyName::SnakeCopter] = true;
	}
}
void CSnakeCopter::Update()
{
	if (state != State::None)
	{
		anime->Update();
		move->Update();
	}
	OnCollision();
}
void CSnakeCopter::Draw()
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
	}
}