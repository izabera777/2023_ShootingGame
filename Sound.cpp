
#include "GameObject.h"
#include "BG.h"
#include "Sound.h"
#include "Menu.h"
//#include "DxLib.h"
#include "Shot.h"
#include "Enemy.h"
#include "Utility.h"
#include "Player.h"
#include "UI.h"
#include "Item.h"
#include "Game.h"

//// 関数

// BGMの初期化
void InitMenuBGM(Sound& sound)
{
	// メニューサウンド
	if (sound.menuBGM < 0)
	{
		sound.menuBGM		= LoadSoundMem("data/texture/MenuBGM.wav");		// メニューBGM
	}
	
	// ゲーム
	if (sound.gameBGM < 0)
	{
		sound.gameBGM = LoadSoundMem("data/texture/BossBGM.wav");
	}

	// BOSS
	sound.bossBGM = LoadSoundMem("data/texture/BossBGM.wav");

	// 効果音
	sound.enemyHitSE	= LoadSoundMem("data/texture/打撃2.mp3");			// 敵に弾が当たった時のサウンド
	sound.enemyKillsSE	= LoadSoundMem("data/texture/爆発1.mp3");			// 敵撃破時のサウンド
	sound.bossEntrySE	= LoadSoundMem("data/texture/警報が鳴る.mp3");		// ボス登場時のサウンド
	sound.glassCrackSE	= LoadSoundMem("data/texture/ガラスにひびが入る.mp3");	// ガラスが割れる音
	// プレイヤー被弾時
	sound.playerHitSE = LoadSoundMem("data/texture/ショット命中.mp3");
	// プレイヤー射撃時
	sound.playerShotSE = LoadSoundMem("data/texture/ショット.mp3");

	// アイテム
	sound.itemGetSE = LoadSoundMem("data/texture/powerUp.mp3");


	// 音量の設定
	ChangeVolumeSoundMem(50, sound.gameBGM);
	ChangeVolumeSoundMem(100, sound.playerShotSE);


}


// メニューBGMの再生
void PlayMenuBGM(Sound& sound)
{
	//PlaySoundMem(sound.menuBGM, DX_PLAYTYPE_LOOP, false);
}

// サウンド関係
void PlaySE(Game& game)
{
	// タイトルBGM
	if (game.state == STATE_MENU)
	{
		//PlaySoundMem(game.sound.menuBGM, DX_PLAYTYPE_BACK, true);
	}
	// ゲーム中GBM
	if (game.state == STATE_STAGE1 || game.state == STATE_STAGE2 || game.state == STATE_STAGE3)
	{
		// BGMストップ
		//StopSoundMem(game.sound.menuBGM);
		//PlaySoundMem(game.sound.gameBGM, DX_PLAYTYPE_BACK, true);
	}
	if (game.gameFrameCount >= BOSS_ENTRY_FRAME - BOSS_ENTRY_DIRECTING_TIME && game.gameFrameCount <= BOSS_ENTRY_FRAME)
	{
		PlaySoundMem(game.sound.bossEntrySE, DX_PLAYTYPE_BACK, true);
	}


	// ボスに弾があったたときのSE
	if (game.enemy.damageFlag == true)
	{
		//PlaySoundMem(game.sound.enemyHitSE, DX_PLAYTYPE_BACK,true);
	}


}