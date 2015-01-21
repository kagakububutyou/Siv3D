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
	//Transform transform;	///<	座標、サイズ、回転

	bool isCollision;	///<	あたり判定がおこっているかどうか
	bool isHit1;
	bool isHit2;
	bool isHit3;
	bool isHit4;

	bool isEnemy1;
	bool isEnemy2;
	bool isEnemy3;
	bool isEnemy4;

private:
	
	std::unique_ptr<CPlayerMove> move;	///	移動処理

	void Create();		///	生成

	void PushKey();

	Point TextureSize = Point(256, 256);		///	画像のサイズ
	Point TexturePos;	///	画像の場所

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
	Font *Logo;	///	ロゴ
};