//----------------------------//
// ユーティリティ（便利）関数群
//----------------------------//

#pragma once

// π
#define PI    3.1415926535897932384626433832795f

// スクリーンサイズ.
#define SCREEN_W 1600				// 50 * 32
#define SCREEN_H 960				// 28.125 * 32

#define LIMIT_TIME_COUNT	30		// ゲームの制限時間.
#define STATE_CHANGE_WAIT	500		// ステート切り替えウェイト(ミリ秒).

// 状態.
enum STATE
{
	STATE_MENU,		// メニュー
	STATE_STAGE1,	// ステージ１
	STATE_STAGE2,	// ステージ２
	STATE_STAGE3,	// ステージ３
	STATE_CLEAR,	// クリア.
	STATE_GAMEOVER,	// ゲームオーバー.
	STATE_NUM		// 番兵.
};

// 指定された全文字列の幅を取得.
int GetDrawStringWidthFull(char* str);

// ディグリーをラジアンに変換
float GetRadian(float degree);


void FpsControll_Initialize();
bool FpsControll_Update();
void FpsControll_Draw();
void FpsControll_Wait();



//// 向ける方向の計算
//float plyaerEnemyVDot;	// playerとenemyの内積
//float playerAbsX;		// プレイヤーの絶対値X
//float playerAbsY;		// プレイヤーの絶対値Y
//float playerAbsSum;		// プレイヤーの絶対値
//float enemyAbsX;		// エネミーの絶対値X
//float enemyAbsY;		// エネミーの絶対値Y
//float enemyAbsSum;		// エネミーの絶対値
//float cosAngle;			// コサインΘ
//float sinAngle;			// サインΘ
//// 内積の計算
//plyaerEnemyVDot = VDot(player.shot[i].obj.pos, multiEnemy[i].obj.pos);
//// プレイヤー絶対値計算
//playerAbsX = sqrtf(player.shot[i].obj.pos.x * player.obj.pos.x);
//playerAbsY = sqrtf(player.shot[i].obj.pos.y * player.obj.pos.y);
//playerAbsSum = playerAbsX + playerAbsY;
//// エネミー絶対値計算
//enemyAbsX = sqrtf(multiEnemy[i].obj.pos.x * multiEnemy[i].obj.pos.x);
//enemyAbsY = sqrtf(multiEnemy[i].obj.pos.y * multiEnemy[i].obj.pos.y);
//enemyAbsSum = enemyAbsX + enemyAbsY;
//// cosΘ計算
//cosAngle = plyaerEnemyVDot / (playerAbsSum * enemyAbsSum);
//// sinΘ計算
//sinAngle = sqrtf(1 - cosAngle);
//
//// ポジションへ代入
//float xCos = player.shot[i].obj.pos.x * cosAngle;
//float yCos = player.shot[i].obj.pos.y * cosAngle;
//float xSin = player.shot[i].obj.pos.x * sinAngle;
//float ySin = player.shot[i].obj.pos.y * sinAngle;
//player.shot[i].obj.pos.x = xCos - ySin;
//player.shot[i].obj.pos.y = xSin + yCos;

