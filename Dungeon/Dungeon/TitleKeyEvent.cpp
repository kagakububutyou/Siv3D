#include "TitleKeyEvent.h"
#include "Scene.h"
#include "CharacterController.h"

CTitleKeyEvent::CTitleKeyEvent()
{

}

void CTitleKeyEvent::ChangeSceneMenu(std::shared_ptr<CSceneManager> scene)
{
	if (CharacterController::ChangeSceneKey())
	{
		scene->ChangeScene(CSceneManager::Scene::Menu);
	}
}