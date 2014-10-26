#include "Scroll.h"
#include "PlayerMove.h"
#include "MapRead.h"
#include "MiniMap.h"

CScroll::CScroll(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos, Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), State::Live),
move(std::make_unique<CPlayerMove>(task))
{

}

void CScroll::Start()
{

}

void CScroll::Update()
{
	move->Update();
}

void CScroll::Draw()
{
	//Rect(transform.GetPos(), transform.GetScale()).draw(Palette::Antiquewhite);
	Rect(transform.GetPos().x / CMiniMap::MapScale, transform.GetPos().y / CMiniMap::MapScale, transform.GetScale().x / CMiniMap::MapScale, transform.GetScale().y / CMiniMap::MapScale).draw(Palette::Blue);
}