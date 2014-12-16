#include "ClearManager.h"
#include "GameApplication.h"
#include "ClearKeyEvent.h"

CClearManager::CClearManager(std::shared_ptr<CSceneManager> manager) :
CScene(manager),
key(std::make_unique<CClearKeyEvent>())
{

}
void CClearManager::Init()
{
	TextureAsset::Register(L"ED", L"engine/data/texture/Character/Etc/ED.png");
	TextureAsset::Register(L"GAMECLEAR", L"engine/data/texture/Character/Etc/GAMECLEAR.png");

	Logo = new Font(50, Typeface::Black);
}

void CClearManager::Update()
{
	key->ChangSceneMenu(scene);
	Draw();
}

void CClearManager::Draw()
{
	TextureAsset(L"ED")/*.resize(CGameApplication::ScreenWidth, CGameApplication::ScreenHeight)*/.draw(CGameApplication::ScreenWidth / 2 - 260, 250);

	(TextureAsset(L"GAMECLEAR")).draw(CGameApplication::ScreenWidth / 2 - 350, 100);

	//Logo->drawCenter(L"GameClearÅH", Float2(CGameApplication::ScreenWidth / 2, 100), Palette::Royalblue);
}