#include "UpStairs.h"
#include "MapRead.h"
#include "Player.h"
#include "GameManager.h"
#include "GameApplication.h"
#include "GameManager.h"
#include "Scroll.h"

#include "Collision.h"

#include "Scene.h"

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
void CUpStairs::ChangeSceneClear()
{
	auto player = task->GetComponent<CPlayer>(CGameManager::PlayerName, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	auto UpStairs = task->GetComponent<CUpStairs>(CGameManager::UpStairs, 0);

	if (Collision::RectToRect(UpStairs->transform.GetPos() - pos, UpStairs->transform.GetScale(),
										player->transform.GetPos(), player->transform.GetScale()))
	{		
		if(player->GetHP() >= 0)	CGameManager::Clear = true;
		if (player->GetHP() < 0) CGameManager::Bat = true;
		//scene->ChangeScene(CSceneManager::Scene::Clear);
	}
}
void CUpStairs::Update()
{
	ChangeSceneClear();
}
void CUpStairs::Draw()
{
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());

	Rect(transform.GetPos() - pos, transform.GetScale())(TextureAsset(L"UpStairs")).draw();
}