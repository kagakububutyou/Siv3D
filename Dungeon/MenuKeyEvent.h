/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include <memory>
class CSceneManager;

///	メニューキーイベント
class CMenuKeyEvent
{
public:
	CMenuKeyEvent();

	///	シーン変更
	void ChngeSceneGame(std::shared_ptr<CSceneManager> scene);
};