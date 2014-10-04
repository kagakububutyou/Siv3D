/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/

#pragma once
#include "Object.h"

class CTask;
///	アクタークラス
class CActor :public Object
{
private:

	std::vector<std::shared_ptr<CActor>> actor;

protected:

	bool isDelete;							///	消去するか調べる
	std::shared_ptr<CTask> task;		///	 タスク

public:
	
	CActor() : isDelete(false){}
	CActor(std::shared_ptr<CTask> task, Transform transform, State state) :
		task(task), Object(transform, state), isDelete(false){}

	virtual ~CActor() = default;

	// ------------------------------
	//	オブジェクトを入れる
	// ------------------------------
	void Append(std::shared_ptr<CActor> obj);

	// ------------------------------
	//	オブジェクトを空にする
	// ------------------------------
	void Clear(){ actor.clear(); }

	// ------------------------------
	//	削除する
	// ------------------------------
	void Remove();

	// ------------------------------
	//	アップデートの前に呼ばれる処理
	// ------------------------------
	void Start();

	// ------------------------------
	//	アップデート
	// ------------------------------
	void Update();

	// ------------------------------
	//	描画
	// ------------------------------
	void Draw();

	// ------------------------------
	//	オブジェクトを取得する
	// ------------------------------
	std::shared_ptr<Object> GetComponent(const int id)const;

	// ------------------------------
	//	自分自身を取得する
	// ------------------------------
	std::vector<std::shared_ptr<CActor>> GetActor()const{ return actor; }

	// ------------------------------
	//	オブジェクトの数を取得する
	// ------------------------------
	int GetSize()const{ return actor.size(); }

	// ---------------------------------------------------------------
	//	ダイナミックキャスト
	//	for(auto&)は基本基底クラスCActorの要素でしか取得できないが、
	//	これを使用すると派生クラスの要素まで取得できる
	// ---------------------------------------------------------------
	template<class CLASS, typename OBJ>
	inline std::shared_ptr<CLASS> DynamicCast(OBJ *obj)
	{
		return std::dynamic_pointer_cast<CLASS>(obj);
	}
};

