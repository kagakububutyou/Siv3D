#include "GameManager.h"
#include "Player.h"
#include "EnemyManager.h"
#include "Actor.h"
#include "MapRead.h"
#include "Floor.h"
#include "Staircase.h"
#include "MiniMap.h"

const std::string CGameManager::PlayerName = "player";
const std::string CGameManager::FloorName = "floor";
const std::string CGameManager::Staircase = "staircase";


CGameManager::CGameManager(std::shared_ptr<CSceneManager> manager) :
CScene(manager),
task(std::make_shared<CTask>()),
map_read(std::make_unique<CMapRead>())
{

}
int CGameManager::TransformMapToScreenX(const int x)
{
	return x * CMapRead::Size;
}
int CGameManager::TransformMapToScreenY(const int y)
{
	return y * CMapRead::Size;
}
int CGameManager::TransformMiniMapToScreenX(const int x)
{
	return x * CMapRead::Size / CMiniMap::MapScale;
}
int CGameManager::TransformMiniMapToScreenY(const int y)
{
	return (y * CMapRead::Size / CMiniMap::MapScale) + CMiniMap::MapScale * 7 / 2;
}
void CGameManager::Init()
{
	state = State::Init;

	auto player = std::make_shared<CActor>();
	auto enemy_manager = std::make_shared<CActor>();

	auto floor = std::make_shared<CActor>();
	auto staircase = std::make_shared<CActor>();
	auto mini_map = std::make_shared<CActor>();

	for (int y = 0; y < CMapRead::Height; y++)
	{
		for (int x = 0; x < CMapRead::Width; x++)
		{
			map_read->ObjectRead(Point(x, y), CMapRead::Floor, floor, std::make_shared<CFloor>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y))));

			map_read->ObjectRead(Point(x, y), CMapRead::StaircasePosition, staircase, std::make_shared<CStaircase>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y))));

			map_read->ObjectRead(Point(x, y), CMapRead::PlayerPosition, player, std::make_shared<CPlayer>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y) - CMapRead::Size / 2)));

			map_read->ObjectRead(Point(x, y), CMapRead::Floor, mini_map, std::make_shared<CMiniMap>(task,
				Point(TransformMiniMapToScreenX(x), TransformMiniMapToScreenY(y))));
		}
	}

	enemy_manager->Append(std::make_shared <CEnemyManager>(task));

	
	
	task->Append(FloorName, floor);
	task->Append(Staircase, staircase);

	task->Append("enemy_manager", enemy_manager);
	task->Append(PlayerName, player);
	task->Append("mini_map", mini_map);


}

///	ゲーム本体のアップデート
void CGameManager::Update()
{
	if (state == State::Init)
	{
		task->Start();
		state = State::Update;
	}
	if (state == State::Update)
	{
		task->Update();
		task->Draw();
		task->Remove();
	}
}
