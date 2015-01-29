#include "Player.h"
#include "PlayerMove.h"
#include "PlayerAttack.h"
#include "PlayerAnimation.h"
#include "MapRead.h"
//#include <string>

CPlayer::CPlayer(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos, Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), State::Live),
move(std::make_unique<CPlayerMove>(task)),
attack(std::make_unique<CPlayerAttack>(task)),
anime(std::make_unique<CPlayerAnimation>(task)),
behavior(false),
MaxHP(3500),
HP(3500)
{

}
///	初めに呼ぶ関数　初期化系
void CPlayer::Start()
{
	move->Start();
	attack->Start();
	anime->Start();
}
///	毎フレーム呼ぶ関数　更新が必要な関数
void CPlayer::Update()
{
	move->Update();
	attack->Update();
	anime->Update();
}
///	描画関係の関数　描画したい奴はここへ
void CPlayer::Draw()
{
	anime->Draw();
	attack->Draw();
}