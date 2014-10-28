#include "Wall.h"
#include "MapRead.h"
#include "GameManager.h"
#include "GameApplication.h"
#include "Player.h"
#include "PlayerMove.h"
#include "Scroll.h"
#include "MiniMap.h"

#include "PlayerMove.h"

CWall::CWall(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos - Point(0, CMapRead::Size / 2) + Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2), Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), State::Live),
move(std::make_unique<CPlayerMove>(task))
{

}

void CWall::Start()
{

	//MessageBox::Show(L"ƒGƒ‰[", L"“Ç‚Ýž‚Ý‚ÉŽ¸”s‚µ‚Ü‚µ‚½B");


	TextureAsset::Register(L"Wall", L"engine/data/texture/MapChip/map_ground_simple.png");
	
}
void CWall::Update()
{
	
}
void CWall::Draw()
{
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());

	//transform.TransformPoint(transform.GetPos() - pos);

	Rect(transform.GetPos() - pos, transform.GetScale())(TextureAsset(L"Wall")).draw();
}