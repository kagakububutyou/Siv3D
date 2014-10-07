/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
# include <Siv3D.hpp>
#include "GameApplication.h"

void Main()
{
	Window::SetTitle(L"Dungeon");
	Window::Resize(CGameApplication::ScreenWidth, CGameApplication::ScreenHeight);
	CGameApplication app;

	while (System::Update())
	{
		app.Update();
	}
}
