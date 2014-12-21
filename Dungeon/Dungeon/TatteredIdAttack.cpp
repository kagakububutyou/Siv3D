#include "MapRead.h"
#include "Scroll.h"
#include "GameApplication.h"
#include "TatteredIdAttack.h"
#include "CharacterController.h"
#include "TatteredId.h"
#include "GameManager.h"
#include "EnemyManager.h"
#include "TatteredIdMove.h"

#include "Player.h"
#include "PlayerAttack.h"

CTatteredIdAttack::CTatteredIdAttack(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos + Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2 - CMapRead::Size / 2), Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), State::Live),
isCollision(false)
{

}
void CTatteredIdAttack::Create()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto TatteredId = (task->GetComponent<CTatteredId>(CEnemyManager::TatteredId, 0));
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());

	if (/*player.x > TatteredId->transform.GetPos().x - TatteredId->transform.GetScale().x / 2 - pos.x - CMapRead::Size
		&&player.x < TatteredId->transform.GetPos().x + TatteredId->transform.GetScale().x / 2 - pos.x + CMapRead::Size
		&&player.y > TatteredId->transform.GetPos().y - TatteredId->transform.GetScale().y / 2 - pos.y - CMapRead::Size
		&&player.y < TatteredId->transform.GetPos().y + TatteredId->transform.GetScale().y / 2 - pos.y + CMapRead::Size
		&&*/task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isCollision
		&&  task->GetComponent<CTatteredId>(CEnemyManager::TatteredId, 0)->GetState() != State::None)
	{
		isCollision = true;
		return;
	}
	isCollision = false;

}
void CTatteredIdAttack::Left()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto TatteredId = (task->GetComponent<CTatteredId>(CEnemyManager::TatteredId, 0));

	if (player.x < TatteredId->transform.GetPos().x - TatteredId->transform.GetScale().x / 2 - pos->transform.GetPos().x)
	{
		transform.TransformPoint(Point(TatteredId->transform.GetPos().x - TatteredId->transform.GetScale().x, TatteredId->transform.GetPos().y) - pos->transform.GetPos());
		TexturePos = Point(0, 1);
	}
}
void CTatteredIdAttack::Right()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto TatteredId = (task->GetComponent<CTatteredId>(CEnemyManager::TatteredId, 0));

	if (player.x > TatteredId->transform.GetPos().x + TatteredId->transform.GetScale().x / 2 - pos->transform.GetPos().x)
	{
		transform.TransformPoint(Point(TatteredId->transform.GetPos().x + TatteredId->transform.GetScale().x, TatteredId->transform.GetPos().y) - pos->transform.GetPos());
		TexturePos = Point(2, 1);
	}
}
void CTatteredIdAttack::Up()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto TatteredId = (task->GetComponent<CTatteredId>(CEnemyManager::TatteredId, 0));

	if (player.y < TatteredId->transform.GetPos().y - TatteredId->transform.GetScale().y / 2 - pos->transform.GetPos().y)
	{
		transform.TransformPoint(Point(TatteredId->transform.GetPos().x, TatteredId->transform.GetPos().y - TatteredId->transform.GetScale().y) - pos->transform.GetPos());
		TexturePos = Point(1, 0);
	}
}
void CTatteredIdAttack::Down()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto TatteredId = (task->GetComponent<CTatteredId>(CEnemyManager::TatteredId, 0));

	if (player.y > TatteredId->transform.GetPos().y + TatteredId->transform.GetScale().y / 2 - pos->transform.GetPos().y)
	{
		transform.TransformPoint(Point(TatteredId->transform.GetPos().x, TatteredId->transform.GetPos().y + TatteredId->transform.GetScale().y) - pos->transform.GetPos());
		TexturePos = Point(1, 2);
	}
}
void CTatteredIdAttack::Update()
{
	Left();
	Right();
	Up();
	Down();

	Create();
}

void CTatteredIdAttack::Draw()
{

	//font(transform.GetPos()).draw();

	if (isCollision)
	{
		Rect(transform.GetPos(), transform.GetScale())(TextureAsset(L"TatteredIdAttack")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw();
		Rect(transform.GetPos(), transform.GetScale())(TextureAsset(L"Attack_Efect")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw();
		//Rect(transform.GetPos(), transform.GetScale()).draw(ColorF(Palette::Red, 0.5));
	}
}