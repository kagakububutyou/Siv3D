#include "GameApplication.h"
#include "TitleManager.h"
#include "MenuManager.h"
#include "GameManager.h"
#include "ClearManager.h"

const int CGameApplication::ScreenWidth = 1280;
const int CGameApplication::ScreenHeight = 720;

CGameApplication::CGameApplication() :
scene_manager(std::make_shared<CSceneManager>(this))
{

}