#include "GameManager.h"
//#include "Scene.h"
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
	return (x - CMapRead::Width / 2) * CMapRead::Size;
}
int CGameManager::TransformMapToScreenY(const int y)
{
	return (y - CMapRead::Height / 2) * -CMapRead::Size;
}
float CGameManager::TransformMiniMapToScreenX(const float x)
{
	return (x - CMapRead::Width / 2) * CMapRead::Size / 10;
}
float CGameManager::TransformMiniMapToScreenY(const float y)
{
	return (y - CMapRead::Height / 2) * -CMapRead::Size / 10;
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
			
			map_read->ObjectRead(Point(x, y), CMapRead::PlayerPosition, player, std::make_shared<CPlayer>(task,
				Float3(TransformMapToScreenX(x), TransformMapToScreenY(y) - CMapRead::Size / 2, -1)));
				
			map_read->ObjectRead(Point(x, y), CMapRead::Floor, floor, std::make_shared<CFloor>(task,
				Float3(TransformMapToScreenX(x), TransformMapToScreenY(y), 0)));

			map_read->ObjectRead(Point(x, y), CMapRead::StaircasePosition, staircase, std::make_shared<CStaircase>(task,
				Float3(TransformMapToScreenX(x), TransformMapToScreenY(y), 0)));

			map_read->ObjectRead(Point(x, y), CMapRead::Floor, mini_map, std::make_shared<CMiniMap>(task,
				Float3(TransformMiniMapToScreenX(x), TransformMiniMapToScreenY(y), -2)));
		}
	}

	enemy_manager->Append(std::make_shared <CEnemyManager>(task));

	task->Append(PlayerName, player);
	task->Append("enemy_manager", enemy_manager);

	task->Append(FloorName, floor);
	task->Append(Staircase, staircase);
	task->Append("mini_map", mini_map);

	light = std::make_unique<CLight>(0, CLight::Type::Point, Float3(-CMapRead::Width * CMapRead::Size / 2, -CMapRead::Height * CMapRead::Size / 2, -1000), 10000.0f, ColorF(2, 2, 2));
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
		light->Update();

		task->Update();
		task->Draw();
		task->Remove();
	}
}
