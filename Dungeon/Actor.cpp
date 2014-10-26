#include "Actor.h"

// ------------------------------
//	オブジェクトを入れる
// ------------------------------
void CActor::Append(std::shared_ptr<CActor> obj)
{
	assert(obj);
	actor.emplace_back(obj);
}

// ------------------------------
//	消去する
// ------------------------------
void CActor::Remove()
{
	Erase_if(actor, [](std::shared_ptr<CActor> &obj)
	{
		return obj->isDelete;
	});
}

// ------------------------------
//	アップデートの前に呼ばれる処理
// ------------------------------
void CActor::Start()
{
	for (auto &obj : actor)
	{
		obj->Start();
	}
}

// ------------------------------
//	アップデート
// ------------------------------
void CActor::Update()
{
	for (auto &obj : actor)
	{
		obj->Update();
	}
}

// ------------------------------
//	描画
// ------------------------------
void CActor::Draw()
{
	for (auto &obj : actor)
	{
		obj->Draw();
	}
}

// ------------------------------
//	オブジェクトを取得する
// ------------------------------
std::shared_ptr<Object> CActor::GetComponent(const int id)const
{
	assert(id >= 0);
	assert(id <= (int)actor.size() - 1);

	return actor[id];
}