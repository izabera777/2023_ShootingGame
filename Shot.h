#pragma once

// 定数宣言
#define OBJECT_HIT_BUF	1.0f		// 当たり判定オブジェクトの当たり判定矩形のバフ値


// プロトタイプ宣言
struct GameObject;

// MEMO:ショット自体にGameObject targetを作って一定時間追いかけさせたりとか
struct Shot
{
	GameObject	obj;
	int		power = 0;					// ダメージ
	bool	visibleFlag = false;		// ショットが画面上に存在しているか
	int		canTrunFrameTime = 0;		// 自機をホーミングできるフレーム数
};

// 初期化.
void InitShot(Shot& shot, int shotGraph, int shotW, int shotH, float angle, float speed, int power);

// ショットの移動.
void MoveShot(Shot& shot);

// ショットの当たり判定チェック
bool IsHitShot(Shot& shot, GameObject& target);

// 描画.
void DrawShot(Shot& shot);