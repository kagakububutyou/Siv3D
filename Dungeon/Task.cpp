#include "Task.h"
#include "Actor.h"
#include <assert.h>

// ------------------------------
//　Actorを入れる
// ------------------------------
void CTask::Append(std::string name, std::shared_ptr<CActor> actor)
{
	assert(actor);
	object.insert(std::make_pair(name, actor));
}
// ------------------------------
//　Actorを空にする
// ------------------------------
void CTask::Clear()
{
	object.clear();
}
// ------------------------------
//　タスクから消去する
// ------------------------------
void CTask::Remove()
{
	for (auto &obj : object)
	{
		obj.second->Remove();
	}
}
// ----------------------------------
//　アップデートの前に呼ばれる処理
// ----------------------------------
void CTask::Start()
{
	for (auto &obj : object)
	{
		obj.second->Start();
	}
}
// ------------------------------
//　アップデート
// ------------------------------
void CTask::Update()
{
	for (auto &obj : object)
	{
		obj.second->Update();
	}
}
// ------------------------------
//　描画
// ------------------------------
void CTask::Draw()
{
	for (auto &obj : object)
	{
		obj.second->Draw();
	}
}
// -------------------------------------------------------------
// オブジェクトを取得する（Actorの中にあるクラスの全体を取得）
// -------------------------------------------------------------
std::shared_ptr <CActor> CTask::GetComponents(const std::string &name)
{
	auto it = object.begin();
	it = object.find(name);
	assert(it != object.end());

	return it->second;
}
// ------------------------------------------------------
//　アクター自体を取得する
// ------------------------------------------------------
std::vector<std::shared_ptr<CActor>> CTask::GetActor(const std::string &name)
{
	auto it = object.begin();
	it = object.find(name);
	assert(it != object.end());

	return it->second->GetActor();
}
// ------------------------------------------
// オブジェクトの数を取得
// ------------------------------------------
int CTask::GetSize(const std::string &name)
{
	auto it = object.begin();
	it = object.find(name);

	assert(it != object.end());

	return it->second->GetSize();
}