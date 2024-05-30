#include "GameObject.h"
#include "BG.h"
#include "DxLib.h"
#include "UI.h"

// 初期化.
void InitBG(BG& bg, int graph, int index)
{
	bg.obj.graph = graph;
	GetGraphSize(bg.obj.graph, &bg.obj.w, &bg.obj.h);	//グラフィックのサイズを得る
	bg.obj.pos.x = bg.obj.w * 0.5f;						//
	bg.obj.pos.y = (float)(index * bg.obj.h);
}

// ワーニング用画像初期化
void InitBGHorizon(BG& bg, int graph, int index)
{
	bg.objNext.graph = graph;
	GetGraphSize(bg.objNext.graph, &bg.objNext.w, &bg.objNext.h);
	//bg.objNext.pos.x = bg.objNext.w * 0.5f;					// 画像の中心
	bg.objNext.pos.x = 0;
	//bg.objNext.pos.y = (float)(index * bg.objNext.h * 0.5f);	// 画像のトップ
	bg.objNext.pos.y = 100;

	// 下描画用
	bg.objNext2.graph = graph;
	GetGraphSize(bg.objNext2.graph, &bg.objNext2.w, &bg.objNext2.h);
	bg.objNext2.pos.x = 0;
	bg.objNext2.pos.y = 880;	// 初期770
	
}

// 背景の町画像初期化
void InitCtiyBG(BG& bg, int graph, int index)
{
	// クリア時の町画像
	bg.obj.graph = graph;
	GetGraphSize(bg.obj.graph, &bg.obj.w, &bg.obj.h);
	bg.obj.pos.x = (float)(index * bg.obj.w);
	bg.obj.pos.y = bg.obj.h * 0.5f;


}


// アップデート.
void UpdateBG(BG& bg)
{
	// 背景縦スクロール.
	bg.obj.pos.y += BG_SCROLL_SPEED;

	// 背景のy座標が背景一つ分余計に下になったら上に移動.
	if (bg.obj.pos.y > bg.obj.h + bg.obj.h * 0.5f)
	{
		bg.obj.pos.y -= bg.obj.h * 2;
	}
}

// 横移動アップデート
void UpdateCityBG(BG& bg,int speed)
{
	// 背景横スクロール
	bg.obj.pos.x += speed;
	// 背景のｘ座標が背景一つ分余計になったら横に移動
	if (bg.obj.pos.x > bg.obj.w + bg.obj.w * 0.5f)
	{
		bg.obj.pos.x -= bg.obj.w * 2;
	}
}


// 横移動 ver.
void UpdateBGHorizon(BG& bg)
{
	// 背景縦スクロール.
	bg.objNext.pos.x += BG_SCROLL_SPEED_H;
	// 背景のy座標が背景一つ分余計に下になったら上に移動.
	if (bg.objNext.pos.x > bg.objNext.w + bg.objNext.w * 0.5f)
	{
		bg.objNext.pos.x -= bg.objNext.w * 2;
	}

	bg.objNext2.pos.x += BG_SCROLL_SPEED_H;
	if (bg.objNext2.pos.x > bg.objNext2.w + bg.objNext2.w * 0.5f)
	{
		bg.objNext2.pos.x -= bg.objNext2.w * 2;
	}
}


// 描画.
void DrawBG(BG& bg)
{
	DrawGameObject(bg.obj, bg.obj.graph);
}

// 横スクロール描画
void DrawBGH(BG& bg)
{
	DrawGameObject(bg.objNext, bg.objNext.graph);
	DrawGameObject(bg.objNext2, bg.objNext2.graph);
}