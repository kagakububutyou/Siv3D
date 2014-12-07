#include "PatrollerAnimation.h"
#include "Patroller.h"
#include "EnemyManager.h"

#include "PlayerAttack.h"
#include "GameManager.h"
#include "Scroll.h"
#include "Collision.h"

#include "Transform.h"
#include "GameApplication.h"

CPatrollerAnimation::CPatrollerAnimation(std::shared_ptr<CTask> task) :
CPlayerState(task),
TexturePos(Point(1, 1))
{

}

void CPatrollerAnimation::Start()
{
	TextureAsset::Register(L"Patroller", L"engine/data/texture/Character/Enemy/Patroller.png");
}

void CPatrollerAnimation::Right()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto patroller = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0));

	if (player.x > patroller->transform.GetPos().x + patroller->transform.GetScale().x / 2 - pos->transform.GetPos().x)
	{
		TexturePos = Point(2,1);
	}
}
void CPatrollerAnimation::Left()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto patroller = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0));

	if (player.x < patroller->transform.GetPos().x - patroller->transform.GetScale().x / 2 - pos->transform.GetPos().x)
	{
		TexturePos = Point(0, 1);
	}
}
void CPatrollerAnimation::Up()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto patroller = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0));

	if (player.y < patroller->transform.GetPos().y - patroller->transform.GetScale().y / 2 - pos->transform.GetPos().y)
	{
		TexturePos = Point(1, 0);
	}
}
	
void CPatrollerAnimation::Down()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto patroller = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0));

	if (player.y > patroller->transform.GetPos().y + patroller->transform.GetScale().y / 2 - pos->transform.GetPos().y)
	{
		TexturePos = Point(1, 2);
	}
}
void CPatrollerAnimation::Update()
{
	Right();
	Left();
	Up();
	Down();
}

void CPatrollerAnimation::Draw()
{
	auto atk = task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	auto patroller = task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0);

	if (Collision::RectToRect(patroller->transform.GetPos() - pos, patroller->transform.GetScale(), atk->transform.GetPos(), atk->transform.GetScale())
		&& atk->isCollision)
	{
		Rect(patroller->transform.GetPos() - pos, patroller->transform.GetScale())(TextureAsset(L"Patroller")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw(ColorF(Palette::Yellow));
	}
	else
	{
		Rect(patroller->transform.GetPos() - pos, patroller->transform.GetScale())(TextureAsset(L"Patroller")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw();
	}
}