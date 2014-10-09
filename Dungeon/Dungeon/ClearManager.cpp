#include "ClearManager.h"
#include "ClearKeyEvent.h"

CClearManager::CClearManager(std::shared_ptr<CSceneManager> manager) :
CScene(manager),
key(std::make_unique<CClearKeyEvent>())
{

}
void CClearManager::Init()
{

}

void CClearManager::Update()
{
	key->ChangSceneMenu(scene);
	Draw();
}

void CClearManager::Draw()
{

}