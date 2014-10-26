#include "Scene.h"
#include "GameApplication.h"

CSceneManager::CSceneManager(CGameApplication *app):
app(app),
isFade(false)
{
	state = State::Init;
}

///	次のシーンに行かせる処理
void CSceneManager::ChangeScene(Scene next_scene)
{
	this->next_scene = app->SceneFind(next_scene);
	isFade = true;
	alpha = 0.0;
}

void CSceneManager::FadeOut()
{
	if (!isFade) return;

	Rect(0, 0, CGameApplication::ScreenWidth, CGameApplication::ScreenHeight).draw(ColorF(1, 1, 1,alpha));
	alpha += 0.05;
	if (alpha >= 1)
	{
		state = State::Init;
	}
}

void CSceneManager::ScenenInit()
{
	if (state != State::Init) return;

	isFade = false;
	scene = next_scene;
	scene->Init();
	state = State::Update;
}
void CSceneManager::SceneUpdate()
{
	if (state != State::Update) return;

	scene->Update();
	FadeOut();
}

///	シーン管理のアップデート
void CSceneManager::Update()
{
	ScenenInit();
	SceneUpdate();
}