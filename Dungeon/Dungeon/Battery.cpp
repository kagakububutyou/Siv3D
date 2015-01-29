#include "Battery.h"
#include "BatteryAnimation.h"
#include "BatteryMove.h"
#include "BatteryAttack.h"
#include "MapRead.h"
#include "MiniMap.h"
#include "Scroll.h"
#include "GameManager.h"
#include "GameApplication.h"
#include "EnemyManager.h"

#include "Player.h"
#include "Collision.h"
#include "PlayerAttack.h"


CBattery::CBattery(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos + Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2 - CMapRead::Size / 2), Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), State::Live),
anime(std::make_unique<CBatteryAnimation>(task)),
move(std::make_unique<CBatteryMove>(task)),
isCollision(false),
HP(10)
{
}
///	‰‚ß‚ÉŒÄ‚ÔŠÖ”@‰Šú‰»Œn
void CBattery::Start()
{
	anime->Start();
	move->Start();
}
///	“–‚½‚è”»’è‚¾‚Æ‚¨‚à‚¤
void CBattery::OnCollision()
{
	auto atk = task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	auto Battery = task->GetComponent<CBattery>(CEnemyManager::Battery, 0);

	if (Collision::RectToRect(Battery->transform.GetPos() - pos, Battery->transform.GetScale(), atk->transform.GetPos(), atk->transform.GetScale())
		&& atk->isCollision)
	{
		Battery->HitAttack();
	}
	if (Battery->GetHP() <= 0)
	{
		state = State::None;
	}
	if (state == State::None)
	{
		atk->isEnemys[CPlayerAttack::EnemyName::Battery] = true;
	}
}
///	–ˆƒtƒŒ[ƒ€ŒÄ‚ÔŠÖ”@XV‚ª•K—v‚ÈŠÖ”
void CBattery::Update()
{
	if (state != State::None)
	{
		anime->Update();
		move->Update();
		attack->Update();
	}

	OnCollision();
}
///	•`‰æŠÖŒW‚ÌŠÖ”@•`‰æ‚µ‚½‚¢“z‚Í‚±‚±‚Ö
void CBattery::Draw()
{
	if (state != State::None)
	{
		move->Draw();
		anime->Draw();
		attack->Draw();
	}
}