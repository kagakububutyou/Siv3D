#include "Player.h"
#include "PlayerMove.h"
#include "MapRead.h"
#include "MiniMap.h"
#include "GameApplication.h"
#include "MiniMapPlayer.h"
#include "GameManager.h"

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

	if (task->GetComponent<CMiniMapPlayer>(CGameManager::MiniPlayer, 0)->OnCollision)
	{
		Rect(transform.GetPos(), transform.GetScale()).draw(Palette::Yellow);
	}
	else
	{
		Rect(transform.GetPos(), transform.GetScale()).draw(Palette::Blue);
	}
	

}