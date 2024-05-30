//-----------------------------------------------------------------------------
// @brief  メイン処理.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include <string>

// main以外は、すべてヘッダでプロトタイプ宣言を行っている
// mainのみ全てのヘッダをインクルードする。順番に注意！
#include "DxLib.h"
#include "Utility.h"
#include "GameObject.h"
#include "Shot.h"
#include "Player.h"
#include "Enemy.h"
#include "BG.h"
#include "UI.h"
#include "Menu.h"
#include "Sound.h"
#include "Item.h"
#include "Game.h"

//----------------------------//
// WinMain関数.
//----------------------------//
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// 画面モードの設定
	SetGraphMode(SCREEN_W, SCREEN_H, 16);		// 解像度をSCREEN_W*SCREEN_H、colorを16bitに設定.

	/////////////////////////////////
	// ウインドウモードに(コメントアウトしたらフルスクリーン).
	//ChangeWindowMode(TRUE);
	/////////////////////////////////

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	// 背景のスクロールをするためにテクスチャモードをラッピングに修正.
	SetTextureAddressMode(DX_TEXADDRESS_WRAP);

	// グラフィックの描画先を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);

	// ゲーム構造体
	Game game;
	FrameCount framecount;

	// ゲーム初期化
	InitGame(game);
	InitMenuBGM(game.sound);

	// ゲームループ.
	while (1)
	{
		// FPS処理
		auto prevTime = GetNowHiPerformanceCount();	// 処理が始まる前の時間

		// 画面を初期化(真っ黒にする)
		ClearDrawScreen();


		// ゲームの更新
		UpdateGame(game);
		DrawGame(game);

		// 裏画面の内容を表画面にコピーする（描画の確定）.
		ScreenFlip();

		// FPS処理
		auto afterTime = GetNowHiPerformanceCount();
		while (afterTime - prevTime < 16667)
		{
			afterTime = GetNowHiPerformanceCount();
		}

		// Windows 特有の面倒な処理をＤＸライブラリにやらせる
		// マイナスの値（エラー値）が返ってきたらループを抜ける
		if (ProcessMessage() < 0)
		{
			break;
		}
		// もしＥＳＣキーが押されていたらループから抜ける
		else if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// ゲームのパッド情報を取得
		//game.keyPad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;					// ソフトの終了
}