#include "Floor.h"
#include "MapRead.h"
#include "GameManager.h"
#include "GameApplication.h"
#include "Player.h"
#include "PlayerMove.h"
#include "Scroll.h"
#include "MiniMap.h"

CFloor::CFloor(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos + Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2) - Point(0, CMapRead::Size / 2), Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), State::Live)
{

}
void CFloor::Start()
{
	if (!TextureAsset(L"Floor"))
	{
		TextureAsset::Register(L"Floor", L"engine/data/texture/MapChip/map_ground_white.png");
	}
}
void CFloor::Update()
{

}
void CFloor::Draw()
{
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());

	Rect(transform.GetPos() - pos, transform.GetScale())(TextureAsset(L"Floor")).draw();
}