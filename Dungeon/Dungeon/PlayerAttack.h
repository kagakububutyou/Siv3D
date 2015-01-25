//PlayerAttack
#pragma once
#include "Actor.h"
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
	

	bool isCollision;	///<	�����蔻�肪�������Ă��邩�ǂ���

	enum EnemyName
	{
		Patroller,
		SnakeCopter,
		TatteredId,
		Battery,

		EnemyMax,
	};

	//bool isHit[EnemyName::EnemyMax];

	///*
	bool isHit1;
	bool isHit2;
	bool isHit3;
	bool isHit4;
	//*/
	bool isEnemy1;
	bool isEnemy2;
	bool isEnemy3;
	bool isEnemy4;

private:
	
	std::unique_ptr<CPlayerMove> move;	///	�ړ�����

	void Create();		///	����

	void PushKey();				///	�U���̕���
	void OnCollision();			///	�����蔻��

	void ReadColors();			///	�F�̓ǂݍ���
	bool ReadColor;				///	�ǂݍ��񂾂��ǂ���

	void DrawHpBar();


	Point TextureSize = Point(256, 256);		///	�摜�̃T�C�Y
	Point TexturePos;	///	�摜�̏ꏊ
	///	HP�̐F
	static const int ColorMax = 7;
	ColorF Color[ColorMax];

	///	�L�[����
	enum KeyNum
	{
		left,
		right,
		up,
		down,

		KeyMax,
	};
	bool KeyPressed[KeyNum::KeyMax];
	Point TransformPoint[KeyNum::KeyMax];

	const Font font;
	Font *Logo;	///	���S
};