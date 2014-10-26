/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include "Scene.h"

class CMenuKeyEvent;

///	���j���[�Ǘ�
class CMenuManager :public CScene
{
public:
	CMenuManager(std::shared_ptr<CSceneManager> manage);

	void Init();
	void Update();
	void Draw();

private:
	Font *Logo;	///	���S
	std::unique_ptr<CMenuKeyEvent> key;	///	�L�[�C�x���g

};