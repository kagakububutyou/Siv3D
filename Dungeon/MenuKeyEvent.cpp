#include "MenuKeyEvent.h"
#include "Scene.h"
#include "CharacterController.h"

CMenuKeyEvent::CMenuKeyEvent()
{

}

void CMenuKeyEvent::ChngeSceneGame(std::shared_ptr<CSceneManager> scene)
{
	if (CharacterController::ChangeSceneKey())
	{
		scene->ChangeScene(CSceneManager::Scene::Game);
	}
}