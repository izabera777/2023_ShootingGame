// エネミー
#pragma once

// プロトタイプ宣言		//この構造体を使用しますよ
struct GameObject;
struct Player;
struct Shot;
struct Game;


// 定数

// ステータス
#define ENEMY_OF_NUMBER		100		// 敵の数
#define ENEMY_SPEED			6		// 敵のスピード.
#define ENEMY_LIFE			1		// 敵のライフ.
#define ENEMY_MOVE_MARGIN	5		// 敵の座標をずらす

// エネミーの数
#define ENEMY_NUM_STAGE1	100		// STAGE１の敵の総数
#define ENEMY_NUM_STAGE2	100		// STAGE２の敵の総数
#define ENEMY_NUM_STAGE3	100		// STAGE３の敵の総数

// ショット
#define ENEMY_SHOT			100		// 敵ショットの最大数.
#define ENEMY_SHOT_POWER	1		// 敵ショットの威力.
#define ENEMY_SHOT_SPEED	8		// 敵ショットのスピード.
#define ENEMY_SHOT_INTERVAL	50		// 敵Sショットの発射インターバル.

// エクストラショット
#define ENEMY_EXTRA_SHOT			20	// 敵のエクストラショット
#define	ENEMY_SHOT_EXTRA_POWER		3	// 敵のエクストラショットの威力
#define	ENEMY_SHOT_EXTRA_SPEED		6	// 敵のエクストラショットのスピード
#define	ENEMY_SHOT_EXTRA_INTERVAL	40	// 敵の発射インターバル

// ボスミサイル
#define ENEMY_MISSILE_POWER			10	// ボスミサイルの威力
#define ENEMY_MISSILE_SPEED			4	// ボスミサイルのスピード
#define ENEMY_MISSILE_INTERVAL		100	// ボスミサイルのインターバル

// スピード
#define ENEMY_FAST_SPEED	20		// 敵のスピード（早い）
#define ENEMY_NORMAL_SPEED	10		// 敵のスピード（普通）
#define ENEMY_SLOW_SPEED	5		// 敵のスピード（遅い）		// 地上兵器用

// 画像
#define ENEMY_BLAST_GRAPH_XNUM	5		// 敵撃破時画像の横の分割数（SFの爆発）
#define ENEMY_BLAST_GRAPH_YNUM	2		// 敵撃破時画像の縦の分割数（SFの爆発）
#define ENEMY_BLAST_GRAPH_DRAW_COUNT 5	// 撃破時画像を描画する時間

// 撃破画像
#define	ENEMY_DESTROY_GRAPH_X_NUM	14	// 敵の撃破時画像の横分割数（現実の爆発）
#define	ENEMY_DESTROY_GRAPH_Y_NUM	1	// 敵の撃破時の画像の縦分割数（現実の爆発）
#define	ENEMY_DESTROY_GRAPH_TOTAL	ENEMY_DESTROY_GRAPH_X_NUM * ENEMY_DESTROY_GRAPH_Y_NUM	// 敵の撃破時画像の総枚数（現実の爆発）

// BOSS
#define BOSS_LIFE					100			// ボスのライフ
#define BOSS_FIRST_FRAME			400			// ボスの最初登場フレーム初期化値
#define BOSS_ENTRY_FRAME			400		// ボスの登場フレーム数	(設定4000)
#define BOSS_ENTRY_DIRECTING_TIME	650			// ボスの登場演出を行う時間
#define BOSS_HBG_TIME				1300		// ボス登場演出用の横スクロール画像を流すフレーム数
#define	BOSS_DESTROY_TIME			300			// ボス撃破後の待機時間

// 中BOSS
#define	SUB_BOSS_LIFE			10	// 中ボスのライフ
#define SUB_BOSS_CRUISERS_LIFE	15	// 巡洋艦のライフ
#define SUB_BOSS_SHOT_INTERVAL	10	// 中ボスのショット発射インターバル

// BOSS　ショット
#define BOSS_SHOT_INTERVAL	5		// ボスのショットの発射インターバル

// SCORE
#define SCORE_IMAGES_X_NUM	5		// スコアの獲得画像の横分割数
#define SCORE_IMAGES_Y_NUM	1		// スコアの獲得画像の縦分割数
#define SCORE_IMAGES_TOTAL	SCORE_IMAGES_X_NUM * SCORE_IMAGES_Y_NUM	// スコアの獲得画像の総数
#define SCORE_IMAGES_SIZE_X	64		// スコアの獲得画像の横サイズ
#define SCORE_IMAGES_SIZE_Y	32		// スコアの獲得画像の縦サイズ
#define SCORE_IMAGES_DRAW_COUNT	10	// スコアの獲得画像を描画する時間
#define SCORE_IMAGES_SHIFT_BUF	50	// スコアの獲得画像のずらし量

// 構造体

// エネミー出現時の情報
struct EnemyEntry
{
	int		frame;		// 出現するフレーム数
	int		x;			// 出現する時点でのX座標
	int		y;			// 出現する時点でのY座標
	int		speed;		// 敵のスピード
	int		routine;	// 行動ルーチン
};

// エネミー.
struct Enemy
{
	// 基本情報
	GameObject	obj;					// エネミーのゲームオブジェクト構造体
	int			life = 0;				// エネミーのHP
	bool		rightMove = true;		// 右移動しているかどうかのフラグをリセット
	int			moveCount = 0;			// エネミーが移動できる時間
	int			lifeBarGraph = -1;		// HP（ライフ）バーの画像

	// エントリー関係
	EnemyEntry	enemyEntry;										// エネミー登場テーブル
	int			bossEntryFrameCount = BOSS_FIRST_FRAME;			// BOSSが登場する時間

	// ダメージ、撃破関係
	int			BlastGraph[ENEMY_BLAST_GRAPH_XNUM * ENEMY_BLAST_GRAPH_YNUM];// エネミー撃破時の画像
	int			destroyGraph[ENEMY_DESTROY_GRAPH_TOTAL];		// エネミーのダメージ演出
	bool		killFlag = false;								// 撃破された
	int			destroyFlameCount	= 0;						// エネミーの撃破時の画像の描画待機フレーム数
	int			bossDestroyTime		= 0;						// BOSSが死んでからの時間
	int			bossDestroyGraph[ENEMY_DESTROY_GRAPH_TOTAL];	// BOSS撃破時の演出
	int			damageGraph = -1;		// エネミーの被弾の画像
	bool		damageFlag = false;		// エネミーがダメージを受けているか
	int			damageCounter = 0;		// エネミーのダメージ受付時間
	bool		alive;					// 生きているかどうかのフラグ
	int			destroyCount = 0;		// エネミーが撃破されてからのカウント

	// スコア
	int			scoreDestroyGraph[SCORE_IMAGES_X_NUM];	// 撃破時に描画するスコアの画像
	GameObject	scoreObj;								// 撃破した機体の上に描画したいのでその位置調整用

	// ノーマルショット
	Shot		shot[ENEMY_SHOT];		// ノーマルショット
	int			shotIntervalCount = 0;	// エネミーショットのインターバルを設定するカウンター

	// ミサイル
	Shot		missile;					// ミサイル
	int			missleIntervalCount = 0;	// ミサイルのインターバルカウント
	int			missileTracingTime = 0;		// ミサイルの追尾時間
	int			missileHitCounter = 0;		// ミサイルが当たってからのカウント
	bool		missileHitFlag = false;		// ミサイルが当たったかのフラグ

	// エクストラショット
	Shot		extraShot[ENEMY_EXTRA_SHOT];	// エクストラショット
	int			extrashotIntervalCount = 0;		// エクストラショットのインタヴァル
};

// マルチエネミーの移動ローテーション
enum MultiEnemyRoutines
{
	// 戦闘機
	VERTICAL_FIGHTER,				// 垂直動作（空）
	HORIZON_FIGHTER,				// 平行動作（空）
	HORIZON_REVERSE_FIGHTER,		// 平行移動（逆）（空）
	RIGHT_ANGLE_FIGHTER,			// 直下移動（空）
	ROTATION_FIGHTER,				// 回転動作（空）

	// 地上兵器
	VERTICAL_GROUND_WEAPON,			// 垂直移動（地上）
	HORIZON_GROUND_WEAPON,			// 平行移動（地上）
	RIGHT_DIAGONAL_GRAOUND_WEAPON,	// 右上から左下への移動（地上）
	ZIGZAG_GROUND_WEAPON,			// ジグザク移動（地上）
	EDGE_MOVE_GROUND_WEAPON,		// Uの時に移動（地上）
	
	// 中ボス
	SUB_BOSS_DUAL_USE,				// 水陸両用戦闘機

	// 海上
	SUB_BOSS_CRUISERS,				// 巡洋艦
	BATTLE_SHIPS,					// 戦艦
	AIRCRAFT_CARRIERS				// 空母
};



// プロトタイプ宣言

// 初期化.
void InitEnemy(Enemy& enemy);

// アップデート.
void UpdateEnemy(Enemy& enemy, Player& player, Game& game);

// 描画.
void DrawEnemy(Enemy& enemy, Game& game);

// スコア描画位置を調整するため、scoreObjに実際の情報をコピー
void CopySocreObject(Enemy& enemy, Enemy multiEnemy[], int arrayNum);

// STAGE１用

void InitEnemySTAGE1(Enemy& enemy);


// STAGE2用
void InitEnemySTAGE2(Enemy& enemy);

