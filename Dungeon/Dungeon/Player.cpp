#include "Player.h"
#include "PlayerMove.h"
#include "PlayerAttack.h"
#include "MapRead.h"
#include "MiniMap.h"
#include "GameApplication.h"
#include "MiniMapPlayer.h"
#include "GameManager.h"

#include "Collision.h"
#include "MiniGoblin.h"
#include "EnemyManager.h"
#include "Wall.h"
#include "Scroll.h"

CPlayer::CPlayer(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos, Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), State::Live),
move(std::make_unique<CPlayerMove>(task)),
attack(std::make_unique<CPlayerAttack>(task)),
behavior(false),
MaxHP(3000),
HP(3000)
{

}

void CPlayer::Start()
{
	move->Start();
}

void CPlayer::Update()
{
	move->Update();
	attack->Update();
}

void CPlayer::Draw()
{
	move->Draw();
	attack->Draw();
}

/*		
		13:30～

		持ち時間
		10分セッティング含めて




*/