#include "UpStairs.h"
#include "MapRead.h"
#include "Player.h"
#include "GameManager.h"
#include "GameApplication.h"
#include "GameManager.h"
#include "Scroll.h"


CUpStairs::CUpStairs(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos + Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2) - Point(0, CMapRead::Size / 2), Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), State::Live)
{

}
void CUpStairs::Start()
{
	if (!TextureAsset(L"UpStairs"))
	{
		TextureAsset::Register(L"UpStairs", L"engine/data/texture/MapChip/map_stair_up.png");
	}
}
void CUpStairs::Draw()
{
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());

	Rect(transform.GetPos() - pos, transform.GetScale())(TextureAsset(L"DownStairs")).draw();
}