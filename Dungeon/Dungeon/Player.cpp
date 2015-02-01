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
MaxHP(3000),
HP(3000)
{

}
///	���߂ɌĂԊ֐��@�������n
void CPlayer::Start()
{
	move->Start();
	attack->Start();
	anime->Start();
}
///	���t���[���ĂԊ֐��@�X�V���K�v�Ȋ֐�
void CPlayer::Update()
{
	move->Update();
	attack->Update();
	anime->Update();
}
///	�`��֌W�̊֐��@�`�悵�����z�͂�����
void CPlayer::Draw()
{
	anime->Draw();
	attack->Draw();
}