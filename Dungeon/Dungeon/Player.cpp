#include "Player.h"
#include "PlayerMove.h"
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
move(std::make_unique<CPlayerMove>(task))
{

}

void CPlayer::Start()
{

}

void CPlayer::Update()
{
	move->Update();
}

void CPlayer::Draw()
{

	for (int i = 0; i < task->GetSize(CGameManager::WallName); i++)
	{
		auto pos = task->GetComponent<CWall>(CGameManager::WallName, i)->transform.GetPos();
		auto size = task->GetComponent<CWall>(CGameManager::WallName, i)->transform.GetScale();

		if (Collision::RectToRect(transform.GetPos(), transform.GetScale(), pos, size))
		{
			Rect(transform.GetPos(), transform.GetScale()).draw(Palette::Yellow);
		}
		else
		{
			Rect(transform.GetPos(), transform.GetScale()).draw(Palette::Blue);
		}
	}
	

}