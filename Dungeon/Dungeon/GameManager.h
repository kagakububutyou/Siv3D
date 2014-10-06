/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include "Task.h"
#include "Scene.h"
#include "Camera.h"
#include "Light.h"
class CGameManager :public CScene
{
public:
	CGameManager(std::shared_ptr<CSceneManager> manager);

	void Init();
	void Update();

private:

	///	状態
	enum class State
	{
		Init,		///	初期化
		Update,	///	アップデート
	};

	State state;	///	状態
	std::shared_ptr<CTask> task;				///	タスク
	std::unique_ptr<CCamera> camera;	///	カメラ
	std::unique_ptr<CLight> light;			///	ライト

};