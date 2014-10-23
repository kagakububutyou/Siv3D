#include "MapMove.h"
#include "CharacterController.h"
#include "MapScroll.h"
#include "Floor.h"
#include "GameManager.h"
#include "MapRead.h"

CMapScroll::CMapScroll(std::shared_ptr<CTask> task, Point pos) :
CActor(task, Transform(pos, Point(CMapRead::Size, CMapRead::Size), Point(0, 0)), State::Live),
move(std::make_unique<CMapMove>(task))
//camera(std::make_unique<CPlayerCamera>(task))
{

}

void CMapScroll::Start()
{

}

void CMapScroll::Update()
{
	//move->Update();

	//camera->Update();
}

void CMapScroll::Draw()
{
	
}