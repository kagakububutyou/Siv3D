#include "PatrollerMove.h"
#include "Patroller.h"
#include "EnemyManager.h"

#include "Player.h"
#include "PlayerAttack.h"
#include "GameManager.h"
#include "Scroll.h"
#include "Collision.h"
#include "MapRead.h"

#include "Transform.h"
#include "GameApplication.h"

CPatrollerMove::CPatrollerMove(std::shared_ptr<CTask> task) :
CPlayerState(task),
velocity(Point(0, 0)),
speed(Point(8.0f, 8.0f))
{

}

void CPatrollerMove::Start()
{
	MoveDirecData[MOVEDIREC::LEFT] = Point(-speed.x, 0);
	MoveDirecData[MOVEDIREC::RIGHT] = Point(speed.x, 0);
	MoveDirecData[MOVEDIREC::UP] = Point(0, -speed.y);
	MoveDirecData[MOVEDIREC::DOWN] = Point(0, speed.y);
}
///	�����𑬓x�ɑ��
void CPatrollerMove::VelocitySpeed(const Point speed)
{
	velocity = speed;
}
///	�~�߂�
void CPatrollerMove::Stop()
{
	auto player = (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->transform.GetPos());
	auto patroll = task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto Patroller = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0));

	if (!task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior
		&&!task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isCollision)
	{
		VelocitySpeed(Point(0, 0));
	}
}
///	�����ɓ����������̓������������߂�
void CPatrollerMove::CollisionMoveDirec(Point player, Point object)
{
	///	�R�����g�A�E�g�͏����Ȃ��悤�Ɂ@������
	int small[] = { player.x, object.x, player.y, object.y };
	int big[] = { object.x, player.x, object.y, player.y };
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
void CPatrollerMove::WallCollision()
{
	auto Patroller = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0));
	std::vector<std::shared_ptr<CActor>> walls[] = { task->GetActor(CGameManager::SwitchWall),
																		task->GetActor(CGameManager::SwitchWall1),
																		task->GetActor(CGameManager::SwitchWall2),
																		task->GetActor(CGameManager::SwitchWall3) };
	for (auto& floor : task->GetActor(CGameManager::WallName))
	{
		if (Collision::RectToRect(Patroller->transform.GetPos(), Patroller->transform.GetScale(),
			floor->transform.GetPos(), floor->transform.GetScale()))
		{
			CollisionMoveDirec(Patroller->transform.GetPos(), floor->transform.GetPos());
		}
	}
	for (int i = 0; i < CPlayerAttack::EnemyName::Max; i++)
	{
		for (auto& wall : walls[i])
		{
			if (Collision::RectToRect(Patroller->transform.GetPos(), Patroller->transform.GetScale(),
				wall->transform.GetPos(), wall->transform.GetScale())
				&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemys[i])
			{
				CollisionMoveDirec(Patroller->transform.GetPos(), wall->transform.GetPos());
			}
		}
	}
}
///	������Ԃ��֐�
CPatrollerMove::MOVEDIREC CPatrollerMove::Direc(Point player, Point scroll, Point enemy_pos, Point enemy_scale)
{
	int small[] = { player.x, enemy_pos.x + enemy_scale.x / 2 - scroll.x, player.y, enemy_pos.y + enemy_scale.y / 2 - scroll.y };
	int big[] = { enemy_pos.x - enemy_scale.x / 2 - scroll.x, player.x, enemy_pos.y - enemy_scale.y / 2 - scroll.y, player.y };
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
///	�����󂯎���ē�����
void CPatrollerMove::Move(MOVEDIREC direc)
{
	VelocitySpeed(MoveDirecData[direc]);
}
///	�X�V
void CPatrollerMove::Update()
{
	auto player = (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->transform.GetPos());
	auto scroll = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	auto patroller_pos = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0)->transform.GetPos());
	auto patroller_scale = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0)->transform.GetScale());

	Move(Direc(player, scroll, patroller_pos, patroller_scale));

	WallCollision();

	Stop();

	task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0)->transform.Translate(velocity);
}
///	�X�V
void CPatrollerMove::Draw()
{

}