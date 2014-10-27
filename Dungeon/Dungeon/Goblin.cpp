#include "Goblin.h"
#include "MapRead.h"
#include "MiniMap.h"
#include "Scroll.h"
#include "GameManager.h"
#include "GameApplication.h"

#include "Player.h"
#include "PlayerMove.h"


CGoblin::CGoblin(std::shared_ptr<CTask> task,Point pos) :
CActor(task, Transform(pos, Point(CMapRead::Size/* / CMiniMap::MapScale*/, CMapRead::Size/* / CMiniMap::MapScale*/), Point(0, 0)), State::Live),
move(std::make_unique<CPlayerMove>(task))
{
}

void CGoblin::Start()
{
	//transform.TransformPoint(Point(transform.GetPos().x / CMiniMap::MapScale + CGameApplication::ScreenWidth / 2 - (CMapRead::Width * CMapRead::Size / CMiniMap::MapScale) / 2,
		//transform.GetPos().y / CMiniMap::MapScale + CGameApplication::ScreenHeight / 2 - (CMapRead::Height * CMapRead::Size / CMiniMap::MapScale) / 2 - (CMapRead::Size / CMiniMap::MapScale) * 7 / 2));
}

void CGoblin::Update()
{
	move->Update();
}
void CGoblin::Draw()
{
	//auto pos = (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->transform.GetPos());
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	//auto pos = (transform.GetPos() - scroll + Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2 - CMapRead::Size / 2), transform.GetScale());

	//Rect(transform.GetPos(), transform.GetScale()).draw(ColorF(0, 255, 0));

	Rect(transform.GetPos() - pos + Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2 - CMapRead::Size / 2), transform.GetScale()).draw(ColorF(0, 255, 0));
}