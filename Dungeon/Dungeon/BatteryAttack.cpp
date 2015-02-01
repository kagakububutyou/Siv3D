#include "MapRead.h"
#include "Scroll.h"
#include "GameApplication.h"
#include "BatteryAttack.h"
#include "CharacterController.h"
#include "Battery.h"
#include "GameManager.h"
#include "EnemyManager.h"
#include "BatteryMove.h"

#include "Player.h"
#include "PlayerAttack.h"

CBatteryAttack::CBatteryAttack(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos + Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2 - CMapRead::Size / 2), Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), State::Live),
isCollision(false)
{

}
void CBatteryAttack::Start()
{
	
}
void CBatteryAttack::PosUpdate()
{
	auto player = (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->transform.GetPos());
	auto scroll = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	auto battery_pos = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0)->transform.GetPos());
	auto battery_scale = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0)->transform.GetScale());

	AttackPos[MOVEDIREC::LEFT]		= Point(Point(battery_pos.x - battery_scale.x, battery_pos.y) - scroll);
	AttackPos[MOVEDIREC::RIGHT]	= Point(Point(battery_pos.x + battery_scale.x, battery_pos.y) - scroll);
	AttackPos[MOVEDIREC::UP]			= Point(Point(battery_pos.x, battery_pos.y - battery_scale.y) - scroll);
	AttackPos[MOVEDIREC::DOWN]	= Point(Point(battery_pos.x, battery_pos.y + battery_scale.y) - scroll);
}
void CBatteryAttack::Create()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto Battery = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0));
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());

	if (task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isCollision
		&&  task->GetComponent<CBattery>(CEnemyManager::Battery, 0)->GetState() != State::None)
	{
		isCollision = true;
		return;
	}
	isCollision = false;

}
///	ï˚å¸Çï‘Ç∑ä÷êî
CBatteryAttack::MOVEDIREC CBatteryAttack::Direc(Point player, Point scroll, Point enemy_pos, Point enemy_scale)
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
void CBatteryAttack::Position(MOVEDIREC direc)
{
	transform.TransformPoint(AttackPos[direc]);
}
void CBatteryAttack::Update()
{
	auto player = (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->transform.GetPos());
	auto scroll = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	auto battery_pos = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0)->transform.GetPos());
	auto battery_scale = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0)->transform.GetScale());

	PosUpdate();
	Position(Direc(player, scroll, battery_pos, battery_scale));

	Create();
}

void CBatteryAttack::Draw()
{

}