#include "PlayerCamera.h"
#include "Player.h"
#include "GameManager.h"

CPlayerCamera::CPlayerCamera(std::shared_ptr<CTask> task) :
CPlayerState(task),
camera(std::make_unique<CCamera>(Point(300, 200, -700), Point(300, 0, 0)))
{

}
void CPlayerCamera::Update()
{
	auto player_pos = task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->transform.GetPos();
	camera->TransformPoint(Point(player_pos.x, player_pos.y+50, -350));
	camera->LookAt(Point(player_pos.x, player_pos.y + 50, 0));
	camera->Update();
}