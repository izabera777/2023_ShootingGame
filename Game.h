#pragma once


//#include"Menu.h"	//注意！！　本当はやらないほうがよい(エラーC2079)

#define	BG_NUM					3		// 背景の個数.
#define GAME_START_FRAME_COUNT	500		// ゲーム開始前の演出をする時間
#define GAME_START_POSION_Y		500		// ゲーム開始時にプレイヤーが自動的に移動する座標

// プロトタイプ宣言
enum   STATE;
struct GameObject;
struct Player;
struct Enemy;
struct BG;
struct UI;
struct Menu;
struct Sound;
struct Item;


// ゲーム構造体
struct Game
{
	//構造体プロトタイプ宣言
	Player	player;
	Enemy	enemy;
	BG		bg[BG_NUM];
	BG		bgNext[BG_NUM];
	BG		bgNext2[BG_NUM];
	BG		city[BG_NUM];
	BG		city2[BG_NUM];
	BG		montain[BG_NUM];
	UI		ui;
	Menu	menu;
	Sound	sound;
	Item	item;

	//変数宣言

	// 基本情報
	STATE	state;	
	int		gameStartTime	= 0;
	int		prevKeyInput	= 0;
	bool	keyOn			= false;
	bool	prevKeyOn		= false;
	bool	keyRelease		= false;
	int		gameFrameCount	= 0;
	bool	playerMoveEndFlag = false;	// プレイヤーが指定の位置まで移動したかどうかのフラグ

	// 画面明るさ
	int		screenBlendNum = 255;		// 画面の明るさを調整する値
	int		blendNumFrameCount = 255;	// 画面の明るさを設定するために保存するカウント
	
	// ステート
	bool	menuFromGameFlag = false;
	bool	GameFromClearFlag = false;
	bool	GameFromOverFlag = false;
	bool	stateInitFlag = false;		// タイトルでイニシャライズを一度だけ呼ぶためのフラグ

	// スコア
	int		subBossIndex = 0;		// サブボスのインデックス
	int		score = 0;				// スコア
	int		scoreUpFlag = false;	// スコアを一度だけ変更する

	// 撃破時
	int		enemyKillNum = 0;	// 撃破した敵の添え字
	int		enemyKillFlag = 0;	// 敵を撃破した
	
	// エントリー
	int		bossEntryFlag = false;

	// コントローラー（パッド）
	int		keyPad;

	// テスト
	VECTOR testPos = VGet(0, 0, 0);

};

//----------------------------//
// ゲームそのものの関数群.
//----------------------------//

// ゲームフレームカウントの更新
void GetFrameCount(Game& game);

// 初期化.
void InitGame(Game& game);

// ゲームスタート時の初期化
void InitGameStart(Game& game);

// ステート切り替え.
void ChangeGameState(STATE state, Game& game);

// アップデート.
void UpdateGame(Game& game);

// ゲーム描画
void DrawGame(Game& game);

// クリア時にプレイヤーを自動的に移動
void AutoMoveClearPlayer(Game& game);

// 画面をだんだん暗くする
void BlackOutScreen(Game& game);

// 画面をだんだん明るくする
void ChangeBrightness(Game& game);

// ベクトルの長さを求める
double GetVectorLength(VECTOR& vector);

// ベクトルの内積を求める
double GetDotProduct(VECTOR& vector1, VECTOR& vector2);

// ベクトルのなす角を求める
double GetAngleOf2Vector(VECTOR& vector1, VECTOR& vector2);


/////////////////
// STAGE1
////////////////
// STAGE1全体の初期化処理
void InitGameStartSTAGE1(Game& game);


/////////////////
// STAGE2
////////////////
// STAGE2全体の初期化処理
void InitGameStartSTAGE2(Game& game);


