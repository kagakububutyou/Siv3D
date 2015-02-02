#include "PatrollerAnimation.h"
#include "PatrollerAttack.h"
#include "Patroller.h"
#include "EnemyManager.h"
#include "Player.h"
#include "PlayerAttack.h"
#include "GameManager.h"
#include "Scroll.h"
#include "Collision.h"
#include "CharacterController.h"

#include "Transform.h"
#include "GameApplication.h"

CPatrollerAnimation::CPatrollerAnimation(std::shared_ptr<CTask> task) :
CPlayerState(task),
MoveTexture(Point(1, 1))
{

}

void CPatrollerAnimation::Start()
{
	TextureAsset::Register(L"Patroller", L"engine/data/texture/Character/Enemy/Patroller.png");
	TextureAsset::Register(L"Fire", L"engine/data/texture/Character/Enemy/Fire.png");

	MoveTexturePos[MOVEDIREC::LEFT] = Point(0, 1);
	MoveTexturePos[MOVEDIREC::RIGHT] = Point(2, 1);
	MoveTexturePos[MOVEDIREC::UP] = Point(1, 0);
	MoveTexturePos[MOVEDIREC::DOWN] = Point(1, 2);
}
///	âÊëúÇÃèÍèäÇï‘Ç∑ä÷êî
void CPatrollerAnimation::Texture(MOVEDIREC Direc)
{
	MoveTexture = MoveTexturePos[Direc];
}
///	ï˚å¸Çï‘Ç∑ä÷êî
CPatrollerAnimation::MOVEDIREC CPatrollerAnimation::Direc(Point player, Point scroll, Point enemy_pos, Point enemy_scale)
{
	int small[] = { player.x, enemy_pos.x + enemy_scale.x / 2 - scroll.x, player.y, enemy_pos.y + enemy_scale.y / 2 - scroll.y };
	int big[] = { enemy_pos.x - enemy_scale.x / 2 - scroll.x, player.x, enemy_pos.y - enemy_scale.y / 2 - scroll.y, player.y };
	MOVEDIREC direc[] = { MOVEDIREC::LEFT, MOVEDIREC::RIGHT, MOVEDIREC::UP, MOVEDIREC::DOWN };

	for (int i = 0; i < MOVEDIREC::DIREC; i++)
	{
		if (small[i] < big[i])
		{
			return direc[i];
		}
	}

	return MOVEDIREC::DOWN;
}
void CPatrollerAnimation::Update()
{
	auto player = (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->transform.GetPos());
	auto scroll = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	auto patroller_pos = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0)->transform.GetPos());
	auto patroller_scale = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0)->transform.GetScale());

	Texture(Direc(player, scroll, patroller_pos, patroller_scale));
}

void CPatrollerAnimation::Draw()
{
	auto atk = task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	auto patroller = task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0);
	auto patro_atk = task->GetComponent<CPatrollerAttack>(CEnemyManager::PatrollerAttack, 0);

	if (Collision::RectToRect(patroller->transform.GetPos() - pos, patroller->transform.GetScale(), atk->transform.GetPos(), atk->transform.GetScale())
		&& atk->isCollision)
	{
		Rect(patroller->transform.GetPos() - pos, patroller->transform.GetScale())(TextureAsset(L"Patroller")(TextureSize.x * MoveTexture.x, TextureSize.y * MoveTexture.y, TextureSize.x, TextureSize.y)).draw(ColorF(Palette::Yellow));
	}
	else if (CharacterController::AttackKey())
	{
		Rect(patro_atk->transform.GetPos(), patro_atk->transform.GetScale())(TextureAsset(L"Fire")(TextureSize.x * MoveTexture.x, TextureSize.y * MoveTexture.y, TextureSize.x, TextureSize.y)).draw();
		Rect(patroller->transform.GetPos() - pos, patroller->transform.GetScale())(TextureAsset(L"Patroller")(TextureSize.x * MoveTexture.x, TextureSize.y * MoveTexture.y, TextureSize.x, TextureSize.y)).draw();
	}
	else
	{
		Rect(patroller->transform.GetPos() - pos, patroller->transform.GetScale())(TextureAsset(L"Patroller")(TextureSize.x * MoveTexture.x, TextureSize.y * MoveTexture.y, TextureSize.x, TextureSize.y)).draw();
	}
}