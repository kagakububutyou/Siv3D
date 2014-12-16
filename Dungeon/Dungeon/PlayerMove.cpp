#include "PlayerMove.h"
#include "CharacterController.h"
#include "Player.h"
#include "Floor.h"
#include "GameManager.h"
#include "Scroll.h"
#include "MiniMap.h"
#include "MiniMapPlayer.h"

#include "Collision.h"

#include "Patroller.h"
#include "MiniGoblin.h"
#include "EnemyManager.h"

#include "Wall.h"
#include "MapRead.h"
#include "PlayerAttack.h"

CPlayerMove::CPlayerMove(std::shared_ptr<CTask> task) :
CPlayerState(task),
state(State::Live),
velocity(Point(0, 0)),
speed(Point(8.0f, 8.0f)),
MoveTexturePos(Point(2,2)),
TexturePos(Point(1, 1)),
GraphicChangeCounts(0)
{

}
void CPlayerMove::Start()
{
	TextureAsset::Register(L"TaChi", L"engine/data/texture/Character/MainCharacter/shujinkoutachi.png");
	TextureAsset::Register(L"Walk", L"engine/data/texture/Character/MainCharacter/shujinkouaruki.png");
	TextureAsset::Register(L"Attack", L"engine/data/texture/Character/MainCharacter/attack.png");
	TextureAsset::Register(L"Attack_Efect", L"engine/data/texture/Character/MainCharacter/�G�t�F�N.png");

}
void CPlayerMove::VelocitySpeed(const Point speed)
{
	/*
	static int hoge = 0;

	hoge++;

	if (hoge % 60 == 0)
	{
	velocity = speed;
	}
	else
	{
	velocity = Point(0,0);
	}
	//*/

	velocity = speed;
}

void CPlayerMove::Left()
{
	if (CharacterController::LeftMoveKey())
	{
		VelocitySpeed(Point(-speed.x, 0));
		TexturePos = Point(0, 1);

		MoveDirec = MOVEDIREC::Left;

		GraphicChangeCounts++;
		if (GraphicChangeCounts % 40 >= 0 && GraphicChangeCounts % 40 <  10) MoveTexturePos = Point(0, 3);
		if (GraphicChangeCounts % 40 >= 10 && GraphicChangeCounts % 40 <  20) MoveTexturePos = Point(1, 3);
		if (GraphicChangeCounts % 40 >= 20 && GraphicChangeCounts % 40 <  30) MoveTexturePos = Point(2, 3);
		if (GraphicChangeCounts % 40 >= 30 && GraphicChangeCounts % 40 <  40) MoveTexturePos = Point(1, 3);

		task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior = true;
	}
}

void CPlayerMove::Right()
{
	if (CharacterController::RightMoveKey())
	{
		VelocitySpeed(Point(speed.x, 0));
		TexturePos = Point(2, 1);

		GraphicChangeCounts++;
		if (GraphicChangeCounts % 40 >= 0 && GraphicChangeCounts % 40 <  10) MoveTexturePos = Point(6, 3);
		if (GraphicChangeCounts % 40 >= 10 && GraphicChangeCounts % 40 <  20) MoveTexturePos = Point(5, 3);
		if (GraphicChangeCounts % 40 >= 20 && GraphicChangeCounts % 40 <  30) MoveTexturePos = Point(4, 3);
		if (GraphicChangeCounts % 40 >= 30 && GraphicChangeCounts % 40 <  40) MoveTexturePos = Point(5, 3);

		task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior = true;
	}
	
}

void CPlayerMove::Up()
{
	if (CharacterController::UpMoveKey())
	{
		VelocitySpeed(Point(0, -speed.y));
		TexturePos = Point(1, 0);

		GraphicChangeCounts++;
		if (GraphicChangeCounts % 40 >= 0 && GraphicChangeCounts % 40 <  10) MoveTexturePos = Point(3, 0);
		if (GraphicChangeCounts % 40 >= 10 && GraphicChangeCounts % 40 <  20) MoveTexturePos = Point(3, 1);
		if (GraphicChangeCounts % 40 >= 20 && GraphicChangeCounts % 40 <  30) MoveTexturePos = Point(3, 2);
		if (GraphicChangeCounts % 40 >= 30 && GraphicChangeCounts % 40 <  40) MoveTexturePos = Point(3, 1);

		task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior = true;
	}
}

void CPlayerMove::Down()
{
	if (CharacterController::DownMoveKey())
	{
		VelocitySpeed(Point(0, speed.y));
		TexturePos = Point(1, 2);

		GraphicChangeCounts++;
		if (GraphicChangeCounts % 40 >= 0 && GraphicChangeCounts % 40 <  10) MoveTexturePos = Point(3, 6);
		if (GraphicChangeCounts % 40 >= 10 && GraphicChangeCounts % 40 <  20) MoveTexturePos = Point(3, 5);
		if (GraphicChangeCounts % 40 >= 20 && GraphicChangeCounts % 40 <  30) MoveTexturePos = Point(3, 4);
		if (GraphicChangeCounts % 40 >= 30 && GraphicChangeCounts % 40 <  40) MoveTexturePos = Point(3, 5);

		task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior = true;
	}
}

void CPlayerMove::RightUp()
{
	if (CharacterController::RightMoveKey() && CharacterController::UpMoveKey())
	{
		VelocitySpeed(Point(speed.x/2, -speed.y/2));
		TexturePos = Point(2, 0);

		GraphicChangeCounts++;
		if (GraphicChangeCounts % 40 >= 0 && GraphicChangeCounts % 40 <  10) MoveTexturePos = Point(6, 0);
		if (GraphicChangeCounts % 40 >= 10 && GraphicChangeCounts % 40 <  20) MoveTexturePos = Point(5, 1);
		if (GraphicChangeCounts % 40 >= 20 && GraphicChangeCounts % 40 <  30) MoveTexturePos = Point(4, 2);
		if (GraphicChangeCounts % 40 >= 30 && GraphicChangeCounts % 40 <  40) MoveTexturePos = Point(5, 1);

		task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior = true;
	}
}

void CPlayerMove::RightDown()
{
	if (CharacterController::RightMoveKey() && CharacterController::DownMoveKey())
	{
		VelocitySpeed(Point(speed.x/2, speed.y/2));
		TexturePos = Point(2, 2);

		GraphicChangeCounts++;
		if (GraphicChangeCounts % 40 >= 0 && GraphicChangeCounts % 40 <  10) MoveTexturePos = Point(6, 6);
		if (GraphicChangeCounts % 40 >= 10 && GraphicChangeCounts % 40 <  20) MoveTexturePos = Point(5, 5);
		if (GraphicChangeCounts % 40 >= 20 && GraphicChangeCounts % 40 <  30) MoveTexturePos = Point(4, 4);
		if (GraphicChangeCounts % 40 >= 30 && GraphicChangeCounts % 40 <  40) MoveTexturePos = Point(5, 5);

		task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior = true;
	}
}

void CPlayerMove::LeftUp()
{
	if (CharacterController::LeftMoveKey() && CharacterController::UpMoveKey())
	{
		VelocitySpeed(Point(-speed.x/2, -speed.y/2));
		TexturePos = Point(0, 0);

		GraphicChangeCounts++;
		if (GraphicChangeCounts % 40 >= 0 && GraphicChangeCounts % 40 <  10) MoveTexturePos = Point(0, 0);
		if (GraphicChangeCounts % 40 >= 10 && GraphicChangeCounts % 40 <  20) MoveTexturePos = Point(1, 1);
		if (GraphicChangeCounts % 40 >= 20 && GraphicChangeCounts % 40 <  30) MoveTexturePos = Point(2, 2);
		if (GraphicChangeCounts % 40 >= 30 && GraphicChangeCounts % 40 <  40) MoveTexturePos = Point(1, 1);

		task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior = true;
	}
}

void CPlayerMove::LeftDown()
{
	if (CharacterController::LeftMoveKey() && CharacterController::DownMoveKey())
	{
		VelocitySpeed(Point(-speed.x/2, speed.y/2));
		TexturePos = Point(0, 2);

		GraphicChangeCounts++;
		if (GraphicChangeCounts % 40 >= 0 && GraphicChangeCounts % 40 <  10) MoveTexturePos = Point(0, 6);
		if (GraphicChangeCounts % 40 >= 10 && GraphicChangeCounts % 40 <  20) MoveTexturePos = Point(1, 5);
		if (GraphicChangeCounts % 40 >= 20 && GraphicChangeCounts % 40 <  30) MoveTexturePos = Point(2, 4);
		if (GraphicChangeCounts % 40 >= 30 && GraphicChangeCounts % 40 <  40) MoveTexturePos = Point(1, 5);

		task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior = true;
	}
}

void CPlayerMove::Stop()
{
	if (!CharacterController::RightMoveKey() && !CharacterController::LeftMoveKey()
		&& !CharacterController::UpMoveKey() && !CharacterController::DownMoveKey())
	{
		VelocitySpeed(Point(0, 0));

		task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior = false;
	}
}
void CPlayerMove::WallCollision()
{
	auto player = task->GetComponent<CPlayer>(CGameManager::PlayerName, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());

	for (auto& floor : task->GetActor(CGameManager::WallName))
	{
		if (Collision::RectToRect(player->transform.GetPos(), player->transform.GetScale(),
			floor->transform.GetPos() - pos, floor->transform.GetScale()))
		{
			if (player->transform.GetPos().y > floor->transform.GetPos().y - pos.y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (floor->transform.GetPos().y - pos.y > player->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (player->transform.GetPos().x > floor->transform.GetPos().x - pos.x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (floor->transform.GetPos().x - pos.x > player->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
}
void CPlayerMove::Update()
{
	//if (state == State::None) return;
	
	Right(),
	Left();
	Up();
	Down();
	//RightUp();
	//RightDown();
	//LeftUp();
	//LeftDown();
	Stop();

	WallCollision();
		
	task->GetComponent<CMiniMapPlayer>(CGameManager::MiniPlayer, 0)->transform.Translate(Point(velocity.x / CMiniMap::MapScale, velocity.y / CMiniMap::MapScale));
	task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.Translate(velocity);
}
void CPlayerMove::Draw()
{
	auto player = task->GetComponent<CPlayer>(CGameManager::PlayerName, 0);
	auto player_atk = task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0);

	//Circle(player->transform.GetPos() + Point(64,128), 32).draw(ColorF(0,0,0,0.5));

	if (!CharacterController::RightMoveKey() && !CharacterController::LeftMoveKey()
		&& !CharacterController::UpMoveKey() && !CharacterController::DownMoveKey())
	{
		
	}
	//if (!task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isCollision)
	{
		if (CharacterController::RightMoveKey() || CharacterController::LeftMoveKey()
			|| CharacterController::UpMoveKey() || CharacterController::DownMoveKey())
		{
			Rect(player->transform.GetPos(), player->transform.GetScale())(TextureAsset(L"Walk")(TextureSize.x * MoveTexturePos.x, TextureSize.y * MoveTexturePos.y, TextureSize.x, TextureSize.y)).draw();
		}
		else if (CharacterController::AttackKey())
		{
			//Rect(player_atk->transform.GetPos(), player_atk->transform.GetScale())(TextureAsset(L"Attack")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw();
			Rect(player_atk->transform.GetPos(), player_atk->transform.GetScale())(TextureAsset(L"Attack_Efect")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw();
			Rect(player->transform.GetPos(), player->transform.GetScale())(TextureAsset(L"Attack")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw();
		}
		else if (CharacterController::AttackAnimation())
		{
			Rect(player->transform.GetPos(), player->transform.GetScale())(TextureAsset(L"Attack")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw();
			if (player_atk->isHit)
			{
				Rect(player->transform.GetPos(), player->transform.GetScale())(TextureAsset(L"Attack")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw(ColorF(Palette::Black));
			}
		}
		else
		{
			Rect(player->transform.GetPos(), player->transform.GetScale())(TextureAsset(L"TaChi")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw();
		}
	}
}