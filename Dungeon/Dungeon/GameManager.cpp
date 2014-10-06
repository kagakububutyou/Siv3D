#include "GameManager.h"
#include "Scene.h"
#include "Player.h"
#include "Enemy.h"
#include "Actor.h"

CGameManager::CGameManager(std::shared_ptr<CSceneManager> manager) :
CScene(manager),
task(std::make_shared<CTask>())
{

}

void CGameManager::Init()
{
	state = State::Init;

	auto player = std::make_shared<CActor>();

	player->Append(std::make_shared<CPlayer>(task));

	task->Append("player", player);

	camera = std::make_unique<CCamera>(Float3(0, 100, -500), Float3(0, 0, 0));
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
	else if (state == State::Update)
	{
		camera->Update();
		light->Update();

		task->Update();
		task->Draw();
		task->Remove();
	}
}
