#include "Goblin.h"
#include "MapRead.h"
#include "MiniMap.h"
#include "Scroll.h"
#include "GameManager.h"
#include "GameApplication.h"
#include "EnemyManager.h"

#include "Player.h"
#include "PlayerMove.h"
#include "Collision.h"
#include "PlayerAttack.h"


CGoblin::CGoblin(std::shared_ptr<CTask> task,Point pos) :
CActor(task, Transform(pos + Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2 - CMapRead::Size / 2), Point(CMapRead::Size/* / CMiniMap::MapScale*/, CMapRead::Size/* / CMiniMap::MapScale*/), Point(0, 0)), State::Live),
move(std::make_unique<CPlayerMove>(task)),
isCollision(false)
{
}

void CGoblin::Start()
{
	//transform.TransformPoint(Point(transform.GetPos().x / CMiniMap::MapScale + CGameApplication::ScreenWidth / 2 - (CMapRead::Width * CMapRead::Size / CMiniMap::MapScale) / 2,
		//transform.GetPos().y / CMiniMap::MapScale + CGameApplication::ScreenHeight / 2 - (CMapRead::Height * CMapRead::Size / CMiniMap::MapScale) / 2 - (CMapRead::Size / CMiniMap::MapScale) * 7 / 2));

	TextureAsset::Register(L"Goblin", L"engine/data/texture/Character/Enemy/パトローラー/patoro-ra- syoumen.png");
}
void CGoblin::OnCollision()
{
	
}
void CGoblin::Update()
{
	//move->Update();
	OnCollision();
}
void CGoblin::Draw()
{
	//auto pos = (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->transform.GetPos());
	//auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	//auto pos = (transform.GetPos() - scroll + Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2 - CMapRead::Size / 2), transform.GetScale());

	//Rect(transform.GetPos(), transform.GetScale()).draw(ColorF(0, 255, 0));

	//isCollision = true;

	auto atk = task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0);
	auto goblin = task->GetComponent<CGoblin>(CEnemyManager::Goblin, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());

	font(transform.GetPos() - pos).draw(0,100);

	if (Collision::RectToRect(transform.GetPos() - pos, transform.GetScale(), atk->transform.GetPos(), atk->transform.GetScale())
	&& atk->isCollision)
	{
		Rect(transform.GetPos() - pos, transform.GetScale())(TextureAsset(L"Goblin")).draw(ColorF(Palette::Yellow));
	}
	else
	{
		Rect(transform.GetPos() - pos, transform.GetScale())(TextureAsset(L"Goblin")).draw();
	}
}