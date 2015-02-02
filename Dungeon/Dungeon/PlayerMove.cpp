#include "PlayerMove.h"
#include "CharacterController.h"
#include "Player.h"
#include "GameManager.h"
#include "Scroll.h"
#include "MiniMap.h"
#include "MiniMapPlayer.h"

#include "Collision.h"

#include "Patroller.h"
#include "SnakeCopter.h"
#include "TatteredId.h"
#include "Battery.h"
#include "EnemyManager.h"

#include "PlayerAttack.h"


/*
	����̗\��
	�����蔻��Ɠ����̕���
*/
CPlayerMove::CPlayerMove(std::shared_ptr<CTask> task) :
CPlayerState(task),
state(State::Live),
velocity(Point(0, 0)),
speed(Point(16.0f, 16.0f))
{

}
///	���߂ɌĂԊ֐��@�������n
void CPlayerMove::Start()
{
	MoveDirecData[MOVEDIREC::LEFT] = Point(-speed.x, 0);
	MoveDirecData[MOVEDIREC::RIGHT] = Point(speed.x, 0);
	MoveDirecData[MOVEDIREC::UP] = Point(0, -speed.y);
	MoveDirecData[MOVEDIREC::DOWN] = Point(0, speed.y);

}
///	�����̊Ǘ��@�X�s�[�h����
void CPlayerMove::VelocitySpeed(const Point speed)
{
	velocity = speed;
}
///	�����L�[�������ꂽ���@�ύX�\��
void CPlayerMove::Left()
{
	if (CharacterController::LeftMoveKey())
	{
		Move(MOVEDIREC::LEFT);
	}
}
void CPlayerMove::Right()
{
	if (CharacterController::RightMoveKey())
	{
		Move(MOVEDIREC::RIGHT);
	}
}
void CPlayerMove::Up()
{
	if (CharacterController::UpMoveKey())
	{
		Move(MOVEDIREC::UP);
	}
}
void CPlayerMove::Down()
{
	if (CharacterController::DownMoveKey())
	{
		Move(MOVEDIREC::DOWN);
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
///	�ǂ����ɓ������̊֐��@�����ŕ�����������ăX�s�[�h�ɓn��
void CPlayerMove::Move(MOVEDIREC direc)
{
	VelocitySpeed(MoveDirecData[direc]);

	task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior = true;
	task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->HitAttack();
}
///	����������Ԃ��@�m�b�N�o�b�N�ł����g���Ă��Ȃ�
CPlayerMove::MOVEDIREC CPlayerMove::MoveDirec(const Point &player, Point object, Point scroll)
{
	int small[] = { player.x, object.x - scroll.x, player.y, object.y - scroll.y };
	int big[] = { object.x - scroll.x, player.x, object.y - scroll.y, player.y };
	MOVEDIREC direc[] = { MOVEDIREC::LEFT, MOVEDIREC::RIGHT, MOVEDIREC::UP, MOVEDIREC::DOWN };

	for (int i = 0; i < MOVEDIREC::DIREC; i++)
	{
		if (small[i] < big[i])
		{
			return direc[i];
		}
	}
	return MOVEDIREC::DOWN;
}
///	�����ɓ����������̓������������߂�
void CPlayerMove::CollisionMoveDirec(Point player, Point object, Point scroll)
{
	///	�R�����g�A�E�g�͏����Ȃ��悤�Ɂ@������
	int small[] = { player.x, object.x - scroll.x, player.y, object.y - scroll.y };
	int big[] = { object.x - scroll.x, player.x, object.y - scroll.y, player.y };
	//MOVEDIREC direc[] = { MOVEDIREC::RIGHT, MOVEDIREC::LEFT, MOVEDIREC::DOWN, MOVEDIREC::UP};
	Point direc[] = { Point(-speed.x, 0), Point(speed.x, 0), Point(0, -speed.y), Point(0, speed.y) };
	for (int i = 0; i < MOVEDIREC::DIREC; i++)
	{
		if (small[i] < big[i])
		{
			VelocitySpeed(direc[i]);
			//return direc[i];
		}
	}
	//return MOVEDIREC::DOWN;
}
///	�ǂƂ̓����蔻��
void CPlayerMove::WallCollision()
{
	auto player = task->GetComponent<CPlayer>(CGameManager::PlayerName, 0);
	auto scroll = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	std::vector<std::shared_ptr<CActor>> walls[]	= {	task->GetActor(CGameManager::SwitchWall),
																		task->GetActor(CGameManager::SwitchWall1),
																		task->GetActor(CGameManager::SwitchWall2),
																		task->GetActor(CGameManager::SwitchWall3) };

	for (auto& floor : task->GetActor(CGameManager::WallName))
	{
		if (Collision::RectToRect(player->transform.GetPos(), player->transform.GetScale(),
			floor->transform.GetPos() - scroll, floor->transform.GetScale()))
		{
			CollisionMoveDirec(player->transform.GetPos(), floor->transform.GetPos(), scroll);
		}
	}
	for (int i = 0; i < CPlayerAttack::EnemyName::Max; i++)
	{
		for (auto& wall : walls[i])
		{
			if (Collision::RectToRect(player->transform.GetPos(), player->transform.GetScale(),
				wall->transform.GetPos() - scroll, wall->transform.GetScale())
				&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemys[i])
			{
				CollisionMoveDirec(player->transform.GetPos(), wall->transform.GetPos(), scroll);
			}
		}
	}
}
///	�I�ɍU�����ꂽ���̃m�b�N�o�b�N
void CPlayerMove::knockBack()
{
	auto player = task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->transform.GetPos();
	auto scroll = task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos();
	auto patroller = task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0)->transform.GetPos();
	auto s = task->GetComponent<CSnakeCopter>(CEnemyManager::SnakeCopter, 0)->transform.GetPos();
	auto t = task->GetComponent<CTatteredId>(CEnemyManager::TatteredId, 0)->transform.GetPos();
	auto b = task->GetComponent<CBattery>(CEnemyManager::Battery, 0)->transform.GetPos();

	Point enemy[] = { patroller, s, t, b };
	for (int i = 0; i < EnemyName::Max; i++)
	{
		if (task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isHits[i])
		{
			Move(MoveDirec(player, enemy[i], scroll));
		}
	}
}
///	�G�Ƃ̓����蔻��@���܂������Ȃ��̂ŏ������ĂȂ�
void CPlayerMove::EnemyCollision()
{
	auto player = task->GetComponent<CPlayer>(CGameManager::PlayerName, 0);
	auto scroll = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	///*
	std::vector<std::shared_ptr<CActor>> enemys[]	= { task->GetActor(CEnemyManager::Patroller) ,
																			 task->GetActor(CEnemyManager::SnakeCopter) ,
																			 task->GetActor(CEnemyManager::TatteredId),
																			 task->GetActor(CEnemyManager::Battery)};
																			 //*/

	for (int i = 0; i < CPlayerAttack::EnemyName::Max; i++)
	{
		for (auto& enemy : enemys[i])
		{
			if (Collision::RectToRect(player->transform.GetPos(), player->transform.GetScale(),
				enemy->transform.GetPos() - scroll, enemy->transform.GetScale())
				&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemys[i])
			{
				CollisionMoveDirec(player->transform.GetPos(), enemy->transform.GetPos(), scroll);
			}
		}
	}
}
///	���t���[���ĂԊ֐��@�X�V���K�v�Ȋ֐�
void CPlayerMove::Update()
{
	
	Right(),
	Left();
	Up();
	Down();

	Stop();

	WallCollision();
	//EnemyCollision();
	knockBack();
		
	task->GetComponent<CMiniMapPlayer>(CGameManager::MiniPlayer, 0)->transform.Translate(Point(velocity.x / CMiniMap::MapScale, velocity.y / CMiniMap::MapScale));
	task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.Translate(velocity);
}
///	�`��֌W�̊֐��@�`�悵�����z�͂�����
void CPlayerMove::Draw()
{
	///	�`�悷����͖̂���
}