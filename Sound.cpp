
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

//// �֐�

// BGM�̏�����
void InitMenuBGM(Sound& sound)
{
	// ���j���[�T�E���h
	if (sound.menuBGM < 0)
	{
		sound.menuBGM		= LoadSoundMem("data/texture/MenuBGM.wav");		// ���j���[BGM
	}
	
	// �Q�[��
	if (sound.gameBGM < 0)
	{
		sound.gameBGM = LoadSoundMem("data/texture/BossBGM.wav");
	}

	// BOSS
	sound.bossBGM = LoadSoundMem("data/texture/BossBGM.wav");

	// ���ʉ�
	sound.enemyHitSE	= LoadSoundMem("data/texture/�Ō�2.mp3");			// �G�ɒe�������������̃T�E���h
	sound.enemyKillsSE	= LoadSoundMem("data/texture/����1.mp3");			// �G���j���̃T�E���h
	sound.bossEntrySE	= LoadSoundMem("data/texture/�x�񂪖�.mp3");		// �{�X�o�ꎞ�̃T�E���h
	sound.glassCrackSE	= LoadSoundMem("data/texture/�K���X�ɂЂт�����.mp3");	// �K���X������鉹
	// �v���C���[��e��
	sound.playerHitSE = LoadSoundMem("data/texture/�V���b�g����.mp3");
	// �v���C���[�ˌ���
	sound.playerShotSE = LoadSoundMem("data/texture/�V���b�g.mp3");

	// �A�C�e��
	sound.itemGetSE = LoadSoundMem("data/texture/powerUp.mp3");


	// ���ʂ̐ݒ�
	ChangeVolumeSoundMem(50, sound.gameBGM);
	ChangeVolumeSoundMem(100, sound.playerShotSE);


}


// ���j���[BGM�̍Đ�
void PlayMenuBGM(Sound& sound)
{
	//PlaySoundMem(sound.menuBGM, DX_PLAYTYPE_LOOP, false);
}

// �T�E���h�֌W
void PlaySE(Game& game)
{
	// �^�C�g��BGM
	if (game.state == STATE_MENU)
	{
		//PlaySoundMem(game.sound.menuBGM, DX_PLAYTYPE_BACK, true);
	}
	// �Q�[����GBM
	if (game.state == STATE_STAGE1 || game.state == STATE_STAGE2 || game.state == STATE_STAGE3)
	{
		// BGM�X�g�b�v
		//StopSoundMem(game.sound.menuBGM);
		//PlaySoundMem(game.sound.gameBGM, DX_PLAYTYPE_BACK, true);
	}
	if (game.gameFrameCount >= BOSS_ENTRY_FRAME - BOSS_ENTRY_DIRECTING_TIME && game.gameFrameCount <= BOSS_ENTRY_FRAME)
	{
		PlaySoundMem(game.sound.bossEntrySE, DX_PLAYTYPE_BACK, true);
	}


	// �{�X�ɒe�����������Ƃ���SE
	if (game.enemy.damageFlag == true)
	{
		//PlaySoundMem(game.sound.enemyHitSE, DX_PLAYTYPE_BACK,true);
	}


}