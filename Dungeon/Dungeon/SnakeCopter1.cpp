#include "SnakeCopter1.h"
#include "SnakeCopter1Animation.h"
#include "SnakeCopter1Move.h"
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


CSnakeCopter1::CSnakeCopter1(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos + Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2 - CMapRead::Size / 2), Point(CMapRead::Size/* / CMiniMap::MapScale*/, CMapRead::Size/* / CMiniMap::MapScale*/), Point(0, 0)), State::Live),
anime(std::make_unique<CSnakeCopter1Animation>(task)),
move(std::make_unique<CSnakeCopter1Move>(task)),
isCollision(false)
{
}

void CSnakeCopter1::Start()
{
	//transform.TransformPoint(Point(transform.GetPos().x / CMiniMap::MapScale + CGameApplication::ScreenWidth / 2 - (CMapRead::Width * CMapRead::Size / CMiniMap::MapScale) / 2,
	//transform.GetPos().y / CMiniMap::MapScale + CGameApplication::ScreenHeight / 2 - (CMapRead::Height * CMapRead::Size / CMiniMap::MapScale) / 2 - (CMapRead::Size / CMiniMap::MapScale) * 7 / 2));

	anime->Start();
	move->Start();
}
void CSnakeCopter1::OnCollision()
{
	auto atk = task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	auto SnakeCopter1 = task->GetComponent<CSnakeCopter1>(CEnemyManager::SnakeCopter1, 0);

	if (Collision::RectToRect(SnakeCopter1->transform.GetPos() - pos, SnakeCopter1->transform.GetScale(), atk->transform.GetPos(), atk->transform.GetScale())
		&& atk->isCollision)
	{
		state = State::None;
		atk->isEnemy3 = true;
	}
}
void CSnakeCopter1::Update()
{
	if (state != State::None)
	{
		anime->Update();
		move->Update();
	}
	OnCollision();
}
void CSnakeCopter1::Draw()
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