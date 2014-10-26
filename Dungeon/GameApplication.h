/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include "Noncopyable.h"
#include "Scene.h"
#include <map>

///	ゲームアプリケーション
class CGameApplication :private Noncopyable
{
public:
	CGameApplication();

	///	アップデート
	void Update();

	static const int ScreenWidth;
	static const int ScreenHeight;

	std::shared_ptr<CScene> SceneFind(CSceneManager::Scene scene);

private:
	std::map<CSceneManager::Scene, std::shared_ptr<CScene>> scene;	///	シーン情報
	std::shared_ptr<CSceneManager> scene_manager;	///	シーン管理
};