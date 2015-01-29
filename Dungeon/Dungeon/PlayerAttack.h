//PlayerAttack
#pragma once
#include "Actor.h"


class CPlayerMove;

class CPlayerAttack :public CActor
{
public:
	CPlayerAttack(std::shared_ptr<CTask> task);

	void Start();		///	初めに呼ぶ関数　
	void Update();		///	毎フレーム呼ぶ関数
	void Draw();		///	描画関係の関数
	

	bool isCollision;	///<	あたり判定がおこっているかどうか

	enum EnemyName
	{
		Patroller,		///	isEnemy1
		SnakeCopter,	///	isEnemy2
		TatteredId,		///	isEnemy3
		Battery,			///	isEnemy4

		Max,
	};

	bool isHits[EnemyName::Max];			///	当たり判定
	bool isEnemys[EnemyName::Max];

private:
	
	std::unique_ptr<CPlayerMove> move;	///	移動処理

	void Create();		///	生成

	void PushKey();				///	攻撃の方向
	void OnCollision();			///	当たり判定

	void ReadColors();			///	色の読み込み
	bool ReadColor;				///	読み込んだかどうか

	void DrawHpBar();			///	HP表示

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