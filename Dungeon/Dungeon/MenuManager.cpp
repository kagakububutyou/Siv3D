#include "MenuManager.h"
#include "GameApplication.h"
#include "MenuKeyEvent.h"

CMenuManager::CMenuManager(std::shared_ptr<CSceneManager> manager) :
CScene(manager),
key(std::make_unique<CMenuKeyEvent>())
{

}

void CMenuManager::Init()
{
	Logo = new Font(50, Typeface::Black);
}

void CMenuManager::Update()
{
	key->ChngeSceneGame(scene);
	Draw();
}

void CMenuManager::Draw()
{
	Logo->drawCenter(L"ƒƒjƒ…[", Float2(CGameApplication::ScreenWidth / 2, 100), Palette::Royalblue);
}