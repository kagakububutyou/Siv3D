/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include "PlayerState.h"

class CPlayerMove :public CPlayerState
{
private:
	void Right();		///	右移動
	void Left();			///	左移動
	void Up();			//	/	上移動
	void Down();		///	下移動
	void Stop();			///	停止
	void VelocitySpeed(const Point speed);	///	移動量設定

	void WallCollision();			///	壁との当たり判定
	void EnemyCollision();		///	敵との当たり判定

	enum EnemyName
	{
		Patroller,
		SnakeCopter,
		TatteredId,
		Battery,

		EnemyMax,
	};

	///	方向
	enum  MOVEDIREC{
		LEFT,
		RIGHT,
		UP,
		DOWN,

		DIREC,
	};
	MOVEDIREC Direc(Point player, Point enemy, Point scroll);
	void Move(MOVEDIREC direc);
	void knockBack();		///	ノックバック

	Point MoveDirec[MOVEDIREC::DIREC];
	Point velocity;	///	移動量
	Point speed;		///	速度

	State state;

public:
	CPlayerMove(std::shared_ptr<CTask> task);

	void Start();

	void Update();

	void Draw();

	

	///	移動量を取得
	Point GetVelocity()const { return velocity; }

	//MOVEDIREC GetMoveDirec() const{ return MoveDirec; }

};