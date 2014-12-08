#include "MapRead.h"
#include "EnemyManager.h"
#include "GameManager.h"
#include "Patroller.h"
#include "PatrollerAttack.h"
#include "SnakeCopter.h"
#include "SnakeCopterAttack.h"
#include "MiniMap.h"
#include "GameApplication.h"
#include "MiniGoblin.h"


const std::string CEnemyManager::SnakeCopter = "SnakeCopter";
const std::string CEnemyManager::SnakeCopterAttack = "SnakeCopterAttack";
const std::string CEnemyManager::Patroller = "Patroller";
const std::string CEnemyManager::PatrollerAttack = "PatrollerAttack";
const std::string CEnemyManager::MiniGoblin = "MiniGoblin";

CEnemyManager::CEnemyManager(std::shared_ptr<CTask> task) :
CActor(task, Transform(Point(0, 0), Point(0, 0), Point(0, 0)), state),
map_read(std::make_unique<CMapRead>())
{

}
int CEnemyManager::TransformMapToScreenX(const int x)
{
	return x * CMapRead::Size;
}
int CEnemyManager::TransformMapToScreenY(const int y)
{
	return y * CMapRead::Size;
}
int CEnemyManager::TransformMiniMapToScreenX(const int x)
{
	return (x * CMapRead::Size / CMiniMap::MapScale) + CGameApplication::ScreenWidth / 2 - (CMapRead::Width * CMapRead::Size / CMiniMap::MapScale) / 2;
}
int CEnemyManager::TransformMiniMapToScreenY(const int y)
{
	return (y * CMapRead::Size / CMiniMap::MapScale) + CGameApplication::ScreenHeight / 2 - (CMapRead::Height * CMapRead::Size / CMiniMap::MapScale) / 2 - (CMapRead::Size / CMiniMap::MapScale) * 4;
}
void CEnemyManager::Start()
{
	auto patroller = std::make_shared<CActor>();
	auto patroller_atk = std::make_shared<CActor>();
	auto snake_copter = std::make_shared<CActor>();
	auto snake_copter_atk = std::make_shared<CActor>();
	auto minigoblin = std::make_shared<CActor>();

	for (int y = 0; y < CMapRead::Height; y++)
	{
		for (int x = 0; x < CMapRead::Width; x++)
		{
			///	パトローラー
			map_read->ObjectRead(Point(x, y), CEnemyManager::PatrollerPosition, patroller, std::make_shared<CPatroller>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y))));
			map_read->ObjectRead(Point(x, y), CEnemyManager::PatrollerPosition, patroller_atk, std::make_shared<CPatrollerAttack>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y))));
			///	ヘビコプター
			map_read->ObjectRead(Point(x, y), CEnemyManager::SnakeCopterPosition, snake_copter, std::make_shared<CSnakeCopter>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y))));
			map_read->ObjectRead(Point(x, y), CEnemyManager::SnakeCopterPosition, snake_copter_atk, std::make_shared<CSnakeCopterAttack>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y))));
			



			map_read->ObjectRead(Point(x, y), CEnemyManager::PatrollerPosition, minigoblin, std::make_shared<CMiniGoblin>(task,
				Point(TransformMiniMapToScreenX(x), TransformMiniMapToScreenY(y))));
			//*/
		}
	}

	task->Append(Patroller, patroller);
	task->Append(PatrollerAttack, patroller_atk);
	task->Append(SnakeCopter, snake_copter);
	task->Append(SnakeCopterAttack, snake_copter_atk);
	task->Append(MiniGoblin, minigoblin);

}

void CEnemyManager::Update()
{

}