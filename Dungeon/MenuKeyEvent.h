/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include <memory>
class CSceneManager;

///	���j���[�L�[�C�x���g
class CMenuKeyEvent
{
public:
	CMenuKeyEvent();

	///	�V�[���ύX
	void ChngeSceneGame(std::shared_ptr<CSceneManager> scene);
};