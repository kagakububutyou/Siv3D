/*

@author shinnnosuke hiratsuka
@date 2014.12.07

*/
#pragma once
#include <memory>
class CSceneManager;

///	�N���A�L�[�C�x���g
class CGameOverKeyEvent
{
public:
	CGameOverKeyEvent();

	///	�V�[���ύX
	void ChangSceneMenu(std::shared_ptr<CSceneManager> scene);
};