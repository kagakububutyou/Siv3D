/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include "Scene.h"

class CClearKeyEvent;

class CClearManager :public CScene
{
public:
	CClearManager(std::shared_ptr<CSceneManager> manager);

	void Init();
	void Update();
	void Draw();

private:
	Font *Logo;	///	ロゴ
	std::unique_ptr<CClearKeyEvent> key;	///	キーイベント
};