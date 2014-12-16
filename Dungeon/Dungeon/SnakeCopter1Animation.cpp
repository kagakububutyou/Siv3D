#include "SnakeCopter1Animation.h"
#include "SnakeCopter1Attack.h"
#include "SnakeCopter1.h"
#include "EnemyManager.h"

#include "PlayerAttack.h"
#include "GameManager.h"
#include "Scroll.h"
#include "Collision.h"

#include "Transform.h"
#include "GameApplication.h"
#include "CharacterController.h"

CSnakeCopter1Animation::CSnakeCopter1Animation(std::shared_ptr<CTask> task) :
CPlayerState(task),
TexturePos(Point(1, 1))
{

}

void CSnakeCopter1Animation::Start()
{
	TextureAsset::Register(L"SnakeCopter1", L"engine/data/texture/Character/Enemy/SnakeCopter.png");
}

void CSnakeCopter1Animation::Right()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter1 = (task->GetComponent<CSnakeCopter1>(CEnemyManager::SnakeCopter1, 0));

	if (player.x > SnakeCopter1->transform.GetPos().x + SnakeCopter1->transform.GetScale().x / 2 - pos->transform.GetPos().x)
	{
		TexturePos = Point(2,1);
	}
}
void CSnakeCopter1Animation::Left()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter1 = (task->GetComponent<CSnakeCopter1>(CEnemyManager::SnakeCopter1, 0));

	if (player.x < SnakeCopter1->transform.GetPos().x - SnakeCopter1->transform.GetScale().x / 2 - pos->transform.GetPos().x)
	{
		TexturePos = Point(0, 1);
	}
}
void CSnakeCopter1Animation::Up()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter1 = (task->GetComponent<CSnakeCopter1>(CEnemyManager::SnakeCopter1, 0));

	if (player.y < SnakeCopter1->transform.GetPos().y - SnakeCopter1->transform.GetScale().y / 2 - pos->transform.GetPos().y)
	{
		TexturePos = Point(1, 0);
	}
}
	
void CSnakeCopter1Animation::Down()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter1 = (task->GetComponent<CSnakeCopter1>(CEnemyManager::SnakeCopter1, 0));

	if (player.y > SnakeCopter1->transform.GetPos().y + SnakeCopter1->transform.GetScale().y / 2 - pos->transform.GetPos().y)
	{
		TexturePos = Point(1, 2);
	}
}
void CSnakeCopter1Animation::Update()
{
	Right();
	Left();
	Up();
	Down();
}

void CSnakeCopter1Animation::Draw()
{
	auto atk = task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	auto SnakeCopter1 = task->GetComponent<CSnakeCopter1>(CEnemyManager::SnakeCopter1, 0);
	auto snake_atk = task->GetComponent<CSnakeCopter1Attack>(CEnemyManager::SnakeCopter1Attack, 0);

	if (Collision::RectToRect(SnakeCopter1->transform.GetPos() - pos, SnakeCopter1->transform.GetScale(), atk->transform.GetPos(), atk->transform.GetScale())
		&& atk->isCollision)
	{
		Rect(SnakeCopter1->transform.GetPos() - pos, SnakeCopter1->transform.GetScale())(TextureAsset(L"SnakeCopter1")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw(ColorF(Palette::Yellow));
	}
	else if (CharacterController::AttackKey())
	{
		Rect(snake_atk->transform.GetPos(), snake_atk->transform.GetScale())(TextureAsset(L"Fire")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw();
		Rect(SnakeCopter1->transform.GetPos() - pos, SnakeCopter1->transform.GetScale())(TextureAsset(L"SnakeCopter1")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw();
	}
	else
	{
		Rect(SnakeCopter1->transform.GetPos() - pos, SnakeCopter1->transform.GetScale())(TextureAsset(L"SnakeCopter1")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw();
	}
}