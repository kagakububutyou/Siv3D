#include "Player.h"
#include "PlayerMove.h"

CPlayer::CPlayer(std::shared_ptr<CTask> task) :
CActor(task ,Transform(Float3(0, 0, 0), Float3(32, 32, 0), Float3(0, 0, 0)), State::Live),
move(std::make_unique<CPlayerMove>(task))
{

}

void CPlayer::Start()
{

}

void CPlayer::Update()
{
	move->Update();
	transform.Translate(move->GetVelocity());
}

void CPlayer::Draw()
{
	Box(transform.GetPos(), transform.GetScale()).draw();
}