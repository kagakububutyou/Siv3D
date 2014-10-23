/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include "Task.h"
#include "Scene.h"
#include "Camera.h"
#include "Light.h"
class CMapRead;
//class CBackGround;

class CGameManager :public CScene
{
public:
	CGameManager(std::shared_ptr<CSceneManager> manager);

	void Init();
	void Update();

	static const std::string PlayerName;
	static const std::string FloorName;
	static const std::string Staircase;

private:
	int TransformMapToScreenX(const int x);
	int TransformMapToScreenY(const int y);

	float TransformMiniMapToScreenX(const float x);
	float TransformMiniMapToScreenY(const float y);

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
	std::unique_ptr<CMapRead> map_read;
	//std::unique_ptr<CBackGround> barck_ground;

};