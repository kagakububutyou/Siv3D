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
StopTexture(Point(1,1)),
MoveTexture(Point(2, 2)),
GraphicChangeCounts(0)
{

}

void CPlayerAnimation::Start()
{
	TextureAsset::Register(L"TaChi", L"engine/data/texture/Character/MainCharacter/shujinkoutachi.png");
	TextureAsset::Register(L"Walk", L"engine/data/texture/Character/MainCharacter/shujinkouaruki.png");
	TextureAsset::Register(L"Attack", L"engine/data/texture/Character/MainCharacter/attack.png");
	TextureAsset::Register(L"Attack_Efect", L"engine/data/texture/Character/MainCharacter/エフェク.png");

	StopTexturePos[MOVEDIREC::LEFT] = Point(0, 1);
	StopTexturePos[MOVEDIREC::RIGHT] = Point(2, 1);
	StopTexturePos[MOVEDIREC::UP] = Point(1, 0);
	StopTexturePos[MOVEDIREC::DOWN] = Point(1, 2);

	Cut[0] = 0; Cut[1] = 1; Cut[2] = 2; Cut[3] = 1;
	
	for (int i = MOVEDIREC::LEFT; i < MOVEDIREC::UP; i++)
	{
		for (int j = 0; j < CutNum; j++)
		{
			MoveTexturePos[i][j] = Point(Cut[j] + i * CutNum, CutNum - 1);
		}
	}
	for (int i = MOVEDIREC::UP; i < MOVEDIREC::DIREC; i++)
	{
		for (int j = 0; j < CutNum; j++)
		{
			MoveTexturePos[i][j] = Point(CutNum - 1, Cut[j] + (i - MOVEDIREC::UP) * CutNum);
		}
	}
}
void CPlayerAnimation::Left()
{
	if (CharacterController::LeftMoveKey())
	{
		Texture(MOVEDIREC::LEFT);
	}
}
void CPlayerAnimation::Right()
{
	if (CharacterController::RightMoveKey())
	{
		Texture(MOVEDIREC::RIGHT);
	}
}

void CPlayerAnimation::Up()
{
	if (CharacterController::UpMoveKey())
	{
		Texture(MOVEDIREC::UP);
	}
}

void CPlayerAnimation::Down()
{
	if (CharacterController::DownMoveKey())
	{
		Texture(MOVEDIREC::DOWN);
	}
}
void CPlayerAnimation::Texture(MOVEDIREC Direc)
{
	StopTexture = StopTexturePos[Direc];

	GraphicChangeCounts++;

	for (int i = 0; i < 4; i++)
	{
		if (GraphicChangeCounts % 40 >= i * 10 && GraphicChangeCounts % 40 < (i + 1) * 10)
		{
			MoveTexture = MoveTexturePos[Direc][i];
		}
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
		Rect(player->transform.GetPos(), player->transform.GetScale())(TextureAsset(L"Walk")(TextureSize.x * MoveTexture.x, TextureSize.y * MoveTexture.y, TextureSize.x, TextureSize.y)).draw();
	}
	else
	{
		Rect(player->transform.GetPos(), player->transform.GetScale())(TextureAsset(L"TaChi")(TextureSize.x * StopTexture.x, TextureSize.y * StopTexture.y, TextureSize.x, TextureSize.y)).draw();
	}
	if (CharacterController::AttackKey())
	{
		Rect(player_atk->transform.GetPos(), player_atk->transform.GetScale())(TextureAsset(L"Attack")(TextureSize.x * StopTexture.x, TextureSize.y * StopTexture.y, TextureSize.x, TextureSize.y)).draw();
		Rect(player_atk->transform.GetPos(), player_atk->transform.GetScale())(TextureAsset(L"Attack_Efect")(TextureSize.x * StopTexture.x, TextureSize.y * StopTexture.y, TextureSize.x, TextureSize.y)).draw();
		Rect(player->transform.GetPos(), player->transform.GetScale())(TextureAsset(L"Attack")(TextureSize.x * StopTexture.x, TextureSize.y * StopTexture.y, TextureSize.x, TextureSize.y)).draw();
	}
	
}