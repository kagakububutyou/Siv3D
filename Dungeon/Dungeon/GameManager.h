/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include "Task.h"
#include "Scene.h"
class CMapRead;

class CGameManager :public CScene
{
public:
	CGameManager(std::shared_ptr<CSceneManager> manager);

	void Init();
	void Update();

	void GameOver(std::shared_ptr<CSceneManager> scene);

	static const std::string PlayerName;
	static const std::string MiniPlayer;
	static const std::string FloorName;
	static const std::string UpStairs;
	static const std::string DownStairs;
	static const std::string Scroll;
	static const std::string WallName;
	static const std::string Attack;

private:
	int TransformMapToScreenX(const int x);
	int TransformMapToScreenY(const int y);

	int TransformMiniMapToScreenX(const int x);
	int TransformMiniMapToScreenY(const int y);

	///	状態
	enum class State
	{
		Init,		///	初期化
		Update,	///	アップデート
	};

	State state;	///	状態
	std::shared_ptr<CTask> task;				///	タスク
	std::unique_ptr<CMapRead> map_read;
};