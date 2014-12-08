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
	Logo = new Font(50, Typeface::Black);
}

void CGameOverManager::Update()
{
	key->ChangSceneMenu(scene);
	Draw();
}

void CGameOverManager::Draw()
{
	Logo->drawCenter(L"Ç∞Å[ÇﬁÇ®Å[ÇŒÅ[", Float2(CGameApplication::ScreenWidth / 2, 100), Palette::Royalblue);
}