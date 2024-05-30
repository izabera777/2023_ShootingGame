// マルチエネミー
#pragma once

// プロトタイプ宣言		//この構造体を使用しますよ
struct GameObject;
struct Player;
struct Shot;
struct Enemy;
struct Shot;

// ゲーム上での複数の敵
Enemy multiEnemy[ENEMY_OF_NUMBER];

// プロトタイプ宣言

// 初期化.
void InitMultiEnemy(Enemy& enemy, Enemy multiEnemy[], int size, Game& game);

// アップデート.
void UpdateMultiEnemy(Enemy& enemy, Enemy multiEnemy[], Player& player, int size, Game& game);

// 描画.
void DrawMultiEnemy(Game& game, Enemy multiEnemy[], int size);

// マルチエネミーの移動ルーチンに沿ったベクトルの調節.
void MoveRoutinesMultiEnemy(Enemy multiEnemy[], int size);

void InitMultiEnemySTAGE1(Enemy& enemy, Enemy multiEnemy[], int size, Game& game);


void InitMultiEnemySTAGE2(Enemy& enemy, Enemy multiEnemy[], int size, Game& game);




