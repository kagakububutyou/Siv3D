#include "MapRead.h"
#include "Scroll.h"
#include "GameApplication.h"
#include "PlayerAttack.h"
#include "CharacterController.h"
#include "Player.h"
#include "GameManager.h"
#include "PlayerMove.h"
#include "Collision.h"

#include "EnemyManager.h"
#include "PatrollerAttack.h"
#include "SnakeCopterAttack.h"
#include "TatteredIdAttack.h"
#include "BatteryAttack.h"

#include "Scene.h"


CPlayerAttack::CPlayerAttack(std::shared_ptr<CTask> task) :
CActor(task, Transform(Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2), Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), state),
isCollision(false),
isHit1(false), isHit2(false), isHit3(false), isHit4(false),
isEnemy1(false),isEnemy2(false),isEnemy3(false),isEnemy4(false),
font(30)
{

}
void CPlayerAttack::Start()
{
	TextureAsset::Register(L"huga", L"engine/data/texture/Character/MainCharacter/efect_damage.png");

	Color[6] = Palette::Purple, 0.5;
	Color[5] = Palette::Indigo, 0.5;
	Color[4] = Palette::Blue, 0.5;
	Color[3] = Palette::Green, 0.5;
	Color[2] = Palette::Yellow, 0.5;
	Color[1] = Palette::Orange, 0.5;
	Color[0] = Palette::Red, 0.5;

}
void CPlayerAttack::Create()
{
	if (CharacterController::AttackKey())
	{
		isCollision = true;
		return;
	}
	isCollision = false;
}
void CPlayerAttack::Left()
{
	auto player = (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0));

	if (CharacterController::LeftMoveKey())
	{
		transform.TransformPoint(Point(player->transform.GetPos().x - player->transform.GetScale().x, player->transform.GetPos().y));
	}
}
void CPlayerAttack::Right()
{
	auto player = (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0));

	if (CharacterController::RightMoveKey())
	{
		transform.TransformPoint(Point(player->transform.GetPos().x + player->transform.GetScale().x, player->transform.GetPos().y));
	}
}
void CPlayerAttack::Up()
{
	auto player = (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0));

	if (CharacterController::UpMoveKey())
	{
		transform.TransformPoint(Point(player->transform.GetPos().x, player->transform.GetPos().y - player->transform.GetScale().y));
	}
}
void CPlayerAttack::Down()
{
	auto player = (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0));

	if (CharacterController::DownMoveKey())
	{
		transform.TransformPoint(Point(player->transform.GetPos().x, player->transform.GetPos().y + player->transform.GetScale().y));
	}
}
void CPlayerAttack::OnCollision()
{
	auto player = (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0));
	auto patroller = task->GetComponent<CPatrollerAttack>(CEnemyManager::PatrollerAttack, 0);
	auto snake_copter = task->GetComponent<CSnakeCopterAttack>(CEnemyManager::SnakeCopterAttack, 0);
	auto snake_copter1 = task->GetComponent<CTatteredIdAttack>(CEnemyManager::TatteredIdAttack, 0);
	auto battery = task->GetComponent<CBatteryAttack>(CEnemyManager::BatteryAttack, 0);

	isHit1 = false; isHit2 = false; isHit3 = false; isHit4 = false;

	if (Collision::RectToRect(player->transform.GetPos(), player->transform.GetScale(), patroller->transform.GetPos(), patroller->transform.GetScale())
		&& patroller->isCollision)
	{
		player->HitAttack();
		isHit1 = true;
		return;
	}
	
	if (Collision::RectToRect(player->transform.GetPos(), player->transform.GetScale(), snake_copter->transform.GetPos(), snake_copter->transform.GetScale())
		&& snake_copter->isCollision)
	{
		player->HitAttack();
		isHit2 = true;
		return;
	}
	if (Collision::RectToRect(player->transform.GetPos(), player->transform.GetScale(), snake_copter1->transform.GetPos(), snake_copter1->transform.GetScale())
		&& snake_copter1->isCollision)
	{
		player->HitAttack();
		isHit3 = true;
		return;
	}
	//*/
	if (Collision::RectToRect(player->transform.GetPos(), player->transform.GetScale(), battery->transform.GetPos(), battery->transform.GetScale())
		&& battery->isCollision)
	{
		player->HitAttack();
		isHit4 = true;
		return;
	}
}
void CPlayerAttack::Update()
{
	Left();
	Right();
	Up();
	Down();

	Create();
	OnCollision();
}

void CPlayerAttack::Draw()
{
	auto hp = task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->GetHP();
	auto maxHp = task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->GetMaxHP();

	//auto HP = "HP";

	//font(hp).draw();
	//Logo->drawCenter(L"E", Float2(0, 10), Palette::Red);

	font(L"E").drawCenter(Float2(10, 30), Palette::Black);

	for (int i = 0; i < ColorMax; i++)
	{
		if (hp > maxHp * i / 7)
		{
			Rect(30, 10, hp / 10, 40).draw(Color[i]);
		}
	}
	/*
	if (hp > maxHp * 6 / 7)
	{
		Rect(30, 10, hp / 10, 40).draw(Color[6]);
	}
	else if (hp > maxHp * 5 / 7)
	{
		Rect(30, 10, hp / 10, 40).draw(ColorF(Palette::Indigo, 0.5));
	}
	else if (hp > maxHp * 4 / 7)
	{
		Rect(30, 10, hp / 10, 40).draw(ColorF(Palette::Blue, 0.5));
	}
	else if (hp > maxHp * 3 / 7)
	{
		Rect(30, 10, hp / 10, 40).draw(ColorF(Palette::Green, 0.5));
	}
	else if (hp > maxHp * 2 / 7)
	{
		Rect(30, 10, hp / 10, 40).draw(ColorF(Palette::Yellow, 0.5));
	}
	else if (hp > maxHp * 1 / 7)
	{
		Rect(30, 10, hp / 10, 40).draw(ColorF(Palette::Orange, 0.5));
	}
	else if (hp > maxHp * 0 / 7)
	{
		Rect(30, 10, hp / 10, 40).draw(ColorF(Palette::Red, 0.5));
	}
	//*/
	if (isCollision)
	{
		//Rect(transform.GetPos(), transform.GetScale()).draw(ColorF(Palette::Blue,0.5));
	}
}