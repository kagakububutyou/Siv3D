#include "SwitchWall1.h"
#include "MapRead.h"
#include "GameManager.h"
#include "GameApplication.h"
#include "Player.h"
#include "PlayerMove.h"
#include "Scroll.h"
#include "MiniMap.h"
#include "PlayerAttack.h"

CSwitchWall1::CSwitchWall1(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos + Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2) - Point(0, CMapRead::Size / 2), Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), State::Live)
{

}
void CSwitchWall1::Start()
{
	if (!TextureAsset(L"Floor"))
	{
		TextureAsset::Register(L"Floor", L"engine/data/texture/MapChip/�Ԍ^�}�b�v�`�b�v/map_ground_batu.png");
	}
}
void CSwitchWall1::Update()
{

}
void CSwitchWall1::Draw()
{
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());

	if (task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemy2)
	{
		Rect(transform.GetPos() - pos, transform.GetScale())(TextureAsset(L"Floor")).draw();
	}
}