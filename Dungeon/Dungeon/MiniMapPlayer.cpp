#include "MiniMapPlayer.h"
#include "PlayerMove.h"
#include "MapRead.h"
#include "MiniMap.h"
#include "GameApplication.h"

#include "Collision.h"
#include "MiniGoblin.h"
#include "EnemyManager.h"
#include "GameManager.h"
#include "Player.h"

CMiniMapPlayer::CMiniMapPlayer(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos, Point(CMapRead::Size / CMiniMap::MapScale, CMapRead::Size / CMiniMap::MapScale), Point(0, 0)), State::Live),
move(std::make_unique<CPlayerMove>(task))
{

}

void CMiniMapPlayer::Start()
{

	transform.TransformPoint(Point(transform.GetPos().x / CMiniMap::MapScale + CGameApplication::ScreenWidth / 2 - (CMapRead::Width * CMapRead::Size / CMiniMap::MapScale) / 2,
		transform.GetPos().y / CMiniMap::MapScale + CGameApplication::ScreenHeight / 2 - (CMapRead::Height * CMapRead::Size / CMiniMap::MapScale) / 2 - (CMapRead::Size / CMiniMap::MapScale) * 4));
	//*/
}

void CMiniMapPlayer::Update()
{
	move->Update();
}

void CMiniMapPlayer::Draw()
{
	auto MiniGoblin = task->GetComponent<CMiniGoblin>(CEnemyManager::MiniGoblin, 0);
	auto DisplayMiniMap = task->GetComponent<CMiniMap>("mini_map", 0)->DisplayMiniMap;
	if (DisplayMiniMap)
	{
		Rect(transform.GetPos(), transform.GetScale()).draw(Palette::Blue);
	}

	


}