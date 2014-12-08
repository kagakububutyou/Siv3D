/*

@author shinnnosuke hiratsuka
@date 2014.12.07

*/
#pragma once
#include <memory>
class CSceneManager;

///	クリアキーイベント
class CGameOverKeyEvent
{
public:
	CGameOverKeyEvent();

	///	シーン変更
	void ChangSceneMenu(std::shared_ptr<CSceneManager> scene);
};