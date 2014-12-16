#include "SnakeCopterAnimation.h"
#include "SnakeCopterAttack.h"
#include "SnakeCopter.h"
#include "EnemyManager.h"

#include "PlayerAttack.h"
#include "GameManager.h"
#include "Scroll.h"
#include "Collision.h"

#include "Transform.h"
#include "GameApplication.h"
#include "CharacterController.h"

CSnakeCopterAnimation::CSnakeCopterAnimation(std::shared_ptr<CTask> task) :
CPlayerState(task),
TexturePos(Point(1, 1))
{

}

void CSnakeCopterAnimation::Start()
{
	TextureAsset::Register(L"SnakeCopter", L"engine/data/texture/Character/Enemy/SnakeCopter.png");
}

void CSnakeCopterAnimation::Right()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter = (task->GetComponent<CSnakeCopter>(CEnemyManager::SnakeCopter, 0));

	if (player.x > SnakeCopter->transform.GetPos().x + SnakeCopter->transform.GetScale().x / 2 - pos->transform.GetPos().x)
	{
		TexturePos = Point(2,1);
	}
}
void CSnakeCopterAnimation::Left()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter = (task->GetComponent<CSnakeCopter>(CEnemyManager::SnakeCopter, 0));

	if (player.x < SnakeCopter->transform.GetPos().x - SnakeCopter->transform.GetScale().x / 2 - pos->transform.GetPos().x)
	{
		TexturePos = Point(0, 1);
	}
}
void CSnakeCopterAnimation::Up()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter = (task->GetComponent<CSnakeCopter>(CEnemyManager::SnakeCopter, 0));

	if (player.y < SnakeCopter->transform.GetPos().y - SnakeCopter->transform.GetScale().y / 2 - pos->transform.GetPos().y)
	{
		TexturePos = Point(1, 0);
	}
}
	
void CSnakeCopterAnimation::Down()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter = (task->GetComponent<CSnakeCopter>(CEnemyManager::SnakeCopter, 0));

	if (player.y > SnakeCopter->transform.GetPos().y + SnakeCopter->transform.GetScale().y / 2 - pos->transform.GetPos().y)
	{
		TexturePos = Point(1, 2);
	}
}
void CSnakeCopterAnimation::Update()
{
	Right();
	Left();
	Up();
	Down();
}

void CSnakeCopterAnimation::Draw()
{
	auto atk = task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	auto SnakeCopter = task->GetComponent<CSnakeCopter>(CEnemyManager::SnakeCopter, 0);
	auto snake_atk = task->GetComponent<CSnakeCopterAttack>(CEnemyManager::SnakeCopterAttack, 0);

	if (Collision::RectToRect(SnakeCopter->transform.GetPos() - pos, SnakeCopter->transform.GetScale(), atk->transform.GetPos(), atk->transform.GetScale())
		&& atk->isCollision)
	{
		Rect(SnakeCopter->transform.GetPos() - pos, SnakeCopter->transform.GetScale())(TextureAsset(L"SnakeCopter")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw(ColorF(Palette::Yellow));
	}
	else if (CharacterController::AttackKey())
	{
		Rect(snake_atk->transform.GetPos(), snake_atk->transform.GetScale())(TextureAsset(L"Fire")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw();
		Rect(SnakeCopter->transform.GetPos() - pos, SnakeCopter->transform.GetScale())(TextureAsset(L"SnakeCopter")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw();
	}
	else
	{
		Rect(SnakeCopter->transform.GetPos() - pos, SnakeCopter->transform.GetScale())(TextureAsset(L"SnakeCopter")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw();
	}
}