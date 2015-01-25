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

	void GameOver();
	void GameClear();

	static const std::string PlayerName;
	static const std::string MiniPlayer;
	static const std::string EnemyManager;
	static const std::string FloorName;
	static const std::string UpStairs;
	static const std::string DownStairs;
	static const std::string Scroll;
	static const std::string WallName;
	static const std::string SwitchWall;
	static const std::string SwitchWall1;
	static const std::string SwitchWall2;
	static const std::string SwitchWall3;
	static const std::string Attack;
	static bool Clear;
	static bool Bat;

private:
	int TransformMapToScreenX(const int x);
	int TransformMapToScreenY(const int y);

	int TransformMiniMapToScreenX(const int x);
	int TransformMiniMapToScreenY(const int y);

	///	���
	enum class State
	{
		Init,		///	������
		Update,	///	�A�b�v�f�[�g
		Clear,	///	���肠
		Bat,
	};

	State state;	///	���
	std::shared_ptr<CTask> task;				///	�^�X�N
	std::unique_ptr<CMapRead> map_read;
};