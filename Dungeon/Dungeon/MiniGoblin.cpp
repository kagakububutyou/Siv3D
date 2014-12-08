#include "MiniGoblin.h"
#include "MapRead.h"
#include "MiniMap.h"
#include "Scroll.h"
#include "GameManager.h"
#include "GameApplication.h"

#include "Player.h"


CMiniGoblin::CMiniGoblin(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos, Point(CMapRead::Size / CMiniMap::MapScale, CMapRead::Size / CMiniMap::MapScale), Point(0, 0)), State::Live)
{
}

void CMiniGoblin::Start()
{
	//transform.TransformPoint(Point(transform.GetPos().x / CMiniMap::MapScale + CGameApplication::ScreenWidth / 2 - (CMapRead::Width * CMapRead::Size / CMiniMap::MapScale) / 2,
	//transform.GetPos().y / CMiniMap::MapScale + CGameApplication::ScreenHeight / 2 - (CMapRead::Height * CMapRead::Size / CMiniMap::MapScale) / 2 - (CMapRead::Size / CMiniMap::MapScale) * 7 / 2));
}

void CMiniGoblin::Update()
{

}

void CMiniGoblin::Draw()
{
	auto pos = (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->transform.GetPos());
	
	auto DisplayMiniMap = task->GetComponent<CMiniMap>("mini_map", 0)->DisplayMiniMap;
	if (DisplayMiniMap)
	{
		//Rect(transform.GetPos(), transform.GetScale()).draw(ColorF(0, 255, 0));
	}
}