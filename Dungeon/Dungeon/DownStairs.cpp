#include "DownStairs.h"
#include "MapRead.h"
#include "Player.h"
#include "GameManager.h"
#include "GameApplication.h"
#include "GameManager.h"
#include "Scroll.h"


CDownStairs::CDownStairs(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos + Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2) - Point(0, CMapRead::Size / 2), Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), State::Live)
{

}
void CDownStairs::Start()
{
	if (!TextureAsset(L"DownStairs"))
	{
		TextureAsset::Register(L"DownStairs", L"engine/data/texture/MapChip/map_stair_down.png");
	}
}
void CDownStairs::Draw()
{
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());

	Rect(transform.GetPos() - pos, transform.GetScale())(TextureAsset(L"DownStairs")).draw();
}