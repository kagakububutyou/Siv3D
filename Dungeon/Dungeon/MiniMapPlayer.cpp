#include "MiniMapPlayer.h"
#include "PlayerMove.h"
#include "MapRead.h"
#include "MiniMap.h"
#include "GameApplication.h"

CMiniMapPlayer::CMiniMapPlayer(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos, Point(CMapRead::Size / CMiniMap::MapScale, CMapRead::Size / CMiniMap::MapScale), Point(0, 0)), State::Live)
{

}
///	初めに呼ぶ関数　初期化系
void CMiniMapPlayer::Start()
{
	transform.TransformPoint(Point(transform.GetPos().x / CMiniMap::MapScale + CGameApplication::ScreenWidth / 2 - (CMapRead::Width * CMapRead::Size / CMiniMap::MapScale) / 2,
		transform.GetPos().y / CMiniMap::MapScale + CGameApplication::ScreenHeight / 2 - (CMapRead::Height * CMapRead::Size / CMiniMap::MapScale) / 2 - (CMapRead::Size / CMiniMap::MapScale) * 4));
}
///	毎フレーム呼ぶ関数　更新が必要な関数
void CMiniMapPlayer::Update()
{
	///	整理してたらなくなった
}
///	描画関係の関数　描画したい奴はここへ
void CMiniMapPlayer::Draw()
{
	auto DisplayMiniMap = task->GetComponent<CMiniMap>("mini_map", 0)->DisplayMiniMap;
	if (DisplayMiniMap)
	{
		Rect(transform.GetPos(), transform.GetScale()).draw(Palette::Blue);
	}
}