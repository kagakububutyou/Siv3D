#include "MiniMap.h"
#include "MapRead.h"
#include "Player.h"
#include "GameManager.h"
#include "CharacterController.h"

CMiniMap::CMiniMap(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos - Point(0, CMapRead::Size / 2), Point(CMapRead::Size / CMiniMap::MapScale, CMapRead::Size / CMiniMap::MapScale), Point(0, 0)), State::Live)
{

}
void CMiniMap::Start()
{
	DisplayMiniMap = false;
}
void CMiniMap::JudgmentDisplayMiniMap()
{
	if (CharacterController::DisplayMiniMapKey() && DisplayMiniMap == false)
	{
		DisplayMiniMap = true;
		return;
	}
	if (CharacterController::DisplayMiniMapKey() && DisplayMiniMap == true)
	{
		DisplayMiniMap = false;
		return;
	}
}
void CMiniMap::Update()
{
	JudgmentDisplayMiniMap();
}
void CMiniMap::Draw()
{
	if (DisplayMiniMap)
	{
		Rect(transform.GetPos(), transform.GetScale()).draw(ColorF(0, 0, 255, 0.5));
	}
}