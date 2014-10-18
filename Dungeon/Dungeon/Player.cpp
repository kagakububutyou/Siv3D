#include "Player.h"
#include "PlayerMove.h"
#include "PlayerCamera.h"

CPlayer::CPlayer(std::shared_ptr<CTask> task, Float3 pos) :
CActor(task ,Transform(pos, Float3(32, 32, 0), Float3(0, 0, 0)), State::Live),
move(std::make_unique<CPlayerMove>(task)),
camera(std::make_unique<CPlayerCamera>(task))
{

}

void CPlayer::Start()
{

}

void CPlayer::Update()
{
	move->Update();
	//transform.Translate(move->GetVelocity());

	camera->Update();
}

void CPlayer::Draw()
{
	Box(transform.GetPos(), transform.GetScale()).draw(Palette::Royalblue);
}