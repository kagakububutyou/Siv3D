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
#include "PlayerAttack.h"
#include "SwitchWall.h"
#include "SwitchWall1.h"
#include "SwitchWall2.h"
#include "SwitchWall3.h"
#include "MiniSwitchWall.h"
#include "MiniSwitchWall1.h"
#include "MiniSwitchWall2.h"
#include "MiniSwitchWall3.h"

const std::string CGameManager::PlayerName = "player";
const std::string CGameManager::MiniPlayer = "MiniMapPlayer";
const std::string CGameManager::EnemyManager = "enemy_manager";
const std::string CGameManager::FloorName = "floor";
const std::string CGameManager::UpStairs = "up_stairs";
const std::string CGameManager::DownStairs = "down_stairs";
const std::string CGameManager::Scroll = "Scroll";
const std::string CGameManager::WallName = "wall";
const std::string CGameManager::SwitchWall = "SwitchWall";
const std::string CGameManager::SwitchWall1 = "SwitchWall1";
const std::string CGameManager::SwitchWall2 = "SwitchWall2";
const std::string CGameManager::SwitchWall3 = "SwitchWall3";
const std::string CGameManager::Attack = "Attack";
bool CGameManager::Clear = false;
bool CGameManager::Bat = false;


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

	TextureAsset::Register(L"hoge", L"engine/data/texture/Character/Etc/kumori.png");

	auto player = std::make_shared<CActor>();
	auto atk = std::make_shared<CActor>();
	auto scroll = std::make_shared<CActor>();

	auto enemy_manager = std::make_shared<CActor>();

	auto wall = std::make_shared<CActor>();
	auto floor = std::make_shared<CActor>();
	auto up_stairs = std::make_shared<CActor>();
	auto down_stairs = std::make_shared<CActor>();
	auto mini_map = std::make_shared<CActor>();
	auto switch_wall = std::make_shared<CActor>();
	auto switch_wall1 = std::make_shared<CActor>();
	auto switch_wall2 = std::make_shared<CActor>();
	auto switch_wall3 = std::make_shared<CActor>();
	auto mini_switch = std::make_shared<CActor>();
	auto mini_switch1 = std::make_shared<CActor>();
	auto mini_switch2 = std::make_shared<CActor>();
	auto mini_switch3 = std::make_shared<CActor>();
	

	auto mini_map_player = std::make_shared<CActor>();

	for (int y = 0; y < CMapRead::Height; y++)
	{
		for (int x = 0; x < CMapRead::Width; x++)
		{
			///	壁
			/*map_read->ObjectRead(Point(x, y), CMapRead::Wall, wall, std::make_shared<CWall>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y))));*/
			map_read->ObjectRead(Point(x, y), 0, wall, std::make_shared<CWall>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y))));
			///	部屋
			map_read->ObjectRead(Point(x, y), CMapRead::Room, floor, std::make_shared<CFloor>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y))));
			map_read->ObjectRead(Point(x, y), CMapRead::Wall, floor, std::make_shared<CFloor>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y))));
			map_read->ObjectRead(Point(x, y), CEnemyManager::PatrollerPosition, floor, std::make_shared<CFloor>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y))));
			map_read->ObjectRead(Point(x, y), CEnemyManager::SnakeCopterPosition, floor, std::make_shared<CFloor>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y))));
			map_read->ObjectRead(Point(x, y), CEnemyManager::TatteredIdPosition, floor, std::make_shared<CFloor>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y))));
			map_read->ObjectRead(Point(x, y), CEnemyManager::BatteryPosition, floor, std::make_shared<CFloor>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y))));
			map_read->ObjectRead(Point(x, y), CMapRead::DownStairsPosition, floor, std::make_shared<CFloor>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y))));
			map_read->ObjectRead(Point(x, y), CMapRead::SwitchWallPosition, switch_wall, std::make_shared<CSwitchWall>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y))));
			map_read->ObjectRead(Point(x, y), CMapRead::SwitchWall1Position, switch_wall1, std::make_shared<CSwitchWall1>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y))));
			map_read->ObjectRead(Point(x, y), CMapRead::SwitchWall2Position, switch_wall2, std::make_shared<CSwitchWall2>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y))));
			map_read->ObjectRead(Point(x, y), CMapRead::SwitchWall3Position, switch_wall3, std::make_shared<CSwitchWall3>(task,
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
			map_read->ObjectRead(Point(x, y), CMapRead::Wall, mini_map, std::make_shared<CMiniMap>(task,
				Point(TransformMiniMapToScreenX(x), TransformMiniMapToScreenY(y))));
			///	通路
			map_read->ObjectRead(Point(x, y), CMapRead::Corridor, mini_map, std::make_shared<CMiniMap>(task,
				Point(TransformMiniMapToScreenX(x), TransformMiniMapToScreenY(y))));
			map_read->ObjectRead(Point(x, y), CMapRead::SwitchWallPosition, mini_switch, std::make_shared<CMiniSwitchWall>(task,
				Point(TransformMiniMapToScreenX(x), TransformMiniMapToScreenY(y))));
			map_read->ObjectRead(Point(x, y), CMapRead::SwitchWall1Position, mini_switch1, std::make_shared<CMiniSwitchWall1>(task,
				Point(TransformMiniMapToScreenX(x), TransformMiniMapToScreenY(y))));
			map_read->ObjectRead(Point(x, y), CMapRead::SwitchWall2Position, mini_switch2, std::make_shared<CMiniSwitchWall2>(task,
				Point(TransformMiniMapToScreenX(x), TransformMiniMapToScreenY(y))));
			map_read->ObjectRead(Point(x, y), CMapRead::SwitchWall3Position, mini_switch3, std::make_shared<CMiniSwitchWall3>(task,
				Point(TransformMiniMapToScreenX(x), TransformMiniMapToScreenY(y))));
			///	階段
			map_read->ObjectRead(Point(x, y), CMapRead::DownStairsPosition, mini_map, std::make_shared<CMiniMap>(task,
				Point(TransformMiniMapToScreenX(x), TransformMiniMapToScreenY(y))));
			map_read->ObjectRead(Point(x, y), CMapRead::UpStairsPosition, mini_map, std::make_shared<CMiniMap>(task,
				Point(TransformMiniMapToScreenX(x), TransformMiniMapToScreenY(y))));
			
			///	敵
			map_read->ObjectRead(Point(x, y), CEnemyManager::PatrollerPosition, mini_map, std::make_shared<CMiniMap>(task,
				Point(TransformMiniMapToScreenX(x), TransformMiniMapToScreenY(y))));
			map_read->ObjectRead(Point(x, y), CEnemyManager::SnakeCopterPosition, mini_map, std::make_shared<CMiniMap>(task,
				Point(TransformMiniMapToScreenX(x), TransformMiniMapToScreenY(y))));
			map_read->ObjectRead(Point(x, y), CEnemyManager::BatteryPosition, mini_map, std::make_shared<CMiniMap>(task,
				Point(TransformMiniMapToScreenX(x), TransformMiniMapToScreenY(y))));
			map_read->ObjectRead(Point(x, y), CEnemyManager::TatteredIdPosition, mini_map, std::make_shared<CMiniMap>(task,
				Point(TransformMiniMapToScreenX(x), TransformMiniMapToScreenY(y))));
		}
	}

	enemy_manager->Append(std::make_shared <CEnemyManager>(task));
	atk->Append(std::make_shared<CPlayerAttack>(task));
	
	task->Append(Scroll, scroll);
	
	

	task->Append(FloorName, floor);
	task->Append(UpStairs, up_stairs);
	task->Append(DownStairs, down_stairs);
	task->Append(WallName, wall);
	task->Append(SwitchWall, switch_wall);
	task->Append(SwitchWall1, switch_wall1);
	task->Append(SwitchWall2, switch_wall2);
	task->Append(SwitchWall3, switch_wall3);
	task->Append(PlayerName, player);
	task->Append(EnemyManager, enemy_manager);

	task->Append(MiniPlayer, mini_map_player);
	task->Append("mini_map", mini_map);
	task->Append("mini_switch", mini_switch);
	task->Append("mini_switch1", mini_switch1);
	task->Append("mini_switch2", mini_switch2);
	task->Append("mini_switch3", mini_switch3);

	task->Append(Attack, atk);

}
void CGameManager::GameOver()
{
	//if (task->GetComponent<CPlayer>(CGameManager::PlayerName,0)->GetHP() < 0)
	if (Input::KeyD.clicked)
	{
		//scene->ChangeScene(CSceneManager::Scene::Over);
	}
}
void CGameManager::GameClear()
{
	if (CGameManager::Clear)
	{
		state = State::Clear;

		scene->ChangeScene(CSceneManager::Scene::Clear);

		//Init();
		
	}
	if (CGameManager::Bat)
	{
		state = State::Clear;

		scene->ChangeScene(CSceneManager::Scene::Over);
	}
	/*
	if (Input::KeyC.clicked)
	{
		scene->ChangeScene(CSceneManager::Scene::Clear);
	}
	//*/
}
///	ゲーム本体のアップデート
void CGameManager::Update()
{
	if (state == State::Init)
	{
		task->Start();
		state = State::Update;
	}
	if (state == State::Clear)
	{
		//scene->ChangeScene(CSceneManager::Scene::Clear);
		//task->Start();
		//state = State::Init;
		//Init();
	}
	if (state == State::Update)
	{
		task->Update();

		(TextureAsset(L"hoge")).draw();
		task->Draw();
		task->Remove();
		GameOver();
		GameClear();
	}
	
}
