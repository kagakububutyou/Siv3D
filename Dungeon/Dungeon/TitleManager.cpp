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
	TextureAsset::Register(L"Title", L"engine/data/texture/Character/Etc/contaminatedSky4.jpg");

	Logo = new Font(50, Typeface::Black);
}

void CTitleManager::Update()
{
	key->ChangeSceneMenu(scene);
	Draw();
}

void CTitleManager::Draw()
{
	TextureAsset(L"Title").resize(CGameApplication::ScreenWidth, CGameApplication::ScreenHeight).draw();

	Logo->drawCenter(L"ƒ^ƒCƒgƒ‹", Float2(CGameApplication::ScreenWidth / 2, 100), Palette::Royalblue);
}