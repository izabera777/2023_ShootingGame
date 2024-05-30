#pragma once

// 構造体プロトタイプ宣言
struct GameObject;
struct EenmyEntry;
struct Enemy;
struct Sound;
struct Game;

// 定数
#define MENU_STAGE_NUM      3   // メニューに表示するステージ数
#define MENU_FIGHTER_NUM    3   // メニューに表示する戦闘機の数
#define MENU_CLOUD_NUM      3   // メニューに表示する雲の数
#define MENU_GLASS_NUM      5   // ステージが割れていく画像の総数
#define MENU_LIFE           6   // ステージの体力
#define STAGE_NUM           3   // ステージの数

// 射撃キー
#define SHOT_KEY_X_POS      500 // 射撃キーの描画X位置
#define SHOT_KEY_Y_POS      650 // 射撃キーの描画Y位置

// 十字キー
#define CROSSKEY_X_POS      1100// 十字キーの描画X位置
#define CROSSKEY_Y_POS      650 // 十字キーの描画Y位置



// 構造体宣言

struct StageMnue
{
    int     life = MENU_LIFE;
};


// メニュー画面
struct Menu
{
    GameObject  obj;                //ゲームオブジェクト構造体
    
    // ステージ
    GameObject  objStageGraph[MENU_STAGE_NUM];          // ステージの画像

    // MENU上でのオブジェクト
    GameObject  objStageSelectBot;                      // ステージセレクト時に使う機体の情報
    GameObject  objCloudGraph[MENU_FIGHTER_NUM];        // メニュー上の演出で使用する雲画像
    int         titleGraph;         // タイトル画像

    // メニュー上の演出で使用する敵戦闘機画像
    GameObject  objFighterNormal;                       // メニュー上の演出で使用する敵戦闘機画像
    GameObject  objBossFighterGraph;                    // メニュー上の演出で使用するボス戦闘機画像
    GameObject  objBossShipGraph;                       // メニュー上の演出で使用するボスタンク画像
    GameObject  objFighterGraph[MENU_CLOUD_NUM];        // メニュー上の演出で使用する戦闘機画像


    // 矢印、ショット画像関係
    int         playerKeyInputIndex = 0;// メニュー上でなんのキーが押されたかを保存する 0:入力なし 1:上 2: 下 3:右 4:左　5:スペース
    int         crossKey;           // 十字キー
    int         rightKeyRedGraph;   // 赤→
    int         leftKeyRedGraph;    // 赤←
    int         upKeyRedGraph;      // 赤↑
    int         downKeyRedGraph;    // 赤↓
    int         spaceKeyGraph;      // スペース
    int         spaceKeyRedGraph;   // 赤スペース
    int         frameGraph;         // フレーム
    int         moveStringGraph;    // 「移動キー」
    int         shotStringGraph;    // 「射撃キー」
    int         glassCrackingGraph[MENU_GLASS_NUM];  // ガラスが割れる

    // ライフ
    StageMnue   stageMenu[STAGE_NUM];   // ステージのライ

    // オペレーター
    GameObject	menuTalkGraph;			// メニューでのオペレーターの会話

};

// ゲームカウント
struct FrameCount
{
    int gameFrameCount;
};



//関数プロトタイプ宣言
//void TestDrawMultiEnemy(Enemy& enemy, EnemyEntry& enemyEntry);
void InitMenu(Menu& menu, int graph);
void DrawMenu(Menu& menu);
void UpdateMenu(Menu& menu, Sound& sound);

void DrawGlassCracking(Menu& menu);






