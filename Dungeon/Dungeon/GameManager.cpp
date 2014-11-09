#include "GameManager.h"
#include "GameApplication.h"
#include "Player.h"
#include "EnemyManager.h"
#include "Actor.h"
#include "MapRead.h"
#include "Floor.h"
#include "UpStairs.h"
#include "DownStairs.h"
#include "MiniMap.h"
#include "Scroll.h"
#include "MiniMapPlayer.h"
#include "Wall.h"

const std::string CGameManager::PlayerName = "player";
const std::string CGameManager::MiniPlayer = "MiniMapPlayer";
const std::string CGameManager::FloorName = "floor";
const std::string CGameManager::UpStairs = "up_stairs";
const std::string CGameManager::DownStairs = "down_stairs";
const std::string CGameManager::Scroll = "Scroll";
const std::string CGameManager::WallName = "wall";


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
	return (x * CMapRead::Size / CMiniMap::MapScale) + CGameApplication::ScreenWidth / 2 - (CMapRead::Width * CMapRead::Size / CMiniMap::MapScale) / 2;
}
int CGameManager::TransformMiniMapToScreenY(const int y)
{
	return (y * CMapRead::Size / CMiniMap::MapScale) + CGameApplication::ScreenHeight / 2 - (CMapRead::Height * CMapRead::Size / CMiniMap::MapScale) / 2;
}
void CGameManager::Init()
{
	state = State::Init;

	auto player = std::make_shared<CActor>();
	auto scroll = std::make_shared<CActor>();

	auto enemy_manager = std::make_shared<CActor>();

	auto wall = std::make_shared<CActor>();
	auto floor = std::make_shared<CActor>();
	auto up_stairs = std::make_shared<CActor>();
	auto down_stairs = std::make_shared<CActor>();
	auto mini_map = std::make_shared<CActor>();

	auto mini_map_player = std::make_shared<CActor>();

	for (int y = 0; y < CMapRead::Height; y++)
	{
		for (int x = 0; x < CMapRead::Width; x++)
		{
			///	壁
			map_read->ObjectRead(Point(x, y), CMapRead::Wall, wall, std::make_shared<CWall>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y))));
			///	部屋
			map_read->ObjectRead(Point(x, y), CMapRead::Room, floor, std::make_shared<CFloor>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y))));
			///	通路
			map_read->ObjectRead(Point(x, y), CMapRead::Corridor, floor, std::make_shared<CFloor>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y))));
			///	上り階段
			map_read->ObjectRead(Point(x, y), CMapRead::UpStairsPosition, up_stairs, std::make_shared<CUpStairs>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y))));
			///	下り階段
			map_read->ObjectRead(Point(x, y), CMapRead::DownStairsPosition , down_stairs, std::make_shared<CDownStairs>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y))));
			///	プレイヤーの位置
			map_read->ObjectRead(Point(x, y), CMapRead::PlayerPosition, player, std::make_shared<CPlayer>(task,
				Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2)));
			///	スクロール
			map_read->ObjectRead(Point(x, y), CMapRead::PlayerPosition, scroll, std::make_shared<CScroll>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y) - CMapRead::Size / 2)));
			///	ミニマップ
			///	プレイヤーの位置
			map_read->ObjectRead(Point(x, y), CMapRead::PlayerPosition, mini_map_player, std::make_shared<CMiniMapPlayer>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y))));
			///	部屋
			map_read->ObjectRead(Point(x, y), CMapRead::Room, mini_map, std::make_shared<CMiniMap>(task,
				Point(TransformMiniMapToScreenX(x), TransformMiniMapToScreenY(y))));
			///	通路
			map_read->ObjectRead(Point(x, y), CMapRead::Corridor, mini_map, std::make_shared<CMiniMap>(task,
				Point(TransformMiniMapToScreenX(x), TransformMiniMapToScreenY(y))));
		}
	}

	enemy_manager->Append(std::make_shared <CEnemyManager>(task));

	
	task->Append(Scroll, scroll);
	
	task->Append(FloorName, floor);
	task->Append(UpStairs, up_stairs);
	task->Append(DownStairs, down_stairs);
	task->Append(WallName, wall);
	task->Append(PlayerName, player);
	task->Append("enemy_manager", enemy_manager);

	task->Append(MiniPlayer, mini_map_player);
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
