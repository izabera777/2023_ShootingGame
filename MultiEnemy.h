// �}���`�G�l�~�[
#pragma once

// �v���g�^�C�v�錾		//���̍\���̂��g�p���܂���
struct GameObject;
struct Player;
struct Shot;
struct Enemy;
struct Shot;

// �Q�[����ł̕����̓G
Enemy multiEnemy[ENEMY_OF_NUMBER];

// �v���g�^�C�v�錾

// ������.
void InitMultiEnemy(Enemy& enemy, Enemy multiEnemy[], int size, Game& game);

// �A�b�v�f�[�g.
void UpdateMultiEnemy(Enemy& enemy, Enemy multiEnemy[], Player& player, int size, Game& game);

// �`��.
void DrawMultiEnemy(Game& game, Enemy multiEnemy[], int size);

// �}���`�G�l�~�[�̈ړ����[�`���ɉ������x�N�g���̒���.
void MoveRoutinesMultiEnemy(Enemy multiEnemy[], int size);

void InitMultiEnemySTAGE1(Enemy& enemy, Enemy multiEnemy[], int size, Game& game);


void InitMultiEnemySTAGE2(Enemy& enemy, Enemy multiEnemy[], int size, Game& game);




