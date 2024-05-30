#pragma once

// �\����

struct Game;


struct Sound
{
	// ���j���[
	int		menuBGM = -1;			// ���j���[��BGM
	int		menuGameStartSE = -1;	// ���j���[����Q�[����ʂւ̈ڍs����Ƃ��̃T�E���h

	// �Q�[��
	int		gameBGM = -1;		// �Q�[����BGM

	// BOSS
	int		bossBGM;		// �{�X���BGM

	// SE
	int		enemyHitSE;		// �G�̃q�b�g���̃T�E���h
	int		enemyKillsSE;	// ���j���̃T�E���h
	int		bossEntrySE;	// �{�X�̃G���g���[�o�ꎞ�ɂ���T�E���h
	int		gameOverSe;		// �Q�[���I�[�o�[���̃T�E���h
	int		gameClaerSE;	// �Q�[���N���A���̃T�E���h
	int		glassCrackSE;	// �K���X���Ђъ����T�E���h

	// �v���C���[
	int		playerHitSE;	// �v���C���[��e���̃T�E���h
	int		playerShotSE;	// �v���C���[�̎ˌ����̃T�E���h

	// �A�C�e��
	int		itemGetSE = -1;	// �A�C�e������肵�����̃T�E���h

};


void InitMenuBGM(Sound& sound);
void PlayMenuBGM(Sound& sound);
void PlaySE(Game& game);
