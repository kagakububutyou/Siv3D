#include "BatteryAnimation.h"
#include "BatteryAttack.h"
#include "Battery.h"
#include "EnemyManager.h"
#include "Player.h"
#include "PlayerAttack.h"
#include "GameManager.h"
#include "Scroll.h"

#include "CharacterController.h"

CBatteryAnimation::CBatteryAnimation(std::shared_ptr<CTask> task) :
CPlayerState(task),
StopTexture(Point(1, 1)),
MoveTexture(Point(2, 2)),
GraphicChangeCounts(0)
{

}
///	èâÇﬂÇ…åƒÇ‘ä÷êîÅ@èâä˙âªån
void CBatteryAnimation::Start()
{
	TextureAsset::Register(L"Battery", L"engine/data/texture/Character/Enemy/Battery.png");
	TextureAsset::Register(L"BatteryWalk", L"engine/data/texture/Character/Enemy/Batteryaruki.png");
	TextureAsset::Register(L"BatteryAttack", L"engine/data/texture/Character/Enemy/BatteryAttack.png");
	TextureAsset::Register(L"tekiefekuto", L"engine/data/texture/Character/Enemy/tekiefekuto.png");

	StopTexturePos[MOVEDIREC::LEFT] = Point(0, 1);
	StopTexturePos[MOVEDIREC::RIGHT] = Point(2, 1);
	StopTexturePos[MOVEDIREC::UP] = Point(1, 0);
	StopTexturePos[MOVEDIREC::DOWN] = Point(1, 2);

	Cut[0] = 0; Cut[1] = 1; Cut[2] = 2; Cut[3] = 1;

	for (int i = MOVEDIREC::LEFT; i < MOVEDIREC::UP; i++)
	{
		for (int j = 0; j < CutNum; j++)
		{
			MoveTexturePos[i][j] = Point(Cut[j] + i * CutNum, CutNum - 1);
		}
	}
	for (int i = MOVEDIREC::UP; i < MOVEDIREC::DIREC; i++)
	{
		for (int j = 0; j < CutNum; j++)
		{
			MoveTexturePos[i][j] = Point(CutNum - 1, Cut[j] + (i - MOVEDIREC::UP) * CutNum);
		}
	}
}
///	âÊëúÇÃèÍèäÇï‘Ç∑ä÷êî
void CBatteryAnimation::Texture(MOVEDIREC Direc)
{
	StopTexture = StopTexturePos[Direc];

	GraphicChangeCounts++;

	for (int i = 0; i < 4; i++)
	{
		if (GraphicChangeCounts % 40 >= i * 10 && GraphicChangeCounts % 40 < (i + 1) * 10)
		{
			MoveTexture = MoveTexturePos[Direc][i];
		}
	}
}
///	ï˚å¸Çï‘Ç∑ä÷êî
CBatteryAnimation::MOVEDIREC CBatteryAnimation::Direc(Point player, Point scroll, Point enemy_pos, Point enemy_scale)
{
	int small[]	= { player.x, enemy_pos.x + enemy_scale.x / 2 - scroll.x, player.y, enemy_pos.y + enemy_scale.y / 2 - scroll.y };
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
///	ñàÉtÉåÅ[ÉÄåƒÇ‘ä÷êîÅ@çXêVÇ™ïKóvÇ»ä÷êî
void CBatteryAnimation::Update()
{
	auto player = (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->transform.GetPos());
	auto scroll = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	auto battery_pos = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0)->transform.GetPos());
	auto battery_scale = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0)->transform.GetScale());

	Texture(Direc(player, scroll, battery_pos, battery_scale));

}
///	ï`âÊä÷åWÇÃä÷êîÅ@ï`âÊÇµÇΩÇ¢ìzÇÕÇ±Ç±Ç÷
void CBatteryAnimation::Draw()
{
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	auto Battery = task->GetComponent<CBattery>(CEnemyManager::Battery, 0);
	auto BatteryAtk = task->GetComponent<CBatteryAttack>(CEnemyManager::BatteryAttack, 0);

	if (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior
		|| task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isCollision)
	{
		Rect(Battery->transform.GetPos() - pos, Battery->transform.GetScale())(TextureAsset(L"BatteryWalk")(TextureSize.x * MoveTexture.x, TextureSize.y * MoveTexture.y, TextureSize.x, TextureSize.y)).draw();
	}
	else if (CharacterController::AttackAnimation())
	{
		Rect(BatteryAtk->transform.GetPos(), BatteryAtk->transform.GetScale())(TextureAsset(L"tekiefekuto")(TextureSize.x * StopTexture.x, TextureSize.y * StopTexture.y, TextureSize.x, TextureSize.y)).draw();
		Rect(Battery->transform.GetPos() - pos, Battery->transform.GetScale())(TextureAsset(L"BatteryAttack")(TextureSize.x * StopTexture.x, TextureSize.y * StopTexture.y, TextureSize.x, TextureSize.y)).draw();
	}
	else
	{
		Rect(Battery->transform.GetPos() - pos, Battery->transform.GetScale())(TextureAsset(L"Battery")(TextureSize.x * StopTexture.x, TextureSize.y * StopTexture.y, TextureSize.x, TextureSize.y)).draw();
	}
}