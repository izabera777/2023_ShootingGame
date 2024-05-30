#pragma once

// プロトタイプ宣言
struct GameObject;

#define BG_SCROLL_SPEED		4		// 背景の縦スクロールスピード.
#define BG_SCROLL_SPEED_H	8		// 背景の横スクロールスピード
#define BG_SCROLL_SPEED_CLEAR	3	// クリア時の町スクロールスピード

// 背景.
struct BG
{
	GameObject	obj;
	GameObject	objNext;
	GameObject	objNext2;

	GameObject city;
};


// 初期化.
void InitBG(BG& bg, int graph, int index);
void InitBGHorizon(BG& bg, int garph, int index);
void InitCtiyBG(BG& bg, int graph, int index);



// アップデート.
void UpdateBG(BG& bg);
void UpdateCityBG(BG& bg, int speed);


// 平行移動 
void UpdateBGHorizon(BG& bg);



// 描画.
void DrawBG(BG& bg);
void DrawBGH(BG& bgNext);


