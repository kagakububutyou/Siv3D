#include "PlayerCamera.h"
#include "Player.h"
#include "GameManager.h"

CPlayerCamera::CPlayerCamera(std::shared_ptr<CTask> task) :
CPlayerState(task),
camera(std::make_unique<CCamera>(Float3(300, 200, -700), Float3(300, 0, 0)))
{

}
void CPlayerCamera::Update()
{
	auto player_pos = task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->transform.GetPos();
	camera->TransformPoint(Float3(player_pos.x, player_pos.y+50, -350));
	camera->LookAt(Float3(player_pos.x, player_pos.y, 0));
	camera->Update();
}