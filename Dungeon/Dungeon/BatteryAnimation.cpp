#include "BatteryAnimation.h"
#include "BatteryAttack.h"
#include "Battery.h"
#include "EnemyManager.h"
#include "Player.h"
#include "PlayerAttack.h"
#include "GameManager.h"
#include "Scroll.h"
#include "Collision.h"

#include "Transform.h"
#include "GameApplication.h"
#include "CharacterController.h"

CBatteryAnimation::CBatteryAnimation(std::shared_ptr<CTask> task) :
CPlayerState(task),
TexturePos(Point(1, 1)),
MoveTexturePos(Point(2, 2)),
GraphicChangeCounts(0)
{

}

void CBatteryAnimation::Start()
{
	TextureAsset::Register(L"Battery", L"engine/data/texture/Character/Enemy/Battery.png");
	TextureAsset::Register(L"BatteryWalk", L"engine/data/texture/Character/Enemy/Batteryaruki.png");
	TextureAsset::Register(L"BatteryAttack", L"engine/data/texture/Character/Enemy/BatteryAttack.png");
	TextureAsset::Register(L"tekiefekuto", L"engine/data/texture/Character/Enemy/tekiefekuto.png");
}

void CBatteryAnimation::Right()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto Battery = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0));

	if (player.x > Battery->transform.GetPos().x + Battery->transform.GetScale().x / 2 - pos->transform.GetPos().x)
	{
		TexturePos = Point(2, 1);

		GraphicChangeCounts++;
		if (GraphicChangeCounts % 40 >= 0 && GraphicChangeCounts % 40 <  10) MoveTexturePos = Point(6, 3);
		if (GraphicChangeCounts % 40 >= 10 && GraphicChangeCounts % 40 <  20) MoveTexturePos = Point(5, 3);
		if (GraphicChangeCounts % 40 >= 20 && GraphicChangeCounts % 40 <  30) MoveTexturePos = Point(4, 3);
		if (GraphicChangeCounts % 40 >= 30 && GraphicChangeCounts % 40 <  40) MoveTexturePos = Point(5, 3);
	}
}
void CBatteryAnimation::Left()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto Battery = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0));

	if (player.x < Battery->transform.GetPos().x - Battery->transform.GetScale().x / 2 - pos->transform.GetPos().x)
	{
		TexturePos = Point(0, 1);


		GraphicChangeCounts++;
		if (GraphicChangeCounts % 40 >= 0 && GraphicChangeCounts % 40 <  10) MoveTexturePos = Point(0, 3);
		if (GraphicChangeCounts % 40 >= 10 && GraphicChangeCounts % 40 <  20) MoveTexturePos = Point(1, 3);
		if (GraphicChangeCounts % 40 >= 20 && GraphicChangeCounts % 40 <  30) MoveTexturePos = Point(2, 3);
		if (GraphicChangeCounts % 40 >= 30 && GraphicChangeCounts % 40 <  40) MoveTexturePos = Point(1, 3);
	}
}
void CBatteryAnimation::Up()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto Battery = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0));

	if (player.y < Battery->transform.GetPos().y - Battery->transform.GetScale().y / 2 - pos->transform.GetPos().y)
	{
		TexturePos = Point(1, 0);

		GraphicChangeCounts++;
		if (GraphicChangeCounts % 40 >= 0 && GraphicChangeCounts % 40 <  10) MoveTexturePos = Point(3, 0);
		if (GraphicChangeCounts % 40 >= 10 && GraphicChangeCounts % 40 <  20) MoveTexturePos = Point(3, 1);
		if (GraphicChangeCounts % 40 >= 20 && GraphicChangeCounts % 40 <  30) MoveTexturePos = Point(3, 2);
		if (GraphicChangeCounts % 40 >= 30 && GraphicChangeCounts % 40 <  40) MoveTexturePos = Point(3, 1);
	}
}

void CBatteryAnimation::Down()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto Battery = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0));

	if (player.y > Battery->transform.GetPos().y + Battery->transform.GetScale().y / 2 - pos->transform.GetPos().y)
	{
		TexturePos = Point(1, 2);

		GraphicChangeCounts++;
		if (GraphicChangeCounts % 40 >= 0 && GraphicChangeCounts % 40 <  10) MoveTexturePos = Point(3, 6);
		if (GraphicChangeCounts % 40 >= 10 && GraphicChangeCounts % 40 <  20) MoveTexturePos = Point(3, 5);
		if (GraphicChangeCounts % 40 >= 20 && GraphicChangeCounts % 40 <  30) MoveTexturePos = Point(3, 4);
		if (GraphicChangeCounts % 40 >= 30 && GraphicChangeCounts % 40 <  40) MoveTexturePos = Point(3, 5);
	}
}
void CBatteryAnimation::Update()
{
	Right();
	Left();
	Up();
	Down();
}

void CBatteryAnimation::Draw()
{
	auto atk = task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	auto Battery = task->GetComponent<CBattery>(CEnemyManager::Battery, 0);
	auto BatteryAtk = task->GetComponent<CBatteryAttack>(CEnemyManager::BatteryAttack, 0);

	if (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior
		|| task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isCollision)
	{
		Rect(Battery->transform.GetPos() - pos, Battery->transform.GetScale())(TextureAsset(L"BatteryWalk")(TextureSize.x * MoveTexturePos.x, TextureSize.y * MoveTexturePos.y, TextureSize.x, TextureSize.y)).draw();
	}
	else if (CharacterController::AttackAnimation())
	{
		Rect(Battery->transform.GetPos() - pos, Battery->transform.GetScale())(TextureAsset(L"BatteryAttack")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw();
	}
	else
	{
		Rect(Battery->transform.GetPos() - pos, Battery->transform.GetScale())(TextureAsset(L"Battery")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw();
	}
}