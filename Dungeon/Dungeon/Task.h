/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/

#pragma once

#include <unordered_map>
#include <string>
#include <memory>
#include "Noncopyable.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//【タスクの使用方法】
//
//		・まずタスクのインスタンを宣言する
//	
//		・インスタンスの初期化
//
//	・TaskのStart(),Update,Draw(),Remove()の書く場所
//	ゲーム管理クラスのコンストラクタの一番下にTask->Start();を書く
//	ゲーム管理クラスのUpdate関数の中に
//	Task->Update();
//	Task->Draw();
//	Task->Remove();
//	この順で書いてください
//	これで登録したオブジェクトはすべて処理が回るようになる
//
//	・タスクに登録するまでの手順

//	①スマートポインタでインスタンスを宣言、初期化
//	Player = std::make_shared(new CActor());
//
//	②アクターにオブジェクトの情報を入れ込む
//	Player->Append(new CPlayer());
//
// ③オブジェクトをタスクに入れる
//	Task->Append("登録名",登録するオブジェクト(インスタンス));
// 例)Task->Append("Player",Player);
//	
//	・注意点
//	登録してない名前は必ずエラーが出る！
//		必ず登録したなめは覚えておく！
//	登録した数以上のもの取得しないようにする
//	
//	登録したオブジェクトを他の所で取得したい場合
//	Task->GetComponent<取得したいクラス名>(登録した名前、登録した番号);
//	例)Task->GetComponent<CPlayer>("Player",0)
//	
//	・登録した要素をすべて取得する場合
//	Task->GetComponents<取得したいクラス名>(登録した名前、登録した番号);
//	例)Task->GetComponents<CEnemy>("Enemy");
//	
//	・登録した要素の数を取得する
//	TAsk->GetSize(登録した名前);
//	例) Task->GetSize("Enemy");
//	
//	・for(auto&)でタスクの夕ソを使う方法
//	基本的に基底クラスのObjectのクラスに入ってる要素した取得できない
//	例)
//	for(auto &obj : Task->GetActor(登録名))
//	{
//		obj->メソッド(関数) or 変数;
//	}
//	
//		派生クラスの要素を取得したい場合
//	DynamicCast<取得したいクラス名>(要素)
//	例)
//	for(auto &obj : Task->GetActor(登録名))
//	{
//		DynamicCast<クラス名>
//	}
//
//	・タスクに登録したオブジェクトはメモリの開放はしなくいい
//	・登録したオブジェクトを途中で削除したい場合は、isDeleteをtrueにすれば次のフレームで削除される
//	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class CActor;

class CTask
{
private:
	std::unordered_map < std::string, std::shared_ptr<CActor>> object;

public:

	// ------------------------------
	//	Actorを入れる
	// ------------------------------
	void Append(std::string name, std::shared_ptr<CActor> actor);

	// ------------------------------
	//	Actorを空にする
	// ------------------------------
	void Clear();

	// ------------------------------
	//	タスクから削除する
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

	// ------------------------------------------------------
	//	オブジェクトを取得する(IDまで取得する)
	// ------------------------------------------------------
	template<typename OBJ>
	std::shared_ptr<OBJ> GetComponet(const std::string &name, const int Id)
	{
		auto it = object.begin();
		it = object.find(name);
		assert(it != object.end());

		return std::dynamic_pointer_cast<OBJ>(it->second->Getcomponent(Id));
	}

	// ------------------------------------------------------
	//	オブジェクトを取得する(Actorの中にあるクラスの全体を取得)
	// ------------------------------------------------------
	std::shared_ptr<CActor> GetComponents(const std::string &name);

	// ------------------------------------------------------
	//	アクター自体を取得する
	// ------------------------------------------------------
	std::vector<std::shared_ptr<CActor>> GetActor(const std::stringbuf &name);

	// ------------------------------------------------------
	//	オブジェクトの数を取得する
	// ------------------------------------------------------
	void GetSize(const std::string &name);

};
