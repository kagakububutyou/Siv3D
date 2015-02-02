#include "TatteredId.h"
#include "TatteredIdAnimation.h"
#include "TatteredIdMove.h"
#include "TatteredIdAttack.h"
#include "MapRead.h"
#include "MiniMap.h"
#include "Scroll.h"
#include "GameManager.h"
#include "EnemyManager.h"

#include "Player.h"
#include "PlayerMove.h"
#include "Collision.h"
#include "PlayerAttack.h"


CTatteredId::CTatteredId(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos, Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), State::Live),
anime(std::make_unique<CTatteredIdAnimation>(task)),
move(std::make_unique<CTatteredIdMove>(task)),
isCollision(false),
HP(10)
{
}

void CTatteredId::Start()
{
	//transform.TransformPoint(Point(transform.GetPos().x / CMiniMap::MapScale + CGameApplication::ScreenWidth / 2 - (CMapRead::Width * CMapRead::Size / CMiniMap::MapScale) / 2,
	//transform.GetPos().y / CMiniMap::MapScale + CGameApplication::ScreenHeight / 2 - (CMapRead::Height * CMapRead::Size / CMiniMap::MapScale) / 2 - (CMapRead::Size / CMiniMap::MapScale) * 7 / 2));

	anime->Start();
	move->Start();
}
void CTatteredId::OnCollision()
{
	auto atk = task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	auto TatteredId = task->GetComponent<CTatteredId>(CEnemyManager::TatteredId, 0);

	if (Collision::RectToRect(TatteredId->transform.GetPos() - pos, TatteredId->transform.GetScale(), atk->transform.GetPos(), atk->transform.GetScale())
		&& atk->isCollision)
	{
		TatteredId->HitAttack();
	}
	if (TatteredId->GetHP() <= 0)
	{
		state = State::None;
	}
	if (state == State::None)
	{
		atk->isEnemys[CPlayerAttack::EnemyName::TatteredId] = true;
	}
}
void CTatteredId::Update()
{
	if (state != State::None)
	{
		anime->Update();
		move->Update();
		task->GetComponent<CTatteredIdAttack>(CEnemyManager::TatteredIdAttack, 0)->Update();
	}

	OnCollision();
}
void CTatteredId::Draw()
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
		task->GetComponent<CTatteredIdAttack>(CEnemyManager::TatteredIdAttack, 0)->Draw();
	}
}