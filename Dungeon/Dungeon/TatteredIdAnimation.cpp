#include "TatteredIdAnimation.h"
#include "TatteredIdAttack.h"
#include "TatteredId.h"
#include "EnemyManager.h"
#include "Player.h"
#include "PlayerAttack.h"
#include "GameManager.h"
#include "Scroll.h"
#include "Collision.h"

#include "Transform.h"
#include "GameApplication.h"
#include "CharacterController.h"

CTatteredIdAnimation::CTatteredIdAnimation(std::shared_ptr<CTask> task) :
CPlayerState(task),
TexturePos(Point(1, 1)),
MoveTexturePos(Point(2, 2)),
GraphicChangeCounts(0)
{

}

void CTatteredIdAnimation::Start()
{
	TextureAsset::Register(L"TatteredId", L"engine/data/texture/Character/Enemy/TatteredId.png");
	TextureAsset::Register(L"TatteredIdWalk", L"engine/data/texture/Character/Enemy/TatteredIdaruki.png");
	TextureAsset::Register(L"TatteredIdAttack", L"engine/data/texture/Character/Enemy/TatteredIdAttack.png");
}

void CTatteredIdAnimation::Right()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto TatteredId = (task->GetComponent<CTatteredId>(CEnemyManager::TatteredId, 0));

	if (player.x > TatteredId->transform.GetPos().x + TatteredId->transform.GetScale().x / 2 - pos->transform.GetPos().x)
	{
		TexturePos = Point(2, 1);

		GraphicChangeCounts++;
		if (GraphicChangeCounts % 40 >= 0 && GraphicChangeCounts % 40 <  10) MoveTexturePos = Point(6, 3);
		if (GraphicChangeCounts % 40 >= 10 && GraphicChangeCounts % 40 <  20) MoveTexturePos = Point(5, 3);
		if (GraphicChangeCounts % 40 >= 20 && GraphicChangeCounts % 40 <  30) MoveTexturePos = Point(4, 3);
		if (GraphicChangeCounts % 40 >= 30 && GraphicChangeCounts % 40 <  40) MoveTexturePos = Point(5, 3);
	}
}
void CTatteredIdAnimation::Left()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto TatteredId = (task->GetComponent<CTatteredId>(CEnemyManager::TatteredId, 0));

	if (player.x < TatteredId->transform.GetPos().x - TatteredId->transform.GetScale().x / 2 - pos->transform.GetPos().x)
	{
		TexturePos = Point(0, 1);


		GraphicChangeCounts++;
		if (GraphicChangeCounts % 40 >= 0 && GraphicChangeCounts % 40 <  10) MoveTexturePos = Point(0, 3);
		if (GraphicChangeCounts % 40 >= 10 && GraphicChangeCounts % 40 <  20) MoveTexturePos = Point(1, 3);
		if (GraphicChangeCounts % 40 >= 20 && GraphicChangeCounts % 40 <  30) MoveTexturePos = Point(2, 3);
		if (GraphicChangeCounts % 40 >= 30 && GraphicChangeCounts % 40 <  40) MoveTexturePos = Point(1, 3);
	}
}
void CTatteredIdAnimation::Up()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto TatteredId = (task->GetComponent<CTatteredId>(CEnemyManager::TatteredId, 0));

	if (player.y < TatteredId->transform.GetPos().y - TatteredId->transform.GetScale().y / 2 - pos->transform.GetPos().y)
	{
		TexturePos = Point(1, 0);

		GraphicChangeCounts++;
		if (GraphicChangeCounts % 40 >= 0 && GraphicChangeCounts % 40 <  10) MoveTexturePos = Point(3, 0);
		if (GraphicChangeCounts % 40 >= 10 && GraphicChangeCounts % 40 <  20) MoveTexturePos = Point(3, 1);
		if (GraphicChangeCounts % 40 >= 20 && GraphicChangeCounts % 40 <  30) MoveTexturePos = Point(3, 2);
		if (GraphicChangeCounts % 40 >= 30 && GraphicChangeCounts % 40 <  40) MoveTexturePos = Point(3, 1);
	}
}

void CTatteredIdAnimation::Down()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto TatteredId = (task->GetComponent<CTatteredId>(CEnemyManager::TatteredId, 0));

	if (player.y > TatteredId->transform.GetPos().y + TatteredId->transform.GetScale().y / 2 - pos->transform.GetPos().y)
	{
		TexturePos = Point(1, 2);

		GraphicChangeCounts++;
		if (GraphicChangeCounts % 40 >= 0 && GraphicChangeCounts % 40 <  10) MoveTexturePos = Point(3, 6);
		if (GraphicChangeCounts % 40 >= 10 && GraphicChangeCounts % 40 <  20) MoveTexturePos = Point(3, 5);
		if (GraphicChangeCounts % 40 >= 20 && GraphicChangeCounts % 40 <  30) MoveTexturePos = Point(3, 4);
		if (GraphicChangeCounts % 40 >= 30 && GraphicChangeCounts % 40 <  40) MoveTexturePos = Point(3, 5);
	}
}
void CTatteredIdAnimation::Update()
{
	Right();
	Left();
	Up();
	Down();
}

void CTatteredIdAnimation::Draw()
{
	auto atk = task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	auto TatteredId = task->GetComponent<CTatteredId>(CEnemyManager::TatteredId, 0);
	auto TatteredIdAtk = task->GetComponent<CTatteredIdAttack>(CEnemyManager::TatteredIdAttack, 0);

	if (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior
		|| task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isCollision)
	{
		Rect(TatteredId->transform.GetPos() - pos, TatteredId->transform.GetScale())(TextureAsset(L"TatteredIdWalk")(TextureSize.x * MoveTexturePos.x, TextureSize.y * MoveTexturePos.y, TextureSize.x, TextureSize.y)).draw();
	}
	else if (CharacterController::AttackAnimation())
	{
		Rect(TatteredId->transform.GetPos() - pos, TatteredId->transform.GetScale())(TextureAsset(L"TatteredIdAttack")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw();
	}
	else
	{
		Rect(TatteredId->transform.GetPos() - pos, TatteredId->transform.GetScale())(TextureAsset(L"TatteredId")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw();
	}
}