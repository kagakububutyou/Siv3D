#include "EnemyManager.h"
#include "GameManager.h"
#include "Goblin.h"

CEnemyManager::CEnemyManager(std::shared_ptr<CTask> task) :
CActor(task, Transform(Point(0, 0), Point(0, 0), Point(0, 0)), state)
{

}

void CEnemyManager::Start()
{
	auto goblin = std::make_shared<CActor>();

	goblin->Append(std::make_shared<CGoblin>(task));

	task->Append("goblin", goblin);

}

void CEnemyManager::Update()
{

}