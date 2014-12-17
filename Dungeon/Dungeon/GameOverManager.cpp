#include "GameOverManager.h"
#include "GameApplication.h"
#include "GameOverKeyEvent.h"

CGameOverManager::CGameOverManager(std::shared_ptr<CSceneManager> manager) :
CScene(manager),
key(std::make_unique<CGameOverKeyEvent>())
{

}
void CGameOverManager::Init()
{
	TextureAsset::Register(L"Bat", L"engine/data/texture/Character/Etc/Bat.png");
	TextureAsset::Register(L"GAMEOVER", L"engine/data/texture/Character/Etc/GAMEOVER.png");
	Logo = new Font(50, Typeface::Black);
}

void CGameOverManager::Update()
{
	key->ChangSceneMenu(scene);
	Draw();
}

void CGameOverManager::Draw()
{
	//Logo->drawCenter(L"Ç∞Å[ÇﬁÇ®Å[ÇŒÅ[", Float2(CGameApplication::ScreenWidth / 2, 100), Palette::Royalblue);
	TextureAsset(L"Bat")/*.resize(CGameApplication::ScreenWidth, CGameApplication::ScreenHeight)*/.draw();

	(TextureAsset(L"GAMEOVER")).draw(CGameApplication::ScreenWidth / 2 - 350, 100);
}