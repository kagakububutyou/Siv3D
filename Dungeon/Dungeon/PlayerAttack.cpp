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
isEnemy1(false),isEnemy2(false),isEnemy3(false),isEnemy4(false),
font(30),
ReadColor(false)
{

}
///	初期化
void CPlayerAttack::Start()
{
	TextureAsset::Register(L"huga", L"engine/data/texture/Character/MainCharacter/efect_damage.png");
	
	auto player = (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0));

	TransformPoint[KeyNum::left]		= Point(player->transform.GetPos().x - player->transform.GetScale().x, player->transform.GetPos().y);
	TransformPoint[KeyNum::right]		= Point(player->transform.GetPos().x + player->transform.GetScale().x, player->transform.GetPos().y);
	TransformPoint[KeyNum::up]		= Point(player->transform.GetPos().x, player->transform.GetPos().y - player->transform.GetScale().y);
	TransformPoint[KeyNum::down]	= Point(player->transform.GetPos().x, player->transform.GetPos().y + player->transform.GetScale().y);

	for (int i = 0; i < EnemyName::EnemyMax; i++)
	{
		isHits[i] = false;
	}
}
///	当たり判定の生成
void CPlayerAttack::Create()
{
	if (CharacterController::AttackKey())
	{
		isCollision = true;
		return;
	}
	isCollision = false;
}
///	当たり判定の場所
void CPlayerAttack::PushKey()
{
	
	KeyPressed[KeyNum::left]	= CharacterController::LeftMoveKey();
	KeyPressed[KeyNum::right]	= CharacterController::RightMoveKey();
	KeyPressed[KeyNum::up]		= CharacterController::UpMoveKey();
	KeyPressed[KeyNum::down]	= CharacterController::DownMoveKey();
	for (int i = 0; i < KeyNum::KeyMax; i++)
	{
		if (KeyPressed[i] == true)
		{
			transform.TransformPoint(TransformPoint[i]);
		}
	}
}
///	当たっているかどうか
void CPlayerAttack::OnCollision()
{
	auto player_pos = (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->transform.GetPos());
	auto player_scale = (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->transform.GetScale());

	auto patroller_pos = task->GetComponent<CPatrollerAttack>(CEnemyManager::PatrollerAttack, 0)->transform.GetPos();
	auto snake_copter_pos = task->GetComponent<CSnakeCopterAttack>(CEnemyManager::SnakeCopterAttack, 0)->transform.GetPos();
	auto tattered_id_pos = task->GetComponent<CTatteredIdAttack>(CEnemyManager::TatteredIdAttack, 0)->transform.GetPos();	
	auto battery_pos = task->GetComponent<CBatteryAttack>(CEnemyManager::BatteryAttack, 0)->transform.GetPos();

	auto patroller_scale = task->GetComponent<CPatrollerAttack>(CEnemyManager::PatrollerAttack, 0)->transform.GetScale();
	auto snake_copter_scale = task->GetComponent<CSnakeCopterAttack>(CEnemyManager::SnakeCopterAttack, 0)->transform.GetScale();
	auto tattered_id_scale = task->GetComponent<CTatteredIdAttack>(CEnemyManager::TatteredIdAttack, 0)->transform.GetScale();
	auto battery_scale = task->GetComponent<CBatteryAttack>(CEnemyManager::BatteryAttack, 0)->transform.GetScale();

	auto patroller_isCollision = task->GetComponent<CPatrollerAttack>(CEnemyManager::PatrollerAttack, 0)->isCollision;
	auto snake_copter_isCollision = task->GetComponent<CSnakeCopterAttack>(CEnemyManager::SnakeCopterAttack, 0)->isCollision;
	auto tattered_id_isCollision = task->GetComponent<CTatteredIdAttack>(CEnemyManager::TatteredIdAttack, 0)->isCollision;
	auto battery_isCollision = task->GetComponent<CBatteryAttack>(CEnemyManager::BatteryAttack, 0)->isCollision;

	Point pos[] = { patroller_pos, snake_copter_pos, tattered_id_pos, battery_pos };
	Point scale[] = { patroller_scale, snake_copter_scale, tattered_id_scale, battery_scale };
	bool Collision[] = { patroller_isCollision, snake_copter_isCollision, tattered_id_isCollision, battery_isCollision };

	for (int i = 0; i < EnemyName::EnemyMax; i++)
	{
		isHits[i] = false;
	}
	for (int i = 0; i < EnemyName::EnemyMax; i++)
	{
		if (Collision::RectToRect(player_pos, player_scale, pos[i], scale[i])
			&& Collision[i])
		{
			task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->HitAttack();
			isHits[i] = true;
			return;
		}
	}
}
///	アップデート
void CPlayerAttack::Update()
{
	PushKey();

	Create();
	OnCollision();
}
///	色設定
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
///	HPバーの表示
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
///	描画
void CPlayerAttack::Draw()
{
	ReadColors();
	DrawHpBar();
}