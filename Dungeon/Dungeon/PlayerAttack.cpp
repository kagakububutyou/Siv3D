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
font(30),
ReadColor(false)
{

}
void CPlayerAttack::Start()
{
	TextureAsset::Register(L"huga", L"engine/data/texture/Character/MainCharacter/efect_damage.png");
	
	auto player = (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0));

	TransformPoint[KeyNum::left]		= Point(player->transform.GetPos().x - player->transform.GetScale().x, player->transform.GetPos().y);
	TransformPoint[KeyNum::right]		= Point(player->transform.GetPos().x + player->transform.GetScale().x, player->transform.GetPos().y);
	TransformPoint[KeyNum::up]		= Point(player->transform.GetPos().x, player->transform.GetPos().y - player->transform.GetScale().y);
	TransformPoint[KeyNum::down]	= Point(player->transform.GetPos().x, player->transform.GetPos().y + player->transform.GetScale().y);

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
void CPlayerAttack::PushKey()
{
	
	KeyPressed[KeyNum::left] = CharacterController::LeftMoveKey();
	KeyPressed[KeyNum::right] = CharacterController::RightMoveKey();
	KeyPressed[KeyNum::up] = CharacterController::UpMoveKey();
	KeyPressed[KeyNum::down] = CharacterController::DownMoveKey();
	for (int i = 0; i < KeyNum::KeyMax; i++)
	{
		if (KeyPressed[i] == true)
		{
			transform.TransformPoint(TransformPoint[i]);
		}
	}
}
void CPlayerAttack::OnCollision()
{
	auto player = (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0));
	auto patroller = task->GetComponent<CPatrollerAttack>(CEnemyManager::PatrollerAttack, 0);
	auto snake_copter = task->GetComponent<CSnakeCopterAttack>(CEnemyManager::SnakeCopterAttack, 0);
	auto tattered_id = task->GetComponent<CTatteredIdAttack>(CEnemyManager::TatteredIdAttack, 0);
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
	if (Collision::RectToRect(player->transform.GetPos(), player->transform.GetScale(), tattered_id->transform.GetPos(), tattered_id->transform.GetScale())
		&& tattered_id->isCollision)
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
	PushKey();

	Create();
	OnCollision();
}
void CPlayerAttack::ReadColors()
{
	if (ReadColor) return;

	Color[6] = ColorF(Palette::Purple, 0.5);
	Color[5] = ColorF(Palette::Indigo, 0.5);
	Color[4] = ColorF(Palette::Blue, 0.5);
	Color[3] = ColorF(Palette::Green, 0.5);
	Color[2] = ColorF(Palette::Yellow, 0.5);
	Color[1] = ColorF(Palette::Orange, 0.5);
	Color[0] = ColorF(Palette::Red, 0.5);

	ReadColor = true;

}
void CPlayerAttack::DrawHpBar()
{
	auto hp = task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->GetHP();
	auto maxHp = task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->GetMaxHP();

	font(L"E").drawCenter(Float2(10, 30), Palette::Black);

	for (int i = 0; i < ColorMax; i++)
	{
		if (hp > maxHp * i / 7)
		{
			Rect(30, 10, hp / 10, 40).draw(Color[i]);
		}
	}
}
void CPlayerAttack::Draw()
{
	ReadColors();
	DrawHpBar();
}