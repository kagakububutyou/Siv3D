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
#include "BatteryAttack.h"

#include "Scene.h"


CPlayerAttack::CPlayerAttack(std::shared_ptr<CTask> task) :
CActor(task, Transform(Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2), Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), state),
isCollision(false),
isHit(false),
font(30)
{

}
void CPlayerAttack::Start()
{
	TextureAsset::Register(L"huga", L"engine/data/texture/Character/MainCharacter/efect_damage.png");
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
	auto battery = task->GetComponent<CBatteryAttack>(CEnemyManager::BatteryAttack, 0);

	isHit = false;

	if (Collision::RectToRect(player->transform.GetPos(), player->transform.GetScale(), patroller->transform.GetPos(), patroller->transform.GetScale())
		&& patroller->isCollision)
	{
		player->HitAttack();
		isHit = true;
		return;
	}
	
	if (Collision::RectToRect(player->transform.GetPos(), player->transform.GetScale(), snake_copter->transform.GetPos(), snake_copter->transform.GetScale())
		&& snake_copter->isCollision)
	{
		player->HitAttack();
		isHit = true;
		return;
	}
	//*/
	if (Collision::RectToRect(player->transform.GetPos(), player->transform.GetScale(), battery->transform.GetPos(), battery->transform.GetScale())
		&& battery->isCollision)
	{
		player->HitAttack();
		isHit = true;
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
	//auto maxHp = task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->GetMaxHP();

	//auto HP = "HP";

	//font(CGameManager::Clear).draw();

	Rect(10, 10, hp * 10, 40).draw(ColorF(Palette::Blue, 0.5));

	if (isCollision)
	{
		//Rect(transform.GetPos(), transform.GetScale()).draw(ColorF(Palette::Blue,0.5));
	}
}