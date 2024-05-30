#pragma once

// 構造体

struct Game;


struct Sound
{
	// メニュー
	int		menuBGM = -1;			// メニュー内BGM
	int		menuGameStartSE = -1;	// メニューからゲーム画面への移行するときのサウンド

	// ゲーム
	int		gameBGM = -1;		// ゲーム内BGM

	// BOSS
	int		bossBGM;		// ボス戦のBGM

	// SE
	int		enemyHitSE;		// 敵のヒット時のサウンド
	int		enemyKillsSE;	// 撃破時のサウンド
	int		bossEntrySE;	// ボスのエントリー登場時にするサウンド
	int		gameOverSe;		// ゲームオーバー時のサウンド
	int		gameClaerSE;	// ゲームクリア時のサウンド
	int		glassCrackSE;	// ガラスがひび割れるサウンド

	// プレイヤー
	int		playerHitSE;	// プレイヤー被弾時のサウンド
	int		playerShotSE;	// プレイヤーの射撃時のサウンド

	// アイテム
	int		itemGetSE = -1;	// アイテムを入手した時のサウンド

};


void InitMenuBGM(Sound& sound);
void PlayMenuBGM(Sound& sound);
void PlaySE(Game& game);
