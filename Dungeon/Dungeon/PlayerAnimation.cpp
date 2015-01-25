#include "PlayerAnimation.h"
#include "PlayerAttack.h"
#include "Player.h"
#include "PlayerAttack.h"
#include "GameManager.h"
#include "Scroll.h"
#include "Collision.h"

#include "Transform.h"
#include "GameApplication.h"
#include "CharacterController.h"

CPlayerAnimation::CPlayerAnimation(std::shared_ptr<CTask> task) :
CPlayerState(task),
TexturePos(Point(1, 1)),
MoveTexturePos(Point(2, 2)),
GraphicChangeCounts(0)
{

}

void CPlayerAnimation::Start()
{
	TextureAsset::Register(L"TaChi", L"engine/data/texture/Character/MainCharacter/shujinkoutachi.png");
	TextureAsset::Register(L"Walk", L"engine/data/texture/Character/MainCharacter/shujinkouaruki.png");
	TextureAsset::Register(L"Attack", L"engine/data/texture/Character/MainCharacter/attack.png");
	TextureAsset::Register(L"Attack_Efect", L"engine/data/texture/Character/MainCharacter/エフェク.png");
}
void CPlayerAnimation::Left()
{
	if (CharacterController::LeftMoveKey())
	{
		TexturePos = Point(0, 1);

		GraphicChangeCounts++;
		if (GraphicChangeCounts % 40 >= 0 && GraphicChangeCounts % 40 <  10) MoveTexturePos = Point(0, 3);
		if (GraphicChangeCounts % 40 >= 10 && GraphicChangeCounts % 40 <  20) MoveTexturePos = Point(1, 3);
		if (GraphicChangeCounts % 40 >= 20 && GraphicChangeCounts % 40 <  30) MoveTexturePos = Point(2, 3);
		if (GraphicChangeCounts % 40 >= 30 && GraphicChangeCounts % 40 <  40) MoveTexturePos = Point(1, 3);
	}
}
void CPlayerAnimation::Right()
{
	if (CharacterController::RightMoveKey())
	{
		TexturePos = Point(2, 1);

		GraphicChangeCounts++;
		if (GraphicChangeCounts % 40 >= 0 && GraphicChangeCounts % 40 <  10) MoveTexturePos = Point(6, 3);
		if (GraphicChangeCounts % 40 >= 10 && GraphicChangeCounts % 40 <  20) MoveTexturePos = Point(5, 3);
		if (GraphicChangeCounts % 40 >= 20 && GraphicChangeCounts % 40 <  30) MoveTexturePos = Point(4, 3);
		if (GraphicChangeCounts % 40 >= 30 && GraphicChangeCounts % 40 <  40) MoveTexturePos = Point(5, 3);
	}
}

void CPlayerAnimation::Up()
{
	if (CharacterController::UpMoveKey())
	{
		TexturePos = Point(1, 0);

		GraphicChangeCounts++;
		if (GraphicChangeCounts % 40 >= 0 && GraphicChangeCounts % 40 <  10) MoveTexturePos = Point(3, 0);
		if (GraphicChangeCounts % 40 >= 10 && GraphicChangeCounts % 40 <  20) MoveTexturePos = Point(3, 1);
		if (GraphicChangeCounts % 40 >= 20 && GraphicChangeCounts % 40 <  30) MoveTexturePos = Point(3, 2);
		if (GraphicChangeCounts % 40 >= 30 && GraphicChangeCounts % 40 <  40) MoveTexturePos = Point(3, 1);
	}
}

void CPlayerAnimation::Down()
{
	if (CharacterController::DownMoveKey())
	{
		TexturePos = Point(1, 2);

		GraphicChangeCounts++;
		if (GraphicChangeCounts % 40 >= 0 && GraphicChangeCounts % 40 <  10) MoveTexturePos = Point(3, 6);
		if (GraphicChangeCounts % 40 >= 10 && GraphicChangeCounts % 40 <  20) MoveTexturePos = Point(3, 5);
		if (GraphicChangeCounts % 40 >= 20 && GraphicChangeCounts % 40 <  30) MoveTexturePos = Point(3, 4);
		if (GraphicChangeCounts % 40 >= 30 && GraphicChangeCounts % 40 <  40) MoveTexturePos = Point(3, 5);
	}
}
void CPlayerAnimation::Update()
{
	Right();
	Left();
	Up();
	Down();
}

void CPlayerAnimation::Draw()
{
	auto player = task->GetComponent<CPlayer>(CGameManager::PlayerName, 0);
	auto player_atk = task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0);

	if (CharacterController::RightMoveKey() || CharacterController::LeftMoveKey()
		|| CharacterController::UpMoveKey() || CharacterController::DownMoveKey())
	{
		Rect(player->transform.GetPos(), player->transform.GetScale())(TextureAsset(L"Walk")(TextureSize.x * MoveTexturePos.x, TextureSize.y * MoveTexturePos.y, TextureSize.x, TextureSize.y)).draw();
	}
	else if (CharacterController::AttackKey())
	{
		Rect(player_atk->transform.GetPos(), player_atk->transform.GetScale())(TextureAsset(L"Attack")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw();
		Rect(player_atk->transform.GetPos(), player_atk->transform.GetScale())(TextureAsset(L"Attack_Efect")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw();
		Rect(player->transform.GetPos(), player->transform.GetScale())(TextureAsset(L"Attack")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw();
	}
	else
	{
		Rect(player->transform.GetPos(), player->transform.GetScale())(TextureAsset(L"TaChi")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw();
	}
}