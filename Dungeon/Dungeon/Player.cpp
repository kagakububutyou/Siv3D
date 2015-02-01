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
///	‰‚ß‚ÉŒÄ‚ÔŠÖ”@‰Šú‰»Œn
void CPlayer::Start()
{
	move->Start();
	attack->Start();
	anime->Start();
}
///	–ˆƒtƒŒ[ƒ€ŒÄ‚ÔŠÖ”@XV‚ª•K—v‚ÈŠÖ”
void CPlayer::Update()
{
	move->Update();
	attack->Update();
	anime->Update();
}
///	•`‰æŠÖŒW‚ÌŠÖ”@•`‰æ‚µ‚½‚¢“z‚Í‚±‚±‚Ö
void CPlayer::Draw()
{
	anime->Draw();
	attack->Draw();
}