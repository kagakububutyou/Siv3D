#include "BatteryMove.h"
#include "Battery.h"
#include "EnemyManager.h"

#include "Player.h"
#include "PlayerAttack.h"
#include "GameManager.h"
#include "Scroll.h"
#include "Collision.h"
#include "MapRead.h"

#include "Transform.h"
#include "GameApplication.h"

CBatteryMove::CBatteryMove(std::shared_ptr<CTask> task) :
CPlayerState(task),
velocity(Point(0, 0)),
speed(Point(8.0f, 8.0f))
{

}

void CBatteryMove::Start()
{
	MoveDirecData[MOVEDIREC::LEFT] = Point(-speed.x, 0);
	MoveDirecData[MOVEDIREC::RIGHT] = Point(speed.x, 0);
	MoveDirecData[MOVEDIREC::UP] = Point(0, -speed.y);
	MoveDirecData[MOVEDIREC::DOWN] = Point(0, speed.y);
}
///	速さを速度に代入
void CBatteryMove::VelocitySpeed(const Point speed)
{
	velocity = speed;
}
///	止める
void CBatteryMove::Stop()
{
	auto player = (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->transform.GetPos());
	auto patroll = task->GetComponent<CBattery>(CEnemyManager::Battery, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto Battery = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0));

	if (!task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior
		&&!task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isCollision)
	{
		VelocitySpeed(Point(0, 0));
	}
}
///	何かに当たった時の動く方向を決める
void CBatteryMove::CollisionMoveDirec(Point player, Point object)
{
	///	コメントアウトは消さないように　調整中
	int small[] = { player.x, object.x, player.y, object.y};
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
///	壁との当たり判定
void CBatteryMove::WallCollision()
{
	auto Battery = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0));
	std::vector<std::shared_ptr<CActor>> walls[] = { task->GetActor(CGameManager::SwitchWall),
																		task->GetActor(CGameManager::SwitchWall1),
																		task->GetActor(CGameManager::SwitchWall2),
																		task->GetActor(CGameManager::SwitchWall3) };
	for (auto& floor : task->GetActor(CGameManager::WallName))
	{
		if (Collision::RectToRect(Battery->transform.GetPos(), Battery->transform.GetScale(),
			floor->transform.GetPos(), floor->transform.GetScale()))
		{
			CollisionMoveDirec(Battery->transform.GetPos(), floor->transform.GetPos());
		}
	}
	for (int i = 0; i < CPlayerAttack::EnemyName::Max; i++)
	{
		for (auto& wall : walls[i])
		{
			if (Collision::RectToRect(Battery->transform.GetPos(), Battery->transform.GetScale(),
				wall->transform.GetPos(), wall->transform.GetScale())
				&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemys[i])
			{
				CollisionMoveDirec(Battery->transform.GetPos(), wall->transform.GetPos());
			}
		}
	}
}
///	方向を返す関数
CBatteryMove::MOVEDIREC CBatteryMove::Direc(Point player, Point scroll, Point enemy_pos, Point enemy_scale)
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
///	方向受け取って動かす
void CBatteryMove::Move(MOVEDIREC direc)
{
	VelocitySpeed(MoveDirecData[direc]);
}
///	更新
void CBatteryMove::Update()
{
	auto player = (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->transform.GetPos());
	auto scroll = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	auto battery_pos = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0)->transform.GetPos());
	auto battery_scale = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0)->transform.GetScale());

	Move(Direc(player, scroll, battery_pos, battery_scale));

	WallCollision();

	Stop();

	task->GetComponent<CBattery>(CEnemyManager::Battery, 0)->transform.Translate(velocity);
}
///	更新
void CBatteryMove::Draw()
{

}