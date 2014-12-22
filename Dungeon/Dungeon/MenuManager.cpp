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
	TextureAsset::Register(L"ƒQ[ƒ€à–¾", L"engine/data/texture/Character/Etc/ƒQ[ƒ€à–¾.png");
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
	//Logo->drawCenter(L"ƒƒjƒ…[", Float2(CGameApplication::ScreenWidth / 2, 100), Palette::Royalblue);
	TextureAsset(L"OP")/*.resize(CGameApplication::ScreenWidth, CGameApplication::ScreenHeight)*/.draw();
	TextureAsset(L"ƒQ[ƒ€à–¾")/*.resize(CGameApplication::ScreenWidth, CGameApplication::ScreenHeight)*/.draw(CGameApplication::ScreenWidth / 2 - 313, 250);
}