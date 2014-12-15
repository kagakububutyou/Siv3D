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
	Logo = new Font(50, Typeface::Black);
}

void CClearManager::Update()
{
	key->ChangSceneMenu(scene);
	Draw();
}

void CClearManager::Draw()
{
	Logo->drawCenter(L"Ç∞Å[ÇﬁÇ≠ÇËÇ†ÅH", Float2(CGameApplication::ScreenWidth / 2, 100), Palette::Royalblue);
}