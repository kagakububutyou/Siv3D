/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include "Scene.h"

class CTitleKeyEvent;

class CTitleManager :public CScene
{
public:
	CTitleManager(std::shared_ptr<CSceneManager> manager);
	void Init();
	void Update();
	void Draw();

private:
	Font *Logo;	///	ロゴ
	std::unique_ptr<CTitleKeyEvent> key;	///	キーイベント
};