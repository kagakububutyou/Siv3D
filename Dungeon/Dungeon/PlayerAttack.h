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
	

	bool isCollision;	///<	あたり判定がおこっているかどうか

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
	
	std::unique_ptr<CPlayerMove> move;	///	移動処理

	void Create();		///	生成

	void PushKey();				///	攻撃の方向
	void OnCollision();			///	当たり判定

	void ReadColors();			///	色の読み込み
	bool ReadColor;				///	読み込んだかどうか

	void DrawHpBar();


	Point TextureSize = Point(256, 256);		///	画像のサイズ
	Point TexturePos;	///	画像の場所
	///	HPの色
	static const int ColorMax = 7;
	ColorF Color[ColorMax];

	///	キー入力
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
	Font *Logo;	///	ロゴ
};