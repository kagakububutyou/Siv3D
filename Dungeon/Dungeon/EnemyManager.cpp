#include "MapRead.h"
#include "EnemyManager.h"
#include "GameManager.h"
#include "Goblin.h"
#include "MiniMap.h"
#include "GameApplication.h"
#include "MiniGoblin.h"



const std::string CEnemyManager::Goblin = "goblin";
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
	auto goblin = std::make_shared<CActor>();
	auto minigoblin = std::make_shared<CActor>();

	for (int y = 0; y < CMapRead::Height; y++)
	{
		for (int x = 0; x < CMapRead::Width; x++)
		{
			map_read->ObjectRead(Point(x, y), CEnemyManager::GoblinPosition, goblin, std::make_shared<CGoblin>(task,
				Point(TransformMapToScreenX(x), TransformMapToScreenY(y))));

			map_read->ObjectRead(Point(x, y), CEnemyManager::GoblinPosition, minigoblin, std::make_shared<CMiniGoblin>(task,
				Point(TransformMiniMapToScreenX(x), TransformMiniMapToScreenY(y))));
		}
	}

	task->Append(Goblin, goblin);
	task->Append(MiniGoblin, minigoblin);

}

void CEnemyManager::Update()
{

}