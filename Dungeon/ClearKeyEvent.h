/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include <memory>
class CSceneManager;

///	�N���A�L�[�C�x���g
class CClearKeyEvent
{
public:
	CClearKeyEvent();

	///	�V�[���ύX
	void ChangSceneMenu(std::shared_ptr<CSceneManager> scene);
};