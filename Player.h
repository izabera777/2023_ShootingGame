// プレイヤー
#pragma once

// プロトタイプ宣言
struct GameObject;
struct Enemy;
struct Shot;
struct Game;
struct Menu;

// 定数
// ステータス
#define PLAYER_SPEED				12		// プレイヤーのスピード.
#define PLAYER_LIFE					29		// プレイヤーのライフ.
#define PLAYER_BOOSTER_X_NUM		4		// プレイヤーのブースター画像の横の画像数
#define PLAYER_BOOSTER_Y_NUM		1		// プレイヤーのブースター画像の縦の画像数
#define	PLAYER_BOOSTER_TOTAL		PLAYER_BOOSTER_X_NUM * PLAYER_BOOSTER_Y_NUM // プレイヤーのブースター画像の総数
#define PLAYER_TRUNING_GRAPH_NUM	7		// プレイヤーの旋回用画像
#define PLAYER_TRUNING_X_NUM		7		// プレイヤーの旋回画像、横の分割数
#define	PLAYER_TRUNING_Y_NUM		1		// プレイヤーの旋回画像、縦の分割数
#define PLAYER_MOVING_RANGE_BUFF	50		// プレイヤーの移動範囲の制限のバフ値
#define PLAYER_DESTROY_GRAPH_X_NUM	14		// プレイヤーが撃破された際の画像横分割数
#define	PLAYER_DESTROY_GRAPH_Y_NUM	1		// プレイヤーが撃破された際の画像縦分割数
#define PLAYER_DESTROY_GRAPH_TOTAL	PLAYER_DESTROY_GRAPH_X_NUM * PLAYER_DESTROY_GRAPH_Y_NUM	// 総合撃破画像

// 当たり判定
#define PLAYER_WIDTH				20		// プレイヤーの幅当たり判定
#define PLAYER_HEIGHT				20		// プレイヤーの高さ当たり判定

// ショット
#define PLAYER_SHOT				60		// ショットの最大数.
#define PLAYER_SHOT_POWER		1		// ショットの威力.
#define PLAYER_SHOT_SPEED		20		// 通常ショットのスピード.
#define PLAYER_SHOT_INTERVAL	10		// 通常ショットの発射インターバル.
#define MISSILE_SHOT_AIM_FRAME	30		// ミサイルがホーミングする時間

// アイテム
#define PLAYER_NO_ITEM			50		// プレイヤーがアイテム効果を保持していない状態（５０個以上アイテムがある場合は変更する）
#define PLAYER_BOM_POWER		10		// プレイヤーボムのパワー
#define ITEM_LEAVE_INTERVAL		20		// アイテム出現の間隔


// 修正値
#define PLAYER_SHOT_X_BUF		50		// プレイヤーのショットの発射位置の修正値(75)

// プレイヤー.
struct Player
{
	// ステータス
	GameObject	obj;
	int		life = 0;						// プレイヤーのライフ
	bool	damageFlag	= false;			// プレイヤーがダメージを受けているかどうか
	int		damageCounter = 0;				// プレイヤーのダメージ受付時間	
	int		changeStateFlag = false;		// ステートが変更されたフラグ
	int		playerDamageCount = 0;			// プレイヤーの被弾時の時間
	bool	moveClearFlag = false;			// クリア時のプレイヤーの移動
	int		playerDeathFrameCount = 0;		// プレイヤーが死んでからの時間
	float	enemyEliminationRate;			// 敵の撃破率
	float	enemyEliminationCount = 1.0f;	// 敵の撃破カウント
	bool	moveEndFlag = false;			// プレイヤーが指定の位置まで移動したかどうかのフラグ

	// 描画関係
	int		boosterGraph[PLAYER_BOOSTER_TOTAL] = {};			// ブースター画像
	int		boosterCount = 0;									// ブースターを描画するカウント
	int		playerTruningGraph[PLAYER_TRUNING_GRAPH_NUM] = {};	// 旋回用画像
	int		truningGraphIndex = 0;								// 旋回画像の添え字
	int		truningTiemer = 0;									// 旋回画像の添え字をどのくらいの時間描画するかのタイマー
	int		lifeBarGraph;										// HP（ライフ）バーの画像
	int		DeathGraph[PLAYER_DESTROY_GRAPH_TOTAL];				// 撃破された時の画像
	int		shadowGraph = -1;									// 影

	// アイテム関係
	int		itemEliminationCount = 0;		// アイテムが出るまでの敵の撃破数
	int		itemStatus = 0;					// どのアイテムを取得しているか
	int		bomCount = 0;					// ボムを持っている

	// ショット関係
	Shot	shot[PLAYER_SHOT];				// プレイヤーのショット
	Shot	missile;						// ミサイル用
	bool	missileHitFlag = false;			// ミサイルがヒットしたか
	Shot	multiShotLeft[PLAYER_SHOT];		// ３WAYショット用　左
	Shot	multiShotRight[PLAYER_SHOT];	// ３WAYショット用　右
	Shot	bomShot;						// ボム用のショット
	int		timeToAimEnemyMissile = 0;		// ミサイルが敵を狙う時間
	int shotIntervalCount = 0;				// ショットのインターバルを設定するカウンター
};

// 初期化.
void InitPlayer(Player& player);

// アップデート.
void UpdatePlayer(Player& player, Enemy multiEnemy[], Enemy& enemy, int size, Game& game);

// アイテムの効果
void EffectItem(Game& game);


// メニュー時でのアップデート
void UpdateMenuPlayer(Game& game, Player& player, Menu& menu);

// 描画.
void DrawPlayer(Player& player);

// プレイヤーの移動
void MovePlayer(Player& player);

