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
	TextureAsset::Register(L"OP", L"engine/data/texture/Character/Etc/OP.png");
	TextureAsset::Register(L"ゲーム説明", L"engine/data/texture/Character/Etc/ゲーム説明.png");
	//TextureAsset::Register(L"GAMEOVER", L"engine/data/texture/Character/Etc/GAMEOVER.png");
	Logo = new Font(50, Typeface::Black);
}

void CMenuManager::Update()
{
	key->ChngeSceneGame(scene);
	Draw();
}

void CMenuManager::Draw()
{
	//Logo->drawCenter(L"メニュー", Float2(CGameApplication::ScreenWidth / 2, 100), Palette::Royalblue);
	TextureAsset(L"OP")/*.resize(CGameApplication::ScreenWidth, CGameApplication::ScreenHeight)*/.draw();
	TextureAsset(L"ゲーム説明")/*.resize(CGameApplication::ScreenWidth, CGameApplication::ScreenHeight)*/.draw(CGameApplication::ScreenWidth / 2 - 313, 250);
}