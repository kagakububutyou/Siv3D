/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include "Task.h"
#include "Scene.h"
#include "Camera.h"
#include "Light.h"
class CGameManager :public CScene
{
public:
	CGameManager(std::shared_ptr<CSceneManager> manager);

	void Init();
	void Update();

private:

	///	���
	enum class State
	{
		Init,		///	������
		Update,	///	�A�b�v�f�[�g
	};

	State state;	///	���
	std::shared_ptr<CTask> task;				///	�^�X�N
	std::unique_ptr<CCamera> camera;	///	�J����
	std::unique_ptr<CLight> light;			///	���C�g

};