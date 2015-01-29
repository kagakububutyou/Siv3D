#include "MiniMapPlayer.h"
#include "PlayerMove.h"
#include "MapRead.h"
#include "MiniMap.h"
#include "GameApplication.h"

CMiniMapPlayer::CMiniMapPlayer(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos, Point(CMapRead::Size / CMiniMap::MapScale, CMapRead::Size / CMiniMap::MapScale), Point(0, 0)), State::Live)
{

}
///	‰‚ß‚ÉŒÄ‚ÔŠÖ”@‰Šú‰»Œn
void CMiniMapPlayer::Start()
{
	transform.TransformPoint(Point(transform.GetPos().x / CMiniMap::MapScale + CGameApplication::ScreenWidth / 2 - (CMapRead::Width * CMapRead::Size / CMiniMap::MapScale) / 2,
		transform.GetPos().y / CMiniMap::MapScale + CGameApplication::ScreenHeight / 2 - (CMapRead::Height * CMapRead::Size / CMiniMap::MapScale) / 2 - (CMapRead::Size / CMiniMap::MapScale) * 4));
}
///	–ˆƒtƒŒ[ƒ€ŒÄ‚ÔŠÖ”@XV‚ª•K—v‚ÈŠÖ”
void CMiniMapPlayer::Update()
{
	///	®—‚µ‚Ä‚½‚ç‚È‚­‚È‚Á‚½
}
///	•`‰æŠÖŒW‚ÌŠÖ”@•`‰æ‚µ‚½‚¢“z‚Í‚±‚±‚Ö
void CMiniMapPlayer::Draw()
{
	auto DisplayMiniMap = task->GetComponent<CMiniMap>("mini_map", 0)->DisplayMiniMap;
	if (DisplayMiniMap)
	{
		Rect(transform.GetPos(), transform.GetScale()).draw(Palette::Blue);
	}
}