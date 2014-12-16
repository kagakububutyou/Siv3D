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
	bool isHit;

private:
	
	std::unique_ptr<CPlayerMove> move;	///	移動処理

	void Create();		///	生成

	void Right();		///	右移動
	void Left();			///	左移動
	void Up();			//	/	上移動
	void Down();		///	下移動
	void RightUp();	///	右上
	void RightDown();///	右下
	void LeftUp();		///	左上
	void LeftDown();	///	左下

	Point TextureSize = Point(256, 256);		///	画像のサイズ
	Point TexturePos;	///	画像の場所

	const Font font;
};