//PlayerAttack
#pragma once
#include "Actor.h"


class CPlayerMove;

class CPlayerAttack :public CActor
{
public:
	CPlayerAttack(std::shared_ptr<CTask> task);

	void Start();		///	���߂ɌĂԊ֐��@
	void Update();		///	���t���[���ĂԊ֐�
	void Draw();		///	�`��֌W�̊֐�
	

	bool isCollision;	///<	�����蔻�肪�������Ă��邩�ǂ���

	enum EnemyName
	{
		Patroller,		///	isEnemy1
		SnakeCopter,	///	isEnemy2
		TatteredId,		///	isEnemy3
		Battery,			///	isEnemy4

		Max,
	};

	bool isHits[EnemyName::Max];			///	�����蔻��
	bool isEnemys[EnemyName::Max];

private:
	
	std::unique_ptr<CPlayerMove> move;	///	�ړ�����

	void Create();		///	����

	void PushKey();				///	�U���̕���
	void OnCollision();			///	�����蔻��

	void ReadColors();			///	�F�̓ǂݍ���
	bool ReadColor;				///	�ǂݍ��񂾂��ǂ���

	void DrawHpBar();			///	HP�\��

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