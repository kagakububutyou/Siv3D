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
	TextureAsset::Register(L"good_end", L"engine/data/texture/Character/Etc/good_end.png");

	Logo = new Font(50, Typeface::Black);
}

void CClearManager::Update()
{
	//key->ChangSceneMenu(scene);
	Draw();
}

void CClearManager::Draw()
{
	TextureAsset(L"good_end").draw();
	TextureAsset(L"ED")/*.resize(CGameApplication::ScreenWidth, CGameApplication::ScreenHeight)*/.draw(CGameApplication::ScreenWidth / 2 - 260, 250);

	//Logo->drawCenter(L"GameClear�H", Float2(CGameApplication::ScreenWidth / 2, 100), Palette::Royalblue);
}