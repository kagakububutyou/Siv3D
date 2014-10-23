/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include "Task.h"
#include "Scene.h"
#include "Camera.h"
#include "Light.h"
class CMapRead;
//class CBackGround;

class CGameManager :public CScene
{
public:
	CGameManager(std::shared_ptr<CSceneManager> manager);

	void Init();
	void Update();

	static const std::string PlayerName;
	static const std::string FloorName;
	static const std::string Staircase;

private:
	int TransformMapToScreenX(const int x);
	int TransformMapToScreenY(const int y);

	float TransformMiniMapToScreenX(const float x);
	float TransformMiniMapToScreenY(const float y);

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
	std::unique_ptr<CMapRead> map_read;
	//std::unique_ptr<CBackGround> barck_ground;

};