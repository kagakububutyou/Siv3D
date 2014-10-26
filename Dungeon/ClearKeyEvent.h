/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include <memory>
class CSceneManager;

///	クリアキーイベント
class CClearKeyEvent
{
public:
	CClearKeyEvent();

	///	シーン変更
	void ChangSceneMenu(std::shared_ptr<CSceneManager> scene);
};