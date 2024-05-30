#include "Utility.h"
#include "DxLib.h"
#include "GameObject.h"
#include "UI.h"
#include "Shot.h"
#include "Player.h"
#include "Enemy.h"
#include "BG.h"
#include "Menu.h"
#include "Sound.h"
#include "Item.h"
#include "Game.h"


// UI初期化.
void InitUI(UI& ui)
{
	// プレイヤー //

	// HP画像のロード
	if (ui.hpGraph < 0)
	{
		ui.hpGraph = LoadGraph("data/texture/hp.png");
	}
	// プレイヤーHPバー画像のロード
	if (ui.playerHpBarGraph < 0)
	{
		ui.playerHpBarGraph = LoadGraph("data/texture/PlaeyrHPUIGraph400New.png");
	}
	// プレイヤー影
	if (ui.playerShadowGraph < 0)
	{
		ui.playerShadowGraph = LoadGraph("data/texture/myShadowThin.png");
	}
	// プレイヤー状態画像
	// 赤
	if (ui.playerStatusRedGraph < 0)
	{
		ui.playerStatusRedGraph = LoadGraph("data/texture/myRed.png");
	}
	// 黄
	if (ui.playerStatusYellowGraph < 0)
	{
		ui.playerStatusYellowGraph = LoadGraph("data/texture/myYellow.png");
	}
	// 緑
	if (ui.playerStatusGreenGraph < 0)
	{
		ui.playerStatusGreenGraph = LoadGraph("data/texture/myGreen.png");
	}
	// 機体情報
	if (ui.playerInfoNameGraph < 0)
	{
		ui.playerInfoNameGraph = LoadGraph("data/texture/DELTA1.png");
	}
	// 機体ダメージ情報
	if (ui.playerInfoDmgGraph < 0)
	{
		ui.playerInfoDmgGraph = LoadGraph("data/texture/DMG.png");
	}
	// 装備情報
	if (ui.playerInfoWeaponGraph < 0)
	{
		ui.playerInfoWeaponGraph = LoadGraph("data/texture/Weapon.png");
	}
	// 装備武装アイコンフレーム
	if (ui.weaponFrameGraph < 0)
	{
		ui.weaponFrameGraph = LoadGraph("data/texture/weaponFrame.png");
	}

	// 文字画像
	if (ui.multiTextGraph < 0)
	{
		ui.multiTextGraph = LoadGraph("data/texture/multi.png");
	}
	if (ui.normalTextGraph < 0)
	{
		ui.normalTextGraph = LoadGraph("data/texture/normal.png");
	}

	// BOSS //
	// BOSS登場時の横スクロール画像のロード
	if (ui.warningGraph < 0)
	{
		ui.warningGraph = LoadGraph("data/texture/warningGraph.jpg");
	}
	// BOSS HPバー画像のロード
	if (ui.bossHpBarGraph < 0)
	{
		ui.bossHpBarGraph  = LoadGraph("data/texture/BossHPUIGraph.png");
	}

	// HP画像のロード
	if (ui.hpBackGraph < 0)
	{
		ui.hpBackGraph = LoadGraph("data/texture/hpBack.png");
	}

	// ボスHPNewバーの画像,サイズの取得

	ui.bossHpBarNewGraphObj.graph = LoadGraph("data/texture/BOSSHPBar.png");
	GetGraphSize(ui.bossHpBarNewGraphObj.graph, &ui.bossHpBarNewGraphObj.w, &ui.bossHpBarNewGraphObj.h);

	// プレイヤーHPバーNew画像
	ui.playerHpBarNewGraph = LoadGraph("data/texture/HPBarNew.png");

	// ステージ１開始時に表示する文字画像
	ui.stage1StringGraph = LoadGraph("data/texture/stage1.png");
	// ステージ２開始時に表示する文字画像
	ui.stage2StringGraph = LoadGraph("data/texture/stage2.png");
	// ステージ３開始時に表示する文字画像
	ui.stage3StringGraph = LoadGraph("data/texture/stage3.png");

	// ゲームクリア時
	ui.gameClearGraph = LoadGraph("data/texture/クリア.png");
	ui.gameClearStringGraph = LoadGraph("data/texture/GameClear.png");

	// ゲームオーバー時
	ui.gameOverGraph = LoadGraph("data/texture/ゲームオーバー.png");
	ui.gameOverStringGraph = LoadGraph("data/texture/GameOver.png");

	// ランク表示用
	if (ui.rankBaseGraph < 0)
	{
		ui.rankBaseGraph		= LoadGraph("data/texture/RANKBase600.png");
	}
	if (ui.rankStringGraph < 0)
	{
		ui.rankStringGraph		= LoadGraph("data/texture/RANK.png");
	}
	if (ui.rankGraphSSS < 0)
	{
		ui.rankGraphSSS			= LoadGraph("data/texture/SSS.png");
	}
	if (ui.rankGraphS < 0)
	{
		ui.rankGraphS			= LoadGraph("data/texture/S.png");
	}
	if (ui.rankGraphA < 0)
	{
		ui.rankGraphA			= LoadGraph("data/texture/A.png");
	}
	if (ui.rankGraphB < 0)
	{
		ui.rankGraphB			= LoadGraph("data/texture/B.png");
	}
	if (ui.rankGraphC < 0)
	{
		ui.rankGraphC			= LoadGraph("data/texture/C.png");
	}
	if(ui.rankDescriptionGraph < 0)
	{
		ui.rankDescriptionGraph = LoadGraph("data/texture/XでMENUへ移動.png");
	}

	// ダメージ
	ui.damageScreenGraph = LoadGraph("data/texture/Damage.png");

	if (ui.bloodScreenGraphNext[0] < 0)
	{
		ui.bloodScreenGraphNext[0] = LoadGraph("data/texture/SPACEでMENUに移動.png");
	}
	if (ui.bloodScreenGraphNext[1] < 0)
	{
		ui.bloodScreenGraphNext[1] = LoadGraph("data/texture/SPACEでMENUに移動.png");
	}
	if (ui.bloodScreenGraphNext[2] < 0)
	{
		ui.bloodScreenGraphNext[2] = LoadGraph("data/texture/SPACEでMENUに移動.png");
	}

	// クリア
	LoadDivGraph("data/texture/花火21.png", 21, 8, 3, 64, 64, ui.fireWorksGraph);
	ui.clound.graph = LoadGraph("data/texture/雲.png");
	ui.fighter.graph = LoadGraph("data/texture/戦闘機.png");
	ui.mountain.graph = LoadGraph("data/texture/山.png");
	ui.clound.pos.x = 100;
	ui.clound.pos.y = 700;
	ui.fighter.pos.x = 400;
	ui.fighter.pos.y = 200;
	ui.mountain.pos.x = 300;
	ui.mountain.pos.y = 700;

}

// UI描画.
// ※難しければUI自体を非表示にして自分で考えること！.
void DrawUI(UI& ui, Game& game)
{
	// 時間を入れる文字列.
	char timeNumStr[256];
	char playerW[256];
	char playerH[256];

	// 残りライフを入れる文字列.
	char lifeStr[256];
	char bossLifeStr[256];
	
	// 敵の撃破率を入れる文字列
	char eliminationRateStr[256];

	// HP表示を始めるX座標.
	int hpGraphStartX;

	// ルールごとに表示物を変える.
	switch (game.state)
	{
		// タイトル.
	case STATE_MENU:
		
		// UI無し

		break;
		// ゲーム中.
	case STATE_STAGE1:

		// フォントサイズ設定
		SetFontSize(TIME_NUM_STR_FONT_SIZE);

		// ステージ番号の表示（ステージ最初に表示）
		if (game.gameFrameCount >= 0 && game.gameFrameCount <= STAGE_NUMBER_DRAW_TIME)
		{
			DrawGraph(STAGE_NUMBER_X, STAGE_NUMBER_Y, ui.stage1StringGraph, true);
		}

		// プレイヤーHP枠の描画
		DrawGraph(0, 0, ui.playerHpBarGraph, true);
		// プレイヤーHP画像の描画
		DrawPlayerInfo(game);

		// プレイヤーダメージ時
		DrawDamageScreen(game);

		// フレームカウント（テスト確認用）
		//DrawFormatString(0, 300, GetColor(255, 255, 0), "フレームカウント: %d", game.gameFrameCount);

		// スコアの表示
		SetFontSize(50);
		game.score = game.player.enemyEliminationCount * 100;
		sprintf_s(eliminationRateStr, "SCORE:%d", game.score);
		DrawString(0, 100, eliminationRateStr, GetColor(50, 50, 50), true);

		// 敵体力(ボス用)
		if (game.gameFrameCount >= BOSS_ENTRY_FRAME && game.enemy.life > 0)
		{
			// ボスのHPバーの描画
			DrawBossHPBar(game);
		}

		break;

		// STAGE1
	case STATE_STAGE2:

		// 制限時間（テスト用）
		//SetFontSize(TIME_STR_FONT_SIZE);
		//DrawString(SCREEN_W / 2 + TIME_STR_OFFSET_X, TIME_STR_POS_Y, TIME_STR, GetColor(255, 0, 0));
		// GetNowCountは1000分の１秒なのでそこから計算する.
		//sprintf_s(timeNumStr, "%d", LIMIT_TIME_COUNT + ((game.gameStartTime - GetNowCount()) / 1000));
		// フレームカウント
		//DrawFormatString(0, 300, GetColor(255, 255, 0), "フレームカウント: %d", game.gameFrameCount);
		
		// フォントサイズ変更
		SetFontSize(TIME_NUM_STR_FONT_SIZE);

		// ステージ番号の表示（ステージ最初に表示）
		if (game.gameFrameCount >= 0 && game.gameFrameCount <= STAGE_NUMBER_DRAW_TIME)
		{
			DrawGraph(STAGE_NUMBER_X, STAGE_NUMBER_Y, ui.stage2StringGraph, true);
		}

		// プレイヤーHP枠の描画
		DrawPlayerInfo(game);
		
		// プレイヤーダメージ時
		DrawDamageScreen(game);


		// スコアの表示
		game.score = game.player.enemyEliminationCount * 100;
		sprintf_s(eliminationRateStr, "SCORE:%d", game.score);
		DrawString(0, 100, eliminationRateStr, GetColor(50, 50, 50), true);

		// 敵体力(ボス用)
		if (game.gameFrameCount >= BOSS_ENTRY_FRAME && game.enemy.life > 0)
		{
			// ボスのHPバーの描画
			DrawBossHPBar(game);
		}

		break;

		// STAGE2
	case STATE_STAGE3:
		
		// フォントサイズ設定
		SetFontSize(TIME_STR_FONT_SIZE);

		// ステージ番号の表示（ステージ最初に表示）
		if (game.gameFrameCount >= 0 && game.gameFrameCount <= STAGE_NUMBER_DRAW_TIME)
		{
			DrawGraph(STAGE_NUMBER_X, STAGE_NUMBER_Y, ui.stage3StringGraph, true);
		}

		// プレイヤーHP枠の描画
		DrawPlayerInfo(game);
		// プレイヤーダメージ時
		DrawDamageScreen(game);

		// フレームカウント
		//DrawFormatString(0, 300, GetColor(255, 255, 0), "フレームカウント: %d", game.gameFrameCount);
		SetFontSize(TIME_NUM_STR_FONT_SIZE);

		// スコアの表示
		SetFontSize(50);
		game.score = game.player.enemyEliminationCount * 100;
		sprintf_s(eliminationRateStr, "SCORE:%d", game.score);
		DrawString(0, 100, eliminationRateStr, GetColor(50, 50, 50), true);

		// 敵体力(ボス用)
		if (game.gameFrameCount >= BOSS_ENTRY_FRAME && game.enemy.life >0)
		{
			// ボスのHPバーの描画
			DrawBossHPBar(game);
		}

		break;

		// クリア画面.
	case STATE_CLEAR:

		// スコアの加算
		if (game.scoreUpFlag == false)
		{
			game.score += 5000;
			game.scoreUpFlag = true;
		}

		// 雲、山、戦闘機描画
		DrawUpdateCleaer(game);
		// クリア文字画像
		DrawGraph(425, 100, ui.gameClearStringGraph, true);
		// リザルトランク表示ベース描画
		DrawGraph(500, 300, ui.rankBaseGraph, true);
		// ランク文字描画
		DrawGraph(615, 350, ui.rankStringGraph, true);
		// クリアランク描画
		DrawFinalRank(ui, game);


		// 花火
		if (ui.fireWorkusCount <= 20)
		{
			DrawGraph(250, 400, ui.fireWorksGraph[ui.fireWorkusCount], true);
			DrawGraph(300, 200, ui.fireWorksGraph[ui.fireWorkusCount], true);
			DrawGraph(350, 500, ui.fireWorksGraph[ui.fireWorkusCount], true);
			DrawGraph(400, 300, ui.fireWorksGraph[ui.fireWorkusCount], true);
			DrawGraph(900, 200, ui.fireWorksGraph[ui.fireWorkusCount], true);
			DrawGraph(1000, 300, ui.fireWorksGraph[ui.fireWorkusCount], true);
			DrawGraph(1200, 400, ui.fireWorksGraph[ui.fireWorkusCount], true);
			DrawGraph(1400, 500, ui.fireWorksGraph[ui.fireWorkusCount], true);
			DrawGraph(1250, 200, ui.fireWorksGraph[ui.fireWorkusCount], true);

			ui.fireWorkusCount++;
		}
		if (ui.fireWorkusCount == 21)// ループさせるためにリセット
		{
			ui.fireWorkusCount = 0;
		}

		// スコアの表示
		SetFontSize(100);
		sprintf_s(eliminationRateStr, "SCORE:%d", game.score);
		DrawString(550, 250, eliminationRateStr, GetColor(55, 55, 255), true);

		
		break;

		// ゲームオーバー.
	case STATE_GAMEOVER:
		// スコアの減算
		if (game.scoreUpFlag == false)
		{
			game.score -= 5000;
			game.scoreUpFlag = true;
		}
		// ゲームオーバー画像
		DrawGraph(0, 0, ui.gameOverGraph, true);
		// ゲームオーバー文字画像
		DrawGraph(425, 100, ui.gameOverStringGraph, true);
		// リザルトランク表示ベース描画
		DrawGraph(500, 300, ui.rankBaseGraph, true);
		// 「RANK」文字描画
		DrawGraph(615, 350, ui.rankStringGraph, true);
		// クリアランクの表示
		DrawFinalRank(ui, game);
		// スコアの表示
		SetFontSize(100);
		sprintf_s(eliminationRateStr, "SCORE:%d", game.score);
		DrawString(550, 250, eliminationRateStr, GetColor(255, 55, 55), true);
		

		break;


	default:
		break;
	}
}

// 最終ランクの表示
void DrawFinalRank(UI& ui,Game& game)
{
	// チェック用
	//game.player.enemyEliminationRate = 75;
	
	// SSSランク
	if (game.score >= 15000)
	{
		DrawGraph(650, 475, ui.rankGraphSSS, true);
	}
	// Sランク
	else if (game.score >= 14500)
	{
		DrawGraph(715, 475, ui.rankGraphS, true);
	}
	// Aランク
	else if (game.score >= 14000)
	{
		DrawGraph(710, 475, ui.rankGraphA, true);
	}
	// Bランク
	else if (game.score >= 12000)
	{
		DrawGraph(710, 475, ui.rankGraphB, true);
	}
	// Cランク 
	else if(game.score <= 11999)
	{
		DrawGraph(710, 475, ui.rankGraphC, true);
	}

	// スペースでメニューに戻れる説明文
	DrawGraph(200, 700, ui.rankDescriptionGraph, true);
}

// プレイヤー情報の描画
void DrawPlayerInfo(Game& game)
{
	// HPバーの描画
	DrawGraph(0, 0, game.ui.playerHpBarNewGraph, true);

	// HPが下がりすぎた時に０に戻す
	if (game.player.life <= 0)
	{
		game.player.life = 0;
	}

	// HPバーの描画
	int _hpBarX2 = game.player.life * 11;
	if (game.player.life >= 14)
	{
		DrawBox(70, 5, _hpBarX2 + 70, 70, GetColor(0, 255, 0), true);
		// 機体HP状態
		DrawGraph(PLAYER_STATUS_POS_X, PLAYER_STATUS_POS_Y, game.ui.playerStatusGreenGraph, true);
	}
	if (game.player.life >= 6 && game.player.life <= 13)
	{
		DrawBox(70, 5, _hpBarX2 + 70, 70, GetColor(255, 255, 0), true);
		// 機体HP状態
		DrawGraph(PLAYER_STATUS_POS_X, PLAYER_STATUS_POS_Y, game.ui.playerStatusYellowGraph, true);
	}
	if (game.player.life <= 5)
	{
		DrawBox(70, 5, _hpBarX2 + 70, 70, GetColor(255, 0, 0), true);
		// 機体HP状態
		DrawGraph(PLAYER_STATUS_POS_X, PLAYER_STATUS_POS_Y, game.ui.playerStatusRedGraph, true);
	}

	// 機体情報の描画
	DrawGraph(PLAYER_NAME_POS_X, PLAYER_NAME_POS_Y, game.ui.playerInfoNameGraph, true);			// 機体名
	DrawGraph(PLAYER_WEAPON_POS_X, PLAYER_WEAPON_POS_Y, game.ui.playerInfoWeaponGraph, true);	// 装備武装
	DrawGraph(PLAYER_DMG_POS_X, PLAYER_DAMEGE_RATE_POS_Y, game.ui.playerInfoDmgGraph, true);			// 損傷状態
	
	// 損傷率の表示
	char damegeRateStr[256];	// 損傷率を入れるための配列
	game.ui.playerDamageRate = (float)game.player.life / PLAYER_LIFE * 100;
	sprintf_s(damegeRateStr, "%.0f%%", game.ui.playerDamageRate);
	SetFontSize(25);
	DrawString(PLAYER_DAMEGE_RATE_POS_X, PLAYER_DAMEGE_RATE_POS_Y + 5, damegeRateStr, GetColor(50, 50, 50), true);


	// 実際の情報
	// 武装テキスト描画
	if (game.player.itemStatus == MULTI_SHOT)
	{
		DrawGraph(USE_WEAPON_TEXT_X, USE_WEAPON_TEXT_Y, game.ui.multiTextGraph, true);	// マルチショット
	}
	else
	{
		DrawGraph(USE_WEAPON_TEXT_X, USE_WEAPON_TEXT_Y, game.ui.normalTextGraph, true);	// ノーマル
	}
	// 機体武装アイコンフレーム描画
	DrawGraph(PLAYER_WEAPON_POS_X + PLAYER_STATUS_TEXT_X_BUF, PLAYER_WEAPON_POS_Y + PLAYER_WEAPON_X_BUF, game.ui.weaponFrameGraph, true);

	// 機体武装アイコン描画
	if (game.player.itemStatus == MULTI_SHOT)
	{
		DrawGraph(PLAYER_WEAPON_POS_X + PLAYER_STATUS_TEXT_X_BUF, PLAYER_WEAPON_POS_Y + PLAYER_WEAPON_X_BUF, game.item.multiShot.obj.graph, true);
	}
	else
	{
		DrawGraph(PLAYER_WEAPON_POS_X + PLAYER_STATUS_TEXT_X_BUF, PLAYER_WEAPON_POS_Y + PLAYER_WEAPON_X_BUF, game.item.missile.obj.graph, true);
	}


}

// プレイヤーの影の描画
void DrawPlayerShadow(Game& game)
{
	if (game.player.life > 0)
	{
		DrawGraph(game.player.obj.pos.x + PLAYER_SHADOW_ADJUST_X, game.player.obj.pos.y + PLAYER_SHADOW_ADJUST_Y, game.ui.playerShadowGraph,true);
	}
}

// ボスのHPバーの描画
void DrawBossHPBar(Game& game)
{
	// ボス登場サウンド再生
	if (game.bossEntryFlag == false)
	{
		PlaySoundMem(game.sound.bossEntrySE, DX_PLAYTYPE_BACK, true);
		game.bossEntryFlag = true;
	}

	// HPバー
	int _PosBuf = game.ui.bossHpBarNewGraphObj.w / BOSS_LIFE;
	int _PosLeftUpX = game.enemy.obj.pos.x - (game.ui.bossHpBarNewGraphObj.w / 2);			// 左上X座標
	int _PosLeftUpY = game.enemy.obj.pos.y - (game.ui.bossHpBarNewGraphObj.h / 2) + 200;			// 左上Y座標
	int _PosRightUpX = _PosLeftUpX + (_PosBuf * game.enemy.life);					// 左下X座標
	int _PosRightUpY = game.enemy.obj.pos.y + (game.ui.bossHpBarNewGraphObj.h / 2) + 200;			// 右下Y座標
	// HP土台の描画
	DrawGraph(_PosLeftUpX, _PosLeftUpY, game.ui.bossHpBarNewGraphObj.graph, true);
	DrawBox(_PosLeftUpX, _PosLeftUpY, _PosRightUpX, _PosRightUpY, GetColor(255,0,0), true);
}


// プレイヤーがダメージを受けた際に画面を少し赤色にする
void DrawDamageScreen(Game& game)
{
	if (game.player.damageFlag == true && game.player.life > 0)
	{
		DrawGraph(0, 0, game.ui.damageScreenGraph, true);
	}
}

// クリア時の画像描画
void DrawUpdateCleaer(Game& game)
{
	// 雲
	if (game.ui.clound.pos.x >= 1700)
	{
		game.ui.clound.pos.x = -100;
	}
	else
	{
		game.ui.clound.pos.x += 2;
	}

	// 描画
	DrawGameObject(game.ui.clound, game.ui.clound.graph);		// 雲
	DrawGameObject(game.ui.fighter, game.ui.fighter.graph);		// 戦闘機

	// 背景の描画
	for (int i = 0; i < BG_NUM; i++)
	{
		DrawBG(game.montain[i]);
	}
	for (int i = 0; i < BG_NUM; i++)
	{
		DrawBG(game.city2[i]);
	}
	for (int i = 0; i < BG_NUM; i++)
	{
		DrawBG(game.city[i]);

	}
}



