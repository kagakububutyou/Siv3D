#include "GameApplication.h"
#include "TitleManager.h"
#include "MenuManager.h"
#include "GameManager.h"
#include "ClearManager.h"
#include "GameOverManager.h"

const int CGameApplication::ScreenWidth = 1280;
const int CGameApplication::ScreenHeight = 720;

CGameApplication::CGameApplication() :
scene_manager(std::make_shared<CSceneManager>(this))
{
	scene.insert(std::make_pair(CSceneManager::Scene::Title, std::make_unique<CTitleManager>(scene_manager)));
	scene.insert(std::make_pair(CSceneManager::Scene::Menu, std::make_unique<CMenuManager>(scene_manager)));
	scene.insert(std::make_pair(CSceneManager::Scene::Game, std::make_unique<CGameManager>(scene_manager)));
	scene.insert(std::make_pair(CSceneManager::Scene::Clear, std::make_unique<CClearManager>(scene_manager)));
	scene.insert(std::make_pair(CSceneManager::Scene::Over, std::make_unique<CGameOverManager>(scene_manager)));

	scene_manager->ChangeScene(CSceneManager::Scene::Title);
}

std::shared_ptr<CScene> CGameApplication::SceneFind(CSceneManager::Scene scene)
{
	auto it = this->scene.find(scene);
	return it->second;
}

///	アップデート
void CGameApplication::Update()
{
	scene_manager->Update();
}