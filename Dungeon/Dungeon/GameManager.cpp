#include "GameManager.h"
#include "Scene.h"
#include "Player.h"
#include "EnemyManager.h"
#include "Actor.h"
#include "MapRead.h"
#include "Floor.h"

const std::string CGameManager::PlayerName = "player";
const std::string CGameManager::FloorName = "floor";


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
void CGameManager::Init()
{
	state = State::Init;

	auto player = std::make_shared<CActor>();
	auto enemy_manager = std::make_shared<CActor>();

	auto floor = std::make_shared<CActor>();

	for (int y = 0; y < CMapRead::Height; y++)
	{
		for (int x = 0; x < CMapRead::Width; x++)
		{
			
			map_read->ObjectRead(Point(x, y), 2, player, std::make_shared<CPlayer>(task,
				Float3(TransformMapToScreenX(x), TransformMapToScreenY(y), -1)));
				
			
			
			map_read->ObjectRead(Point(x, y), 1, floor, std::make_shared<CFloor>(task,
				Float3(TransformMapToScreenX(x), TransformMapToScreenY(y), 0)));
		}
	}

	//player->Append(std::make_shared<CPlayer>(task));
	enemy_manager->Append(std::make_shared <CEnemyManager>(task));

	task->Append(PlayerName, player);
	task->Append("enemy_manager", enemy_manager);

	task->Append(FloorName, floor);

	light = std::make_unique<CLight>(0, CLight::Type::Point, Float3(0, 100, -1000), 10000.0f, ColorF(2, 2, 2));
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
