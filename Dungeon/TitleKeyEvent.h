/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include <memory>
class CSceneManager;

///	タイトルキーイベント
class CTitleKeyEvent
{
public:
	CTitleKeyEvent();

	void ChangeSceneMenu(std::shared_ptr<CSceneManager> scene);
};