/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include <Siv3D.hpp>
#include "Noncopyable.h"

class CSceneManager;
class CGameApplication;

///	シーンの基底クラス
class CScene :private Noncopyable
{
public:
	CScene(std::shared_ptr<CSceneManager> scene) :scene(scene){}
	virtual ~CScene() = default;

	virtual void Init() = 0;
	virtual void Update() = 0;

protected:
	std::shared_ptr<CSceneManager> scene;	///	シーン管理

private:

};

///	シーン管理
class CSceneManager :private Noncopyable
{
public:
	enum class Scene;

	CSceneManager(CGameApplication *app);

	void Update();

	///	次のシーンに行かせる処理
	void ChangeScene(Scene next_scene);

	///	シーン
	enum class Scene
	{
		Title,		///	タイトル
		Menu,	///	メニュー
		Game,	///	ゲーム
		Clear,	///	クリア
	};
private:

	///	フェードアウト
	void FadeOut();

	///	シーンの初期化
	void ScenenInit();

	///	シーンのアップデート
	void SceneUpdate();

	///	シーン管理の状態
	enum class State
	{
		Init,		///	初期化
		Update,	///	アップデート処理
	};

	std::shared_ptr<CScene> scene;			///	シーンのインスタンス	
	std::shared_ptr<CScene> next_scene;	///	シーンのインスタンス
	std::shared_ptr<CGameApplication> app;	///	アプリケーション

	State state;	///	シーン管理の状態
	double alpha;	///	フェードアウト用の変数
	bool isFade;	///	フェードアウトフラグ
};