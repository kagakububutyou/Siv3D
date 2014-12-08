/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include "Scene.h"

class CGameOverKeyEvent;

class CGameOverManager :public CScene
{
public:
	CGameOverManager(std::shared_ptr<CSceneManager> manager);
	void Init();
	void Update();
	void Draw();

private:
	Font *Logo;	///	ロゴ
	std::unique_ptr<CGameOverKeyEvent> key;	///	キーイベント
};