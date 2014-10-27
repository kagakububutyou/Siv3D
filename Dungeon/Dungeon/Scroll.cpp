#include "Scroll.h"
#include "PlayerMove.h"
#include "MapRead.h"
#include "MiniMap.h"
#include "GameApplication.h"

CScroll::CScroll(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos, Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), State::Live),
move(std::make_unique<CPlayerMove>(task))
{

}

void CScroll::Start()
{
	/*
	transform.TransformPoint(Point(transform.GetPos().x / CMiniMap::MapScale + CGameApplication::ScreenWidth / 2 - (CMapRead::Width * CMapRead::Size / CMiniMap::MapScale) / 2,
		transform.GetPos().y / CMiniMap::MapScale + CGameApplication::ScreenHeight / 2 - (CMapRead::Height * CMapRead::Size / CMiniMap::MapScale) / 2 - (CMapRead::Size / CMiniMap::MapScale) * 7 / 2));
		//*/
}

void CScroll::Update()
{
	move->Update();
}

void CScroll::Draw()
{
	/*
	Rect(transform.GetPos().x / CMiniMap::MapScale + CGameApplication::ScreenWidth / 2 - (CMapRead::Width * CMapRead::Size / CMiniMap::MapScale) / 2,
		transform.GetPos().y / CMiniMap::MapScale + CGameApplication::ScreenHeight / 2 - (CMapRead::Height * CMapRead::Size / CMiniMap::MapScale) / 2 - (CMapRead::Size / CMiniMap::MapScale) * 7 / 2,
		transform.GetScale().x / CMiniMap::MapScale, transform.GetScale().y / CMiniMap::MapScale).draw(Palette::Blue);
		//*/

	//Rect(transform.GetPos(), transform.GetScale().x / CMiniMap::MapScale, transform.GetScale().y / CMiniMap::MapScale).draw(Palette::Blue);
}