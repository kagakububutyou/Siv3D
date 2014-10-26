/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include <Siv3D.hpp>
#include "Noncopyable.h"

class CSceneManager;
class CGameApplication;

///	�V�[���̊��N���X
class CScene :private Noncopyable
{
public:
	CScene(std::shared_ptr<CSceneManager> scene) :scene(scene){}
	virtual ~CScene() = default;

	virtual void Init() = 0;
	virtual void Update() = 0;

protected:
	std::shared_ptr<CSceneManager> scene;	///	�V�[���Ǘ�

private:

};

///	�V�[���Ǘ�
class CSceneManager :private Noncopyable
{
public:
	enum class Scene;

	CSceneManager(CGameApplication *app);

	void Update();

	///	���̃V�[���ɍs�����鏈��
	void ChangeScene(Scene next_scene);

	///	�V�[��
	enum class Scene
	{
		Title,		///	�^�C�g��
		Menu,	///	���j���[
		Game,	///	�Q�[��
		Clear,	///	�N���A
	};
private:

	///	�t�F�[�h�A�E�g
	void FadeOut();

	///	�V�[���̏�����
	void ScenenInit();

	///	�V�[���̃A�b�v�f�[�g
	void SceneUpdate();

	///	�V�[���Ǘ��̏��
	enum class State
	{
		Init,		///	������
		Update,	///	�A�b�v�f�[�g����
	};

	std::shared_ptr<CScene> scene;			///	�V�[���̃C���X�^���X	
	std::shared_ptr<CScene> next_scene;	///	�V�[���̃C���X�^���X
	std::shared_ptr<CGameApplication> app;	///	�A�v���P�[�V����

	State state;	///	�V�[���Ǘ��̏��
	double alpha;	///	�t�F�[�h�A�E�g�p�̕ϐ�
	bool isFade;	///	�t�F�[�h�A�E�g�t���O
};