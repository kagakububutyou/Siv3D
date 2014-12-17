#include "GameOverKeyEvent.h"
#include "Scene.h"
#include "CharacterController.h"

CGameOverKeyEvent::CGameOverKeyEvent()
{

}

void CGameOverKeyEvent::ChangSceneMenu(std::shared_ptr<CSceneManager> scene)
{
	//if (CharacterController::ChangeSceneKey())
	if (Input::KeyC.clicked)
	{
		scene->ChangeScene(CSceneManager::Scene::Clear);
	}
}