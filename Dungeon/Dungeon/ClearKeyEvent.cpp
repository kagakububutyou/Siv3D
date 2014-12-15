#include "ClearKeyEvent.h"
#include "Scene.h"
#include "CharacterController.h"

CClearKeyEvent::CClearKeyEvent()
{

}

void CClearKeyEvent::ChangSceneMenu(std::shared_ptr<CSceneManager> scene)
{
	if (CharacterController::ChangeSceneKey())
	{
		scene->ChangeScene(CSceneManager::Scene::Title);
	}
}