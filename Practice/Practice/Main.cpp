
/*
		シューティングゲームサンプル
		渡辺先生に初めてもらったコード
*/
//	Siv3Dを使用するためのインクルード
# include <Siv3D.hpp>
//	------------------------------------------------------------------------------------------------------------------------
//	定義
//	------------------------------------------------------------------------------------------------------------------------
const int SCREEN_WIDTH = 640;				//		ウインドウの横幅
const int SCREEN_HEIGHT = 480;				//		ウインドウの縦幅

enum ID	//		オブジェクトのID
{
	PLAYER = 1,		//		プレイヤー
	ENEMY,			//		敵
};

enum STATE		//		オブジェクトの状態
{
	NONE,			//		死亡確認
	LIVE,				//		生きている
	HIT,				//		当たった時
};

//		プレイヤー情報用データ
const int PLAYER_WIDTH = 32;																//		プレイヤーの横幅
const int PLAYER_HEIGHT = 32;															//		プレイヤーの縦幅
const int PLAYER_START_X	= (SCREEN_WIDTH / 2);								//		初期位置
const int PLAYER_START_Y = (SCREEN_HEIGHT - PLAYER_HEIGHT);		//		初期位置
const Color PLAYER_COLOR = Color(255, 255, 255);								//		プレイヤーの色
const int PLAYER_SHOT_WIDTH = 16;													//		プレイヤーの弾の横幅
const int PLAYER_SHOT_HEIGHT = 16;													//		プレイヤーの弾の縦幅
const int PLAYER_SHOT_SPEED = 8;														//		プレイヤーの弾の早さ
const int PLAYER_MOVESPEED = 4;														//		プレイヤーの早さ

//		敵情報用のデータ
const int ENEMY_START_X = 0;								//		初期位置
const int ENEMY_START_Y = 0;								//		初期位置
const int ENEMY_WIDTH = 32;									//		敵の横幅
const int ENEMY_HEIGHT = 32;									//		敵の縦幅
const Color ENEMY_COLOR = Color(0, 255, 0);			//		敵の色
const int ENEMY_SHOT_WIDTH = 16;							//		敵の弾の横幅
const int ENEMY_SHOT_HEIGHT = 16;						//		敵の弾の縦幅
const int ENEMY_SHOT_SPEED = 8;							//		敵の弾の早さ
const int ENEMY_MOVESPEED = 4;							//		敵の早さ
const int ENEMY_SHOT_MIN_TIME = 100;					//		敵がショットを打つまでの最低間隔
const int ENEMY_SHOT_MAX_TIME = 400;					//		敵がショットを打つまでの最大間隔

//		背景情報
const Color BG_COLOR = Color(0, 0, 0);
//	------------------------------------------------------------------------------------------------------------------------
//	構造体定義
//	------------------------------------------------------------------------------------------------------------------------
class OBJECT
{
public:
	OBJECT(){}
	~OBJECT(){}
public:
	int x;				//		X座標
	int y;				//		Y座標
	int width;		//		横幅
	int height;		//		縦幅
	Color color;	//		色
	int state;		//		状態を表す変数

private:
};

//	------------------------------------------------------------------------------------------------------------------------
//	グローバル変数定義
//	------------------------------------------------------------------------------------------------------------------------

OBJECT Player;				//	プレイヤー情報
OBJECT Enemy;				//	敵情報
OBJECT PlayerShot;		//	プレイヤーのショット情報
OBJECT EnemyShot;		//	敵のショット情報

int enemyMoveDirc = 1;	//	敵の移動方向
int enemyShotTime = 0;	//	敵が弾をうつタイミング

//	--------------------------------------------------------------------
//	プレイヤー情報の初期化関数
//	--------------------------------------------------------------------
void InitPlayer()
{
	//	プレイヤーデータに初期値を入れる
	Player.x = PLAYER_START_X;
	Player.y = PLAYER_START_Y;
	Player.width = PLAYER_WIDTH;
	Player.height = PLAYER_HEIGHT;
	Player.color = PLAYER_COLOR;
	Player.state = STATE::LIVE;

	//	プレイヤーショットデータに初期値を入れる
	//	ショットは存在しない状態からゲームが開始されるので-1で初期化する
	//	座標データはショットを打つまでわからないのでまだ入れない
	PlayerShot.width = PLAYER_SHOT_WIDTH;
	PlayerShot.height = PLAYER_SHOT_HEIGHT;
	PlayerShot.color = PLAYER_COLOR;
	PlayerShot.state = STATE::NONE;
}
//	--------------------------------------------------------------------
//	敵がショットをうつまでのタイミングを計算する
//	--------------------------------------------------------------------
void CalcEnemyShotTiming()
{
	//	ショットを打つまでの間隔を決める
	//	ENEMY_SHOT_MIN_TIMEからENEMY_SHOT_MAX_TIMEまでの間の乱数をつくる
	enemyShotTime = Random(ENEMY_SHOT_MIN_TIME, ENEMY_SHOT_MAX_TIME);
}
//	--------------------------------------------------------------------
//	敵情報の初期化関数
//	--------------------------------------------------------------------
void InitEnemy()
{
	//	敵データの初期値を入れる
	Enemy.x = Random(SCREEN_WIDTH - ENEMY_WIDTH);	//	毎回ランダムな場所に出現させる
	Enemy.y = ENEMY_START_Y;
	Enemy.width = ENEMY_WIDTH;
	Enemy.height = ENEMY_HEIGHT;
	Enemy.color = ENEMY_COLOR;
	Enemy.state = STATE::LIVE;

	//	敵ショットデータに初期値を入れる
	//	ショットは存在しない状態からゲームが開始されるので-1で初期化する
	//	座標データはショットを打つまでわからないのでまだ入れない
	EnemyShot.width = ENEMY_SHOT_WIDTH;
	EnemyShot.height = ENEMY_SHOT_HEIGHT;
	EnemyShot.color = ENEMY_COLOR;
	EnemyShot.state = STATE::NONE;

	//	敵の初期移動方向を計算
	//	より広くあいている方向へ移動する
	if (Enemy.x < SCREEN_WIDTH / 2)
	{
		enemyMoveDirc = 1;
	}
	else
	{
		enemyMoveDirc = -1;
	}

	CalcEnemyShotTiming();

	return;
}
//	--------------------------------------------------------------------
//	ゲーム情報を初期化する関数
//	--------------------------------------------------------------------
void InitGame()
{
	//	プレイヤー情報の初期化
	InitPlayer();
	//	敵情報の初期化
	InitEnemy();

	return;
}
//	--------------------------------------------------------------------
//	オブジェクト描画を行う関数
//	--------------------------------------------------------------------
void DrawObject(OBJECT target)
{
	//	オブジェクトが存在しないときは描画しなくてよい
	if (target.state == STATE::NONE) return;

	//	オブジェクト描画
	Rect(target.x,			//	X1座標
		target.y,			//	Y1座標
		target.x + target.width - 1,	//	X2座標　この引数は幅を指定するのではなく座標をしているので-1している。
		target.y + target.height - 1)	//	Y2座標　この引数は幅を指定するのではなく座標をしているので-1している。
		.draw(target.color);//	色

	return;
}
//	--------------------------------------------------------------------
//	背景を塗りつぶす関数
//	--------------------------------------------------------------------
void DrawBG()
{
	Graphics::SetBackground(BG_COLOR);

	return;
}
//	--------------------------------------------------------------------
//	objAとobjBが衝突しているかを調べる
//	引数：OBJECT objA,objB...衝突判定したいオブジェクト
//	戻り値：1...衝突している 0...衝突していない
//	--------------------------------------------------------------------
int IsHit(OBJECT objA, OBJECT objB)
{
	int x0 = objA.x;
	int y0 = objA.y;
	int x1 = objA.x + objA.width - 1;
	int y1 = objA.y + objA.height - 1;

	int x2 = objB.x;
	int y2 = objB.y;
	int x3 = objB.x + objB.width - 1;
	int y3 = objB.y + objB.height - 1;

	//	二つの矩形が何かしらの形で重なっているか？
	if (x0 < x3 && x2 < x1 && y0 < y3 && y2 < y1)
	{
		//	重なっていた
		return 1;
	}

	//	重なってなかった
	return 0;
}
//	--------------------------------------------------------------------
//	弾を生成する関数
//	引数：int shooterID...弾をうつのはプレイヤーか敵なのかの情報
//	引数：OBJECT shooter...弾をうったオブジェクト情報
//	--------------------------------------------------------------------
void CreateShot(int shooterID, OBJECT shooter)
{
	//	自分の弾か敵の弾なのかで処理を変更
	switch (shooterID)
	{
	case ID::PLAYER:
		PlayerShot.state = STATE::LIVE;
		PlayerShot.x = shooter.x + shooter.width / 2 - PlayerShot.width / 2;	//	プレイヤーの真ん中から発射
		PlayerShot.y = shooter.y - PlayerShot.height;
		break;
	case ID::ENEMY:
		EnemyShot.state = STATE::LIVE;
		EnemyShot.x = shooter.x + shooter.width / 2 - EnemyShot.width / 2;	//	敵の真ん中から発射
		EnemyShot.y = shooter.y + shooter.height;
		break;
	}
}

//	初期化
void init()
{
	DrawBG();

	Window::Resize(SCREEN_WIDTH, SCREEN_HEIGHT);
}
//	メイン関数
void Main()
{
	//	初期化
	init();

	while (System::Update())
	{
		
	}
}
