#include "ClearKeyEvent.h"
#include "Scene.h"
#include "CharacterController.h"
#include <Siv3D.hpp>

CClearKeyEvent::CClearKeyEvent()
{

}

void CClearKeyEvent::ChangSceneMenu(std::shared_ptr<CSceneManager> scene)
{
	if (CharacterController::ChangeSceneKey())
	{
		System::SetExitEvent;
		scene->ChangeScene(CSceneManager::Scene::Title);
		

	}
}