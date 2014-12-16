//PlayerAttack
#pragma once
#include "PlayerState.h"
#include "Transform.h"
#include "Scene.h"

class CPlayerMove;
class CSceneManager;

class CPlayerAttack :public CActor
{
public:
	CPlayerAttack(std::shared_ptr<CTask> task);

	void Start();
	void Update();
	void Draw();
	void OnCollisionStart();
	void Finish();
	void OnCollision();
	//Transform transform;	///<	���W�A�T�C�Y�A��]

	bool isCollision;	///<	�����蔻�肪�������Ă��邩�ǂ���
	bool isHit;

private:
	
	std::unique_ptr<CPlayerMove> move;	///	�ړ�����

	void Create();		///	����

	void Right();		///	�E�ړ�
	void Left();			///	���ړ�
	void Up();			//	/	��ړ�
	void Down();		///	���ړ�
	void RightUp();	///	�E��
	void RightDown();///	�E��
	void LeftUp();		///	����
	void LeftDown();	///	����

	Point TextureSize = Point(256, 256);		///	�摜�̃T�C�Y
	Point TexturePos;	///	�摜�̏ꏊ

	const Font font;
};