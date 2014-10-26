#include "TitleManager.h"
#include "GameApplication.h"
#include "TitleKeyEvent.h"

CTitleManager::CTitleManager(std::shared_ptr<CSceneManager> manager) :
CScene(manager),
key(std::make_unique<CTitleKeyEvent>())
{

}
void CTitleManager::Init()
{
	Logo = new Font(50, Typeface::Black);
}

void CTitleManager::Update()
{
	key->ChangeSceneMenu(scene);
	Draw();
}

void CTitleManager::Draw()
{
	Logo->drawCenter(L"ƒ^ƒCƒgƒ‹", Float2(CGameApplication::ScreenWidth / 2, 100), Palette::Royalblue);
}