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
	bool isHit1;
	bool isHit2;
	bool isHit3;
	bool isHit4;

	bool isEnemy1;
	bool isEnemy2;
	bool isEnemy3;
	bool isEnemy4;

private:
	
	std::unique_ptr<CPlayerMove> move;	///	�ړ�����

	void Create();		///	����

	void PushKey();

	Point TextureSize = Point(256, 256);		///	�摜�̃T�C�Y
	Point TexturePos;	///	�摜�̏ꏊ

	static const int ColorMax = 7;

	ColorF Color[ColorMax];

	enum KeyNum
	{
		left,
		right,
		up,
		down,

		max,
	};

	bool KeyPressed[KeyNum::max];
	Point TransformPoint[KeyNum::max];

	const Font font;
	Font *Logo;	///	���S
};