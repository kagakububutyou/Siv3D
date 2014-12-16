#include "SwitchWall3.h"
#include "MapRead.h"
#include "GameManager.h"
#include "GameApplication.h"
#include "Player.h"
#include "PlayerMove.h"
#include "Scroll.h"
#include "MiniMap.h"
#include "PlayerAttack.h"

CSwitchWall3::CSwitchWall3(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos + Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2) - Point(0, CMapRead::Size / 2), Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), State::Live)
{

}
void CSwitchWall3::Start()
{
	if (!TextureAsset(L"Floor"))
	{
		TextureAsset::Register(L"Floor", L"engine/data/texture/MapChip/網型マップチップ/map_ground_batu.png");
	}
}
void CSwitchWall3::Update()
{

}
void CSwitchWall3::Draw()
{
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());

	if (task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemy4)
	{
		Rect(transform.GetPos() - pos, transform.GetScale())(TextureAsset(L"Floor")).draw();
	}
}